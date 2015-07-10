#define input_up_button 5
#define input_down_button 4
#define input_left_button 3
#define input_right_button 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input_up_button, INPUT);
  pinMode(input_down_button, INPUT);
  pinMode(input_left_button, INPUT);
  pinMode(input_right_button, INPUT);
}

void loop() {
  if (digitalRead(input_up_button))
    Serial.print("^");
  if (digitalRead(input_down_button))
    Serial.print("v");
  if (digitalRead(input_left_button))
    Serial.print("<");
  if (digitalRead(input_right_button))
    Serial.print(">");
  delay(30);
}
