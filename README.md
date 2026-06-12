# RED IOT EMPRESARIAL SEGURA CON GESTIÓN CENTRALIZADA Y ANALÍTICA DE DATOS
## Trabajo de Fin de Grado (TFG) - 2º ASIR

Este repositorio contiene la infraestructura de microservicios y los scripts de simulación desarrollados para la validación perimetral, la persistencia de datos cronológicos y el análisis analítico de una red IoT empresarial.

> ⚠️ **Nota de Configuración:** Con el objetivo de aislar y auditar las capacidades del backend informático de forma controlada, el proyecto se ejecuta bajo un **entorno de simulación 100% virtualizado**. El comportamiento de la telemetría del nodo sensor se emula directamente en el servidor central mediante la interfaz de línea de comandos (CLI).

---

## 🛠️ Arquitectura Tecnológica Desplegada

La solución se estructura mediante la orquestación de tres microservicios principales aislados en contenedores:
* **Core de Mensajería:** Eclipse Mosquitto como Broker central bajo protocolo ligero MQTT (Puerto 1883).
* **Motor de Almacenamiento:** InfluxDB v2 como base de datos NoSQL especializada en Series Temporales (TSDB).
* **Plataforma Analítica:** Grafana como servidor web para el renderizado de cuadros de mando en tiempo real (Puerto 3000).

---

## 🚀 Guía de Despliegue Rápido (Entorno Local)

### 1. Requisitos Previos
* Sistema Operativo con compatibilidad para contenedores (Windows 11 con WSL2 o Linux Ubuntu Server).
* Motor de virtualización ligero **Docker Desktop** o **Docker Engine** instalado.

### 2. Clonar el repositorio y arrancar el entorno
Accede a la consola de comandos (CLI) de tu sistema anfitrión y ejecuta la siguiente secuencia de instrucciones de administración:

```bash
# Clonar el proyecto
git clone [https://github.com/luissiriartee/TFG-ASIR-IOT.git](https://github.com/luissiriartee/TFG-ASIR-IOT.git)

# Acceder al directorio raíz del trabajo
cd TFG-ASIR-IOT

# Levantar la pila de microservicios en segundo plano (Detached mode)
docker-compose up -d
