program project1;
var kol,max,N,i,ans,r1,j: LongInt;
infile,outfile:Text;
begin
Assign(infile,'twosqr.in');
Reset(infile);
Assign(outfile,'twosqr.out');
Rewrite(outfile);
Read(infile,kol);
For j:=1 to kol do
begin
Read(infile,N);
i:=0;
ans:=0;
max:=N div 2;
While i*i<=max do
begin
r1:=round(sqrt(N-i*i));
if (i*i+r1*r1=N) then ans:=ans+1;
inc(i);
end;
Writeln(outfile,ans);
end;
Close(infile);
Close(outfile);
halt(0);
end.
