#define MAX_WORDS_LENGTH 100

#define LUCKY 13

String sen;
String uppercasetoggle;
String lowercasetoggle;
int word_index = 0;

struct Word {
  int length;
  char prefix[5];
  struct Word *next;
};

struct Word words[MAX_WORDS_LENGTH];

struct Word *head = nullptr;
struct Word *end = nullptr;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LUCKY, OUTPUT);
}

void loop() {
  // Your loop code here
}


void init_words() 
{
  for (int i = 0; i < MAX_WORDS_LENGTH; i++) {
    words[i].length = 0;
    memset(words[i].prefix, 0, sizeof(words[i].prefix));
    words[i].next = NULL;
  }
}

void print_words()
{
  head = &words[0];
  while (head != NULL) {
    if (head->length != 0) {
      Serial.println("hey");
//		Serial.println(head->prefix);
    }
  }
}
