Node* Brisi(Node* LL, int E) {
    if (LL == NULL) return LL;
    
    Node* pomocni = LL;
    Node* prethodni = NULL;
    
    // Provera prvog čvora
    if (pomocni->value == E) {
        LL = pomocni->next;
        delete pomocni;
        return LL;
    }
    
    // Traženje čvora
    while (pomocni != NULL && pomocni->value != E) {
        prethodni = pomocni;
        pomocni = pomocni->next;
    }
    
    // Element nije pronađen
    if (pomocni == NULL) return LL;
    
    // Brisanje
    prethodni->next = pomocni->next;
    delete pomocni;
    
    return LL;
}
