#include "LedMatrix.h"

const uint8_t pins[] = { 5, 4, 3, 2, 11, 10, 9, 8 } ;

const uint8_t digits[][2] = {
  { B0000, B0011 },
  { B1001, B1111 },
  { B0010, B0101 },
  { B0000, B1101 },
  { B1001, B1001 },
  { B0100, B1001 },
  { B0100, B0001 },
  { B0001, B1111 },
  { B0000, B0001 },
  { B0000, B1001 },
  { B0001, B0001 },
  { B1100, B0001 },
  { B0110, B0011 },
  { B1000, B0101 },
  { B0110, B0001 },
  { B0111, B0001 }
} ;

MatrixSegment& operator++(MatrixSegment &s) {
    s = static_cast<MatrixSegment>(static_cast<int>(s) + 1 ) ;
    return s ;
}

MatrixSegment& operator--(MatrixSegment &s) {
    s = static_cast<MatrixSegment>(static_cast<int>(s) - 1) ;
    return s ;
}

MatrixSegment operator++(MatrixSegment &s, int) {
  MatrixSegment m = s ;
  ++s ;
  return m ;
}

MatrixSegment operator--(MatrixSegment &s, int) {
  MatrixSegment m = s ;
  --s ;
  return m ;
}

LedMatrix::LedMatrix() {
    for (uint8_t i = 0; i < 8; i++) {
        pinMode(pins[i], OUTPUT) ;
    }
}

void LedMatrix::clear() {
    PORTD = (PIND & (uint8_t)B11000011) | (uint8_t)B11111100 ;
    PORTB = (PINB & (uint8_t)B11110000) | (uint8_t)B1111 ;
}

void LedMatrix::digit(const uint8_t d, boolean dot) {
    if (d > 15) return ;
    PORTD = (PIND & (uint8_t)B11000011) | (digits[d][0] << 2) ;
    PORTB = ((PINB & (uint8_t)B11110000) | (digits[d][1] & (dot ? (uint8_t)B1110 : (uint8_t)B1111))) ;
}

void LedMatrix::segment(const MatrixSegment seg, boolean on) {
    digitalWrite(pins[seg], on ? LOW : HIGH) ;
}


