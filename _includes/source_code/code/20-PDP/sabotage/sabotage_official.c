/* ΑΝΑΣΤΑΣΙΟΣ ΓΕΡΜΑΝΙΔΗΣ ΚΟΛΛΕΓΙΟ ΨΥΧΙΚΟΥ*/
      
#include <stdio.h>
#define MAXSIZE 1001

int Qx[MAXSIZE*MAXSIZE], Qy[MAXSIZE*MAXSIZE];
char field[MAXSIZE][MAXSIZE];

int main(void) {
  FILE *in, *out;
  
  in=fopen("sabotage.in", "r");
  out=fopen("sabotage.out", "w");
  
  int x=0, y=0, startx=0, starty=0, endx=0, endy=0,
  mines=0, minex=0, miney=0, steps=0,
  tailqx=0, tailqy=0, headqx=0, headqy=0,
  i=0, p=0, direction=0, mode=0,
  ux=0, uy=0, vx=0, vy=0, kx=0, ky=0,
  found=0, finished=0;
  
  for (i=1; i<x+1; i++) {
    for (p=1; p<y+1; p++) {
      field[i][p] = 0;
    }
  }
  
  for (i=0;i<(x+1)*(y+1);i++) {
    Qx[i]=0;
    Qy[i]=0;
  }
  
  fscanf(in,"%d %d\n", &x, &y);
  if (startx>endx) { direction=1; }
  fscanf(in,"%d\n", &mines);
  
  for (i=0;i<mines;i++) {
    fscanf(in,"%d %d\n", &minex, &miney);
    field[minex][miney]=1;
    minex=0;
    miney=0;
  }
  
  fscanf(in,"%d %d\n", &startx, &starty);
  fscanf(in,"%d %d\n", &endx, &endy);
  fclose(in);
  
  field[startx][starty]=4;
  Qx[tailqx++]=startx;
  Qy[tailqy++]=starty;
  
  while (!finished) {
    ux=Qx[headqx];
    uy=Qy[headqy];
    if (ux==0 && uy==0) {
      finished=1;
    }
    
    for (i=0;i<3 && ux!=0 && uy!=0;i++) {
      vx=0;
      vy=0;
      if (!direction) {
        if (field[ux+1][uy]==0 && ux!=x) {
          vx=ux+1;
          vy=uy;
          mode=1;
        }
        else if (field[ux][uy+1]==0 && uy!=endy) {
          vy=uy+1;
          vx=ux;
          mode=2;
        }
        else if (field[ux-1][uy]==0 && ux!=1) {
          vx=ux-1;
          vy=uy;
          mode=3;
        }
      }
      else if (direction) {
        if (field[ux-1][uy]==0 && ux!=1) {
          vx=ux-1;
          vy=uy;
          mode=3;
        }
        else if (field[ux][uy+1]==0 && uy!=endy) {
          vy=uy+1;
          vx=ux;
          mode=2;
        }
        else if (field[ux+1][uy]==0 && ux!=x) {
          vx=ux+1;
          vy=uy;
          mode=1;
        }
      }  
      
      if (vx != 0 && vy != 0 && field[vx][vy]==0) {
        field[vx][vy]=mode;
        if (vx==endx && vy==endy) {
          found=1;
          finished=1;
        }
        Qx[tailqx++]=vx;
        Qy[tailqy++]=vy;
      }
    }
    headqx++;
    headqy++;
    steps++;
  }
  
  if (!found) {
    fprintf(out,"%d\n",0);
  }
  else {
    kx=endx;
    ky=endy;
    for(i=0;i<(x+1)*(y+1);i++) {
      Qx[i]=0;
      Qy[i]=0;
    }
    
    for (i=steps+1; i>0; i--) {
      if (field[kx][ky]!=4) {
        if (field[kx][ky]==1) {
          Qx[i]=kx-1;
          Qy[i]=ky;
        }
        else if (field[kx][ky]==2) {
          Qx[i]=kx;
          Qy[i]=ky-1;
        }
        else if (field[kx][ky]==3) {
          Qx[i]=kx+1;
          Qy[i]=ky;
        }
        kx=Qx[i];
        ky=Qy[i];
      }
    }
    
    for (p=0; Qx[p]==0;p++) { ; }
    
    fprintf(out,"%d\n", steps-p+3);
    for (i=p;i<steps+2;i++) {
      fprintf(out,"%d %d\n", Qx[i], Qy[i]);
    }
    
    fprintf(out,"%d %d\n", endx, endy);
  }
  fclose(out);
  return(0);
}

