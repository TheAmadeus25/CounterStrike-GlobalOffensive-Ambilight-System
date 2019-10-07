void Parsing() {
  //char Buffer[payload.length() + 1];
  //payload.toCharArray(Buffer, (payload.length() + 1) );
    
  Player.health  = atoi( strtok(incomingPacket, ";") );
  Player.armor   = atoi( strtok(NULL,           ";") ); 
  Player.helmet  = strtok(NULL,                 ";");
  Round.win_team = strtok(NULL,                 ";");
  Player.flashed = atoi( strtok(NULL,           ";") );
  
  
  return;
}

bool CheckDifferent() {
  if( Player_Last.health != Player.health || Player_Last.armor != Player.armor || Player_Last.helmet != Player.helmet || Round_Last.win_team != Round.win_team || Player_Last.flashed != Player.flashed ) {
    return true;
  } else {
    return false;
  }

  return false;
}
