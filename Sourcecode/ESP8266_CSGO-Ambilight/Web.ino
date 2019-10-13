/*void GetWebsocket() {
  if (WiFi.status() == WL_CONNECTED) {                              //Check WiFi connection status
    HTTPClient http;                                                //Declare an object of class HTTPClient

    http.begin("http://" + IP + ":" + PORT);                        //Specify request destination

    if (http.GET() > 0) {                                           //Check the returning code
      payload = http.getString();                                   //Get the request response payload
      Serial.println(payload);                                      //Print the response payload
    }
    http.end();                                                     //Close connection
  }

  return;
}*/


void InitUDP() {
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
  
  return;
}


void GetUDP() {
  packetSize = Udp.parsePacket();
  if (packetSize) {
    digitalWrite(LED1, LOW);
    len = Udp.read(incomingPacket, 128);
    if (len > 0) {
      incomingPacket[len] = 0;
    }
    
    Serial.println(incomingPacket);

    // send back a reply, to the IP address and port we got the packet from
    //Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    //Udp.write(replyPacket);
    Udp.endPacket();
    digitalWrite(LED1, HIGH);
    Parsing();
  }

  return;
}
