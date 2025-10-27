
[komande](#komande)
<br>

[oktobar 2025](#oktobar-2025)


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

# oktobar 2025

```cpp
void switch(int key1, int key2){
    
    Node* p1 = nullptr;
    Node* p2=nullptr;
    Node* t1= head;  
    Node* t2= nullptr;
    
    while(t1->key != key1){
      p1=t1;
      t1=t1->next;
    }
    t2=t1->next;
    while(t2->key!=key2){
      p2=t2;
      t2=t2->next;
   }
    
    // key1 na pocetku
    // switch(1,2)  1 2 3 4 5    2 1 3 4 5
    if(p1==nullptr)   {
      Node* tmp = t2->next;
  		t2->next = t1;
      t1->next=tmp;
      t2=head;
      delete tmp;
    } 
    // jedan za drugim
    // 1 2 3 4 5  -->>  1 3 2 4 5 
    if(t1->next = t2){
      Node* temp2 = t2->next;
      t1->next=temp;
      t2->next=t1;
      p1->next=t2;
      p2->next=temp;
      delete temp2;
    }
    // opsti slucaj
  	// switch(2,3)  1 2 3 4 5   1 3 2 4 5
    else{
      Node* temp = t1->next;   
      Node* temp2=t2->next;  
      t2->next = temp;  
      t1->next=temp2; 
      p1->next=t2; 
      p2->next=t1; 
      delete temp;
      delete temp2;
    }
    

}
```
