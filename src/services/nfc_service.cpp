#include "nfc_service.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include <nfc/nfc.h>

NFCService::NFCService() {
    nfc_init(&context);
    if (context == nullptr) {
        std::cerr << "Error initializing NFC context" << std::endl;
        return;
    }

    pnd = nfc_open(context, nullptr);
    if (pnd == nullptr) {
        std::cerr << "Error opening NFC device" << std::endl;
        nfc_exit(context);
        return;
    }

    std::cout << "NFC reader initialized successfully" << std::endl;
}

NFCService::~NFCService() {
    nfc_close(pnd);
    nfc_exit(context);
}

std::string NFCService::readUID() {
    nfc_target nt;
    int res;

    // Configurar modulación
    nfc_modulation nmMifare = {
        .nmt = NMT_ISO14443A,
        .nbr = NBR_106,
    };

    // Selección de la tarjeta NFC pasiva
    res = nfc_initiator_select_passive_target(pnd, nmMifare, nullptr, 0, &nt);
    if (res <= 0) {
        return "";
    }

    std::string uid;
    for (size_t i = 0; i < nt.nti.nai.szUidLen; ++i) {
        char buf[3]; // Buffer para almacenar cada byte como hexadecimal
        snprintf(buf, sizeof(buf), "%02X", nt.nti.nai.abtUid[i]); // Convertir byte a hexadecimal
        uid += buf; // Agregar al string final
    }

    return uid;
}

unsigned int NFCService::hexStringToInt(const std::string& hexString) {
    unsigned int intValue;
    std::stringstream ss;
    ss << std::hex << hexString; // Utilizamos la manipulación de formato hex para leer el valor
    ss >> intValue;
    return intValue;
}

// Función para convertir un UID hexadecimal a std::string
std::string NFCService::uidToString(const std::string& uidHex) {
    // Convertir el UID hexadecimal a un entero
    unsigned int uidInt = hexStringToInt(uidHex);

    // Convertir el entero a std::string
    std::string uidString = std::to_string(uidInt);

    return uidString;
}
