#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include <Arduino.h>

typedef enum {
    BEFORE_LIST = -1,
    A = 0,  // D5
    B,      // D4
    C,      // D3
    D,      // D2
    E,      // D11
    F,      // D10
    G,      // D9
    H,      // D8
    END_OF_LIST
} MatrixSegment ;

MatrixSegment& operator++(MatrixSegment &s) ;
MatrixSegment operator++(MatrixSegment &s, int) ;
MatrixSegment& operator--(MatrixSegment &s) ;
MatrixSegment operator--(MatrixSegment &s, int) ;

class LedMatrix {
    public:
        LedMatrix() ;
        void clear() ;
        void digit(const uint8_t d, boolean dot) ;
        void segment(const MatrixSegment seg, boolean on) ;
} ;

#endif
