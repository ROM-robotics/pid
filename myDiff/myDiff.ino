double nowx, nowy, freq;// y = dx/dt;
double prv_x, prv_time;
float now_time;
double T;

void setup() {
  prv_x     = 0.0; //x(n-1)
  prv_time  = 0.0; //t(n-1)
  freq      = 1.2;
  Serial.begin(9600);
}
//y=dx/dt
void loop() {
  now_time  = millis() / 1000.0;
  nowx      = sin(2 * PI * freq * now_time);
  //nowx = 2* now_time;
  nowy      = (nowx - prv_x) / (now_time - prv_time);
  
  Serial.print(nowx);
  //Serial.print(" ");
  //Serial.print(nowy);
  Serial.println(" ");
  prv_time  = now_time;
  prv_x     = nowx;
}
