#include <stdio.h>
#define exch(A,B) { int t[2]; t[0]=A[0]; t[1]=A[1]; A[0] = B[0]; A[1]=B[1]; B[0] = t[0]; B[1]=t[1]; }

void quicksort(int (*a)[2], int l, int r)
{
   int k, i = l-1, j = r, p = l-1, q = r, v = a[r][1], v0 = a[r][0];
   if (r <= l) return;
	
   while(1)
   {
      while (a[++i][1] > v || (a[i][1] == v && a[i][0] < v0) ) ;
      while (v > a[--j][1] || (a[j][1] == v && a[j][0] > v0)) if (j == l) break;
      if (i >= j) break;
      exch(a[i], a[j]);
   }

    exch(a[i], a[r]); j = i-1; i = i+1;
    for (k = l; k < p; k++, j--) exch(a[k], a[j]);
    for (k = r-1; k > q; k--, i++) exch(a[i], a[k]);
    quicksort(a, l, j);
    quicksort(a, i, r);
}

int main() {
	FILE *in = fopen("hydrogen.in", "r");
    int out_arr[10000][2],i,x,y,in_len,out_len = 0;

	fscanf(in, "%d", &in_len);

	for (i = 0; i < in_len; i++)
    {
       fscanf(in,"%d %d",&x,&y);
		if (y==0)
			continue;           //An oi blables einai 0 de tis theloyme...
		out_arr[out_len][0] = x;
		out_arr[out_len][1] = y;
		out_len++;    //Auto tha katametrisei posa tmhmata exoyme. Einai osa eixame stin arxi plhn auta poy einai 0
    }

	fclose(in);

	quicksort(out_arr, 0, out_len-1);

	FILE *out = fopen("hydrogen.out", "w");  //Open output file

	fprintf(out, "%d\n", out_len);    //Tmhmata

	for (i = 0; i<out_len; i++)         //Print data!
		fprintf(out, "%d\n", out_arr[i][0]);

	fclose(out);
	return 0;
}


