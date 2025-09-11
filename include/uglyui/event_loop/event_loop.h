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

void init_event_loop(EventLoop* loop);
void push_event(EventLoop* loop, Event event);
void clear_events(EventLoop *loop);
#endif // !EVENT_LOOP_H
