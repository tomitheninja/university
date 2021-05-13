# MatLab cheatsheet

[yt/konzi](https://youtu.be/c-NzEwUjpAE)

[Összesített diák](https://users.itk.ppke.hu/~sudta/matlab.pdf)

[cheatsheet](https://tomitheninja.github.io/university/szemeszeter-2/matlab)

[GitHub repo](https://github.com/tomitheninja/university/tree/master/szemeszeter-2/matlab)

# 📝 Table of Contents

- [MatLab cuccok](#matlab)
- [Vezérlő utasítások](#stmts)
- [Adat típusok](#datatypes)
  - [Valós szám](#scalar)
  - [Logikai](#boolean)
  - [Vektorok](#vectors)
  - [Mátrixok](#matrices)
- [Algorithmusok](#algorithms)
- [Grafikonok](#graphics)
- [Analízis](#calculus)
  - [Deriválás](#derivate)
  - [Integrálás - adatsor](#integrate1)
  - [Integrálás - függvény](#integrate2)
  - [Differenciál egyenletek](#diffequation)
- [3D ábrázolás](#3d)
  - [Ponthalmaz](#3ddots)
  - [Felület](#3dsurf)
- [Struktúrák](#structs)
  - [Cellatömb](#cellarray)
  - [Struktúra](#struct)
  - [StruktúraTömb](#structArray)
- [Fájlok](#files)

# MatLab cuccok <a name = "matlab"></a>

Az `ans` változó tárolja a legutóbbi művelet eredményét.

a `clear` parancs kitörli a memóriát.

a `clc` parancs törli a konzol historyt.

a `help <függvény neve>` parancs megjelenít egy rövíditett dokumentációt. (ez nem az, ami a helpben van)

a `0`-val val való osztáskor hiba dobás helyett, kiszámolja az osztás "határértékét" (`1/0 == Inf`, `-1/0 == -Inf`)

a label és title függvények képesek latex módban is működni: `f(..., 'interpreter', 'latex')`

#### Konzolra iratás

a `disp(x)` függvénnyel lehet a konzolra írni egy előre megadott értéket: `disp('Hello world!')` , vagy egy változó értékét: `disp(a)`.

Ha nem teszel egy sor végére `;`-őt, akkor annak értéke meg fog jelenni a konzolon.

Ennek a trükknek a segítségével és az `sprintf('format string', param1, param2, ...)` függvénnyel lehet változókat tartalmazó szöveget (*=template*) a konzolra iratni: `sprintf('Petinek %d almája van.', num_apples)`.

# Vezérlő utasítások <a name = "stmts"></a>

## If-Else

```matlab
if r == c
  disp('1');
elseif abs(r-c) == 1
  disp('2');
else
  disp('0');
end
```

## For ciklus

```matlab
for i = 1:10
  disp(i);
end
```

# Adat típusok <a name = "datatypes"></a>

## Szöveg

### sprintf (template string)

A szövegbe változók értékét lehet vele elhelyezni.

Formázási beállítások:

_Ami szögletes zárójelben van, az elhagyható_ 

```
változó jelölése: "%"
[mindig legyen előjel: "+"]
[a kellő számjegyet szóköz helyett nullával töltse fel: "0"]
[a generált szöveg hossza: 123]
[tizedes pont: "."]
[törtjegyek száma: 123]
változó típusa:
 valós szám: "f"
 egész szám: "d"
```

## Valós szám (=[1x1] mátrix) <a name = "scalar"></a>

Jelölés: `3.14`

* `^`: hatványozás -> `a^(1/b)` == gyökvonás
* `*`, `/`: szorzás, osztás
* `+`, `-`: összeadás, kivonás
* `==`, `~=`: egyenlő, nem egyenlő

## Logikai  <a name = "boolean"></a>

Ez csak egy, a programozó fejében létező dolog. Igazából valós számként van eltárolva és megjelenítve.

### Felvehető értékek:

* `true` (1)

* `false` (0)

### Műveletek:

legyen bool = egy 0 vagy 1 értéket tároló változó.

`~bool` (tagadás)

`bool && bool` (és)

`bool || bool` (vagy)

## Vektorok (=[1xn] mátrix) <a name = "vectors"></a>

Jelölés: `[1 2 3]` vagy `[1, 2, 3]` (a vessző opcionális)

### Műveletek a vektor egészén

Legyenek v1 és v2 [1xk] típusú vektorok.
Legyen m egy [kxk] típusú mátrix.

* `v1 + v2`: Vektorok összege
* `v1 * m`: Szorzás mátrixxal.

#### Logikai műveletek egy vektoron

* `[1 2 3] == 2`: `[0 1 0]`
* `[1 2 3]  > 2`: `[0 0 1]`

### Műveletek a vektor elemein

#### A `.` operátor működése 

A dot operátort követő műveletet, ahelyett, hogy a műveletet az operátor bal oldalán lévő vektorra hajtaná végre, ahelyett egyesével, a vektor összes elemére hajta végre (olyan mint egy for ciklus).

```c++
// op(a, b) helyett ez: 
for (int i = 0; i < a.size(); i++) {
  op(a[i], b)
}
```

Például, legyen s egy skalár.

Ekkor `[a b c] .* s = [a*s, b*s, c*s]` (Látható, hogy a *s műveletet nem magára a vektorra hajtotta végre, hanem annak elemeire, egyesével)

#### Logikai műveletek a vektor elemein.

Az egyszeres logikai operátorokat akkor használjuk, amikor két feltételt szeretnénk összefűzni.

Pl: alma & finom kiértékése: `[1 0] & [1 1] = [1 0]`

### Vektorok skalár-indexelése

Eredménye a vektor egy eleme.

```matlab
v = [10 15 30]; % three rand nums
v(1) == 10;
v(2) == 15;
v(3) == 30;
v(end) == 30;
```

### Vektorok tartomány-indexelése

Eredménye a vektor egy része (=slice=szelete).

```matlab
v = [10 15 30]; % three rand nums
v(1:2) == [10 15];
```

### Vektorok létrehozása

* Elemeinek felsorolásával: `v = [1 2 3]`
* Index-tartomány segítségével: `v = 1:10`
* Okos-tartomány segítségével: `v = linspace(1, 10, 5)` első elem = 1, utolsó = 10, size = 5
* Csak nulla vektor: `v = zeros([1 5])`
* Csak egy vektor: `v = ones([1 5])`
* Bármely szám: `v = zeros([1 5]) + 10`
* Rand szám: `v = rand([1 5])`

## Mátrixok <a name = "matrices"></a>

```matlab
m = [1, 2; 3, 4];
% [1 2]
% [3 4]
```

```matlab
a = [1, 2];
m = [a; 3 4]; % az értékek kimásolása egy másik vektorból
```

## Gyakori műveletek mátrixokkal: <a name = "algorithms"></a>

#### Egy elem lekérése

```matlab
% első sor
% második oszlop
x = m(1, 2);
```

#### Több elem lekérése

```matlab
% minden sor
% második oszlop
first_row = m([1 end], 2);
```

#### Egy sor lekérése

A speciális `:` (all / row) operátor használatával:

```matlab
first_row = m(:, 2);
```

#### Trimming

Az első és az utolsó elem elhagyása:

```matlab
first_row = v(2:end-1);
```

#### Feltétel az elemeire:

```matlab
megfelel_e_a_feltetelnek = m > 2;
```

#### Szűrés

Csak a feltételnek megfelelő elemek:

```matlab
filtered = m(m > 2);
```

#### Keresés

Azon elemek indexei, amelyek megfelelnek egy feltételnek.

```matlab
idxs = find(m > 2); 
```

Ezzel is megvalósítható a szűrés, de az előző módszer gyorsabb.

#### Frissítés, Cserélés

Az adott indexű elemeknek értéket ad.

```matlab
m(:, 1) = 0;
A2(A2 == 0) = Inf; % replace zeros with Infinity
```

#### Átlag, Minimum, Maximum

```matlab
5 == mean([0 5 10])

% melyik dimenzió (irány) mentén fusson le?
% általában a második dim kell (sorok átlaga)
[1 15] == mean([0 2; 10 20], 2)

[min_val, min_idx] = min(M) % a szélsőérték indexének (is) lekérdezése
```

#### Gauss elemináció

1. Rendezd az egyenletet `A * x = b` alakba.
2. `x = A\b`

#### Lapítás, Átméretezés

`squeeze(A)` returns an array with the same elements as the input array M, but with dimensions of length 1 removed.

# Grafikonok <a name = "graphics"></a>

## 1. Figure (rajzvászon)

```matlab
fig = figure;
```

## 2. Subplot (rácsrendszer) *- opcionális*

```matlab
subplot(grid_width, grid_height, [use these indexes]);
```

## 3. Plot (grafikon)

Adottak az azonos hosszúságú xs és ys tömbök.

```matlab
pl = plot(xs,ys, '<style using code>', <style name>,<style value>, <style name>,<style value>, ...);
```

### Több vonal

Adottak az azonos hosszúságú xs és ys tömbök.

```matlab
hold on; % Az előző plot újrafelhasználása a hold off;-ig
pl1 = plot(xs,ys, '-g', 'LineWidth',2);
pl2 = plot(xs,ys, '-b', 'LineWidth',2);
hold off;
```

### Megadható tulajdonságok

```matlab
xlim([t(1), t(end)]); % min x, max x
ylim([-2, 1]); % min y, max y

title('upperLeft', 'FontWeight', 'bold');
xlabel('t');
ylabel('y value');

p.Marker = 'square';
p.MarkerSize = 7;
p.MarkerEdgeColor = 'red';

p.Color = 'blue';
p.LineStyle = '--';
p.LineWidth = 2;

grid on;

axes = gca; axes.FontSize = 12; % tengelyek értékeinek felirata

legend({'zsakmany', 'ragadozo'}, 'Location', 'northeast');
```

# Analízis <a name = "calculus"></a>

## Deriválás <a name = "derivate"></a>

Matematikai def.: Két mérési pont közötti érték különbség és idő különbség hányadosa (dx / dt)

A számolásban segítséghet a `diff(vector, nth_derivate?, dimension?)` függvény, amely megadja az egymás után mért értékek közötti különbségét.

## Integrálás - adatsor <a name = "integrate1"></a>

Ha van N darab x adatunk és N darab Y adatunk, akkor a MatLab az adatok közötti résekre trapézokat tud illeszeni és így meg tudja határozni az adatok által leírt függény alatti területet.

```matlab
xs = 0:0.001:10; % ez egy vektor
ys = sin(xs); % ez is egy vektor
area = trapz(xs, ys);
```
## Integrálás - függvény <a name = "integrate2"></a>

Sokkal pontosabb eredményt ad, mint az előző módszer.

Csak akkor működik, ha ismert a függvény

```matlab
integral(@(t) 2*t, domain(1), domain(end))
```

## Differenciál egyenletek <a name = "diffequation"></a>

Amíg a függvény az egy `x -> y` leképzés, a DE-ek a függvény előző értékéből adják meg a következő felvett értéket.

#### ode45

Az ode45 függvény visszaállítja a függvényt a tspan intervallumban a differenciálegyenletből.

Továbbá meg kell neki adni az `y0=f(t_start)` értéket is

```matlab
ode45(diff_eq, [t_start t_end], y0);
```

## Első rendű diff. egyenlet

1. meg lesz adva valami egyenlet.

def.: `y' = dy/dt` (lehet be kell helyettesítened)

2. rendezd az egyenletet a következő alakra: `y' = ...`

3. készíts egy anon függvényt: `f = @(t, y) ...`, ahol a három pont a felső egyenlet jobb oldala.

A függvény t paraméterér szinte biztosan nem fogod használni!

4. hívd meg az ode45 függvényt, ami kiszámít néhány pontot a tspan intervallumon és visszaadja ezeket

`[T, Y] = ode45(f, tspan, y0);`

(a T az x tengely, az Y az f(T))

## Vegyes diff. egyenletek

A [préda-ragadozó feladatban](https://github.com/tomitheninja/matlab/blob/master/hf/ragadozo_zsakmany.md) volt ilyen.

Lényege, hogy a változás egy másik de. egyenlet megoldásától is függ.

Emiatt ahelyett, hogy külön-külön meghívnád az ode45-öt a két függvényre, egy függvényként kell azt kezelni.

Ezt úgy lehet elérni, hogy az y helyén egy két (vagy több) elemű vektort használsz

```matlab
t = [0, 20]; % t_start = 0; t_end = 20
y_0 = [100, 150]; % y1_0 = 100; y2_0 = 150

 fv = @(t, y) [1-y(2)/300; -1+y(1)/200] .* y; % y egy vektor
 [T, Y] = ode45(fv, t, y_0);
 Y1 = Y(:, 1); % az első függvény értékei
 Y2 = Y(:, 2); % a második függvény értékei
 ```
 
 ## Másodrendű DE-ek
 
 Ha y második deriváltja is szerepel benne
 
 próbálj meg [innen](https://moodle.ppke.hu/pluginfile.php/20734/mod_resource/content/2/06_lab_matlab_2021.pdf) másolni 

#### konstans szorzók:

ennek a változónak -> ez a szorzója

```
x'' -> m % ezzel le kell majd osztani a teljes egyenlőséget
x'  -> A % = y(2)
x   -> B % = y(1)
1   -> C
```

#### Az egyenlet rendezése

`m * x'' = C - A*x' - B*x` : x másodrendű deriváltjának kifejezése

`x'' = C/m - A*x'/m - B*x/m` : y vektor használata

`[y(2); C/m - A*y(2)/m - B*y(1)/m]` : ezt már meg tudja oldani a MatLab

#### MatLab

```matlab
f = @(~, y) [y(2); C/m - A*y(2)/m - B*y(1)/m];
tspan = [0 250];
y0 = 1; // X
dy0 = 0.2; // X'
[T, Y] = ode45(F, [0 250], [y0 dy0]);
```

# 3D ábrázolás <a name = "3d"></a>

## Pontok vagy vonalak <a name = "3ddots"></a>

- To plot a set of coordinates connected by **line segments**, specify X, Y, and Z **as vectors** of the same length.

- To plot multiple **sets of coordinates** on the same set of axes, specify at least one of X, Y, or Z **as a matrix** and the others as vectors.

- én sem értem, hogy miről pofázik. Minden esetre, ha megadsz Stylenak egy '.'-ot, akkor pont halmaz lesz belőle.

```matlab
figure;
t = 0:pi/50:10*pi;
st = t .* sin(2*t);
ct = t .* cos(2*t);
plot3(st,ct,t);
title('fagyi');
xlabel('x = sin(t)');
ylabel('y = cos(t)');
zlabel('z = t');
```

## Felület <a name="3dsurf"></a>

Az alábbi megoldások mindegyike azon alapszik, hogy kifeszítűnk a térben egy XY síkot és ehhez rendelünk egy harmadik pontot.

Egy téglalap alakú síkot a `meshgrid(t_x, t_y)` függvény hozza létre.

A meshgrid mind a kettő bemenete egy intervallumot vár, amely megadja, hogy a sík ezen a tengelyen mettől-meddig nyúljon.

Leggyakrabban a `linspace(mettől, meddig, hányPont)` függvényhívással szoktuk jellemezni a tengelyt.

A meshgrid függvénynek két kimete van, az `[X, Y]` változók. A Z változót ebből kell majd kifejezni.

### Egyszerű felület

```matlab
[X, Y] = meshgrid(linspace(0, 10, 100), linspace(0, 15, 100)); % 100 pontból álló 0-től 10-ig terjedő tengelyek
% az X és Y mátrixok, ezért minden műveletet (+, -, *, /, ^) előjelezni kell egy ponttal
Z = sin(-X) ./ X; % a harmadik koodináta kifejezése az előző kettőből
surf(X, Y, Z);

view(param1, param2); % látószög beállítása

```

### Megjelenítési formák

- `surf(X, Y, Z)` = surface (felület)
- `contour(X, Y, Z)` = domborzati térkép (felülnézetben)
- `contour3(X, Y, Z)` = domborzati térkép (de 3D-ben)
- `surfc(X, Y, Z)` = surface, alatta (a síkon) egy contour leképzés
- `mesh(X, Y, Z)` = átlátszóbb surface

#### Vegyítés

`hold on;` módban tetszőlegesen mixelhető, de némelyik mód elbassza a `view`-t.

Gyakori probléma, a domborzati térkép feliratozása:

```matlab
[C, h] = contour3(X, Y, Z);
clabel(C, h);
```

# Struktúrák <a name = "structs"></a>

## Cellatömb <a name = "cellarray"></a>

Egy axb méretű mátrix, amelynek elemei nem azonos típusúak (lehet benne szám, szöveg vagy igazából bármi és vegyesen is)

```matlab
cellaTomb = {
  t, [], []; ... % egy változó értéke, majd két üres cella
  'alma', 'fa', '11'; ... % szöveges adatok
  3, 4, 5 ... % számok
};
```

Így lehet lekérni egy elemét:
```matlab
myFour = cellaTomb{3, 2};
```

## Struktúra <a name = "struct"></a>

Cellatömb, de nem index alapú indexeléssel.

Szóval az mint c++ struct, de nem kell előre definiálni

```c++
// c++
struct XYNev
{
  int x;
  int y;
  string nev;
};

XYNev aPontom{ x=0, y=0, nev="Origo" };

cout << aPontom.nev << endl;
```

```matlab
% matlab
aPontom = struct('x', 0, 'y', 0, 'nev', 'Origo');
disp(aPontom.nev);
```

## Struktúra tömb <a name = "structArray"></a>

Leggyakrabban nem csak egy struktúrát akarunk létrehozni, hanem sokat, egyszerre

```matlab
strukturaTomb = [ ...
    struct('x', t, 'y', sin(3*t), 'nev', 'Sin(3x)') ...
    struct('x', t, 'y', cos(5*t), 'nev', 'Cos(5x)') ...
    struct('x', t, 'y', sin(3*t) .* cos(5*t), 'nev', 'Sin(3x)*Cos(5x)')];
```

# Fájlok <a name="files"></a>

## Adat olvasása / írása

```matlab
% Tell the system how to open the file
fIn = fopen(bemenetiFajlNev, 'r');
  % r = read (default)
  % w = write
  % a = append
  % ... in help fopen

% N adat beolvasása (több dimenzió esetén a mátrix külön sorába teszi őket) 
% [21 inf] jelentése = 21 oszlop, az összes sor
data = fscanf(fIn, '%f', [6]);
  % '%f' = float (valós szám)
  % '%d' = digit
  % ... in help fscanf

  
% adatok írása fájlba. jajj
fwrite(fOut, data, dataType?);
  % ... help write / precision
  
% ##### NE FELEJTSD EL BEZÁRNI A FÁJLT #####
fclose(fIn);
```

## Változó mentése .m fájlba

Egy paranccsal el lehet menteni egy változó állapotát

Ugyan ilyen könnyen vissza lehet tölteni azt

```matlab
myVarName = magic(3);
save('filename.mat', 'myVarName'); % lementi a 'myVarName' nevű változó értékét a fájlba

clear; % kitörli a program memóriáját

load('filename.mat'); % betölti a fájlba elmentett változókat
```

