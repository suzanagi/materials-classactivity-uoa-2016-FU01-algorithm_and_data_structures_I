#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10000

void printdata(void);
void printdata30(void);
int binarysearch(int v);
int interpolationsearch(int v);
void quicksort(int a[], int l, int r);

int a[N]={ 1, 4, 6, 9, 10, 13, 19, 23, 25, 30 };
int comparison;

int main(){
  int i, key, ret;

  srand(getpid());

  for( i=0; i<N; i++){
    a[i]=rand();
  }

  quicksort( a, 0, N-1 ); /* クイックソート */

  printdata30();


  /* binarysearch */
  printf("Input key for binary search:  ");
  scanf("%d", &key);

  ret=binarysearch(key);

  if( ret==-1 ){
    printf("not found.\n");
  }else{
    printf("found.\n");
  }
  printf("Number of Comparison:  %d\n", comparison); /* 比較回数を表示 */
  printf("\n");

  /* interpolationsearch */
  printf("Input key for interpolation search:  ");
  scanf("%d", &key);

  ret=interpolationsearch(key);

  if( ret==-1 ){
    printf("not found.\n");
  }else{
    printf("found.\n");
  }
  printf("Number of Comparison:  %d\n", comparison); /* 比較回数を表示 */

  return 0;
}

int binarysearch(int v){

  int l = 0, r = N, m;
  /*比較回数を初期化*/
  comparison = 0;
  while(r >= l){
          /*比較回数をインクリメント*/
          comparison++;
    
	  m = (l + r) / 2;
	  
	  if(v < a[m]) r = m - 1;
	  else if(v == a[m]) return a[m];
	  else l = m + 1;
	  
  }

  return -1;
}

int interpolationsearch(int v){

  int l = 0, r = N - 1, m;
  /*比較回数を初期化*/
  comparison = 0;
  while(r >= l){
          /*比較回数をインクリメント*/
          comparison++;

	  /*探索する値がlからrまでの要素に含まれないとき*/
	  //mの値がデータ列の範囲を超える場合の考慮を含む
	  //分子が負の値になる場合の考慮を含む
	  if(v < a[l] || a[r] < v){
	    break;
	  }
	  
	  /*0での除算になった場合*/
	  if(a[r] == a[l]){//要素lからrまでが同じものになっている
	    if(a[l] == v){//要素lからrまでの要素が探索対象の v に等しい場合
	      return a[r];
	    }
	    else break;//要素内に探索対象の v がない場合
	  }
	  
      	  m = l + (((double)(v - a[l])/(double)(a[r] - a[l])) * (r - l));
  
      	  if(v < a[m]) r = m - 1;
	  else if(v == a[m]) return a[m];
	  else l = m + 1;
  }

  return -1;
}

void printdata(void){ /* 全てのdataを表示 */
  int i;

  printf("data:  ");
  for( i=0; i<N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n\n");
}

void printdata30(void){ /* dataを30個表示 */
  int i, j;

  printf("data:\n");

  for( i=0; i<3; i++ ){
    for( j=0; j<9; j++ ){
      printf("%3d ", a[i*10+j]);
    }
    printf("\n");
  }
  printf("\n");
}

void quicksort(int a[], int l, int r){
  int v, i, j, t;
  if( r>l ){
    v=a[r];
    i=l-1;
    j=r;
    for( ;; ){
      while( a[++i]<v );
      while( j>0 && a[--j]>v );
      if( i>=j ) break;
      t=a[i]; a[i]=a[j]; a[j]=t;
    }
    t=a[i]; a[i]=a[r]; a[r]=t;
    quicksort( a, l, i-1 );
    quicksort( a, i+1, r );
  }
}
