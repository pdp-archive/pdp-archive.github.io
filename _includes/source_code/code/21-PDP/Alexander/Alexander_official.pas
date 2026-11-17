(* Ιωσήφ Σάκος (1ο ΕΠΑΛ Ηρακλείου) *)

program alexander;
var 
  A:text;
  L,C:integer;
  M,N:char;
  S:ansistring;

begin
  assign(A,'Alexander.in');
  reset(A);
  readln(A,L,C);
  readln(A,M);
  close(A);
  if M='P' then N:='V' else N:='P';
  S:=M+N;
  repeat
    S:=S+S;
  until length(S)>=C;
  setlength(S,C);
  S:=S+#$0A+N+S;
  setlength(S,C*2+1);
  S:=S+#$0A;
  repeat
    S:=S+S;
  until length(S)>=(C+1)*L;
  setlength(S,(C+1)*L);
  assign(A,'Alexander.out');
  rewrite(A);
  write(A,S);
  close(A);
  halt;
end.

