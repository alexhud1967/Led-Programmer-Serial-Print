

/* This is noteworthy: when I enter a line of  
 *  5 'e's, output is 5 dots, or 1s, really.  
 *  In a Jandy system, then, "Sky Blue" would be
 *  
 *  [e][e]
 *  
 *  for two ON pulses.
 *  White is defined as "ON, OFF [delay 4.5 seconds] ON"
 *  so, using delay can define this, two. In that case, we 
 *  can use char to define the string "sky blue" toe output White,
 *  then EE for sky blue..
 *  
 * 
 * 
 */
 
 
 int ledPin = 13;

//For letters
char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

//For Numbers
char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....",
"-....", "--...", "---..", "----."
};
int dotDelay = 200;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char ch;
if (Serial.available())
{
ch = Serial.read(); // read a single letter if (ch >= 'a' && ch <= 'z')
if (ch >= 'a' && ch <= 'z')
{
flashSequence(letters[ch - 'a']);
}
else if (ch >= 'A' && ch <= 'Z') {
flashSequence(letters[ch - 'A']); }
else if (ch >= '0' && ch <= '9') {
flashSequence(numbers[ch - '0']); }
else if (ch == ' ') {
delay(dotDelay * 4);
}
}

}

void flashSequence(char* sequence) {
int i = 0;
while (sequence[i] != NULL) {
        flashDotOrDash(sequence[i]);
i++; }
delay(dotDelay * 3);
}


void flashDotOrDash(char dotOrDash) {
digitalWrite(ledPin, HIGH); if (dotOrDash == '.')
{
    delay(dotDelay);
  }
else // must be a - 
{
delay(dotDelay * 3); }
digitalWrite(ledPin, LOW); delay(dotDelay);
}
