<img width="1025" height="263" alt="image" src="https://github.com/user-attachments/assets/59db68c7-2bf7-4942-8e80-716de7814fab" />

```mermaid
classDiagram
classDiagram
    class Dokument {
        - naziv : String
        - datumKreiranja : Date
        - datumIzmene : Date
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
        - tipLinije : String
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

    GrafickiObjekat "1" --> "0..1" StilLinije : stilLinije
    GrafickiObjekat "1" --> "0..1" StilIspune : stilIspune

```
