#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

  char input;
  int isbn[10];
  int check[9];
  int i = 0;

  /*入力指示と入力処理*/
  printf("Input ISBN:  ");
  while(1){
    /*char型inputに入力した一文字を入れる*/
    scanf("%c",&input);

    /*入力した文字が数字だった場合*/
    if(input >= '0' && input <= '9'){
      isbn[i] = atoi(&input);
      i++;
    }
    /*ISBNが9文字入力されたらbreak*/
    if(i == 9) break;
  }

  /*チェックディジットを求める*/  
  /*各桁の桁数倍の計算したものを配列checkに入れる*/
  for(i = 0; i < 9; i++){
    check[i] = isbn[i] * (i + 1);
  }
  
  /*配列checkを全て足したものをISBNの配列のチェックディジット(9番目)にいれる。*/
  /*9番目の初期化*/
  isbn[9] = 0;
  /*すべて足す*/
  for(i = 0; i < 9; i++)
    isbn[9] += check[i];

  /*9番目を11で割った余りに入れ替える。*/
  isbn[9] %= 11;

  /*結果を出力*/
  printf("ISBN => ");
  /*1-3桁目*/
  printf("%d-%d%d-",isbn[0] ,isbn[1] ,isbn[2]);
  /*n-9桁目*/
  for(i = 3; i < 9; i++)
    printf("%d",isbn[i]);
  printf("-");
  /*検査数字*/
  if(isbn[9] == 10)
    printf("X");
  else
    printf("%d",isbn[9]);

  printf("\n");
  
  return 0;
}
