```vhdl
readline(Fin, current_rline);
read(current_rline, current_aux); 
	ABCD_TB<=current_aux;
```

<br>

1. `readline(Fin, current_rline);` – iz fajla `Fin` se pročita cela jedna linija i ta linija se smešta u promenljivu `current_rline` tipa `line`.
2. `read(current_rline, current_aux);` – iz te linije se pročita jedan element (na primer broj, string ili neki drugi tip podataka) i smešta u promenljivu `current_aux`.
3. `ABCD_TB <= current_aux;` – vrednost iz `current_aux` se dodeljuje signalu `ABCD_TB`.

Dakle, prvo se uzme cela linija teksta iz fajla, pa se iz nje pročita određeni podatak koji se potom prosleđuje signalu.
