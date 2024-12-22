#ifndef MQTT_H
#define MQTT_H

#include "mqtt_client.h"

void mqtt_init(esp_event_handler_t event_handler);
void mqtt_publish(const char *topic, const char *data);

#endif