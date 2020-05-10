int Echo=11;
int Trigger=10;
double t=0.0;
double distance=0.0;

void setup() {
  // put your setup code here, to run once:
pinMode(Echo,INPUT);
pinMode(Trigger,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(Trigger,LOW);
//delayMicroseconds(2);
digitalWrite(Trigger,HIGH);
delayMicroseconds(10);
digitalWrite(Trigger,LOW);

t=pulseIn(Echo,HIGH);

distance=340*t/20000.0;

Serial.print("dist=");
Serial.print(distance);
Serial.println();
 delay(10);





}
