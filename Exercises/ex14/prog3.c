#include <stdio.h>
#include <string.h>

#define MaxLen 1000	/* 列の長さの最大値 */

int c[MaxLen+1][MaxLen+1];	/* LCS の長さの表 */

void tableprint(int table[][MaxLen+1], int m, int n);

main()
{
  char X[MaxLen+1], Y[MaxLen+1];	/* 文字列 */
  int m, n, i, j;

  /* 文字列 X の入力 */
  scanf("%s",X);
  /* 文字列 Y の入力 */
  scanf("%s",Y);

  /* 文字列 X と Y の長さ m と n の計算 */
  m = strlen(X);
  n = strlen(Y);

  /*テスト出力
  for(i = 0; i < m; i++)
    printf("X[%d]:%c\n", i, X[i]);
  for(j = 0; j < n; j++)
    printf("Y[%d]:%c\n", j, Y[j]);
  */

  /* LCS の長さの計算 */
  for(i = 0; i <= m; i++)
    c[i][0] = 0;
  for(j = 0; j <= n; j++)
    c[0][j] = 0;

  for(i = 1; i <= m; i++){
    for(j = 1; j <= n; j++){
      if(X[i-1] == Y[j-1]) c[i][j] = c[i - 1][j - 1] + 1;
      else if(c[i - 1][j] >= c[i][j - 1]) c[i][j] = c[i - 1][j];
      else c[i][j] = c[i][j - 1];
    }
  }

  /* 以下の行のコメントを外すと、表 m の内容の確認ができる */
  /* tableprint(c,m,n); */

  /* 文字列 X と Y の LCS の長さの出力 */
  printf("the length of LCS = %d\n", c[m][n]);

}

/* 表の内容の出力 */
void tableprint(int table[][MaxLen+1], int m, int n)
{
  int i, j;

  for (i=0; i<=m; i++)  {
    for (j=0; j<=n; j++)
      printf("%d ",table[i][j]);
    putchar('\n');
  }
}
