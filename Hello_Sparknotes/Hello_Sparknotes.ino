
//LED pin
int LED1=1;

//Button pin
int b1=0;

//this will be the notifier for the light to know if the button has changed states
int state=0;

//This records the state of the button
boolean bs=false;

//this will depict the previous state of the button
boolean bps=false;


void setup() {
//pin setup
 pinMode(LED1, OUTPUT);
 pinMode(b1, INPUT);
}

void loop() {

 bs = debounce (b1, bps);

 //Changes button state
 if (bs==true && bs==!bps){
 state=1+state;
 }
 
 if (state==0) {
 digitalWrite(LED1, HIGH);
 } else if (state==1) {
 digitalWrite(LED1, LOW);
 } else if (state==2) {
 digitalWrite(LED1, HIGH);
 delay(100);
 digitalWrite(LED1,LOW);
 delay(100);
 }
 
 //resets the state if it goes over 3
 if (state>=3){
  state=0;
 }

//Sets button state pt previous button state
 bps=bs;
}

//this function prevent bouncing to influence the state of the button
boolean debounce (int aButton, boolean aPrevState) {
  boolean aButtonState = digitalRead(aButton);
  if (aButtonState != aPrevState) {
    delay(5);
    aButtonState = digitalRead(aButton);
  }
  return aButtonState;
}
