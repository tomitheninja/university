# Lineáris egyenletrendszerek

Egy egyenlet akkor lineáris, ha minden tényező legfeljebb első fokon szerepel benne (tehát nincs $x^2$, $x^3$, ...)

## Az egyenletek alakjai

### Felsorolás

1. $2x - 5y = 8$
2. $3x + 9y = -12$

### Vektorok

$
x\begin{bmatrix}2\\\\ 3\end{bmatrix} +
y\begin{bmatrix}-5\\\\ 9\end{bmatrix} =
\begin{bmatrix}8\\\\ -12\end{bmatrix}
$

### Mátrixok

A mátrix az egy mxn méretű táblázat, amit fel lehet használni például egyenletek tárolására is:

$
\underline{\underline{A}} = \left[\begin{array}{cc|c}
 2 & -5 & 8 \\\\ 3 & 9 & -12
\end{array}\right]
$

A mátrixot kibővítettnek hívjuk, ha tartalmazza az egyenlet megoldásait is. Ennek jelölése: $ [A\vert b] $

# Determináns

A determináns, az egy olyan függvény, amely egy számot rendel egy nxn típusú mátrixhoz.

Jelölése: A mátrix abszolút jelben $ \left|\underline{\underline{A}}\right| $, vagy függvényként $ \det(A) $

## Geometriai jelentés

paralelepipedon előjeles térfogata (pofáncsapott téglatest)

## Nulla determináns jelentése

Ha az nxn típusú mátrix determinánsa nulla, akkor az csak egy n-nél kisebb dimenziós alakzatot tartalmaz (későbbiekben: lineáris összefüggőség).

Tehát ha egy 3x3-as mátrix determinánsa nulla, akkor a paralelepipedon valamely irányú kiterjedése nulla, tehát az igazából nem egy három dimenziós testet ír le.

## Determináns kifejtése

### 1x1 determináns kifejtése

$ \det(x) = x $ (önmaga)

### 2x2 determináns kifejtése

$ \begin{bmatrix}
a & b\\\\c & d
\end{bmatrix} $ mátrix determinánsa = $ ad - bc $

### Nagyobb mátrix determinánsa

tetszőleges $1 \le i \le n$ esetén:

$$ \sum_{j=1}^{n} A_{ij} \cdot (-1)^{i+j} \cdot D_{ij} $$

#### Értelmezési segédlet

- $ A_{ij} $: A mátrix i-edik sorának j-edik eleme.
- $ (-1)^{i+j} $ A sakktábla színezése szerint változó előjel
- A $ D_{ij} $ aldeterminás úgy keletkezik, hogy elhagyjuk a mátrix i-edik sorát és j-edik oszlopát, majd az ennek a minormátrixnak vesszük a determinánsát.

## Kifejtési tétel

Egy determináns bármely sora vagy oszlopa alapján kifejthető és az eredmény minden esetben ugyan az lesz.

## Ferde kifejtés (Gauss-os)

Előnye, hogy sokkal kevesebb számítást igényel nagyobb (3x3, 4x4) mátrixok esetén

#### Átalakítás

Gauss elemináció segítségével előállítható egy ilyen mátrix: $
\begin{bmatrix}
a & - & -\\\\b & c & -\\\\d & e & f
\end{bmatrix}
$

#### Kiértékelés

**Tétel:** Egy alsó- vagy felsőháromszögmátrix determinánsa a főátlóban lévő elemeinek szorzata.

#### Visszaalakítás

Az eredeti determinánsérték visszafejtése a háromszögmátrixból:

- Egy sor szorzása egy skalárral: $ D_2 = D_1 \cdot \lambda $ (valamelyik tengely nyújtása)
- Ha valemelyik sorhoz hozzáadjuk a másik sor akárhányszorosát, akkor a determináns nem változik (ugyan az az alakzat, de egy más tengelyen felírva)
- Ha két szomszédos sort felcserélünk, akkor a determináns értéke mínusz egyszeresére változik (az előjel jelentése = nézőpont (lásd negatív sebesség), de a tengelyek most felcserélődnek)

##### Sorcserék

Ha bármely két sort cseréljük fel, akkor $ 2k+1 $, azaz páratlan számú cserét hajtunk végre.

Bizonyítás: Ha a két sor között pontosan k sor helyezkedik el, akkor mind a kettő sor k-nyit vándorol, a két sor cseréje pedig egy lépés.

Mivel páratlan számúszor invertálódik a determináns értéke, ezért (-1)-esére változik.
