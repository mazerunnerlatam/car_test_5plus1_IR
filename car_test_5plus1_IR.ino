#define leftCenterSensor   17
#define leftNearSensor     18
#define leftFarSensor      19
#define rightCenterSensor  16
#define rightNearSensor    15
#define rightFarSensor     14

int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;

#define led2 2
#define led3 3
#define led4 4
#define led5 5
#define led6 6
#define led7 7

void setup(){
  
  pinMode(leftCenterSensor, INPUT);
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(rightCenterSensor, INPUT);
  pinMode(rightNearSensor, INPUT);
  pinMode(rightFarSensor, INPUT);

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("About to start...");
  delay (1000);
}

void loop(){
  
 readSensors();                                                                                     
 if(leftFarReading>200){ 
    Serial.print("leftFarReading>200");
    Serial.print("\t");
    digitalWrite(2, HIGH);                                                                         
  }
  else{                                                                                              
    Serial.print("NOT leftFarReading>200");
    Serial.print("\t");
    digitalWrite(2, LOW);                                                       
  }
 
 if(leftNearReading>200){
    Serial.print("leftNearReading>200");
    Serial.print("\t");
    digitalWrite(3, HIGH);                                                                         
  }
  else{                                                                                              
    Serial.print("NOT leftNearReading>200");
    Serial.print("\t");
    digitalWrite(3, LOW);                                                       
  }
  


 if(leftCenterReading>200){ 
    Serial.print("leftCenterReading>200");
    Serial.print("\t");
    digitalWrite(4, HIGH);                                                                         
  }
  else{                                
    Serial.print("NOT leftCenterReading>200");
    Serial.print("\t");
    digitalWrite(4, LOW);                                                       
  }



   
  if(rightCenterReading>200){ 
    Serial.print("rightCenterReading>200");
    Serial.print("\t");
    digitalWrite(5, HIGH);                                                                         
  }
  else{                                                                                              
    Serial.print("NOT rightCenterReading>200");
    Serial.print("\t");
    digitalWrite(5, LOW);                                                       
  }
   if(rightNearReading>200){ 
    Serial.print("rightNearReading>200");
    Serial.print("\t");
    digitalWrite(6, HIGH);                                                                         
  }
  else{                                                                                              
    Serial.print("NOT rightNearReading>200");
    Serial.print("\t");
    digitalWrite(6, LOW);                                                       
  }
  // Nota el cambio en la logica con el NOT con el simbolo: if(!(rightFarReading>200))
  // Pero es mejor modificar readSensors()   rightFarReading = 1023 - rightFarReading;
  if(rightFarReading>200){ 
    Serial.print("rightFarReading>200");
    Serial.print("\t");
    digitalWrite(7, HIGH);                                                                         
  }
  else{                                                                                              
    Serial.print("NOT rightFarReading>200");
    Serial.print("\t");
    digitalWrite(7, LOW);                                                       
  }
  Serial.println();

}

void readSensors(){
  
  //Ambos al aire 22:51:00.174 -> leftNearReading 964	rightFarReading 22
  //leftNearReading con linea negra 22:52:12.942 -> leftNearReading 5	rightFarReading 21
  //rightFarReading con linea negra 22:55:11.448 -> leftNearReading 966	rightFarReading 877

  leftCenterReading  = analogRead(leftCenterSensor);
  leftNearReading    = analogRead(leftNearSensor);
  //Serial.print("leftNearReading ");
  //Serial.print(leftNearReading);
  //Serial.print("\t"); 

  leftFarReading     = analogRead(leftFarSensor);
  rightCenterReading = analogRead(rightCenterSensor);
  rightNearReading   = analogRead(rightNearSensor);

  rightFarReading    = analogRead(rightFarSensor);
  //Serial.print("rightFarReading ");
  //Serial.print(rightFarReading);
  //Serial.print("\t"); 
  // SOUTION to invert the analog value of the 6th IR sensor
  rightFarReading = 1023 - rightFarReading;
  //Serial.print("SOLUTION rightFarReading ");
  //Serial.print(rightFarReading);
  //Serial.print("\t");
  //Serial.println();
}
