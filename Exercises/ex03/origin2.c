#include <stdio.h>
#include <stdlib.h>

#define DEEP 10

int main(){
  int stack[DEEP]; /*スタックを保管する配列*/
  int n = 0; /*次に数字を格納するスタックの要素番号*/
  int i; /*カウンタ変数*/
  int a, b; /*演算に使用する変数*/
  char receive; /*入力された文字を受け取る*/

  /*すべてのスタックの要素に-1を入れておく(要素数の判別のため)*/
  for(i = 0; i < DEEP; i++) stack[i] = -1;

  /*入力の要求*/
  printf("Input data by Reverse Polish Notation: ");

  /*一文字ずつ読み込み処理する*/
  while(1){
    scanf("%c",&receive);
    if(receive == '\n'){ // 受け取ったものが改行文字なら終了
      break;
    }
    else if(receive == '+' || receive == '-' || receive == '*' 
	    || receive == '/' || receive == '%'){ // 受け取ったものが演算子の場合
      if(n < 2){ // スタックに計算するデータがない、または足りない場合
	printf("No enough data in the stack.\n");
	break;
      }
      else{ // スタックに十分なデータがある場合
	a = stack[n - 2];
	b = stack[n - 1];
	/*演算の前にスタックの演算するデータの分を削除しておく*/
	n--;
	stack[n] = -1;
	n--;
	switch(receive){
	case '+':
	  stack[n] = a + b;
	  break;
	case '-':
	  stack[n] = a - b;
	  break;
	case '*':
	  stack[n] = a * b;
	  break;
	case '/':
	  stack[n] = a / b;
	  break;
	case '%':
	  stack[n] = a % b;
	  break;
	}
	n++;
      }
    }
    else if(receive > '0' && receive < '9'){ // 数字ならそれをスタックに放り込む
      a = atoi(&receive);
      stack[n] = a;
      n++;
      if(n == DEEP) printf("stack deep not enough.\n");
    }
    else{/*処理するのはスタックと演算子のみ*/
      printf("Can't process this character: %c\n", receive);
      break;
    }

    /*スタックの中身を出力*/
    for(i = 0; stack[i] != -1; i++)
      printf("%d ",stack[i]);
    printf("\n");
  }

  /*Answerを出力*/
  printf("Answer: %d\n",stack[n - 1]);

  return 0;
}
