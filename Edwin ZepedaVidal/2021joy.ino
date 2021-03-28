#define joyX A0
#define joyY A1

int xValue;
int yValue;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

}



void loop() {
 
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

 
  Serial.print(xValue);
  Serial.print(',');
  Serial.println(yValue);
  delay(250);
 
  
  
 
  
  
  }
  
  
