#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define ECHOPIN1 2        //Pin pentru semnalul echo - senzor1
#define TRIGPIN1 3        //Pin pentru semnalul trigger - senzor1 

#define ECHOPIN2 4        //Pin pentru semnalul echo - senzor2
#define TRIGPIN2 5        //Pin pentru semnalul trigger - senzor2

#define Buzzer 6          //Pin pentru buzzer 


int  led1=A0; //led verde
int led2=A1; //led rosu

int sonerCheak = 1, sc, count = 0, sonerCheak1 = 1, sc1;


void setup()
{

  
  pinMode(led1,OUTPUT); //define outputs of leds
  pinMode(led2, OUTPUT);
  
  Serial.begin(9600); //Lungimea de banda
  
  //Se seteaza pini ca input - sezori
  pinMode(ECHOPIN1, INPUT);
  pinMode(ECHOPIN2, INPUT);

  //Se seteaza pinii ca output - senzori
  pinMode(TRIGPIN1, OUTPUT);
  pinMode(TRIGPIN2, OUTPUT);

  //Se seteaza piniul pentru buuzer ca output
  pinMode(Buzzer,OUTPUT);

}

float read(int TRIGPIN,int ECHOPIN)
{
  float distance=0;
  
  //Incepere masurare
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);      //Este nevoie doar de 10 ms pentru ca senzorul sa inceapa sa detecteze
  digitalWrite(TRIGPIN, LOW);
  
  //Se calculeaza distanta
  distance = pulseIn(ECHOPIN, HIGH); /* Reads a pulse (either HIGH or LOW) on a pin.Returns the length of the pulse in microseconds or 0 if no complete pulse was received*/
  distance= distance/58;  //Formula: uS / 58 = centimetri(58 - valoarea vitezei sunetului)
  
  return distance;
}
 

void loop()
{
  int distMin=0;

   digitalWrite(led2,HIGH); //aprind becul rosu


  //Se citeste prima distanta
  float distance1 =read(TRIGPIN1,ECHOPIN1);
  //Se citeste a doua distanta
  float distance2 =read(TRIGPIN2,ECHOPIN2);
  
  //Se calculeaza distanta minima dintre cele 2 citite de cei 2 senzori
  if(distance1 < distance2)
    distMin= distance1;
  else distMin = distance2;


    if (distance1 < 10) {  //verific daca senzor1 primeste semnal
    sc = 1;
  } else {
    sc = 0;
  }

  if (distance2 < 10) { //verific daca senzor2 primeste semnal
    sc1 = 1;
  } else {
    sc1  = 0;
  }

   if (sonerCheak == sc) { //daca senzor1 e activat
  digitalWrite(led2,LOW); //rosu se stinge,verde se aprinde/stinge,rosu revine
  delay(500);
  digitalWrite(led1,HIGH);
  delay(4000);
  digitalWrite(led1,LOW);
  delay(2000);
  digitalWrite(led2,HIGH);
   }


 if (sonerCheak1 == sc1) { //daca senzor2 e activat
    //rosu se stinge,verde se aprinde/stinge,rosu revine
  

  digitalWrite(led2,LOW);
  delay(500);
  digitalWrite(led1,HIGH);
  delay(4000);
  digitalWrite(led1,LOW);
  delay(2000);
  digitalWrite(led2,HIGH);
 }
   
  //Comparare distanta minima de la cei 2 senzori pentru buzzer
  if(distMin < 100)
  {
      if(distMin > 70)  // 70 < Distanta minima < 100
      {
         tone(Buzzer,300); //Mentinere frecventa de 300, timp de 200 ms
         delay(1500);
         noTone(Buzzer);   //Fara sunet timp de 1500 ms
         delay(1500);
      }
      
      else if(distMin <= 70 && distMin >= 25)  //25 <= Distanta minima <= 70
      {
         tone(Buzzer,500); //Mentinere frecventa de 500, timp de 200 ms
         delay(1600);
         noTone(Buzzer);  //Fara sunet timp de 600 ms
         delay(600);
      }
      
      else if(distMin < 25 && distMin > 10) //10 < Distanta minima < 25
      {
         tone(Buzzer,900); //Mentinere frecventa de 900, timp de 200 ms
         delay(600);
         noTone(Buzzer);  //Fara sunet timp de 300 ms
         delay(300);
      }
      
      else if(distMin <= 10) //0 < Distanta minima <= 10
      {
         tone(Buzzer,1000); //Mentinere frecventa de 1000, timp de 200 ms
         delay(600);
      }
  }
  
  delay(10); //citirea din 10 ms in 10 ms
}
