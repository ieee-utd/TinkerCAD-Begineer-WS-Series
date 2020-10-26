int trigPin = 7; 
int echoPin = 6; 

int ledPin = 5; 

int cm = 0; 
int inch = 0; 

int threshold = 100; 

//helper function 
long readUltrasonicDistance(int triggerPin, int ePin)
{
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(triggerPin , LOW); 
  
  long input = pulseIn(ePin, HIGH);
  return input; 
}


void setup()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  pinMode(ledPin, OUTPUT); 
  
  Serial.begin(9600); 
}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(trigPin, echoPin);
  inch = (cm / 2.54); 
  
  Serial.print(cm); 
  Serial.print("cm, "); 
  Serial.print(inch); 
  Serial.println("in"); 
  
  if(cm > threshold)
  {
    //led does not light up
    digitalWrite(ledPin, LOW);
  }
  else //cm <= threshold 
  {
    //led lights up 
    digitalWrite(ledPin, HIGH); 
  }
  delay(100); 
}











