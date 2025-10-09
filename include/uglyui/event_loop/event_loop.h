#ifndef EVENT_LOOP_H
# define EVENT_LOOP_H

# include <stdlib.h>

# define UGLY_TRUE 1
# define UGLY_FALSE 0

typedef void (*EventHandler)(int, void *data);
typedef char ugly_bool;

typedef struct{
  EventHandler handler;
  void *arg;
 } Event;

 // TO_READ: Abbiamo un doppio puntatore agli eventi ma te lo spiego nel prossimo episodio (ovvero event_loop.c)
typedef struct{
  Event   **events;
  size_t  initial_capacity;
  size_t  size;
  size_t  current_capacity;

} EventLoop;

EventLoop *new_event_loop(size_t initial_capacity);
void free_event_loop(EventLoop *event_loop);
void init_event_loop(EventLoop* loop);
ugly_bool push_event(EventLoop *loop, Event *event);
void clear_events(EventLoop *loop);
#endif // !EVENT_LOOP_H
