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
