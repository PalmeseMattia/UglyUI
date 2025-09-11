#ifndef INPUTS
#define INPUTS
#include "event_loop/event_loop.h"

typedef enum{
  KEY_PRESS,
  KEY_RELEASE,
}KeyEventType;

typedef struct {
  KeyEventType type;
  int key_code;
  char character;
}KeyboardEvent;

void set_raw_mode(int enable);
void process_input(EventLoop  *loop, void *handler);
#endif // !INPUTS
