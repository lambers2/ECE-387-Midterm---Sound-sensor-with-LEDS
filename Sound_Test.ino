/* sound sensor test project
 */
int analog_sensor  = A0; // select the input pin for the potentiometer
int digit_sensor = 12; // select the input pin for the potentiometer
int ledPin = 3; // select the pin for the LED
int analogValue ; // value from the analog input pin
int digitValue ;  //  value from the digit input pin
void setup () {
pinMode (ledPin, OUTPUT);
pinMode (digit_sensor, INPUT);
Serial.begin (9600);
}
void loop () {
analogValue = analogRead (analog_sensor);
digitValue=digitalRead(digit_sensor);
Serial.println (analogValue, DEC);
if (digitValue==HIGH){
  digitalWrite (ledPin, HIGH);
  
}
  //digitalWrite (ledPin, HIGH);
 else{
  digitalWrite (ledPin, LOW);
  
 }
 

}
