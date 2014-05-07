
#include <avr/eeprom.h>
#include <Bounce.h>


Bounce button1 = Bounce(A0, 50);
Bounce button2 = Bounce(A1, 50);  
Bounce button3 = Bounce(A2, 50);
Bounce button4 = Bounce(11, 50);
Bounce button5 = Bounce(10, 50);  

unsigned long  timeOfPress = 0;
byte mode = 1;

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

  eeprom_read_block((void*)&mode, (void*)0, sizeof(mode));
  
  Serial.begin (115200);
  Keyboard.begin();

}

void loop() {
  if (button1.update()) {
    if (button1.fallingEdge()) {
      timeOfPress = millis();
    }
    else if (button1.risingEdge()) {
      if (millis() - timeOfPress > 2000) {
        mode = 1;
        eeprom_write_block((const void*)&mode, (void*)0, sizeof(mode));
        Serial.println("Mode is nu 1");
      }
      switch (mode) {
        case 1: 
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('2');
          delay(10);
          Keyboard.releaseAll();
          break;
        case 2:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_BACKSPACE);
          delay(10);            
          Keyboard.releaseAll();
          break;
        case 3:
          Keyboard.print("demo, 1");
          break;
        case 4:          
          Keyboard.press(KEY_LEFT_GUI);        
          Keyboard.press('q');
          delay(10);            
          Keyboard.releaseAll();          
          break;
        case 5:          
          //code
          break;        
      }
    }
  }
  if (button2.update()) {
    if (button2.fallingEdge()) {
      timeOfPress = millis();
    }
    else if (button2.risingEdge()) {
      if (millis() - timeOfPress > 2000) {
        mode = 2;
        eeprom_write_block((const void*)&mode, (void*)0, sizeof(mode));        
        Serial.println("Mode is nu 2");        
      }
      switch (mode) {
        case 1: 
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('3');
          delay(10);
          Keyboard.releaseAll();
          break;
        case 2:
          Keyboard.press(KEY_BACKSPACE);
          delay(10);
          Keyboard.releaseAll();
          break;
        case 3:
          Keyboard.print("demo, 2");
          break;
        case 4:          
          Keyboard.press(KEY_LEFT_GUI);        
          Keyboard.press('s');
          delay(10);            
          Keyboard.releaseAll();          
          break;
        case 5:          
          //code
          break;        
      }
    }    
  }
  if (button3.update()) {
    if (button3.fallingEdge()) {
      timeOfPress = millis();
    }
    else if (button3.risingEdge()) {
      if (millis() - timeOfPress > 2000) {
        mode = 3;
        eeprom_write_block((const void*)&mode, (void*)0, sizeof(mode));
        Serial.println("Mode is nu 3");        
      }
      switch (mode) {
        case 1: 
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('4');
          delay(10);
          Keyboard.releaseAll();
          break;
        case 2:
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('r');
          delay(10);
          Keyboard.releaseAll();          
          break;
        case 3:
          //code
          break;
        case 4:          
          Keyboard.press(KEY_LEFT_GUI);        
          Keyboard.press(KEY_TAB);
          delay(10);            
          Keyboard.releaseAll();          
          break;
        case 5:          
          //code
          break;        
      }
    }    
  }
  if (button4.update()) {
    if (button4.fallingEdge()) {
      timeOfPress = millis();
    }
    else if (button4.risingEdge()) {
      if (millis() - timeOfPress > 2000) {
        mode = 4;
        eeprom_write_block((const void*)&mode, (void*)0, sizeof(mode));        
        Serial.println("Mode is nu 4");        
      }
      switch (mode) {
        case 1: 
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('5');
          delay(10);
          Keyboard.releaseAll();
          break;
        case 2:
          //code
          break;
        case 3:
          Keyboard.print("demo, 4");
          break;
        case 4:          
          Keyboard.press(KEY_LEFT_GUI);        
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_TAB);
          delay(10);            
          Keyboard.releaseAll();  
          break;
        case 5:          
          //code
          break;        
      }
    }    
  }
  if (button5.update()) {
    if (button5.fallingEdge()) {
      timeOfPress = millis();
    }
    else if (button5.risingEdge()) {
      if (millis() - timeOfPress > 2000) {
        if (millis() - timeOfPress > 10000) {
          Keyboard.print("Hoi!\n\nDit wordt de handleiding van het knoppending. Veel plezier!\n\nHerman\nherman@kopinga.nl");
        }
        mode = 5;
        eeprom_write_block((const void*)&mode, (void*)0, sizeof(mode));        
        Serial.println("Mode is nu 5");        
      }
      switch (mode) {
        case 1: 
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.write('z');
          delay(10);
          Keyboard.releaseAll();
          break;
        case 2:
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('a');
          delay(10);
          Keyboard.releaseAll();          
          break;
        case 3:
          Keyboard.print("demo, 5");
          break;
        case 4:          
          Keyboard.press(KEY_LEFT_GUI);        
          Keyboard.press('`');
          delay(10);            
          Keyboard.releaseAll();  
          break;
        case 5:          
          //code
          break;        
      }
    }    
  }

}


