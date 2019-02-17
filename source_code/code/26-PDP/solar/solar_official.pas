program solar;
var
s,a: array [1..1000000] of longint;
x,z,y,N,i,k: longint;
filein,fileout:text;
begin
assign(filein,'solar.in');
assign(fileout,'solar.out');
reset(filein);
readln(filein,N);
for i:= 1 to N do
begin
readln(filein,s[i]);
a[i]:=0;
end;
close(filein);
y:=0;
z:=1000000;
for i:=1 to N do
begin
if s[i]>y then
begin
y:=s[i];
a[i]:=a[i]+1;
end;
end;
for i:= N downto 1 do
begin
if s[i]<z then
begin
z:=s[i];
a[i]:=a[i]+1;
end;
end;
a[1]:=0;
a[N]:= 0;
for i:=1 to N do
begin
if a[i]=2 then
begin
x:=x+1;
end
else
begin
a[i]:=0;
end;
end;
rewrite(fileout);
if x=0 then
begin
write(fileout,'NOT FOUND');
end;
if x= 1 then
begin
for i:= 1 to N do
begin
if a[i]=2 then write(fileout,s[i]);
end;
end;
k:=0;
if x>1 then
begin
for i:= 1 to N do
begin
if (a[i]=2) and (s[i]>k) then
begin
k:=s[i];
end;
end;
write(fileout,k);
end;
close(fileout);
end.
