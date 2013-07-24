// Readme 
// This is for Tech Kitchen only and wrote by Jackie Wang
// Email: wangejay@gmail.com 

//define pin number. 
int DD_allswitch_pin = 2;
int DD_dryerswitch_pin = 3; //PMW
int DD_cleanswitch_pin = 4;
int DD_lightswitch_pin = 5; //PMW
int pin06 = 6; //PMW
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

void setup()
{
    pinMode(DD_allswitch_pin, OUTPUT);     
    pinMode(DD_dryerswitch_pin, OUTPUT);
    pinMode(DD_cleanswitch_pin, OUTPUT);
    pinMode(DD_lightswitch_pin, OUTPUT);
    pinMode(pin06, OUTPUT);
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
    Serial.begin(9600);   
}

void loop() 
{

  delay(1000);
  datefromAndroid = 'wait'; 
      Serial.println(datefromAndroid);
      
  if (Serial.available()>0){
      datefromAndroid = Serial.read();
      Serial.println(datefromAndroid); 
      
      switch (datefromAndroid){
      case 'A':
          DishDryer_allswitch();
          break; 
      case 'B':
          DishDryer_dryerswitch();
          break;
      case 'C':
          DishDryer_cleanswitch();
          break;
      case 'D':
          DishDryer_lightswitch();
          break; 
      case 'E':
          break; 
      case 'F':
          break; 
      case 'G':
          break; 
      case 'H':
          RangeHood_allswitch();
          break; 
      case 'I':
          RangeHood_fanswitch();
          break;
      case 'J':
          RangeHood_lightswitch();
          break; 
      }
  }
}



//Range hood

void RangeHood_allswitch()
{
   if ( digitalRead(RH_allswitch_pin) == HIGH){
       digitalWrite(RH_allswitch_pin, LOW);      
   }
   else {
       digitalWrite(RH_allswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void RangeHood_fanswitch()
{
   if ( digitalRead(RH_fanswitch_pin) == HIGH){
       digitalWrite(RH_fanswitch_pin, LOW);      
   }
   else {
       digitalWrite(RH_fanswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void RangeHood_lightswitch()
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

void DishDryer_allswitch()
{
   if ( digitalRead(DD_allswitch_pin) == HIGH){
       digitalWrite(DD_allswitch_pin, LOW);      
   }
   else {
       digitalWrite(DD_allswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void DishDryer_dryerswitch()
{
   if ( digitalRead(DD_dryerswitch_pin) == HIGH){
       digitalWrite(DD_dryerswitch_pin, LOW);      
   }
   else {
       digitalWrite(DD_dryerswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void DishDryer_cleanswitch()
{
   if ( digitalRead(DD_cleanswitch_pin) == HIGH){
       digitalWrite(DD_cleanswitch_pin, LOW);      
   }
   else {
       digitalWrite(DD_cleanswitch_pin, HIGH); 
   }
   delay(deleytime);
}

void DishDryer_lightswitch()
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



