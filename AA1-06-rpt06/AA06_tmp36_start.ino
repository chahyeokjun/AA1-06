//
// AA06, TMP36 sensor
//

#define TMP36_INPUT 0
#define CDS_INPUT 1
// or  int TEMP_INPUT = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   //Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting that reading to voltage
  float voltage = temp_value * 5.0 * 1000; // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10;

  // Lux from Cds (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
//
  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);
  
  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0; // 5/1023 (Vin = 5 V)
  int lux=(2500/Vout-500)/10;
  //lux = 500 / Ridr, Vout = lidr*Ridr = (5/(10 + Ridr))*Ridr
  return lux;
}
