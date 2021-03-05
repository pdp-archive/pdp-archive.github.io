program ishare;

var
  share: Text;
  sum, i, n, mo: longint;
  kerdos: array[1 .. 1000000] of longint;
  elegxos: boolean;

begin
  Assign(share, 'share.in');
  reset(share);
  readln(share, n);
  for i := 1 to n do
  begin
    readln(share, kerdos[i]);
    sum := sum + kerdos[i];
  end;
  Close(share);

  mo := round(sum / 3);
  if mo < sum / 3 then
    mo := mo + 1;
  repeat
    elegxos := true;
    i := 1;
    sum := 0;
    while ((sum + kerdos[i]) <= mo) and (n - i >= 2) do
    begin
      sum := sum + kerdos[i];
      i := i + 1;
    end;
    sum := 0;
    while ((sum + kerdos[i]) <= mo) and (n - i >= 1) do

    begin
      sum := sum + kerdos[i];
      i := i + 1;
    end;
    sum := 0;
    if (i < n) then
      for i := i to n do
        sum := sum + kerdos[i]
    else
    if kerdos[n] > mo then
      mo := kerdos[n];
    if sum > mo then
      elegxos := false;
    mo := mo + 1;
  until elegxos = true;
  mo := mo - 1;
  Assign(share, 'share.out');
  rewrite(share);
  writeln(share, mo);
  Close(share);
  halt(0);
end.
