#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, n, Hits[100000], Servers[10000], j, k, max, key[3], ServReplace[3], maxHits;
    FILE *file_in, *file_out;
    for (i = 0; i < 10000; i++)
        Servers[i] = 0;
    file_in = fopen("sch.in", "r");
    fscanf(file_in, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(file_in, "%d", &Hits[i]);
        if (i == 0)
            maxHits = Hits[0];
        if (Hits[i] > maxHits)
            maxHits = Hits[i];
        k = Hits[i];
        Servers[k - 1] = Servers[k - 1] + 1;
    }
    fclose(file_in);
    for (i = 0; i < 3; i++) {
        key[i] = 0;
        ServReplace[i] = 0;
    }
    for (j = 0; j < 3; j++) {
        ServReplace[j] = 0;
        max = Servers[0];
        for (i = 0; i < maxHits; i++) {
            if (Servers[i] > max) {
                max = Servers[i];
                ServReplace[j] = i;
            }
        }
        Servers[ServReplace[j]] = 0;
        key[j] = max;
    }
    file_out = fopen("sch.out", "w");
    fprintf(file_out, "%d %d %d\n", ServReplace[0] + 1, ServReplace[1] + 1, ServReplace[2] + 1);
    fclose(file_out);
    return 0;
}
