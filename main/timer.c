#include "esp_timer.h"
#include "esp_log.h"
#include "timer.h"

static const char *TAG = "Timer";

esp_timer_handle_t oneshot_timer;

void timer_init(void (*callback)(void* arg))
{
    const esp_timer_create_args_t oneshot_timer_args = {
            .callback = callback,
            .arg = NULL,
            .name = "one-shot"
    };
    ESP_ERROR_CHECK(esp_timer_create(&oneshot_timer_args, &oneshot_timer));
}

void timer_start(int duration_ms)
{
    ESP_LOGI(TAG, "Timer start");
    ESP_ERROR_CHECK(esp_timer_start_once(oneshot_timer, duration_ms * 1000));
}

