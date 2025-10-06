<img width="1029" height="437" alt="image" src="https://github.com/user-attachments/assets/ec85010f-fc0d-4a29-8cff-460f8e47701d" />


```mermaid
classDiagram
    class Fakultet {
        - PIB : String
        - naziv : String
        - adresa : String
    }

    class Katedra {
        - naziv : String
        - projekti : List~String~
    }

    class Nastavnik {
        - ime : String
        - prezime : String
        - titula : String
        - brojProjekata : int
    }

    class Saradnik {
        - ime : String
        - prezime : String
    }

    class Laborant {
        - ime : String
        - prezime : String
    }

    class Student {
        - ime : String
        - prezime : String
        - indeks : String
        - godinaRodjenja : int
        - datumUpisa : Date
        - smer : String
    }

    class Predmet {
        - naziv : String
        - sifra : String
        - skolskaGodina : String
        - semestar : int
    }

    class DeoPredmeta {
        - nazivDeo : String
    }

    Fakultet "1" --> "1..*" Katedra
    Katedra "1" --> "1" Nastavnik : sef
    Katedra "1" --> "0..*" Nastavnik
    Katedra "1" --> "0..*" Saradnik
    Katedra "1" --> "0..*" Laborant
    Katedra "1" --> "1..*" Predmet
    Nastavnik "1" --> "1..*" Predmet : predaje
    Predmet "1" --> "0..*" DeoPredmeta
    DeoPredmeta "1" --> "1" Nastavnik : drzi
    Saradnik "1" --> "1" Predmet : administracija
    Student "1" --> "1..*" Predmet : slusa

```
