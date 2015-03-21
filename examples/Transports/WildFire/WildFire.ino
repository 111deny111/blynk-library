/*
 * For this example you need a WildFire device,
 * and also to install "Combined Arduino Support Package".
 * Please find more information here:
 *   http://shop.wickeddevice.com/resources/wildfire
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 */

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WildFire_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <BlynkSimpleWildFire.h>
#include <WildFire.h>

WildFire wildfire;

// Auth token you get from App
char auth[] = "YourAuthToken";

void setup()
{
  Serial.begin(9600);
  wildfire.begin();
  Blynk.begin(auth, "ssid", "pass", WLAN_SEC_WPA2);
  timer.setInterval(1000, sendUptime);
}

void loop()
{
  Blynk.run();
}

