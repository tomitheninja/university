# Algoritmusok I

- Gelle Kitti jegyzete

## Követelmények

- nincs katalógus

### 2 zh

- okt 13 (50 pont, min 13)
- dec 1 (50 pont, mint 13)

egy javítható, akár ötösre is

### Jegyek

1. 0-50
2. 51-60
3. 61-70
4. 71-85
5. 86-100

### plusz pont

max 10

## 1. óra

### Algoritmus

- konkrét inputhoz hozzárendel egy konkrét outputot
- van időigénye
- van tárigénye

### Magyar kártyás feladat (lineáris keresés $\mathcal{O}(n)$)

- 32 lap = N
- legrosszabb eset: 32 kérdés
- legjobb eset: 1 kérdés
- átlagos eset: $\frac{1+32}{2} = 16.5$

#### Futási idő tulajdonságai

- felső korlát = legrosszabb eset

$\mathcal{O}(n)$: $g(n)$ függvény felső korlátja $f(n)$, ha $f(n) \le c_0g(n)$

### Magyar kártyás feladat tulajdnságokkal (logaritmikus keresés $\mathcal{O}(\log_2n$)

algoritmus lényege: pakli felezése minden lépésben

- szín: 2 lépés (P, Z, M, T)
- ez egy szám? (I/N)
- ez vagy ez? (I/N)
- ez az a kártya? (I/N)
- meg van a válasz

```ts
/**
 * Finds x in arr in logarithmic time
 * @param arr Ordered number array
 * @param x Item to find
 * @param left starting index of slice we are searching in
 * @param right
 * @returns index of x in arr or -1 if not found
 */
function keres(arr: number[], x, left, right) {
    const NOT_FOUND = -1
    let middle = left + (right - left) / 2
    if (arr[middle] < x)
        return keres(arr, x, middle + 1, right)
    else if (arr[middle] > x)
        return keres(arr, x, left, middle - 1)
    else if (arr[middle] == x)
        return middle
    else return NOT_FOUND
}
```

### Sátorkeresős, oda-vissza

- n sátor
- csak akkor ismerem fel, ha mégegyszer megnézem (2 teszt)
- algoritmus: megnézem az összeset, majd visszafelé újra

- idő igény
  - legjobb: $n + 1$
  - legrosszabb: $2n$
  - átlagos: $\frac{n+1+2n}{2} = \frac{3n + 1}{2}$
- tárterület igény
  - $\frac{\sum_{i=1}^{n} (n+i)}{n}$

### Absztrakt példa

```js
```