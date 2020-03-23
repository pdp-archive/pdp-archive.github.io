#include <stdio.h>
#include <stdlib.h>

FILE *in, *out;

int main(int argc, char** argv) {
   in = fopen("xxx.in", "r");
   int total;
   int size;
   int offset = 0;
   fscanf(in, "%d", &total);
   fseek(in, 0L, SEEK_END);

#if defined(_WIN32)
   size = ftell(in) - 1;
#elif defined(_WIN64)
   size = ftell(in) - 1;
#else
   size = ftell(in);
#endif
   fseek(in, 0L, SEEK_SET);

   char *buffer = (char*) malloc(size + 1);
   char *token;

   fread(buffer, 1, size, in);
   buffer[size] = '\n';

   int *values = (int*) malloc(total * sizeof(int));
   int i;

   while(*buffer != '\n'){
      buffer++;
   }

   buffer++;
 
   for (i=0;i<total;i++){
      values[i] = 0;

      while(*buffer != ' ' && *buffer != '\n'){
         values[i] = (values[i] * 10) + (*buffer - '0');
         buffer++;
      }
      buffer++;
   }

   int maxValue = values[total - 1];
   int output = 1;

   for (i=total-2;i>=0;i--) {
      if (values[i] > maxValue) {
         maxValue = values[i];
         output++;
      }
   }
   fclose(in);
   out = fopen("xxx.out", "w");
   fprintf(out, "%d\n", output);
   fclose(out);
   return 0;
}