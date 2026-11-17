(* Καρύδης Θρασύβουλος (ΓΕΛ Κέρκυρας) *)

PROGRAM evripos;

USES
  SysUtils;

CONST
  MaxPoints = 204;
  INF = 100000;

TYPE
  coordinates = record
    X:integer;
    Y:integer;
  end;
  Coordsys = array[1..MaxPoints] of coordinates;

VAR
  N,
  I,J,K,
  d:integer;
  q:real;
  input,output:text;
  points:Coordsys;
  l:array[1..MaxPoints,1..MaxPoints] of real;

FUNCTION dist(a,b:coordinates):real; //euclidean distiance//
BEGIN
  dist:=sqrt(sqr(a.X-b.X)+sqr(a.Y-b.Y))
END;

PROCEDURE swap(VAR a, b: coordinates);
VAR
  t: integer;
BEGIN
  t := a.X;
  a.X := b.X;
  b.X := t;
  t := a.Y;
  a.Y := b.Y;
  b.Y := t;
END;

FUNCTION Split(start, stop: integer): integer;
VAR
  left, right: integer;
  pivot: integer;
BEGIN
  pivot := points[start].X;
  left := start + 1;
  right := stop;
  WHILE left <= right DO BEGIN
    WHILE (left <= stop) AND (points[left].X < pivot) DO
      left := left + 1;
    WHILE (right > start) AND (points[right].X >= pivot) DO
      right := right - 1;
    IF left < right THEN
      swap(points[left], points[right]);
  END;
  swap(points[start], points[right]);
  Split := right
END;

PROCEDURE QuicksortRecur(start, stop: integer);
VAR
  splitpt: integer;
BEGIN
  IF start < stop THEN BEGIN
    splitpt := Split(start, stop);
    QuicksortRecur(start, splitpt-1);
    QuicksortRecur(splitpt+1, stop);
  END
END;

PROCEDURE Quicksort(size: Integer; VAR points: Coordsys);
BEGIN
  QuicksortRecur(1, size)
END;

BEGIN
  assign(input,'evripos.in');
  reset(input);
  readln(input,N);
  N:=N+2;
  points[1].X:=0;
  points[1].Y:=0;
  FOR I := 2 TO N-1 DO
    readln(input,points[I].X,points[I].Y);
  close(input);
  Quicksort(N, points);
  FOR J := 2 TO N DO
    FOR I := 1 TO J-1 DO
      IF (I=1) AND (J=2) THEN
        l[I,J] := dist(points[i],points[j])
      ELSE IF J>I+1 THEN
        l[I,J]:= l[I,J-1] + dist(points[J-1],points[J])
      ELSE BEGIN
        l[I,J] := INF;
        FOR K := 1 TO I-1 DO BEGIN
          q:= l[K,I] + dist(points[K],points[J]);
          IF q < l[I,J] THEN
            l[I,J]:= q;
        END;
      END;
  d:= Round( l[n-1,n] + dist(points[n-1],points[n]));
  assign(output,'evripos.out');
  rewrite(output);
  writeln(output,d);
  close(output);
end.

