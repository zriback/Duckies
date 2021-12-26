/*
* Sketch generated by duck2spark from Marcus Mengs aka MaMe82
*
*/
#include "DigiKeyboard.h"

#define DUCK_LEN 383
const PROGMEM uint8_t duckraw [DUCK_LEN] = {
	82, 69, 77, 32, 84, 104, 105, 115, 32, 115, 99, 114, 105, 112, 116, 32, 105, 115, 32, 109, 101, 97, 110, 116, 32, 116, 111, 32, 116, 114, 121, 32, 97, 110, 100, 32, 102, 108, 105, 112, 32, 116, 104, 101, 32, 115, 99, 114, 101, 101, 110, 32, 117, 112, 115, 105, 100, 101, 32, 100, 111, 119, 110, 32, 40, 108, 97, 110, 100, 115, 99, 97, 112, 101, 32, 105, 110, 118, 101, 114, 116, 101, 100, 41, 13, 10, 82, 69, 77, 32, 84, 104, 105, 115, 32, 115, 99, 114, 105, 112, 116, 32, 105, 115, 32, 100, 101, 115, 105, 103, 110, 101, 100, 32, 116, 111, 32, 119, 111, 114, 107, 32, 111, 110, 32, 97, 32, 87, 105, 110, 100, 111, 119, 115, 32, 49, 48, 32, 109, 97, 99, 104, 105, 110, 101, 13, 10, 82, 69, 77, 32, 65, 117, 116, 104, 111, 114, 58, 32, 90, 97, 99, 104, 32, 82, 105, 98, 97, 99, 107, 13, 10, 68, 69, 70, 65, 85, 76, 84, 95, 68, 69, 76, 65, 89, 32, 50, 48, 13, 10, 77, 69, 78, 85, 13, 10, 85, 80, 13, 10, 85, 80, 13, 10, 69, 78, 84, 69, 82, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 84, 65, 66, 13, 10, 69, 78, 84, 69, 82, 13, 10, 68, 79, 87, 78, 13, 10, 68, 79, 87, 78, 13, 10, 69, 78, 84, 69, 82, 13, 10, 82, 69, 77, 32, 84, 104, 101, 32, 115, 99, 114, 101, 101, 110, 32, 97, 115, 107, 105, 110, 103, 32, 116, 111, 32, 107, 101, 101, 112, 32, 116, 104, 101, 32, 115, 101, 116, 116, 105, 110, 103, 115, 32, 119, 105, 108, 108, 32, 115, 116, 105, 108, 108, 32, 98, 101, 32, 117, 112, 44, 32, 97, 110, 100, 32, 116, 104, 101, 32, 102, 108, 105, 112, 32, 119, 105, 108, 108, 32, 98, 101, 32, 97, 117, 116, 111, 109, 97, 116, 105, 99, 97, 108, 108, 121, 32, 114, 101, 118, 101, 114, 116, 101, 100, 13, 10
};
int i = 1; //how many times the payload should run (-1 for endless loop)
bool blink=true;

void setup()
{
	// initialize the digital pin as an output.
	pinMode(0, OUTPUT); //LED on Model B
	pinMode(1, OUTPUT); //LED on Model A
	DigiKeyboard.delay(1000); //wait 1000 milliseconds before first run, to give target time to initialize
}

void loop()
{

	//should code be runned in this loop?
	if (i != 0) {
		DigiKeyboard.sendKeyStroke(0);

		//parse raw duckencoder script
		for (int i=0; i<DUCK_LEN; i+=2)
		{
			uint8_t key = pgm_read_word_near(duckraw + i);
			uint8_t mod = pgm_read_word_near(duckraw + i+1);
			if (key == 0) //delay (a delay>255 is split into a sequence of delays)
			{
				DigiKeyboard.delay(mod);
			}
			else DigiKeyboard.sendKeyStroke(key,mod);
		}
		i--;
		DigiKeyboard.delay(5000); //wait 5000 milliseconds before next loop iteration

	}
	else if (blink)
	{
		digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
		digitalWrite(1, HIGH);
		delay(100);               // wait for a second
		digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
		digitalWrite(1, LOW);
		delay(100);               // wait for a second
	}
}
