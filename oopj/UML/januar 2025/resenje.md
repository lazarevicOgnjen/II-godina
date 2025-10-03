```mermaid

classDiagram

class Fakultet {
+int PiB
+string naziv
+string adresa
}

class Katedra{
+string sef
+string naziv
+string spisak projekata
}

class Nastavnicko_zvanje{
+docent
+vanredni profesor
+redovni profesor
}

class Clanovi{
+string saradnici
+string nastavnici
+string laboranti
}

class Predmet{
+string naziv predmeta
+int sifra predmeta
+string skolska godina
+int redni broj semestra
}

class Student{
+string ime
+string prezime
+int indeks
+int godina rodjenja
+date datum upisa
+string smer
}

class Nastavnik{
+string ime
+string prezime
+string titula
+int broj projekata
}

```
