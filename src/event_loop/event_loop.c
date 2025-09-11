#include "uglyui/event_loop/event_loop.h"
#include <stdio.h>
#include <stdlib.h>

void init_event_loop(EventLoop* loop) {
  loop->size=0;
  loop->current_capacity=4;
  loop->events = malloc(loop->current_capacity * sizeof(Event));
}

void push_event(EventLoop *loop, Event event) {
  Event *temp = loop->events;

  if(loop->size>=loop->current_capacity){

    size_t newCapacity = loop->current_capacity+4;
    Event *newPtr = realloc(loop->events, newCapacity*sizeof(Event));
    if(newPtr!=NULL){
      loop->events = newPtr;
      loop->current_capacity = newCapacity;
    }
  }
  loop->events[loop->size] = event;
  loop->size++;
}

void clear_events(EventLoop *loop){
  for(size_t i = 0; i<loop->size; i++){
    Event event = loop->events[i];
    if(event.arg!=NULL)
      free(event.arg);
  }
  loop->size = 0;
}
