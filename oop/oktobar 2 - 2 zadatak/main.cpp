void zadatak2() {
int maxPodataka = 8, brojPodataka = 9;
// 3 boda
// postavljanje i prihvatanje izuzetaka
{
float tezine[] = { 1.5, 2.7, 3.2, 0.8, 1.8, 4.1, 2.5, 2.3, 3.6 };
Ispit<float> ispit(maxPodataka);
// 1 bod
for (int i = 0; i < brojPodataka; i++)
ispit.Dodaj(tezine[i]);
cout << ispit << endl; //nov.Ispisi(cout);
// 1 bod
ispit.Izbaci(4, 3);
cout << ispit << endl; //nov.Ispisi(cout);
// 1 bod
float ukupno = ispit.Ukupno();
cout << ukupno << endl; // 14.1
// 1 bod
float vrednost = 2.0; float ukupnaVrednost = 0;
int broj = ispit.UkupniBrojVrednost(vrednost, ukupnaVrednost);
cout << broj << " " << ukupnaVrednost << endl; // 4 11.8
// 1 bod
float min = 0.0; float max = 1000.0;
ispit.minMax(1, 4, min, max);
cout << min << " " << max << endl; // 4
// 1 bod
ispit.Sacuvaj("IspProst.txt");
// 1 boda
Ispit<int> ispUc(maxPodataka);
ispUc.Ucitaj("IspProst.txt");
cout << ispUc << endl; //novUcitan.Ispisi(cout);
}
{
char naziv[][8] = { "prva", "druga", "treca", "cetvrta", "peta",
"sesta", "sedma", "osma", "deveta" };
float tezine[] = { 1.5, 2.7, 3.2, 0.8, 1.8, 4.1, 2.5, 2.3, 3.6 };
float duzina[] = { 1.2, 3.1, 2.5, 3.4, 4.1, 1.7, 2.2, 3.7, 2.8 };
Ispit<LekcijaNormalna> ispNor(maxPodataka);
// 1 bod
for (int i = 0; i < brojPodataka; i++) {
LekcijaNormalna lekcija(naziv[i], tezine[i], duzina[i]);
ispNor.Dodaj(lekcija);
}
// 1 bod
cout << ispNor << endl; //novVal.Ispisi(cout);
// 1 bodova
ispNor.Izbaci(4, 3);
cout << ispNor << endl; //novVal.Ispisi(cout);
// 1 bod
float ukupno = ispNor.Ukupno();
cout << ukupno << endl;
// 2 bod
float vrednost = 2.0; float ukupnaVrednost = 0;
int broj = ispNor.UkupniBrojVrednost(vrednost, ukupnaVrednost);
cout << broj << " " << ukupnaVrednost << endl;

// 2 bod
LekcijaNormalna min, max;
ispNor.minMax(1, 4, min, max);
cout << min << " " << max << endl;
// 1 bod
ispNor.Sacuvaj("IspNormal.txt");
// 1 bod
Ispit<LekcijaNormalna> ispNorUc(maxPodataka);
ispNorUc.Ucitaj("IspNormalB.txt");
cout << ispNorUc << endl; //novValUc.Ispisi(cout);
}
}

void main(){
 zadatak2();
}

