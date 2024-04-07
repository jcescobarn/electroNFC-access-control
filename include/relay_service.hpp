#ifndef AUTH_HANDLER_HPP
#define AUTH_HANDLER_HPP

#include "lcd_service.hpp"
#include "nfc_service.hpp"
#include "database_service.hpp"

class RelayService {
    public:
        RelayService(int pin1, int pin2, int pin3, int pin4);
        ~RelayService();

        void activateRelay(int relayNumber);
        void deactivateRelay(int relayNumber);
    private:
        int relayPins[4];
};

#endif //AUTH_HANDLER_HPP

