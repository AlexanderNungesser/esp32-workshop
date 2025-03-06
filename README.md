# esp32-workshop
Example code for the ESP32 Workshop at Wago
## Steps to Run:
  1. Connect to the access point "Wago"
  2. Point your web browser to http://192.168.4.1 to see the Webservers Webpage
  3. Use http://192.168.4.1/left, http://192.168.4.1/middle, http://192.168.4.1/right, http://192.168.4.1/sweep to toggle the servo motor
     You can also use the slider which modifies the url as follows http://192.168.4.1/slider?value=90 </br>
     OR </br>
     Run raw TCP "GET /left", "GET /middle", "GET /right", "GET /sweep" or "GET /slider?value=90" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port
