# Sensor DPS310 - ESP32  

Este repositorio contiene programas de ejemplo para la lectura de **presión barométrica y temperatura** utilizando el sensor **DPS310** en conjunto con un **ESP32**, programado desde el **Arduino IDE**.  

El sistema permite adquirir datos atmosféricos en tiempo real, con posibilidad de extenderse a aplicaciones de **altimetría, IoT, monitoreo ambiental y proyectos aeroespaciales experimentales**.  

## Archivos incluidos  

- **DPS310.ino**  
  Código base de prueba que inicializa el sensor y muestra lecturas de presión (hPa) y temperatura (°C) en el monitor serial cada 1 segundo.  

## Requisitos  

- **Arduino IDE**  
- Librerías:  
  - `Adafruit_DPS310`  
  - `Adafruit_Sensor`  
  - *(Opcional)* `Wire` – ya incluida de manera indirecta, pero necesaria si se quiere usar comunicación I²C manual.  

## Conexiones  

El sensor DPS310 utiliza comunicación **I2C**. En el ESP32, las conexiones recomendadas son:  

- **SDA → GPIO21**  
- **SCL → GPIO22**  
- **VDD / VDDIO → 3.3V**  
- **GND → GND**  

> ⚠️ Importante: el DPS310 debe alimentarse con **3.3V**. Conectarlo a **5V puede dañar el sensor**.  

© Diego Barajas, 2025  
