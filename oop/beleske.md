- [inline funkcija](#inline-funkcija)
- [trougao](#trougao)


# inline funkcija

1. Obična funkcija  
   Pozoves funkciju. 
   Program skoči do te funkcije, izračuna, vrati se. Skok-gore-skok-dole = malo sporije.

2. Inline funkcija  
   Pozoves funkciju. 
   Program **iskopira** ceo račun tamo gde si pozvao – nema skakanja, odmah uradi.  
   Brže je, ali svaki put kad pozoveš, iskopira se ceo kod (veći program).


# trougao

Uslov da je nesto trougao: *a>0 && b>0 && c>0 && a+b>c && b+c>a && c+a>b*

**Heronova formula**, najpoznatiji način da se izračuna površina bilo kog trougla kad znaš sve tri stranice.

Koraci:

1. Izračunaš **poluobim** (pola obima):  
   `s = (a + b + c) / 2`

2. Ubaciš u formulu:  
   `P = √[ s ⋅ (s − a) ⋅ (s − b) ⋅ (s − c) ]`

kod:

```cpp
double s = (a + b + c) / 2;
return sqrt(s * (s - a) * (s - b) * (s - c));
```
