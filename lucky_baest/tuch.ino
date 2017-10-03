


int tuch(){ 
  times = 0; 

  // パルスの立ち上げ 
  digitalWrite(8, HIGH); 

  // 立ち上がりまでの時間計測 
  while (digitalRead(9)!=HIGH) times++; 

  // 放電するまで待つ 
  digitalWrite(8, LOW); 
  delay(1); 

  // ローパスフィルタ 
  t = 0.8 * prevt + 0.2 * t; 
  prevt = t; 

  // LED点灯 
  if( times > threshold ){ 
    return 1;
    //digitalWrite(13, HIGH); 
  } else { 
    return 0;
    //digitalWrite(13, LOW); 
  } 
}

