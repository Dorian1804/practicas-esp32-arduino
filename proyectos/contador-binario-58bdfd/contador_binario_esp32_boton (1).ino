/*
  Contador binario con ESP32, 4 LEDs y un botón
  Cada vez que se presiona el botón, el contador incrementa en 1.
  Al llegar a 15, en la siguiente pulsación regresa a 0.

  Conexiones:
    D19 -> LED bit 0 (valor 1)
    D5  -> LED bit 1 (valor 2)
    D21 -> LED bit 2 (valor 4)
    D18 -> LED bit 3 (valor 8)
    D17 -> Botón (a GND, usando resistencia pull-up interna)
*/

const int pinBit0 = 19;  // valor 1
const int pinBit1 = 5;   // valor 2
const int pinBit2 = 21;  // valor 4
const int pinBit3 = 18;  // valor 8
const int pinBoton = 17;

const int pinesLED[] = {pinBit0, pinBit1, pinBit2, pinBit3};
const int numBits = 4;

int contador = 0;
bool subiendo = true;   // true = contando hacia arriba, false = hacia abajo

// --- Variables para el anti-rebote (debounce) ---
int estadoBotonActual;
int estadoBotonAnterior = HIGH;   // con pull-up, en reposo es HIGH
unsigned long ultimoCambio = 0;
const unsigned long antirrebote = 50;  // ms

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
        if (subiendo) {
          contador++;
          if (contador >= 15) {
            contador = 15;
            subiendo = false;   // llegó al tope, ahora baja
          }
        } else {
          contador--;
          if (contador <= 0) {
            contador = 0;
            subiendo = true;    // llegó al fondo, ahora sube
          }
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
