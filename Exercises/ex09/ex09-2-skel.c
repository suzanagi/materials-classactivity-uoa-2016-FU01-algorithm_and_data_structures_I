#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define N 100000

void print_array(int a[]);
void quicksort(int a[], int l, int r);

int main(){
  int i;
  int a[N];
  hrtime_t start, finish;

  srand(getpid());

  for( i=0; i<N; i++){
    a[i]=rand();
  }

  /*   print_array(a); */

  start=gethrtime();
  quicksort( a, 0, N-1 );
  finish=gethrtime();
  printf("quick sort: elapsed time %f.\n", (double)(finish-start)/NANOSEC);

  /*   print_array(a); */

  return 0;
}

void print_array(int a[]){
  int i;

  for( i=0; i<N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void quicksort(int a[], int l, int r){

  /* ここにプログラムを追加 */

}

