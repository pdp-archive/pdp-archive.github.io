program lusi;
var
Userfile:text;
N,I,S,max1,max2,max3,maxsum:longint;
Row:Array[1..10000] of longint;
txt:string;
begin
   max1:=0;
   max2:=0;
   max3:=0;
   maxsum:=0;
   assign(Userfile,'sch.in');
   reset(Userfile);
   readln(Userfile,N);
   for I:=1 to N do
   begin
      read(Userfile,S);
      Row[S]:=Row[S]+1
   end;
   close(Userfile);
   for I:=1 to 10000 do
   begin
      if maxsum<Row[I] then
      begin
         maxsum:=Row[I];
         max1:=I;
      end;
   end;
   Row[max1]:=0;
   maxsum:=0;
   for I:=1 to 10000 do
   begin
      if Row[I]>maxsum then
      begin
         maxsum:=Row[I];
         max2:=I;
      end;
   end;
   Row[max2]:=0;
   maxsum:=0;
   for I:=1 to 10000 do
   begin
      if Row[I]>maxsum then
      begin
         maxsum:=Row[I];
         max3:=I;
      end;
   end;
   assign(Userfile,'sch.out');
   rewrite(Userfile);
   writeln(Userfile,max1,' ',max2,' ',max3);
   close(Userfile);
   halt(0);
end.
