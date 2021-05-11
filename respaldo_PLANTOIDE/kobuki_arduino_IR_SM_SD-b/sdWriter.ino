void sdWrite() {
  String dataString = "";

  for (int i = 0; i < numSensor; i++) {
    dataString += String(cmArray[i]);
    if (i < numSensor) {
      dataString += ",";
    }
  }
  dataString += String(estado);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void sdWrite(long _x, long _y, long _incazzato) {
  String dataString = "";
  dataString += String(_x);
  dataString += ",";
  dataString += String(_y);
  dataString += ",";
  dataString += String(_incazzato);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
