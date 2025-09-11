#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdlib.h>
#include "uglyui/inputs.h"
#include "uglyui/event_loop/event_loop.h"

// This stuff is for linux
void set_raw_mode(int enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);    // save old settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // disable buffering and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore
    }
}

int isKeyboardReady(){
  fd_set readfds;
  struct timeval timeout = {0,0};
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);
  int result = select(STDIN_FILENO+1, &readfds, NULL, NULL, &timeout);
  return (result>0&&FD_ISSET(STDIN_FILENO,&readfds));
}

void process_input(EventLoop *loop, void *handler){
  if(isKeyboardReady()){
    char ch = getchar();
    KeyboardEvent *keyData = malloc(sizeof(KeyboardEvent));
    keyData->character = ch;
    keyData->type = KEY_PRESS;

    Event event = {
      .handler=handler,
      .arg = keyData
    };
    push_event(loop, event);
  }
}
