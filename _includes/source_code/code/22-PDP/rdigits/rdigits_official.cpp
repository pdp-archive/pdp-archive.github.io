#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char originalString[555];
int originalCount[10], toRemoveCount[10];
int originalStringLength;

int findPlace(int start, int number) {
        int i;
        for (i=start; originalString[i]-'0' != number;i++) ;
        return i;
}

int canErase(int start, int end) {
        int i, digit;
        int tempToRemoveCount[10];

        for (i=0; i<=9; i++) tempToRemoveCount[i] = toRemoveCount[i];

        for (i=start; i<=end; i++) {
                digit = originalString[i]-'0';

                if ( tempToRemoveCount[digit] == 0 ) break;
                tempToRemoveCount[digit]--;
        }

        if ( i > end ) return 1;
        return 0;
}

int main(void) {
        FILE *in = fopen("rdigits.in", "r"), *out = fopen("rdigits.out", "w");
        int i, j, k, digit, position;
        char c;

        fscanf(in, "%s\n", originalString);
        originalStringLength = strlen(originalString);

        for (i=0; i<originalStringLength; i++) {
                originalCount[ originalString[i] - '0' ]++;
        }

        while(fscanf(in, "%c", &c) && c != '\n') {
                toRemoveCount[c-'0']++;
        }

        for (i=0; i<originalStringLength; i++) {
                for (j=9; j>=1; j--) {
                        if ( originalCount[j] <= toRemoveCount[j] ) continue;

                        position = findPlace(i, j);

                        if ( canErase(i, position-1) == 1 ) {
                                fprintf(out, "%d", j);

                                for (k=i; k<position; k++) {
                                        digit = originalString[k]-'0';
                                        originalCount[digit]--;
                                        toRemoveCount[digit]--;
                                }

                                originalCount[j]--;

                                i = position;
                                break;
                        }
                }
        }

        fprintf(out, "\n");
        fclose(in); fclose(out); return 0;
}
