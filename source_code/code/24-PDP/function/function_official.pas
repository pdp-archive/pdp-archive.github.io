program functionz;
var i,j,l,n,m,o,temp,limit:integer;
 fin,fout: text;
 k:array [1..10000] of boolean;
 flag:boolean;
begin
assign(fin,'function.in');
Reset(fin);
read(fin,n,m);
close(fin);
if n>m then
begin
temp:=n;
n:=m;
m:=temp;
end;
for o:=1 to m do k[o]:=true;
 limit:=trunc(sqrt(M));
 for i:=2 to limit do
 if k[i] then for j:=2 to m DIV i do k[i*j]:=FALSE;
{for i:=n+1 to m div 2 do
 begin
 if k[i]=true then
 for j:=n+1 to m do
 begin
 k[j*i]:=false;
 end;
 end;}
k[2]:=false;
assign(fout,'function.out');
rewrite(fout);
for l:=n+1 to m-1 do
begin
if k[l]=true then
begin
write(fout,' ',l);
flag:=true;
end;
end;
