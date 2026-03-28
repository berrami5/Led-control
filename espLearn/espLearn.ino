#include <ESP8266WiFi.h>
#include <aREST.h>

const char* ssid = "IdoomFibre_ATHhBz52q";
const char* password = "xf4UBMyx";

int value = 123;
aREST rest = aREST();
WiFiServer server (80);
void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid , password);
  
  while (server.available() != WL_CONNECTED) {delay(100);}
  rest.variable("test" , &value);
  Serial.print(WiFi.localIP());
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    rest.handle(client);
    client.stop();
  }
}
