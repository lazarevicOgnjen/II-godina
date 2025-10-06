<img width="1228" height="322" alt="image" src="https://github.com/user-attachments/assets/0c8f4550-5495-4aed-ac6e-e587dd2c7de4" />

```mermaid
classDiagram
    class Dokument {
        - naziv : String
        - datumKreiranja : Date
        - datumIzmene : Date
        + dodajObjekat(objekat: GrafickiObjekat)
        + dodajStil(stil: Stil)
    }

    class GrafickiObjekat {
        + crtaj()
    }

    class Tacka {
        - x : float
        - y : float
    }

    class Polilinija {
        - tacke : List~Tacka~
    }

    class Pravougaonik {
        - x : float
        - y : float
        - sirina : float
        - visina : float
    }

    class Elipsa {
        - centarX : float
        - centarY : float
        - poluosaX : float
        - poluosaY : float
    }

    class Poligon {
        - tacke : List~Tacka~
    }

    class Tekst {
        - sadrzaj : String
        - pozicija : Tacka
    }

    class Stil {
    }

    class StilLinije {
        - tip : String
        - debljina : float
        - boja : String
    }

    class StilIspune {
        - boja : String
        - srafura : String
        - tekstura : String
    }

    Dokument "1" --> "1..*" GrafickiObjekat
    Dokument "1" --> "0..*" Stil

    GrafickiObjekat <|-- Tacka
    GrafickiObjekat <|-- Polilinija
    GrafickiObjekat <|-- Pravougaonik
    GrafickiObjekat <|-- Elipsa
    GrafickiObjekat <|-- Poligon
    GrafickiObjekat <|-- Tekst

    Stil <|-- StilLinije
    Stil <|-- StilIspune

    GrafickiObjekat "1" --> "0..1" StilLinije : koristi
    GrafickiObjekat "1" --> "0..1" StilIspune : koristi

```
