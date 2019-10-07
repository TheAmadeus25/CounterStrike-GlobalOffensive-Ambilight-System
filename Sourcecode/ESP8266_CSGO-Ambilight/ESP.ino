void InitESP() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  delay(100);

  return;
}

void InitWiFi() {
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(5);
    WiFiLED();
  }
  Serial.print("WiFi connected @: ");
  Serial.println(WiFi.localIP());

  ClearLED();

  return;
}

void Mode() {                                       // # Check if Button is Pressed
  if (digitalRead(BTN) == LOW) {                    // When pressing the button...
    if (canBtnPress) canBtnPress = false;           // ...change state
  } else if (!canBtnPress) {
    canBtnPress = true;


    if ( (Light_Mode + 1) > 3 ) {
      Light_Mode = 0;
    } else {
      Light_Mode++;
    }

    Light_FX();
  }

  return;
}
