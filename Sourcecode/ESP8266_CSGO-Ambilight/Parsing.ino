void Parsing() {
  //char Buffer[payload.length() + 1];
  //payload.toCharArray(Buffer, (payload.length() + 1) );

  Player.health   = atoi( strtok(incomingPacket, ";") );
  Player.armor    = atoi( strtok(NULL,           ";") );
  Player.helmet   = strtok(NULL,                 ";");
  Round.win_team  = strtok(NULL,                 ";");
  Player.flashed  = atoi( strtok(NULL,           ";") );
  Player.smoked   = atoi( strtok(NULL,           ";") );
  Player.activity = strtok(NULL,                 ";");

  Refresh.last_refresh = millis();

  return;
}

bool CheckDifferent() {
  if ( Player_Last.health != Player.health ||
       Player_Last.armor != Player.armor ||
       Player_Last.helmet != Player.helmet ||
       Round_Last.win_team != Round.win_team ||
       Player_Last.flashed != Player.flashed ||
       Player_Last.smoked != Player.smoked ||
       Player_Last.activity != Player.activity) {

    if (Round.win_team)  ClearLED();                      // Refresh the hole LED strip for next round
    return true;                                          // Something has changed
  } else {
    return false;                                         // Nothing has changed
  }
}
