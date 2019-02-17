#include <stdio.h>
#include <stdlib.h>
#define F_IN "scidinner.in"
#define F_OUT "scidinner.out"
typedef struct {
int *data;
int size;
int top;
} stack;
int Max(int *list, int size)
{
register int i, max;
max = list[1];
for (i=2; i<=size; i++) {
if (list[i] > max)
max = list[i];

}
return max;
}
int main()
{
int N, M, j, k, d=0;
register int i;
int *list, *count;
int **sec;
stack st;
FILE *in, *out;
in = fopen(F_IN, "r");
fscanf(in, "%d %d", &N, &M);
list = (int *) calloc(N + 1, sizeof(int));
count = (int *) calloc(N + 1, sizeof(int));
st.data = (int *) malloc(N * sizeof(int));
st.size = N;
st.top = 0;
sec = (int **) calloc(2, sizeof(int *));
sec[0] = (int *) calloc(N + 1, sizeof(int));
sec[1] = (int *) calloc(N + 1, sizeof(int));
for (i=1; i<=M; i++) {
fscanf(in, "%d %d", &k, &j);
if (k == j)
continue;
list[j] = k;
}
fclose(in);
for (i=1; i<=N; i++) {
if (count[i] != 0)
continue;
if (list[i] == 0) {
count[i] = 1;
continue;
}
j = list[i];
st.data[st.top++] = i;
sec[0][i] = i;
sec[1][i] = 0;
while (st.top < st.size) {
if (list[j] == 0) {
count[j] = 1;
k = count[j];
break;
}
if (count[j] != 0) {
k = count[j];
break;
}
if (sec[0][j] == i) {
k = st.top - sec[1][j];
d = k;
count[j] = k;
break;
}
sec[0][j] = i;
sec[1][j] = st.top;
st.data[st.top++] = j;
j = list[j];
}
while (st.top > 0)
count[st.data[--st.top]] = (--d >= 0) ? k : ++k;

st.top = 0;
d = 0;
}
out = fopen(F_OUT, "w+");
fprintf(out, "%d\n", Max(count, N));
fclose(out);
free(list);
free(count);
free(st.data);
free(sec[0]);
free(sec[1]);
free(sec);
return 0;
}
