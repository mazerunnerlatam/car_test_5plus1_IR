/*
Remove ambient noise from sensor data.
IR LED  connected to Digital pin: 6
IR diode connected to analog input:A3
*/

// Analog as Digital
#define ir1 14 // This is A0
#define ir2 15 // This is A1
#define ir3 16
#define ir4 17
#define ir5 18
#define ir6 19 // Thhis is A5

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  Serial.println("About to start...");
  delay (1000);
}

void loop() {
  /*
  int slmm = analogRead(ir1);
  int slm = analogRead(ir2); // Please Notice this is a DigitalREAD
  int sl = analogRead(A2);
  int sr = analogRead(A3);
  int srm = analogRead(A4);
  int srmm = analogRead(A5); // Sensor Right More More in config 6 IRs
  */

  int slmm = !digitalRead(ir1); // Symbol !  means NOT
  int slm = digitalRead(ir2); // Please Notice this is a DigitalREAD
  int sl = digitalRead(A2);
  int sr = digitalRead(A3);
  int srm = digitalRead(A4);
  int srmm = digitalRead(A5); // Sensor Right More More in config 6 IRs



  Serial.print(slmm);
  Serial.print("\t");
  Serial.print(slm);
  Serial.print("\t");
  Serial.print(sl);
  Serial.print("\t");
  Serial.print(sr);
  Serial.print("\t");
  Serial.print(srm);
  Serial.print("\t");
  Serial.print(srm);
  Serial.println("\t => Notice one sensor has a DigitalREAD: 1 or 0");
  

  delay(500); 
}