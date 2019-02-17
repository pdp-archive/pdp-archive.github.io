#include <cstdio>
inline int max(int a, int b) {
return (a>b)?a:b;
}
struct Node {
int lo, hi, mid, range;
int rval, lval, mval, val;
bool painted;
Node *left, *right;
void make_children() {
if(range==1) return;
if(left == 0) left = new Node(lo, mid, painted);
if(right == 0) right = new Node(mid+1, hi, painted);
}
void update() {
if(range==1) return;
lval = left->lval;
if(left->val == left->range) lval = left->val + right->lval;
rval = right->rval;
if(right->val == right->range) rval = right->val + left->rval;
mval = max(max(left->val, right->val), left->rval +
right->lval);
val = max(max(lval, rval), mval);
}
void paint(int qlo, int qhi) {
if(qlo <= lo && qhi >= hi) {
rval = lval = mval = val = 0;
painted = true;
return;
}
make_children();
if(qlo <= mid) left->paint(qlo, qhi);
if(qhi > mid) right->paint(qlo, qhi);
update();
}
Node(int l, int h, bool p) {
//printf("Building node for [%d, %d] (%c)\n", l, h, painted?'B':'W');
lo = l; hi = h;
mid = (lo+hi)/2;
range = hi-lo+1;
painted = p;
left = right = 0;
if(painted) rval = lval = mval = val = 0;
else rval = lval = mval = val = range;
}
} *root;
int main() {
FILE *fin = fopen("roadwork.in", "r"), *fout =
fopen("roadwork.out", "w");
int N, L, X;
fscanf(fin, "%d %d %d", &N, &L, &X);
root = new Node(1, L, false);
for(int i=1;i<=N;i++) {
int lo, hi;
fscanf(fin, "%d %d", &lo, &hi);
root->paint(lo, hi);
if(root->val < X) {
fprintf(fout, "%d\n", i);
fclose(fin); fclose(fout);
return 0;
}
}
fprintf(fout, "-1\n");
fclose(fin); fclose(fout);
return 0;
}
