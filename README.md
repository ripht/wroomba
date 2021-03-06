# WROOMBA!
iRobot Roombas are great for cleaning. - But pretty damn expensive. Especially the higher-tier models that actually support scheduling or remote control are not exactly cheap. The main goal of this project is to modify my Roomba 560 and add scheduled cleaning myself.    

### Hardware
The project hardware is dead simple. Roomba exposes an open interface at the top (Roomba Open Interface) which is a 7-pin Mini-DIN pug. (If you're like me and don't have those lying around, you can also use a 6-PS2 plug, since the roomba interface has 2 Vpp and 2 GND lines one of which is conveniently placed where the PS2 plug has a missing pin). Or if you are feeling adventurous, screw the thing apart and solder the wires directly to the print, that way the cover can be reinstalled and it will look bone stock.

Other than that, you will need:
- An Espressif ESP32 development board
- A little circuit to get 3.3V from roomba's ~20V battery. If you can't be bothered to order one from ali express, you can consider pulling a 12-24V car USB adapter apart, they will contain a circuit that reduces 24-12V to 5V, which you can feed into the Vusb and have the board's own 3V3 regulator take care of it.

### Software
The software is a standard ESP32 project for use with the ESP-IDF v4.0.1. It's forked from cybrox's great original project which uses the old, pre-CMAKE esp-idf.

### Usage
Since for my application, the actual scheduling of tasks is done on a central device. Wroomba merely needs to add an API between that scheduler and the Roomba Open Interface. This Software exposes a very simple HTTP API with the following endpoints:
- `GET /info` Returns "wroomba!"
- `POST /clean` Sends `start` + `clean` command to roomba

If you want to use this, please remember to set your hostname, wifi SSID and password during the menuconfig step under "Wifi SSID and PSK".

### Future updates
I'm intending to add a POST method to send a play command plus a song and a GET /dock to send it back to the dock.
