program Noimosini;

var
  f1, f2: Text;
  N, M, i, d, before, after, Count: integer;
  Data, out: array[1..10000] of integer;
begin
  Assign(f1, 'seti.in');
  reset(f1);
  readln(f1, N);
  for i := 1 to N do
  begin
    read(f1, Data[i]);
    out[i] := 0;
  end;
  Close(f1);
  Count := 0;
  for M := 2 to N - 1 do
  begin
    before := M - 1;
    after := N - M;
    if after > before then
      d := before
    else
      d := after;
    repeat
      if (Data[M - d] = Data[M + d]) and (2 * Data[M - d] < Data[M]) then
      begin
        out[M] := 1;
        Count := Count + 1;
        d := 0;
      end
      else
        d := d - 1;
    until d = 0;
  end;
  Assign(f2, 'seti.out');
  rewrite(f2);
  writeln(f2, Count);
  for M := 2 to N - 1 do
    if out[M] = 1 then
      writeln(f2, M);
  Close(f2);
  halt(0);
end.