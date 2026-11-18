PROGRAM apollon; (* by Nikos Adamopoulos *)
VAR
  portenergy:array[1..2000000] OF LongInt ;
  maxports, firstport, curenergy, curport, steps, i, ein, eout: LongInt;
  done:Boolean;
  inpFile:TextFile;
  outFile:Textfile;

BEGIN
  assign(inpFile, 'cyclotron.in');
  assign(outFile, 'cyclotron.out');
  reset(inpFile);
  readln(inpFile, maxports);
  FOR i:=1 TO maxports DO
    BEGIN
      readln(inpfile, ein, eout);
      portenergy[i]:=ein-eout;
    END;
  close(inpFile);

  firstport:=0;
  done:=false;
  REPEAT
    firstport:=firstport+1;
    curport:=firstport;
    curenergy:=0;
    steps:=0;
    REPEAT
      curenergy:=portenergy[curport]+curenergy;
      steps:=steps+1;
      curport:=curport+1;
      IF curport>maxports THEN curport:=1;
    UNTIL (curenergy<0) or (steps=maxports);
    IF (steps=maxports) and (curenergy>=0) THEN done:=true;
  UNTIL done or (firstport=maxports);

  rewrite(outFile);
  IF done THEN
    writeln(outFile,firstport)
  ELSE
    writeln(outFile,0);
  close(outFile);
  halt(0);
END.

