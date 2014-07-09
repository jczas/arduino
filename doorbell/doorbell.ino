#include <SD.h>
#include <SPI.h>
#include <arduino.h>
#include <MusicPlayer.h>

const int pingPin = 2;

const int distance = 100;
const int delta = 50;
void setup(void)
{
  Serial.begin(9600);
  
  player.begin();
  player.playOne("marsz.mp3");
  player.opStop();
}
void loop(void)
{
  player.play();  //do some leisurely job
  
  delay(500);

  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();  
  
  int minDistance = distance - delta;

  if (cm < minDistance && player.isIdle())
  {
    Serial.println("Play music");  
    player.opPlayPause();
  }
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


