#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <FastLED.h>



#include "A_Configuration.h"
#include "A_Variable.h"                                         // Move Variable to it's own File

void setup () {
  InitLED();
  InitESP();
  InitWiFi();
  InitUDP();
  Light_FX();
}


void loop() {
  Mode();
  GetUDP();

  if ( CheckDifferent() || FX_Changed == true) {
    FX_Changed = false; 
    Set_FX();
    
    Player_Last.health  = Player.health;
    Player_Last.armor   = Player.armor;
    Player_Last.helmet  = Player.helmet;
    Round_Last.win_team = Round.win_team;
    Player_Last.flashed = Player.flashed;
  }


}
