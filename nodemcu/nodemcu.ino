/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "f9b3ee1823614ce39bd46c0c01bd4c5e";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "RZL-hardcore";
char pass[] = "affeaffeaffeaffeaffeaffe00";

//Servo const
Servo esc;
int throttlePin = 0;

//decleration
int pVButton = 0;
int pVPoti = 20;  //started but not beeping

// Attach virtual serial terminal to Virtual Pin V1
WidgetTerminal terminal(V2);



//On /OFF Button--- 0 -> false    1--> true
BLYNK_WRITE(V1)
{
   pVButton = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  terminal.print("V1 Button value is: ");
  terminal.println(pVButton);

  if(pVButton == 1){
    //motor init
  esc.attach(D0);
  //esc.write(0);
  //delay(50);
  //esc.write(1023);
  
  Serial.begin(9600);
  terminal.print("Start up prod");
  esc.write(20);  
  terminal.print("low 20");
  delay(3000); 

  //set to v of poti
  esc.write(pVPoti);
  } else{
    esc.write(0); //turn motor off
  }
}



//Poti 
BLYNK_WRITE(V0)
{

  if(pVButton == 1){
    digitalWrite(D1, HIGH);
    pVPoti = param.asInt(); // assigning incoming value from pin V1 to a variable
  terminal.print("V0 Slider value is: ");
  terminal.println(pVPoti);
  
  int throttle = pVPoti;
  throttle = map(throttle, 0, 1023, 20, 179);
  terminal.println(throttle);
  //delay(100);
  esc.write(throttle);
  } else{
    digitalWrite(D1, LOW);
  }
  
  
  
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D1, OUTPUT);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
  
  
}

