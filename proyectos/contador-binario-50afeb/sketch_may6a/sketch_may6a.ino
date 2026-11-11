// C++ code
//

int analogPin = A0;
float V2;
double analogVal;
int blueLed = 3;
int luz = 100;

void setup()

{
pinMode(analogPin, INPUT); 
  Serial.begin(9600);
  pinMode(blueLed, OUTPUT);

}

void loop()
{
  analogVal = analogRead(analogPin);
  int valorPWM = map(analogVal, 0, 1023, 0, 255);
  Serial.println(V2);	
  V2=(5*analogVal)/1023.;

  if(V2>=3.00){
  
  digitalWrite(blueLed, HIGH);
    
  }
  else{
  digitalWrite(blueLed, LOW);
  }
}