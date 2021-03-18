/* ir-distance sketch
  prints distance and changes LED flash rate based on distance from IR sensor
*/
const byte sensorPin1 = 0;
const byte sensorPin2 = 1;
const byte sensorPin3 = 2;
const byte sensorPin4 = 3;

const byte numSensor = 4;

int cmArray[4] = {0, 0, 0, 0};

const long referenceMv = 5000; // long int to prevent overflow when multiplied
void setup()
{
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
  delay(300);
}



// the following is used to interpolate the distance from a table
// table entries are distances in steps of 250 millivolts
const int TABLE_ENTRIES = 12;
const int firstElement = 2750; // first entry is 250 mV
const int INTERVAL = 250; // millivolts between each element
static int distance[TABLE_ENTRIES] = {150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 45};
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
