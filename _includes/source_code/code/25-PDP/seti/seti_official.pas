PROGRAM Noimosini;
VAR
f1,f2: Text;
N, M, i, d, before, after, count: Integer;
data, out: array[1..10000] of Integer;
BEGIN
assign(f1, 'seti.in');
reset(f1);
readln(f1, N);
FOR i:=1 TO N DO
BEGIN
read(f1, data[i]);
out[i]:=0;
END;
close(f1);
count:=0;
FOR M:=2 to N-1 do
BEGIN
before:=M-1;
after:=N-M;
if after>before then
d:=before
else
d:=after;
REPEAT
if (data[M-d]=data[M+d]) and (2*data[M-d]<data[M])
then
BEGIN
out[M]:=1;
count:=count+1;
d:=0;
END
else
d:=d-1;
UNTIL d=0;
END;
assign(f2, 'seti.out');
rewrite(f2);
writeln(f2, count);
for M:=2 TO N-1 DO
if out[M]=1 then
writeln(f2, M);
close(f2);
halt(0);
END.