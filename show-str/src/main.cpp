

// mapping suggestion from Waveshare SPI e-Paper to Wemos D1 mini
// BUSY -> D2, RST -> D4, DC -> D3, CS -> D8, CLK -> D5, DIN -> D7, GND -> GND, 3.3V -> 3.3V

// include library, include base class, make path known
#include <GxEPD.h>

// select the display class to use, only one

#include <GxGDEW0371W7/GxGDEW0371W7.h> // 3.7" b/w

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include <GxIO/GxIO.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>

#define GxEPD_BLACK 0x0000
#define GxEPD_DARKGREY 0x7BEF  /* 128, 128, 128 */
#define GxEPD_LIGHTGREY 0xC618 /* 192, 192, 192 */
#define GxEPD_WHITE 0xFFFF
#define GxEPD_RED 0xF800 /* 255,   0,   0 */

void showBitmapExample();
void showFontCallback();
void showFont(const char name[], const GFXfont *f);
void drawCornerTest();

GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=D4*/ 2, /*BUSY=D2*/ 4);        // default selection of D4(=2), D2(=4)


void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("setup");

    display.init(115200); // enable diagnostic output on Serial

    Serial.println("setup done");
}

void loop()
{
    showBitmapExample();
    delay(5000);
    showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
    delay(5000);
    showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
    delay(5000);
}

void showBitmapExample()
{
    display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
    delay(2000);
#if !defined(__AVR)
    display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
    delay(2000);
    display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
    delay(2000);
#endif
    display.fillScreen(GxEPD_WHITE);
    display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
    display.update();
}
void showFont(const char name[], const GFXfont *f)
{
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(f);
    display.setCursor(0, 0);
    display.println();
    display.println(name);
    display.println(" !\"#$%&'()*+,-./");
    display.println("0123456789:;<=>?");
    display.println("@ABCDEFGHIJKLMNO");
    display.println("PQRSTUVWXYZ[\\]^_");
    display.println("`abcdefghijklmno");
    display.println("pqrstuvwxyz{|}~ ");
    display.update();
    delay(5000);
}

void showFontCallback()
{
    const char *name = "FreeMonoBold9pt7b";
    const GFXfont *f = &FreeMonoBold9pt7b;
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(f);
    display.setCursor(0, 0);
    display.println();
    display.println(name);
    display.println(" !\"#$%&'()*+,-./");
    display.println("0123456789:;<=>?");
    display.println("@ABCDEFGHIJKLMNO");
    display.println("PQRSTUVWXYZ[\\]^_");
    display.println("`abcdefghijklmno");
    display.println("pqrstuvwxyz{|}~ ");
}

void drawCornerTest()
{
    display.drawCornerTest();
    delay(5000);
    uint8_t rotation = display.getRotation();
    for (uint16_t r = 0; r < 4; r++)
    {
        display.setRotation(r);
        display.fillScreen(GxEPD_WHITE);
        display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
        display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
        display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
        display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
        display.update();
        delay(5000);
    }
    display.setRotation(rotation); // restore
}
