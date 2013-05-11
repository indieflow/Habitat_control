void cool1()  {
  uint8_t i;
  float average2;
 
  // Take multiple readings, with a slight delay
  for(i=0; i< numsamples; i++)  {
   samples[i] = analogRead(thermCoolPin1);
   delay(10);
  }
  
  // Average all the samples out
  average2 = 0;
  for(i=0; i< numsamples; i++)  {
     average2 += samples[i];
  }
  average2 /= numsamples;
  
  // Convert the value to resistance
  average2 = 1023 / average2 - 1;
  average2 = seriesResistor / average2;
 
  float coolendTemp;
  coolendTemp = average2 / thermistorNominal;         // (R/Ro)
  coolendTemp = log(coolendTemp);                     // ln(R/Ro)
  coolendTemp /= bCoefficient;                        // 1/B * ln(R/Ro)
  coolendTemp += 1.0 / (temperatureNominal + 273.15); // + (1/To)
  coolendTemp = 1.0 / coolendTemp;                    // Invert
  coolendTemp -= 273.15;                              // convert to C
  if(fahrenheit==true)  {
    coolendTemp = ((coolendTemp*9.0) / 5.0 + 32.0);
  }
  
  // Display info
  if(LCD==true)  {                                    // To determine LCD or Serial
    if(LCD_WIDTH<20)  {                               // If 16x2 LCD used
      lcd.setCursor(0, 1);                            // Move cursor
      lcd.print("                ");                  // Clear the line
      lcd.setCursor(0, 1);
      lcd.print("C");
      lcd.setCursor(1, 1);
      lcd.write(byte(1));                             // Insert character
      lcd.setCursor(2, 1);
      lcd.print(coolendTemp);
      lcd.setCursor(7, 1);
      lcd.write(byte(0));
      lcd.setCursor(8, 1);
      if(fahrenheit==true)  {
        lcd.print("F");
      }
      else  {
        lcd.print("C"); 
      }
    }
    else  {
      lcd.setCursor(0, 2);                                
      lcd.print("                    ");                  
      lcd.setCursor(0, 2);
      lcd.print("C");
      lcd.setCursor(1, 2);
      lcd.write(byte(1));
      lcd.setCursor(3, 2);
      lcd.print(coolendTemp);
      lcd.setCursor(8, 2);
      lcd.write(byte(0));
      lcd.setCursor(9, 2);
      if(fahrenheit==true)  {
        lcd.print("F");
      }
      else  {
        lcd.print("C"); 
      }
    }
  }
  else  {
    Serial.print("Coolend temperature = ");
    Serial.print(coolendTemp);
    }
    if(fahrenheit==true)  {
      Serial.println(" *F");
    }
    else  {
      Serial.println(" *C");
    }
 
 if(fans==true)  {
  if(LCD_WIDTH<20)  {
    if(coolendTemp>coolend+2)  {                      // Check temperature vs global setting
    analogWrite(fanPin, 255);                         // Accelerate fan to full speed
    if(LCD==true)  {
      lcd.setCursor(10, 1);
      lcd.write(byte(5));
    }
    else  {
    Serial.println("Fan 100%");      
    }
  }
  else if (coolendTemp>coolend+1)  {
    analogWrite(fanPin, 190);                         // Accelerate fan to half speed
    if(LCD==true)  {
      lcd.setCursor(10, 1);
      lcd.write(byte(4));
    }
    else  {
    Serial.println("Fan 50%");      
    }
  }
  else if (coolendTemp>coolend)  {
    analogWrite(fanPin, 130);                         // Accelerate fan to quarter speed
    if(LCD==true)  {
      lcd.setCursor(10, 1);
      lcd.write(byte(3));
    }
    else  {
    Serial.println("Fan 25%");      
    }   
  }
  else  {
    analogWrite(fanPin, 0);                           // Turn fan OFF
    if(LCD==true)  {
      lcd.setCursor(10, 1);
      lcd.write(byte(2));
    }
    else  {
    Serial.println("Fan OFF");
    }
  }
  }
  else  {
    if(coolendTemp>coolend+2)  {                      // Check temperature vs global setting
    analogWrite(fanPin, 255);                         // Accelerate fan to full speed
    if(LCD==true)  {
      lcd.setCursor(11, 2);
      lcd.print("Fan 100%");                          
    }
    else  {
    Serial.println("Fan 100%");      
    }
  }
  else if (coolendTemp>coolend+1)  {
    analogWrite(fanPin, 190);                         // Accelerate fan to half speed
    if(LCD==true)  {
      lcd.setCursor(11, 2);
      lcd.print("Fan 50%");                           
    }
    else  {
    Serial.println("Fan 50%");      
    }
  }
  else if (coolendTemp>coolend)  {
    analogWrite(fanPin, 130);                         // Accelerate fan to quarter speed
    if(LCD==true)  {
      lcd.setCursor(11, 2);
      lcd.print("Fan 25%");                           
    }
    else  {
    Serial.println("Fan 25%");      
    }   
  }
  else  {
    analogWrite(fanPin, 0);                           // Turn fan OFF
    if(LCD==true)  {
      lcd.setCursor(11, 2);
      lcd.print("Fan OFF");                           
    }
    else  {
    Serial.println("Fan OFF");
    }
  }    
}
}
}


//void cool2()  {
//}
