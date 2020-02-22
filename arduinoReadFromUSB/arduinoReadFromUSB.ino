void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);

    ledBlink(50);
    Serial.println("Arduino>> I'm ready!");
}

void ledBlink(int timeDelay) {
    for(int i=0; i<=9; i++) {
        digitalWrite(13 , HIGH);
        delay(timeDelay);
        digitalWrite(13 , LOW);
        delay(timeDelay);
    }
}

void loop() {
    String request, response;
  
    while(Serial.available()) {
        request = Serial.readStringUntil("\n");
        Serial.println("Arduino>> Hello! Message received!");
        ledBlink(100);
        delay(2000);
    }
}
