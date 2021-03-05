(* Αλέξανδρος Μπιμπίκος *)

program pdp2011;
var
  N,xi,i,min,x1:integer;
  profit,cur_profit:real;
  input_file,output_file:Text;
begin
  assign(input_file,'profit.in');
  reset(input_file);
  readln (input_file,N);
  profit:=1;
  read(input_file,x1);
  min:=x1;
  for i:=2 to N do
    begin
      read(input_file,xi);
      if(xi<min) then
        begin
          min:=xi;
        end
      else
        begin
          cur_profit:=xi/min;
          if (cur_profit>profit) then
            profit:=cur_profit;
        end;
    end;
  assign(output_file,'profit.out');
  rewrite(output_file);
  writeln (output_file,profit:0:3);
  close(input_file);
  close(output_file);
end.
