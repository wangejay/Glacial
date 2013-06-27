
#include <IRremote.h>                    // 引用 IRRemote 函式庫
#include <MeetAndroid.h>
// declare MeetAndroid so that you can call functions with it
MeetAndroid meetAndroid;
const int buttonPin = 4;                 // 按鍵(pushbutton)接在 pin 4
int buttonState = 0;                     // 按鍵狀態

//LED
int led_green = 13;
int led_red   = 12;
int led_yellow = 11;
//Others


IRsend irsend;                           // 定義 IRsend 物件來發射紅外線訊號

// Sony IrDA Code
unsigned long Num1      =0x010;
unsigned long Num2      =0x810;
unsigned long Num3      =0x410;
unsigned long Num4      =0xC10;
unsigned long Num5      =0x210;
unsigned long Num6      =0xA10;
unsigned long Num7      =0x610;
unsigned long Num8      =0xE10;
unsigned long Num9      =0x110;
unsigned long Num0      =0x910;
unsigned long Red       =0x338;
unsigned long Green     =0xB38;
unsigned long Yelloy    =0x738;
unsigned long Blue      =0xF38;
unsigned long Up        =0x2F0;
unsigned long Down      =0xAF0;
unsigned long Left      =0x2D0;
unsigned long right     =0xCD0;
unsigned long Ok        =0xA70;
unsigned long Menu      =0x070;
unsigned long Vol_up    =0x490;
unsigned long Vol_down  =0xC90;
unsigned long Mute      =0x290;
unsigned long Prog_up   =0x090;
unsigned long Prog_down =0x890;
unsigned long Power     =0xA90;
unsigned long Input_sel =0xA50;
unsigned long Sel_enter =0xA70;
unsigned long Sel_up    =0x2F0;
unsigned long Sel_down  =0xAF0;
unsigned long Sel_right =0xCD0;
unsigned long Sel_left  =0x2D0;

// MOD IrDA Code
unsigned long M_Num1      =0x7D7D847B;
unsigned long M_Num2      =0x7D7D44BB;
unsigned long M_Num3      =0x7D7DC43B;
unsigned long M_Num4      =0xC10;
unsigned long M_Num5      =0x210;
unsigned long M_Num6      =0xA10;
unsigned long M_Num7      =0x610;
unsigned long M_Num8      =0xE10;
unsigned long M_Num9      =0x110;
unsigned long M_Num0      =0x910;
unsigned long M_Red       =0x338;
unsigned long M_Green     =0xB38;
unsigned long M_Yelloy    =0x738;
unsigned long M_Blue      =0xF38;
unsigned long M_Up        =0x2F0;
unsigned long M_Down      =0xAF0;
unsigned long M_Left      =0x2D0;
unsigned long M_right     =0xCD0;
unsigned long M_Ok        =0x7D7DFE01;
unsigned long M_Menu      =0x070;
unsigned long M_Vol_up    =0x7D7D6C93;
unsigned long M_Vol_down  =0x7D7DEC13;
unsigned long M_Mute      =0x290;
unsigned long M_Prog_up   =0x7D7DDE21;
unsigned long M_Prog_down =0x7D7D3EC1;
unsigned long M_Power     =0x7D7D0EF1;


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

