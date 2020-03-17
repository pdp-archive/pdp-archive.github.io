(* Αλέξανδρος Μπιμπίκος *)

program pdp23b;
var
  N,i,j,cur_pos:longint;
  a,b:array [1..100000] of longint;
  input_file,output_file:text;
begin
  assign (input_file,'snow_run.in');
  reset (input_file); 
  readln (input_file,N);
  for i:=1 to N do
    begin
      readln (input_file,cur_pos);
      for j:=i-1 downto cur_pos do
        begin
          a[j+1]:=a[j];
        end;
      a[cur_pos]:=i;
    end; 
  close(input_file); 
  for i:=1 to N do
    begin
      b[a[i]]:=i;
    end; 
  assign(output_file,'snow_run.out');
  rewrite (output_file);
  for i:=1 to N do
    begin
      writeln(output_file,b[i]);
    end; 
  close(output_file);
end.
