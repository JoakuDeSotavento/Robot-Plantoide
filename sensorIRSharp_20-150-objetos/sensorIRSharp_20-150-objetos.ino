class IRsensor {

  private:
    byte pin;
    const long referenceMv = 5000;
    // the following is used to interpolate the distance from a table
    // table entries are distances in steps of 250 millivolts
    const int TABLE_ENTRIES = 12;
    const int firstElement = 2750; // first entry is 250 mV
    const int INTERVAL = 250; // millivolts between each element
    int distance[12] = {150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 45};
    int val;
    int mV;

  public:
    IRsensor(byte pin) {
      this->pin = pin;
      val = 0;
      mV = 0;
      init();
    }

    void init() {
      update();
    }

    void update() {
      val = analogRead(pin);
      mV = (val * referenceMv) / 1023;
    }


    int getCM() {
      update();
      if ( mV > INTERVAL * TABLE_ENTRIES - 1 )
        return distance[TABLE_ENTRIES - 1];
      else
      {
        int index = mV / INTERVAL;
        float frac = (mV % 250) / (float)INTERVAL;
        return distance[index] - ((distance[index] - distance[index + 1]) * frac);
      }
    }

    int getVolts() {
      update();
      return mV;
    }
};



#define IR_1_PIN 0
IRsensor senFront(IR_1_PIN);

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int mV = senFront.getVolts();
  Serial.print(mV);
  Serial.print(",");
  int cm = senFront.getCM();
  Serial.println(cm);
  delay(100);
}
