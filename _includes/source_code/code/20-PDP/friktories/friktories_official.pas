(* Μιχάλης Γαλιανάκης (2ο ΤΕΕ Ρεθύμνου) *)

program friktories(input,output) ;
const
  stath=25 ;
  
type
  typos=0..1000000 ;
  egrafi=record
    a:byte ;
    syn:typos ;
  end ;

var
  ar1:text ;
  pin:array[1..stath]of egrafi ;
  backup:egrafi ;
  a,w,i:byte ;
  fr:string ;
 
begin
  for i:=1 to stath do
    begin
      pin[i].a:=i+127 ;
      pin[i].syn:=0 ;
    end ;
  assign(ar1,'friktories.in') ;
  reset(ar1) ;
  while not eof(ar1) do
    begin
      repeat
        read(ar1,fr) ;
        w:=length(fr) ;
        for i:=1 to w do
          begin
            a:=ord(fr[i]) ;
            if (a<128)or(a>151) then
              begin
                if a=32 then
                  a:=152
                else
                  a:=0 ;
              end ;
            if a<>0 then
              pin[a-127].syn:=pin[a-127].syn+1 ;
          end ;
      until w<>255 ;
      readln(ar1) ;
    end ;
  close(ar1) ;
  w:=1 ;
  repeat
    w:=w+1 ;
    a:=1 ;
    for i:=stath downto w do
      if pin[i-1].syn<pin[i].syn then
        begin
          a:=0 ;
          backup:=pin[i] ;
          pin[i]:=pin[i-1] ;
          pin[i-1]:=backup ;
        end ;
  until (a=1)or(w=stath) ;
  assign(ar1,'friktories.out') ;
  rewrite(ar1) ;
  for i:=1 to stath do
    begin
      if pin[i].a=152 then
      pin[i].a:=32 ;
      writeln(ar1,chr(pin[i].a),' ',pin[i].syn);
    end ;
  close(ar1) ;
  halt(0) ;
end.

