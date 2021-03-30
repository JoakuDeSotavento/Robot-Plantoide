// tarjeta SD
#include <SPI.h>
#include <SD.h>
const int chipSelect = 4;

/////////////// Creación del mapa
long movX = 0;
long movY = 0;
long incazzato = 0;
unsigned long previousMillis = 0;        // will store last time LED was updated

// sensores
const byte sensorPin1 = 0;
const byte sensorPin2 = 1;
const byte sensorPin3 = 2;
const byte sensorPin4 = 3;

const int umbral = 120;
const int umbral2 = 100;

//const int umbral = 120;
//const int umbral2 = 100;

const byte numSensor = 4;
int cmArray[4] = {0, 0, 0, 0};

// the following is used to interpolate the distance from a table
// table entries are distances in steps of 250 millivolts
const long referenceMv = 5000; // long int to prevent overflow when multiplied
const byte TABLE_ENTRIES = 12;
const int firstElement = 2750; // first entry is 250 mV
const int INTERVAL = 250; // millivolts between each element
static int distance[TABLE_ENTRIES] = {150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 45};

////////////////////////////////////////////////////////////////////////////////

const byte MOTOR_L = 9; // the pin for the left motor power
const byte MOTOR_R = 10; // the pin for the right motor power

int speed_change_dir = 0;
int max_speed = 255;
int min_speed = 0;
int zero_speed = 135;
int fSpeed = 170;
int bSpeed = 100;
int speed_step = 1; // how much the speed in/decrease per each button press
int current_speed = zero_speed;

byte estado = 0;

void setup()
{
  // inicializaciones de la base
  pinMode(MOTOR_L, OUTPUT); // tell Arduino LED is an output
  pinMode(MOTOR_R, OUTPUT); // tell Arduino LED is an output
  attachInterrupt(0, change_speed, FALLING);
  Serial.begin(9600);
  speed_change_dir = 1;
  randomSeed(analogRead(5));
  analogWrite(MOTOR_L, zero_speed);
  analogWrite(MOTOR_R, zero_speed);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void upadate() {
  for (int i = 0; i < numSensor; i++) {
    cmArray[i] = getDistance(i);
    /* Serial.print("Sensor");
      Serial.print(i);
      Serial.print(":");
      Serial.print(cmArray[i]);
      Serial.print("\t");
    */
  }
  /*
    Serial.print("Velocity:");
    Serial.print(current_speed);
    Serial.print("\t");
    Serial.print("Estado:");
    Serial.print(estado);
    Serial.println();
  */
}

void change_speed()
{
  /*
    if (current_speed <= (max_speed - speed_step))
    {
    current_speed = current_speed + speed_step;
    }
    else
    {
    current_speed = zero_speed;
    }*/

  if (current_speed >= (0 + speed_step))
  {
    current_speed = current_speed - speed_step;
  }
  else
  {
    current_speed = zero_speed;
  }
}

void loop()
{
  upadate();
  checkIR();
  switch (estado) {
    //movimientos(); 0 stop, 1 ->, 2 <-, 3 giro derecha, 4 giro izquierda
    // movimientos si un solo sensor percibe algo
    case 0:
      // no se mueve
      // variables del mapa
      movX = movX;
      movY = movY;
      if (timer(10000)) {
        if (incazzato > 0) {
          incazzato--;
          //sdWrite(movX, movY, incazzato);
          //delay(30);
        }
      }
      // función de movimiento
      movimientos(0);
      delay(100);
      break;
    case 1:
      // si el sensor forntal detecta, da marcha a trás
      movX = movX;
      movY -= 1;
      incazzato++;
      movimientos(2);
      delay(300);
      sdWrite(movX, movY, incazzato);
      delay(30);
      break;
    case 2:
      // si el sensor izquierdo detecta, gira a la derecha y avanza
      movX += 1;
      movY = movY;
      incazzato++;
      movimientos(3);
      delay(300);
      sdWrite(movX, movY, incazzato);
      delay(30);
      break;
    case 3:
      // si el sensor trasero detecta, da marcha hacia delante
      movX = movX;
      movY += 1;
      incazzato++;
      movimientos(1);
      delay(300);
      sdWrite(movX, movY, incazzato);
      delay(30);
      break;
    case 4:
      // si el sensor derecho detecta, gira a la izquierda y avanza
      movX -= 1;
      movY = movY;
      incazzato++;
      movimientos(4);
      delay(300);
      sdWrite(movX, movY, incazzato);
      delay(30);
      break;
    // movimientos si dos sensores perciben cosas
    case 5:
      // si los sensores frontales y el izquierdo, gira 45 grados a la izquierda y da marcha atrás
      movimientos(0);
      delay(100);
      break;
    case 6:
      // si los sensores frontales y trasero, gira 180 a derecha o izquierda y da marcha delante o atrás
      movimientos(0);
      delay(100);
      break;
    case 7:

      break;

    case 8:

      break;

    case 9:

      break;

    case 10:

      break;

    case 11:

      break;

    case 12:

      break;

    case 13:

      break;

    case 14:

      break;

    case 15:

      break;
  }

}
