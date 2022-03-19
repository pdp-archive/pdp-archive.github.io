program LimniKarla123;

var
  fin, fout: Text;
  N, M, i, ii, jj, j, k, p: integer;
  karo: array[1..100, 1..100] of integer;
  todo: array[1..2, 1..1000] of integer;
  b: char;
begin
  k := 0;
  Assign(fin, 'karla.in');
  reset(fin);
  read(fin, N);
  read(fin, b);
  readln(fin, M);
  for i := 1 to N do
    for j := 1 to N do
    begin
      read(fin, karo[i, j]);
      read(fin, b);
    end;
  Close(fin);
   {for i:=1 to N do
   begin
   for j:=1 to N do
   begin
   if karo[i,j]>M then
   karo[i,j]:=-1
   else
   karo[i,j]:=-2;
   end;
   end;
   }
  for i := 1 to N do
    for j := 1 to N do
      if karo[i, j] > M then
      begin
        k := k - 1;
        ii := i;
        jj := j;
        p := 0;
        repeat
          if P >= 1 then
          begin
            ii := todo[1, p];
            jj := todo[2, p];
            p := p - 1;
          end;
          if (jj <> N) and (karo[ii, jj + 1] > M) then
          begin
            p := p + 1;
            todo[1, p] := ii;
            todo[2, p] := jj + 1;
          end;
          if (ii <> N) and (karo[ii + 1, jj] > M) then
          begin
            p := p + 1;
            todo[1, p] := ii + 1;
            todo[2, p] := jj;
          end;
          if (jj <> 1) and (karo[ii, jj - 1] > M) then
          begin
            p := p + 1;
            todo[1, p] := ii;
            todo[2, p] := jj - 1;
          end;
          if (ii <> 1) and (karo[ii - 1, jj] > M) then
          begin
            p := p + 1;
            todo[1, p] := ii - 1;
            todo[2, p] := jj;
          end;
          karo[ii, jj] := k;
        until P = 0;
      end;
  Assign(fout, 'karla.out');
  rewrite(fout);
  writeln(fout, ABS(k));
  // writeln (ABS (k));
  Close(fout);
end.
