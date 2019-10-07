



#ifndef A_Configuration_h
#define A_Configuration_h

#define LED 2                                                     // Built-In Blue LED on ESP32
#define BTN 0                                                     // Built-In Button on ESP32

#define NUM_LEDS    21                                            // How many leds in your strip?
#define DATA_PIN     5                                            // Data Pin of your WS28XX
#define CLOCK_PIN   13                                            // If nessecary
#define BRIGHTNESS 255
CRGB leds[NUM_LEDS];                                              // Define the array of leds


#define ZONE_1_LOW   0
#define ZONE_1_HIGH  3

#define ZONE_2_LOW   4
#define ZONE_2_HIGH  7

#define ZONE_3_LOW   9
#define ZONE_3_HIGH 11

#define ZONE_4_LOW  13
#define ZONE_4_HIGH 16

#define ZONE_5_LOW  17
#define ZONE_5_HIGH 20



#endif