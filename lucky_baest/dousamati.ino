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


 void onsitudo(){
  get_temper();
char onsitydo[]={"i'mano,/o'nndoto,/_shitsu'dowa.","_shitsu'dowa.","<NUMK VAL=" + String(h) + " COUNTER=pa-> ","_shitsuo'nnwa","<NUMK VAL=" + String(t) + " COUNTER=do>","dayo?"};
 }
 }

