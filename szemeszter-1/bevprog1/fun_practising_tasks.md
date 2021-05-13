tömb: értsd = vector<>

és ahol nem kell tömb, ott megcsinálhatjátok tömbbel és a nélkül is

## Tömb:
### Könnyű házik:

1) Írd bele egy tömbbe a páros számokat 10 - 10 000-ig. Legyen benne a 10 és a 10 000 is. (% operátor nélkül is megy?)

2) Tölts fel egy tömböt 100 db véletlen generált számmal.

3) Tölts fel egy tömböt 100 db véletlen generált számmal.
A véletlen generált számok legyenek 5-20 közöttiek. (lehet 5 és 20 is)

### Közepesen nehéz házik:

4) Írd bele egy tömbbe 1-1000-ig a 7-tel osztható számokat % használatával.
(segítség: a % operátor az osztási maradékot adja meg, pl: 5 % 2 = 1, 6 % 6 = 0)

5) Írd bele egy tömbbe 1-1000-ig a prímszámokat.
  Készíts függvény, ami egy adott számról megmondja, hogy prím-e, majd ezt használd a feladathoz.

6) Írd bele egy tömbbe 1-1000-ig a számokat ha az adott szám osztható 3-mal VAGY osztható 4-gyel. (segítség: ||, &&)

7) Írd bele egy tömbbe 1-1000-ig a számokat ha az adott szám osztható 2-vel VAGY osztható 5-tel ÉS nem osztható 3-mal.

8) Írd ki egy tetszõleges tömb elemeit fordított sorrendben.

Extra nehéz házik:

9) Készíts függvény, melynek bemeneti paramétere egy tetszõleges tömb, kimeneti paramétere pedig a megfordított tömb, majd ezt felhasználva oldd meg a 8. feladatot.

10) Keresd meg és írd ki egy tömbben a legkisebb elemet.

11) Keresd meg és írd ki egy tömbben a legnagyobb elemet.

12) Rendezd növekvő sorrendbe az elemeit. (segítség: buborék rendezés).

#### 2D-s tömb:
```c++
vector<vector<int>> v;
v[row][col]
```

1. feladat: A 2D-s tömb
   a) Tölts fel egy 2D-s tömböt véletlenszerű (1 és 5 közötti) számokkal.
   b) Írd ki az elemeit az előbb feltöltött tömbnek
   c) Add össze a tömb elemeit. Példa: [[1,1], [2,2]] eredmény: 6

2. feladat: Szorzótábla  
   a) Generáld le 2D-s tömbbe a szorzótáblát.    
   Help: http://cms.sulinet.hu/get/d/86fbabdf-9269-48d8-ad8c-568296a8e235/1/7/b/Normal/m6ny-0595kepp-normal.jpg
   b) Írd ki a 7-es szorzótáblát. Elvárt kimenet: 7,14,21,28,35,42,49,56,63,70
   c) Írd ki az 5. sorát a szorzótáblának
   d) Kérj be a felhasználótól két számot (10 vagy az alattit), majd írd ki a szorzatukat.
   FONTOS: a 2D-s tömbből kell kiolvasnotok a szorzatot. Összeszorozni nem ér. Ügyeljetek arra is, hogy ha 10-nél nagyobbat ad meg akkor újra kérjétek be a számot.


## Object:

1) Hogyan tárolhatnám el ~~javascriptben~~ az adataimat? (név, életkor, emailcím, iskola)

2) Hozz létre egy olyan objectet, ami egy autóról a teljesítményén és tipusán kívül azt is eltárolja hogy milyen színekben kapható.
Tehát pl: Ferrari, 400 lóerő, szinek: kék , zöld, fehér, piros.  (segítség: objectben tömb?)

### Nehezebb házi:

3) Hozz létre az előbbihez hasonló objectet. Legyen egy olyan függvénye az objectnek, amit ha meghívsz egy színnel, megmondja hogy az autó kapható-e abban a színben.
Példa a hívásra:
vanIlyenSzin(ferrari, "feher");
Ha van ilyen szin akkor írd ki hogy van, egyébként azt, hogy nincsen.
