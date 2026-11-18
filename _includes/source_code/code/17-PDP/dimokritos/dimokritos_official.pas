PROGRAM dimokritos; (* by Nikos Adamopoulos *)
VAR
  Sensors:array[-700..700,-700..700] of longint;
  Recordings:array[0..2000000] of longint;
  MoveChars:array[1..2000000] of char;
  SCount,MCount,i,j:longint;
  x,y:integer;
  f:Text;


PROCEDURE RecordTheMove(x, y:integer);
VAR code:longint;
BEGIN
  code:=Sensors[x,y];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x-1,y-1];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x-1,y];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x-1,y+1];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x,y+1];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x+1,y+1];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x+1,y];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x+1,y-1];
  Recordings[code]:=Recordings[code]+1;
  code:=Sensors[x,y-1];
  Recordings[code]:=Recordings[code]+1;
END;


BEGIN
  FOR i:=-700 TO 700 DO
    FOR j:=-700 TO 700 DO
      Sensors[i,j]:=0; 
      
  FOR i:=0 TO 2000000 DO Recordings[i]:=0; assign(f,'dimokritos.in');
  
  reset(f);
  readln(f,SCount); 
  
  FOR i:=1 TO SCount DO
    BEGIN
      readln(f,x,y);
      Sensors[x,y]:=i;
    END;
    
  readln(f,MCount);
  IF MCount>0 THEN
    BEGIN
      readln(f,MoveChars);
      x:=0; y:=0;
      RecordTheMove(x,y); 
      
      FOR i:=1 TO MCount DO
        BEGIN
          CASE MoveChars[i] OF
            'R': x:=x+1;
            'L': x:=x-1;
            'U': y:=y+1;
            'D': y:=y-1;
          END;
          RecordTheMove(x,y);
        END;
    END;
  Close(f); 
 
  assign(f,'dimokritos.out');
  rewrite(f);
  If MCount=0 THEN
    writeln(f,-1)
  ELSE
    FOR i:=1 TO SCount DO
      IF Recordings[i]>0 THEN writeln(f,i,' ',Recordings[i]); 
      
  Close(f);
  halt(0);
END.

