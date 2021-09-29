// Daniel Su, Sept 28, R3 software task 1

// Output pin numbers
const int TENS_FIRST_OUTPUT = 9;
const int TENS_SECOND_OUTPUT = 8;
const int TENS_THIRD_OUTPUT = 7;
const int TENS_FOURTH_OUTPUT = 6;
const int ONES_FIRST_OUTPUT = 5;
const int ONES_SECOND_OUTPUT = 4;
const int ONES_THIRD_OUTPUT = 3;
const int ONES_FOURTH_OUTPUT = 2;

void setup()
{
  	// Set all the output pins
	pinMode(TENS_FOURTH_OUTPUT, OUTPUT);
	pinMode(TENS_THIRD_OUTPUT, OUTPUT);
	pinMode(TENS_SECOND_OUTPUT, OUTPUT);
	pinMode(TENS_FIRST_OUTPUT, OUTPUT);
	pinMode(ONES_FOURTH_OUTPUT, OUTPUT);
	pinMode(ONES_THIRD_OUTPUT, OUTPUT);
	pinMode(ONES_SECOND_OUTPUT, OUTPUT);
	pinMode(ONES_FIRST_OUTPUT, OUTPUT);
}

void loop()
{
	// Get the input from the potentiometer and map it to a range of values from 0-99
	int input = analogRead(5);
	input = map(input, 0, 1023, 0, 99);

	// Get the individual tens and ones digits
	int tens = input / 10;
	int ones = input % 10;
	
	// Turn the tens and ones digits into binary
	// 7 -> 0111 -> [false, true, true, true]
	bool tensDigits[] = {tens / 8 == 1, tens / 4 % 2 == 1, tens / 2 % 2 == 1, tens % 2 == 1};
	bool onesDigits[] = {ones / 8 == 1, ones / 4 % 2 == 1, ones / 2 % 2 == 1, ones % 2 == 1};
	
	// Sets the output pins to the tens digit decoder to be high or low
	if (tensDigits[0])
		digitalWrite(TENS_FIRST_OUTPUT, HIGH);
	else
		digitalWrite(TENS_FIRST_OUTPUT, LOW);
	if (tensDigits[1])
		digitalWrite(TENS_SECOND_OUTPUT, HIGH);
	else
		digitalWrite(TENS_SECOND_OUTPUT, LOW);
	if (tensDigits[2])
		digitalWrite(TENS_THIRD_OUTPUT, HIGH);
	else
		digitalWrite(TENS_THIRD_OUTPUT, LOW);
	if (tensDigits[3])
		digitalWrite(TENS_FOURTH_OUTPUT, HIGH);
	else
		digitalWrite(TENS_FOURTH_OUTPUT, LOW);
	
	// Sets the output pins to the ones digit decoder to be high or low
	if (onesDigits[0])
		digitalWrite(ONES_FIRST_OUTPUT, HIGH);
	else
		digitalWrite(ONES_FIRST_OUTPUT, LOW);
	if (onesDigits[1])
		digitalWrite(ONES_SECOND_OUTPUT, HIGH);
	else
		digitalWrite(ONES_SECOND_OUTPUT, LOW);
	if (onesDigits[2])
		digitalWrite(ONES_THIRD_OUTPUT, HIGH);
	else
		digitalWrite(ONES_THIRD_OUTPUT, LOW);
	if (onesDigits[3])
		digitalWrite(ONES_FOURTH_OUTPUT, HIGH);
	else
		digitalWrite(ONES_FOURTH_OUTPUT, LOW);

	delay(50);
}
