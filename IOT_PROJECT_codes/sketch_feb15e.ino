
void setup() {
pinMode(A1,INPUT);
pinMode(A0,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  float A=analogRead(A1);
  float B=analogRead(A0);
  float C=analogRead(A2);
  float D=analogRead(A3);
float H=(A/1023)*100;
float I=(B/1023)*100;
float J=(C/619)*100;
float K=(D/619)*100;
Serial.println("Soil Moisture 1:");
Serial.println(H);
  delay(3000);
Serial.println("Soil Moisture 2:");
Serial.println(I);
delay(3000);
Serial.println("waterlevelsensor 1");
Serial.println(J);
  delay(3000);
Serial.println("waterlevelsensor 2");
Serial.println(K);
  delay(3000);
  // put your main code here, to run repeatedly:

}
