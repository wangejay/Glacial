#include <MeetAndroid.h>
MeetAndroid meetAndroid;

const int buttonPin = 4;                 // 按鍵(pushbutton)接在 pin 4
int buttonState = 0;                     // 按鍵狀態

//define LED number. 
int led_green = 13;
int led_red   = 12;
int led_yellow = 9;
int ledPin_PWM = 11; 
//Others




void setup()
{
  pinMode(buttonPin, INPUT);     // 把 buttonPin 設置成 INPUT
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  
  Serial.begin(9600); 
  // register callback functions, which will be called when an associated event occurs.
  meetAndroid.registerFunction(power, 'A');
  meetAndroid.registerFunction(vol_up, 'B');  
  meetAndroid.registerFunction(vol_down, 'C');   
  meetAndroid.registerFunction(up, 'D');
  meetAndroid.registerFunction(down, 'E');  
  meetAndroid.registerFunction(input_sel, 'F');  
  meetAndroid.registerFunction(sel_enter, 'G');  
  meetAndroid.registerFunction(sel_up, 'H');  
  meetAndroid.registerFunction(sel_down, 'I');  
  meetAndroid.registerFunction(led1, 'X');  
  meetAndroid.registerFunction(led2, 'Y');  
  meetAndroid.registerFunction(led3, 'Z');  
  meetAndroid.registerFunction(num1, '1');   
  meetAndroid.registerFunction(num2, '2');
  meetAndroid.registerFunction(num3, '3');  
  meetAndroid.registerFunction(num4, '4');   
  meetAndroid.registerFunction(num5, '5');
  meetAndroid.registerFunction(num6, '6');  
  meetAndroid.registerFunction(num7, '7');   

}

void loop() 
{
  // 讀取按鍵狀態
  
  buttonState = digitalRead(buttonPin);
  meetAndroid.receive(); // you need to keep this in your loop() to receive events

  // 檢查按鍵是否被按下(pressed)
  // 有的話，buttonState 會是 HIGH
  
   // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin_PWM, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin_PWM, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
  
  if (buttonState == HIGH) {    
    // 發射紅外線訊號

    for (int i = 0; i < 3; i++) {
      irsend.sendSony(Power, 12); // Sony TV power code
      delay(45);
    }
    irsend.sendNEC(0x7D7D0EF1, 32);   // MOD Power
    irsend.sendNEC(0xFFFFFFFF, 32);   // MOD Power
    led1(0,0);
    led2(0,0); 
    delay(1000);
  }
}

void power(byte flag, byte numOfValues)
{
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xA90, 12); // Sony TV power code
      delay(45);
    }
    irsend.sendNEC(0x7D7D0EF1, 32);   // MOD Power
    irsend.sendNEC(0xFFFFFFFF, 32);   // MOD Power
}

void vol_up(byte flag, byte numOfValues)
{
  
    for (int i = 0; i < 5; i++) {
      irsend.sendNEC(0x7D7D6C93, 32); // volume up
      delay(45);
    }    
}

void vol_down(byte flag, byte numOfValues)
{
    for (int i = 0; i < 5; i++) {
      irsend.sendNEC(0x7D7DEC13, 32); // volume dowm
      delay(45);   
    }
}

void up(byte flag, byte numOfValues)
{
      irsend.sendNEC(M_Prog_up, 32); 
}

void down(byte flag, byte numOfValues)
{
      irsend.sendNEC(M_Prog_down, 32); 
}
void input_sel(byte flag, byte numOfValues)
{
   for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xA50, 12); 
      delay(45);
    }
}
void sel_enter(byte flag, byte numOfValues)
{
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xA70, 12); 
      delay(45);
    }
}
void sel_up(byte flag, byte numOfValues)
{
      for (int i = 0; i < 3; i++) {
      irsend.sendSony(Sel_up, 12); 
      delay(45);
    }
 }
void sel_down(byte flag, byte numOfValues)
{
      for (int i = 0; i < 3; i++) {
      irsend.sendSony(Sel_down, 12); 
      delay(45);
    }
}


void led1(byte flag, byte numOfValues)
{
        int buttonState_led1 = digitalRead(led_green);
        if (buttonState_led1== HIGH) {    
        digitalWrite(led_green, LOW);      
        }
        else {
        digitalWrite(led_green, HIGH); 
        }
}
void led2(byte flag, byte numOfValues)
{
       int buttonState_led2 = digitalRead(led_red);
        if (buttonState_led2== HIGH) {    
        digitalWrite(led_red, LOW);      
        }
        else {
        digitalWrite(led_red, HIGH); 
        }
}
void led3(byte flag, byte numOfValues)
{
        int buttonState_led3 = digitalRead(led_yellow);
        if (buttonState_led3== HIGH) {    
        digitalWrite(led_yellow, LOW);      
        }
        else {
        digitalWrite(led_yellow, HIGH); 
        }
}
void num1(byte flag, byte numOfValues)
{
      irsend.sendNEC(M_Num1, 32); 
}
void num2(byte flag, byte numOfValues)
{
irsend.sendNEC(M_Num2, 32);
}
void num3(byte flag, byte numOfValues)
{
irsend.sendNEC(M_Num3, 32);
}
void num4(byte flag, byte numOfValues){}
void num5(byte flag, byte numOfValues){}
void num6(byte flag, byte numOfValues){}
void num7(byte flag, byte numOfValues){}
void num8(byte flag, byte numOfValues){}
void num9(byte flag, byte numOfValues){}
void num0(byte flag, byte numOfValues){}

