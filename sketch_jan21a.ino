#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char *SERVER_WIFI_SSID = "Ashok";
const char *SERVER_WIFI_PASS = "9443237730";



void setupWiFi()
{
   Serial.print("Connecting to WiFi ");
   WiFi.begin(SERVER_WIFI_SSID,SERVER_WIFI_PASS);
   while(WiFi.status() != WL_CONNECTED)
   {
     delay(500);
     Serial.print(".");
   }

   Serial.println("Connected");
}

void setup() {
  Serial.begin(9600);
 // pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, INPUT);
  setupWiFi();

}

void loop() {
  // put your main code here, to run repeatedly:
  HTTPClient http;
long state = digitalRead(12);
    if(state == HIGH) {
      Serial.println("Detected");
    http.begin("http://192.168.1.100:8080/ROOT/Test?status=1&key=abc123");
    http.GET();
    http.end();
    delay(10000);
   }else{
     
   }
  //Let is try a GET request first 
 
}
