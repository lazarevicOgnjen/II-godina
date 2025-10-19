<img width="1029" height="437" alt="image" src="https://github.com/user-attachments/assets/ec85010f-fc0d-4a29-8cff-460f8e47701d" />

```mermaid
classDiagram
    class Fakultet {
        PIB : String
        naziv : String
        adresa : String
        katedre : List~Katedra~
    }

    class Katedra {
        naziv : String
        spisakProjekata : List~String~
        šef : Nastavnik
        saradnici : List~Saradnik~
        nastavnici : List~Nastavnik~
        laboranti : List~Laborant~
        predmeti : List~Predmet~
    }

    class Osoba {
        <<abstract>>
        ime : String
        prezime : String
    }

    class Student {
        ime : String
        prezime : String
        indeks : String
        godinaRodjenja : int
        datumUpisa : Date
        smer : String
        predmeti : List~Predmet~
    }

    class Nastavnik {
        ime : String
        prezime : String
        titula : String
        brojProjekata : int
        predmeti : List~Predmet~
        deloviPredmeta : List~DeoPredmeta~
    }

    class Saradnik {
        administracije : List~Administracija~
    }

    class Laborant {
    }

    class Predmet {
        naziv : String
        sifra : String
        skolskaGodina : String
        semestar : int
        delovi : List~DeoPredmeta~
        studenti : List~Student~
    }

    class DeoPredmeta {
        naziv : String
        nastavnik : Nastavnik
    }

    class Administracija {
        opis : String
        saradnik : Saradnik
        predmet : Predmet
    }

    Fakultet "1" *-- "1..*" Katedra
    Katedra "1" -- "1" Nastavnik : šef
    Katedra "1" *-- "1..*" Saradnik
    Katedra "1" *-- "1..*" Nastavnik
    Katedra "1" *-- "1..*" Laborant
    Katedra "1" *-- "1..*" Predmet
    Nastavnik "1..*" -- "1..*" Predmet
    Predmet "1" *-- "1..*" DeoPredmeta
    DeoPredmeta "1" -- "1" Nastavnik
    Saradnik "1" *-- "1..*" Administracija
    Administracija "1" -- "1" Predmet
    Student "1..*" -- "1..*" Predmet

    Osoba <|-- Student
    Osoba <|-- Nastavnik
    Osoba <|-- Saradnik
    Osoba <|-- Laborant
```
