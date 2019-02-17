#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *fl;
fl = fopen("domes.in","rb");
freopen("domes.out","w",stdout);
int n,m;
int memorybuffer = 41943040; //40 MB
fseek(fl,0,SEEK_END);
long filesize = ftell(fl); //bytes
fseek(fl,0,SEEK_SET);
int looptimes;
fscanf(fl,"%d%d",&n,&m);
char *domes = (char *)calloc(n+1,sizeof(char));
char *buffer, *start;
int output = 0;
int i = 0;
char cn;
int num1;
int pos =0;
if(filesize > memorybuffer)
{
if(filesize%memorybuffer != 0){
looptimes = (int) (filesize/memorybuffer) + 1;
}else{
looptimes = (int) (filesize/memorybuffer);
}
}else{
looptimes = 1;
memorybuffer = filesize;
}
for(i = 0; i < looptimes;i++)
{
pos = ftell(fl);
while(1)
{
fseek(fl,pos+memorybuffer,SEEK_SET);
cn = fgetc(fl);
if(cn == '\n' || cn ==' ' ||pos+memorybuffer >= filesize){
fseek(fl,pos,SEEK_SET);
break;
}else{
memorybuffer++;
}
}/*Edo 8a doume posi mnimi 8a paroume gia na spasoume to arxio se katalili
8esi*/
buffer = (char *) malloc(memorybuffer*sizeof(char));
fread(buffer,sizeof(char),memorybuffer,fl);
start = buffer;
while(num1 = strtol(start,&start,10))
{
if(*(domes+num1-1) < 2){
*(domes+num1-1)+=1;
}
}
free(buffer);
}
for(i = 0;i < n;i++)
{
if(*(domes+i) < 2)
output++;
}
printf("%d",output);
return 0;
}
