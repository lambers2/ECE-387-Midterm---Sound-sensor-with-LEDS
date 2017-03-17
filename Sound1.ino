#define rpin 5
#define gpin 6
#define bpin 3
#define DIGITSENSOR 13

int sensorValue = 0;         
int sensorMin = 1023;        
int sensorMax = 0; 

void setup(){
  Serial.begin(9600); //For debugging
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode (DIGITSENSOR, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600); //For debugging
  
while (millis() < 1000) {
   sensorValue = analogRead(A0);

   // record the maximum sensor value
   if (sensorValue > sensorMax) {
     sensorMax = sensorValue;
   }
   // record the minimum sensor value
   if (sensorValue < sensorMin) {
     sensorMin = sensorValue;
   }
 }
 Serial.print(sensorMax);
 Serial.print(" ");
 Serial.println(sensorMin);
}

void loop(){
  sensorValue = analogRead(A0);
  boolean soundstate = digitalRead(DIGITSENSOR);
  analogWrite(rpin,0);
  analogWrite(bpin,0);
  analogWrite(gpin,0);
  Serial.print("Analog: ");
  Serial.print(sensorValue);
  Serial.print("                Digital:" );
  Serial.print(soundstate);
  Serial.print("\n");
    
  

//boolean soundstate = digitalRead(DIGITSENSOR);
  
if ((sensorValue) > 500 && (sensorValue) < 525){
    analogWrite(rpin, 225);
    analogWrite(bpin,105);
    analogWrite(bpin,175);
    delay(110);
  }
  else if ((sensorValue) > 525 && (sensorValue ) < 550){
    analogWrite(bpin,255);
    delay(110);
  }
  else if ((sensorValue ) > 550 && (sensorValue ) < 575){
    analogWrite(gpin,255);
    delay(110);
  }
  else if ((sensorValue) > 575  && (sensorValue ) < 600){
   analogWrite(gpin,150);
    delay(110);
  }
  else if ((sensorValue) > 625 && (sensorValue) < 650){
    analogWrite(bpin,200);
    delay(110);
  } 
  else if ((sensorValue) > 650 && (sensorValue) < 675){
    analogWrite(rpin, 200);
    delay(110);
 } else if (soundstate == false ||(sensorValue) > 675){
    analogWrite(rpin,0);
   analogWrite(bpin,0);
   analogWrite(gpin,0);
  // analogWrite(bpin,255);
   delay(110);
  } else if (soundstate == false ||(sensorValue) < 500){
   analogWrite(rpin,0);
   analogWrite(bpin,0);
   analogWrite(gpin,0);
   delay(110);
  }
 

}
void setColor(int red, int gre, int blu){
  digitalWrite(rpin, red);
  digitalWrite(gpin, gre);
  digitalWrite(bpin, blu);
}
