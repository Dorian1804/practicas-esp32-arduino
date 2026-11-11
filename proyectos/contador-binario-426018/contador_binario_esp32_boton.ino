
const int pinBit0 = 19;  // valor 1
const int pinBit1 = 5;   // valor 2
const int pinBit2 = 21;  // valor 4
const int pinBit3 = 18;  // valor 8
const int pinBoton = 17;

const int pinesLED[] = {pinBit0, pinBit1, pinBit2, pinBit3};
const int numBits = 4;

int contador = 0;

int estadoBotonActual;
int estadoBotonAnterior = HIGH;   
unsigned long ultimoCambio = 0;
const unsigned long antirrebote = 50;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < numBits; i++) {
    pinMode(pinesLED[i], OUTPUT);
    digitalWrite(pinesLED[i], LOW);
  }

  pinMode(pinBoton, INPUT_PULLUP);  // botón conectado entre el pin y GND

  actualizarLEDs();
}

void loop() {
  int lectura = digitalRead(pinBoton);

  // Si el estado cambió, reinicia el temporizador de antirrebote
  if (lectura != estadoBotonAnterior) {
    ultimoCambio = millis();
  }

  if ((millis() - ultimoCambio) > antirrebote) {
    // El estado ya es estable
    if (lectura != estadoBotonActual) {
      estadoBotonActual = lectura;

      // Detecta el flanco de bajada (botón presionado, con pull-up)
      if (estadoBotonActual == LOW) {
        contador++;
        if (contador > 15) {
          contador = 0;
        }
        actualizarLEDs();

        Serial.print("Contador: ");
        Serial.print(contador);
        Serial.print("  Binario: ");
        Serial.println(contador, BIN);
      }
    }
  }

  estadoBotonAnterior = lectura;
}

void actualizarLEDs() {
  for (int i = 0; i < numBits; i++) {
    digitalWrite(pinesLED[i], bitRead(contador, i));
  }
}
