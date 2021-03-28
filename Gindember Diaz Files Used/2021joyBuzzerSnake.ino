#define joyX A0
#define joyY A1

int xValue;
int yValue;
int buzzer =13;
int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(buzzer,OUTPUT);

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
  
  
