// Configuración de red y Broker MQTT
const char* ssid = "TU_WIFI_SSID";
const char* password = "TU_WIFI_PASSWORD";
const char* mqtt_server = "172.18.0.2"; // IP del contenedor Mosquitto (según esquema)

void setup_wifi() {
  delay(10);
  Serial.println("Conectando a la red WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado. Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Lectura del sensor DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Publicación de datos en el Broker
  String payload = "{\"temp\":" + String(t) + ",\"hum\":" + String(h) + "}";
  client.publish("sensores/sala1", (char*) payload.c_str());
  delay(5000); // Envío cada 5 segundos
}