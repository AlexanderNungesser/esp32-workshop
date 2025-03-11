/*
  WorkshopExample.ino creates a WiFi access point and provides a web server on it

  Steps:
  1. Connect to the access point "Wago"
  2. Point your web browser to http://192.168.4.1 to see the Webservers Webpage
  3. Use http://192.168.4.1/left, http://192.168.4.1/middle, http://192.168.4.1/right, http://192.168.4.1/sweep to toggle the servo motor
     You can also use the slider which modifies the url as follows http://192.168.4.1/slider?value=90
     OR
     Run raw TCP "GET /left", "GET /middle", "GET /right", "GET /sweep" or "GET /slider?value=90" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port

  Created for Wago ESP-32 Workshop on 06 March, 2025
  by Max Steidle, Alexander Nungesser
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include "buildinfiles.h"

// Set these to your desired credentials
const char *ssid = "Wago";
const char *password = "1234567890";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring Access-Point...");

  // You can remove the password parameter if you want the Access-Point to be open.
  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft Access-Point creation failed.");
    while (1)
      ;
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Access-Point IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();  // listen for incoming clients

  if (client) {                    // if you get a client,
    Serial.println("New Client");  // print a message out the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected()) {   // loop while the client's connected
      if (client.available()) {    // if there's bytes to read from the client,
        char c = client.read();    // read a byte, then
        Serial.write(c);           // print it out the serial monitor
        if (c == '\n') {           // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print(html);
            client.println("");
            // The HTTP response ends with another blank line:
            client.println();  // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }


        if (currentLine.indexOf("GET /left") >= 0) {
          // TODO: insert action to be done with the servo motor


        } else if (currentLine.indexOf("GET /right") >= 0) {
          // TODO: insert action to be done with the servo motor


        } else if (currentLine.indexOf("GET /middle") >= 0) {
          // TODO: insert action to be done with the servo motor


        } else if (currentLine.indexOf("GET /sweep") >= 0) {
          // TODO: insert action to be done with the servo motor


        } else if (currentLine.indexOf("GET /slider?value=") >= 0) {
          // TODO: insert action to be done with the servo motor


        }
      }
    }

    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
