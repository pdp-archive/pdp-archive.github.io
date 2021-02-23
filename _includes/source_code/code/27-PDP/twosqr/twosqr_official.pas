program project1;

var
  kol, max, N, i, ans, r1, j: longint;
  infile, outfile: Text;
begin
  Assign(infile, 'twosqr.in');
  Reset(infile);
  Assign(outfile, 'twosqr.out');
  Rewrite(outfile);
  read(infile, kol);
  for j := 1 to kol do
  begin
    read(infile, N);
    i := 0;
    ans := 0;
    max := N div 2;
    while i * i <= max do
    begin
      r1 := round(sqrt(N - i * i));
      if (i * i + r1 * r1 = N) then
        ans := ans + 1;
      Inc(i);
    end;
    writeln(outfile, ans);
  end;
  Close(infile);
  Close(outfile);
  halt(0);
end.
