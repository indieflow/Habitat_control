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
 
  float hotendTemp1;
  hotendTemp1 = average1 / thermistorNominal;            // (R/Ro)
  hotendTemp1 = log(hotendTemp1);                        // ln(R/Ro)
  hotendTemp1 /= bCoefficient;                           // 1/B * ln(R/Ro)
  hotendTemp1 += 1.0 / (temperatureNominal + 273.15);    // + (1/To)
  hotendTemp1 = 1.0 / hotendTemp1;                       // Invert
  hotendTemp1 -= 273.15;                                 // convert to C
  if(fahrenheit==true)  {
    hotendTemp1 = ((hotendTemp1*9.0) / 5.0 + 32.0);
  }

  // Display info
  if(LCD==true)  {
    if(LCD_WIDTH<20)  {
      lcd.setCursor(0, 0);                               // Move cursor
      lcd.print("                    ");                 // Clear the line
      lcd.setCursor(0, 0); 
      lcd.print("H");
      lcd.setCursor(1, 0);
      lcd.write(byte(1));
      lcd.setCursor(2, 0);
      lcd.print(hotendTemp1);
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
      lcd.setCursor(0, 1);                                
      lcd.print("                    ");                  
      lcd.setCursor(0, 1);
      lcd.print("H");
      lcd.setCursor(1, 1);
      lcd.write(byte(1));
      lcd.setCursor(3, 1);
      lcd.print(hotendTemp1);
      lcd.setCursor(8, 1);
      lcd.write(byte(0));
      lcd.setCursor(9, 1);
      if(fahrenheit==true)  {
        lcd.print("F");
      }
      else  {
        lcd.print("C"); 
      }      
    }
  }
  else  {
    Serial.print("Hotend temperature = ");
    Serial.print(hotendTemp1);
    }
    if(fahrenheit==true)  {
      Serial.println(" *F");
    }
    else  {
      Serial.println(" *C");
    }
 
  // Adjust Heating
  if(LCD_WIDTH<20)  {  
    if(hotendTemp1<hotend1)  {                           // Check temperature verses global setting
    digitalWrite(relay_1, relay_ON);                     // Turns heating ON if less than
    if(LCD==true)  {
      lcd.setCursor(10, 0);
      lcd.write(byte(5));
    }
    else  {
    Serial.println("Heat ON");      
    }
  }
  else  {
    digitalWrite(relay_1, relay_OFF);                    // Turns heating OFF if more than
    if(LCD==true)  {
      lcd.setCursor(10, 0);
      lcd.write(byte(2));
    }
    else  {
    Serial.println("Heat OFF");      
    }   
  }
  }
  else  {
    if(hotendTemp1<hotend1)  {                           // Check temperature verses global setting
    digitalWrite(relay_1, relay_ON);                     // Turns heating ON if less than
    if(LCD==true)  {
      lcd.setCursor(11, 1);
      lcd.print("Heat ON");                              
    }
    else  {
    Serial.println("Heat ON");      
    }
  }
  else  {
    digitalWrite(relay_1, relay_OFF);                    // Turns heating OFF if more than
    if(LCD==true)  {
      lcd.setCursor(11, 1);
    lcd.print("Heat OFF");                               
    }
    else  {
    Serial.println("Heat OFF");      
    }   
  }
}
lcd.setCursor(12, 0);
lcd.print("Viv1"); 
}

void heat2()  {  
  uint8_t i;
  float average3;
 
  // Take multiple readings, with a slight delay
  for(i=0; i< numsamples; i++)  {
   samples[i] = analogRead(thermHotPin2);
   delay(10);
  }
  
  // Average all the samples out
  average3 = 0;
  for(i=0; i< numsamples; i++)  {
     average3 += samples[i];
  }
  average3 /= numsamples;
  
  // Convert the value to resistance
  average3 = 1023 / average3 - 1;
  average3 = seriesResistor / average3;
 
  float hotendTemp2;
  hotendTemp2 = average3 / thermistorNominal;            // (R/Ro)
  hotendTemp2 = log(hotendTemp2);                        // ln(R/Ro)
  hotendTemp2 /= bCoefficient;                           // 1/B * ln(R/Ro)
  hotendTemp2 += 1.0 / (temperatureNominal + 273.15);    // + (1/To)
  hotendTemp2 = 1.0 / hotendTemp2;                       // Invert
  hotendTemp2 -= 273.15;                                 // convert to C
  if(fahrenheit==true)  {
    hotendTemp2 = ((hotendTemp2*9.0) / 5.0 + 32.0);
  }

  // Display info
  if(LCD==true)  {
    if(LCD_WIDTH<20)  {
      lcd.setCursor(0, 0);                               // Move cursor
      lcd.print("                    ");                 // Clear the line
      lcd.setCursor(0, 0); 
      lcd.print("H");
      lcd.setCursor(1, 0);
      lcd.write(byte(1));
      lcd.setCursor(2, 0);
      lcd.print(hotendTemp2);
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
      lcd.setCursor(0, 1);                                
      lcd.print("                    ");                  
      lcd.setCursor(0, 1);
      lcd.print("H");
      lcd.setCursor(1, 1);
      lcd.write(byte(1));
      lcd.setCursor(3, 1);
      lcd.print(hotendTemp2);
      lcd.setCursor(8, 1);
      lcd.write(byte(0));
      lcd.setCursor(9, 1);
      if(fahrenheit==true)  {
        lcd.print("F");
      }
      else  {
        lcd.print("C"); 
      }      
    }
  }
  else  {
    Serial.print("Hotend temperature = ");
    Serial.print(hotendTemp2);
    }
    if(fahrenheit==true)  {
      Serial.println(" *F");
    }
    else  {
      Serial.println(" *C");
    }
 
  // Adjust Heating
  if(LCD_WIDTH<20)  {  
    if(hotendTemp2<hotend2)  {                           // Check temperature verses global setting
    digitalWrite(relay_3, relay_ON);                     // Turns heating ON if less than
    if(LCD==true)  {
      lcd.setCursor(10, 0);
      lcd.write(byte(5));
    }
    else  {
    Serial.println("Heat ON");      
    }
  }
  else  {
    digitalWrite(relay_3, relay_OFF);                    // Turns heating OFF if more than
    if(LCD==true)  {
      lcd.setCursor(10, 0);
      lcd.write(byte(2));
    }
    else  {
    Serial.println("Heat OFF");      
    }   
  }
  }
  else  {
    if(hotendTemp2<hotend2)  {                           // Check temperature verses global setting
    digitalWrite(relay_3, relay_ON);                     // Turns heating ON if less than
    if(LCD==true)  {
      lcd.setCursor(10, 1);
      lcd.print("Heat ON");                              
    }
    else  {
    Serial.println("Heat ON");      
    }
  }
  else  {
    digitalWrite(relay_3, relay_OFF);                    // Turns heating OFF if more than
    if(LCD==true)  {
      lcd.setCursor(10, 1);
    lcd.print("Heat OFF");                               
    }
    else  {
    Serial.println("Heat OFF");      
    }   
  }
}
lcd.setCursor(12, 0);
lcd.print("Viv2"); 
}
