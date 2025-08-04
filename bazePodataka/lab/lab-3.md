> **lab 3 - azuriranje podataka, pogledi i indeksi**

---

> **nove komande**
- INSERT INTO .... VALUES
- SYSDATE
- UPDATE .... SET
- DELETE FROM
- CREATE VIEW .... AS
- CREATE INDEX .... ON
- ALTER TABLE

---

**<mark>zadaci za samostalni rad</mark>**

```sql
-- 1. zadatak
INSERT INTO FILM
(BROJ, NASLOV, TIP, GODINA, REZISER, BROJ_DISKOVA)
VALUES ( (SELECT MAX(BROJ) + 1 FROM FILM;), 'Promise me this', 'comedy', 2007, 21, 4);
```

```sql
-- 2. zadatak
UPDATE IZNAJMLJIVANJE
SET DATUM_VRACANJA = SYSDATE
WHERE CLAN = 8 AND FILM = 53 AND DATUM_IZNAJMLJIVANJA = '6-APR-2017';
```

```sql
-- 3. zadatak

-- prvo moramo da odstranimo strani kljuc
ALTER TABLE IZNAJMLJIVANJE DROP CONSTRAINT IZNAJMLJIVANJE_CLAN_FK;

-- sada brisemo clana sa brojem 8 iz sporednih tabela (u ovom slucaju samo jedna)
DELETE FROM IZNAJMLJIVANJE WHERE CLAN = 8;

-- sada  brisemo clana sa brojem 8 iz glavne tabele
DELETE FROM CLAN WHERE BROJ = 8;

-- vracamo strani kljuc
ALTER TABLE IZNAJMLJIVANJE ADD CONSTRAINT IZNAJMLJIVANJE_CLAN_FK FOREIGN KEY (CLAN) REFERENCES CLAN(BROJ);

```
