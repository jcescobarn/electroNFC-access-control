# NFC Access Control Project with Electromagnetic Door

This project is a C++ application designed to manage access using Near Field Communication (NFC) technology along with an LCD screen, a SQLite database, and a relay module to control an electromagnet. The application allows for reading NFC cards, displaying relevant information on an LCD screen, managing access records in a SQLite database, and controlling the opening of an electromagnetic door.

## Electronic Components

### Near Field Communication (NFC) Card
- The NFC card is an identification device that uses near field communication technology for data transfer.
- It is used to identify and authenticate users of the access system.

### Liquid Crystal Display (LCD)
- The LCD screen provides a visual user interface for displaying relevant information.
- It is used to display messages, instructions, and access data.

### SQLite Database
- SQLite is an open-source relational database management system used for storing access records.
- It is used to store information about users, access records, and other relevant system information.

### Relay Module and Electromagnet
- The relay module is used to control the electromagnet that opens the door.
- It is used to activate and deactivate the electromagnet in response to authorized access events.

## Key Features

- Reading NFC cards to identify users.
- Displaying messages and data on the LCD screen.
- Recording access logs in the SQLite database.
- Controlling the opening of the electromagnetic door using the relay module.

## Project Structure

- **src/main.cpp**: Main file containing the core logic of the program.
- **include/**: Directory containing header files (.hpp) for the classes and services used in the project.
- **src/services/**: Directory containing implementations of the classes and services used in the project.


# Proyecto de Control de Acceso NFC con Puerta Electromagnética

Este proyecto es una aplicación desarrollada en C++ para gestionar el acceso utilizando tecnología de comunicación de campo cercano (NFC) junto con una pantalla LCD, una base de datos SQLite y un módulo de relé para controlar un electroimán. La aplicación permite leer tarjetas NFC, mostrar información relevante en una pantalla LCD, gestionar los registros de acceso en una base de datos y controlar la apertura de una puerta electromagnética.

## Componentes Electrónicos

### Tarjeta de Comunicación de Campo Cercano (NFC)
- La tarjeta NFC es un dispositivo de identificación que utiliza tecnología de comunicación de campo cercano para la transferencia de datos.
- Se utiliza para identificar y autenticar a los usuarios del sistema de acceso.

### Pantalla de Cristal Líquido (LCD)
- La pantalla LCD proporciona una interfaz de usuario visual para mostrar información relevante.
- Se utiliza para mostrar mensajes, instrucciones y datos de acceso.

### Base de Datos SQLite
- SQLite es un sistema de gestión de bases de datos relacional de código abierto que se utiliza para almacenar registros de acceso.
- Se utiliza para almacenar información sobre los usuarios, registros de acceso y otra información relevante del sistema.

### Módulo de Relé y Electroimán
- El módulo de relé se utiliza para controlar el electroimán que abre la puerta.
- Se utiliza para activar y desactivar el electroimán en respuesta a eventos de acceso autorizado.

## Funcionalidades Principales

- Lectura de tarjetas NFC para identificar a los usuarios.
- Visualización de mensajes y datos en la pantalla LCD.
- Registro de accesos en la base de datos SQLite.
- Control de la apertura de la puerta electromagnética mediante el módulo de relé.

## Estructura del Proyecto

- **src/main.cpp**: Archivo principal que contiene la lógica principal del programa.
- **include/**: Directorio que contiene los archivos de encabezado (.hpp) para las clases y servicios utilizados en el proyecto.
- **src/services/**: Directorio que contiene las implementaciones de las clases y servicios utilizados en el proyecto.
