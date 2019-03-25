#include <stdio.h>
#include <stdlib.h>

#define DEEP 10
#define EMPTY -1

void push(int);
int pop(void);
int isempty(void);
void print_stack(void);
int judge(char);

int stack[DEEP];

int main(){
  char receive;
  int flag = 0;
  int a, b, i;

  /*すべてのスタックの要素に-1を入れておく(要素数の判別のため)*/
  for(i = 0; i < DEEP; i++) stack[i] = -1;

  /*入力の要求*/
  printf("Input data by Reverse Polish Notation: ");

  while(1){
    /*一文字読み込む*/
    receive = getchar();

    switch(judge(receive)){
    
    case 0:
      /*判定外の文字なら処理しないで終了*/
      printf("What's this character.\n");
      flag = 1;
      break;
    case 1:
      /* 受け取ったものが改行文字なら終了 */
      flag = 1;
      break;
    case 2:
      /* 受け取ったものが演算子の場合 */
      b = pop();
      a = pop();

      if(a == EMPTY || b == EMPTY){
	printf("No enough data in stack.\n");
	flag = 1;
	break;
      }

      switch(receive){
      case '+':
	push(a + b);
	break;
      case '-':
	push(a - b);
	break;
      case '*':
	push(a * b);
	break;
      case '/':
	push(a / b);
	break;
      case '%':
	push(a % b);
	  break;
      }
      break;

    case 3:
      /* 受け取ったものが数字の場合 */
      push(atoi(&receive));
      break;
    }

    if(flag == 1) break;

    print_stack();
  }

  printf("Answer: %d\n",stack[0]);

  return 0;
}

void push(int n){ /*スタックにデータ x をプッシュ（一番上に置く）する関数*/
  int i;
  for(i = 0; i < DEEP; i++)
    if(stack[i] == EMPTY) break;
  stack[i] = n;
}

int pop(){/*スタックからデータをポップ（一番上を取る）して、それを返す関数*/
  int n, i;
  if(isempty() == 1) return EMPTY; // 空だったらデータはEMPTYのまま
  for(i = DEEP - 1; i >= 0; i--)
    if(stack[i] != EMPTY) break;
  n = stack[i];
  stack[i] = EMPTY;
  return n;
}

int isempty(){
/*スタックが空かどうかをチェックする関数。空なら 1、そうでないなら 0 を返す。*/
  int i;
  for(i = DEEP - 1; i >= 0; i--){
    if(stack[i] != EMPTY) return 0;
  }

  return 1;
}

void print_stack(){/*スタックの中身を表示する関数*/
  int i;
  for(i = 0; stack[i] != EMPTY; i++)
     printf("%d ",stack[i]);
  printf("\n");
}

 int judge(char c){/*文字が演算子か数字か改行文字かそれ以外か判定する関数*/
   /*
    *改行文字なら 1
    *演算子なら 2
    *数字なら 3
    *それ以外なら 0
    *を返す
    */
   if(c == '\n') return 1;
   else if(c == '+' || c == '-' || c == '*' 
	   || c == '/' || c == '%') return 2;
   else if(c >= '0' && c <= '9') return 3;
   else return 0;
 }

