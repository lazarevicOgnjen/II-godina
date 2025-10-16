Funkcija Brisi(LL, E)
1. if (LL = NULL) then
2.    return LL    // prazna lista
3. 
4. pomocni ← LL
5. prethodni ← NULL
6. 
7. // Provera prvog čvora
8. if (info(pomocni) = E) then
9.    LL ← link(pomocni)
10.   freenode(pomocni)
11.   return LL
12. 
13. // Traženje čvora koji se briše
14. while (pomocni ≠ NULL) AND (info(pomocni) ≠ E)
15.    prethodni ← pomocni
16.    pomocni ← link(pomocni)
17. 
18. // Ako nije pronađen element
19. if (pomocni = NULL) then
20    return LL

// Brisanje pronađenog čvora
link(prethodni) ← link(pomocni)
freenode(pomocni)

return LL
End Function
