    Copyright (C) 2021  Nonscio, LLC
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.


//================================================================================
//CONSTANTS
//================================================================================

const int motorRightA = 2;
const int motorRightB = 4;
const int motorLeftA = 7;
const int motorLeftB = 8;
const int enableRight = 5;
const int enableLeft = 6;

//================================================================================
//VARIABLES
//================================================================================

//================================================================================
//FUNCTIONS
//================================================================================

/**
 * Function: setup()
 * Description: The setup() function runs once after the microcontroller is booted
 * or reset. Sets the pin modes of the defined motor logic pin to OUTPUT mode.
 */

void setup() {

  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftA, OUTPUT);
  pinMode(motorLeftB, OUTPUT);
  pinMode(enableRight, OUTPUT);
  pinMode(enableLeft, OUTPUT);

}

/**
 * Function: loop()
 * Description: The loop() function runs repeatedly in a loop after the setup()
 * function has completed. Sets the enable pins to high to enable both the left
 * and right motors, then sends a HIGH signal to one lead on each motor and a 
 * LOW signal to the other lead on each motor. This causes each motor to turn
 * in one direction.
 */

void loop() {

  digitalWrite(enableLeft, HIGH);
  digitalWrite(enableRight, HIGH);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

}
