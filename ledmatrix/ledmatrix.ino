#include "LedMatrix.h"

LedMatrix m ;

void setup() {
    m.clear() ;
//    Serial.begin(115200) ;
}

void loop() {
    m.clear() ;
    
//    for (MatrixSegment s = A; s <= H; s++) {
//        m.segment(s, true) ;
//        delay(500) ;
//    }
//    
//    for (MatrixSegment s = H; s >= A; s--) {
//        m.segment(s, false) ;
//        delay(500) ;
//    }
    
    for (uint8_t i = 0x0; i <= 0xF; i++) {
        m.digit(i, false) ;
        delay(1000) ;
        m.digit(i, true) ;
        delay(500) ;
        m.digit(i, false) ;
        delay(500) ;
    }
}

