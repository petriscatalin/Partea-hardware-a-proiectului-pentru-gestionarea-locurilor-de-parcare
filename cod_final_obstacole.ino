

int parking1_slot1_ir_s = 7; 
int parking1_slot2_ir_s = 8;
int parking1_slot3_ir_s = 9;
 
int parking2_slot1_ir_s = 10;
int parking2_slot2_ir_s = 11;
int parking2_slot3_ir_s = 12;
 
String sensor1; 
String sensor2; 
String sensor3; 
String sensor4; 
String sensor5; 
String sensor6; 


String cdata =""; 

char array[]="Distanta1";
  //Afisare lcd

void setup()
{
  Serial.begin(9600); //Lungimea de banda


  pinMode(parking1_slot1_ir_s, INPUT);
  pinMode(parking1_slot2_ir_s, INPUT);
  pinMode(parking1_slot3_ir_s, INPUT);
   
  pinMode(parking2_slot1_ir_s, INPUT);
  pinMode(parking2_slot2_ir_s, INPUT);
  pinMode(parking2_slot3_ir_s, INPUT);
   
  

}
void loop()
{
  int distMin=0;

  p1slot1(); 
  p1slot2();
  p1slot3(); 
   
  p2slot1();
  p2slot2();
  p2slot3();


  cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 +","+ sensor4 + "," + sensor5 + "," + sensor6 +","; // comma will be used a delimeter
   Serial.println(cdata); 
   //nodemcu.println(cdata);
   delay(2000); // 2 seconds
    cdata = ""; 
    digitalWrite(parking1_slot1_ir_s, HIGH); 
    digitalWrite(parking1_slot2_ir_s, HIGH); 
    digitalWrite(parking1_slot3_ir_s, HIGH);
     
    digitalWrite(parking2_slot1_ir_s, HIGH);
    digitalWrite(parking2_slot2_ir_s, HIGH);
    digitalWrite(parking2_slot3_ir_s, HIGH); 

  delay(10); //citirea din 10 ms in 10 ms
}




void p1slot1() // parkng 1 slot1
{
  if( digitalRead(parking1_slot1_ir_s) == LOW) 
  {
  sensor1 = "p1s1on"; // parking1 slot1 
 delay(200); 
  } 
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
  sensor1 = "p1s1off";  
 delay(200);  
}
 
}
 
void p1slot2() // parking 1 slot2
{
  if( digitalRead(parking1_slot2_ir_s) == LOW) 
  {
  sensor2 = "p1s2on"; 
  delay(200); 
  }
if( digitalRead(parking1_slot2_ir_s) == HIGH)  
  {
  sensor2 = "p1s2off";  
 delay(200);
  } 
}
 
 
void p1slot3() // parking 1 slot3
{
  if( digitalRead(parking1_slot3_ir_s) == LOW) 
  {
  sensor3 = "p1s3on"; 
  delay(200); 
  }
if( digitalRead(parking1_slot3_ir_s) == HIGH)  
  {
  sensor3 = "p1s3off";  
 delay(200);
  } 
}
 
 
// now for parking 2
 
void p2slot1() // parking 1 slot3
{
  if( digitalRead(parking2_slot1_ir_s) == LOW) 
  {
  sensor4 = "p2s1on"; 
  delay(200); 
  }
if( digitalRead(parking2_slot1_ir_s) == HIGH)  
  {
  sensor4 = "p2s1off";  
 delay(200);
  } 
}
 
 
void p2slot2() // parking 1 slot3
{
  if( digitalRead(parking2_slot2_ir_s) == LOW) 
  {
  sensor5 = "p2s2on"; 
  delay(200); 
  }
if( digitalRead(parking2_slot2_ir_s) == HIGH)  
  {
  sensor5 = "p2s2off";  
 delay(200);
  } 
}
 
 
void p2slot3() // parking 1 slot3
{
  if( digitalRead(parking2_slot3_ir_s) == LOW) 
  {
  sensor6 = "p2s3on"; 
  delay(200); 
  }
if( digitalRead(parking2_slot3_ir_s) == HIGH)  
  {
  sensor6 = "p2s3off";  
 delay(200);
  } 
}
  
