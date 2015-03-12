/*
 * For this example you need a WildFire device,
 * and also to install "Combined Arduino Support Package".
 * Please find more information here:
 *   http://shop.wickeddevice.com/resources/wildfire
 */

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WildFire_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <BlynkSimpleWildFire.h>

// Auth token you get from App
char auth[] = "00000000000000000000000000000000";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "ssid", "pass", WLAN_SEC_WPA2);
}

void loop()
{
  Blynk.run();
}

