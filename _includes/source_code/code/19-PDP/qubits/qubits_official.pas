(*
 Πρόκειται για έναν κλασσικό αλγόριθμο γνωστό ως Αλγόριθμο του Ανόι (Hanoi). Υλοποιείται με τυπικό κώδικα αρκετών γραμμών ή σε λίγες γραμμές με αναδρομή. Αποτελεί κλασσικό παράδειγμα διδασκαλίας της χρησιμότητας της Αναδρομής. Σχολικό Βιβλίο Γ΄ Ε.Λ. Ανάπτυξη Εφαρμογών σε Προγραμματιστικό Περιβάλλον (ΕΠΥ), Τετράδιο Μαθητή, σελ 104. (Υλοποίηση Pascal σελ. 106)
*)

program qubits (Indata, Outdata);
const
  st1='A';
  st2='B';
  st3='C';
var
  n: integer;
  Indata, Outdata: text;


procedure move (n:integer; sta, stb, stc:char);
begin
  if n=1 then
  begin
    writeln (Outdata, sta, ' ', stc);
  end
  else
  begin
    move (n-1, sta, stc, stb);
    writeln (Outdata, sta, ' ', stc);
    move (n-1, stb, sta, stc);
  end;
end;


begin
  assign (Indata, 'qubits.in');
  reset (Indata);
  readln (Indata, n);
  close (Indata);
  assign (Outdata, 'qubits.out');
  rewrite (Outdata);
  move (n, st1, st2, st3);
  close (Outdata);
  halt (0);
end.

