/*
   test write of ultrasonic code
   ultrasonic distance sensor connected
   to leds, different color lights up
   based on distance
*/

#define TRIGPIN 7; // set constant for trigger pin
#define ECHOPIN 8; // set constant for echo pin

int led_red = 5; // port red led is in
int led_green = 4; // port green led is in
int led_yellow = 3; // port yellow led is in
int led_blue = 2; // port blue led is in

long duration, distance; // duration used to calculate distance

void setup()
{
  // code for distance sensor
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Serial.begin(9600);

  // led code
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_blue, OUTPUT);
}

void loop()
{
  // code for distance sensor

  // following TRIGPIN/ECHOPIN cycle used to determine
  // distance of nearest object by bouncing soundwaves off them
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // starts timing when signal goes HIGH
  // stops timing when signal goes LOW
  // returns time in microseconds
  duration = pulseIn(ECHOPIN, HIGH);

  // calculate distance (in cm) based on speed of sound
  distance = duration/58.2;
  Serial.println(distance); // log distance to serial monitor
  delay(500); // delay .5 seconds before next reading

  // code for leds

  // check distance through IF statement
  if (distance > 0 && distance < 10)
  {
    digitalWrite(led_red, HIGH) // turn on red led
    delay(500)
    digitalWrite(led_red, LOW) // turn off red led
  }
  else if (distance > 10 && distance < 50)
  {
    digitalWrite(led_green, HIGH) // turn on green led
    delay(500)
    digitalWrite(led_green, LOW) // turn off green led
  }
  else if (distance > 50 && distance < 200)
  {
    digitalWrite(led_yellow, HIGH) // turn on yellow led
    delay(500)
    digitalWrite(led_yellow, LOW) // turn off yellow led
  }
  else
  {
    digitalWrite(led_blue, HIGH) // turn on blue led
    delay(500)
    digitalWrite(led_blue, LOW) // turn off blue led
  }
}
