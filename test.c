
#include <stdint.h>
#include <stdio.h>

const uint16_t QUEUESIZE = 5;

enum incomingEvents { NORTHEVENT, SOUTHEVENT, NONE } incomingEvents;

// enum incomingEvents eventQueue[QUEUESIZE] = {NONE, NONE, NONE, NONE, NONE};
enum incomingEvents eventQueue[QUEUESIZE] = {NORTHEVENT, NORTHEVENT, SOUTHEVENT,
                                             SOUTHEVENT, SOUTHEVENT};

void completeEvent() {
  for (int i = 1; i < QUEUESIZE; ++i) {
    eventQueue[i - 1] = eventQueue[i];
    printf("%d\n", i); // Corrected line
  }
  eventQueue[QUEUESIZE - 1] = NONE;
}

enum incomingEvents getNextEvent()
{
  return eventQueue[0];
}

void addEvent(enum incomingEvents aEvent) {
  for (int i = 0; i < QUEUESIZE; ++i) {
    if (eventQueue[i] == NONE) {
      eventQueue[i] = aEvent;
      return;
    }
  }
}

void dumpQueue() {
  for (int i = 0; i < QUEUESIZE; ++i) {
      eventQueue[i] = NONE;  
  }
}

const char *eventToString(enum incomingEvents event) {
  switch (event) {
  case NORTHEVENT:
    return "NORTHEVENT";
  case SOUTHEVENT:
    return "SOUTHEVENT";
  case NONE:
    return "NONE";
  default:
    return "UNKNOWN";
  }
}

void printQueue() {
  for (int i = 0; i < QUEUESIZE; ++i) {
    printf("eventQueue[%d] = %s\n", i, eventToString(eventQueue[i]));
  }
}

// enum getNextEvent() {
//   return NONE;
// }

int main(int argc, char const *argv[]) {
  completeEvent();
  printQueue();
  addEvent(NORTHEVENT);
  printQueue();
  return 0;
}
