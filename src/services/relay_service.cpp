#include <iostream>
#include <wiringPi.h>
#include <relay_service.hpp>


RelayService::RelayService(int pin1, int pin2, int pin3, int pin4){
    relayPins[0] = pin1;
    relayPins[1] = pin2;
    relayPins[2] = pin3;
    relayPins[3] = pin4;

    if (wiringPiSetup() == -1) {
        std::cerr << "Error al inicializar WiringPi" << std::endl;
    }

    for (int i = 0; i < 4; ++i) {
        pinMode(relayPins[i], OUTPUT);
    }
}

RelayService::~RelayService(){}

void RelayService::activateRelay(int relayNumber){
    if (relayNumber >= 1 && relayNumber <= 4) {
        digitalWrite(relayPins[relayNumber - 1], HIGH); 
        std::cout << "Relé " << relayNumber << " activado" << std::endl;
    } else {
        std::cerr << "Número de relé inválido" << std::endl;
    }
}

void RelayService::deactivateRelay(int relayNumber){
    if (relayNumber >= 1 && relayNumber <= 4) {
        digitalWrite(relayPins[relayNumber - 1], LOW); 
        std::cout << "Relé " << relayNumber << " desactivado" << std::endl;
    } else {
        std::cerr << "Número de relé inválido" << std::endl;
    }
}
