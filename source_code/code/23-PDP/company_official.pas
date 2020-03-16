(* Δημήτρης Μπεχράκης *)

program company;
var
  p,N,x,i,r_m,r_f:LongInt;
  input_file,output_file:Text;
  S:string[2];
  R:array[1..400000] of LongInt;
  G:array[0..400000] of boolean;
  M:array[0..400000] of LongInt;
  F:array[0..400000] of LongInt;

procedure Calc(p: LongInt);
var
  Next: LongInt;
begin
  Next:=R[p];
  if Next<>0 then
    begin
      if M[Next]+F[Next]=0 then Calc(Next);
      if G[Next]=true then
        begin
          M[p]:=M[Next]+1;
          F[p]:=F[Next];
        end
      else
        begin
          M[p]:=M[Next];
          F[p]:=F[Next]+1;
        end;
    end
  else
    begin
      M[p]:=0;
      F[p]:=0;
    end;
end;

begin
  assign(input_file,'company.in');
  reset(input_file);
  readln (input_file,N);
  for i:=1 to N do
    begin
      read(input_file,R[i]);
      read(input_file,S);
      if S[2]='m' then G[i]:=true else G[i]:=false;
    end;
  r_m:=0;
  r_f:=0;
  for i:=1 to N do
    begin
      Calc(i);
      if G[i]=true then r_f:=r_f+F[i] else r_m:=r_m+M[i];
    end;
  assign(output_file,'company.out');
  rewrite(output_file);
  writeln (output_file,r_m-r_f);
  close(input_file);
  close(output_file);
end.
