/* Άγγελος Καθαρόπουλος (Αρσάκειο ΓΕΛ Θεσσαλονίκης) */
     
#include <stdio.h>

struct freq
{
  int f;
  unsigned char ch;
};

void mySort(freq *table,int size);


int main ()
{
  FILE * frikin;
  FILE * frikout;
  frikin = fopen("friktories.in","rb");
  frikout = fopen("friktories.out","w");
  if (frikin == NULL || frikout == NULL) 
  { 
    perror("Couldn't open a file"); 
    return -1; 
  }
 
  freq myChars[25];
  for (int i = 0; i < 25; i++) { myChars[i].f = 0;
    myChars[i].ch=i+128; }
 
  myChars[24].ch = 32;
  long size,res;
  unsigned char *container;
  fseek(frikin,0,SEEK_END);
  size = ftell(frikin);
  rewind(frikin);
  container = new unsigned char[size];
  if (container == NULL) {fclose(frikout); fclose(frikin);
    perror("Error allocating the memory needed to read the file"); return -1; }

  res = fread(container,1,size,frikin);
  if (res != size) 
  {
    fclose(frikout); fclose(frikin); 
    delete [] container; 
    perror("Error reading file into memory");
    return -1; 
  }

  fclose(frikin);
  for (unsigned char *temp = container; *temp; temp++)
  {
    if (*temp < 152 && *temp > 127)
    {
      myChars[(*temp)-128].f++;
    }
    else if (*temp == 32)
    {
      myChars[24].f++;
    }
  }
  mySort(myChars,25);
  for (int i = 0; i < 25; i++) 
  { 
    fprintf(frikout,"%c %d\n",myChars[i].ch,myChars[i].f); 
  }
  delete [] container;
  fclose(frikout);
  return 0;
}


void mySort(freq *table, int size)
{
  unsigned short swap = 1;
  freq temp;
  while (swap)
  {
    swap = 0;
    for (int i = 0; i < size-1; i++)
    {
      if (table[i].f < table[i+1].f)
      {
        temp = table[i];
        table[i] = table[i+1];
        table[i+1] = temp;
        swap = 1;
      }
    }
  }
}

