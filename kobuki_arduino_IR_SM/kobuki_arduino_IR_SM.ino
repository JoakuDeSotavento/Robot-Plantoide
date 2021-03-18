// sensores
const byte sensorPin1 = 0;
const byte sensorPin2 = 1;
const byte sensorPin3 = 2;
const byte sensorPin4 = 3;

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

const byte BUMPER_R = 7;
const byte BUMPER_C = 6;
const byte BUMPER_L = 5;
const byte WELL_DROP = 4;

const byte MOTOR_L = 10; // the pin for the left motor power
const byte MOTOR_R = 11; // the pin for the right motor power

int speed_change_dir = 0;
int max_speed = 255;
int min_speed = 0;
int zero_speed = 135;
int speed_step = 1; // how much the speed in/decrease per each button press
int current_speed = zero_speed;

byte estado = 0;

void setup()
{
  pinMode(BUMPER_R, INPUT);
  pinMode(BUMPER_C, INPUT);
  pinMode(BUMPER_L, INPUT);
  pinMode(WELL_DROP, INPUT);
  pinMode(MOTOR_L, OUTPUT); // tell Arduino LED is an output
  pinMode(MOTOR_R, OUTPUT); // tell Arduino LED is an output
  attachInterrupt(0, change_speed, FALLING);
  Serial.begin(9600);
  speed_change_dir = 1;
  randomSeed(analogRead(5));
}
/*
  int check_bumpers()
  {
  int bumps = 0;
  if (analogRead(BUMPER_R) > 100)
  {
    digitalWrite(BUMPER_R_LED, HIGH);
    bumps = bumps + 1;
  }
  else
  {
    digitalWrite(BUMPER_R_LED, LOW);
  }
  if (analogRead(BUMPER_C) > 100)
  {
    digitalWrite(BUMPER_C_LED, HIGH);
    bumps = bumps + 2;
  }
  else
  {
    digitalWrite(BUMPER_C_LED, LOW);
  }
  if (analogRead(BUMPER_L) > 100)
  {
    digitalWrite(BUMPER_L_LED, HIGH);
    bumps = bumps + 4;
  }
  else
  {
    digitalWrite(BUMPER_L_LED, LOW);
  }
  return bumps;
  }

  /**
   speed: 0 ... 127 ... 255 = full speed backward ... stop ... full speed forward
*/



void upadate() {
  for (int i = 0; i < numSensor; i++) {
    cmArray[i] = getDistance(i);
    Serial.print("Sensor:");
    Serial.print(cmArray[i]);
    Serial.print("\t");
  }
  Serial.print("Velocity:");
  Serial.print(current_speed);
  Serial.print("\t");
  Serial.print("Estado:");
  Serial.print(estado);
  Serial.println();
}

int checkIR() {

  if (cmArray[1] <= 70){ 
    estado = 1;
  }else {
    estado = 0;
    }

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

  //analogWrite(MOTOR_L, zero_speed);
  //analogWrite(MOTOR_R, zero_speed);

  switch (estado) {
    case 0:
      analogWrite(MOTOR_L, zero_speed);
      analogWrite(MOTOR_R, zero_speed);
      break;
    case 1:
      analogWrite(MOTOR_L, 170);
      analogWrite(MOTOR_R, 170);
      break;
  }

  /*
    Serial.println("------");
    int bumps = 0;
    bumps = check_bumpers();
    if (bumps > 0)
    {
    Serial.print("Bumps: ");
    Serial.println(bumps);
    // first go backwards a bit
    analogWrite(MOTOR_L, (zero_speed - speed_step));
    analogWrite(MOTOR_R, (zero_speed - speed_step));
    delay(300);
    // then turn
    switch (bumps)
    {
      case 1: // bumper right hit -> turn left a bit
        analogWrite(MOTOR_L, -current_speed);
        analogWrite(MOTOR_R, current_speed);
        delay(random(100, 300));
        break;
      case 2: // bumper middle hit -> turn left or right a bit
        if (random(-1, 2) < 0)
        {
          analogWrite(MOTOR_L, -current_speed);
          analogWrite(MOTOR_R, current_speed);
        }
        else
        {
          analogWrite(MOTOR_L, current_speed);
          analogWrite(MOTOR_R, -current_speed);
        }
        delay(random(100, 300));
        break;
      case 3: // bumper right & middle hit -> turn left a bit more
        analogWrite(MOTOR_L, -current_speed);
        analogWrite(MOTOR_R, current_speed);
        delay(random(300, 600));
        break;
      case 4: // bumper left hit -> turn right a bit
        analogWrite(MOTOR_L, current_speed);
        analogWrite(MOTOR_R, -current_speed);
        delay(random(100, 300));
        break;
      case 5: // bumper left & right hit -> turn left or right a lot
        if (random(-1, 2) < 0)
        {
          analogWrite(MOTOR_L, -current_speed);
          analogWrite(MOTOR_R, current_speed);
        }
        else
        {
          analogWrite(MOTOR_L, current_speed);
          analogWrite(MOTOR_R, -current_speed);
        }
        delay(random(600, 900));
        break;
      case 6: // bumper left & middle hit -> turn right a bit more
        analogWrite(MOTOR_L, current_speed);
        analogWrite(MOTOR_R, -current_speed);
        delay(random(300, 600));
        break;
      case 7: // all bumpers hit -> turn left or right a lot
        if (random(-1, 2) < 0)
        {
          analogWrite(MOTOR_L, -current_speed);
          analogWrite(MOTOR_R, current_speed);
        }
        else
        {
          analogWrite(MOTOR_L, current_speed);
          analogWrite(MOTOR_R, -current_speed);
        }
        delay(random(600, 900));
        break;
    }
    }
    else
    {
    analogWrite(MOTOR_L, current_speed);
    analogWrite(MOTOR_R, current_speed);
    }
    Serial.print("Speed: ");
    Serial.println(current_speed);
    delay(10);
  */
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
