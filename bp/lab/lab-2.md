<br><br>
> **lab 2 - slozeni upiti**

<br>

<table> 
  <tr>
    <th>nove komande</th>
  </tr>
  <tr>
    <td>JOIN</td>
  </tr>
  <tr>
    <td>UNION</td>
  </tr>
  <tr>
    <td>INTERSECT</td>
  </tr>
  <tr>
    <td>(NOT) EXISTS</td>
  </tr>
  <tr>
    <td>MINUS</td>
  </tr>
  <tr>
    <td>ROWNUM</td>
  </tr>
  <tr>
    <td>GROUP BY</td>
  </tr>
  <tr>
    <td>HAVING</td>
  </tr>
</table>

<br><br>

**<mark>zadaci za samostalni rad</mark>**

<br>

```sql
-- 1. zadatak I nacin
SELECT FILM.NASLOV, REZISER.IME, PREZIME
FROM FILM INNER JOIN REZISER ON FILM.REZISER = REZISER.BROJ;
```
**<mark> II nacin</mark>**
```sql
SELECT FILM.NASLOV, REZISER.IME, REZISER.PREZIME
FROM FILM, REZISER
WHERE FILM.REZISER = REZISER.BROJ;
```
<br>

```sql
-- 2. zadatak
SELECT FILM.BROJ, NASLOV
FROM FILM INNER JOIN REZISER ON FILM.REZISER = REZISER.BROJ
WHERE REZISER.IME = 'Emir' AND REZISER.PREZIME = 'Kusturica'
MINUS
SELECT FILM.BROJ, NASLOV
FROM FILM INNER JOIN IGRA ON FILM.BROJ = IGRA.FILM
  INNER JOIN GLUMAC ON GLUMAC.BROJ = IGRA.GLUMAC
WHERE GLUMAC.IME = 'Mira' AND GLUMAC.PREZIME = 'Banjac';
```
<br>

```sql
-- 3. zadatak
SELECT CLAN.BROJ, IME, PREZIME
FROM CLAN 
MINUS
SELECT CLAN.BROJ, IME, PREZIME
FROM CLAN INNER JOIN IZNAJMLJIVANJE ON CLAN.BROJ = IZNAJMLJIVANJE.CLAN;
```

<br><br>

