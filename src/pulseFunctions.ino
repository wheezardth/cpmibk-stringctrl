void setAnimation() // needed for animStartTime
{
  animStartTime = millis();
}

float getStepFloat(long t0, long t, float v)
{
  return ((millis()-t0)%t)*v/t;
}

void calculatePulse()
{
  float l = numLeds/4;  // length of the tail

  float t = getStepFloat(animStartTime, animSpeed, 2*numLeds-l);

  for(int x=0; x<numLeds; x++)
  {
    values[x] = (int)constrain( (((x-t)/l+3.0f))*(((x-t)<0)? 1:0)*255, 0, 255);
  }
}

void runPulse()
{
    // skip the refresh if not enough time has passed since last update
  if (millis() < lastRefreshTime + refreshMillis)
    return;
  lastRefreshTime = millis();
  // call the animation function and refresh if necessary
  
  calculatePulse();
    for(int i=0; i<numLeds; i++)
        DmxSimple.write(channels[i], values[i]); 
}
