<img width="1127" height="432" alt="image" src="https://github.com/user-attachments/assets/0cee3868-fbe3-4eb5-b181-b7e65bf2dc1e" />

```mermaid
classDiagram
    class EvropskoPrvenstvo {
        - instance : EvropskoPrvenstvo
        + getInstance() EvropskoPrvenstvo
    }

    class Reprezentacija {
        - naziv : String
        - sifraDrzave : String
        - bojaDresa : String
    }

    class Fudbaler {
        - brojDresa : int
        - ime : String
        - prezime : String
        - godiste : int
    }

    class AktivniIgrac {
        - brojPogodaka : int
    }

    class Golman {
        - brojOdbranjenihUdaraca : int
    }

    class Grupa {
        - oznakaGrupe : String
    }

    class Utakmica {
        - faza : String
        - poeniDomacin : int
        - poeniGost : int
        - grad : String
    }

    EvropskoPrvenstvo "1" --> "1..*" Grupa
    Grupa "1" --> "1..*" Reprezentacija
    Reprezentacija "1" --> "1..*" Fudbaler
    Fudbaler <|-- AktivniIgrac
    Fudbaler <|-- Golman
    EvropskoPrvenstvo "1" --> "1..*" Utakmica
    Utakmica "1" --> "1" Reprezentacija : domacin
    Utakmica "1" --> "1" Reprezentacija : gost

```
