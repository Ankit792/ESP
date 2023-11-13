#include <stdio.h>
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#include "esp_system.h"
#include "esp_random.h"
#include "math.h"

#define PIN 2
#define TAG "Test"

int dice_roll()
{
    int random = esp_random();
    int positiveNum = abs(random);
    int diceNum = (positiveNum % 6) + 1;
    return diceNum;
}

void app_main(void)
{
/*  random number generator
    while(true)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "random number %d", dice_roll());
    }
*/



/*  input characters
    char c = 0;
    char str[100];
    memset(str,0,sizeof(str));
    while(c!='\n')
    {
        c=getchar();
        if(c!=0xff)
        {
            str[strlen(str)] = c;
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    printf("String: %s\n", str);
*/

// led blink
    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

    int isOn = 0;
    while(true)
    {
        isOn = !isOn;
        gpio_set_level(PIN, isOn);
        vTaskDelay(10000 / portTICK_PERIOD_MS);

//  Logging Examples
//         esp_log_level_t("LOG1", ESP_LOG_INFO);   //enable till info
//         ESP_LOGI("LOG1", "Blinkig LED Informational");
//         ESP_LOGW("LOG1", "Blinkig LED Warning");
//         ESP_LOGE("LOG1", "Blinkig LED ERROR");
//         ESP_LOGD("LOG1", "Blinkig LED Debug");
//         ESP_LOGV("LOG1", "Blinkig LED Verbose");

//         // by default Debug and Verbose are off to turn on menuconfig
//         ESP_LOGI(TAG, "Blinkig LED Informational");
//         ESP_LOGW(TAG, "Blinkig LED Warning");
//         ESP_LOGE(TAG, "Blinkig LED ERROR");
//         ESP_LOGD(TAG, "Blinkig LED Debug");
//         ESP_LOGV(TAG, "Blinkig LED Verbose");

    }
}