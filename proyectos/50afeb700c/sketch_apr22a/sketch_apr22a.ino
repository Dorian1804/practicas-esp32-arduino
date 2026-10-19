int tiempo = 1000;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(tiempo);
  digitalWrite(13, LOW);
  delay(tiempo);

  digitalWrite(12, HIGH); 
  delay(tiempo);
  digitalWrite(12, LOW);
  delay(tiempo);

  digitalWrite(11, HIGH); 
  delay(tiempo);
  digitalWrite(11, LOW);
  delay(tiempo);

  digitalWrite(10, HIGH);
  delay(tiempo); 
  digitalWrite(10, LOW);
  delay(tiempo);
}