// A testbed to measure serial lcd speed

#include <SerialLCD.h>
#include <SoftwareSerial.h>

SerialLCD slcd(1,2);
int samplecount = 0;
int samplesize = 100;

int last = 0;

void setup() {
  slcd.begin();
  last = millis();
}

void loop(){  
  slcd.setCursor(0,0);
  for (int y = 0; y < 1; y++) {
    for (int x = 0; x < 16; x++) {
      slcd.print("-");
    }
  }
  
  samplecount++;
  if (samplecount > samplesize) {
    samplecount = 0;
    int current = millis();
    
    slcd.setCursor(0,1);
    slcd.print("                ");
    slcd.setCursor(0,1);
    slcd.print((current-last),10);
    
    last = millis();
  }
}

