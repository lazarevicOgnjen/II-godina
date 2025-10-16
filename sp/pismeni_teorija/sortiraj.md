Function Dodaj(LL, E):
    new_node = CreateNode(E)  	// Kreiramo novi čvor sa vrednošću E
    
    // Slučaj 1: Prazna lista
    If LL == NULL:
        LL = new_node           // Lista postaje novi čvor
        new_node -> next = NULL // Novi čvor pokazuje na NULL (kraj liste)
        return LL  
    // Slučaj 2: Ubacivanje na početak       LL---> 1 ------> 2 3 4 5 6 7
    If E < LL->value :         // Ako je nova vrednost manja od prvog elementa
        new_node -> next = LL   // Novi čvor pokazuje na stari početak
        LL = new_node           // Novi čvor postaje početak liste
        return LL     
    
    // Slučaj 3: Ubacivanje u sredinu ili na kraj      createNode(5)          1 2 3 4->5-> 6 7 8 9   2)4->next = 5   1) 5 ->next =4->next
    current = LL                // Počinjemo od početka liste
    While current -> next != NULL AND current -> next -> value < E:
        current = current -> next  // Pomeramo se kroz listu dok ne nađemo mesto 
    
    
    curent = 4
    
    
    // Ubacivanje novog čvora
    new_node -> next = current -> next  // Novi čvor pokazuje na sledeći čvor  5 -> 6
    current -> next = new_node          // Prethodni čvor pokazuje na novi čvor
    
    Return LL  // Vraćamo pokazivač na početak liste
End Function
