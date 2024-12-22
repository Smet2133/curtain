#include "mqtt.h"
#include "esp_log.h"
#include "mqtt_client.h"

esp_mqtt_client_handle_t client;

void mqtt_init(esp_event_handler_t event_handler)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = "mqtt://m3.wqtt.ru",
        .credentials.username = "u_NUG5UJ",
        .credentials.authentication.password = "zLaZivDF",
        .broker.address.port = 11593,
        .session.last_will.msg = "offline",
        .session.last_will.topic = "device/state",
        .session.last_will.qos = 1,
        .session.last_will.retain = 1
    };

    client = esp_mqtt_client_init(&mqtt_cfg);
    /* The last argument may be used to pass data to the event handler, in this example mqtt_event_handler */
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, event_handler, NULL);
    esp_mqtt_client_start(client);
}

void mqtt_publish(const char *topic, const char *data) {
    esp_mqtt_client_publish(client, topic, data, 0, 1, 0);
}

