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
  if(r>MIN_LEN){
    star(x-r, y+r, r/2);      /* 焊惧を面看に star を闪く */
    star(x+r, y+r, r/2);      /* 宝惧を面看に star を闪く */
    star(x-r, y-r, r/2);      /* 焊布を面看に star を闪く */
    star(x+r, y-r, r/2);      /* 宝布を面看に star を闪く */

    line(x-r, y-r, x+r, y-r);    /* 布收を闪く */
    line(x+r, y-r, x+r, y+r);    /* 宝收を闪く */
    line(x+r, y+r, x-r, y+r);    /* 惧收を闪く */
    line(x-r, y+r, x-r, y-r);    /* 焊收を闪く */
  }
}
