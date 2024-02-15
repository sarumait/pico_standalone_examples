#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "btstack.h"

#define HEARTBEAT_PERIOD_MS 1000

static btstack_timer_source_t heartbeat;

static void heartbeat_handler(btstack_timer_source_t *ts){
    UNUSED(ts);

    printf("BTstack heartbeat");

    // re-register timer
    btstack_run_loop_set_timer(&heartbeat, HEARTBEAT_PERIOD_MS);
    btstack_run_loop_add_timer(&heartbeat);
} 

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }

    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    btstack_memory_init();
    
    // set one-shot timer
    heartbeat.process = &heartbeat_handler;
    btstack_run_loop_set_timer(&heartbeat, HEARTBEAT_PERIOD_MS);
    btstack_run_loop_add_timer(&heartbeat);

    printf("Running");
    btstack_run_loop_execute(); 
}