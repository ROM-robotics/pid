double mydecitime,Amplitude,Amplitude2, frequency1, frequency2,frequency3;
double x, x1, x2, y, z, z1,a,b,c;
int    myintetime;
double samp_time, prev_time, myInitialTime, myC,myC1,myC2 ;

void setup()
{
  Serial.begin(9600);
  Amplitude     = 5.0;
  Amplitude2    = 0.5;
  frequency1    = 0.5;//------------------
  frequency2    = 0.1;//------------------
  frequency3    = 40.0;
  myInitialTime = 7.0; 
  myC           = 0.034;
  myC1          = 0.34 ;
  myC2          = 3.4 ;
}
float i = 0.1;
void loop()
{
  mydecitime = millis()/ 1000.0;
  myintetime = micros()/ 1000000;
  samp_time = mydecitime - prev_time;
  //x         = Amplitude * exp(-mydecitime/myC2)* sin(2 * PI * frequency2 * mydecitime) ;
  x         = Amplitude * exp(-mydecitime/myC2) * sin(2*PI* frequency2*i);//2 * PI * frequency2 * mydecitime) ;
  x1        = Amplitude * exp(-mydecitime/myC1) ;
  
  x2        = Amplitude * exp(mydecitime/myC1)  ;
  
  y        = Amplitude * cos(2 * PI * frequency2 * mydecitime);  
  z        = Amplitude2 * sin(2 * PI * frequency3 * mydecitime); 
  z1       = y + z ;

  a = Amplitude * exp(-50*mydecitime) * sin(2 * PI * frequency2 * mydecitime);
  b = Amplitude * exp(-5*mydecitime) * sin(2 * PI * frequency2 * mydecitime);
  c = Amplitude * exp(-0.5*mydecitime) * sin(2 * PI * frequency2 * mydecitime);
  //y         = Amplitude * cos(2 * PI * frequency1 * mydecitime);
  //z         = (x*x) + (y*y);
  //Serial.print("     ");  Serial.print (x2);
  //Serial.print("     ");  Serial.print (x);
  //Serial.print("     ");  Serial.print (x1);
  Serial.print("     ");  Serial.print (z);
  //Serial.print("     ");  Serial.print (y);
  //Serial.print("     ");  Serial.print (y);
  //Serial.print("    ");  Serial.print (x2);
  //Serial.print("     ");  Serial.print (a);
  Serial.print("     ");  Serial.print (z1);
  Serial.print("     ");  Serial.print (mydecitime);
  Serial.println("    ");
  prev_time = mydecitime;
  i += 0.1;
}
