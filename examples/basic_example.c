#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <uglyui/inputs.h>
#include <uglyui/event_loop/event_loop.h>

void key_handler(int event_id, void *data){
  KeyboardEvent *keyData =  (KeyboardEvent*)data;
  printf("CHAR PRESSED = %c\n", keyData->character);
}

int main() {
  EventLoop eventLoop;
  init_event_loop(&eventLoop);
  set_raw_mode(1);

  while(1){
    process_input(&eventLoop, key_handler);



    for (size_t i = 0; i<eventLoop.size; i++){
      Event event = eventLoop.events[i];
      event.handler(i,event.arg);
    }

    clear_events(&eventLoop);
  }
}
