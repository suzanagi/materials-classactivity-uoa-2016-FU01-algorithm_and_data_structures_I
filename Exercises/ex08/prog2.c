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
  int i, j, t;
  for(i = 0; i < N - 1; i++){
    for(j = N - 1; j >= 1; j--){
      //printf("a[j]: %d, a[j - 1]: %d\n", a[j], a[j - 1]);
      if(a[j] < a[j - 1]){
	t = a[j];
	a[j] = a[j - 1];
	a[j - 1] = t;
      }
    }
    print_array(a);
  }
}

void insertion(int a[]){
  int i, j, v;
  for(i = 1; i <= N - 1; i++){
    v = a[i]; j = i;
    while(a[j - 1] > v){
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
    print_array(a);
  }

}

void selection(int a[]){
  int i, j, min, t;
  for(i = 0; i < N - 1; i++){/*main loop*/
    min = i;
    /*find the minimum*/
    for(j = i + 1; j < N; j++)
      if(a[j] < a[min]) min = j;
    /*swap*/
    t = a[min];
    a[min] = a[i];
    a[i] = t;
    /*print array*/
    print_array(a);
  }
}
