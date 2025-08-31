<br><br>

> **stare generacije -** [**YouTube playlist**](https://www.youtube.com/playlist?list=PLFUwkwonRM--gjbTwQO8l-7XWcsd17Iln)

<br>

```mermaid
flowchart LR

classDef komanda fill:#3396D3, stroke:#000, stroke-width: 2px, color:#fff
classDef klase fill:#E43636, stroke:#000, stroke-width: 2px, color:#fff
classDef vrednosni fill:#556B2F, stroke:#000, stroke-width: 2px, color:#fff
classDef referentni fill:#F97A00, stroke:#000, stroke-width: 2px, color:#fff

subgraph Klase

end

subgraph Komande
k1[Console.WriteLine]:::komanda
k2[Console.Write]:::komanda
end

subgraph TipoviPodataka
  subgraph Vrednosni
    v1[struct]:::vrednosni
    v2[enum]:::vrednosni
  end
  subgraph Referentni
   r1[class]:::referentni
  end
end
```
