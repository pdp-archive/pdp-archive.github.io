(* NAME: SOFIA MARAGOU
 * TASK: PULSARS
 * LANG: PASCAL
 *)
program pdp_pulsars;
var userfile:text;
  st:string;
  location,error:integer;
  s:array[1..1000000,1..2] of word;
  k:array[1..1000000] of longint;
  z,b,x1,y1,a,us,d,i,max,min,j,n:longint;
  bmax,flag:boolean;
  smax,sy:real;
  temp:longint;

begin
  Assign(userfile,'pulsars.in');
  reset(userfile);
  readln(userfile,st);
  val(st,n,error);

  for i:=1 to n do
  begin
    readln(userfile,st);
    location:=pos(' ', st);
    val(copy(st,1,location-1),s[i,1],error);
    val(copy(st,location+1,length(st)-location),s[i,2],error);
  end;
  close(userfile);

  max:=1;min:=1;
  for i:=1 to n do
  begin
    if s[i,2] > s[max,2] then
      max:=i
    else
      begin
        if s[i,2]=s[max,2] then
          if s[i,1]>s[max,1] then max:=i;
      end; {else}

    if s[i,2]<s[min,2] then
      min:=i
    else
      begin
        if s[i,2]=s[min,2] then
          if s[i,1]>s[min,1] then min:=i;
      end; {else}
  end; {for}
  for i:=1 to n do k[i]:=0;

  d:=1; k[d]:=min; bmax:=false; flag:=false; us:=min; smax:=-2;
  while (flag=false) do
  begin
    if bmax=false then
    begin
      smax:=-2;
      for a:=1 to n do
      begin
        if a<>us then
          if s[a,2]>=s[us,2] then
          begin
            x1:=(s[a,1]-s[us,1]);
            y1:=(s[a,2]-s[us,2]);
            sy:=x1/sqrt(sqr(x1)+sqr(y1));
            if sy>smax then
            begin
              smax:=sy; b:=a;
            end;{if}
          end;{if}
      end; {for}

      us:=b; d:=d+1; k[d]:=us;
      if us=max then bmax:=true;
    end {if}
    else
    begin
      smax:=2;
      for a:=1 to n do
      begin
        if a<>us then
          if s[a,2]<=s[us,2] then
          begin
            x1:=(s[a,1]-s[us,1]);
            y1:=(s[a,2]-s[us,2]);
            sy:=x1/sqrt(sqr(x1)+sqr(y1));
            if sy<smax then
            begin
              smax:=sy; b:=a;
            end;{if}
          end;{if}
      end; {for}

      us:=b;
      if us=min then
        flag:=true
      else
        begin
          d:=d+1;
          k[d]:=us;
        end;
    end ;{else}
  end; {while}

  for z:=2 to d do
  begin
    for i:=d downto z do
      if k[i]<k[i-1] then
      begin
        temp:=k[i]; k[i]:=k[i-1];k[i-1]:=temp;
      end;
  end;

  assign(userfile,'pulsars.out');
  rewrite(userfile);
  writeln(userfile,d);
  for i:=1 to d do writeln(userfile,k[i]);
  close(userfile);

end.
