<img width="1180" height="294" alt="image" src="https://github.com/user-attachments/assets/1a73ac2b-4f6d-4bea-96b3-f22d879aed66" />

<br><br>

Razbijamo zadatak na četiri dela:

1. Formiranje **Max-Heap** stabla iz niza A  
2. Grafički prikaz stabla **posle svakog koraka**  
3. **Statička** i **dinamička (povezana)** reprezentacija konačnog stabla  
4. **Pseudokod** funkcije koja pronalazi koren podstabla čija je vrednost jednaka zadatoj vrednosti E  

---

### 1. Niz A i pravilo Max-Heap
Niz:  
A = (8, 12, 10, 15, 7, 5, 6, 24, 21)  
Indeksi: 0  1   2   3   4  5  6   7   8  

Pravilo Max-Heap:  
`A[i] ≥ A[2i+1]` i `A[i] ≥ A[2i+2]`

---

### 2. „Bottom-up“ izgradnja Max-Heap (sift-down)
Počinjemo od poslednjeg čvora koji ima decu (index = ⌊n/2⌋ – 1 = 3) i idemo unazad do korena.

| Korak | Index | Niz (pre) | Akcija | Niz (posle) |
|-------|-------|-----------|--------|-------------|
| 0 | – | (8,12,10,15,7,5,6,24,21) | – | – |
| 1 | 3 | ...15,24,21... | 15 ↔ 24 | (8,12,10,**24**,7,5,6,**15**,21) |
| 2 | 2 | ...10,6... | OK | – |
| 3 | 1 | ...12,7,5... | OK | – |
| 4 | 0 | 8,12,24... | 8 ↔ 24 | (**24**,12,**8**,15,7,5,6,10,21) |
| 5 | 0 (ponovo) | 8,15,6... | 8 ↔ 15 | (24,12,**15**,**8**,7,5,6,10,21) |

Konačni **Max-Heap** niz:  
`H = (24, 12, 15, 8, 7, 5, 6, 10, 21)`

---

### 3. Grafički prikaz konačnog stabla
```
        24
      /    \
    12      15
   / \     /  \
  8   7   5   6
 / \
10  21
```

---

### 4. Reprezentacije stabla

#### 4.1 Statička (sekvencijalna) – već je data gore:
`H = [24, 12, 15, 8, 7, 5, 6, 10, 21]`

#### 4.2 Dinamička (povezana) – lista čvorova:
```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
};
```

Raspored pokazivača odgovara slici iz tačke 3.

---

### 5. Pseudokod: pronalazak korena podstabla sa vrednošću E
```python
function findRootSubtree(H, E):
    n = length(H)
    for i = 0 .. n-1:
        if H[i] == E:
            return i          # i je index čvora koji je koren traženog podstabla
    return -1                 # vrednost E se ne pojavljuje
```

Objašnjenje:  
- U nizovskoj reprezentaciji binarnog stabla **svaki element je koren nekog podstabla**  
- Stoga je dovoljna jedna linearna pretraga po nizu  

---

### Rezime
- Max-Heap niz: `[24, 12, 15, 8, 7, 5, 6, 10, 21]`  
- Stablo: vidi crtež iz tačke 3  
- Reprezentacije: niz (statička) i pokazivačka struktura (dinamička)  
- Za pronalaženje korena podstabla sa vrednošću E koristi se dati `findRootSubtree` algoritam
