#define trigPin 13
#define echoPin 12
#define blue 10
#define red 11
#define yell 9

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(blue, OUTPUT);
  pinMode(yell,OUTPUT);
  pinMode(red, OUTPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1 / 2.54; // 2.54 is to make it inches
  if (distance <= 4) {  // This is where the LED On/Off happens
    digitalWrite(red,HIGH);
    digitalWrite(yell,LOW);
    digitalWrite(blue,LOW);
    
    if(distance <= 3){
        digitalWrite(red,LOW);
        delay(50);
        digitalWrite(red,HIGH);
        
    }
  }
  else if(distance > 4 && distance < 12 ){
      digitalWrite(red,LOW);
      digitalWrite(yell,HIGH);
      digitalWrite(blue,LOW); 
  }
  else {
      digitalWrite(red,LOW);
      digitalWrite(yell,LOW);
      digitalWrite(blue,HIGH);
  }

  Serial.print(distance);
  Serial.println(" inches");
  delay(500);
}
