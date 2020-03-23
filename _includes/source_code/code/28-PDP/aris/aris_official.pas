Program Aris_solve (Indata, Outdata);
Var
Indata, Outdata: text;
n, m, i, x, min, max, count: longint;
R: array [1..1000000] of longint;
begin
	assign (Indata, 'aris.in');
	reset (Indata);
	readln (Indata, n, m);
	for i:=1 to n do
	begin
		read (Indata, x);
		R[x]:=R[x] + 1;
	end;
	close (Indata);
	min:=1000001;
	max:=0;
	for i:=1 to m do
	begin
		if R[i] <> 0 then
			count:=count + 1;
		if (R[i] < min) AND (R[i] <> 0) then
			min:=R[i];
		if R[i] > max then
			max:=R[i];
	end;
	assign (Outdata, 'aris.out');
	rewrite (Outdata);
	writeln (Outdata, count,' ', min,' ', max);
	close (Outdata);
	halt {0}
end.

