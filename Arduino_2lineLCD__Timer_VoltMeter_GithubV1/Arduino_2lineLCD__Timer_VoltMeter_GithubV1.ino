/*
  
  NOW With a Volt Meter!
  Voltage meter also based on Superfish1000 sketch here: http://www.instructables.com/id/Arduino-Voltage-Sensor-0-25V/
  Just examples of sketches to use with the LCD display

  
 LiquidCrystal Library - Timer in Hours, Miutes and Seconds

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
int val11;
float val2;

int val13;
float val4;


const int VMAX=12;   //Warning for overvoltage

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  Serial.println("Voltage Display Module");

  Serial.println("Voltage: ");
  Serial.print("V");

 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
/*  
  // Print a message to the LCD.
  lcd.print("Voltage read is:");
*/  
}

void loop() {
      float temp;
      val11=analogRead(A3 );    //Input pin anologue 2
      temp=val11/4.092;         //int val11;
      val2=(temp/10);           //float val2;
      Serial.print("A2:");
      Serial.println(val2);    

       









      
   delay(1000);
// ==========================================================================
// Write Maximum voltage warning here!! version - 1
/*
  if (val2>VMAX)
  {
  lcd.setCursor(8, 0);   // COLUMN, ROW  variable read out here over-voltage show M for maximum 
  lcd.print("M");
  delay (1000);
  lcd.setCursor(8, 0);   // COLUMN, ROW  variable read out here overvoltage - Blink on-off the M   
  lcd.print(" ");

  }
  else 
  {
  lcd.setCursor(8, 0);   // COLUMN, ROW  Blank off M character if not required.
  lcd.print(" ");

  }
  */
// ==========================================================================
// Write Maximum voltage warning here!! version - 2
  if (val2>VMAX)   // this vmax voltage is set in setup as variable
  {
  lcd.setCursor(4, 0);   // COLUMN, ROW  variable read out here over-voltage show M for maximum 
  lcd.print("MAX");
  delay (1000);
  lcd.setCursor(4, 0);   // COLUMN, ROW  variable read out here overvoltage - Blink on-off the M   
  lcd.print("   ");

  }
  else 
  {
  lcd.setCursor(4, 0);   // COLUMN, ROW  Blank off M character if not required.
  lcd.print("   ");

  }
  
// ==========================================================================
  // Print voltage  message to the LCD. note: line 0 is the first row, since counting begins with 0, COLUMN then ROW
  lcd.setCursor(0, 0);  // COLUMN, ROW
  lcd.print("Voltage:");

  if (val2<10)
  {
  lcd.setCursor(10, 0);   // COLUMN, ROW  variable read out here over 1x digit as its only 1-9 
  lcd.print(val2);
  lcd.setCursor(9, 0);   // COLUMN, ROW  Blank off unused 1st digit if it has prevuously been written.   Other wise there is a"1" left over soo you get 19 not 9 for example
  lcd.print(" ");

  }
  else 
  {
  lcd.setCursor(9, 0);   // COLUMN, ROW  variable read out here, to the left 1x digit as its 10 upwards  
  lcd.print(val2);
  }

    
  lcd.setCursor(14, 0);  // COLUMN, ROW
  lcd.print("v");
  

// ==========================================================================
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // lcd.print ("Timer:");
  // lcd.print(millis() / 1000);
  
unsigned long Now = millis()/1000;
  int Seconds = Now%60;
  int Minutes = (Now/60)%60;
  int Hours = (Now/3600)%24;
  
  lcd.setCursor(0, 1); 
  lcd.print("H:"); lcd.print(Hours);
    
  lcd.setCursor(5, 1); 
  lcd.print("M:"); lcd.print(Minutes); 
  
        lcd.setCursor(13,1);               // This to cover up the 0-9 next digit left over when it reaches 59 and loops back to 1 ie a "9" will stay on the display during 1-9
        lcd.print(" ");                    // This covers up the previous value of left over digit

  lcd.setCursor(10, 1);   
  lcd.print("S:"); lcd.print(Seconds); 

/*
  
  
//  delay(1000);

  
// Serial.print(Hours); Serial.print(':'); 
//  Serial.print(Minutes); Serial.print(':'); 
//  Serial.print(Seconds); Serial.println();
//  delay(1000);


  Serial.print("H:");
  Serial.print(Hours); Serial.print(':'); 
  Serial.print("  M:");
  Serial.print(Minutes); Serial.print(':'); 
  Serial.print("  S:");
  Serial.print(Seconds); Serial.println();
  delay(1000); 
  
*/
  
}
