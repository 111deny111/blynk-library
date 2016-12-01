/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use SIM800 or SIM900
 * to connect your project to Blynk.
 *
 * Attention!
 *   1. Using your phone:
 *       Disable PIN code on the SIM card
 *       Check your ballance
 *       Check that APN,User,Pass are correct and you have internet
 *   2. Ensure the sim card is correctly inserted into the module
 *   3. Provide a good, stable power supply (up to 2A)
 *      (4.0-4.2V or 5V according to your module documentation)
 *   4. Provide good, stable serial connection
 *      (Hardware Serial is recommended)
 *   5. Check if GSM antenna is attached
 *
 * WARNING: SIM moudle support is for BETA testing.
 *
 * Change GPRS apm, user, pass, and Blynk auth token to run :)
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/

//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

// Default heartbeat interval for GSM is 60
// If you want override this value, uncomment and set this option:
//#define BLYNK_HEARTBEAT 30

#include <TinyGsmClient.h>
#include <BlynkSimpleSIM800.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your GPRS credentials
// Leave empty, if missing user or pass
char apn[]  = "YourAPN";
char user[] = "";
char pass[] = "";

// Hardware Serial on Mega, Leonardo, Micro
#define GsmSerial Serial1

// or Software Serial on Uno, Nano
//#include <SoftwareSerial.h>
//SoftwareSerial GsmSerial(2, 3); // RX, TX

TinyGsmClient gsm(GsmSerial);

void setup()
{
  // Set console baud rate
  Serial.begin(115200);
  delay(10);

  // Set GSM module baud rate
  GsmSerial.begin(115200);
  delay(3000);

  // Restart takes quite some time
  // You can skip it in many cases
  Serial.println("Restarting modem...");
  gsm.restart();

  Blynk.begin(auth, gsm, apn, user, pass);
}

void loop()
{
  Blynk.run();
}

