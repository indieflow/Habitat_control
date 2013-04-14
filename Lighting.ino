void light1()  {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  lcd.setCursor(12, 1);                            
  lcd.write(byte(6));                                // Moon
  
//analogWrite(greenPin, 255);
  
  
  /*  int m, s;
  // Moon rise
  for(m = 0; m < 255; m++) { 
    analogWrite(bluePin, m);
    delay(fadespeed);
  }
 delay(10000);

  // Sun rise
  for(s = 0; s < 255; s++)
  {
    analogWrite(redPin, s);
    analogWrite(greenPin, s);
    delay(fadespeed);
  }
  delay(10000);
  
  // Sun set
  for(s = 255; s > 0; s--)
  {
    analogWrite(redPin, s);
    analogWrite(greenPin, s);
    delay(fadespeed);
  }
  delay(10000);
  
  // Moon set
  for (m = 255; m > 0; m--) { 
    analogWrite(bluePin, m);
    delay(fadespeed);
  }
 delay(10000);
 */
}

void light2()  {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);

  lcd.setCursor(12, 1);
  lcd.write(byte(5));                                // Sun
}
