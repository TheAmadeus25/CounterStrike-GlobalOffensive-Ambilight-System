void Light_FX() {
  switch (Light_Mode) {
    case 0:
      Zone.A_LOW  =  0;
      Zone.A_HIGH = NUM_LEDS;
      break;
    case 1:
      Zone.A_LOW  = ZONE_5_LOW;
      Zone.A_HIGH = ZONE_5_HIGH;
      Zone.B_LOW  = ZONE_1_LOW;
      Zone.B_HIGH = ZONE_1_HIGH;
      break;
    case 2:
      Zone.A_LOW  = ZONE_5_LOW;
      Zone.A_HIGH = ZONE_5_HIGH;
      Zone.B_LOW  = ZONE_4_LOW;
      Zone.B_HIGH = ZONE_4_HIGH;
      //---
      Zone.D_LOW  = ZONE_2_LOW;
      Zone.D_HIGH = ZONE_2_HIGH;
      Zone.E_LOW  = ZONE_1_LOW;
      Zone.E_HIGH = ZONE_1_HIGH;
      break;
    case 3:
      Zone.A_LOW  =  0;
      Zone.A_HIGH = NUM_LEDS;
      break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    case 8: break;
    case 9: break;
    case 10: break;
    case 11: break;
    case 12: break;
    case 13: break;
    case 14: break;
    default: break;
  }

  FX_Changed = true;
  ClearLED();

  return;
}

void Set_FX() {  
  if (Player.activity == "menu") {
    EndDots();
    return;
  }

  if (Player.flashed != 0) {
    Flashed();
    return;
  }

  if (Round.win_team == "CT") {
    FillLED(0, 0, 255);
    return;
  } else if (Round.win_team == "T") {
    //FillLED(204, 153, 0);
    FillLED(255, 153, 0);
    return;
  }

  if (Player.smoked != 0) {
    Smoked();
    return;
  }



  switch (Light_Mode) {
    case 0: Life(Zone.A_LOW, Zone.A_HIGH);  break;
    case 1: Life(Zone.A_LOW, Zone.A_HIGH);  Armor(Zone.B_LOW, Zone.B_HIGH);  break;
    case 2: Life(Zone.A_LOW, Zone.A_HIGH);  Armor(Zone.B_LOW, Zone.B_HIGH);  Helmet(Zone.D_LOW, Zone.D_HIGH);  Life(Zone.E_LOW, Zone.E_HIGH);  break;
    case 3: BigLife(Zone.A_LOW, Zone.A_HIGH);  break;
    default:  break;

  }


  return;
}
