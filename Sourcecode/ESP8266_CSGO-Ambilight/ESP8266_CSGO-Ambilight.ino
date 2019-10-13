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
}//END-SETUP


void loop() {
  Mode();
  GetUDP();
  Standby();

  if ( CheckDifferent() || FX_Changed == true) {
    FX_Changed = false; 
    Set_FX();
    
    Player_Last.health   = Player.health;
    Player_Last.armor    = Player.armor;
    Player_Last.helmet   = Player.helmet;
    Round_Last.win_team  = Round.win_team;
    Player_Last.flashed  = Player.flashed;
    Player_Last.smoked   = Player.smoked;
    Player_Last.activity = Player.activity;
  }
}//END-LOOP
