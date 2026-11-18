PROGRAM apollon; (* by Nikos Adamopoulos *)
CONST
  maxt=650;
VAR
  town_dist:array[1..maxt,1..maxt] OF LongInt ;
  distance:array[1..maxt] OF LongInt;
  changed:array[1..maxt] OF Boolean;
  i,j,a,b,L,N,from,dest,ct,cd,nd:LongInt;
  chans:Boolean;
  inpFile:TextFile;
  outFile:Textfile;

BEGIN
  assign(inpFile, 'apollon.in');
  assign(outFile, 'apollon.out');
  reset(inpFile);
  readln(inpFile, N, L);
  FOR i:=1 TO N DO
    BEGIN
      distance[i]:=MaxInt;
      changed[i]:=false;
      FOR j:=1 TO N DO town_dist[i,j]:=MaxInt;
    END;

  FOR i:=1 TO L do
    BEGIN
      readln(inpFile, a, b, cd);
      town_dist[a,b]:=cd;
      town_dist[b,a]:=cd;
    END;

  readln(inpFile, from, dest);
  close(inpFile);

  ct:=from;
  cd:=0;
  distance[ct]:=cd;
  REPEAT
    changed[ct]:=false;
    FOR i:=1 TO N DO
      BEGIN
        nd:=cd+town_dist[ct,i];
        IF nd<distance[i] THEN
          BEGIN
            distance[i]:=nd;
            changed[i]:=true;
          END;
        END;

    chans:=false;
    i:=0;
    REPEAT
      i:=i+1;
      IF changed[i] THEN
        BEGIN
          chans:=true;
          ct:=i;
          cd:=distance[i];
        END;
    UNTIL chans or (i=N);
  UNTIL not chans;

  rewrite(outFile);
  writeln(outFile,distance[dest]);
  close(outFile);
  halt(0);
END.

