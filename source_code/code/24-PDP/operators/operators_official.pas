(* NAME: KOULAS IASONAS
* TASK: OPERATORS
* LANG: PASCAL
*)
program pdp;
var
input,output: text;
c,thet,arn: array [1..1000000] of longint;
i,s,j,l,min,a,temp,ar1,ar2:longint;
counter,counter1,k,b:integer;

begin

assign(input,'operators.in');
reset(input);
readln(input,a);
assign(output,'operators.out');
rewrite(output);
for i:=1 to a do
begin
read(input,s);
if s<0 then
begin
counter:=counter+1;
arn[counter]:=s;
end
else
begin
counter1:=counter1+1;
thet[counter1]:=s;
end;
end;
if counter1=0 then
begin
write(output,arn[counter-1],' ',arn[counter]);
end
else
if counter=0 then
begin
write(output,thet[1],' ',thet[2]);
end
else
begin
i:=1; j:=counter; k:=1;
while (i<=counter1) and (j>=1) do
if (thet[i]<abs(arn[j])) then
begin
c[k]:=thet[i];k:=k+1;i:=i+1;
end
else
begin
c[k]:=arn[j]; k:=k+1; j:=j-1;
end;
if i>counter1 then
for l:=k to a do
begin
c[l]:=arn[j]; j:=j-1;
end
else
for l:=k to a do
begin
c[l]:=thet[i]; i:=i+1;
end;
min:=2000000000;
for i:=1 to a-1 do
begin
temp:=abs(c[i]+c[i+1]);
if temp<=min then
begin
min:=temp;
ar1:=c[i];
ar2:=c[i+1];
end;
end;
if ar1>ar2 then
begin
write(output,ar2,' ',ar1);
end
else
begin
write(output,ar1,' ',ar2);
end;

end;
close(output);
close(input);

end.
