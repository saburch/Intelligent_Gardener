#include <Servo.h>

int motor_v1 = 12;
int motor_v2 = 13;
int motor_z1 = 10;
int motor_z2 = 11;
int servo = 5;
int pumpe = 9;
int feucht = A0;
int feuchte;
int T1 = 4;
int T2 = 3;
int M1;
int M2;
Servo myservo;


void setup()
{
  
  pinMode(motor_v1, OUTPUT);
  pinMode(motor_v2, OUTPUT);
  pinMode(motor_z1, OUTPUT);
  pinMode(motor_z2, OUTPUT);
  pinMode(servo,   OUTPUT);
  pinMode(pumpe,   OUTPUT);
  pinMode(feucht,  INPUT);
  pinMode(T1,      INPUT);
  pinMode(T2,      INPUT);
  
  digitalWrite(motor_v1, HIGH);
  digitalWrite(motor_v2, HIGH);
  digitalWrite(motor_z1, HIGH);
  digitalWrite(motor_z2, HIGH);
  digitalWrite(pumpe, HIGH);
  
  
  
  Serial.begin(9600);
  
  myservo.attach(5);      //pin belegen
  
  myservo.write(65);
}




void loop()
{
  
  
  
//Fährt in Ausgangsstellung
   M1 = digitalRead(T1);

    while (M1 == 0)
    {
      digitalWrite(motor_z1, LOW);
      digitalWrite(motor_z2, LOW);
      M1 = digitalRead(T1);
      delay(10);
    }
  
    digitalWrite(motor_z1, HIGH);
    digitalWrite(motor_z2, HIGH);
   

//Fährt zu Pflanze 1  
    
    for(int i = 0; i < 250; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M2 == 0)
      {
      digitalWrite (motor_v1, LOW);
      digitalWrite (motor_v2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_v1, HIGH);
      digitalWrite (motor_v2, HIGH);
    
  

for(int i = 0; i < 5; i++)
{
//Fährt zu Pflanze #X

//Feuchtigkeit messen {- Servo runter, - Messen, - Servo hoch}

  
  for(int pos = 80; pos < 170; pos++)   
  {                                  
    myservo.write(pos);               
    delay(7);                       
  } 
  delay(2000);
  feuchte = analogRead(feucht); 
  delay(500);
  for(int pos = 170; pos > 80; pos--)  
  {                                  
    myservo.write(pos);              
    delay(7);                     
  } 

  if (feuchte < 400)  //------------------------------------------------------------------------------------
  {
     for(int i = 0; i < 125; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M2 == 0)
      {
      digitalWrite (motor_z1, LOW);
      digitalWrite (motor_z2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_z1, HIGH);
      digitalWrite (motor_z2, HIGH);
    
    digitalWrite (pumpe, LOW);
    delay(1500);

    for(int i = 0; i < 100; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M2 == 0)
      {
      digitalWrite (motor_z1, LOW);
      digitalWrite (motor_z2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_z1, HIGH);
      digitalWrite (motor_z2, HIGH);
    
    
   
  
   for(int i = 0; i < 200; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M1 == 0 && M2 == 0)
      {
      digitalWrite (motor_v1, LOW);
      digitalWrite (motor_v2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_v1, HIGH);
      digitalWrite (motor_v2, HIGH);
    
    
    
    
    
    
    for(int i = 0; i < 100; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M2 == 0)
      {
      digitalWrite (motor_z1, LOW);
      digitalWrite (motor_z2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_z1, HIGH);
      digitalWrite (motor_z2, HIGH);
      
      digitalWrite (pumpe, HIGH);
      
      for(int i = 0; i < 125; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M2 == 0)
      {
      digitalWrite (motor_v1, LOW);
      digitalWrite (motor_v2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_v1, HIGH);
      digitalWrite (motor_v2, HIGH);
 
      
      delay(1000);
      
  }
     
      
   for(int i = 0; i < 200; i++)
    {
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      if(M2 == 0)
      {
      digitalWrite (motor_v1, LOW);
      digitalWrite (motor_v2, LOW);
      delay(10);
      }
    }
      digitalWrite (motor_v1, HIGH);
      digitalWrite (motor_v2, HIGH);
      
      M1 = digitalRead(T1);
      M2 = digitalRead(T2);
      
      
      
            
    if(M2 == 1)
  {
  goto fertig;
  }  
  
}
  fertig:
  //Fährt in Ausgangsstellung
   M1 = digitalRead(T1);

    while (M1 == 0)
    {
      digitalWrite(motor_z1, LOW);
      digitalWrite(motor_z2, LOW);
      M1 = digitalRead(T1);
      delay(10);
    }
  
    digitalWrite(motor_z1, HIGH);
    digitalWrite(motor_z2, HIGH);
    
    digitalWrite(motor_v1, LOW);
    digitalWrite(motor_v2, LOW);
    delay(200);
    digitalWrite(motor_v1, HIGH);
    digitalWrite(motor_v2, HIGH);
  
 delay(1800000);                 //Halbe Stunde
 
 }













