#include "lcd_service.hpp"
#include "nfc_service.hpp"
#include "database_service.hpp"
#include "relay_service.hpp"
#include <thread>
#include <chrono>
#include <sqlite3.h>
#include <vector>


int main() {
    LCDService lcd;
    NFCService nfc;
    RelayService relay(37,35,33,31);
    ResultSet resultset;
    std::string dbPath = "/home/gaia/Documents/c_nfc_app/database/access_control.db";
    DatabaseService db(dbPath.c_str());
    std::string uid_readed;
    std::string user;
    std::string uid;

    lcd.lcd_init();
    lcd.printToLCD("Acerque su ", "Documento .");
    relay.deactivateRelay(1);
    relay.deactivateRelay(2);
    relay.deactivateRelay(3);
    relay.deactivateRelay(4);
    while(true){
        if (nfc.readUID() != "") {
            uid_readed = nfc.uidToString(nfc.readUID());
            std::cout << "UID de la tarjeta NFC: " << uid_readed << std::endl;
            db.open();

            resultset = db.executeQuery("select * from users where uid="+uid_readed);
            if(!resultset.empty()){
                user = resultset[0][1];
                uid =  resultset[0][0];

                if(uid == uid_readed) {
                    lcd.printToLCD("Bienvenido...", user.c_str());
                    relay.activateRelay(1);
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    relay.deactivateRelay(1);
                    db.registerAccess(uid_readed);
                }
            }else{
                lcd.printToLCD("Permiso ","Denegado ");
            }
            lcd.printToLCD("Acerque su ", "Documento .");
            db.close();
        } 
    }



}
