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

const int motorLeft[] = {2, 4};
const int motorRight[] = {7, 8};
const int speedPinLeft = 5;
const int speedPinRight = 6;

const int LEFT = 0;
const int RIGHT = 1;

const float WHEEL_CIRCUMFERENCE_IN = 10.63;
const float WHEEL_BASE_IN = 6.89;
const float MOTOR_RPM_AT_9V = 55.0;

const float SECONDS_IN_MINUTE = 60.0;

//================================================================================
//VARIABLES
//================================================================================

//================================================================================
//FUNCTIONS
//================================================================================

/**
 * Function: setup()
 * Description: The setup() function runs once after the microcontroller is 
 * booted or reset. Sets the pin modes of the defined motor logic pin to OUTPUT
 * mode. Initializes serial output for debugging.
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i = 0; i < 2; i++) {
    pinMode(motorLeft[i], OUTPUT);
    pinMode(motorRight[i], OUTPUT);
  }

  pinMode(speedPinLeft, OUTPUT);
  pinMode(speedPinRight, OUTPUT);

}

/**
 * Function: loop()
 * Description: The loop() function runs repeatedly in a loop after the setup()
 * function has completed. Calls a sequence of functions to issue these commands
 * to the ScioBot 2.0.
 */

void loop() {

  driveForwardDistance(12);
  turnDegrees(LEFT, 30.0);
  driveForwardDistance(255, 10);
  turnDegrees(RIGHT, 15.0);
  
}

/**
 * Function: driveForwardDistance(int inches)
 * Description: The driveForwardDistance() function uses principles of 
 * geometry to calculate durations that equate to distances the ScioBot 2.0
 * should move.
 * Parameters: 
 *   inches - integer type defining the desired distance in inches the
 *   ScioBot 2.0 should travel forward.
 */

void driveForwardDistance(int inches) {
  
  float secondsPerInch = 1/(MOTOR_RPM_AT_9V/SECONDS_IN_MINUTE*WHEEL_CIRCUMFERENCE_IN);

  digitalWrite(speedPinLeft, HIGH);
  digitalWrite(speedPinRight, HIGH);

  digitalWrite(motorLeft[0], HIGH);
  digitalWrite(motorLeft[1], LOW);

  digitalWrite(motorRight[0], HIGH);
  digitalWrite(motorRight[1], LOW);

  float delayMilli = ((float)inches * secondsPerInch) * 1000;

  Serial.print(secondsPerInch);
  Serial.print(", ");
  Serial.print(delayMilli);
  Serial.print(", ");
  Serial.println((int)delayMilli);
  
  delay((int)delayMilli);

}

/**
 * Function: turnDegrees(int direction)
 * Description: The turnDegrees() function uses principles of geometry to
 * calculate duration that equate to a number of degrees in a turn to issue
 * precise turning commands to the ScioBot 2.0. *Note that as battery voltage
 * is reduced, RPM is reduced causing these values to shift.
 * Parameters: 
 *   direction - integer type defining the direction the ScioBot 2.0 should
 *   turn. LEFT and RIGHT constants defined as 0 and 1 respectively.
 *   degrees - float type defining the number of degrees (realtively) the
 *   ScioBot 2.0 should turn.
 */

void turnDegrees(int direction, float degrees) {

  float turnCircumference = 2*PI*WHEEL_BASE_IN;
  float inchesPerDegree = turnCircumference/360;
  
  float secondsPerInch = 1/(MOTOR_RPM_AT_9V/SECONDS_IN_MINUTE*WHEEL_CIRCUMFERENCE_IN);
  float secondsPerDegree = inchesPerDegree * secondsPerInch;

  digitalWrite(speedPinLeft, direction=LEFT?LOW:HIGH);
  digitalWrite(speedPinRight, direction=RIGHT?LOW:HIGH);

  digitalWrite(motorLeft[0], direction=LEFT?LOW:HIGH);
  digitalWrite(motorLeft[1], LOW);

  digitalWrite(motorRight[0], direction=LEFT?LOW:HIGH);
  digitalWrite(motorRight[1], LOW);

  

  float delayMillis = degrees * secondsPerDegree *1000;

  Serial.print(degrees);
  Serial.print(", ");
  Serial.println(delayMillis);

  delay(delayMillis);
}
