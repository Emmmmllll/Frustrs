int N11 = 13;
int N12 = 12;
int N22 = 11;
int N21 = 10;
int GSM2 = A1;
int GSM1 = A0;
void setup()
{
 // pinMode(GSM1,OUTPUT);
 // pinMode(GSM2,OUTPUT);
 Serial.begin(9600);
  pinMode(N22,OUTPUT);
  pinMode(N21,OUTPUT);
  pinMode(N11,OUTPUT);
  pinMode(N12,OUTPUT);
  pinMode(GSM1,OUTPUT);
  pinMode(GSM2,OUTPUT);
  Serial.println("Test");

  analogWrite(GSM1, 255);
  analogWrite(GSM2, 255);
//   exit(0);
}

void loop()
{
  digitalWrite(N22,HIGH);  // Motor 1 beginnt zu rotieren
  digitalWrite(N21,LOW);

  analogWrite(GSM1,128);   // Motor 1 soll mit der Geschwindigkeit "200" (max. 255) rotieren 



  analogWrite(GSM2, 128);   // Motor 2 soll ebenfalls mit der Geschwindigkeit "200" (max. 255) rotieren
  delay(2000);

  digitalWrite(N11,LOW);  // Motor 2 beginnt zu rotieren
  digitalWrite(N12,HIGH);
  delay(2000);

 // digitalWrite(N22,LOW);   // Durch die Veränderung von HIGH auf LOW (bzw. LOW auf HIGH) wird die Richtung der Rotation verändert.
 // digitalWrite(N21,HIGH);  
 // digitalWrite(N11,LOW);
 // digitalWrite(N12,HIGH); 
 // delay(2000);

  digitalWrite(N22,LOW);   // Anschließend sollen die Motoren 2 Sekunden ruhen.
  digitalWrite(N21,LOW);  
  digitalWrite(N11,LOW);
  digitalWrite(N12,LOW);

  delay(2000);
}








