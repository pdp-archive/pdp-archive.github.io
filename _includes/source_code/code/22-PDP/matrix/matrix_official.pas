(*
USER: 22pdp16
LANG: PASCAL
TASK: matrix
*)
Program Matrix(Indata, Outdata);
Var
Indata, Outdata: text;
j, i, K, N: longint;
C: char;
S: array [1..1024] of char;
T: array [1..65536] of char;
flag:boolean;
begin
   assign (Indata, 'matrix.in');
   reset (Indata);
   readln (Indata, K);
   for j:=1 to K do
   begin
      read (Indata, C);
      S[j]:=C;
   end;
   readln (Indata);
   readln (Indata, N);
   for i:=1 to N do
   begin
      read (Indata, C);
      T[i]:=C;
   end;
   close (Indata);
   if K=N then
   begin
      flag:=false;
      i:=2; (* GIATI tha to meivsei apo to N an einai isa N & K *)
      j:=1;
      while (S[j] = T[j]) AND (j<=k) do
         j:=j+1;
      if j=K+1 then
         flag:=true;
   end
   else
   begin
      flag:=false;
      i:=1;
      while (i <= (N-K)) AND (flag=false) do
      begin
         j:=1;
         while S[j] = T[i+j-1] do
            j:=j+1;
         if j=K+1 then
            flag:=true;
         i:=i+1;
      end;
   end;
   assign (Outdata, 'matrix.out');
   rewrite (Outdata);
   if flag=true then
   begin
      i:=i-1;
      writeln (Outdata, i);
   end
   else
   begin
      writeln (Outdata, 'F');
   end;
   close (Outdata);
   halt (0);
end.
