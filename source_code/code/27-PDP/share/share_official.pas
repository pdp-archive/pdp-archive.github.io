program ishare;
var
share:text;
sum,i,n,mo:longint;
kerdos: array[1 .. 1000000] of longint;
elegxos:boolean;

begin
assign(share,'share.in');
reset(share);
readln(share,n);
for i:=1 to n do
begin
readln(share,kerdos[i]);
sum:=sum+kerdos[i];
end;
close(share);

mo:=round(sum/3);
if mo<sum/3 then
mo:=mo+1;
repeat
elegxos:=true;
i:=1;
sum:=0;
while ((sum+kerdos[i])<=mo) and (n-i>=2) do
begin
sum:=sum+kerdos[i];
i:=i+1;
end;
sum:=0;
while ((sum+kerdos[i])<=mo) and (n-i>=1) do

begin
sum:=sum+kerdos[i];
i:=i+1;
end;
sum:=0;
if (i<n) then
begin
for i:=i to n do
begin
sum:=sum+kerdos[i];
end;
end
else
if kerdos[n]>mo then
mo:=kerdos[n];
if sum>mo then
elegxos:=false;
mo:=mo+1;
until elegxos=true;
mo:=mo-1;
assign(share,'share.out');
rewrite(share);
write(share,mo);
close(share);
halt(0);
end.
