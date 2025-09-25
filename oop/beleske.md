<br><br>

> [!NOTE]
> - [inline funkcija](#inline-funkcija)
>   
> - [trougao](#trougao)
>   
> - [prosledjivanje vrednosti](#prosledjivanje-vrednosti)

<br><br><br>

# Inline funkcija

1. Obična funkcija
   ```cpp
   double P(double a, double b, double c) {
	.....
   }
   ```
   Pozoves funkciju. <br>
   Program skoči do te funkcije, izračuna, vrati se. Skok-gore-skok-dole = malo sporije.

2. Inline funkcija
   ```cpp
   inline double P(double a, double b) {
   	.....
   }
   ```
   Pozoves funkciju. <br>
   Program **iskopira** ceo račun tamo gde si pozvao – nema skakanja, odmah uradi.  
   Brže je, ali svaki put kad pozoveš, iskopira se ceo kod (veći program).

<br><br>

# Trougao

Uslov da je nesto trougao: ***a>0 && b>0 && c>0 && a+b>c && b+c>a && c+a>b***

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

<br><br>

# Prosledjivanje vrednosti

1. Pomocu pokazivaca.
```cpp
// pozivamo funkciju
polar(x, y, &r, &fi);
```

```cpp
// deklaracija i definicija funkcije
void polar(double x, double y, double* r, double* fi) {
	*r  = sqrt(x*x + y*y);
	*fi = (x==0 && y==0) ? 0 : atan2(y, x);
}
```

2. Pomocu upucivaca (reference).
```cpp
// pozivamo funkciju
polar(x, y, r, fi);
```

 ```cpp
// deklaracija i definicija funkcije
void polar(double x, double y, double& r, double& fi) {
	r  = sqrt(x*x + y*y);
	fi = (x==0 && y==0) ? 0 : atan2(y, x);
}
```

<br><br>
