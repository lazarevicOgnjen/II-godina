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
