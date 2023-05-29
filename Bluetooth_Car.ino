// Include the SoftwareSerial library to create a serial connection with the GUI
#include <SoftwareSerial.h>

// Define the pins for the motor driver
char t;
int sec;

#define IN1 2
#define IN2 5
#define IN3 4
#define IN4 3

void setup() 
{
  // Set the motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set the baud rate for the serial connection
  Serial.begin(9600);
}

void loop() 
{
  // Check for incoming commands
  if (Serial.available()) 
  {
    t = Serial.read();
    sec = Serial.parseInt();
    Serial.println(t);
    Serial.println(sec);

    // Execute the action based on the command
    if (t == 'F') 
    {
      moveForward(sec);
    } 
    else if (t == 'B') 
    {
      moveBackward(sec);
    } 
    else if (t == 'L') 
    {
      turnLeft(sec);
    } 
    else if (t == 'R') 
    {
      turnRight(sec);
    } 
  }
}

void moveForward(int duration) 
{
  Serial.println("Car Moving Forward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(sec * 1000);
  stopCar();
}

void moveBackward(int duration) 
{
  Serial.println("Car Moving Backward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(duration * 1000);
  stopCar();
}

void turnLeft(int duration) 
{
  Serial.println("Car Moving Left");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(duration * 1000);
  stopCar();
}

void turnRight(int duration) 
{
  Serial.println("Car Moving Right");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(duration * 1000);
  stopCar();
}

void stopCar() 
{
  Serial.println("Car Stopped");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
