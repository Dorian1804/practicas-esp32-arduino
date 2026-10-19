#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int IN1 = 26;
const int IN2 = 27;
const int ENA = 25;


const unsigned long TIEMPO_GIRO = 3000;  
const unsigned long TIEMPO_PAUSA = 500;  

LiquidCrystal_I2C lcd(0x27, 16, 2);

void mostrar(const char* sentido) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor DC");
  lcd.setCursor(0, 1);
  lcd.print(sentido);
}

void detener() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void girarDerecha() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void girarIzquierda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  digitalWrite(ENA, HIGH);
  detener();

  Wire.begin(21, 22); 
  lcd.init();
  lcd.backlight();
  mostrar("Iniciando...");
  delay(1000);
}

void loop() {
  
  mostrar("Giro: DERECHA");
  girarDerecha();
  delay(TIEMPO_GIRO);

  
  detener();
  mostrar("Detenido");
  delay(TIEMPO_PAUSA);

  mostrar("Giro: IZQUIERDA");
  girarIzquierda();
  delay(TIEMPO_GIRO);


  detener();
  mostrar("Detenido");
  delay(TIEMPO_PAUSA);
}
