void setup() {
    for(int i = 2; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW);

    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
}
