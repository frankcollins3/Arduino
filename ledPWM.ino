int PIN_10 = 10;
int NINER = 9;
int brightness = 0;
String sen;


void setup()
{
  pinMode(NINER, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);  
  while (!Serial.available()) {
  }
  
  delay(100); // Delay to ensure complete input is received
}


void loop()
{

  delay(1000);
  delay(1000);     
	writeStringPrintString();
	senLoop();
//  digitalWrite(PIN_10, HIGH);
}

// void blinkSequence() {
//	digitalWrite(13, HIGH);
//	Serial.println("printing to confirm");
// }

void blinkSequence() {
	for (int i = 0; i <= 200; i++) {
//    analogWrite(13, i);	 
      int bright_setter = i / 2;
      analogWrite(9, bright_setter);
	  delay(10);
  }  
}

void lightSequence () {
   digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}


void writeStringPrintString() {
  sen = Serial.readString();
  int str_len = sen.length();
  if (str_len >= 1) {
    Serial.println(sen);    
  } else {
    return; // or continue if in a loop.
  }  
}

void senLoop() {
    for (int i = 0; i < sen.length(); i++) {
	char c = sen[i];
    Serial.print(c);
      if (c == 'B') {
        Serial.println("B aggressive");
		blinkSequence();
    }
  Serial.println();
 }
}

//  lightSequence(); //  brightnessFunc(NINER); // func: loop() | setup()
