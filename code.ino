#include <LiquidCrystal.h>

String s1="Medication      ";
String s2="Exercise        ";
String s3="Party time      ";

int A,B,C,D,E,F;
int flag0,flag1,flag2,flag3,flag4,flag5;
int input_value;
int hour1,hour2,minute1,minute2,ampm;  
int hours,minutes;
LiquidCrystal lcd(2,3,4,5,6,7);
const int backlight =13;
int vibrator = 12;
int led1=11;
int led2=10;
int i=1;
int secs =0;
int secs2 = 0;
int mins = -1;
int hrs = 12;
int inp=-1;
boolean isAM = true; 
boolean isAMcheck;
int flagg=1;
int milliDivSecs = 1000;
int milliDivMins = 60000;
int milliDivHrs = 360000;

unsigned long prevmillis=0;

int interval = 1000;


void setup() {
  Serial.begin(9600);

delay(2000);
 pinMode(backlight, OUTPUT);
    pinMode(vibrator, OUTPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
  digitalWrite(backlight, HIGH);
  lcd.begin(16,2); //set number of cols and rows
  
 
  lcd.setCursor(5,0);
    calliberate();
  lcd.print("12:00 AM");
  
  Serial.begin(9600);

}


void loop() {
  updatetime();

if(flagg==1){
  
if(hrs==hours&&minutes==mins&&isAM==isAMcheck&&inp==-1)
{
  flagg=1;
Serial.println("Alarm bajj raha hai");
lcd.setCursor(0,1);
lcd.print("Alarm Ringing :)");
digitalWrite(vibrator, HIGH);
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
if(analogRead(A2)<C/2)
{
lcd.setCursor(0,1);
  lcd.print("Alarm Stopped\\m/");
  digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
  digitalWrite(vibrator, LOW);
flagg=0;
}
}
else
{lcd.setCursor(0,1);
  lcd.print("                   ");
  digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
  digitalWrite(vibrator, LOW);
}

if(hrs==hours&&minutes==mins&&isAM==isAMcheck&&inp!=-1)
{
  flagg=1;
Serial.println("reminder bajj raha hai");
lcd.setCursor(0,1);
if(inp==1)
lcd.print(s1);

if(inp==2)
lcd.print(s2);

if(inp==3)
lcd.print(s3);

digitalWrite(vibrator, HIGH);
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
if(analogRead(A2)<C/2)
{
lcd.setCursor(0,1);
  lcd.print("Reminder Stopped\\m/");
  digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
  digitalWrite(vibrator, LOW);
flagg=0;
}
}
else
{lcd.setCursor(0,1);
  lcd.print("               ");
  digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
  digitalWrite(vibrator, LOW);
}
}
touchpad();

//if(i==0)

}


void touchpad()
{
  
flag0=flag1=flag2=flag3=flag4=flag5=0;

//Serial.println("PUT on A3");
//delay(1000);
//Serial.println(analogRead(A3));

if(analogRead(A3)<D/2)
{
reminders();
}


if(analogRead(A5)<F/2)
{
  hours=minutes=0;
  hour1=hour2=minute1=minute2=ampm=-1;
  input_value=-1;
  delay(1000);
  Serial.println("Setting Alarm  ");
  lcd.setCursor(0,1);
  lcd.print("setting alarm   ");
delay(1500);
  lcd.setCursor(0,1);
  lcd.print("             ");

Serial.println("Enter 10's place of hour:");
while(hour1==-1)
{
  delay(1000);
  takeInput();  
if(input_value!=-1&&input_value<=2)
hour1=input_value;

if(hour1!=-1)
{
Serial.println(hour1);
  lcd.setCursor(0,1);
    lcd.print(hour1);

}else
Serial.println("Enter 10's place of hour again:");
}

delay(2000);

Serial.println("Enter 1's place of hour:");
while(hour2==-1)
{
  delay(1000);
  takeInput();  

  if(input_value!=-1)
  {
    if(hour1==2&&input_value<=4)
hour2=input_value;
if(hour1<=1)
hour2=input_value;
  }
if(hour2!=-1)
{Serial.println(hour2);
  lcd.setCursor(1,1);
    lcd.print(hour2);
}
else
Serial.println("Enter 1's place of hour again:");
}
lcd.setCursor(2,1);
    lcd.print(":");
delay(2000);
Serial.println("Enter 10's place of minute:");
while(minute1==-1)
{
  delay(1000);
  takeInput();  
  
if(input_value!=-1&&input_value<=5)
minute1=input_value;

if(minute1!=-1)
{
Serial.println(minute1);
  lcd.setCursor(3,1);
    lcd.print(minute1);
}
else
Serial.println("Enter 10's place of minute again:");
}

delay(2000);

Serial.println("Enter 1's place of minute:");
while(minute2==-1)
{    
  delay(1000);
  takeInput();  
if(input_value!=-1)
minute2=input_value;

if(minute2!=-1)
{
  Serial.println(minute2);
  lcd.setCursor(4,1);
    lcd.print(minute2);
}else
Serial.println("Enter 1's place of minute again:");
}

delay(2000);

Serial.println("Enter AM or PM:");
while(ampm==-1)
{    
  delay(1000);
  takeInput();  
if(input_value==11||input_value==12)
ampm=input_value;

if(ampm!=-1)
{	if(ampm==11)
{
  isAMcheck=true;
  Serial.println("AM");
lcd.setCursor(5,1);
    lcd.print("AM");
}		if(ampm==12)
{  isAMcheck=false;
  Serial.println("PM");
  lcd.setCursor(5,1);
    lcd.print("PM");
}
}else
Serial.println("Enter AM or PM again:");
}

String alarm="Alarm time set is ";
String alarmhour=alarm + hour1 + hour2;
String alarmcollen=alarmhour + ':'  + minute1 + minute2;
Serial.println(alarmcollen);


hours=hour1*10+hour2;
minutes=minute1*10+minute2;
//i=0;
delay(1500);
lcd.setCursor(0,1);
lcd.print("Alarm Set ! ! ! ");
delay(1500);
lcd.setCursor(0,1);
lcd.print("                     ");
updatetime();
}




if(analogRead(A0)<A/2)
{
 // hours=minutes=0;
  hour1=hour2=minute1=minute2=-1;
  input_value=-1;
  delay(1000);
  Serial.println("Setting Time");
  lcd.setCursor(0,1);
  lcd.print("Setting Time");
delay(1500);
  lcd.setCursor(0,1);
  lcd.print("                     ");

Serial.println("Enter 10's place of hour:");
while(hour1==-1)
{
  delay(1000);
  takeInput();  
if(input_value!=-1&&input_value<=2)
hour1=input_value;

if(hour1!=-1)
{
Serial.println(hour1);
  lcd.setCursor(0,1);
    lcd.print(hour1);

}else
Serial.println("Enter 10's place of hour again:");
}

delay(2000);

Serial.println("Enter 1's place of hour:");
while(hour2==-1)
{
  delay(1000);
  takeInput();  

  if(input_value!=-1)
  {
    if(hour1==2&&input_value<=4)
hour2=input_value;
if(hour1<=1)
hour2=input_value;
  }
if(hour2!=-1)
{Serial.println(hour2);
  lcd.setCursor(1,1);
    lcd.print(hour2);
}
else
Serial.println("Enter 1's place of hour again:");
}

delay(2000);
 lcd.setCursor(2,1);
    lcd.print(":");
Serial.println("Enter 10's place of minute:");
while(minute1==-1)
{
  delay(1000);
  takeInput();  
  
if(input_value!=-1&&input_value<=5)
minute1=input_value;

if(minute1!=-1)
{
Serial.println(minute1);
  lcd.setCursor(3,1);
    lcd.print(minute1);
}
else
Serial.println("Enter 10's place of minute again:");
}

delay(2000);

Serial.println("Enter 1's place of minute:");
while(minute2==-1)
{    
  delay(1000);
  takeInput();  
if(input_value!=-1)
minute2=input_value;

if(minute2!=-1)
{
  Serial.println(minute2);
  lcd.setCursor(4,1);
    lcd.print(minute2);
}else
Serial.println("Enter 1's place of minute again:");
}

delay(2000);
ampm=-1;
Serial.println("Enter AM or PM:");
while(ampm==-1)
{    
  delay(1000);
  takeInput();  
if(input_value==11||input_value==12)
ampm=input_value;

if(input_value==11||input_value==12)
{	if(ampm==11)
{
  Serial.println("AM");
lcd.setCursor(5,1);
    lcd.print("AM            ");
}		if(ampm==12)
{  Serial.println("PM");
  lcd.setCursor(5,1);
    lcd.print("PM           ");
}
}
else
Serial.println("Enter AM or PM again:");
}

String setting="time set is ";
if(ampm==11)
{
if(isAM==false)
updateAMPM();
}
if(ampm==12)
{
if(isAM==true)
updateAMPM();
}

hrs=hour1*10+hour2;
mins=minute1*10+minute2-1;
updatetime();
//delay(1500);
lcd.setCursor(0,1);
lcd.print("Time Set ! ! ! ");
delay(1500);
lcd.setCursor(0,1);
lcd.print("                       ");
updatetime();
String thour=setting + hour1 + hour2;
String tcollen=thour + ':'  + minute1 + minute2;
Serial.println(tcollen);

}
}



void calliberate()
{
    Serial.println("Calliberating for max light....");
      digitalWrite(13,HIGH);
    delay(2000);
    int x0=analogRead(A0);
        int x1=analogRead(A1);
            int x2=analogRead(A2);
                int x3=analogRead(A3);
                    int x4=analogRead(A4);
                        int x5=analogRead(A5);
                         digitalWrite(13,LOW);
                          Serial.println("Done....");
                         delay(3000);
               
                         Serial.println("Calliberating for least light....");
      digitalWrite(13,HIGH);
    delay(2000);
      int y0=analogRead(A0);
        int y1=analogRead(A1);
            int y2=analogRead(A2);
                int y3=analogRead(A3);
                    int y4=analogRead(A4);
                        int y5=analogRead(A5);
                         Serial.println("Done....");
                         digitalWrite(13,LOW);
                         
                         A=(x0+y0)/2;
                         B=(x1+y1)/2;
                         C=(x2+y2)/2;
                         D=(x3+y3)/2;
                         E=(x4+y4)/2;
                         F=(x5+y5)/2;
//debugg
                         Serial.println(A);
                         Serial.println(B);
                          Serial.println(C);
                           Serial.println(D);
                            Serial.println(E);
                             Serial.println(F);                        

              
delay(2000);                         
                         
}                         

void reminders()
{
  inp=-1;
  while(inp==-1)
  {
lcd.setCursor(0,1);
lcd.print(s1);
delay(2000);

lcd.setCursor(0,1);
lcd.print(s2);
delay(2000);

lcd.setCursor(0,1);
lcd.print(s3);
delay(2000);

lcd.setCursor(0,1);
lcd.print("Enter:               ");
takeInput();
if(input_value<=0||input_value>4)
{ 
lcd.setCursor(0,1);
lcd.print("Aww u missed it :(");

}
if(input_value>0&&input_value<4)
{
inp=input_value;
alarminput();
}
flagg=1;
}
}


void takeInput()
{

input_value=-1;
flag0=flag1=flag2=flag3=flag4=flag5=0;
unsigned long int starttime = millis();
unsigned long int endtime = starttime;

while ((endtime - starttime) <=3000) // do this loop for up to 1000mS
{
if(analogRead(A0)<A)
flag0=1;

if(analogRead(A1)<B)
flag1=1;

if(analogRead(A2)<C)
flag2=1;

if(analogRead(A3)<D)
flag3=1;

if(analogRead(A4)<E)
flag4=1;

if(analogRead(A5)<F)
flag5=1;

endtime = millis();
}
Serial.println("3 seconds over:");


//testing part below
Serial.println(flag0);
Serial.println(flag1);
Serial.println(flag2);
Serial.println(flag3);
Serial.println(flag4);
Serial.println(flag5);
if(flag0==1&&flag1==1&&flag2==1&&flag3==0&&flag4==0&&flag5==0)
{
  input_value=1;
}

if(flag0==0&&flag1==1&&flag2==1&&flag3==1&&flag4==1&&flag5==0)
{
  input_value=2;
}

if(flag0==1&&flag1==1&&flag2==1&&flag3==1&&flag4==0&&flag5==1)
{
  input_value=3;
}

if(flag0==1&&flag1==1&&flag2==1&&flag3==1&&flag4==1&&flag5==0)
{
  input_value=4;
}

if(flag0==1&&flag1==0&&flag2==0&&flag3==1&&flag4==1&&flag5==1)
{
  input_value=5;
}

if(flag0==1&&flag1==1&&flag2==0&&flag3==1&&flag4==1&&flag5==1)
{
  input_value=6;
}

if(flag0==1&&flag1==1&&flag2==1&&flag3==1&&flag4==0&&flag5==0)
{
  input_value=7;
}

if(flag0==1&&flag1==1&&flag2==1&&flag3==1&&flag4==1&&flag5==1)
{
  input_value=8;
}

if(flag0==0&&flag1==0&&flag2==0&&flag3==1&&flag4==1&&flag5==1)
{
  input_value=9;
}

if(flag0==1&&flag1==1&&flag2==0&&flag3==0&&flag4==1&&flag5==1)
{
  input_value=0;
}

if(flag0==0&&flag1==1&&flag2==0&&flag3==1&&flag4==1&&flag5==1)
{
  input_value=11; // down arraow
}

if(flag0==1&&flag1==1&&flag2==1&&flag3==0&&flag4==1&&flag5==0)
{
  input_value=12; // up arrow
}

 String stringOne = "Input value is ";
  String stringTwo = stringOne + input_value;
Serial.println(stringTwo);
delay(1000);
}



void updatetime()
{
  unsigned long currmillis = millis();

  if(currmillis-prevmillis ==499)
{lcd.setCursor(7,0);
  lcd.print(":");
}
  if(currmillis-prevmillis ==999)
{
lcd.setCursor(7,0);
  lcd.print(" ");
}

if(currmillis-prevmillis > 999){
    //lcd.clear();
    prevmillis =currmillis;
   /* if(secs<10){
    lcd.setCursor(12,0);
      lcd.print(secs);
      lcd.setCursor(11,0);
      lcd.print(0);
    }
    else{
      lcd.setCursor(11,0);
      lcd.print(secs);
    }
*/


//display minutes
    if(secs == 0){
      mins = mins+1;
      updateMin();
    }

   secs = (millis()/milliDivSecs)%60; // divide by 1000 and mod by 60 gives seconds from milliseconds  
    
  }

  }

  void updateMin(){
      if(mins > 59){
        hrs = hrs+1;
        updateHrs();  //update hours then
        if(hrs==11 && mins >59){
          updateAMPM();
        }
        mins = 0;  //reset mins

        lcd.setCursor(8,0);
        lcd.print("00");
      }
      if(mins < 10){
        lcd.setCursor(9,0);
      }
      else{
        lcd.setCursor(8,0);
      }
      lcd.print(mins);
  }
  
   void updateHrs(){
      //display hours - needs fixing for am pm

       if(hrs> 12){
        //reset to 1
        hrs = 1;
      }
      if(hrs< 10){
        lcd.setCursor(5,0);
        lcd.print(" ");
        lcd.setCursor(6,0);
      }
      else{
        lcd.setCursor(5,0);
      }
      lcd.print(hrs);
      
  }
  
    void updateAMPM(){
      if(isAM){
        isAM = false;
        lcd.setCursor(11,0);
        lcd.print("PM");
      }
      else{
        isAM = true;
        lcd.setCursor(11,0);
        lcd.print("AM");
      }
  }
  
  void alarminput()
  {
   hours=minutes=0;
  hour1=hour2=minute1=minute2=ampm=-1;
  input_value=-1;
  delay(1000);
  Serial.println("Setting Alarm");
  lcd.setCursor(0,1);
  lcd.print("setting alarm");
delay(1500);
  lcd.setCursor(0,1);
  lcd.print("             ");

Serial.println("Enter 10's place of hour:");
while(hour1==-1)
{
  delay(1000);
  takeInput();  
if(input_value!=-1&&input_value<=2)
hour1=input_value;

if(hour1!=-1)
{
Serial.println(hour1);
  lcd.setCursor(0,1);
    lcd.print(hour1);

}else
Serial.println("Enter 10's place of hour again:");
}

delay(2000);

Serial.println("Enter 1's place of hour:");
while(hour2==-1)
{
  delay(1000);
  takeInput();  

  if(input_value!=-1)
  {
    if(hour1==2&&input_value<=4)
hour2=input_value;
if(hour1<=1)
hour2=input_value;
  }
if(hour2!=-1)
{Serial.println(hour2);
  lcd.setCursor(1,1);
    lcd.print(hour2);
}
else
Serial.println("Enter 1's place of hour again:");
}
lcd.setCursor(2,1);
    lcd.print(":");
delay(2000);
Serial.println("Enter 10's place of minute:");
while(minute1==-1)
{
  delay(1000);
  takeInput();  
  
if(input_value!=-1&&input_value<=5)
minute1=input_value;

if(minute1!=-1)
{
Serial.println(minute1);
  lcd.setCursor(3,1);
    lcd.print(minute1);
}
else
Serial.println("Enter 10's place of minute again:");
}

delay(2000);

Serial.println("Enter 1's place of minute:");
while(minute2==-1)
{    
  delay(1000);
  takeInput();  
if(input_value!=-1)
minute2=input_value;

if(minute2!=-1)
{
  Serial.println(minute2);
  lcd.setCursor(4,1);
    lcd.print(minute2);
}else
Serial.println("Enter 1's place of minute again:");
}

delay(2000);

Serial.println("Enter AM or PM:");
while(ampm==-1)
{    
  delay(1000);
  takeInput();  
if(input_value==11||input_value==12)
ampm=input_value;

if(ampm!=-1)
{	if(ampm==11)
{
  isAMcheck=true;
  Serial.println("AM");
lcd.setCursor(5,1);
    lcd.print("AM");
}		if(ampm==12)
{  isAMcheck=false;
  Serial.println("PM");
  lcd.setCursor(5,1);
    lcd.print("PM");
}
}else
Serial.println("Enter AM or PM again:");
}
hours=hour1*10+hour2;
minutes=minute1*10+minute2;
//i=0;
//delay(1500);
lcd.setCursor(0,1);
lcd.print("Alarm Set ! ! ! ");
delay(1500);
lcd.setCursor(0,1);
lcd.print("                   ");
updatetime();
String alarm="Alarm time set is ";
String alarmhour=alarm + hour1 + hour2;
String alarmcollen=alarmhour + ':'  + minute1 + minute2;
Serial.println(alarmcollen);

  }
