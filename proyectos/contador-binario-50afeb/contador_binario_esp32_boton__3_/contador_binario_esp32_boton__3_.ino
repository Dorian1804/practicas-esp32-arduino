const int IN1 = 26;
const int IN2 = 27;
 const int ENA = 25; 

{

void setup() {
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA, OUTPUT); 


digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
analogWrite(ENA, 0);
 } 
void loop() 
{digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, 200); delay(5000); digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); 
analogWrite(ENA, 0); 
delay(2000); digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH);
analogWrite(ENA, 200);
delay(5000); 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW); 
analogWrite(ENA, 0);
 delay(2000); }
