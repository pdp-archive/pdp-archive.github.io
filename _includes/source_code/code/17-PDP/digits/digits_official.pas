PROGRAM pollaplasiasmos; (* by Nikos Adamopoulos *)
USES math;
VAR
  f:Text;
  m, m1, m2, maxtry:longint;
  mdigits, alldigits: array[0..9] of boolean;
  IsOK: boolean;


PROCEDURE check_m_number(m:longint; VAR valid:boolean);
VAR d, i:integer;
BEGIN
  mdigits[0]:=true;
  FOR i:=1 TO 9 DO
    mdigits[i]:=false;

  valid:=true;
  WHILE valid and (m>0) DO
    BEGIN
      d:=m mod 10;
      m:=m div 10;
      IF mdigits[d] THEN
        valid:=false
      ELSE
        mdigits[d]:=true;
    END;
END;


PROCEDURE check_number(n:longint; VAR valid:boolean);
VAR d, i:integer;
BEGIN
  valid:=true;
  WHILE valid and (n>0) DO
    BEGIN
      d:=n mod 10;
      n:=n div 10;
      IF alldigits[d] THEN
        valid:=false
      ELSE
        alldigits[d]:=true;
    END;
END;


PROCEDURE NewTry;
VAR i:integer;
BEGIN
  FOR i:=0 TO 9 DO
    alldigits[i]:=mdigits[i];
END;


BEGIN
  assign(f, 'digits.in');
  reset(f);
  readln(f, m);
  close(f);
  assign(f, 'digits.out');
  rewrite(f);

  check_m_number(m,IsOK);
  IF IsOK THEN
    BEGIN
      m1:=0;
      maxtry:=ceil(98765432/m);
      IsOK:=false;
      WHILE (m1<maxtry) and (not IsOK) DO
        BEGIN
          NewTry;
          m1:=m1+1;
          check_number(m1,IsOK);
          IF ISOK THEN
            BEGIN
              m2:=m*m1;
              check_number(m2,IsOK);
            END;
        END;
    END;

  IF IsOK THEN writeln(f, m1, ' ', m2) ELSE writeln(f, 0);
  close(f);
  halt(0);
END.

