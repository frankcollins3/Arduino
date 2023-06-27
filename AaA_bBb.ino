#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10

struct Word {
  char w[MAX_WORD_LENGTH];
};

Word words[MAX_WORDS];

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    tokenize(input);
    printWords();
  }
}

void tokenize(String sentence) {
  int wordIndex = 0;
  int charIndex = 0;

  for (int i = 0; i < sentence.length(); i++) {
    char c = sentence.charAt(i);
    
    if (c == ' ') {
      words[wordIndex].w[charIndex] = '\0'; // Null-terminate the word
      wordIndex++;
      charIndex = 0;
    } else {
      if (wordIndex < MAX_WORDS && charIndex < MAX_WORD_LENGTH - 1) {
        words[wordIndex].w[charIndex] = c;
        charIndex++;
      }
    }
  }
  
  words[wordIndex].w[charIndex] = '\0'; // Null-terminate the last word
}

void printWords() {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].w[0] != '\0') {
      Serial.print("Word ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(words[i].w);
    }
  }
}
