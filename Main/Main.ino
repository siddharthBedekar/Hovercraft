// Headlights

#include <Servo.h>
#include <IRremote.h>

IRrecv irrecv(6);
decode_results results;
Servo myServo;

int pos = 0;
int stat = 0;

void setup() {
	Serial.begin(9600);
	pinMode(3, OUTPUT);
	myServo.attach(10);
	irrecv.enableIRIn();
}

void servoControl(int pos) {
 	myServo.write(pos); 
}

int ledControl(int stat) {
	if (digitalRead(2) == 1) {
		Serial.println(stat);
		if (stat == 1) {
			digitalWrite(3, LOW);
			stat = 0;
			delay(500);
		} else {
			digitalWrite(3, HIGH);
			stat = 1;
			delay(500);
		}
	return stat;
	}
}

void loop() { 
	stat = ledControl(stat);
	if (irrecv.decode(&results)) {
		Serial.println(results.value);
		irrecv.resume();
	}
	/*  
		servoControl(0);
		delay(1000);
		servoControl(75);
		delay(1000);
		servoControl(150);
		delay(1000);
	*/
}
