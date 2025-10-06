<img width="1141" height="276" alt="image" src="https://github.com/user-attachments/assets/c8b5f76e-29bb-48ad-a201-ac0f0217ac9d" />

```mermaid

classDiagram
    direction BT

    class Dokument {
        +naziv: string
        +datumKreiranja: date
        +datumSnimanja: date
        +lokacija: string
        +autor: Autor
        +pasusi: Pasus[*]
        +cloudovi: CloudStorage[*]
    }

    class Pasus {
        +recenice: Recenica[1..*]
        +linkovanaSlika: Slika[0..1]
    }

    class Recenica {
        +tokeni: Token[*]
    }

    class Token {
        <<abstract>>
        +sadrzaj: string
        +stil: Stil
    }

    class KarakterNiz {
    }

    class CeoBroj {
    }

    class Razmak {
    }

    class Tacka {
    }

    class Stil {
        +font: string
        +velicina: int
        +boja: string
        +bold: bool
        +italic: bool
    }

    class Slika {
        +putanja: string
    }

    class Autor {
        +ime: string
        +prezime: string
        +email: string
    }

    class CloudStorage {
        <<interface>>
        +sacuvaj(dok: Dokument)
    }

    class DropBox {
        +sacuvaj(dok: Dokument)
    }

    class OneDrive {
        +sacuvaj(dok: Dokument)
    }

    Dokument "1" -- "*" Pasus : sadrži
    Dokument "*" -- "1" Autor : napisao
    Dokument "*" -- "*" CloudStorage : čuva se u
    Pasus "1" -- "*" Recenica : ima
    Pasus "*" -- "0..1" Slika : linkovan
    Recenica "1" -- "*" Token : sadrži
    Token <|-- KarakterNiz
    Token <|-- CeoBroj
    Token <|-- Razmak
    Token <|-- Tacka
    Token "*" -- "1" Stil : opisan
    CloudStorage <|.. DropBox
    CloudStorage <|.. OneDrive

```
