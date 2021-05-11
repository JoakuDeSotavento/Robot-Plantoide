const byte MOTOR_L = 10; // the pin for the left motor power
const byte MOTOR_R = 9; // the pin for the right motor power

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_L, OUTPUT); // tell Arduino LED is an output
  pinMode(MOTOR_R, OUTPUT); // tell Arduino LED is an output


}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(MOTOR_L, 255);
  delay(1000);
  analogWrite(MOTOR_L, 135);
  analogWrite(MOTOR_R, 135);
  delay(1000);

  //  delay(1000);
  //  analogWrite(MOTOR_R, 135);
  //  delay(1000);
  //  analogWrite(MOTOR_L, 0);
  //  delay(1000);
  //  analogWrite(MOTOR_R, 0);
  //  delay(1000);

}
