#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE 3

int main(){

  /*魔法陣の数字を保持する二次元配列*/
  int square[LINE][LINE];
  /*後から回転したものの完成系の二次元配列*/
  int done_square[LINE][LINE];
  /*行列を管理するためのカウンタ変数*/
  int i,j;
  /*マス内の数字を管理するためのカウンタ変数*/
  int n = 1;
  /*乱数を格納する変数*/
  int ran;

  /*奇数魔法陣の公式から、まず魔法陣の最下行中央に1を入れる。*/
  i = LINE - 1;
  j = (LINE - 1) / 2;
  square[i][j] = n;

  /*奇数魔法陣の公式から、入力した数字に1足したものを右下のマスに格納する。*/
  while(1){
    /*右下のマスへ移動*/
    i++;
    j++;

    /*マスが枠外だった場合反対面の対応するマスへ移動*/
    if(i >= LINE) i = 0;
    if(j >= LINE) j = 0;

    /*マスに既に数字が入っていた場合*/
    if(square[i][j] > 0 && square[i][j] <= LINE * LINE){
      /*左上のマスへ戻る*/
      i--;
      j--;

      /*戻ったマスが枠外だった場合反対面の対応するマスへ移動*/
      if(i < 0) i = LINE - 1;
      if(j < 0) j = LINE - 1;

      /*戻ったマスから上のマスへ移動*/
      i--;

      /*上のマスが枠外だった場合*/
      if(i < 0) i = LINE - 1;
      
      /*上のマスにも既に数字が入っていた場合(すべて数字が揃ったとき)*/
      if(square[i][j] > 0 && square[i][j] < LINE * LINE)
	break;
    }
    /*前回挿入した数字に1を足したものを現在のマスに挿入*/
    n++;
    square[i][j] = n;
  }

  /*魔方陣は完成したが、これを乱数により左右上下反転(回転)させることで出力に多様性をもたせることができる。*/
  /*乱数の生成*/
  srand((unsigned)time(NULL));
  ran = rand() % 4;
  printf("ran = %d\n",ran);
  /*乱数に応じて反転させる*/
  switch(ran){
  case 0:
    for(i = 0; i < LINE; i++){
      for(j = 0; j < LINE; j++){
	done_square[i][j] = square[i][j];
      }
    }
    break;
  case 1:
    for(i = 0; i < LINE; i++){
      for(j = 0; j < LINE; j++){
	done_square[i][j] = square[LINE - 1 - i][j];
      }
    }
    break;
  case 2:
    for(i = 0; i < LINE; i++){
      for(j = 0; j < LINE; j++){
	done_square[i][j] = square[i][LINE - 1 - j];
      }
    }
    break;
  case 3:
    for(i = 0; i < LINE; i++){
      for(j = 0; j < LINE; j++){
	done_square[i][j] = square[LINE - 1 - i][LINE - 1 - j];
      }
    }
    break;
  default:
    for(i = 0; i < LINE; i++){
      for(j = 0; j < LINE; j++){
	done_square[i][j] = square[i][j];
      }
    }
    break;
  }

  /*出力テスト用
  for(i = 0; i < LINE; i++){
    for(j = 0; j < LINE; j++){
      if(square[i][j] < 0  || square[i][j] > LINE * LINE) square[i][j] = 0;
    }
  }
  */
  
  /*魔法陣を出力*/
  for(i = 0; i < LINE; i++){
    for(j = 0; j < LINE; j++){
      printf("%d ",done_square[i][j]);
    }
    printf("\n");
  }

  
  return 0;
}
