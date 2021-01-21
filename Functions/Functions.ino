/** Copyright (C) 2021  Nonscio, LLC
 *  This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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
 * function has completed. Calls a sequence of functions to issue these commands
 * to the ScioBot 2.0.
 */

void loop() {

  forward(5);
  stop(0.5);
  pivotLeft(3);
  stop(0.5);
  backward(2);
  stop(0.5);
  pivotRight(7);
  stop(3);

}

/**
 * Function: stop(int seconds)
 * Description: The stop() sets all OUTPUT pins to LOW disabling all motors.
 * Parameters: seconds - integer type defining number of seconds this action
 * should be active for.
 */

void stop(int seconds) {

  digitalWrite(enableLeft, LOW);
  digitalWrite(enableRight, LOW);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, LOW);
  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, LOW);

  delay(seconds*1000);
  
}

/**
 * Function: forward(int seconds)
 * Description: The forward() sets enable OUTPUT pins to HIGH enabling both
 * motors. Sets motor pins to HIGH and LOW respecively to to rotate in the
 * forward direction.
 * Parameters: seconds - integer type defining number of seconds this action
 * should be active for.
 */

void forward(int seconds) {

  digitalWrite(enableLeft, HIGH);
  digitalWrite(enableRight, HIGH);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  delay(seconds*1000);
  
}

/**
 * Function: backward(int seconds)
 * Description: The backward() sets enable OUTPUT pins to HIGH enabling both
 * motors. Sets motor pins to HIGH and LOW respecively to to rotate in the
 * backward direction.
 * Parameters: seconds - integer type defining number of seconds this action
 * should be active for.
 */

void backward(int seconds) {

  digitalWrite(enableLeft, HIGH);
  digitalWrite(enableRight, HIGH);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);

  delay(seconds*1000);
  
}

/**
 * Function: pivotLeft(int seconds)
 * Description: The pivotLeft() sets enable OUTPUT pins to HIGH enabling both
 * motors. Sets motor pins to HIGH and LOW respecively to to rotate in
 * opposite direction resulting in a pivot to the left.
 * Parameters: seconds - integer type defining number of seconds this action
 * should be active for.
 */

void pivotLeft(int seconds){

  digitalWrite(enableLeft, HIGH);
  digitalWrite(enableRight, HIGH);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);

  delay(seconds*1000);
  
}

/**
 * Function: pivotRight(int seconds)
 * Description: The pivotRight() sets enable OUTPUT pins to HIGH enabling both
 * motors. Sets motor pins to HIGH and LOW respecively to to rotate in
 * opposite direction resulting in a pivot to the right.
 * Parameters: seconds - integer type defining number of seconds this action
 * should be active for.
 */

void pivotRight(int seconds) {

  digitalWrite(enableLeft, HIGH);
  digitalWrite(enableRight, HIGH);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  delay(seconds*1000);
  
}
