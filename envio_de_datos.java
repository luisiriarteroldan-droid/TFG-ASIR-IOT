// Fragmento de código para enviar datos a InfluxDB vía MQTT
void send_to_database(float temp, float hum) {
  // Creamos el mensaje en formato Line Protocol (el que entiende InfluxDB)
  String payload = "clima,sensor=esp32_sala1 temperatura=" + String(temp) + ",humedad=" + String(hum);
  
  // Enviamos al topic de MQTT que está escuchando el integrador
  if (client.publish("sensores/datos", (char*) payload.c_str())) {
    Serial.println("Datos enviados correctamente al flujo de la base de datos");
  } else {
    Serial.println("Error en el envío MQTT");
  }
}