
#include "print.h"
#include <stdbool.h>
#include "matrix.h"
#include <util/delay.h>
#include "quantum.h"

static const uint32_t col_values[8] = SHR_COLS;

static uint8_t read_rows(void);
static void    select_col(uint8_t col);

static void    shift_pulse(void);
static void    shift_out_single(uint8_t value);
static void    shift_out(uint32_t value);

void matrix_init_custom(void) {
  setPinInput(ROW_A);
  setPinInput(ROW_B);

  setPinOutput(SHR_DATA);
  setPinOutput(SHR_LATCH);
  setPinOutput(SHR_CLOCK);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;
    print("hm...");
    
    // for (uint8_t col = 0; col < MATRIX_COLS; col++) {
    //     select_col(col);
    //     _delay_us(5);
    //     uint8_t rows = read_rows();
    //     for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    //         bool prev_bit = ((uint8_t)(current_matrix[row]) & (matrix_row_t)(1UL << col)) ? 1 : 0;
    //         bool curr_bit = ((uint8_t)rows & (uint8_t)(1UL << row)) ? 1 : 0;
    //         if (prev_bit != curr_bit) {
    //             current_matrix[row] = (uint8_t)(current_matrix[row]) ^ (uint8_t)(1UL << col);
    //             changed = true;
    //         }
    //     }
    // }

    uint8_t rows = read_rows();
    uprintf("rows %u", rows);
    select_col(1);
    if (rows == 1){
        print("hm...1 \n");
    }
    return changed;
}

static uint8_t read_rows(void) {
          return (readPin(ROW_B) << 1)
            | (readPin(ROW_A) );   
}

static void select_col(uint8_t col) {
    shift_out(col_values[col]);
}

static void shift_out(uint32_t value) {
  writePinLow(SHR_LATCH);
  uint8_t first_byte  = (uint8_t)(value & 0xFF);

  shift_out_single(first_byte);

  writePinHigh(SHR_LATCH);
  /* We delay here to prevent multiple consecutive keys being triggered with a single switch press */
  _delay_us(10);
}

static void shift_out_single(uint8_t value) {

    for (uint8_t i = 0; i < 8; i++) {
        if (value & 0b10000000) {
            writePinHigh(SHR_DATA);
        } else {
            writePinLow(SHR_DATA);
        }

        shift_pulse();
        value = value << 1;
    }
}

static inline void shift_pulse(void) {
    writePinHigh(SHR_CLOCK);
    writePinLow(SHR_CLOCK);
}