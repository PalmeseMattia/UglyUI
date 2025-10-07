#include "uglyui/event_loop/event_loop.h"
#include <stdio.h>
#include <stdlib.h>

void init_event_loop(EventLoop* loop) {
  loop->size=0;
  loop->current_capacity=4;
  loop->events = malloc(loop->current_capacity * sizeof(Event));
}

/*
 * TO_READ
 * Le allocazioni possono fallire quindi checkiamo al volo che il diobubu
 * non abbia labubato
*/
EventLoop *new_event_loop(size_t initial_capacity) {
  EventLoop *event_loop;

  event_loop = (EventLoop *) calloc(1, sizeof(EventLoop));
  if (event_loop == NULL) {
    return NULL;
  }
  event_loop -> initial_capacity = initial_capacity;
  event_loop -> current_capacity = initial_capacity;
  event_loop -> events = (Event **) calloc(initial_capacity, sizeof(Event *));
  if (event_loop -> events == NULL) {
    free (event_loop);
    return NULL;
  }

  return event_loop;
}

void free_event_loop(EventLoop *event_loop) {
  if (event_loop) {
    clear_events(event_loop);
    free(event_loop);
  }
}

/*
 * Adesso che gli eventi sono un puntatore a puntatore, ogni volta
 * Che riallochiamo, possiamo riallocare solo i puntatori agli eventi,
 * e non gli eventi stessi. Salviamo tempo e spazio, di conseguenza
 * salviamo il pianeta 🌎❤️.
 * Tra l'altro così gli eventi possono vivere indipendentemente dal loop.
 * Ma se sapessimo quanti eventi massimi si possono avere allora sarebbe un altro
 * discorso. averli tutti in memoria contigua sarebbe meglio per ridurre gli accessi
 * sparsi in memoria, cache miss ecc ma adesso basta parlare di questo pezzo di codice
 * di merda e di ottimizzazioni per una cosa che porco dio AAAAAAAAAAAAAAAAAAAAAAAAAAAAA
*/
ugly_bool push_event(EventLoop *loop, Event *event) {
  Event   **newPtr;

  if(loop -> size >= loop -> current_capacity){
    size_t newCapacity = loop -> current_capacity + loop -> initial_capacity; // Di solito in questi casi si fa un *2, ma sti cazzi
    newPtr = (Event **) realloc(loop->events, newCapacity * sizeof(Event *));
    if(!newPtr) { // Allora vedi che le controlli le allocazioni, gay. Però se ritorna null dobbiamo tipo morire
      return UGLY_FALSE;
    }
    loop -> events = newPtr;
    loop -> current_capacity = newCapacity;
  }
  loop -> events[loop -> size++] = event;

  return UGLY_TRUE;
}

void clear_events(EventLoop *loop){
  for(size_t i = 0; i < loop -> size; i++){
    if (loop -> events[i])
      free (loop -> events[i]);
  }
  loop->size = 0;
}
