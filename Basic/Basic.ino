const int motorRightA = 2;
const int motorRightB = 4;
const int motorLeftA = 7;
const int motorLeftB = 8;
const int enableRight = 5;
const int enableLeft = 6; 

void setup() {
  // put your setup code here, to run once:

  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftA, OUTPUT);
  pinMode(motorLeftB, OUTPUT);
  pinMode(enableRight, OUTPUT);
  pinMode(enableLeft, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(enableLeft, HIGH);
  digitalWrite(enableRight, HIGH);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

}
