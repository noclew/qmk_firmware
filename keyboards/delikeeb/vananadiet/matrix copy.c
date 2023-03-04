
#include "print.h"
#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"
#include "quantum.h"

#ifndef PIN_USED_74HC595
#    define PIN_USED_74HC595 8
#endif
#ifndef PIN_START_74HC595
#    define PIN_START_74HC595 8
#endif


#ifdef CONSOLE_ENABLE
void print_bin(unsigned char value)
{
    for (int i = sizeof(char) * 7; i >= 0; i--)
        uprintf("%d", (value & (1 << i)) >> i );
    putc('\n', stdout);
}
#endif 

static const uint32_t col_values[8] = SHR_COLS;

static uint8_t read_rows(void);
static void    select_col(uint8_t col);

static void    shift_pulse(void);
static void    shift_out_single(uint8_t value);
static void    shift_out(uint32_t value);

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;

void matrix_init_custom(void) {
  
  // set col pins
  setPinOutput(SHR_DATA);
  setPinOutput(SHR_LATCH);
  setPinOutput(SHR_CLOCK);

  // set row pins
  //   default state is high (due to setPinInputHigh) and active is low (switch presumably connects to ground)
  for (int i = 0; i < MATRIX_ROWS; ++i) {
    setPinInputHigh(row_pins[i]);
  } 

  print("--initiated\n"); 
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    // print("--scanning started\n");
    bool changed = false;
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        
        // set the column output
        select_col(col);
        wait_us(1);
        uint8_t rowsReading = read_rows();

        // uprintf("rows readings with col %u :", col);
        // print_bin(rowsReading);
        // print("\n");

        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = ((uint8_t)(current_matrix[row]) & (matrix_row_t)(1UL << (7 - col) )) ? 1 : 0;
            bool curr_bit = ((uint8_t)rowsReading & (uint8_t)(1UL << ( 7 - row)) ) ? 1 : 0;

            // if (col == 0 || col == 7 ){
            //     uprintf("prev bit of %u th row:: %u   \n", row, prev_bit);
            //     uprintf("cur  bit of %u th row:: %u   \n", row, curr_bit);
            // }

            if (prev_bit != curr_bit) {
                current_matrix[row] = (uint8_t)(current_matrix[row]) ^ (uint8_t)(1UL << (7-col) );
                changed = true;
            }
        }
    }
#ifdef CONSOLE_ENABLE
    if (changed){
        print("--matrix changed");
    }
    // return false;
#endif
    return changed;
}

static uint8_t read_rows(void) {
    //wait_us(100000);
    uint8_t combinedReading = 0b00000000;   

    for (int i = 0; i < MATRIX_ROWS; ++i) {
        uint8_t rowReading = 0b00000000;
        pin_t currentRowPin = row_pins[i];
        uint8_t reading = !readPin(currentRowPin);
        rowReading = rowReading | reading << (7-i);

        uprintf("%u th rows reading val %u: //  ", i, reading);
        uprintf("%u th rows readings:", i);
        print_bin(rowReading);
        print("\n");

        // add the reading of the current row to the combined reading. 
        combinedReading = combinedReading | rowReading;
    }
    //print_bin(rowReading);
    
    return combinedReading;

    // uprintf("rowsB val: %u \n", readPin(B5));
    // uprintf("rowsA val: %u \n", readPin(B6));
          // return (readPin(ROW_B) << 1)
          //   | (readPin(ROW_A) );   
}




static void select_col(uint8_t col) {
    shift_out(col_values[col]);
}

static void shift_out(uint32_t colValue) {
  writePinLow(SHR_LATCH);
  uint8_t first_byte  = (uint8_t)(colValue & 0xFF);
//   print_bin(first_byte);
//   uprintf("\n");
  shift_out_single(first_byte);
  writePinHigh(SHR_LATCH);
  /* We delay here to prevent multiple consecutive keys being triggered with a single switch press */
  wait_us(10);
}

static void shift_out_single(uint8_t colValue) {

    // print("------starting shifting \n");
    // uint8_t shifterRegistry = 0b00000000;

    for (uint8_t i = 0; i < 8; i++) {
        if (1ul << i & colValue) {
            writePinLow(SHR_DATA);
            // shifterRegistry = shifterRegistry | 1ul << i; 
        } else {
            writePinHigh(SHR_DATA);
        }
        shift_pulse();
    }

    // print_bin(shifterRegistry);
    // print("  \n");
}

static inline void shift_pulse(void) {
    writePinHigh(SHR_CLOCK);
    writePinLow(SHR_CLOCK);
}