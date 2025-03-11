# esp32-workshop
Example code for the ESP32 Workshop at Wago
## Preparation
- For the Access-Point open the `AccessPointExample.ino`
- For all the other tasks open a blank/new sketch in the Arduino IDE and add: `#include <ESP32Servo.h>`
- The rest is up to the participants
## Tasks
1. Assembly and wiring
2. Programming the sweep motion
3. Programming a photosensor-dependent control of the servo
4. Programming the servo logic marked as TODOs in the `AccessPointExample.ino`
## Steps to Run the Access-Point:
  1. Connect to the access point "Wago"
  2. Point your web browser to http://192.168.4.1 to see the Webservers Webpage
  3. Use http://192.168.4.1/left, http://192.168.4.1/middle, http://192.168.4.1/right, http://192.168.4.1/sweep to toggle the servo motor
     You can also use the slider which modifies the url as follows http://192.168.4.1/slider?value=90 </br>
     OR </br>
     Run raw TCP "GET /left", "GET /middle", "GET /right", "GET /sweep" or "GET /slider?value=90" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port
