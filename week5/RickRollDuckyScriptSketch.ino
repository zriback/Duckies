/*
* Sketch generated by duck2spark from Marcus Mengs aka MaMe82
*
*/
#include "DigiKeyboard.h"

#define DUCK_LEN 166
const PROGMEM uint8_t duckraw [DUCK_LEN] = {
	21, 8, 0, 200, 6, 0, 11, 0, 21, 0, 18, 0, 16, 0, 8, 0, 55, 0, 8, 0, 27, 0, 8, 0, 0, 200, 40, 0, 0, 200, 11, 0, 23, 0, 23, 0, 19, 0, 22, 0, 51, 2, 56, 0, 56, 0, 26, 0, 26, 0, 26, 0, 55, 0, 28, 0, 18, 0, 24, 0, 23, 0, 24, 0, 5, 0, 8, 0, 55, 0, 6, 0, 18, 0, 16, 0, 56, 0, 26, 0, 4, 0, 23, 0, 6, 0, 11, 0, 56, 2, 25, 0, 46, 0, 7, 0, 20, 2, 26, 0, 33, 0, 26, 0, 38, 0, 26, 2, 10, 0, 27, 2, 6, 0, 20, 2, 36, 2, 4, 0, 5, 0, 45, 2, 6, 0, 11, 0, 4, 0, 17, 0, 17, 0, 8, 0, 15, 0, 46, 0, 21, 2, 12, 0, 6, 0, 14, 0, 4, 2, 22, 0, 23, 0, 15, 0, 8, 0, 28, 0, 0, 200, 40, 0, 0, 200
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
