<img width="1141" height="276" alt="image" src="https://github.com/user-attachments/assets/c8b5f76e-29bb-48ad-a201-ac0f0217ac9d" />

```mermaid
classDiagram
    class Dokument {
        -String naziv
        -Date datumKreiranja
        -Date datumPoslednjegSnimanja
        -Lokacija lokacija
        -Autor autor
        +sacuvajUDropBox()
        +sacuvajUOneDrive()
    }

    class Pasus {
        -Slika linkovanaSlika
    }

    class Recenica {
        -List~Token~ tokeni
    }

    class Token {
        -String vrednost
        -TokenTip tip
        -Stil stil
    }

    class Stil {
        -String font
        -int velicinaFonta
        -boolean jePodebljan
        -boolean jeKurziv
        -String boja
    }

    class TokenTip {
        <<enumeration>>
        TEKST
        CEO_BROJ
        RAZMAK
        TACKA
    }

    class Slika {
        -String putanja
        -String naziv
        -int visina
        -int sirina
    }

    class Lokacija {
        -String putanja
    }

    class Autor {
        -String ime
        -String prezime
        -String email
    }

    class DropBoxService {
        +sacuvajDokument(Document doc)
    }

    class OneDriveService {
        +sacuvajDokument(Document doc)
    }

    Dokument "1" *-- "1..*" Pasus
    Pasus "1" *-- "1..*" Recenica
    Recenica "1" *-- "1..*" Token
    Token "1" --> "1" Stil
    Token "1" --> "1" TokenTip
    Pasus "1" --> "0..1" Slika
    Dokument "1" --> "1" Lokacija
    Dokument "1" --> "1" Autor
    Dokument ..> DropBoxService
    Dokument ..> OneDriveService
```
