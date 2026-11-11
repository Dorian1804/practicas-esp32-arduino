const int PIN_ADC = 34;
const int LEDS[]  = {16, 17, 18, 19};
const int N = 4;
const int N_INICIAL = 3;      // LEDs antes del escalón
const int N_FINAL   = 2;      // LEDs después del escalón
const int NMUESTRAS = 3000;   // 3 s a 1 kHz
const int I_ESCALON = 500;    // el escalón ocurre en la muestra 500 (0.5 s)
uint16_t buf[NMUESTRAS];

void ponerLeds(int n) {
  for (int i = 0; i < N; i++) digitalWrite(LEDS[i], i < n ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);
  analogSetPinAttenuation(PIN_ADC, ADC_11db);
  for (int i = 0; i < N; i++) pinMode(LEDS[i], OUTPUT);
  ponerLeds(N_INICIAL);
  delay(8000);                           // estabilizar (la LDR tarda en asentarse)

  unsigned long t0 = micros();
  for (int i = 0; i < NMUESTRAS; i++) {
    while (micros() - t0 < (unsigned long)i * 1000) {}
    if (i == I_ESCALON) ponerLeds(N_FINAL);
    buf[i] = analogReadMilliVolts(PIN_ADC);
  }
  Serial.println("t_ms,n_leds,y_V");
  for (int i = 0; i < NMUESTRAS; i++)
    Serial.printf("%d,%d,%.4f\n", i, i < I_ESCALON ? N_INICIAL : N_FINAL, buf[i] / 1000.0);
  Serial.println("FIN");
}

void loop() {}