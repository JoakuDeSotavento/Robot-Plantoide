// sensores
const byte sensorPin1 = 0;
const byte sensorPin2 = 1;
const byte sensorPin3 = 2;
const byte sensorPin4 = 3;
const byte sensorPin5 = 4;
const byte sensorPin6 = 5;

const byte numSensor = 6;
int cmArray[numSensor] = {0, 0, 0, 0, 0, 0};

// the following is used to interpolate the distance from a table
// table entries are distances in steps of 250 millivolts
const long referenceMv = 5000; // long int to prevent overflow when multiplied
const byte TABLE_ENTRIES = 12;
const int firstElement = 2750; // first entry is 250 mV
const int INTERVAL = 250; // millivolts between each element
static int distance[TABLE_ENTRIES] = {150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 45};

////////////////////////////////////////////////////////////////////////////////
const byte MOTOR_L = 10; // the pin for the left motor power
const byte MOTOR_R = 11; // the pin for the right motor power

int max_speed = 255;
int min_speed = 0;
int zero_speed = 135;
int current_speed = zero_speed;

void setup()
{
  pinMode(MOTOR_L, OUTPUT); // tell Arduino LED is an output
  pinMode(MOTOR_R, OUTPUT); // tell Arduino LED is an output
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < numSensor; i++) {
    cmArray[i] = getDistance(i);
    Serial.print("Sensor:");
    Serial.print(cmArray[i]);
    Serial.print("\t");
  }
  Serial.println();

  analogWrite(MOTOR_L, current_speed);
  analogWrite(MOTOR_R, current_speed);
 }

int getDistance(int _pin)
{
  int val = analogRead(_pin);
  int mV = (val * referenceMv) / 1023;
  if ( mV > INTERVAL * TABLE_ENTRIES - 1 )
    return distance[TABLE_ENTRIES - 1];
  else
  {
    int index = mV / INTERVAL;
    float frac = (mV % 250) / (float)INTERVAL;
    return distance[index] - ((distance[index] - distance[index + 1]) * frac);
  }
}
