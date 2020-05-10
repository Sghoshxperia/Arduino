int echoL=11;
int echoR=7;
int trigL=12;
int trigR=6;
int Li1=10;
int Li2=9;
int Ri1=8;
int Ri2=5;
double dL;
double dR;
double tR;
//double diff=0.0;
double tL;
/*double a=0.0;
double b=0.0;
double c=0.0;
double d=0.0;*/

void setup() {
  // put your setup code here, to run once:
pinMode(echoL,INPUT);
pinMode(echoR,INPUT);
pinMode(trigL,OUTPUT);
pinMode(trigR,OUTPUT);
pinMode(Li1,OUTPUT);
pinMode(Li2,OUTPUT);
pinMode(Ri1,OUTPUT);
pinMode(Ri2,OUTPUT);
Serial.begin(9600);

}

void loop() {
  //delay(100);
  // put your main code here, to run repeatedly:
   // digitalWrite(ledR,LOW);

digitalWrite(trigL,LOW);
  delayMicroseconds(2);
  digitalWrite(trigL,HIGH); //digitalWrite(trigR,HIGH);
delayMicroseconds(10);
digitalWrite(trigL,LOW); //digitalWrite(trigR,LOW);
  tL=pulseIn(echoL,HIGH);
  dL=tL*0.017;



  digitalWrite(trigR,LOW);
  delayMicroseconds(2);
digitalWrite(trigR,HIGH);
delayMicroseconds(10);
digitalWrite(trigR,LOW);
  tR=pulseIn(echoR,HIGH);
  dR=tR*0.017;



/*while(digitalRead(echoL!=HIGH)){;}
a=micros();
while(digitalRead(echoL!=LOW)){;}
b=micros();
tL=b-a;*/

/*while(digitalRead(echoR!=HIGH)){;}
c=micros();
while(digitalRead(echoR!=LOW)){;}
d=micros();
tR=d-c;*/

//diff=dL-dR;
//Serial.println(abs(diff));


//if((dL<40.0)||(dR<40.0))
//{
if(dL>25&&dR>25)
{
  digitalWrite(Li1,LOW);//forward
  digitalWrite(Li2,HIGH);
  digitalWrite(Ri1,LOW);
  digitalWrite(Ri2,HIGH);
  
}

 if(dL>25&&dR<25)
{
  digitalWrite(Li1,LOW);//right
  digitalWrite(Li2,HIGH);
  digitalWrite(Ri1,HIGH);
  digitalWrite(Ri2,LOW);

}
  if(dL<25&&dR>25)
  {
   digitalWrite(Li1,HIGH);//left
  digitalWrite(Li2,LOW);
  digitalWrite(Ri1,LOW);
  digitalWrite(Ri2,HIGH);
 
  }

  if(dL<25&&dR<25)
  {
    digitalWrite(Li1,HIGH);//backwards
  digitalWrite(Li2,LOW);
  digitalWrite(Ri1,HIGH);
  digitalWrite(Ri2,LOW);

  delay(1000);
  
  digitalWrite(Li1,LOW);//right again
  digitalWrite(Li2,HIGH);
  digitalWrite(Ri1,HIGH);
  digitalWrite(Ri2,LOW);

  delay(1000);
  }
  
  

  
  //}
Serial.print("Left:");
Serial.println(dL);
Serial.print("Right:");
Serial.println(dR);
delay(10);
}
