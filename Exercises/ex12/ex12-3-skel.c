#include <stdio.h>
#include <stdlib.h>

#define M 11

struct node{
  char key;
};

void hashinitialize(void);
void hashinsert(char v);
int hash(char c);
int hash2(char c);
void hashprint(void);

struct node a[M];

int main(){
  char c;

  hashinitialize();

  printf("Input data: ");
  while( 1 ){
    c = getchar();
    if( c == '\n' ){
      break;
    }
    hashinsert(c);
    hashprint();
  }

  return 0;
}

void hashinitialize(void){
  int i;

  for( i=0; i<M; i++ ){
    a[i].key = ' ';
  }
}

void hashinsert(char v){

  /* ここにプログラムを追加 */

}

int hash(char c){

  /* ここにプログラムを追加 */

}

int hash2(char c){

  /* ここにプログラムを追加 */

}

void hashprint(void){
  int i;

  for( i=0; i<M; i++ ){
    printf("%c ", a[i].key);
  }
  printf("\n");
}
