
  const int DIR1 = 9; 
  const float EN1 = 3; 
  const int DIR2 = 6; 
  const float EN2 = 5;    
  float microstep1[16] = {25,51,74,97,120,143,161,181,196,212,224,237,244,250,254,255};  //0->100 chuyen thanh 0->255
  float microstep2[16] = {254,250,244,237,224,212,196,181,161,143,120,97,74,51,25,0};    
  float a=1.8; //goc buoc
  float b=0.05625; //goc quay dong co khi tu truong quay goc 2.8 
  float ppr, pps, rpm, Td, T_ms;
  float s;  // s la vi tri can dieu khien
  float h, k; // k la so lan tu truong quay (s/b) , h la bien chay tu 0 den k
  const float pi = 3.14;
  int i=0, j=0;
  void setup()
  {
      Serial.begin(9600);
      pinMode(EN1,OUTPUT);
      pinMode(EN2,OUTPUT);
      pinMode(DIR1,OUTPUT);
      pinMode(DIR2,OUTPUT);
  }
 void loop() 
  {
    rpm=0;
    s=0.0;
    h=0;
    Serial.println("nhap van toc (vong/phut) ban muon: ");
    while(rpm==0)
    rpm=Serial.parseInt();
    Serial.print("rpm la: ");
    Serial.println(rpm);
    Serial.println("nhap vi tri (degree) ban muon: ");
    while(s==0)
    s=Serial.parseInt();
    Serial.print("s la: ");
    Serial.println(s);
    ppr = 360/a;
    pps=(rpm/60)*ppr;
    Td=1/pps;
    T_ms=((Td/32)*1000);
    k=(s/b);
    while(h<=k)
    {
      digitalWrite(DIR2,1);                //nua duoi goc phan tu thu 1
      digitalWrite(DIR1,1);   
      analogWrite(EN1,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN2,microstep1[i]);
          delay(T_ms);
        }
      }
      digitalWrite(DIR1,1);                   //nua tren goc phan tu thu 1
      digitalWrite(DIR2,1);       
      analogWrite(EN2,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN1,microstep2[i]);
          delay(T_ms);
        } 
      }
      digitalWrite(DIR1,0);                  //nua tren goc phan tu thu 2
      digitalWrite(DIR2,1);     
      analogWrite(EN2,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN1,microstep1[i]);
          delay(T_ms);
        } 
      }
      digitalWrite(DIR2,1);                  //nua duoi goc phan tu thu 2
      digitalWrite(DIR1,0);      
      analogWrite(EN1,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN2,microstep2[i]);
          delay(T_ms);
        } 
      }
      digitalWrite(DIR1,0);                    //nua tren goc phan tu thu 3
      digitalWrite(DIR2,0);    
      analogWrite(EN1,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN2,microstep1[i]);
          delay(T_ms);
        } 
      }
      digitalWrite(DIR1,0);                   //nua duoi goc phan tu thu 3
      digitalWrite(DIR2,0);       
      analogWrite(EN2,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN1,microstep2[i]);
          delay(T_ms);
        } 
      }
      digitalWrite(DIR1,1);                    //nua duoi goc phan tu thu 4
      digitalWrite(DIR2,0);      
      analogWrite(EN2,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN1,microstep1[i]);
          delay(T_ms);
        } 
      }
      digitalWrite(DIR1,1);                   //nua tren goc phan tu thu 4
      digitalWrite(DIR2,0);      
      analogWrite(EN1,255);   
      for (i=0;i<=15;i++)
      {
        if (h>=k)
        {
          h++;
          break;
        }
        else
        {
          h++;
          analogWrite(EN2,microstep2[i]);
          delay(T_ms);
        } 
      }
    }
  }
