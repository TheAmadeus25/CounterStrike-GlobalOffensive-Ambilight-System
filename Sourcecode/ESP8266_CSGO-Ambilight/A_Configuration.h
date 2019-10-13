



#ifndef A_Configuration_h
#define A_Configuration_h

#define LED1  2                                                   // Built-In Blue LED on ESP8266 1 (D4) ~
#define LED2 16                                                   // Built-In Blue LED on ESP8266 2 (D0)
#define BTN   0                                                   // Built-In Button on ESP8266

#define NUM_LEDS    21                                            // How many leds in your strip?
#define DATA_PIN     5                                            // Data Pin of your WS28XX
#define CLOCK_PIN   13                                            // If nessecary
#define BRIGHTNESS 255
CRGB leds[NUM_LEDS];                                              // Define the array of leds


#define ZONE_1_LOW   0
#define ZONE_1_HIGH  3

#define ZONE_2_LOW   4
#define ZONE_2_HIGH  7
// 8
#define ZONE_3_LOW   9
#define ZONE_3_HIGH 11
// 12
#define ZONE_4_LOW  13
#define ZONE_4_HIGH 16

#define ZONE_5_LOW  17
#define ZONE_5_HIGH 20



#endif
