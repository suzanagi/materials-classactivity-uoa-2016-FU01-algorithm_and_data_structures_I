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
  int v, i, j, t;
  if( r > l ){
    v = a[r];
    i = l - 1;
    j = r;
    for( ; ; ){
      while( a[++i] < v ) ;
      while( a[--j] > v ) ;
      if( i >= j ) break;
      t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[i]; a[i] = a[r]; a[r] = t;
    //printf("i: %d\n", i);
    //printf("quicksort begin\n");
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
    //printf("quicksort finished\n");
  }
}

