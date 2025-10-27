
[komande](#komande)
<br>

[primer](#primer)


# komande

`LL-   LinkedNode* headSL = sublist->head;` 
<br>

`LinkedNode* tmp = this->head;`
<br>

`currSL = currSL->next;`
<br>

`tmp->info`
<br>

`LinkedNode* brisac = save;`
<br>

`save = save->next;`
<br>

`delete brisac;`
<br>

`novaLista->tail = nullptr; `
<br>

`staralista.isEmpty()`
<br>

# primer

```cpp
class LinkedList {
private:
    struct Node {
        int key;
        Node* next;
        Node(int k) : key(k), next(nullptr) {}
    };
    
    Node* head;

public:
    void switch(int key1, int key2) {
        if (key1 == key2) return; // Nema potrebe za zamenu istih ključeva
        
        // Pronalazimo čvorove i njihove prethodnike
        Node* prev1 = nullptr;
        Node* curr1 = head;
        Node* prev2 = nullptr;
        Node* curr2 = head;
        
        // Tražimo prvi čvor (key1) i njegovog prethodnika
        while (curr1 != nullptr && curr1->key != key1) {
            prev1 = curr1;
            curr1 = curr1->next;
        }
        
        // Tražimo drugi čvor (key2) i njegovog prethodnika
        while (curr2 != nullptr && curr2->key != key2) {
            prev2 = curr2;
            curr2 = curr2->next;
        }
        
        // Ako nismo pronašli oba čvora, prekidamo
        if (curr1 == nullptr || curr2 == nullptr) {
            return;
        }
        
        // Menjamo čvorove
        // Slučaj 1: key1 je glava liste
        if (prev1 == nullptr) {
            head = curr2;
        } else {
            prev1->next = curr2;
        }
        
        // Slučaj 2: key2 je glava liste
        if (prev2 == nullptr) {
            head = curr1;
        } else {
            prev2->next = curr1;
        }
        
        // Menjamo next pokazivače
        Node* temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
    }
};
```
