#include <stdio.h>
#include <stdlib.h>

#define MaxNodeNum 100
#define WHITE 0
#define GRAY  1
#define BLACK 2

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

void listinitialize(struct list *lp);
NodePointer insert(struct list *lp, int v);
void dfs(int n);
void dfsvisit(int u);
void visitprint(int n);
void graphprint(int n);

struct list adj[MaxNodeNum];	/* 隣接リストのデータ構造 */

/* DFS のためのデータ */
int color[MaxNodeNum];
int d[MaxNodeNum], f[MaxNodeNum];
int time;

main(){
  int n, e, v, i, j;

  /* グラフのノード数の入力 */
  scanf("%d", &n);
  /* 各ノードの隣接リストの初期化（初期化したいリストのアドレスを渡す） */
  for (i=0; i<n; i++)
    listinitialize(&adj[i]);

  /* 隣接リスト法で表現されたグラフのノードと連結の情報の入力 */
  for (i=0; i<n; i++)  {

    /* ここにプログラムを追加 */

  }
  /* 以下の行のコメントを外すと、グラフの確認ができる */
  /* graphprint(n); */

  dfs(n);
  visitprint(n);
}

/* 深さ優先探索 */
void dfs(int n){

    /* ここにプログラムを追加 */

}

void dfsvisit(int u){

    /* ここにプログラムを追加 */

}

/* 各ノードの発見時刻と終了時刻の出力 */
void visitprint(int n){

    /* ここにプログラムを追加 */

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
