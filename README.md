Notar que el 6to sensor tiene logica inversa a los 5irs


  rightFarReading    = analogRead(rightFarSensor);
  Serial.print("rightFarReading ");
  Serial.print(rightFarReading);
  Serial.print("\t"); 
  // SOUTION to invert the analog value of the 6th IR sensor
  rightFarReading = 1023 - rightFarReading;
  Serial.print("SOLUTION rightFarReading ");
  Serial.print(rightFarReading);
  Serial.print("\t");

