#include <AquesTalk.h> 
#include <Wire.h> //by dd647 

AquesTalk atp; //インスタンス定義 変数名は任意 
int prevt = 0; 
int times = 0; 
int threshold = 5; 
//////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////

float h,t =0; 
int times_dalays=100; 
char jikosyoukai[]={"hajime,ma'_shite","bo'kuwa,/rakki-bi'-_suto,dayo.","kimiwa,/kokoni,/ki'ta.","<NUMK VAL=" + String(h) + " COUNTER=ninnme> ","no,/fure'nnzu,dayo.","kimiwa,/na'niga,/shirita'i?"};//6
char annnai[]={"kimiwa,/na'niga,/shirita'i?","o'nndo,to,/_shitsu'do?","pimu,ni,tsu'ite?","i'mano,/jikann,ga,/shirita'i?"};//4
char orei[]={"waka'ttayo.","pimu,no,moyoo'shio","yukkuritanoshi'nndene?"}
char freez[]={"awawawa'wawa wa wa wa wa wa wa "}
//////////////////////////////

///////////////////自己紹介だよ
void loop() {
  while(tuch==0){}
  for(int i=0;i<6;i++){
    speak(jikosyoukai[i]);
 }///////////////////自己紹介だよ

 
 int res=0;
 /////////////////////////////質問だよ
  for(int i=0;i<3;i++){
    for(int jj=0;jj<4;jj++){
    res=question(annnai[jj]);
    if(res>0) break;
    }
  if(res>0) break;
 }
 /////////////////////////////質問だよ
   
 if(res>0){/////////////////////////////////////////////////////////////////////////////////////////通常対応の選択

  }//////////////////////////////////////////////////////////////////////////////////////////////// 
 else{
    for(int i=0;i<3;i++){
    speak(orei[i]);
    }
  }/////////////////////////////////////////////////////////////////////////////////////////無視された時の対応
 
 t =   get_temper();
    
} 



 



///////////////////////////////////
void question(char talk){
     atp.Synthe(talk); 
     delay(100); 
     sawata = 0
     while(digitalRead(6)==LOW){sawata=tuch()+sawata};
     return sawata;  
}

void speak(char talk){
     atp.Synthe(talk); 
     delay(100); 
     while(digitalRead(6)==LOW){};
     return 0;
}

