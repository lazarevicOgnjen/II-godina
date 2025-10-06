<img width="1012" height="401" alt="image" src="https://github.com/user-attachments/assets/10a0782f-eb1f-44ca-be0b-a92641782203" />

```mermaid
classDiagram
    class Banka {
        - naziv : String
        - PIB : String
        - adresa : String
        + povuciNovac(racun: Racun, iznos: float)
        + uplatiNovac(racun: Racun, iznos: float)
        + transfer(sa: Racun, na: Racun, iznos: float)
    }

    class Centrala {
    }

    class Filijala {
        - sef : String
        + zatvoriFilijalu()
    }

    class Ekspozitura {
    }

    class Bankomat {
        - kolicinaNovca : float
    }

    class Korisnik {
        - ime : String
        - prezime : String
        - JMBG : String
    }

    class Racun {
        - brojRacuna : String
        - brojNerealizovanihCekova : int
        - dozvoljeniMinus : float
        - stanje : float
        - tip : String
    }

    class TekuciRacun {
    }

    class DevizniRacun {
        - valuta : String
        - kurs : float
    }

    Banka "1" --> "1" Centrala
    Centrala "1" --> "1..*" Filijala
    Filijala "1" --> "0..*" Ekspozitura
    Ekspozitura "0..1" --> Bankomat
    Filijala "1" --> "0..*" Korisnik
    Ekspozitura "1" --> "0..*" Korisnik
    Korisnik "1" --> "1..*" Racun
    Racun <|-- TekuciRacun
    Racun <|-- DevizniRacun

```
