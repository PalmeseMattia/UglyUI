#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "core/inputs.h"
#include "core/event_loop/event_loop.h"

void helloworld(int event_id, void *data){
  printf("EventId = %d helloworld\n", event_id);
}

int main() {
  EventLoop eventLoop;
  initEventLoop(&eventLoop);

  Event event = {
    .handler = helloworld,
    NULL
  };

  int i = 0;
  while(i<=8){
    pushEvent(&eventLoop, event);
    i++;
  }

  for(int i = 0; i<eventLoop.size; i++){
    Event event = eventLoop.events[i];
    event.handler(i, event.arg);
  }

  printf("Ending size %zu", eventLoop.size);


}
