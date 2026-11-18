PROGRAM taksidi; (* by Nikos Adamopoulos *)
VAR
  f:Text;
  pc, start, pnow, r, i:longint;
  pratirio: array[1..5000000] of longint;

BEGIN
  assign(f, 'stations.in');
  reset(f);
  readln(f, pc);
  FOR i:=1 TO pc DO
    readln(f, pratirio[i]);
  close(f);
  assign(f, 'stations.out');
  rewrite(f);

  start:=0;
  REPEAT
    start:=start+1;
    r:=0;
    pnow:=start;
    REPEAT
      r:=r+pratirio[pnow]-100;
      pnow:=pnow+1;
      IF pnow>pc THEN pnow:=1;
    UNTIL (pnow=start) or (r<0);
  UNTIL (pnow=start) and (r>=0);

  writeln(f, start);
  close(f);
  halt(0);
END.

