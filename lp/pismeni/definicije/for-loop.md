```vhdl

```

<br>

- Petlja `for i in 0 to 15 loop` ponavlja kod unutar  nje 16 puta (za i=0 do i=15).
- Svaki put:

1. `readline(Fin, current_rline);` čita jednu liniju iz ulaznog fajla `Fin` u promenljivu `current_rline`.
2. `read(current_rline, current_aux);` iz te linije čita jedan podatak i smešta u `current_aux`.
3. `ABCD_TB <= current_aux;` dodeljuje taj podatak signalu `ABCD_TB`.
4. `wait for 10 ns;` pauzira izvršavanje petlje na 10 nanosekundi (simulaciono vreme).
5. Zatim sa `write` funkcijama sklapa liniju teksta: prvo piše `"ABCD="`, pa vrednost `ABCD_TB`, zatim `"F="`, pa vrednost `F_TB`.
6. `writeline(Fout, current_wline);` upisuje tu liniju u izlazni fajl `Fout`.

Dakle, petlja čita podatke iz fajla, dodeljuje signalima, pravi tekstualni zapis i upisuje ga u drugi fajl, sa pauzom između svake iteracije.
