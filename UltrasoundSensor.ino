const int pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int red = 13;
int yellow = 12;
int green = 11;
int spPin = 3;

void setup() {
   Serial.begin(9600);// Starting Serial Terminal
   pinMode(red,OUTPUT);
   pinMode(yellow,OUTPUT);
   pinMode(green,OUTPUT);
   

}
//Add more comments..
void loop() {
   long duration, inches, distance; // special data type for long decimals, useful for time data
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   
   //converts microsecconds to centimeters
   
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);// mesures the pulse given from Ultrasonic sensor
 
   distance = microsecondsToCentimeters(duration);
  // values print in serial monitor
   Serial.print(distance);
   Serial.print("cm");
   Serial.println();
   delay(100);

// code to turn on lights
   if(distance < 6){
     digitalWrite(red,HIGH);
     delay(100);
     digitalWrite(red,LOW);
     tone(spPin,5000);
    }else if(distance > 6 && distance < 20){
       digitalWrite(yellow,HIGH);
        delay(100);
       digitalWrite(yellow,LOW);
      }else{
        digitalWrite(green,HIGH);
         delay(100);
       digitalWrite(green,LOW);
        }

   
}

// fuction for conversion(ms-cm)

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
