<img width="807" height="794" alt="image" src="https://github.com/user-attachments/assets/3fe21f4a-5967-4a1b-98b2-b7e1666cac22" /><img width="1141" height="276" alt="image" src="https://github.com/user-attachments/assets/c8b5f76e-29bb-48ad-a201-ac0f0217ac9d" />

```mermaid
classDiagram
    class Dokument {
        - naziv : String
        - datumKreiranja : Date
        - datumPoslednjegSnimanja : Date
        - lokacija : String
        - autor : String
        + sacuvajUDropBox()
        + sacuvajUOneDrive()
    }

    class Pasus {
        - slika : Slika
    }

    class Recenica {
    }

    class Token {
        - stil : String
    }

    class NizKaraktera {
        - sadrzaj : String
    }

    class CeoBroj {
        - vrednost : int
    }

    class Razmak {
    }

    class Tacka {
    }

    class Slika {
        - putanja : String
    }

    Dokument "1" --> "1..*" Pasus
    Pasus "1" --> "1..*" Recenica
    Recenica "1" --> "1..*" Token
    Pasus --> Slika : "moze biti linkovan"
    Token <|-- NizKaraktera
    Token <|-- CeoBroj
    Token <|-- Razmak
    Token <|-- Tacka


```
