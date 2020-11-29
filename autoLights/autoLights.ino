
unsigned long stopMs = 0; // Timestamp to stop..
int secsWait = 30;
bool debug = false;

// Inputs..
int pirSensor = 9;

// Outputs..
int internalLed = 13;
int externalLed = 5;
int relay = 7;

void setup() {
  pinMode(internalLed, OUTPUT); 
  pinMode(externalLed, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(pirSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  int currentStatus = digitalRead(pirSensor);

  if(debug) {
    String sms = (String) millis() + "=>" + (String) stopMs + " Sensor: " + (String) currentStatus;
    Serial.println(sms);
  }

  if(stopMs > millis()) {
    if (currentStatus == HIGH) {
      stopMs = millis() + secsWait * 1000;
    }
  } else {
    // Switch on/off lights if counter is zero..
    if (currentStatus == HIGH) {
      stopMs = millis() + secsWait * 1000;
      
      digitalWrite(internalLed, HIGH);
      digitalWrite(externalLed, HIGH);
      digitalWrite(relay, HIGH);
    } else {
      digitalWrite(internalLed, LOW);
      digitalWrite(externalLed, LOW);
      digitalWrite(relay, LOW);
    }
  }

  // Reset..
  if(stopMs > millis() && stopMs - millis() > 2 * (secsWait * 1000)) {
    stopMs = 0;
  }
}
