// ======================================
// CONTADOR BINARIO ASCENDENTE/DESCENDENTE
// ESP32 - Arduino IDE
// ======================================

// Salidas
const int SALIDA_1 = 19;   // Bit 1
const int SALIDA_2 = 5;    // Bit 2
const int SALIDA_4 = 21;   // Bit 4
const int SALIDA_8 = 18;   // Bit 8

// Botón
const int BOTON = 17;

// Número actual
int contador = 0;

// Dirección:
// 1  = contando hacia arriba
// -1 = contando hacia abajo
int direccion = 1;

// Estado anterior del botón
int estadoAnterior = HIGH;

// Antirrebote
unsigned long ultimoCambio = 0;
const unsigned long debounce = 50;


// ======================================
// CONFIGURACIÓN
// ======================================

void setup() {

  pinMode(SALIDA_1, OUTPUT);
  pinMode(SALIDA_2, OUTPUT);
  pinMode(SALIDA_4, OUTPUT);
  pinMode(SALIDA_8, OUTPUT);

  // Botón entre GPIO17 y GND
  pinMode(BOTON, INPUT_PULLUP);

  // Mostrar 0 al iniciar
  mostrarNumero(contador);
}


// ======================================
// PROGRAMA PRINCIPAL
// ======================================

void loop() {

  int estadoActual = digitalRead(BOTON);

  // Detectar una nueva pulsación
  if (estadoActual == LOW && estadoAnterior == HIGH) {

    // Antirrebote
    if (millis() - ultimoCambio > debounce) {

      // Cambiar número
      contador = contador + direccion;

      // Llegó a 15
      if (contador >= 15) {
        contador = 15;
        direccion = -1;
      }

      // Llegó a 0
      if (contador <= 0) {
        contador = 0;
        direccion = 1;
      }

      // Actualizar salidas
      mostrarNumero(contador);

      // Guardar tiempo
      ultimoCambio = millis();
    }
  }

  // Guardar estado del botón
  estadoAnterior = estadoActual;
}


// ======================================
// MOSTRAR NÚMERO EN BINARIO
// ======================================

void mostrarNumero(int numero) {

  digitalWrite(SALIDA_1, (numero & 1) ? HIGH : LOW);

  digitalWrite(SALIDA_2, (numero & 2) ? HIGH : LOW);

  digitalWrite(SALIDA_4, (numero & 4) ? HIGH : LOW);

  digitalWrite(SALIDA_8, (numero & 8) ? HIGH : LOW);
}