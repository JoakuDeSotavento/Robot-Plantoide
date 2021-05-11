void movimientos(byte _mov) {

  switch (_mov) {

    case 0:
    // stop
      analogWrite(MOTOR_L, zero_speed);
      analogWrite(MOTOR_R, zero_speed);
      break;
    case 1:
    // go
      analogWrite(MOTOR_L, 255);
      analogWrite(MOTOR_R, 255);
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


  }

}
