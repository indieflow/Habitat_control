void heat1()  {  
  uint8_t i;
  float average1;
 
  // Take multiple readings, with a slight delay
  for(i=0; i< numsamples; i++)  {
   samples[i] = analogRead(thermHotPin1);
   delay(10);
  }
  
  // Average all the samples out
  average1 = 0;
  for(i=0; i< numsamples; i++)  {
     average1 += samples[i];
  }
  average1 /= numsamples;
  
  // Convert the value to resistance
  average1 = 1023 / average1 - 1;
  average1 = seriesResistor / average1;
 
  float hotendTemp;
  hotendTemp = average1 / thermistorNominal;         // (R/Ro)
  hotendTemp = log(hotendTemp);                      // ln(R/Ro)
  hotendTemp /= bCoefficient;                        // 1/B * ln(R/Ro)
  hotendTemp += 1.0 / (temperatureNominal + 273.15); // + (1/To)
  hotendTemp = 1.0 / hotendTemp;                     // Invert
  hotendTemp -= 273.15;                              // convert to C

  // Display info
  if(LCD==true)  {
  lcd.setCursor(0, 0);                               // Move cursor
  lcd.print("                    ");                 // Clear the line
  lcd.setCursor(0, 0); 
  lcd.print("H");
  lcd.setCursor(2, 0);
  if(fahrenheit==true)  {
    lcd.print((hotendTemp*9.0) / 5.0 + 32.0);        // Convert Celcius to Fahrenheit
  }
  else  {
    lcd.print(hotendTemp);
  }
  lcd.setCursor(7, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  if(fahrenheit==true)  {
    lcd.print("F");
  }
  else  {
    lcd.print("C"); 
  }
}
  else  {
  Serial.print("Hotend temperature = ");
  Serial.print(hotendTemp);
  Serial.println(" *C");
  }
   
  if(hotendTemp<hotend)  {                           // Check temperature verses global setting
    digitalWrite(relay_1, relay_ON);                 // Turns heating ON if less than
    if(LCD==true)  {
    lcd.setCursor(10, 0);
    //lcd.print("Heat ON");                          // Used on 20x4
    lcd.write(byte(4));
    }
    else  {
    Serial.println("Heat ON");      
    }
  }
  else  {
    digitalWrite(relay_1, relay_OFF);                // Turns heating OFF if more than
    if(LCD==true)  {
    lcd.setCursor(10, 0);
    //lcd.print("Heat OFF");                         // Used on 20x4
    lcd.write(byte(1));
    }
    else  {
    Serial.println("Heat OFF");      
    }   
  }
  
  lcd.setCursor(12, 0);
  lcd.print("Viv1"); 
}

void heat2()  {
  lcd.setCursor(0, 0);                               // Move cursor
  lcd.print("                    ");                 // Clear the line
  lcd.setCursor(0, 0); 
  lcd.print("Test");
  lcd.setCursor(12, 0);
  lcd.print("Viv2");
}
