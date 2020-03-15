program hydrogen;

type section_errors_diad=record
  section_ID: integer;
  errors: integer;
end;

var f:text;
    c_count: integer;
    i,j,k: integer;
    a: array[1..10000] of section_errors_diad;
    b: section_errors_diad;
    max_a: integer;
    c1,c2,cc,c_errors: integer;

begin
  max_a:=0;
  assign(f,'hydrogen.in');
  reset(f);
  readln(f,c_count);

  for i:=1 to c_count do
  begin
    readln(f,b.section_ID,b.errors);
    if b.errors<>0 then
    begin
      case max_a of           { ***** binary search algorithm ***** }
      0: a[1]:=b;
      1: if b.errors<=a[1].errors then 
           a[2]:=b
         else 
         begin
           a[2]:=a[1];
           a[1]:=b;
         end;
      else
        begin
          if b.errors<=a[max_a].errors then 
            a[max_a+1]:=b
          else if b.errors>=a[1].errors then 
          begin
            for j:=max_a downto 1 do a[j+1]:=a[j];
            a[1]:=b;
          end
          else
          begin
            c1:=1;
            c2:=max_a;
            while c1+1<c2 do
            begin
              cc:=round((c1+c2)/2);
              c_errors:=b.errors-a[cc].errors;
              if c_errors<0 then c1:=cc
              else if c_errors>0 then c2:=cc
              else 
              begin
                c1:=cc;
                c2:=c1+1;
              end;
            end;
            for j:=max_a downto c2 do a[j+1]:=a[j];
            a[c2]:=b;
          end;
        end;
      end;               { **** END of binary search algorithm **** }
      inc(max_a);
    end;
  end;

  close(f);

  c2:=1;
  repeat
    c1:=c2;
    while ((a[c1].errors=a[c2+1].errors) and (c2<max_a)) do inc(c2);
    if c2>c1 then for i:=c1+1 to c2 do
    begin
      j:=c1;
      while ((a[i].section_ID>a[j].section_ID) and (j<i)) do inc(j);
      if j<i then
      begin
        b:=a[i];
        for k:=i downto j+1 do a[k]:=a[k-1];
        a[j]:=b;
      end;
    end;
    inc(c2);
  until c2>max_a;

  assign(f,'hydrogen.out');
  rewrite(f);
  writeln(f,max_a);
 
  for i:=1 to max_a do writeln(f,a[i].section_ID);
  close(f);
end.
