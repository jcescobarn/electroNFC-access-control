#ifndef LCD_SERVICE_HPP
#define LCD_SERVICE_HPP

class LCDService {
private:
    int fd;
    const int I2C_ADDR = 0x27;
    const int LCD_CHR = 1;
    const int LCD_CMD = 0;
    const int LINE1 = 0x80;
    const int LINE2 = 0xC0;
    const int LCD_BACKLIGHT = 0x08;
    const int ENABLE = 0b00000100;

public:
    LCDService();
    void lcd_init();
    void lcd_byte(int bits, int mode);
    void lcd_toggle_enable(int bits);
    void printToLCD(const char *line1, const char *line2);
    void clearLCD();

private:
    void lcdLoc(int line);
    void typeln(const char *s);
};

#endif // LCD_SERVICE_HPP
