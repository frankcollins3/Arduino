// int LED_PIN = 13;
#define SEN_LEN 100;
int hasLooped = 0;
int LUCKY_PIN = 13;
int ELEVENELEVEN = 11;
int PIN_10 = 10;
int NINER = 9;
int bright_lvl = 0;

void setup()
{
  pinMode(NINER, OUTPUT);
  
  Serial.begin(9600);
	
  
  Serial.write('A');
}

void loop()
{
  if (Serial.available()) {
    //  if (Serial.available() && !hasLooped) {
    Serial.println("enter sentence please");
    hasLooped++;
  }
  
  for (brightness; brightness <= 200; brightness++) {
    analogWrite(NINER, brightness);	 
    delay(5);
  }
  
  for (brightness; brightness >= 0; brightness--) {
	analogWrite(NINER, brightness);
    delay(5);
  }
  
  lightSequence();  	 
}


void lightSequence () {
   digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

}
