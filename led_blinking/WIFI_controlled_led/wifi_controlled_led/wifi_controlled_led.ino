#include <WiFi.h>
#include <WebServer.h>

// Replace with your WiFi credentials
const char* ssid = "ACT102726263119";
const char* password = "80502892";

// GPIO pin for LED
const int ledPin = 2;
const int ledPin2= 4;

WebServer server(80); // HTTP server on port 80

// HTML page with ON and OFF buttons
String HTML = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>ESP32 LED Control</title>
<style>
  body { font-family: Arial; text-align: center; margin-top: 50px; }
  button { font-size: 20px; padding: 10px 20px; margin: 10px; }
</style>
</head>
<body>
  <h1>ESP32 Web LED Control</h1>
  <h1>ESP32 1st LED Control</h1>
  <p><a href="/LED1=ON"><button>ON</button></a></p>
  <p><a href="/LED1=OFF"><button>OFF</button></a></p>
  <h1>ESP32 2nd LED Control</h1>
  <p><a href="/LED2=ON"><button>ON</button></a></p>
  <p><a href="/LED2=OFF"><button>OFF</button></a></p>
</body>
</html>
)rawliteral";

// Root page
void handle_OnConnect() {
  server.send(200, "text/html", HTML); // send webpage
}

// LED ON
void handle_led1_on() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", HTML);
}

// LED OFF
void handle_led1_off() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", HTML);
}

// LED ON
void handle_led2_on() {
  digitalWrite(ledPin2, HIGH);
  server.send(200, "text/html", HTML);
}

// LED OFF
void handle_led2_off() {
  digitalWrite(ledPin2, LOW);
  server.send(200, "text/html", HTML);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2,OUTPUT);

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Define URL routes
  server.on("/", handle_OnConnect);
  server.on("/LED1=ON", handle_led1_on);
  server.on("/LED1=OFF", handle_led1_off);
  server.on("/LED2=ON", handle_led2_on);
  server.on("/LED2=OFF", handle_led2_off);

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}
