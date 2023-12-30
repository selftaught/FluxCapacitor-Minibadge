/**
 * Project: SaintCon Flux Capacitor Minibadge
 * Author: Dillan Hildebrand
 * Date: 09/21/2022
 */
#include <avr/io.h>
#include "Arduino.h"

/* Breadboard pins
#define LED_SEG_1_PIN PB1
#define LED_SEG_2_PIN PB2
#define LED_SEG_3_PIN PB0
#define LED_SEG_4_PIN PB4
#define LED_SEG_0_PIN PB3 // center led
*/

// Minibadge Pins
#define LED_SEG_0_PIN PB0 // center led
#define LED_SEG_1_PIN PB4
#define LED_SEG_2_PIN PB3
#define LED_SEG_3_PIN PB2
#define LED_SEG_4_PIN PB1

const int NUM_LEDS = 5;

int leds[5] = {
    LED_SEG_1_PIN,
    LED_SEG_2_PIN,
    LED_SEG_3_PIN,
    LED_SEG_4_PIN,
    LED_SEG_0_PIN};


void setup()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        pinMode(leds[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < 30; i++)
    {
        int d = (i <= 25 ? 40 - i : 20);
        for (int i = 0; i < NUM_LEDS; i++)
        {
            PORTB |= (1 << leds[i]); // led on
            delay(d);
            PORTB &= ~(1 << leds[i]); // led off
        }
        delay(100);
    }
    delay(3000);
}