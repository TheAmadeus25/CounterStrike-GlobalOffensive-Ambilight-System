void InitESP() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  delay(100);
  pinMode(BTN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

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

void Standby() {
  if (millis() >= Refresh.last_refresh + Refresh.refresh_delay) {
    ClearLED();
    //digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);

  } else {
    //digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }

  return;
}
