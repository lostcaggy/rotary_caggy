/*
 * Example using the Rotary library, dumping integers to the serial
 * port. The integers increment or decrement depending on the direction
 * of rotation.
 *
 * This example uses polling rather than interrupts and is adapted for use with Raspberry Pi Pico .
  CLK -> GP16
  DT -> GP17
  SW -> Not connected
  +  -> 3V3
  GND -> GND
 */

#include <Rotary.h>

// Rotary encoder is wired with the common to ground and the two
// outputs to pins 17 and 16.
Rotary rotary = Rotary(17, 16);

// Counter that will be incremented or decremented by rotation.
int counter = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned char result = rotary.process();
  if (result == DIR_CW) {
    counter++;
    Serial.println(counter);
  } else if (result == DIR_CCW) {
    counter--;
    Serial.println(counter);
  }
}

