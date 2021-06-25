{ OBI2005            }
{ Tarefa Bafo        }
{ r. anido           }

program bafo;

var
	num_teste, r, a, b : integer;
	tot_a, tot_b, i	 : longint;

begin
	num_teste := 0;
	readln(r);
	while (r>0) do begin
		{ reinicializa totais }
		tot_a := 0; tot_b := 0;
		for i:=1 to r do begin
			{ lê valores de cada rodada e totaliza }
			readln(a, b);
			tot_a := tot_a + a;
			tot_b := tot_b + b;
		end;
		num_teste := num_teste + 1;
		{ imprime resultado }
		writeln('Teste ', num_teste);
		if (tot_a > tot_b) then
			writeln('Aldo')
		else
			writeln('Beto');
		writeln;
		readln(r);
	end;
end.
