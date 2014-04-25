#define PIN_BUTTON  (2)
#define PIN_LED  (13)
#define BAUDRATE    (57600)

// globals
int buttonState = 0;  // variable for reading the pushbutton status

int val         = 0;
boolean hit     = true;



void setup() {
  pinMode(PIN_BUTTON, INPUT);     
  Serial.begin(BAUDRATE);
}

void loop() {
  unsigned char buffer[1] = {
    0                              };
  ////////////BUTTON/////////////

  buttonState = digitalRead(PIN_BUTTON);
  if(hit){
    if (buttonState == HIGH)  {
      buffer[0] = 1;
      hit = false;
    } 
    else {
      buffer[0] = 0;
    }
  }
  ////////////READING VALUE FROM OF/////////////
  val = Serial.read();
  if (val != -1) {
    if (val == 'a') {
      hit = true;
    }
  }


  Serial.write(buffer, 1);
}





















