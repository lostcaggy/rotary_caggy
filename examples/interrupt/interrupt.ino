/*
 * Example using the Rotary library, dumping integers to the serial
 * port. The integers increment or decrement depending on the direction
 * of rotation.
 *
 * This example uses interrupts rather than polling and is adapted to work with Raspberry Pi Pico
 
 CLK -> GP16
 DT -> GP17
 SW -> Not connected
 +  -> 3V3
 GND -> GND
 */

#include <Rotary.h>

// Pins for rotary encoder controlling frequency(ies)
const int PIN_ROT_A = 17;
const int PIN_ROT_B = 16;

Rotary rotary = Rotary(PIN_ROT_A, PIN_ROT_B);

// Counter that will be incremented or decremented by rotation.
int counter = 0;

void setup() {
  Serial.begin(115200);
  // Attach interrupts for Rotary Encoder
  // pinMode(PIN_ROT_A, INPUT_PULLUP); // Enable if not using KY-040 or HW-040
  // pinMode(PIN_ROT_B, INPUT_PULLUP); // as has pull up resitors on board
  attachInterrupt(digitalPinToInterrupt(PIN_ROT_A), rotate, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_ROT_B), rotate, CHANGE);
}

void loop() {
}

// rotate is called anytime the rotary inputs change state.
void rotate() {
  unsigned char result = rotary.process();
  if (result == DIR_CW) {
    counter++;
    Serial.println(counter);
  } else if (result == DIR_CCW) {
    counter--;
    Serial.println(counter);
  }
}
