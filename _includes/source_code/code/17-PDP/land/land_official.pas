PROGRAM idioktisies; (* by Nikos Adamopoulos *)
VAR
  f:Text;
  ic, p1, p2, i, j:longint;
  pososto: array[1..50000] of double;
  min1, min2, kostos: double;

BEGIN
  assign(f, 'land.in');
  reset(f);
  readln(f, ic);
  FOR i:=1 TO ic DO
    readln(f, pososto[i]);
  close(f);
  assign(f, 'land.out');
  rewrite(f);

  kostos:=0;
  FOR i:=ic DOWNTO 2 DO
    BEGIN
      IF pososto[1]<pososto[2] THEN
        BEGIN
          min1:=pososto[1]; p1:=1;
          min2:=pososto[2]; p2:=2;
        END
      ELSE
        BEGIN
          min1:=pososto[2]; p1:=2;
          min2:=pososto[1]; p2:=1;
        END;

      FOR j:=3 TO i DO
        IF pososto[j]<min1 THEN
          BEGIN
            min2:=min1; p2:=p1;
            min1:=pososto[j]; p1:=j;
          END
        ELSE IF pososto[j]<min2 THEN
               BEGIN
                 min2:=pososto[j]; p2:=j;
               END;

      kostos:=kostos+min1+min2;
      pososto[p1]:=min1+min2;
      pososto[p2]:=pososto[i];
    END;

  kostos:=kostos+0.00001;
  writeln(f, kostos:2:2);
  close(f);
  halt(0);
END.

