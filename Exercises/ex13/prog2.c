#include <stdio.h>
#include <stdlib.h>

#define MaxNodeNum 100

/*
 * リストのノードを表すデータ構造
 */
struct node {
  int vertex;
  struct node *next;
};
typedef struct node * NodePointer;

/*
 * リストを表すデータ構造
 */
struct list {
  NodePointer head;
  NodePointer tail;
};

void makematrix(int n);
void matrixprint(int n);
void listinitialize(struct list *lp);
NodePointer insert(struct list *lp, int v);
void graphprint(int n);

struct list adj[MaxNodeNum];		/* 隣接リストのデータ構造 */
char matrix[MaxNodeNum][MaxNodeNum];	/* 隣接行列のデータ構造 */


main(){
  int n, e, v, i, j;

  /* グラフのノード数の入力 */
  scanf("%d", &n);
  /* 各ノードの隣接リストの初期化（初期化したいリストのアドレスを渡す） */
  for (i=0; i<n; i++)
    listinitialize(&adj[i]);

  /* 隣接リスト法で表現されたグラフのノードと連結の情報の入力 */
  for (i=0; i<n; i++)  {

    scanf("%d", &e);
    
    for(j = 0; j < e; j++){
      scanf("%d", &v);
      if(insert(&adj[i], v - 1) == NULL){//vの数字はひとつずれる
	printf("list insert failed\n");
	break;
      }
    }

  }
  /* 以下の行のコメントを外すと、グラフの確認ができる */
  /* graphprint(n); */

  makematrix(n);
  matrixprint(n);
}

/* 隣接リスト法による表現から隣接行列法による表現を作る */
void makematrix(int n){

  int i, j;
  NodePointer np;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      matrix[i][j] = '0';

  for(i = 0; i < n; i++){
    np = adj[i].head;
    while(1){
      /*リストの最後についたらループ終了*/
      np = np->next;
      if(np == adj[i].tail)break;
      /*リストの数字の場所のみ1をいれる*/
      matrix[i][(*np).vertex] = '1';

      //printf("Now, put '1' to matrix[%d][%d]\n", i, (*np).vertex - 1);
      }
  }
  
}

/* 隣接行列の出力 */
void matrixprint(int n){

  int i, j;

  printf("matrix\n");
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }

}

/* リストの初期化（初期化するリストへのポインタも引数で与えられる） */
void listinitialize(struct list *lp){
  lp->head = (NodePointer)malloc(sizeof(struct node));
  lp->tail = (NodePointer)malloc(sizeof(struct node));

  lp->head->next = lp->tail;
  lp->tail->next = lp->tail;
}

/* リストへの要素の挿入（挿入先のリストへのポインタも引数で与えられる） */
NodePointer insert(struct list *lp, int v){
  NodePointer x;

  x = (NodePointer)malloc(sizeof(struct node));
  x->vertex = v;
  x->next = lp->head->next;
  lp->head->next = x;
  return x;
}

/* グラフの隣接リスト法によるデータ構造から、隣接リスト法による表現を出力する */
void graphprint(int n)
{
  int i;
  NodePointer np;

  printf("adjacency list\n");
  for (i=0; i<n; i++)  {
    printf("%d: ",i+1);
    for (np=adj[i].head->next; np != adj[i].tail; np = np->next)
      printf("%d ",np->vertex+1);
    putchar('\n');
  }
}
