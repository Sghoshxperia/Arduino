const int SW_pin = 8; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int LeftB = 11;
int LeftF = 10;
int RightF = 6;
int RightB = 5;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  pinMode(X_pin, OUTPUT);
  pinMode(Y_pin, OUTPUT);
  pinMode(LeftB, OUTPUT);          
  pinMode(LeftF, OUTPUT);
  pinMode(RightF, OUTPUT);
  pinMode(RightB, OUTPUT);
  Serial.begin(9600);
}



void loop() 
{
  
  /*Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_pin));
  Serial.println(" | ");
  delay(200);*/

  int Y_val = analogRead(X_pin);
  int X_val = analogRead(Y_pin);
  
   X_val = map(X_val, 0, 1023, -255, 255);
   Y_val = map(Y_val, 0, 1023, -255, 255); 

 /*  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | ");
  Serial.print("X-axis: ");
  Serial.print((X_val));
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  Serial.print((Y_val));
  Serial.println(" | ");
  delay(200);*/
 
  //Serial.print(Y_val);
  //Serial.print(" ");
  //Serial.println(X_val);

   //Serial.print(X_val);
   //Serial.print(" ");
   //Serial.println(Y_val);

  //X_val = X_val - 5;
  //Y_val = Y_val - 5;

  double theta=0.00;

  theta = atan2(Y_val, X_val);

  int remap = 0;

   remap = abs(abs(X_val)-abs(Y_val));

 // Serial.println(remap);


    // analogWrite(LeftB,0);
     //analogWrite(LeftF,0);
     //analogWrite(RightF,0); 
     //analogWrite(RightB,0);
     

if(abs(X_val)<=10&&abs(Y_val)<=10)
  {
  analogWrite(LeftB,0);
  analogWrite(LeftF,0);
  analogWrite(RightF,0); 
  analogWrite(RightB,0);

  X_val = 0;
  Y_val = 0;
  
  }
   

 if(theta>=0&&theta<=0.79)     //Quadrant 1
  {
    //Y_val-=255;
     analogWrite(LeftB,0);
     analogWrite(LeftF,X_val);
     analogWrite(RightF,0); 
     analogWrite(RightB,remap);

     Serial.print("Left FWD: ");
     Serial.print(X_val);
     Serial.print(" ");
      Serial.print("Right back ");
     Serial.println(remap);
   
  }


 if(theta>0.79&&theta<=1.57)     //Quadrant 2
  {
    //X_val-=255;
     analogWrite(LeftB,0);
     analogWrite(LeftF,Y_val);
     analogWrite(RightF,remap); 
     analogWrite(RightB,0);


     Serial.print("Left FWD ");
     Serial.print(Y_val);
     Serial.print(" ");
     Serial.print("Right FWD ");
     Serial.println(remap);
     
      
  }

   if(theta>1.57&&theta<=2.36)     //Quadrant 3
  {
    //X_val+=255;
     analogWrite(LeftB,0);
     analogWrite(LeftF,remap);
     analogWrite(RightF,Y_val); 
     analogWrite(RightB,0);

     Serial.print("Left FWD ");
    Serial.print(remap);
    Serial.print(" ");
     Serial.print("Right FWD ");
    Serial.println(Y_val);
  }

   if(theta>2.36&&theta<=3.14)     //Quadrant 4
  {
    //Y_val-=255;
     analogWrite(LeftB,remap);
     analogWrite(LeftF,0);
     analogWrite(RightF,abs(X_val)); 
     analogWrite(RightB,0);

       Serial.print("Left BCK ");
     Serial.println(remap);
     Serial.print(" ");
      Serial.print("Right FWD  ");
     Serial.print(abs(X_val));
     
     
   
  }

   if(theta>-3.14&&theta<-2.36)     //Quadrant 5
  {
    //Y_val+=255;
     analogWrite(LeftB,abs(X_val));
     analogWrite(LeftF,0);
     analogWrite(RightF,remap); 
     analogWrite(RightB,0);

      
      
      Serial.print("Left BCK ");
     Serial.println(abs(X_val));
      Serial.print(" ");
      Serial.print("Right FWD ");
     Serial.print(remap);
    
      
   
  }

   if(theta>=-2.36&&theta<-1.57)     //Quadrant 6
  {
    //X_val+=255;
     analogWrite(LeftB,abs(Y_val));
     analogWrite(LeftF,0);
     analogWrite(RightF,0); 
     analogWrite(RightB,remap);

      
      
      Serial.print("Left BCK ");
     Serial.println(abs(Y_val));
     Serial.print(" ");
      Serial.print("Right BCK ");
     Serial.print(remap);
     
      
   
  }

   if(theta>=-1.57&&theta<=-0.79)     //Quadrant 7
  {
    //X_val-=255;
     analogWrite(LeftB,remap);
     analogWrite(LeftF,0);
     analogWrite(RightF,0); 
     analogWrite(RightB,abs(Y_val));

      Serial.print("Left BCK ");
     Serial.print(remap);
     Serial.print(" ");
      Serial.print("Right BCK ");
     Serial.println(abs(Y_val));
   
  }

   if(theta>=-0.79&&theta<0)     //Quadrant 8
  {
    //Y_val+=255;
     analogWrite(LeftB,0);
     analogWrite(LeftF,remap);
     analogWrite(RightF,0); 
     analogWrite(RightB,X_val);

      Serial.print("Left FWD ");
     Serial.println(remap);
     Serial.print("Right BCK ");
     Serial.print(X_val);
     Serial.print(" ");
     
   
  } 

  
//Serial.println(theta);



  //delay(500);

  //switching of quadrants

}
