// Incluimos la librería de Adafruit para el DPS310
#include <Adafruit_DPS310.h>

// Creamos un objeto para manejar el sensor
Adafruit_DPS310 dps;

void setup() {
  // Iniciamos la comunicación serial a 115200 baudios
  Serial.begin(115200);
  // Esperamos a que el puerto serial esté listo (necesario en algunas placas)
  while (!Serial) delay(10);

  // Inicializamos el sensor en modo I²C
  if (!dps.begin_I2C()) {
    Serial.println("No se detectó el DPS310, revisa las conexiones.");
    while (1) delay(10); // Si no se detecta, se queda en bucle infinito
  }
  Serial.println("DPS310 detectado correctamente.");

  // Configuramos el sensor:
  // - 64 Hz de muestreo
  // - Promedio de 64 muestras para mayor precisión
  dps.configurePressure(DPS310_64HZ, DPS310_64SAMPLES);
  dps.configureTemperature(DPS310_64HZ, DPS310_64SAMPLES);
}

void loop() {
  // Creamos dos eventos para guardar las lecturas
  sensors_event_t temp_event, pressure_event;

  // Obtenemos las lecturas del sensor (presión y temperatura)
  dps.getEvent(&pressure_event, &temp_event);

  // Imprimimos la presión en hPa
  Serial.print("Presión: ");
  Serial.print(pressure_event.pressure);
  Serial.print(" hPa | ");

  // Imprimimos la temperatura en grados Celsius
  Serial.print("Temperatura: ");
  Serial.print(temp_event.temperature);
  Serial.println(" °C");

  // Esperamos 1 segundo antes de la siguiente lectura
  delay(1000);
}
