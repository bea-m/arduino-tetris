cmake_minimum_required(VERSION 3.26)
project(tetris)

set(CMAKE_CXX_STANDARD 14)

include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2c_address_detect")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2c_readwrite")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2c_registers")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2corspi_register")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_modetest")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_readwrite")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_register_bits")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_registers")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/examples/GFXcanvas")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/examples/mock_ili9341")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/breakouttouchpaint")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/graphicstest")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/graphicstest_featherwing")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/graphicstest_pyportal")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/mandelbrot")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/onoffbutton")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/onoffbutton_breakout")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/pictureEmbed")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/pyportal_boing")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/touchpaint")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/touchpaint_featherwing")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/touchpaint_pyportal")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_featherwing")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_QTPY_SH1106")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_QTPY_SH1106/SH1106_128x64_i2c_QTPY")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_QTPY_SH1106/SH1106_128x64_SPi_QTPY")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/SH1107_128x128")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit STMPE610")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit STMPE610/examples")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit STMPE610/examples/TouchTest")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/examples")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/examples/touchscreendemo")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/examples/touchscreendemoshield")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/examples")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/examples/tsc2007_demo")
include_directories(".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/examples/tsc2007_oleddemo")

add_executable(tetris
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2c_address_detect/i2c_address_detect.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2c_readwrite/i2c_readwrite.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2c_registers/i2c_registers.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/i2corspi_register/i2corspi_register.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_modetest/spi_modetest.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_readwrite/spi_readwrite.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_register_bits/spi_register_bits.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/examples/spi_registers/spi_registers.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_BusIO_Register.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_BusIO_Register.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_I2CDevice.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_I2CDevice.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_I2CRegister.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_SPIDevice.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO/Adafruit_SPIDevice.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/examples/GFXcanvas/GFXcanvas.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/examples/GFXcanvas/GFXcanvasSerialDemo.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/examples/GFXcanvas/GFXcanvasSerialDemo.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/examples/mock_ili9341/mock_ili9341.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/fontconvert/fontconvert.c"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMono12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMono18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMono24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMono9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBold12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBold18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBold24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBold9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBoldOblique12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBoldOblique18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBoldOblique24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoBoldOblique9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoOblique12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoOblique18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoOblique24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeMonoOblique9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSans12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSans18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSans24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSans9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBold12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBold18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBold24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBold9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBoldOblique12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBoldOblique18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBoldOblique24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansBoldOblique9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansOblique12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansOblique18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansOblique24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSansOblique9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerif12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerif18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerif24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerif9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBold12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBold18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBold24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBold9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBoldItalic12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBoldItalic18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBoldItalic24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifBoldItalic9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifItalic12pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifItalic18pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifItalic24pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/FreeSerifItalic9pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/Org_01.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/Picopixel.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/Tiny3x3a2pt7b.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Fonts/TomThumb.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_GFX.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_GFX.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_GrayOLED.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_GrayOLED.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_SPITFT.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_SPITFT.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/Adafruit_SPITFT_Macros.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/gfxfont.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit GFX Library/glcdfont.c"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/breakouttouchpaint/breakouttouchpaint.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/graphicstest/graphicstest.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/graphicstest_featherwing/graphicstest_featherwing.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/graphicstest_pyportal/graphicstest_pyportal.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/mandelbrot/mandelbrot.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/onoffbutton/onoffbutton.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/onoffbutton_breakout/onoffbutton_breakout.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/pictureEmbed/dragon.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/pictureEmbed/pictureEmbed.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/pyportal_boing/graphics.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/pyportal_boing/pyportal_boing.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/touchpaint/touchpaint.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/touchpaint_featherwing/touchpaint_featherwing.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/examples/touchpaint_pyportal/touchpaint_pyportal.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/Adafruit_ILI9341.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit ILI9341/Adafruit_ILI9341.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_featherwing/OLED_featherwing.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_QTPY_SH1106/SH1106_128x64_i2c_QTPY/SH1106_128x64_i2c_QTPY.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/OLED_QTPY_SH1106/SH1106_128x64_SPi_QTPY/SH1106_128x64_SPi_QTPY.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/examples/SH1107_128x128/SH1107_128x128.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/Adafruit_SH1106G.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/Adafruit_SH1107.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/Adafruit_SH110X.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/Adafruit_SH110X.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit SH110X/splash.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit STMPE610/examples/TouchTest/TouchTest.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit STMPE610/Adafruit_STMPE610.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit STMPE610/Adafruit_STMPE610.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/examples/touchscreendemo/touchscreendemo.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/examples/touchscreendemoshield/touchscreendemoshield.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/TouchScreen.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TouchScreen/TouchScreen.h"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/examples/tsc2007_demo/tsc2007_demo.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/examples/tsc2007_oleddemo/tsc2007_oleddemo.ino"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/Adafruit_TSC2007.cpp"
        ".pio/libdeps/esp32doit-devkit-v1/Adafruit TSC2007/Adafruit_TSC2007.h"
        src/main.cpp)
