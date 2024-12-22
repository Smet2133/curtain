#ifndef TIMER_H
#define TIMER_H

void timer_init(void (*callback)(void* arg));
void timer_start(int duration_ms);

#endif