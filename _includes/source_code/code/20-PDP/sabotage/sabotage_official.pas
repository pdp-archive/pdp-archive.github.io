(* ΔΗΜΗΤΡΗΣ ΜΟΥΔΗΛΟΣ ΓΕΛ ΑΝΑΒΥΣΣΟΥ *)
     
Program sabotage;
var
  width,height,mines,mine_x,mine_y,i:longint;
  start_x,start_y,end_x,end_y: longint;
  map:array [1..1000,1..1000] of longint;
  c_x:array[1..10000] of longint ;
  c_y:array[1..10000] of longint ;
  t_x:array[1..10000] of longint;
  t_y:array[1..10000] of longint ;
  N,temp_step,step:longint;
  x,y,tx,ty:longint;
  ok:boolean;
  fdata,fdata2:text;

Begin
  assign (fdata,'sabotage.in');
  reset (fdata);
  read (fdata,width);
  read (fdata,height);
  read (fdata,mines);
  if mines<>0 then
    begin
      for i:=1 to mines do
        begin
          read (fdata,mine_x);
          read (fdata,mine_y);
          map[mine_x,mine_y]:=-1;
        end;
    end;
    
  read (fdata,start_x);
  read (fdata,start_y);
  read (fdata,end_x);
  read (fdata,end_y);
  
  c_x[1]:=end_x;
  c_y[1]:=end_y;
  t_x[1]:=end_x;
  t_y[1]:=end_y;
  N:=1;
  temp_step:=0;
  step:=1;
  ok:=true;
  
  While (map[start_x,start_y]=0) and (ok=true) do
    begin
      ok:=false;
      For i:=1 to step do
        begin
          if c_x[i]+1<=width then
            begin
              if (map[c_x[i]+1,c_y[i]]=0) then
                begin
                  map[c_x[i]+1,c_y[i]]:=N;
                  temp_step:=temp_step+1;
                  t_x[temp_step]:=c_x[i]+1;
                  t_y[temp_step]:=c_y[i];
                  ok:=true;
                end;
            end;
          if c_x[i]-1>0 then
            begin
              if (map[c_x[i]-1,c_y[i]]=0) then
                begin
                  map[c_x[i]-1,c_y[i]]:=N;
                  temp_step:=temp_step+1;
                  t_x[temp_step]:=c_x[i]-1;
                  t_y[temp_step]:=c_y[i];
                  ok:=true;
                end;
            end;
          if c_y[i]-1>0 then
            begin
              if (map[c_x[i],c_y[i]-1]=0) then
                begin
                  map[c_x[i],c_y[i]-1]:=N;
                  temp_step:=temp_step+1;
                  t_x[temp_step]:=c_x[i];
                  t_y[temp_step]:=c_y[i]-1;
                  ok:=true;
                end;
            end;
        end;
      For i:=1 to temp_step do
        begin
          c_x[i]:=t_x[i];
          c_y[i]:=t_y[i];
        end;
      step:=temp_step;
      N:=N+1;
      temp_step:=0;
    end;
    
  close(fdata);
  map[end_x,end_y]:=0;
  assign (fdata2,'sabotage.out');
  rewrite (fdata2);
  
  if map[start_x,start_y]<>0 then
    begin
      x:=start_x;
      y:=start_y;
      writeln(fdata2,map[start_x,start_y]+1);
      writeln(fdata2,x,' ',y);
      For i:=map[start_x,start_y] downto 1 do
        begin
          tx:=x;
          ty:=y;
          ok:=false;
          if y+1<=height then
            begin
              if (ok=false) and (map[x,y+1]=i-1) then
                begin
                  ty:=y+1;
                  writeln(fdata2,x,' ',ty);
                  ok:=true;
                end;
            end;
          if x-1>0 then
            begin
              if (ok=false) and (map[x-1,y]=i-1) then
                begin
                  tx:=x-1;
                  writeln(fdata2,tx,' ',y);
                  ok:=true;
                end;
            end;
          if x+1<=width then
            begin
              if (ok=false) and (map[x+1,y]=i-1) then
                begin
                  tx:=x+1;
                  writeln(fdata2,tx,' ',y);
                  ok:=true;
                end;
            end;
          x:=tx;
          y:=ty;
        end;
    end
  else
    begin
      writeln(fdata2,'0');
    end;
  close(fdata2);
  halt(0);
End.

