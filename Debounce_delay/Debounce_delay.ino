int last;
int led=13;
int button=5;
int time=0;
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(button,INPUT);
Serial.begin(9600);
}
int debounce(int lastx)
{
// int a; 
  int current= digitalRead(button);
  if(lastx==current)
  {
  return lastx;
  
  }
  else
  //a=millis();
 // while(millis()<=(a+10))
 {delay(10);
    current=digitalRead(button);}
    
  return current;
 }
void loop() {
 
int n;
last=digitalRead(5);
n=debounce(last);
Serial.println(n);
digitalWrite(led,n);
}
