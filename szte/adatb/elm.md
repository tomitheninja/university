# Adatbázisok elmélet

## Az adatok típusa

- strukturálatlan: bináris adat
- egyszerű szöveg: lehet benne keresni
- formázott szöveg: hierarchiaszintek (cím, bekezdés, ...)
- hipertext: hivatkozások
- táblázat: lekérdezéseket értelmezünk rajta
- adatbázis: lsd: következő pont

## Adatbázisok

Adott formátum és rendszer szerint tárolt adatok halmaza

adategysége: rekord (sor)

kezelő szoftver: DBMS (database management system)

feladatai:

- adatstruktúrák definiálása
- adatok kezelése (insert, delete, update, query)
- adatok tárolása
- felhasználók (kliensek) kiszolgálása
- több feladat egyidejű végrehajtása, tranzakciók kezelése

## Adatmodellek

- Hierarchikus modell: fa struktúra (XML)
- hálós modell: gráf struktúra, `set<pointer>` segítségével
- relációs modell: kapcsoló táblák
- objektumorientált modell: OOP eszköztárával működik
- objektum-relációs modell: egyszerre relációs és OOP

## Egyed-kapcsolat modell

egyed: a valós világ egy objektuma

- egyedtípus: általános objektum
- egyedpéldány: konkrét értékekkel rendelkező objektum

tulajdonság: egyed egy jelzője

## Egyed-kapcsolat diagram

|  | jelölés|
| ------- | ------- |
|egyed       | téglalap ▭|
|tulajdonság | elipszis ⬭|
|kulcs       | aláhúzás  a̲|
|kapcsolat   | rombusz ◊|

### Kapcsolatok az E-K diagramban

- **1:1** - mindkettő végére nyilat teszünk
- **1:N** - 1 felöli oldalára nyilat teszünk
- **N:M** - nincs nyíl
