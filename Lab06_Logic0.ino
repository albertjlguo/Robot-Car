/*
  ELEC1100 Lab06

  Have the car turn left at split

*/

// assign meaningful names to those pins that will be used
#define pinLeftSensor A1      //pin A1
#define pinRightSensor A3     //pin A3
#define pinMiddleSensor A2    //pin A2

#define pinLDir 2             //pin D2
#define pinRDir 3             //pin D3

#define pinLQ0 5              //pin D5
#define pinLQ1 6              //pin D6
#define pinLQ2 7              //pin D7
#define pinLQ3 8              //pin D8

#define pinRQ0 9              //pin D9
#define pinRQ1 10             //pin D10
#define pinRQ2 11             //pin D11
#define pinRQ3 12             //pin D12

//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int middleSensor = 1;
int numberOfZone = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinMiddleSensor, INPUT);

  pinMode(pinLDir, OUTPUT);
  pinMode(pinRDir, OUTPUT);

  pinMode(pinLQ0, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ3, OUTPUT);

  pinMode(pinRQ0, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ3, OUTPUT);

  // initialize output pins.
  digitalWrite(pinLDir, HIGH);        // HIGH: forward rotate
  digitalWrite(pinRDir, HIGH);        // LOW:  reverse rotate
  digitalWrite(pinLQ0, LOW);
  digitalWrite(pinLQ1, LOW);
  digitalWrite(pinLQ2, HIGH);
  digitalWrite(pinLQ3, HIGH);
  digitalWrite(pinRQ0, LOW);
  digitalWrite(pinRQ1, LOW);
  digitalWrite(pinRQ2, HIGH);
  digitalWrite(pinRQ3, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  
  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  middleSensor = digitalRead(pinMiddleSensor);
  
  if ( leftSensor && rightSensor ) {
    digitalWrite(pinLDir, HIGH);
    digitalWrite(pinRDir, HIGH);
    
  }//FORWARD

  if ( !leftSensor && rightSensor ) {
    digitalWrite(pinLDir, LOW);
    digitalWrite(pinRDir, HIGH);
    
  }//LEFT

   if ( leftSensor && !rightSensor ) {
    digitalWrite(pinLDir, HIGH);
    digitalWrite(pinRDir, LOW);
    
  }//RIGHT

  if ( !leftSensor && !rightSensor ) {
    numberOfZone += 1;
    if (numberOfZone < 3){
      digitalWrite(pinLDir, LOW);
      digitalWrite(pinRDir, HIGH);
      
      }//LEFT
    if (numberOfZone == 3){
      digitalWrite(pinLDir, HIGH);
      digitalWrite(pinRDir, LOW);
      
      }//RIGHT

  }//1-2 LEFT

}
