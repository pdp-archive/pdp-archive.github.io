program ypsos;
var
   board:array [1..1000000] of longint;
   N,max,i,counter:longint;
   infile,outfile:text;
begin
   assign(infile,'xxx.in');
   reset(infile);
   readln(infile,N);
   for i:=1 to N do
      read(infile,board[i]);
   max :=board[N];
   counter:=1;
   for i:=N-1 downto 1 do
   begin
      if board[i]>max then
      begin
         max:=board[i];
         counter:=counter+1;
      end;
   end;
   assign(outfile,'xxx.out');
   rewrite (outfile);
   writeln(outfile,counter);
   close(infile);
   close(outfile);
end.
