
// Điều khiển động cơ Hybrid lưỡng cực bằng L298
// Khai báo chân DIR và EN  
  const int DIR1 = 2; 
  const int EN1 = 3; // Chân analog(PWM) output
  const int DIR2 = 4;
  const int EN2 = 5;// Chân analog(PWM) output

  float i,chieu,giatri, val,chieuz ;
  steparray[8] = {0x0C; 0xFF; 0x30; 0x38; 0x08; 0x28; 0x20; 0x2C}; // half step và full step chạy xen kẽ
  Td = 0.005; // Td tương ứng với tốc độ quay 60rpm
  void setup()
  {
      Serial.begin(9600);
      //Đặt các chân EN và DIR thành chân output
      DDRD = 0x3C; // Đặt các chân D2, D3, D4, D5 là output. Trong đó D3, D5 là analog output (PWM)
  }
  
void loop() {
     Serial.print("nhap chieu quay");
     
     while(chieu==0)
      {
         chieu = Serial.parseInt(); // Quy ước chiều quay; chieu = 0: CW; chieu = 1: CCW
      }
        Serial.print("Chieu quay:  ");
        if (chieu ==0)
          Serial.print("quay phai");
        else
          Serial.print("quay trai");
     for(i=0,i<=7,i++){
           DDRD=
     }
        
       
        
    int n=1;
    while (n <= pulsex || n<=pulsey || n<=pulsez)
   {
    n++;
    if (chieuz==1 || chieuz==0)
    {
     digitalWrite(dirPin3,chieuz);
     if(n<pulsez)
     {
      digitalWrite(stepPin3,HIGH);
      delay(5);
      digitalWrite(stepPin3,LOW);
     }
     }

////////////////////////////////
     if (chieuy==1 || chieuy==0)
    {
     digitalWrite(dirPin2,chieuy);
     if(n<pulsey)
     {
      digitalWrite(stepPin2,HIGH);
      delay(5);
      digitalWrite(stepPin2,LOW);
     }
     }
     /////////////////////////////
    if (chieux==1 || chieux==0)
    {
      digitalWrite(dirPin1,chieux);
     if(n<pulsex)
     {
      digitalWrite(stepPin1,HIGH);
      delay(5);
      digitalWrite(stepPin1,LOW);
     }
