<br><br>
> **lab 1 - prosti upiti**

<br><br>

**<mark> zadaci za samostalni rad </mark>**

<br>

```sql
-- 1. zadatak
SELECT IME, PREZIME, GODINA_ROD, MESTO_ROD
FROM GLUMAC
WHERE BROJ = 50;
```
<br>

```sql
-- 2. zadatak
SELECT IME, PREZIME
FROM GLUMAC
WHERE GODINA_ROD > 1920;
```
<br>

```sql
-- 3. zadatak
SELECT BROJ
FROM IGRA
WHERE FILM BETWEEN 85 AND 91;
```
<br>

```sql
-- 4. zadatak
SELECT BROJ, NASLOV
FROM FILM
WHERE TIP = 'comedy' AND ( AA_NAGRADE IS NOT NULL OR AA_NAGRADE > 0 );
```
<br>

```sql
-- 5. zadatak
SELECT COUNT(*)
FROM IZNAJMLJIVANJE
WHERE CLAN = 3;
```
<br>

```sql
-- 6. zadatak
SELECT BROJ, NASLOV
FROM FILM
WHERE TIP = 'comedy' AND ( AA_NAGRADE IS NOT NULL OR AA_NAGRADE > 0 ) AND LOWER(NASLOV) NOT LIKE '%uncle%' AND GODINA > 1970;
```

**<mark> ovde je NOT LIKE moglo da se iskoristi i ovako </mark>**

```sql
SELECT BROJ, NASLOV
FROM FILM
WHERE TIP = 'comedy' AND ( AA_NAGRADE IS NOT NULL OR AA_NAGRADE > 0 ) AND NOT LOWER(NASLOV) LIKE '%uncle%' AND GODINA > 1970;
```

<br><br>
