
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

const int buzzer1 = 8;
const int buzzer2 = 9;
const int buzzer3 = 10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, LOW);
  int sensorValue = analogRead(A0);

  if (sensorValue > 500) {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(buzzer1, HIGH);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, LOW);
    
  } else if (sensorValue < 500 && sensorValue > 300) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, HIGH);
  digitalWrite(buzzer3, LOW);

  } else if (sensorValue < 280 && sensorValue > 230) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, HIGH);


  } else if (sensorValue < 230 && sensorValue > 10) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }


  // read the input on analog pin 0:

  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}

