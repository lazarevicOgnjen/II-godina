<img width="1718" height="357" alt="image" src="https://github.com/user-attachments/assets/7820f230-9536-41e8-b93a-8316c0628ab2" />

<br><br>

# Rešenje zadatka iz binarnog pretrage stabla (MaxHeap)

## 1. Formiranje MaxHeap stabla S iz niza A = (13, 2, 1, 18, 7, 25, 8)

### Početni niz:
```
A = [13, 2, 1, 18, 7, 25, 8]
```

### Proces izgradnje MaxHeap-a korak po korak:

**Korak 0:** Prazno stablo

**Korak 1:** Dodavanje 13
```
    13
```

**Korak 2:** Dodavanje 2
```
    13
   /
  2
```

**Korak 3:** Dodavanje 1
```
    13
   / \
  2   1
```

**Korak 4:** Dodavanje 18
```
    13
   / \
  2   1
 /
18
```
→ Heapify: 18 > 13, zamena
```
    18
   / \
  2   1
 /
13
```

**Korak 5:** Dodavanje 7
```
    18
   / \
  2   1
 / \
13  7
```

**Korak 6:** Dodavanje 25
```
    18
   / \
  2   1
 / \ /
13 7 25
```
→ Heapify: 25 > 18, zamena
```
    25
   / \
  2   1
 / \ /
13 7 18
```

**Korak 7:** Dodavanje 8
```
    25
   / \
  2   1
 / \ / \
13 7 18 8
```

## 2. Konačni izgled MaxHeap stabla S:
```
        25
       / \
      2   1
     / \ / \
    13 7 18 8
```

## 3. Opis postupka brisanja čvora iz binarnog pretrage stabla

### Postupak brisanja čvora iz MaxHeap-a:
1. **Pronalaženje čvora**: Pronađi čvor koji želiš da obrišeš
2. **Zamena sa poslednjim**: Zameni vrednost tog čvora sa vrednošću poslednjeg čvora u stablu
3. **Uklanjanje poslednjeg**: Ukloni poslednji čvor iz stabla
4. **Heapify down**: Pozovi heapify down operaciju da bi se očuvao MaxHeap svojstvo

## 4. Brisanje čvora sa vrednošću 2 (korak po korak)

### Početno stablo:
```
        25
       / \
      2   1
     / \ / \
    13 7 18 8
```

**Korak 1:** Pronalaženje čvora sa vrednošću 2
- Čvor 2 se nalazi na levoj strani stabla (dete od 25)

**Korak 2:** Zamena sa poslednjim čvorom
- Poslednji čvor je 8
- Zamena vrednosti 2 sa 8
```
        25
       / \
      8   1
     / \ / \
    13 7 18  [2]
```

**Korak 3:** Uklanjanje poslednjeg čvora
- Uklanjamo čvor sa vrednošću 2
```
        25
       / \
      8   1
     / \ /
    13 7 18
```

**Korak 4:** Heapify down za čvor sa vrednošću 8
- Proveravamo da li 8 zadovoljava MaxHeap svojstvo
- 8 < 13 (levo dete), pa vršimo zamenu
```
        25
       / \
      13  1
     / \ /
    8  7 18
```

**Konačno stablo nakon brisanja čvora 2:**
```
        25
       / \
      13  1
     / \ /
    8  7 18
```

## Rezime

- **MaxHeap stablo** je binarno stablo gde je vrednost svakog čvora veća ili jednaka vrednostima njegove dece
- **Brisanje čvora** podrazumeva zamenu sa poslednjim čvorom, uklanjanje poslednjeg čvora i heapify down operaciju
- **Vremenska složenost** brisanja čvora je O(log n) gde je n broj čvorova u stablu
