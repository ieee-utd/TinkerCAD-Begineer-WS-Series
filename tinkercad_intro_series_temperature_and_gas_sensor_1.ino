/* temperature sensor variables*/
float celcius;
float fahrenheit;
float voltage;
int temperatureSensorPin = A0;

/* gas sensor variables */
const int gas = 0;
int gasSensorPin = A1;

/* variable that both sensors use */
float sensorValue;

void setup()
{
  pinMode(temperatureSensorPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  /* code for the gas sensor */
  sensorValue = analogRead(gasSensorPin);
  
  if(sensorValue >= 450)
  {
	Serial.print(sensorValue);
    Serial.println("	| SMOKE DETECTED!");
  }
  else
  {
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
  }
  
  /* code for the temperature sensor */
  sensorValue = analogRead(temperatureSensorPin);
  
  /* calculating the voltage collected from the sensor */
  voltage = sensorValue * 5;
  voltage /= 1024;
  
  /* calculate the temperature from the voltage */
  
  celcius = (voltage - 0.5) * 100;
  fahrenheit = (9.0 / 5) * celcius + 32;
  
  /* printing the temperatures */
  Serial.print("Celcius: ");
  Serial.println(celcius);
  Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);
  Serial.println();
  
  delay(2000); // pauses for 2 seconds so we're not bombarded with data
}