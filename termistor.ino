#define termistorPin A0
#define termistorNominalRes 100000      //100k
#define termistorNominalTemp 25         //25 grados Celcius
#define termistorBValue 3950
#define VoltageDivideResistor 100000


float termistorRes=0.0;
float steinhart;
float Fahrenheit=0;
void setup(){
        Serial.begin(115200);
        analogReference(EXTERNAL);
}
void loop(){
        termistorRes = ((float)analogRead(termistorPin)*VoltageDivideResistor)/(1023-(float)analogRead(termistorPin));
        steinhart = termistorRes / termistorNominalRes;         // R/Ro
        steinhart = log(steinhart);                                                     // ln(R/Ro)
        steinhart /= termistorBValue;                                           // 1/B * ln(R/Ro)
        steinhart += 1.0 / (termistorNominalTemp + 273.15);     // +(1/To)
        steinhart = 1.0 / steinhart;                                            // Invert
        steinhart -= 273.15;                                                            // convertir a Celcius
  Fahrenheit = ((steinhart*9)/5)+32;
        Serial.print("Temp: \t");
        Serial.print(steinhart);
  Serial.print(" *C\n\t");
  Serial.print(Fahrenheit);
  Serial.print(" Fahrenheit\n\n");
        delay(1000);

}
