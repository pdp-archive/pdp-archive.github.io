program diagonismos;
var
iddomes,outdomes:Text;
i,N,M,elfor,f1,f2:longint ;
foreis:array [1..100000] of byte ;
begin
assign (iddomes, 'domes.in' ) ;
reset (iddomes);
readln (iddomes, N,M);
writeln(N,' ',M);
elfor := N;
for i := 1 to N do
foreis[i] := 0 ;
for i := 1 to M do
begin
readln (iddomes, f1,f2);
if foreis[f1] < 2 then
begin
foreis[f1] := foreis[f1] +1 ;
if foreis[f1] = 2 then
elfor := elfor -1 ;
end ;
if foreis[f2] < 2 then
begin
foreis[f2] := foreis[f2] +1 ;
if foreis[f2] = 2 then
elfor := elfor - 1 ;
end ;
end;
assign (outdomes, 'domes.out' ) ;
rewrite (outdomes) ;
writeln (outdomes,elfor);
close (iddomes) ;
close (outdomes) ;
end.
