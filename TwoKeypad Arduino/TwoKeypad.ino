// Include Arduino Wire library for I2C
#include <Wire.h>
// Include LCD display library for I2C
#include <LiquidCrystal_I2C.h>
// Include Keypad library
#include <Keypad.h>

// Constants for row and column sizes for keypad 1
const byte ROWS1 = 4;
const byte COLS1 = 4;

// Constants for row and column sizes for keypad 2
const byte ROWS2 = 4;
const byte COLS2 = 4;

// Array to represent keys on keypad 1
char hexaKeys1[ROWS1][COLS1] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Array to represent keys on keypad 2
char hexaKeys2[ROWS2][COLS2] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connections to Arduino
byte rowPins1[ROWS1] = {53, 52, 51, 50};
byte colPins1[COLS1] = {49, 48, 47, 46};

// Connections of keypad 2 to Arduino
byte rowPins2[ROWS2] = {19, 18, 17, 16};
byte colPins2[COLS2] = {15, 14, 13, 12};

// Create keypad 1 & 2 object
Keypad customKeypad1 = Keypad(makeKeymap(hexaKeys1), rowPins1, colPins1, ROWS1, COLS1);
Keypad customKeypad2 = Keypad(makeKeymap(hexaKeys2), rowPins2, colPins2, ROWS2, COLS2);

// Create LCD objects LCD1 & LCD2
LiquidCrystal_I2C lcd1(0x23, 20, 4);
LiquidCrystal_I2C lcd2(0x27, 16, 2);

//Array to store bus station
String Vituo[] = {"", "FERRY", "POSTA", "COUNCIL", "KISUTU", "DIT", "FIRE", "JANGWANI", "MAPIPA"};


//Variable
char customKey1;
char customKey2;
const int buzzer = 10;


//Function called to confirm the choice of a bus station
void Confirmation(char kituoChar) {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Umechagua");
  lcd1.setCursor(10, 0);
  int kituoInt = kituoChar - '0';
  lcd1.print(Vituo[kituoInt]);
  lcd1.setCursor(0, 1 );
  lcd1.print("Bonyeza * kukubali");
  lcd1.setCursor(0, 2);
  lcd1.print("Bonyeza # kuktaa");
}


//Function to confirm the destination of choice
void Confirmation2(char kituoChar) {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Umefika");
  lcd1.setCursor(10, 0);
  int kituoInt = kituoChar - '0';
  lcd1.print(Vituo[kituoInt]);
  lcd1.setCursor(0, 1 );
  lcd1.print("Tafadhali shuka");
}

//Function gives driver info about the choice of a bus station
void Driver(char kituoChar) {
  if (customKey2 == '1') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '2') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '3') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '4') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '5') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '6') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '7') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
  if (customKey2 == '8') {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Umefika");
    lcd1.setCursor(10, 0);
    int kituoInt = kituoChar - '0';
    lcd1.print(Vituo[kituoInt]);
    lcd1.setCursor(0, 1 );
    lcd1.print("Tafadhali shuka");
    delay(10000);
  }
}
void setup() {
  // Setup LCD with backlight and initialize
  lcd1.backlight();
  lcd1.init();
  lcd2.init();
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

menu:
  //lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("1.FERRY");
  lcd1.setCursor(11, 0);
  lcd1.print("2.POSTA");
  lcd1.setCursor(0, 1);
  lcd1.print("3.COUNCIL");
  lcd1.setCursor(11, 1);
  lcd1.print("4.KISUTU");
  lcd1.setCursor(0, 2);
  lcd1.print("5.DIT");
  lcd1.setCursor(11, 2);
  lcd1.print("6.FIRE");
  lcd1.setCursor(0, 3);
  lcd1.print("7.JANGWANI");
  lcd1.setCursor(11, 3);
  lcd1.print("8.MAPIPA");

  customKey1 = customKeypad1.getKey();        //Listening he pressed number in keypad 1 for h selection of choice

  if (customKey1 == '1') {
    Confirmation(customKey1);           //If someone choose bus statin 1 call the confimation  1 to confirm his/her choice

    while ( customKey1 == '1') {
      char customKey1 = customKeypad1.getKey();         //Waiting for a paasenger to confirm or cancel his/her choice

      if (customKey1 == '*') {              //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("FERRY");
        Serial.println(customKey1);
        tone(buzzer, 10000);
        delay(1000);
        noTone(buzzer);
        delay(100);
        lcd1.clear();
        goto menu;
      }
      else if (customKey1 == '#') {       //if he/she cancel returnn to print menu
        lcd1.clear();
        goto menu;
      }
    }
  }

  if (customKey1 == '2') {                      //If someone choose bus statin 2 call the confimation  1 to confirm his/her choice
    Confirmation(customKey1);

    while ( customKey1 == '2') {
      char customKey1 = customKeypad1.getKey();             //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("POSTA");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {             //if he/she cancel returnn to print menu
        lcd1.clear();
        goto menu;
      }
    }
  }

  if (customKey1 == '3') {                      //If someone choose bus statin 3 call the confimation  1 to confirm his/her choice
    Confirmation(customKey1);

    while ( customKey1 == '3') {
      char customKey1 = customKeypad1.getKey();       //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                      //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("COUNCIL");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {                         //if he/she cancel returnn to print menu
        goto menu;
      }
    }
  }

  if (customKey1 == '4') {            //If someone choose bus statin 4 call the confimation  1 to confirm his/her choice
    Confirmation(customKey1);

    while ( customKey1 == '4') {
      char customKey1 = customKeypad1.getKey();       //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                      //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("KISUTU");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {                       //if he/she cancel returnn to print menu
        goto menu;
      }
    }
  }

  if (customKey1 == '5') {          //If someone choose bus statin 5 call the confimation  1 to confirm his/her choice
    Confirmation(customKey1);

    while ( customKey1 == '5') {
      char customKey1 = customKeypad1.getKey();       //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                        //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("DIT");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {
        goto menu;
      }
    }
  }

  if (customKey1 == '6') {              //If someone choose bus statin 6 call the confimation  1 to confirm his/her choice
    Confirmation(customKey1);

    while ( customKey1 == '6') {
      char customKey1 = customKeypad1.getKey();         //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                          //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("FIRE");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {                 //if he/she cancel returnn to print menu
        goto menu;
      }
    }
  }

  if (customKey1 == '7') {              //If someone choose bus statin 7 call the confimation  1 to confirm his/her choice
    Confirmation(customKey1);

    while ( customKey1 == '7') {
      char customKey1 = customKeypad1.getKey();       //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                          //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("JANGWANI");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {                 //if he/she cancel returnn to print menu
        goto menu;
      }
    }
  }

  if (customKey1 == '8') {
    Confirmation(customKey1);

    while ( customKey1 == '8') {            //If someone choose bus statin 8 call the confimation  1 to confirm his/her choice
      char customKey1 = customKeypad1.getKey();         //Waiting for a paasenger to confirm or cancel his/her choice
      if (customKey1 == '*') {                      //if he/she confirm the info transfer to a driver
        lcd2.clear();
        lcd2.setCursor(0, 0);
        lcd2.print("MAPIPA");
        Serial.println(customKey1);
        tone(buzzer, 1000);
        delay(100);
        noTone(buzzer);
        delay(100);
        goto menu;
      }
      else if (customKey1 == '#') {                   //if he/she cancel returnn to print menu
        goto menu;
      }
    }
  }
  customKey2 = customKeypad2.getKey();
  if (customKey2) {
    Driver(customKey2);
  }

}
