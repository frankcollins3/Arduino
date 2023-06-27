#define MAX_WORDS_LENGTH 13
#define MAX_WORDS 20
#define LUCKY 13

String sen;
String uppercasetoggle;
String lowercasetoggle;
int tokenize_yet = 0;

struct Word {
  int length;
  char prefix[5];
  struct Word *next;
};

typedef struct Word Word;
Word words[MAX_WORDS];

struct Word *head = nullptr;
struct Word *end = nullptr;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LUCKY, OUTPUT);
}

void loop() {
  // Your loop code here
  
  if (tokenize_yet == 0) {
   	Serial.println("hey tokenize once!");
    tokenize_yet = 1;
  }
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

void tokenize(String usersentence) 
{
 int word_index = 0;
 int i = 0;
 int len = usersentence.length();
 
  for (i; i < len; i++) {
    char c = usersentence[i];
    if (c == ' ' || c == '\n') {
		words[i].length = word_index;
 strncpy(words[word_index].prefix, &usersentence[i],
              words[word_index].length >= 4 ? 4 : words[word_index].length);
    }
  }
  
}
