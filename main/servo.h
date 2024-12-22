#ifndef SERVO_H
#define SERVO_H

typedef enum {
    FORWARD,
    REVERSE,
    STOP
} servo_mode;

void servo_init(void);
void servo_set_mode(servo_mode);

#endif