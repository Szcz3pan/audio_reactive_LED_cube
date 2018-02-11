/*
 * This sketch is made for controlling 4x4x4 LED cube,
 * attached with loudness sensor.
 * I used Arduino Nano ATmega328P for this project.
 */


int x;
int column[16]={2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3};
int layer[4]={0,1,A4,A5};
int loudsens=A6;
void setup() {
  // put your setup code here, to run once:
  pinMode(loudsens, INPUT);
  for(int i=0; i<16; i++)
  {
  pinMode(column[i], OUTPUT);
  digitalWrite(column[i], 1);
  delay(100);
  }
  for(int i=0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }

  
}

void loop() {
  // put your main code here, to run repeatedly:
  x=analogRead(loudsens);
  x=(x-450)*4/250;
  if(x>=0)
  {
    digitalWrite(layer[0], 0);
  }
  else
    digitalWrite(layer[0], 1);
  if(x>=1)
  {
    digitalWrite(layer[1], 0);
  }
  else
    digitalWrite(layer[1], 1);
  if(x>=2)
  {
    digitalWrite(layer[2], 0);
  }
  else
    digitalWrite(layer[2], 1);
  if(x>=3)
  {
    digitalWrite(layer[3], 0);
  }
  else
    digitalWrite(layer[3], 1);
  delay(100);
}
