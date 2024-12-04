#include <HX711.h>
#include <Stepper.h>
#include "pitches.h"

#define DOUT  3 
#define CLK  2
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define IN5 4                   //motor 2 premio
#define IN6 5                   //motor 2 premio
#define IN7 6                   //motor 2 premio
#define IN8 7                   //motor 2 premio
#define BUZZER_PIN 12           // Pin del buzzer

HX711 scale;
Stepper motor(200, IN1, IN3, IN2, IN4); // Configura el motor de dispensación de comida
Stepper motor_premio(200, IN5, IN7, IN6, IN8); // Configura el motor para entregar y cerrar el compartimiento del premio

float peso_minimo = 5.0;               // Peso mínimo para activar el motor (en gramos)
float peso_maximo = 80.0;              // Peso máximo para detener el motor (en gramos)
unsigned long intervalo_tiempo = 5000; // Tiempo mínimo entre dispensaciones (20 segundos en ms)
unsigned long ultimo_tiempo = 0;       // Último tiempo de activación del motor
unsigned long tiempo_maximo_dispensacion = 10000; // Tiempo máximo para la dispensación (10 segundos)

// Melodía para tocar cuando comienza el motor
int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4, 
  NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4, 
  NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
  NOTE_A4
};

int durations[] = {
  8, 8, 4, 4,
  8, 8, 4, 4,
  8, 8, 4, 4,
  2
};

void setup() {
  Serial.begin(9600);

  // Configuración de la celda de carga
  scale.begin(DOUT, CLK);
  scale.set_scale(980.f);    // Ajusta este valor según la calibración de la celda de carga
  scale.tare();               // Poner la balanza a cero
  
  // Configuración del motor paso a paso
  motor.setSpeed(150);         // Velocidad del motor de comida
  motor_premio.setSpeed(110);  // Velocidad del motor de premio (ajusta según tus necesidades)
  
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float peso_actual = scale.get_units(10);  // Leer el peso actual del plato con un promedio de 5 lecturas
  
  Serial.print("Peso actual: ");
  Serial.print(peso_actual);
  Serial.println(" g");

  // Verificar si el peso está por debajo del mínimo y si ha pasado el intervalo de tiempo de enfriamiento
  if ((peso_actual < peso_minimo) && (millis() - ultimo_tiempo >= intervalo_tiempo)) {
    Serial.println("Activando motor de comida...");
    unsigned long tiempo_inicio_dispensacion = millis();
    bool dispensado_exitosamente = false;

    // Dispensar comida hasta que el peso alcance el máximo o hasta alcanzar el tiempo máximo de dispensación
    while ((millis() - tiempo_inicio_dispensacion < tiempo_maximo_dispensacion) && !dispensado_exitosamente) {
      for (int i = 0; i < 50; i++) { // Hacer 50 pasos antes de leer el peso
        motor.step(10);         // Realiza 10 pasos
      }

      peso_actual = scale.get_units(10);  // Leer el peso después de realizar los pasos
      Serial.print("Peso durante dispensación: ");
      Serial.print(peso_actual);
      Serial.println(" g");

      if (peso_actual >= peso_maximo) {
        dispensado_exitosamente = true;      
      }
    }

    // Actualizar el tiempo de la última dispensación si fue exitosa o si se alcanzó el tiempo máximo
    ultimo_tiempo = millis();
    
    if (dispensado_exitosamente) {
      Serial.println("Desactivando motor de comida, dispensado exitosamente...");
    } else {
      Serial.println("Tiempo máximo de dispensación alcanzado, se detiene la dispensación.");
    }

    // Reproducir la melodía al comenzar a mover el motor
    playMelody();

    // Activar motor del premio
    Serial.println("Activando motor del premio para abrir el compartimiento...");
    motor_premio.step(1100);  // Realizar una vuelta completa (200 pasos)
    
    delay(500); // Pausar para dar tiempo a que el compartimiento se mantenga abierto
    
    Serial.println("Activando motor del premio para cerrar el compartimiento...");
    motor_premio.step(-1100);  // Realizar una vuelta completa en la dirección opuesta (200 pasos para cerrar)
  }

  // Mostrar el tiempo restante para la restricción de 20 segundos entre dispensaciones
  if (millis() - ultimo_tiempo < intervalo_tiempo) {
    unsigned long tiempo_restante = intervalo_tiempo - (millis() - ultimo_tiempo);
    unsigned long segundos_restantes = tiempo_restante / 1000;

    Serial.print("Tiempo restante para la siguiente dispensación: ");
    Serial.print(segundos_restantes);
    Serial.println(" segundos");
  }

  delay(500); // Pausa para evitar lecturas demasiado frecuentes del peso
}

// Función para reproducir la melodía al comienzo de mover el motor
void playMelody() {
  int size = sizeof(durations) / sizeof(int);
  for (int note = 0; note < size; note++) {
    // Calcular la duración de la nota
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    // Pausar entre notas
    int pauseBetweenNotes = duration * 1.10;
    delay(pauseBetweenNotes);

    // Detener el tono
    noTone(BUZZER_PIN);
  }
}
