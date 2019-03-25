#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};
typedef struct node * NodePointer;

void listinitialize(void);
NodePointer insert(int key);
NodePointer delete(int key);
NodePointer finditem(int v);
void listprint(void);
NodePointer exchange(int v1, int v2);
void reverse(void);

NodePointer head, tail;

int main(){
  int i;

  /* リストを初期化 */
  listinitialize();

  /* データを 9 から 1 までリストに入れる */
  for(i=9; i>=1; i--) {
    if( insert(i)==NULL ){
      printf("Data %d is already on the list\n",i);
    }
  }

  /* リストを表示 */
  listprint();
  printf("\n");

  /* 問題２ */
  printf("=> exchange(1,2)\n");
  if( exchange(1,2)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();
  printf("=> exchange(1,2)\n");
  if( exchange(1,2)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();

  printf("=> exchange(4,7)\n");
  if( exchange(4,7)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();
  printf("=> exchange(4,7)\n");
  if( exchange(4,7)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();
  printf("\n");

  /* 問題３ 
   printf("=> reverse()\n"); 
   reverse();                
   listprint();              
  */
  return 0;
}

/*
 * リストの初期化
 * head と tail を作って、繋げる。
 */
void listinitialize(void){
  head = malloc(sizeof(struct node));
  tail = malloc(sizeof(struct node));

  head->next = tail;
  tail->next = tail;
}

/*
 * 引数で渡された key と同じ値のノードがあるかを調べ、
 * 存在しなければ、key を値に持つノードを作って head の次に繋げ、
 * そのノードへのポインタを返す。
 * すでに存在するならば、リストには繋げず、NULL を返す。
 */
NodePointer insert(int key){
  NodePointer x;

  if(finditem(key) == NULL){
    /* key を値に持つノードを作る */
    x = malloc(sizeof(struct node));
    x->key = key;

    /* head の次に繋げる */
    x->next = head->next;
    head->next = x;
    return x;
  }
  return NULL;
}

/*
 * 引数で渡された key と同じ値のノードがあるかを調べ、
 * 存在するならば、そのノードを削除する。
 * 存在しなければ、リストの操作はしない。
 * 返り値は finditem(key) と同じ値である。
 */
NodePointer delete(int key){
  NodePointer x, y;

  x = finditem(key);
  if(x != NULL){
    /* 削除するノードの前後を繋ぎ換える */
    y = x->next;
    x->next = y->next;

    /* ノードを削除する */
    free(y);
  }
  return x;
}

/*
 * head から tail までのノードの値(key)を表示する。
 */
void listprint(void){
  NodePointer n;

  printf("Head - ");
  n = head->next;
  while (n != tail) {
    printf("%d - ", n->key);
    n = n->next;
  }
  printf("Tail\n");
}

/*
 * v と同じ値を持つノードを探す。
 * 見つかれば、そのノードのひとつ手前のノードへのポインタを返す。
 * 見つからなければ、NULL を返す。
 */
NodePointer finditem(int v){
  NodePointer x, y;

  y = head;
  x = y->next;

  while(x != tail)
  {
    if(x->key == v){
      return y;
    }
    y = x;
    x = y->next;
  }
  return NULL;
}

/*
 * v1 と同じ値が入っているノードと v2 と同じ値が入っているノードを
 * 交換する。
 * 交換できた場合は、v1 と同じ値が入っているノードへのポインタを返す。
 * 交換できない場合は、NULL を返す。
 */
NodePointer exchange(int v1, int v2){
  NodePointer p1, p2;
  NodePointer p3, p4, p5;

  p1=finditem(v1);//p1: v1と同じ値が入っているノードのひとつ前のポインタ
  p2=finditem(v2);//p2: v2と同じ値が入っているノードのひとつ前のポインタ
  if( p1==NULL || p2==NULL ){
    return NULL;
  }

  if( /* p2 の次が p1 なら */ p2->next == p1 ){
    /* ポインタ p1 と p2 を入れ替える */
    p3 = p1;
    p1 = p2;
    p2 = p3;
  }

  if( /* p1 の次が p2 なら */ p1->next == p2 ){
    p1->next = p2->next;
    p2->next = p1->next->next;
    p1->next->next = p2;
  }else{/*p2がp1の次でなければ(p1とp2が離れていたら)*/
    p3 = p1->next;
    p1->next = p3->next;
    p3->next = p2->next->next;
    p2->next->next = p1->next;
    p1->next = p2->next;
    p2->next = p3;
  }

  return p1;
}

/*
 * リストを逆順に繋ぎ換える。
 */
void reverse(void){
  NodePointer c;
  int i, num[9];
    
  c = head->next;

  for(i = 0; i < 9; i++){
    num[i] = c->key;
    c = c->next;
  }

  //fprintf(stderr,"num insert completed.\n");

  /*1番目と9番目、2番目と8番目、3番目と7番目、4番目と6番目を交換*/
  exchange(num[0], num[8]);
  exchange(num[1], num[7]);
  exchange(num[2], num[6]);
  exchange(num[3], num[5]);
}
