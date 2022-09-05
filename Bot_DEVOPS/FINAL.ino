#include "eloquent.h"
#include "eloquent/print.h"
#include "eloquent/tinyml/voting/quorum.h"
#include "eloquent/vision/camera/aithinker.h"
#include "HogPipeline.h"
#include "HogClassifier.h"

Eloquent::TinyML::Voting::Quorum<7> quorum;

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <ArduinoJson.h>

//
#define TELEGRAM_TOKEN "5606383670:AAFYBE8jPcWjRDW5sUz0sLmR5V_y5NDZMbg"

#define CHAT_ID "1054650225"
#include <WiFi.h>
#include <eloquent.h>
#include <eloquent/fs/spiffs.h>
#include <eloquent/networking/wifi.h>
#include <eloquent/apps/telegram/bot/wifi.h>

//
// Wifi network station credentials
#define WIFI_SSID "Hola"
#define WIFI_PASSWORD "rojas1067"
// Telegram BOT Token (Get from Botfather)


// Use @myidbot (IDBot) to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you

WiFiClientSecure secured_client;


void setup() {
  Serial.begin(115200);
 


    wifi.connectTo(WIFI_SSID, WIFI_PASSWORD);

    Serial.println("Connected to WiFi. Attempting to connect to Telegram API...");
  Serial.println("Begin");

  if (!telegramBot.connect()) {
        eloquent::abort(Serial, "Cannot connect to Telegram API");
    }

    Serial.println("Connected!");
    Serial.println("Type a jpeg filename to send to Telegram Bot");
    
  camera.qqvga();
  camera.grayscale();

  while (!camera.begin()){
    Serial.println("Cannot init camera");
    }

 // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  telegramBot.sendMessageTo(CHAT_ID, "Hola! Si ves esto el mensaje automatico funciona!");
}

void loop() {

  
   if (!camera.capture()) {
      Serial.println(camera.getErrorMessage());
      delay(1000);
      return;
  }
  hog.transform(camera.buffer);

  // get a stable prediction
  // this is optional, but will improve the stability of predictions
  uint8_t prediction = classifier.predict(hog.features);
  int8_t stablePrediction = quorum.vote(prediction);

  if (quorum.isStable()) {
    
    
    eloquent::print::printf(
      Serial, 
      "Stable prediction: %s \t(DSP: %d ms, Classifier: %d us)\n", 
      classifier.getLabelOf(stablePrediction),
      hog.latencyInMillis(),
      classifier.latencyInMicros()
    );
   
  }
  if (classifier.getLabelOf(stablePrediction)=="Key"){
 
      Serial.println("ESTOY VIENDO LAS LLAVES DE TU CASA!!!");
       telegramBot.sendMessageTo(CHAT_ID, "Hola! Veo tus llaves!");
       delay(3000);
       
      
      }
   if (classifier.getLabelOf(stablePrediction)=="Lukas"){
      Serial.println("ESTOY VIENDOTE");
      delay(10000);
       telegramBot.sendMessageTo(CHAT_ID, "Hola! Veo un Lukas!");
       delay(1000);
      
      }

  camera.free();
  

}
