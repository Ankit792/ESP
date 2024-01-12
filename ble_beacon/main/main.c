#include <stdio.h>
#include <string.h>
#include "nvs.h"
#include "nvs_flash.h"
#include "esp_nimble_hci.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "host/ble_hs.h"
#include "services/gap/ble_svc_gap.h"
#include <stdbool.h>
#include "esp_log.h"

#define DEVICE_Name "BLE Ankit"

// Define your known beacon parameters
// #define KNOWN_BEACON_UUID "\x22\x11\x66\x55\x44\x33\x22\x11\x66\x55\x44\x33\x22\xdd\x58\xab"
// #define KNOWN_BEACON_MAJOR 2
// #define KNOWN_BEACON_MINOR 10


void ble_app_set_addr(void)   //Bluetooth address
{
    /* Generate a non-resolvable private address. */
    ble_addr_t addr;
    int rc;
    rc = ble_hs_id_gen_rnd(1, &addr);
    assert(rc == 0);
    rc = ble_hs_id_set_rnd(addr.val);
    assert(rc == 0);
}

void ble_app_advertise(void)
{
    uint8_t uuid128[16];
    // memset(uuid128, 0x11, sizeof(uuid128));
    memcpy(uuid128, (uint8_t[]){0x22, 0x11, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x66, 0x55, 0x44, 0x33, 0x22, 0xdd, 0x58, 0xab}, sizeof(uuid128));
    ble_ibeacon_set_adv_data(uuid128, 2, 10, -50);

    struct ble_gap_adv_params adv_params = (struct ble_gap_adv_params){0};
    ble_gap_adv_start(BLE_OWN_ADDR_RANDOM, NULL, BLE_HS_FOREVER, &adv_params, NULL, NULL);
}

void ble_app_on_sync(void)
{
    ble_app_set_addr();
    ble_app_advertise();
    
}

void on_reset(void)
{
    ESP_LOGI("on reset", "Resetting state");
}


void host_task(void *params)
{
    nimble_port_run();
}


void app_main(void)
{
    nvs_flash_init();
    nimble_port_init();

    ble_svc_gap_device_name_set(DEVICE_Name);      
    ble_svc_gap_init();
    
    ble_hs_cfg.sync_cb = ble_app_on_sync;
    ble_hs_cfg.reset_cb = on_reset;

    nimble_port_freertos_init(host_task);
}
