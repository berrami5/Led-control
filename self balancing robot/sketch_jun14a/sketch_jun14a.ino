#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>


  const char* id = "realmi C51";
  const char* password = "78a4fa7340bf";
  
  ESP8266WebServer server(80);
  DynamicJsonDocument doc(256);
  void fct () {
    server.send(200 , "text/plain", "OK");
  }
  void handlePID() {
    String res = server.arg("plain");
    Serial.println(res);
    server.send(200, "text/plain", "OK");
    }

  void setup() {
    Serial.begin(9600);
    WiFi.begin(id , password);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print("error");
      delay(500);
    }
    Serial.println("");
    Serial.print(WiFi.localIP());
    
    server.on("/pid" ,HTTP_POST ,handlePID);
    server.on("/" , fct);
    server.begin();
  }

  void loop() {
    if (Serial.available()) {
      String data = Serial.readStringUntil('\n');
      Serial.println(data);
    }
    
    server.handleClient();
  }
