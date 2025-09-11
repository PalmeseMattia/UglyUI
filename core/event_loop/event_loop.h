#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H
#include <stdlib.h>

typedef void (*EventHandler)(int, void *data);

typedef struct{
  EventHandler handler;
  void *arg;
 } Event;

typedef struct{
  Event *events;
  size_t size;
  size_t  current_capacity;

}EventLoop;

void initEventLoop(EventLoop* loop);
void pushEvent(EventLoop* loop, Event event);

#endif // !EVENT_LOOP_H
