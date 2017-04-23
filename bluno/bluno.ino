#include "LedMatrix.h"

#define READ_BUFSIZE 20
uint8_t packetbuffer[READ_BUFSIZE + 1] ;
LedMatrix m ;

void setup() {
    m.clear() ;
    Serial.begin(115200) ;
}

void loop() {
  if (Serial.available()) {
      Serial.readBytes(packetbuffer, READ_BUFSIZE) ;

      // Led
      if (packetbuffer[0] == 'D') {
          uint8_t d = (packetbuffer[1] - '0') * 10 + (packetbuffer[2] - '0') ;
          sprintf((char *)packetbuffer, "LED %02d", d) ;
          Serial.write(packetbuffer, 6) ;
          m.digit(d, false) ;
      } else if(packetbuffer[0] == 'C') {
          Serial.print(F("CLEAR")) ;
          m.clear() ;
      } else if(packetbuffer[0] == 'P') {
          Serial.print(F("POINT")) ;
          m.segment(MatrixSegment::H, true) ;
      }
  }
}

