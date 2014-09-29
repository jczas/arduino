// http://forum.arduino.cc/index.php?PHPSESSID=363paoco6fe4e6rf6vnq7uo580&topic=101156.0

int input = A0;
int val = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(input, INPUT);
}

void loop() {
  val = analogRead(input);
  Serial.println(val);
  delay(500);
}

