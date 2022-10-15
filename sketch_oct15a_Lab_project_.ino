int i=0;

int test = 0;
int temperature;
int baselineTemp = 0;
int celsius = 0;
int gas_input = A2;
int gas;
int buzzer = 8;
int a,b;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  a = temp();
  b = gasMesure();
  
    
  if(gas>30 && celsius>70){
    tone(buzzer,200);
    delay(100);
  }
  else{
    noTone(buzzer);
  }
 
  delay(100);
  
}
int temp(){
   baselineTemp = 40;
   celsius = map(((analogRead(A0) - 20) * 
                 3.04), 0, 1023, -40, 125);
  Serial.print(celsius);
  Serial.print(" C, \n");
  Serial.print(analogRead(A0));
  Serial.print("\n");
  return(celsius);
  
  /*if(celsius>70){
    tone(buzzer,200);
    delay(100);
  }
  else{
    noTone(buzzer);
  }*/
}
int gasMesure(){
   gas  = analogRead(A2);
  gas = map(gas, 300, 750, 0, 100);
  Serial.println(gas);
  
  return(gas);

}
