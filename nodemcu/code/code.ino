// This example uses an Adafruit Huzzah ESP8266
// to connect to shiftr.io.
//
// You can check on your device after a successful
// connection here: https://shiftr.io/try.
//
// by Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <ESP8266WiFi.h>
#include <MQTT.h>
#include <Servo.h>

const char ssid[] = "RZL-hardcore";
const char pass[] = "affeaffeaffeaffeaffeaffe00";

//constants for hardwarecntrl

//Servo const
Servo esc;
int throttlePin = 0;

//decleration
int spd = 20; //started but not beeping

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

// Convert payload to int and map it to throttle, change speed
void setSpd(String payload){
  int throttle = payload.toInt();
  throttle = map(throttle, 0, 10, 20, 179);
  //delay(100);
  esc.write(throttle);
}

void setRot(String payload){
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/hello");
  // client.unsubscribe("/hello");
  client.subscribe("/barschair/rotation");
  client.subscribe("/barschair/speed");
  
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if (topic == "/barschair/speed")
    setSpd(payload);

  if (topic == "/barschair/rotation")
    setRot(payload);

  
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported by Arduino.
  // You need to set the IP address directly.
  client.begin("172.22.37.76", net);
  client.onMessage(messageReceived);

  connect();

  //Attach ESC Pin
  esc.attach(D0);
  
  Serial.begin(9600);
 
  esc.write(20);  
  
  delay(3000); 

  //set to v of poti
  esc.write(spd);
  
} 


void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

 
}



