#include <AquesTalk.h> 
#include <Wire.h> //by dd647 

AquesTalk atp; //インスタンス定義 変数名は任意 
int prevt = 0; 
int times = 0; 
int threshold = 5; 

void setup(){ 

  Wire.begin(); 
  Serial.begin(9600); 
  delay(100); 
  pinMode(7,OUTPUT); 
    digitalWrite(7,LOW); 
     pinMode(8,OUTPUT); 
  pinMode(9,INPUT); 
  pinMode(13,OUTPUT); 


} 
float h,t =0; 
int times_dalays=100; 
void loop() {
 if (tuch()==1){  
  while(t==0){
  printf(Wire.endTransmission(true));// 
  Wire.beginTransmission(0x5c); // address(0x5c) sensor(AM2320) 
  delay(times_dalays); 
  Wire.write(0x03); //Arduino read senser 
  delay(times_dalays); 
  Wire.write(0x00); //address of Humidity 
  delay(times_dalays); 
  Wire.write(0x04); //The number of address 
                    //(Humidity1,Humidity2,Temperature1,Temperature2) 

  Wire.endTransmission(true);// 

  int ans = Wire.requestFrom(0x5c,6);// request 6 bytes from sensor(AM2320) 
     digitalWrite(7,LOW); 
  // float h,t =0; 
    while(Wire.available() !=0){ 
    int H1,H2,T1,T2 = 0; 

        for(int i = 1; i < ans+1; i++){ 
        int c = Wire.read(); 
            switch (i){ 
            case 5: 
            T1 = c; 
            break; 
            case 6: 
            T2 = c; 
            break; 
            case 3: 
            H1 = c; 
            break; 
            case 4: 
            H2 = c; 
            break; 
            default: 
            break; 
            } 
        } 

    h = (H1*256 + H2)/10.0; 
    t = (T1*256 + T2)/10.0; 
    Serial.print(" Humidity="); 
    Serial.print(h); 
    Serial.print(" "); 
    Serial.print(" Temperature="); 
    Serial.println(t); 

    } }
        Serial.print(" Humidity="); 
    Serial.println(h); 
digitalWrite(7,HIGH);
  atp.Synthe("hajimema'_shite.");
  delay(100); 
  while(digitalRead(6)==LOW){};
  atp.Synthe("bo'kuwa rakki-bi'-_sutodayo."); 
   delay(100); 
 
     delay(100); 
  while(digitalRead(6)==LOW){};//i'mano _shitsuonn to _shitsu'do o/oshierune.
  atp.Synthe("i'mano _shitsuonn to _shitsu'do o/oshierune."); 
  delay(100); 
  while(digitalRead(6)==LOW){};//i'mano _shitsuonn to _shitsu'do o/oshierune.
  
  //////////////////////////// 
  if(t!=0){ 
      digitalWrite(7,HIGH); 
     Serial.println("_________");
    atp.Synthe("_shitsuo'nnwa"); 
     delay(100); 
     while(digitalRead(6)==LOW){};
    String str = "<NUMK VAL=" + String(t) + " COUNTER=do> "; 
    //Serial.println(str); 

    // 発声開始 
    
    atp.Synthe((const char*)&str[0]); 
    String strs = "<NUMK VAL=" + String(h) + " COUNTER=pa-> "; 
    atp.Synthe("_shitsu'dowa."); 
     delay(100); 
    while(digitalRead(6)==LOW){};
    //Serial.println(str); 

    // 発声開始 
     atp.Synthe((const char*)&strs[0]); 
     delay(100); 
     atp.Synthe("dayo"); 
     delay(100); 
     while(digitalRead(6)==LOW){};     
     atp.Synthe("ko'nndo daiga_kuchiho'-no."); 
     delay(100); 
     while(digitalRead(6)==LOW){};
     atp.Synthe("bunnka'saini/iru'kara."); 
      delay(100); 
     while(digitalRead(6)==LOW){};
     atp.Synthe("minnna' yukkurishiniki'tene?"); 
     delay(100); 
     while(digitalRead(6)==LOW){};
     digitalWrite(7,LOW);
 } 
}

     //Wire.endTransmission(true); 
    //delay(5000); 

}
