(* Ελευθερίου Θεόδωρος (1ο Γυμνάσιο Μυτιλήνης) *)

program Pdp_2;
var
  a:array[1..1000,1..3] of integer;
  N:integer; {plithos aeroplanwn}
  kk,i,plane1,plane2:integer;
  in_text,out_text:text;
  min,theirdistance:real;

function distance(x1,y1,z1,x2,y2,z2:integer):real;
begin
  distance:=sqrt(sqr(x1-x2)+ sqr(y1-y2)+sqr(z1-z2));
end;

procedure findnearest(k:integer;var kk:integer;var apostasi:real);
var
  x:real;
  i,thesi:integer;
begin
  apostasi:=10001;
  for i:=1 to N do
    begin
     if i<>k then
       begin
         x:=distance(a[i,1],a[i,2],a[i,3],a[k,1],a[k,2],a[k,3]);
         if x<apostasi then
           begin
             apostasi:=x;
             thesi:=i;
           end;
       end;
  end;
  kk:=thesi;
end;

BEGIN
  assign(in_text,'airforce.in');
  reset(in_text);
  readln(in_text,N);
  for i:=1 to N do readln (in_text,a[i,1],a[i,2],a[i,3]);
  close(in_text);
  for i:=1 to N do
    begin
      kk:=0; theirdistance:=0;
      findnearest(i,kk,theirdistance);
      if theirdistance<min then
        begin
          min:=theirdistance;
          plane1:=i;
          plane2:=kk;
        end;
    end;
  assign(out_text,'airforce.out');
  rewrite(out_text);
  writeln(out_text,plane1,' ',plane2);
  close(out_text);
END

