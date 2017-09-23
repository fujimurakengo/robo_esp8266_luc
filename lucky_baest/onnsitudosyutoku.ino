float get_temper(){
while(t==0){
  //printf(Wire.endTransmission(true));// 
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

    }
    
  }
//  retruen t;
}
