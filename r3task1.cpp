// Daniel Su, Sept 28, R3 software task

const int TENS_FIRST_OUTPUT = 5; // BCD output pins
const int TENS_SECOND_OUTPUT = 4;
const int TENS_THIRD_OUTPUT = 3;
const int TENS_FOURTH_OUTPUT = 2;
const int ONES_FIRST_OUTPUT = 9;
const int ONES_SECOND_OUTPUT = 8;
const int ONES_THIRD_OUTPUT = 7;
const int ONES_FOURTH_OUTPUT = 6;

void setup()
{
	Serial.begin(9600);
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
	int adc = analogRead(5);
	adc = map(adc, 0, 1023, 0, 99);

	int first = adc / 10;
	int second = adc % 10;

	bool firstDigits[] = {first / 8 == 1, first / 4 % 2 == 1, first / 2 % 2 == 1, first % 2 == 1};
	bool secondDigits[] = {second / 8 == 1, second / 4 % 2 == 1, second / 2 % 2 == 1, second % 2 == 1};

	if (firstDigits[0])
		digitalWrite(TENS_FIRST_OUTPUT, HIGH);
	else
		digitalWrite(TENS_FIRST_OUTPUT, LOW);
	if (firstDigits[1])
		digitalWrite(TENS_SECOND_OUTPUT, HIGH);
	else
		digitalWrite(TENS_SECOND_OUTPUT, LOW);
	if (firstDigits[2])
		digitalWrite(TENS_THIRD_OUTPUT, HIGH);
	else
		digitalWrite(TENS_THIRD_OUTPUT, LOW);
	if (firstDigits[3])
		digitalWrite(TENS_FOURTH_OUTPUT, HIGH);
	else
		digitalWrite(TENS_FOURTH_OUTPUT, LOW);
		
	if (secondDigits[0])
		digitalWrite(ONES_FIRST_OUTPUT, HIGH);
	else
		digitalWrite(ONES_FIRST_OUTPUT, LOW);
	if (secondDigits[1])
		digitalWrite(ONES_SECOND_OUTPUT, HIGH);
	else
		digitalWrite(ONES_SECOND_OUTPUT, LOW);
	if (secondDigits[2])
		digitalWrite(ONES_THIRD_OUTPUT, HIGH);
	else
		digitalWrite(ONES_THIRD_OUTPUT, LOW);
	if (secondDigits[3])
		digitalWrite(ONES_FOURTH_OUTPUT, HIGH);
	else
		digitalWrite(ONES_FOURTH_OUTPUT, LOW);

	delay(50);
}