#include "event_loop.h"
#include <stdio.h>

void initEventLoop(EventLoop* loop) {
  loop->size=0;
  loop->current_capacity=4;
  loop->events = malloc(loop->current_capacity * sizeof(Event));
}

void pushEvent(EventLoop* loop, Event event) {
  Event *temp = loop->events;

  if(loop->size>=loop->current_capacity){

    size_t newCapacity = loop->current_capacity+4;
    printf("Scaling eventloop from %zu to %zu\n", loop->current_capacity, newCapacity);
    Event *newPtr = realloc(loop->events, newCapacity*sizeof(Event));
    if(newPtr!=NULL){
      loop->events = newPtr;
      loop->current_capacity = newCapacity;
    }
  }
  loop->events[loop->size] = event;
  loop->size++;
}
