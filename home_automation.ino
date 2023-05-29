int trigpin=A0;
int echopin=A1;
int bulb=7;
float distance,duration;
int tmp=A2;
int photo_sensor=A3;
int motor=8;
void setup() {
  
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(bulb,OUTPUT);
pinMode(tmp,INPUT);
pinMode(photo_sensor,INPUT);
pinMode(motor,OUTPUT);
}

void loop() {
  
digitalWrite(trigpin,LOW);
delay(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration= pulseIn(echopin,HIGH);
distance=(duration*0.034)/2;
Serial.println(distance);
int tmp_value=analogRead(tmp);
//Serial.println(tmp_value);
float mv=(tmp_value/1024.0)*5000;
float cel=mv/10;
//Serial.println(cel);
int photo_value=analogRead(photo_sensor);
//Serial.println(photo_value);
  if(distance<90)
  {
    if(cel>40)
    {
      digitalWrite(motor,HIGH);
    }
    else
    {
      digitalWrite(motor,LOW);
    }
    if(photo_value<500)
    {
      digitalWrite(bulb,HIGH);
    }
    else
    {
      digitalWrite(bulb,LOW);
    }
  }
  else{
    digitalWrite(motor,LOW);
    digitalWrite(bulb,LOW);
  }
delay(1000);
}
