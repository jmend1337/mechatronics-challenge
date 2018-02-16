#include "Particle.h"

#include "LIS3DH.h"
// Electron sample to print accelerometer samples to serial
// (also works on the Photon, P1, Core)

#include "TinyGPS++.h"
// Port of TinyGPS for the Particle AssetTracker
// https://github.com/mikalhart/TinyGPSPlus

SYSTEM_THREAD(ENABLED);
// This sample only uses serial, not data, so cellular is turned off to save data
/*
   This sample sketch demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object directly.
 */

// Print 10 samples per second to serial
const unsigned long PRINT_SAMPLE_PERIOD = 100;
unsigned long lastPrintSample = 0;

// LIS3DH is connected as in the AssetTracker, to the primary SPI with A2 as the CS (SS) pin, and INT connected to WKP
LIS3DHSPI accel(SPI, A2, WKP);

void displayInfo(); // forward declaration

const unsigned long PUBLISH_PERIOD = 120000;
const unsigned long SERIAL_PERIOD = 5000;

// The TinyGPS++ object
TinyGPSPlus gps;
unsigned long lastSerial = 0;
unsigned long lastPublish = 0;
unsigned long startFix = 0;
bool gettingFix = false;

void setup()
{
  Serial.begin(9600);

  // The GPS module on the AssetTracker is connected to Serial1 and D6
  Serial1.begin(9600);
  
  delay(5000);

  // Initialize sensors
  LIS3DHConfig config;
  config.setAccelMode(LIS3DH::RATE_100_HZ);

  bool setupSuccess = accel.setup(config);
  Serial.printlnf("setupSuccess=%d", setupSuccess);
  
  // Settings D6 LOW powers up the GPS module
    pinMode(D6, OUTPUT);
    digitalWrite(D6, LOW);
    startFix = millis();
    gettingFix = true;
}

void loop()
{
  if (millis() - lastPrintSample >= PRINT_SAMPLE_PERIOD) {
    lastPrintSample = millis();

    LIS3DHSample sample;
    if (accel.getSample(sample)) {
      Serial.printlnf("%d,%d,%d", sample.x, sample.y, sample.z);
    }
    else {
      Serial.println("no sample");
    }
  }
  
  // note the below command was a while, but was changed to an if to allow for the acceleromter to also publish data
  if (Serial1.available() > 0) {
    if (gps.encode(Serial1.read())) {
      displayInfo();
    }
  }

}

void displayInfo()
{
  if (millis() - lastSerial >= SERIAL_PERIOD) {
    lastSerial = millis();

    char buf[128];
    if (gps.location.isValid()) {
      snprintf(buf, sizeof(buf), "%f,%f,%f", gps.location.lat(), gps.location.lng(), gps.altitude.meters());
      if (gettingFix) {
        gettingFix = false;
        unsigned long elapsed = millis() - startFix;
        Serial.printlnf("%lu milliseconds to get GPS fix", elapsed);
      }
    }
    else {
      strcpy(buf, "no location");
      if (!gettingFix) {
        gettingFix = true;
        startFix = millis();
      }
    }
    Serial.println(buf);

    if (Particle.connected()) {
      if (millis() - lastPublish >= PUBLISH_PERIOD) {
        lastPublish = millis();
        Particle.publish("gps", buf);
      }
    }
  }

}
