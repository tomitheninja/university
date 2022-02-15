# Operáció kutatás

# Pizzák

| milyen  | Sajtos | Ananászos | db  |
| ------- | ------ | --------- | --- |
| Sonka   | 8      | 10        | 48  |
| Sajt    | 5      | 1         | 20  |
| Ananász |        | 2         | 8   |

Előfeltétel: $\not\exists$ negatív pizza: $X >= 0$

$X_s = 0, X_A = 0, C=0$

$X_s = 4, $X_A = 0, C=4$

$X_s = 1, x_A = 1, C=2$

## Optimális megoldás

Módszer: Pizzák visszabontása

### 1. Lineáris egyenletrendszer felírása

$X_{s,a} \ge 0$

$8X_s + 10X_A \le 48$

$5X_s + A_x \le 20$

$2X_a \le 8$

$\frac{Ax \le b}{c^Tb \to max}$

<img src="https://i.imgur.com/O7lTgyb.png">

#### jelmagyarázat

- kék, fekete egyenesek által határolt területek: megoldásokat tartalmazó poliéder
- piros egyenesek: a poliéder csúcsai, amelyek a lehetséges optimális megoldások
- legjobb megoldás: $max(piros egyenesek)$

#### matekkal

$X_S = \frac{152}{42} = 3.619...$

$X_A = \frac{80}{42} = 1.904$

$X_S + X_A = \underline{5.523}$

#### mátrix eleminációval

Ötlet: $\exists X_1, X_2, ..., X_n \ge 0$, hogy

$8X_1 + 10X_2 + X_3 = 48$

$5X_1 + 1X_2 + X_4 = 20$

$2X_2 + X_5 = 8$

---

$max(X_1 + X_2)$

vagy szótár alakban: ugyan ez, de $X_i$-re rendezve.

$X_3 = 48 - 8X_1 - 10X_2$

$X_4 = 20 - 5X_1 - X_2$

$X_5 = 8 - 2X_2$

---

$Z(X) = 0 + X_1 + X_2 \to max$

#### Lehetséges megoldás


|x_1|x_2|x_3|x_4|x_5|
|:--:|:--:|:--:|:--:|:--:|
|0|0|48|20|8|

ennél sokkal jobb megoldást lehet találni, ha behelyettesítéssel egyszerűsítjük az egyenletrendszert és $Z(X)=...$-ra rendezzük azt. Lesz egy (vagy több) generáló elem, ami alapján pozitív irányba mozdítható a $Z$ értéke (mohó algoritmusos közelítés). Ha nincsen ilyen (= az összes együttható negatív), akkor megtaláltunk egy $Z_{max}$-ot.

Bizi: Mivel csak egyenleteket alakítottunk át, ezért ez is megoldása az egyenletnek. Mivel $\forall$ együttható negatív, ezért ez $max(Z)$.

HF: X_2-ből indulva megoldani
