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

  /* �����˥ץ������ɲ� */

}

int hash(char c){

  /* �����˥ץ������ɲ� */

}

int hash2(char c){

  /* �����˥ץ������ɲ� */

}

void hashprint(void){
  int i;

  for( i=0; i<M; i++ ){
    printf("%c ", a[i].key);
  }
  printf("\n");
}
