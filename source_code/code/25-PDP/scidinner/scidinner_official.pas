program diagwnismos_b_fasi;
var max,i,d,proswrino,n,m,a,b,temp,z,top:integer;
pin:array[1..999999]of integer;
k,stack,plith:array[1..1000000]of integer;
filein,filex:text;
t:boolean;
begin
assign(filein,'scidinner.in');
reset(filein);
readln(filein,n,m);
for i:=1 to n do k[i]:=0;
for i:=1 to m do
begin
readln (filein,a,b);
pin[i]:=b;
k[b]:=a;
end;
close(filein);
max:=-1;
for i:=1 to m do
begin
plith[pin[i]]:=1;
proswrino:=pin[i];
t:=false;
top:=0;
while (k[proswrino]<>0) and (t=false) do
begin
if plith[k[proswrino]]=0 then
begin
plith[pin[i]]:=plith[pin[i]]+1;
proswrino:=k[proswrino];
top:=top+1;
stack[top]:=proswrino;
if plith[pin[i]]>max then
max:=plith[pin[i]];
end
else
begin
plith[pin[i]]:=plith[pin[i]]
+plith[k[proswrino]];
t:=true;
if plith[pin[i]]>max then
max:=plith[pin[i]];
end;
end;
temp:=plith[pin[i]];
for z:=1 to top do plith[stack[z]]:=temp-z;
// for z:=1 to n do write(z:2,' '); writeln;
// for z:=1 to n do write(plith[z]:2,' ');
writeln;
// for z:=1 to n do write(k[z]:2,' ');
writeln;readln;
end;
assign(filex,'scidinner.out');
rewrite(filex);
writeln(filex,max);
close(filex);
end.
