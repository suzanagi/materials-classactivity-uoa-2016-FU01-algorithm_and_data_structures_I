#include <stdio.h>

int factorial(int);
int geometrical(int, int);
int fibonacci(int);
double horner(int, int);

int main(){
  /*カウンタ変数*/
  int i;
  /*階乗を求める数*/
  int fact = 10;
  /*等比級数の等比と項数*/
  int r = 2, arity = 10;
  /*求めるフィボナッチ数列の項*/
  int fibnum = 20;
  /*4次多項式に入れるxの値と式の次数*/
  int x = 2, order = 4;
  
  /*階乗の出力*/
  printf("%d! = %d\n",fact ,factorial(fact));
  /*等比級数の出力*/
  for(i = 0; i < arity; i++){
    printf("%d^%d",r, i);
    if(i == 9)printf(" = ");
    else printf(" + ");
  }
  printf("%d\n",geometrical(r, arity - 1));
  /*フィボナッチ数列の第n項の値の出力*/
  printf("fibonacci %d: %d\n",fibnum ,fibonacci(fibnum));
  /*4次多項式の結果を出力*/
  printf("f(%d) = %4.2f\n",x ,horner(x, order));
  
  return 0;
}

/*階乗*/
int factorial(int num){
  if(num == 0) return 1;
  else return num * factorial(num - 1);
}

/*等比級数*/
int geometrical(int r, int num){
  /*等比r, 項数num*/
  int result = 1;
  int i;

  if(num == 0) return 1;
  
  for(i = 0; i < num; i++){
    result *= r;
  }

  result += geometrical(r, num - 1);
  
  return result;
}

/*フィボナッチ数列の第n項の値*/
int fibonacci(int num){

  /* ErrorOutput
   * fprintf(stderr,"fibonacci: %d",num);
   */  

  if(num > 2) return fibonacci(num - 1) + fibonacci(num - 2);
  else if(num == 2 || num == 1) return 1;
  else{
    printf("unusual number\n");
    return 0;
  }
}

/*4次多項式(ホーナー法を用いる)*/
double horner(int x, int num){
  /*多項式 x^4 + 2x^3 + 3x^2 + 4x + 5*/

  /*係数anを配列で宣言しておく*/
  double an[5] = {1.0 ,2.0 ,3.0 ,4.0 ,5.0};
  
  if(num == 0) return 1;

  /*今回はanは配列からもってくる*/
  return horner(x, num - 1) * (double)x + an[num];
}
