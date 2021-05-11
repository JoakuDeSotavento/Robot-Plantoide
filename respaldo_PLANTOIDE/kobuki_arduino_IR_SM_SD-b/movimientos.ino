/*
int max_speed = 255;
int min_speed = 0;
int zero_speed = 135;
int fSpeed = 170;
int bSpeed = 100;
int current_speed = zero_speed;
*/
void movimientos(byte _mov) {

  switch (_mov) {

    case 0:
      // stop
      analogWrite(MOTOR_L, zero_speed);
      analogWrite(MOTOR_R, zero_speed);
      break;
    case 1:
      // go
      analogWrite(MOTOR_L, fSpeed-5);
      analogWrite(MOTOR_R, fSpeed-5);
      break;
    case 2:
      // back
      analogWrite(MOTOR_L, bSpeed);
      analogWrite(MOTOR_R, bSpeed);
      break;
    case 3:
      //turn right
      analogWrite(MOTOR_L, fSpeed);
      analogWrite(MOTOR_R, bSpeed);
      break;
    case 4:
      // turn left
      analogWrite(MOTOR_L, bSpeed);
      analogWrite(MOTOR_R, fSpeed);
      break;
    case 5:
      // go left
      analogWrite(MOTOR_L, fSpeed-25);
      analogWrite(MOTOR_R, fSpeed);
      break;
    case 6:
      // go right
      analogWrite(MOTOR_L, fSpeed);
      analogWrite(MOTOR_R, fSpeed-25);
      break;

  }

}
