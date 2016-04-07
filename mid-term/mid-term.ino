

//display pins
int segA = 5;  // >>  11
int segB = 13; // >>  7
int segC = 10; // >>  4
int segD = 8;  // >>  2
int segE = 7;  // >>  1
int segF = 4;  // >>  10
int segG = 11; // >>  5
int segPt = 9; // >>  3
//------------//

//display digit
int d1 = 6;   // >> 12
int d2 = 3;   // >> 9
int d3 = 2;   // >> 8
int d4 = 12;  // >> 6
//------------//

int delayTime = 5000; //delayTime <Don't change it, if you don't know where is it!>

int i=0;

//=============================================//
//init all pin used

//We always have to include the library
#include "LedControlMS.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);
LedControl lcd=LedControl(4,5,6,7);

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
//  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
//  /* and clear the display */
////  lc.clearDisplay(0);
//
   lcd.shutdown(0,false);
//  /* Set the brightness to a medium values */
  lcd.setIntensity(0,8);
//  /* and clear the display */
////  lcd.clearDisplay(0);

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
}


void writeArduinoOnMatrix() {

  byte a[8]={B00010000,B00101010,B00010100,B00111000,B01010000,B10010000,B00101000,B01000100};
  byte b[8]={B00010000,B10101000,B01010000,B00111000,B00010100,B00010010,B00101000,B01000100};

//led matrix player 1
  lc.setRow(0,0,b[0]);
  lc.setRow(0,1,b[1]);
  lc.setRow(0,2,b[2]);
  lc.setRow(0,3,b[3]);
  lc.setRow(0,4,b[4]);
  lc.setRow(0,5,b[5]);
  lc.setRow(0,6,b[6]);
  lc.setRow(0,7,b[7]);

//led matrix player 2
  lcd.setRow(0,0,a[0]);
  lcd.setRow(0,1,a[1]);
  lcd.setRow(0,2,a[2]);
  lcd.setRow(0,3,a[3]);
  lcd.setRow(0,4,a[4]);
  lcd.setRow(0,5,a[5]);
  lcd.setRow(0,6,a[6]);
  lcd.setRow(0,7,a[7]);

}



void loop() { 
  writeArduinoOnMatrix();
  down(0,0,6,0);
}

//Write a Number - writeN(1,9,9,0) -> 1990
void writeN(int a,int b,int c,int d){
    selectDwriteL(1,a);
    selectDwriteL(2,b);
    selectDwriteL(3,c);
    selectDwriteL(4,d);
}

//=============================================//
//Make a Number Number Countdown (Timers).
void down(int a,int b,int c,int d){
  while (a != -1) {
    while(b != -1){
      while(c != -1){
        while (d != -1) {
          while (i<10) { // i here is like a timer ! because we can't use delay function
            selectDwriteL(1,a);
            selectDwriteL(2,b);
            selectDwriteL(3,c);
            selectDwriteL(4,d);
            i++;
          }
          i=0;
          d--;
        }
        d=9;
        c--;
      }
      c=9;
      b--;
    }
    b=9;
    a--;
    }
}

//=============================================//
//Select Wich Digit (selectD) is going to Display (writeL)
void selectDwriteL(int d,int l){
  switch (d) { // choose a digit
    case 0: digitalWrite(d1, LOW); //case 0 - All ON
            digitalWrite(d2, LOW);
            digitalWrite(d3, LOW);
            digitalWrite(d4, LOW);
            break;
    case 1: digitalWrite(d1, LOW);//case 1 - Digit Number 1
            digitalWrite(d2, HIGH);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, HIGH);
            break;
    case 2: digitalWrite(d1, HIGH);//case 1 - Digit Number 2
            digitalWrite(d2, LOW);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, HIGH);
            break;
    case 3: digitalWrite(d1, HIGH);//case 1 - Digit Number 3
            digitalWrite(d2, HIGH);
            digitalWrite(d3, LOW);
            digitalWrite(d4, HIGH);
            break;
    case 4: digitalWrite(d1, HIGH);//case 1 - Digit Number 4
            digitalWrite(d2, HIGH);
            digitalWrite(d3, HIGH);
            digitalWrite(d4, LOW);
            break;
  }

  switch (l) { // choose a Number
    case 0: zero();
            break;
    case 1: one();
            break;
    case 2: two();
            break;
    case 3: three();
            break;
    case 4: four();
            break;
    case 5: five();
            break;
    case 6: six();
            break;
    case 7: seven();
            break;
    case 8: eight();
            break;
    case 9: nine();
            break;
    case 10: point(); // print a Point
            break;
    case 11: none(); // make all them off !
            break;
  }

delayMicroseconds(delayTime); // delayTime for nice display of the Number !

}

//=============================================//
//shown one Number in the 4 Digit
void all(int n){
  selectDwriteL(0,n);
}

//=============================================//
void zero(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}
//=============================================//
void one(){
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}
//=============================================//
void two(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void three(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void four(){
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void five(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void six(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void seven(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}
//=============================================//
void eight(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void nine(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segPt, LOW);
}
//=============================================//
void point(){
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, HIGH);
}
//=============================================//
void none(){
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segPt, LOW);
}
  
