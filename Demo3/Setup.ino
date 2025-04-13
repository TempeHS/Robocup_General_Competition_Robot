void lcd_setup(const char* _software_version) {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("V: ");
  lcd.print(_software_version);
  Serial.print("V: ");
  Serial.println(_software_version);
}

void rgb_sen_setup () {
  if (tcs.begin()) {
    Serial.println("Found RGB sensor");
    lcd.setCursor(0,1);
    lcd.println("Found RGB sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    lcd.setCursor(0,1);
    lcd.println("NO RGB SENSOR!");
  }

  // Convert RGB colors to what humans see
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    gammatable[i] = 255 - x;

  }
}