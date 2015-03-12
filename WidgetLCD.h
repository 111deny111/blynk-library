/**
 * @file       WidgetLCD.h
 * @author     Volodymyr Shymanskyy
 * @date       Mar 2015
 * @brief
 */

#ifndef WidgetSD_h
#define WidgetSD_h

#include <Blynk/BlynkApi.h>

class WidgetLCD
{
public:
    WidgetLCD(uint8_t pin) : mPin(pin) {}

    void clear() {
        Blynk.virtualWrite(mPin, "clr");
    }

    void print(int x, int y, const char* str) {
        char mem[64] = "";
        BlynkParam cmd(mem, 0, sizeof(mem));
        cmd.add("p");
        cmd.add(x);
        cmd.add(y);
        cmd.add(str);
        Blynk.virtualWrite(mPin, cmd);
    }

private:
    uint8_t mPin;
};

#endif
