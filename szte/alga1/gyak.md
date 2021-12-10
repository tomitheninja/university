# Algoritmusok I

- [gyakvez jegyzete](https://github.com/dhirling/alga1)

- [Gelle Kitti jegyzete](https://www.inf.u-szeged.hu/~kgelle/?q=alga)

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

## Nagy O jelölések

### Legjobb eset = alsó korlát (omega)

$$
\Omega(g(n)) = \left\{f(n), \exists c, n_0, \forall n_0 \le n, f(n) \ge C\cdot g(n) \right\}
$$

### Legrosszabb eset (ordó)

$$
\mathcal{O}(g(n)) = \left\{f(n), \exists c, n_0, \forall n_0 \le n, f(n) \le C\cdot g(n) \right\}
$$

### Nagyságrend (theta)

$$
f(x) = \mathcal{O}(g(n)), f(x) = \Omega(g(n))
$$

## Algoritmusok

### Lineáris keresés

```java
public static int seach(int key, int[] a) {
  for (int i = 0; i < a.length; i++)
    if ( a[i] == key ) return i;
  return −1;
}
```

#### Időigény
|  min. | max.  | avg.  |
| --- | --- | --- |
|  1 | n  | (1+n)/2  |

### Logaritmikus keresés

```java
public static int seach(int key, int[] a) {
  int l = 0, r = arr.length − 1;
  while ( l <= r ) {
    int m = l + ( r−l ) / 2 ;
    if ( arr[m] == x ) return m;
    if ( arr[m] < x ) l = m + 1;
    else
      r = m − 1 ;
  }
  return −1;
}
```

### Faktoriális

```java
public static int factorial(int n) {
  if ( n <= 1 ) return 1;
  return n * factorial(n-1);
}
```

### Lépcső mászás

n lépcső, léphetünk 1-et vagy 2-őt

```c
int P( int n ){
  if ( n == 1 )
    return 1;
  else if ( n == 2 )
    return 2;
  else
    return P(n−1) + P(n−2);
}
```

### Utazás sakktábla sarkai között

k sor, n oszlop nagyságú sakktábla bal alsó sarkából a jobb felsőbe.

```c++
int R( int n , int k ){
  if (( n == 1 ) or ( k == 1 ))
    return 1 ;
  else
    return R(n−1, k) + R(n, k−1);
}
```


### Mergesort

```python
def merge_sort(A, n):
  if len(A) == n:
    return A
  A1 = mergesort(A[1:n/2])
  A2 = mergesort(A[n/2+1:-1])
  return merge(A1, A2)

def merge(A1, A2):
  A = []
  while not empty(A1) and not empty(A2):
    smaller = min(first(A1), first(A2))
	A.push(smaller)
	if smaller == first(A1):
	  A1.remove_at(0)
	else:
	  A2.remove_at(0)
  return list(A, A1, A2) # Everything from A + the remaining items from the non empty array
```
