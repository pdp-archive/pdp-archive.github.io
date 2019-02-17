#include <cstdio>
#define filename_input "sch.in"
#define filename_output "sch.out"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define getc_unlocked _fgetc_nolock
#endif
#define maxn 1000001
#define maxs 10001

using namespace std;

int all[maxn];
FILE *in, *out;

void fastGet(int& x) {
    int c;
    x = getc(in) - '0';
    while ((c = getc(in)) >= '0')
        x = 10 * x + c - '0';
}

int main() {
    in = fopen(filename_input, "r");
    int n;
    fastGet(n);
    int first = 0, second = 0, third = 0;
    int firstindex = 0, secondindex = 0, thirdindex = 0;
    register int x;
    for (int c = 0; c <= n - 1; c++) {
        fastGet(x);
        all[x]++;
    }
    fclose(in);
    for (int c = 0; c <= maxs; c++) {
        register int x = all[c];
        if (x <= 0) {
            continue;
        } else if (x > first) {
            third = second;
            thirdindex = secondindex;
            second = first;
            secondindex = firstindex;
            first = x;
            firstindex = c;
        } else if (x > second) {
            third = second;
            thirdindex = secondindex;
            second = x;
            secondindex = c;
        } else if (x > third) {
            third = x;
            thirdindex = c;
        }
    }
    out = fopen(filename_output, "w");
    fprintf(out, "%d %d %d\n", firstindex, secondindex,
        thirdindex);
    fclose(out);
    return 0;
}
