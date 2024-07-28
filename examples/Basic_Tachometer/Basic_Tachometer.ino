#include <Tachometer.h>

Tachometer t(2);

void setup() {
    Serial.begin(115200);
    t.init();
}

void loop() {
    Serial.print("Revolutions: ");
    Serial.print(t.getCurrentRevs());
    Serial.print(" RPM: ");
    Serial.println(t.getRPM());
}
