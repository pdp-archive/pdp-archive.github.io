program Fire;

type
   myint=0..1001;
   ccc=0..1000000;
var
   xx,yy,M,N,i,j:myint;
   C:ccc;
   infile,outfile:text;
   ch:char;
   pin:array[0..1001,0..1001] of boolean;
{-----------------BURN-----------------}
PROCEDURE burn(x,y:myint);
begin
  if pin[x,y] then
     begin
       pin[x,y]:=false;
       C:=C+1;
       burn(x-1,y);
       burn(x+1,y);
       burn(x,y+1);
       burn(x,y-1);
     end;
end;
{=================MAIN=================}
BEGIN
   C:=0;
   {Read the data}
   assign(infile,'fire.in');
   reset(infile);
   readln(infile,N,M);
   readln(infile,xx,yy);
   for i:= 1 to M do
      begin
         for j:= 1 to N do
         begin
            read(infile,ch);
            if ch='@' then
               pin[i,j]:=false
            else
               pin[i,j]:=true;
         end;
         readln(infile);
      end;
   close(infile);

   {Topo8etisi vraxwn stis akres}
   for j:= 0 to N+1 do
      begin
         pin[0,j]:=false;
         pin[M+1,j]:=false;
     end;
   for i:= 0 to M+1 do
      begin
         pin[i,0]:=false;
         pin[i,N+1]:=false;
      end;

   burn(yy,xx);

   {Create the output}
   assign(outfile,'fire.out');
   rewrite(outfile);
   writeln(outfile,C);
   close(outfile);
END.
