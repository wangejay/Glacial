// Readme 
// This is for Tech Kitchen only and wrote by Jackie Wang
// Email: wangejay@gmail.com 

// include libs
#include <MeetAndroid.h>
#include <IRremote.h>     

MeetAndroid meetAndroid;
IRsend irsend;   

//define the path 0: Bluetooth 1: Serial port. 
int Path = 1;
int Debug = 1; 

//define pin number. 
int DD_allswitch_pin = 2;
int IRsend_pin = 3; //PMW
int DD_cleanswitch_pin = 4;
int DD_lightswitch_pin = 5; //PMW
int DD_dryerswitch_pin = 6; //PMW
int pin07 = 7;
int RH_allswitch_pin = 8;  
int RH_fanswitch_pin = 9;  
int RH_lightswitch_pin = 10; //PMW
int pin11 = 11; //PMW
int pin12 = 12; 
int pin13 = 13; 


//define all parameters 
int deleytime = 100; //deley for 100ms  
char datefromAndroid; 

//define MOD IrDA Code
unsigned long MOD_Num1      =0x7D7D847B;
unsigned long MOD_Num2      =0x7D7D44BB;
unsigned long MOD_Num3      =0x7D7DC43B;
unsigned long MOD_Num4      =0xC10;
unsigned long MOD_Num5      =0x210;
unsigned long MOD_Num6      =0xA10;
unsigned long MOD_Num7      =0x610;
unsigned long MOD_Num8      =0xE10;
unsigned long MOD_Num9      =0x110;
unsigned long MOD_Num0      =0x910;
unsigned long MOD_Red       =0x338;
unsigned long MOD_Green     =0xB38;
unsigned long MOD_Yelloy    =0x738;
unsigned long MOD_Blue      =0xF38;
unsigned long MOD_Up        =0x2F0;
unsigned long MOD_Down      =0xAF0;
unsigned long MOD_Left      =0x2D0;
unsigned long MOD_right     =0xCD0;
unsigned long MOD_Ok        =0x7D7DFE01;
unsigned long MOD_Menu      =0x070;
unsigned long MOD_Vol_up    =0x7D7D6C93;
unsigned long MOD_Vol_down  =0x7D7DEC13;
unsigned long MOD_Mute      =0x290;
unsigned long MOD_Prog_up   =0x7D7DDE21;
unsigned long MOD_Prog_down =0x7D7D3EC1;
unsigned long MOD_Power     =0x7D7D0EF1;

void setup()
{
    pinMode(DD_allswitch_pin, OUTPUT);     
    pinMode(DD_dryerswitch_pin, OUTPUT);
    pinMode(DD_cleanswitch_pin, OUTPUT);
    pinMode(DD_lightswitch_pin, OUTPUT);
    pinMode(DD_dryerswitch_pin, OUTPUT);
    pinMode(pin07, OUTPUT);
    pinMode(RH_allswitch_pin, OUTPUT);     
    pinMode(RH_fanswitch_pin, OUTPUT);
    pinMode(RH_lightswitch_pin, OUTPUT);
    pinMode(pin11, OUTPUT);
    pinMode(pin12, OUTPUT);
    pinMode(pin13, OUTPUT);
  
    digitalWrite(RH_allswitch_pin, HIGH);    
    digitalWrite(RH_fanswitch_pin, HIGH);    
    digitalWrite(RH_lightswitch_pin, HIGH);    
    digitalWrite(pin11, HIGH);    
    digitalWrite(pin12, HIGH);     
    
   // DishDryer callback functions
    meetAndroid.registerFunction(DishDryer_allswitch, 'A');  
    meetAndroid.registerFunction(DishDryer_dryerswitch, 'B');
    meetAndroid.registerFunction(DishDryer_cleanswitch, 'C');
    meetAndroid.registerFunction(DishDryer_lightswitch, 'D');  
    
    //Range hood callback functions
    meetAndroid.registerFunction(RangeHood_allswitch, 'H'); 
    meetAndroid.registerFunction(RangeHood_fanswitch, 'I');  
    meetAndroid.registerFunction(RangeHood_lightswitch, 'J'); 

    //MOD callback functnions
    meetAndroid.registerFunction(power, 'P');   
    meetAndroid.registerFunction(vol_up, 'Q');   
    meetAndroid.registerFunction(vol_down, 'R');   
    meetAndroid.registerFunction(prog_up, 'S');   
    meetAndroid.registerFunction(prog_down, 'T');   
    meetAndroid.registerFunction(num1, '1');   
    meetAndroid.registerFunction(num2, '2');   
    meetAndroid.registerFunction(num3, '3');   
    
    Serial.begin(9600);   
}

void loop() 
{ 
  if (Path == 0) 
  { 
      datefromAndroid = meetAndroid.receive(); // you need to keep this in your loop() to receive events
      if (Debug == 1)
      {
         Serial.println("Arduino get the char:" );
         Serial.println(datefromAndroid);
      }   
      delay(100);
  }
  
  else 
  {    
  if (Serial.available()>0){
      datefromAndroid = Serial.read();
      Serial.println(datefromAndroid); 
      
      switch (datefromAndroid){
      case '1':
          break; 
      case '2':
          break; 
      case '3':
          break; 
      case '4':
          break; 
      case '5':
          break; 
      case '6':
          break; 
      case '7':
          break; 
      case '8':
          break; 
      case '9':
          break; 
      case '0':
          break; 
      
      case 'A':
          DishDryer_allswitch(0,0);
          break; 
      case 'B':
          DishDryer_dryerswitch(0,0);
          break;
      case 'C':
          DishDryer_cleanswitch(0,0);
          break;
      case 'D':
          DishDryer_lightswitch(0,0);
          break; 
      case 'E':
          break; 
      case 'F':
          break; 
      case 'G':
          break; 
      case 'H':
          RangeHood_allswitch(0,0);
          break; 
      case 'I':
          RangeHood_fanswitch(0,0);
          break;
      case 'J':
          RangeHood_lightswitch(0,0);
          break;
      case 'K':
          break; 
      case 'L':
          break; 
      case 'M':
          break; 
      case 'N':
          break; 
      case 'O':
          break; 
      case 'P':
          power(0,0); 
          break; 
      case 'Q':
          prog_up(0,0);
          break; 
      case 'R':
          prog_down(0,0);
          break; 
      case 'S':
          vol_up(0,0);
          break; 
      case 'T':
          vol_down(0,0);
          break; 
      }
  }
  }
}

//Range hood

void RangeHood_allswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(RH_allswitch_pin) == HIGH){
       digitalWrite(RH_allswitch_pin, LOW);      
   }
   else {
       digitalWrite(RH_allswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void RangeHood_fanswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(RH_fanswitch_pin) == HIGH){
       digitalWrite(RH_fanswitch_pin, LOW);      
   }
   else {
       digitalWrite(RH_fanswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void RangeHood_lightswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(RH_lightswitch_pin) == HIGH){
       digitalWrite(RH_lightswitch_pin, LOW);      
   }
   else {
       digitalWrite(RH_lightswitch_pin, HIGH); 
   }
   delay(deleytime);
}

//Dish Dryer

void DishDryer_allswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(DD_allswitch_pin) == HIGH){
       digitalWrite(DD_allswitch_pin, LOW);      
   }
   else {
       digitalWrite(DD_allswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void DishDryer_dryerswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(DD_dryerswitch_pin) == HIGH){
       digitalWrite(DD_dryerswitch_pin, LOW);      
   }
   else {
       digitalWrite(DD_dryerswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void DishDryer_cleanswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(DD_cleanswitch_pin) == HIGH){
       digitalWrite(DD_cleanswitch_pin, LOW);      
   }
   else {
       digitalWrite(DD_cleanswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void DishDryer_lightswitch(byte flag, byte numOfValues)
{
   if ( digitalRead(DD_lightswitch_pin) == HIGH){
       digitalWrite(DD_lightswitch_pin, LOW);      
   }
   else {
       digitalWrite(RH_lightswitch_pin, HIGH); 
   }
   delay(deleytime);
}

// IR remote, implement it next time 

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

void prog_up(byte flag, byte numOfValues)
{
      irsend.sendNEC(MOD_Prog_up, 32); 
}

void prog_down(byte flag, byte numOfValues)
{
      irsend.sendNEC(MOD_Prog_down, 32); 
}


void num1(byte flag, byte numOfValues)
{
      irsend.sendNEC(MOD_Num1, 32); 
}
void num2(byte flag, byte numOfValues)
{
irsend.sendNEC(MOD_Num2, 32);
}
void num3(byte flag, byte numOfValues)
{
irsend.sendNEC(MOD_Num3, 32);
}
void num4(byte flag, byte numOfValues){}
void num5(byte flag, byte numOfValues){}
void num6(byte flag, byte numOfValues){}
void num7(byte flag, byte numOfValues){}
void num8(byte flag, byte numOfValues){}
void num9(byte flag, byte numOfValues){}
void num0(byte flag, byte numOfValues){}




