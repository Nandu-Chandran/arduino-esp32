int sensorPin = A0; // select the input pin for LDR

double Light(int raw_data)
{  double Vout=raw_data*0.0048828125;
  //int lux=500/(10*((5-Vout)/Vout));//use this equation if the LDR is in the upper part of the divider
  int lux=(2500/Vout-500)/10;
  return lux;
}
void setup() {
Serial.begin(9600); //sets serial port for communication
}
void loop() {
  Serial.print("Light Intensity:");
  Serial.print(int(Light(analogRead(sensorPin))));
  Serial.println(" Lux");
  delay(100);

}
