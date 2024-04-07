#ifndef NFC_SERVICE_HPP
#define NFC_SERVICE_HPP

#include <iostream>
#include <cstring>
#include <nfc/nfc.h>
#include <sstream>

class NFCService {
private:
    nfc_device* pnd;
    nfc_context* context;

public:
    NFCService();
    ~NFCService();
    std::string readUID();
    unsigned int hexStringToInt(const std::string& hexString);
    std::string uidToString(const std::string& uidHex);

};

#endif // NFC_SERVICE_HPP
