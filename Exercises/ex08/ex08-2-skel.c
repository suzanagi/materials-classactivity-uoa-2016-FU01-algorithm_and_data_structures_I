#include <stdio.h>

#define N 5

void print_array(int a[]);
void bubble(int a[]);
void insertion(int a[]);
void selection(int a[]);


int main(){
  int method;
  int a[N]={ 7, 1, 6, 5, 2 };
  void (*sort)(int []); /* 関数へのポインタ */

  printf("Before:  ");
  print_array(a);
  printf("\n");

  printf("Select a method (1:buble, 2:insertion: 3: selection) >  ");
  scanf("%d", &method);

  switch( method ){
  case 1:
    sort=bubble;
    break;
  case 2:
    sort=insertion;
    break;
  case 3:
    sort=selection;
    break;
  default:
    sort=bubble;
    break;
  }

  (*sort)(a);

  return 0;
}

void print_array(int a[]){
  int i;

  for( i=0; i<N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void bubble(int a[]){

  /* ここにプログラムを追加 */

}

void insertion(int a[]){

  /* ここにプログラムを追加 */

}

void selection(int a[]){
 
  /* ここにプログラムを追加 */

}
