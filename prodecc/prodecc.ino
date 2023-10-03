char incoming=0;//var to store incoming data
int i;
void setup() 
{
Serial.begin(9600); 
for(i=1;i<8;i++)
{ pinMode(i,OUTPUT);
}
}
void loop() 
{
  if(Serial.available()>0)
   {
   char incoming=Serial.read();
   switch(incoming)
      {case '1':digitalWrite(2,HIGH);break;
       case 'A':digitalWrite(2,LOW);break;
       case '2':digitalWrite(3,HIGH);break;
       case 'B':digitalWrite(3,LOW);break;
       case '3':digitalWrite(4,HIGH);break;
       case 'C':digitalWrite(4,LOW);break;
       case '4':digitalWrite(5,HIGH);break;
       case 'D':digitalWrite(5,LOW);break;
       case '5':digitalWrite(6,HIGH);break;
       case 'E':digitalWrite(6,LOW);break;
       case '6':digitalWrite(7,HIGH);break;
       case 'F':digitalWrite(7,LOW);break;
       case '7':digitalWrite(8,HIGH);break;
       case 'G':digitalWrite(8,LOW);break;
       default:break;
      }  
Serial.println(incoming);
   }  
delay(50);
}  
            
