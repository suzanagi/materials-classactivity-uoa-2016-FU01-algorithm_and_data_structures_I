#include <stdio.h>
#include <errno.h>
#define OUTFILE "star.ps"
#define LINE_WIDTH 0.5
#define CENTER_X 300
#define CENTER_Y 400
#define SQUARE_LEN 100
#define MIN_LEN 5

void init_star(void);
void finish_star(void);
void line(float fromX, float fromY, float toX, float toY);
void star(float x, float y, float r);

FILE *fp;

int main(){
  init_star();
  star(CENTER_X, CENTER_Y, SQUARE_LEN);
  finish_star();
  return 0;
}

void init_star(void){
  fp = fopen(OUTFILE, "w");
  if( fp==NULL ){
    perror(OUTFILE);
    exit(errno);
  }
  fprintf(fp, "%%!PS-Adobe-3.0\n");
  fprintf(fp, "%.3f setlinewidth\n\n", LINE_WIDTH);
}

void finish_star(void){
  fprintf(fp, "showpage\n");
  fclose(fp);
}

void line(float fromX, float fromY, float toX, float toY){
  fprintf(fp, "%.3f %.3f moveto\n", fromX, fromY);
  fprintf(fp, "%.3f %.3f rlineto\n", toX-fromX, toY-fromY);
  fprintf(fp, "stroke\n\n");
}

void star(float x, float y, float r){
  /*positionはstarを描く先の方向の情報を入れる。*/
  static int position = 0;
  /*prohibitは四角形がおおきいものに隠れたときに見えないようにするフラグ*/
  int prohibit = 0;

  /*
   *positionとprohibitには
   *左上を1
   *右上を2
   *左下を3
   *右下を4として指定する
   */

  if(r>MIN_LEN){
    switch(position){
    case 0:
      line(x-r, y-r, x+r, y-r);    /* 下辺を描く */
      line(x+r, y-r, x+r, y+r);    /* 右辺を描く */
      line(x+r, y+r, x-r, y+r);    /* 上辺を描く */
      line(x-r, y+r, x-r, y-r);    /* 左辺を描く */
      break;
    case 1:/*左上*/
      line(x-r, y-r, x, y-r);    /* 下辺を描く */
      line(x+r, y, x+r, y+r);    /* 右辺を描く */
      line(x+r, y+r, x-r, y+r);    /* 上辺を描く */
      line(x-r, y+r, x-r, y-r);    /* 左辺を描く */
      prohibit = 4;
      break;
    case 2:/*右上*/
      line(x, y-r, x+r, y-r);    /* 下辺を描く */
      line(x+r, y-r, x+r, y+r);    /* 右辺を描く */
      line(x+r, y+r, x-r, y+r);    /* 上辺を描く */
      line(x-r, y+r, x-r, y);    /* 左辺を描く */
      prohibit = 3;
      break;
    case 3:/*左下*/
      line(x-r, y-r, x+r, y-r);    /* 下辺を描く */
      line(x+r, y-r, x+r, y);    /* 右辺を描く */
      line(x, y+r, x-r, y+r);    /* 上辺を描く */
      line(x-r, y+r, x-r, y-r);    /* 左辺を描く */
      prohibit = 2;
      break;
    case 4:/*右下*/
      line(x-r, y-r, x+r, y-r);    /* 下辺を描く */
      line(x+r, y-r, x+r, y+r);    /* 右辺を描く */
      line(x+r, y+r, x, y+r);    /* 上辺を描く */
      line(x-r, y, x-r, y-r);    /* 左辺を描く */
      prohibit = 1;
      break;
    default:
      break;
    }
    
    if(prohibit != 1){
    position = 1;
    star(x-r, y+r, r/2);      /* 左上を中心に star を描く */
    }    
    if(prohibit != 2){
    position = 2;
    star(x+r, y+r, r/2);      /* 右上を中心に star を描く */    
    }
    if(prohibit != 3){
    position = 3;
    star(x-r, y-r, r/2);      /* 左下を中心に star を描く */
    }
    if(prohibit != 4){
    position = 4;    
    star(x+r, y-r, r/2);      /* 右下を中心に star を描く */
    }
  }
}
