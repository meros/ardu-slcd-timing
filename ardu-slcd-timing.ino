// A testbed to measure serial lcd speed

#include <SerialLCD.h>
#include <SoftwareSerial.h>

SerialLCD slcd(1,2);
int samplecount = 0;
int samplesize = 25;

int last = 0;

void setup() {
  slcd.begin();
  last = micros();
}

void loop(){  
  for (int y = 0; y < 1; y++) {
    for (int x = 0; x < 16; x++) {
      slcd.setCursor(x,y);
      slcd.print("-");
    }
  }
  
  samplecount++;
  if (samplecount > samplesize) {
    samplecount = 0;
    int current = micros();
    
    slcd.setCursor(0,1);
    slcd.print("                ");
    slcd.setCursor(0,1);
    slcd.print((current-last)/samplesize,10);
    
    last = micros();
  }
}

