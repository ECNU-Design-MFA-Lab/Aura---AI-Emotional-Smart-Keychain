#include "smile.h"  //đặt mặc định
#include "binhthuong.h"   //frame mở đầu dùng chung
#include "suprised.h"
#include "tired.h"
#include "happy.h"
#include "angry.h"
#include "sad.h"
#include "chop.h"    //frame kết cuối dùng chung
#include <TJpg_Decoder.h>
#include <DIYables_TFT_Round.h>

#define PIN_RST 4
#define PIN_DC 16
#define PIN_CS 5

DIYables_TFT_GC9A01_Round TFT_display(PIN_RST, PIN_DC, PIN_CS);

bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
    TFT_display.drawRGBBitmap(x, y, bitmap, w, h);
    return true;
}

void happyGif()
{
    TFT_display.drawRGBBitmap(0, 0, happy, 240, 240);
    delay(2500);

    TFT_display.drawRGBBitmap(0, 0, confused3, 240, 240);
    delay(300);

    TFT_display.drawRGBBitmap(0, 0, smile, 240, 240);
}

void suprisedGif()
{
    TFT_display.drawRGBBitmap(0, 0, suprised, 240, 240);
    delay(2500);

    TFT_display.drawRGBBitmap(0, 0, confused3, 240, 240);
    delay(300);

    TFT_display.drawRGBBitmap(0, 0, smile, 240, 240);
}

void angryGif()
{
    TFT_display.drawRGBBitmap(0, 0, confused1, 240, 240);
    delay(500);

    TFT_display.drawRGBBitmap(0, 0, angry, 240, 240);
    delay(2500);

    TFT_display.drawRGBBitmap(0, 0, confused3, 240, 240);
    delay(300);

    TFT_display.drawRGBBitmap(0, 0, smile, 240, 240);
}

void sadGif()
{
    TFT_display.drawRGBBitmap(0, 0, confused1, 240, 240);
    delay(500);

    TFT_display.drawRGBBitmap(0, 0, sad, 240, 240);
    delay(2500);

    TFT_display.drawRGBBitmap(0, 0, confused3, 240, 240);
    delay(300);

    TFT_display.drawRGBBitmap(0, 0, smile, 240, 240);
}

void tiredGif()
{
    TFT_display.drawRGBBitmap(0, 0, confused1, 240, 240);
    delay(500);

    TFT_display.drawRGBBitmap(0, 0, tired, 240, 240);
    delay(2500);

    TFT_display.drawRGBBitmap(0, 0, confused3, 240, 240);
    delay(300);

    TFT_display.drawRGBBitmap(0, 0, smile, 240, 240);
}

void setup()
{
    Serial.begin(115200);

    SPI.begin(18, -1, 23, 5);

    TFT_display.begin();

    TFT_display.drawRGBBitmap(0, 0, smile, 240, 240);

    TJpgDec.setJpgScale(1);
    TJpgDec.setCallback(tft_output);
}

void loop()
{
    if (Serial.available())
    {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();

        if (cmd == "happy")
        {
            happyGif();
        }
        else if (cmd == "sad")
        {
            sadGif();
        }
        else if (cmd == "angry")
        {
            angryGif();
        }
        else if (cmd == "tired")
        {
            tiredGif();
        }
        else if (cmd == "surprised")
        {
            suprisedGif();
        }
    }
}