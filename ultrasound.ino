
#define BUZZER 8
#define TRIG_PIN 9
#define ECHO_PIN 10

float timing = 0.0;
float distance = 0.0;

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delay(2);

  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  timing = pulseIn(ECHO_PIN, HIGH);
  distance = (timing * 0.034) / 2;

  Serial.println("Distance: ");
  Serial.print(distance);
  Serial.println("cm ");

  if (distance <= 50) {

    tone(BUZZER, 500);
  } else {

    noTone(BUZZER);
  }

  delay(100);
}