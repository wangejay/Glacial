#include <MeetAndroid.h>
MeetAndroid meetAndroid;

const int buttonPin = 4;                 // 按鍵(pushbutton)接在 pin 4
int buttonState = 0;                     // 按鍵狀態

//define pin number. 
int pin08 = 8;
int pin09 = 9;
int pin10 = 10;
int pin11 = 11; 
int pin12 = 12; 

void setup()
{
  pinMode(pin08, OUTPUT);     
  pinMode(pin09, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  digitalWrite(pin08, HIGH);    
  digitalWrite(pin09, HIGH);    
  digitalWrite(pin10, HIGH);    
  digitalWrite(pin11, HIGH);    
  digitalWrite(pin12, HIGH);    
  
  Serial.begin(9600); 

  // register callback functions, which will be called when an associated event occurs.
  meetAndroid.registerFunction(pin08_action, 'A');  
  meetAndroid.registerFunction(pin09_action, 'B');
  meetAndroid.registerFunction(pin10_action, 'C');
  meetAndroid.registerFunction(pin11_action, 'D');
  meetAndroid.registerFunction(pin12_action, 'E');
}

void loop() 
{
  meetAndroid.receive(); // you need to keep this in your loop() to receive events
  delay(100);
}

void pin08_action(byte flag, byte numOfValues)
{
   digitalWrite(pin08, LOW);      
   delay(100);
   digitalWrite(pin08, HIGH);      
}

void pin09_action(byte flag, byte numOfValues)
{
   digitalWrite(pin09, LOW);      
   delay(100);
   digitalWrite(pin09, HIGH);      
}

void pin10_action(byte flag, byte numOfValues)
{
   digitalWrite(pin10, LOW);      
   delay(100);
   digitalWrite(pin10, HIGH);  
}

void pin11_action(byte flag, byte numOfValues)
{
   digitalWrite(pin11, LOW);      
   delay(100);
   digitalWrite(pin11, HIGH);  
}
void pin12_action(byte flag, byte numOfValues)
{
   digitalWrite(pin12, LOW);      
   delay(100);
   digitalWrite(pin12, HIGH);  
}



