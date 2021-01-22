program pdp2b26;
var
infile,outfile:text;
N,K:longint;
scoreb:array[1..101] of longint;
scoreindex,lindex,hindex,i:byte;
score,sum,score1st,score2nd:real;
begin
   assign(infile,'ensemble.in');
   reset(infile);
   readln(infile,N,K);
   for i:=1 to 101 do
      scoreb[1]:=0;
   while not eof(infile) do
   begin
      readln(infile,score);
      scoreindex:=round(score*10)+1;
      scoreb[scoreindex]:=scoreb[scoreindex]+1;
   end;
   lindex:=1;
   while scoreb[lindex]<=K do
   begin
      scoreb[lindex+1]:=scoreb[lindex+1]+scoreb[lindex];
      lindex:=lindex+1;
   end;
   hindex:=101;
   while scoreb[hindex]<=K do
   begin
      scoreb[hindex-1]:=scoreb[hindex-1]+scoreb[hindex];
      hindex:=hindex-1;
   end;
   sum:=0;
   for scoreindex:=lindex to hindex do
      sum:=sum+scoreb[scoreindex]*(scoreindex-1)/10;
   score2nd:=sum/N;
   scoreb[lindex]:=scoreb[lindex]-K;
   scoreb[hindex]:=scoreb[hindex]-K;
   sum:=0;
   for scoreindex:=lindex to hindex do
      sum:=sum+scoreb[scoreindex]*(scoreindex-1)/10;
   score1st:=sum/(N-K-K);
   assign(outfile,'ensemble.out');
   rewrite(outfile);
   writeln(outfile,score1st:4:2,' ',score2nd:4:2);
   close(infile);
   close(outfile);
end.
