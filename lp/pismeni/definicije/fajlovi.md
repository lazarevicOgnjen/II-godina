```vhdl
file Fout: TEXT open WRITE_MODE is "output";
   file Fin: TEXT open READ_MODE is "input";
   variable current_wline : line;
   variable current_rline : line; 
   variable current_aux : std_logic_vector(3 downto 0);
```

<br>

- `file Fout: TEXT open WRITE_MODE is "output";`
Deklariše fajl `Fout` tipa TEXT koji se otvara za **pisanje**. Ime fajla na disku je "output". Kroz ovaj fajl se upisuju rezultati simulacije.
- `file Fin: TEXT open READ_MODE is "input";`
Deklariše fajl `Fin` tipa TEXT koji se otvara za **čitanje**. Ime fajla na disku je "input". Iz ovog fajla se čitaju ulazni test vektori.
- `variable current_wline : line;`
Promenljiva tipa `line` koja predstavlja jednu liniju teksta namenjenu za pisanje u fajl (`Fout`). Koristi se kao pomoć kod formiranja linije pre upisa.
- `variable current_rline : line;`
Promenljiva tipa `line` koja predstavlja jednu liniju teksta pročitanu iz fajla (`Fin`). Koristi se za čitanje i parsiranje jedne linije ulaznog fajla.
- `variable current_aux : std_logic_vector(3 downto 0);`
Promenljiva u koju se smešta konvertovani ulazni vektor (logički signal) iz teksta pročitanog iz fajla.

Ovaj deo koda predstavlja osnovnu pripremu za rad sa tekstualnim fajlovima u testbenču koristeći VHDL paket `textio`. Omogućava čitanje linija iz ulaznog fajla, konverziju u logičke signale, i upisivanje podataka u izlazni fajl u obliku linija teksta.
