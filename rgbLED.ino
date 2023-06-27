int NINER = 9;
int LUCKY = 13;
int THREE = 3;
String c;
int intro_text = 0;
int wrong_entry_text = 0;

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
  if (intro_text == 0) {
	Serial.println("please type: 'red', 'green', or 'blue' into the input!");
    intro_text = 1;
  }
  
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
    else {
      
    if (c.length() >= 1 && wrong_entry_text == 0) {           
      Serial.println("select: 'red', 'green', or 'blue', please");
      wrong_entry_text = 1;
    } else {
		return
    } 
  }
}
