//This allows an arduino (mega was used for us) to ocillate between two sets of lots of LEDs
//Further, using I2C from the speaker Arduino, it allows the music to be synced to the LED switching and thus only switch on every beat.
#include<Wire.h>
   bool flipFlopFlag = false;
   int evenPins[] = {0,2,4,6,8,10,12,14,16,18,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,A0,A2,A4,A6,A8,A10,A12,A14};
   int oddPins[] = {1,3,5,7,9,11,13,15,17,19,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,A1,A3,A5,A7,A9,A11,A13,A15};
void setup() {
  Serial.begin(9600);
  Wire.begin();
  //20/21 are I2C pins SCL and SDA and thus unused here
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(54, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(A12, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);
  //All but 20/21 as they are I2C pins
      for(int x=0;x<35;x++){
      digitalWrite(evenPins[x], HIGH);
    }
    for(int x=0;x<35;x++){
      digitalWrite(oddPins[x], LOW);
    }
   
}

void loop() {

//testMode(); // a debug mode for those who are building the LED arrays to quickly test their circuits
  Wire.requestFrom(1, 1);//From Sender 1, request 1 byte
  
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
    if(c == 'f') //Arbitrary decision
    {
      doAFlip();
    }
 // }

  delay(100);

}


void doAFlip(){ //Performs the flip back and forth between odd and even pin pairs
  Serial.println("\nFLIP");
  if(flipFlopFlag){
  //Flip even/odd
    for(int x=0;x<35;x++){
      digitalWrite(evenPins[x], HIGH);
    }
    for(int x=0;x<35;x++){
      digitalWrite(oddPins[x], LOW);
    }
  }
  else{
 //Opposite of above
     for(int x=0;x<35;x++){
      digitalWrite(evenPins[x], LOW);
    }
    for(int x=0;x<35;x++){
      digitalWrite(oddPins[x], HIGH);
    }
  }
  flipFlopFlag = !flipFlopFlag;
}

void testMode(){
 digitalWrite(15, LOW);
  digitalWrite(14, HIGH);

  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  
  delay(1000);

  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);

  digitalWrite(1, LOW);
  digitalWrite(0, HIGH); 
  delay(1000);
  testMode(); 
}

