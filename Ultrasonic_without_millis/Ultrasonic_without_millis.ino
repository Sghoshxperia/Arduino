double t,k,d;
int h;
double distance;


void setup() {
  pinMode(10,OUTPUT);
  pinMode (11,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(10,HIGH);
  delayMicroseconds(10);
  digitalWrite(10,LOW);
  while(1)
  {
  
  }
  {;}
  
    
    while(1)
    {
      if(digitalRead(11)=LOW)
      {K=micros();
      break;}
      
    }
  
  k=micros();
    t=k-d;
    distance=340*t/20000.0;
    Serial.print("distance");
    Serial.print(distance);
    Serial.print("\n");
    delay(10);
  }
  
  // put your main code here, to run repeatedly:
