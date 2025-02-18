#include "quantum.h"

#include "wait.h"
#include "spi_master.h"

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

static const uint8_t col_values[MATRIX_COLS] = COLS;
static const pin_t row_pins[MATRIX_ROWS] = ROWS;

// static const int msize = MATRIX_ROWS * sizeof(matrix_row_t);
// static matrix_row_t prev_matrix[MATRIX_ROWS];

static inline uint8_t read_rows(void) {
  uint8_t r = readPin(row_pins[0]);

  for (uint8_t row = 1; row < MATRIX_ROWS; row++) {
    r |= (readPin(row_pins[row]) << row);
   }
  return r;
}

static inline void shift_out(uint8_t value) {

  // writePinLow(SPI_LATCH_PIN);
  spi_start(SPI_LATCH_PIN, true, 3, SPI_DIVISOR);
  spi_write(value);
  spi_stop();
  // writePinHigh(SPI_LATCH_PIN);
  matrix_output_select_delay();
}

static inline void select_col(uint8_t col) {
    shift_out(col_values[col]);
}

void matrix_init_custom(void) {

#ifdef CONSOLE_ENABLE
  wait_ms(3000);
#endif
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    setPinInputLow(row_pins[row]);
  }
  matrix_io_delay();
  spi_init();
  matrix_io_delay();

  setPinOutput(SPI_LATCH_PIN);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);
        // wait_us(3);
        uint8_t rows = read_rows();
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = (current_matrix[row] & (matrix_row_t)(1 << col))? 1 : 0;
            bool curr_bit = (rows & (1 << row))? 1 : 0;
            if (prev_bit != curr_bit) {
                current_matrix[row] = current_matrix[row] ^ (1 << col);
                changed = true;
            }
        }
    }

    return changed;
}
