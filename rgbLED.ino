int NINER = 9;
int LUCKY = 13;
int THREE = 3;
String c;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(NINER, OUTPUT);
  pinMode(THREE, OUTPUT);
  pinMode(LUCKY, OUTPUT);
}

void loop()
{ 

  c = Serial.readString();
  Serial.println(c);
  changebulb(c);

  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void changebulb(String light) {
  if (light.equals("red")) {
	digitalWrite(LUCKY, HIGH);
  } 
  if (light.equals("blue")) { 
	digitalWrite(NINER, HIGH);	
  }
  if (light.equals("green")) {
   	digitalWrite(THREE, HIGH); 
  }
}
