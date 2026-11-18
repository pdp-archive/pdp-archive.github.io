PROGRAM acropolis; (* by Nikos Adamopoulos *)
VAR
  f: Text;
  i, j, tmp, pos, pieces, tosort, p: Integer;
  weights: array [1..1000] of Integer;
  monades: array [1..1000] of Boolean;

BEGIN
  assign(f, 'acropolis.in');
  reset(f);
  readln(f, pieces);
  tosort:=0;
  for i:=1 to pieces do
    begin
      readln(f,p);
      if p=1 then
        monades[i]:=true
      else
        begin
          tosort:=tosort+1;
          weights[tosort]:=p;
          monades[i]:=false;
        end;
    end;
  Close(f);

  for i:=1 to tosort-1 do
    for j:=1 to tosort-i do
      if weights[j]>weights[j+1] then
        begin
          tmp:=weights[j];
          weights[j]:=weights[j+1];
          weights[j+1]:=tmp;
        end;

  assign(f, 'acropolis.out');
  rewrite(f);
  pos:=0;
  for i:=1 to pieces do
    begin
      if monades[i] then
        writeln(f,1)
      else
        begin
          pos:=pos+1;
          writeln(f, weights[pos]);
        end;
    end;
  Close(f);
  halt(0);
END.

