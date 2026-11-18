PROGRAM dekathlo; (* by Nikos Adamopoulos *)
VAR
  f1,f2: Text;
  i, athlites, nikites, best_epid, best_prosp: Integer;
  epid: array [1..4000, 1..2] of Integer;

BEGIN
  assign(f1, 'dekathlo.txt');
  reset(f1);
  readln(f1, athlites);
  readln(f1, epid[1,1], epid[1,2]);
  best_epid:=epid[1,1];
  best_prosp:=epid[1,2];
  nikites:=1;  
 
  for i:=2 to athlites do
    begin
      readln(f1, epid[i,1], epid[i,2]);
      if epid[i,1]>best_epid then
        begin
          best_epid:=epid[i,1];
          best_prosp:=epid[i,2];
          nikites:=1;
        end
      else if epid[i,1]=best_epid then
        begin
          if epid[i,2]<best_prosp then
            begin
              best_prosp:=epid[i,2];
              nikites:=1;
            end 
          else if epid[i,2]=best_prosp then
            nikites:=nikites+1; 
        end;
    end;
  Close(f1);
    
  assign(f2, 'nikites.txt');
  rewrite(f2);
  writeln(f2, nikites);
  for i:=1 to athlites do
    if (epid[i,1]=best_epid) and (epid[i,2]=best_prosp) then
      writeln(f2, i);
  Close(f2);
  halt(0);
END.

