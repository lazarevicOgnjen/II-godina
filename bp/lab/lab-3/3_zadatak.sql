-- prvo moramo da odstranimo strani kljuc
ALTER TABLE IZNAJMLJIVANJE DROP CONSTRAINT IZNAJMLJIVANJE_CLAN_FK;

-- sada brisemo clana sa brojem 8 iz sporednih tabela (u ovom slucaju samo jedna)
DELETE FROM IZNAJMLJIVANJE WHERE CLAN = 8;

-- sada  brisemo clana sa brojem 8 iz glavne tabele
DELETE FROM CLAN WHERE BROJ = 8;

-- vracamo strani kljuc
ALTER TABLE IZNAJMLJIVANJE ADD CONSTRAINT IZNAJMLJIVANJE_CLAN_FK FOREIGN KEY (CLAN) REFERENCES CLAN(BROJ);
