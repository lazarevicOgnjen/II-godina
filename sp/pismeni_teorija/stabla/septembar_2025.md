<img width="1153" height="221" alt="image" src="https://github.com/user-attachments/assets/718f98c7-2461-4c95-b279-d4a9f0332679" />

<br><br>

# Rešenje zadatka: Izgradnja Min-Heap stabla iz niza A = [1, 5, 6, 2, 7, 3, 9, 4]

---

## 1. **Uvodni pojmovi**

- **Min-Heap** je binarno stablo koje ispunjava sledeće uslove:
  - **Strukturni**: stablo je skoro potpuno (svi nivoi su potpuni osim poslednjeg, koji se popunjava sleva nadesno).
  - **Svojstvo redosleda**: vrednost svakog čvora je manja ili jednaka vrednostima njegove dece.

- **Niz (array) reprezentacija stabla**:
  - Za čvor na poziciji `i` (0-indeksiran):
    - Levi sin: `2*i + 1`
    - Desni sin: `2*i + 2`
    - Roditelj: `(i-1)//2`

---

## 2. **Početni niz**

A = [1, 5, 6, 2, 7, 3, 9, 4]

---

## 3. **Proces izgradnje Min-Heap stabla**

Heap se gradi **postepeno**, dodavanjem elemenata jednog po jednog i **sprovođenjem operacije "heapify-up"** (ponišavanje nagore) ako je potrebno.

### Korak 0: Prazno stablo

```

```

### Korak 1: Dodaj 1

```
    1
```

### Korak 2: Dodaj 5

```
    1
   /
  5
```

### Korak 3: Dodaj 6

```
    1
   / \
  5   6
```

### Korak 4: Dodaj 2

```
     1
   /   \
  5     6
 /
2
```

→ **Heapify-up**: 2 < 5 ⇒ zameni

```
     1
   /   \
  2     6
 /
5
```

### Korak 5: Dodaj 7

```
     1
   /   \
  2     6
 / \
5   7
```

### Korak 6: Dodaj 3

```
     1
   /   \
  2     6
 / \   /
5   7 3
```

→ **Heapify-up**: 3 < 6 ⇒ zameni

```
     1
   /   \
  2     3
 / \   /
5   7 6
```

### Korak 7: Dodaj 9

```
     1
   /   \
  2     3
 / \   / \
5   7 6   9
```

### Korak 8: Dodaj 4

```
     1
   /   \
  2     3
 / \   / \
5   7 6   9
/
4
```

→ **Heapify-up**: 4 < 5 ⇒ zameni

```
     1
   /   \
  2     3
 / \   / \
4   7 6   9
/
5
```

→ **Heapify-up**: 4 < 2 ⇒ zameni

```
     1
   /   \
  4     3
 / \   / \
2   7 6   9
/
5
```

---

## 4. **Konačno Min-Heap stablo (nakon svih koraka)**

```
       1
     /   \
    4     3
   / \   / \
  2   7 6   9
 /
5
```

---

## 5. **Niz (array) reprezentacija konačnog stabla**

Heap = [1, 4, 3, 2, 7, 6, 9, 5]

---

## 6. **Operacija pretrage Trazi(S, E)**

- **Cilj**: Proveriti da li se element `E` nalazi u heap-u `S`.
- **Algoritam**:
  1. Počni od korena (indeks 0).
  2. Ako je trenutni čvor jednak `E` → pronađeno.
  3. Ako je trenutni čvor **veći** od `E` → prekini granu (u Min-Heap-u deca su veća).
  4. Ako je trenutni čvor **manji** od `E` → nastavi pretragu u levom i desnom podstablu.

### Primer: Trazi([1, 4, 3, 2, 7, 6, 9, 5], 6)

- Koren = 1 < 6 → idi deci
- Levi sin = 4 < 6 → idi deci
- Levi sin = 2 < 6 → idi deci
- Levi sin = 5 < 6 → idi deci
- 5 nema decu → nema više puta
- Desni sin = 7 > 6 → prekini
- Vrati se na čvor 3
- Levi sin = 6 == 6 → **pronađeno**

---

## 7. **Zaključak**

- **Min-Heap** je uspešno izgrađen iz niza A = [1, 5, 6, 2, 7, 3, 9, 4]
- **Konačni niz stabla**: [1, 4, 3, 2, 7, 6, 9, 5]
- **Pretraga** u heap-u koristi svojstva stabla da efikasno odbaci grane koje ne mogu sadržati traženi element.
