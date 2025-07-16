#include <Arduino.h>

// input for arduino from esp32
const int input_1 = A0;
const int input_2 = A1;
const int input_3 = A2;
const int input_4 = A3;

// output for left and right which will require analog outputs

const int A_output_1 = 3;
const int A_output_2 = 5;

void setup() {
  pinMode (input_1, INPUT); // for forward from esp32
  pinMode (input_2, INPUT); // for backward -/- -/-
  pinMode (input_3, INPUT); // for right -/- -/-
  pinMode (input_4, INPUT); // for left -/- -/-
  


  // analog output for right and left steer

  pinMode (A_output_1, OUTPUT);
  pinMode (A_output_2, OUTPUT);


}

void loop() {
  int in1 = digitalRead(input_1);
  int in2 = digitalRead(input_2);
  int in3 = digitalRead(input_3);
  int in4 = digitalRead(input_4);

  if (in1 == HIGH) {
    digitalWrite(A_output_1, HIGH);
    digitalWrite(A_output_2, HIGH);
  }
  else if (in2 == HIGH) {
    digitalWrite(A_output_1, LOW);
    digitalWrite(A_output_2, LOW);
  }
  else if (in3 == HIGH) {
    digitalWrite(A_output_1, LOW);
    digitalWrite(A_output_2, HIGH);
  } 
  else if (in4 == HIGH) {
    digitalWrite(A_output_1, HIGH);
    digitalWrite(A_output_2, LOW);
  }
}
