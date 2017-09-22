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
int ningen=0;
int times_dalays=100; 
//6
//char annnai[5][30]={"kimiwa,/na'niga,/shirita'i?","o'nndo,to,/_shitsu'do?","pimu,ni,tsu'ite?","i'mano,/jikann,ga,/shirita'i?","soreto'mo bo'kuno+koto'?"};//5質問
//温度　pimのこと　時間　ラッキーさん　
//char pims[5][30]={"pi'muwa <NUMK VAL=2014>nennni.","ha'ppi-ga,/_tsuku'tta,/bukatsu,da'yo.","ko-ninnsa'-kuru ni na'ttanowa kono/ma'edayo.","i'ma i'_chi ni/nennsei no buinnga ina'ikara boshu-chu-da'yo.","kimimo isshoni _kika'iga/toku'ina fure'nnzuni nara'nai?"};
//char now_time[3][30]={"waka'ttayo.","maka'sete ","imanojika'nnwa imanojika'nnwa ","awawawa'wawa wa wa wa wa wa wa "};//時
//char boss_no_koto[10][30]={"i'i/se'nnsuda.","bo'kuwa,/kabannchannni,_tsukura'reta.","pi'muno,/bu-su,nabige-to',robodayo.","maikonn'wa i-esu'pi-wa/chini-roku'ro_ku.","to-saisareta,se'nnsa-wa.","onn_shitsu'do se'nnsa-.","seidennyo-ryo-'_shiki/taxtu_chise'nnsa.","soreni/kuwaete,onnseigo-se-a'ishi-o/tsunnderuyo.","bo'_ku sugo'idesho?","kabannga,gittoni,bo'kuno/so-_suko'-doo,agetekureteruyo."};               
//ラッキービースト自身の自己紹介および解説

//  部屋の温度と湿度


//char freez[]={"awawawa'wawa wa wa wa wa wa wa "};//フリーズした時
//////////////////////////////

///////////////////自己紹介だよ
void loop() {
  //String *pointa;
  while( tuch() == 0){}
  static char* jikosyoukai[5][30]={"hajime,ma'_shite","bo'kuwa,/rakki-bi'-_suto,dayo.","kimiwa,/kokoni,/ki'ta.","<NUMK VAL=" +  String(ningen) + " COUNTER=ninnme> ","no,/fure'nnzu,dayo.","kimiwa,/na'niga,/shirita'i?"};
  for(int i=0;i<6;i++){
//    speak(&jikosyoukai[i]);
  }///////////////////自己紹介だよ

 
 int res=0;
 
 /////////////////////////////質問だよ
 static char* annnai[5][30]={"kimiwa,/na'niga,/shirita'i?","o'nndo,to,/_shitsu'do?","pimu,ni,tsu'ite?","i'mano,/jikann,ga,/shirita'i?","soreto'mo bo'kuno+koto'?"};//.c_str();//5質問
  for(int i=0;i<3;i++){
    for(int jj=0;jj<4;jj++){
    res=question(&annnai[jj]);
    if(res>0) {
      res=jj;
      break;
      }
    }
  if(res>0) break;
 }
 /////////////////////////////質問だよ
   //////通常対応の選択
 if(res>0){/////////////////////////////////////////////////////////////////////////////////////////通常対応の選択
    

    
//    sizeof(array) / sizeof(array[0]);
  }//////////////////////////////////////////////////////////////////////////////////////////////// 
 else{
    static char* orei[3][30]={"waka'ttayo.","pimu,no,moyoo'shio","yukkuritanoshi'nndene?"};//.c_str();//無視された時
    for(int i=0;i<3;i++){
    speak(&orei[i]);
    }
  }/////////////////////////////////////////////////////////////////////////////////////////無視された時の対応
 
 get_temper();
    
} 



 



///////////////////////////////////
int question(char *talk[30]){
     atp.Synthe(talk); 
     delay(100); 
     int sawata = 0;
     while(digitalRead(6)==LOW){sawata=1;};
     return sawata;  
}

void speak(char *talk[30]){
     atp.Synthe(talk); 
     delay(100); 
     while(digitalRead(6)==LOW){};
     return 0;
}

