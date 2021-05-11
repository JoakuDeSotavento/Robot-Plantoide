boolean timer(long _interval) {
  unsigned long currentMillis = millis();
  // constants won't change:
  if (currentMillis - previousMillis >= _interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}
