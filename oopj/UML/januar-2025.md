<img width="1029" height="437" alt="image" src="https://github.com/user-attachments/assets/ec85010f-fc0d-4a29-8cff-460f8e47701d" />

```mermaid
classDiagram
    class Fakultet {
        -String PIB
        -String naziv
        -String adresa
        +List~Katedra~ katedre
    }

    class Katedra {
        -String naziv
        -List~String~ spisakProjekata
        +Nastavnik šef
        +List~Saradnik~ saradnici
        +List~Nastavnik~ nastavnici
        +List~Laborant~ laboranti
        +List~Predmet~ predmeti
    }

    class Osoba {
        <<abstract>>
        -String ime
        -String prezime
    }

    class Student {
        -String indeks
        -int godinaRodjenja
        -Date datumUpisa
        -String smer
        +List~Predmet~ predmeti
    }

    class Nastavnik {
        -String titula
        -int brojProjekata
        +List~Predmet~ predmeti
        +List~DeoPredmeta~ deloviPredmeta
    }

    class Saradnik {
        +List~Administracija~ administracije
    }

    class Laborant {
    }

    class Predmet {
        -String naziv
        -String sifra
        -String skolskaGodina
        -int semestar
        +List~DeoPredmeta~ delovi
        +List~Student~ studenti
    }

    class DeoPredmeta {
        -String naziv
        +Nastavnik nastavnik
    }

    class Administracija {
        -String opis
        +Saradnik saradnik
        +Predmet predmet
    }

    Fakultet "1" *-- "1..*" Katedra : sadrži
    Katedra "1" -- "1" Nastavnik : šef
    Katedra "1" *-- "1..*" Saradnik : članovi
    Katedra "1" *-- "1..*" Nastavnik : članovi
    Katedra "1" *-- "1..*" Laborant : članovi
    Katedra "1" *-- "1..*" Predmet : zadužena za
    Nastavnik "1..*" -- "1..*" Predmet : predaje
    Predmet "1" *-- "1..*" DeoPredmeta : sadrži
    DeoPredmeta "1" -- "1" Nastavnik : drži
    Saradnik "1" *-- "1..*" Administracija : radi
    Administracija "1" -- "1" Predmet : vezana za
    Student "1..*" -- "1..*" Predmet : sluša

    Osoba <|-- Student
    Osoba <|-- Nastavnik
    Osoba <|-- Saradnik
    Osoba <|-- Laborant
```
