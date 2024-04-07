#include "lcd_service.hpp"
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

LCDService::LCDService() {
    if (wiringPiSetup() == -1) exit(1);
    fd = wiringPiI2CSetup(I2C_ADDR);
    lcd_init();
}

void LCDService::lcd_init() {
    lcd_byte(0x33, LCD_CMD); // Initialise
    lcd_byte(0x32, LCD_CMD); // Initialise
    lcd_byte(0x06, LCD_CMD); // Cursor move direction
    lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
    lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
    lcd_byte(0x01, LCD_CMD); // Clear display
    delayMicroseconds(500);
}

void LCDService::lcd_byte(int bits, int mode) {
    int bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT;
    int bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT;

    wiringPiI2CReadReg8(fd, bits_high);
    lcd_toggle_enable(bits_high);

    wiringPiI2CReadReg8(fd, bits_low);
    lcd_toggle_enable(bits_low);
}

void LCDService::lcd_toggle_enable(int bits) {
    delayMicroseconds(500);
    wiringPiI2CReadReg8(fd, (bits | ENABLE));
    delayMicroseconds(500);
    wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
    delayMicroseconds(500);
}

void LCDService::printToLCD(const char *line1, const char *line2) {
    clearLCD();
    lcdLoc(LINE1);
    typeln(line1);

    lcdLoc(LINE2);
    typeln(line2);
}

void LCDService::clearLCD() {
    lcd_byte(0x01, LCD_CMD); // Envía el comando para limpiar el display
    delay(2); // Espera un tiempo para que se complete la operación de limpieza
}

void LCDService::lcdLoc(int line) {
    lcd_byte(line, LCD_CMD);
}

void LCDService::typeln(const char *s) {
    while (*s) lcd_byte(*(s++), LCD_CHR);
}