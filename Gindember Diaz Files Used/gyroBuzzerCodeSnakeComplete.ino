/* The Original Source code was taken from https://how2electronics.com/measure-tilt-angle-mpu6050-arduino/
 *  This Source code has been edited by Gindember Diaz in corder to execcuted a specified application.
 *  
 *  This revised code uses angle measurements from 6050 gyro and will output a string consiting
 *  of eihter Up,Down,Left,Right. These Strings will serve as inputs for snake.py file.
 * 
 */
#include<Wire.h>
 
const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int buzzer = 13;
int incomingByte = 0;

int minVal=265;
int maxVal=402;

double x;
double y;
double z;

String xValue;
String yValue;

void setup(){
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
Serial.begin(9600);
}
void loop(){
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);
AcX=Wire.read()<<8|Wire.read();
AcY=Wire.read()<<8|Wire.read();
AcZ=Wire.read()<<8|Wire.read();
int xAng = map(AcX,minVal,maxVal,-90,90);
int yAng = map(AcY,minVal,maxVal,-90,90);
int zAng = map(AcZ,minVal,maxVal,-90,90);
 
x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
 
//Serial.print("AngleX= ");
//Serial.println(x);
if (x < 330 && x > 240){
  xValue = "up";
}
else if ( x < 100 && x >20){
  xValue = "down";
}
else {
  xValue = "notmoving";
}

if ( y < 330 && y > 270){
  yValue = "right";
}
else if (y < 100 && y > 20){
  yValue = "left";
}
else {
  yValue = "notmoving";
}

Serial.print(xValue);
Serial.print(',');
Serial.println(yValue);

delay(400);
pinMode(buzzer,OUTPUT);
if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
   
    
    if(incomingByte == 'H') {
      digitalWrite(buzzer, HIGH);
    }
     if(incomingByte == 'L'){
      digitalWrite(buzzer, LOW); 
     }

  

  }



  
}
