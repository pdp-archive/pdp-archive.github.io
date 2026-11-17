(* Καρύδης Θρασύβουλος (3ο ΓΕΛ Κέρκυρας) *)

program hydroloGIS;
uses
  SysUtils;
var
  a,b,N,M:integer;
  V_R:longint;
  V:longint;
  input,output:text;

function factorial(k:integer):real;
begin
  if ( k=1 ) then
    factorial := 1
  else
    factorial:= factorial(k-1)*k;
end;


function sum(k:integer):longint;
var
  i:integer;
  s:longint;
begin
  s:=0;
  for i := 1 to k do
    s:= s + i;
  sum:=s;
end;

begin
  assign(input,'hydrologis.in');
  reset(input);
  readln(input,N);
  readln(input,M);
  readln(input,V_R);
  readln(input,a);
  readln(input,b);
  V:= round(V_R + a*factorial(N)/1000000 - b*sum(M));
  assign(output,'hydrologis.out');
  rewrite(output);
  writeln(output,V);
  close(output);
end.

