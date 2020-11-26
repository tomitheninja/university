# The most common algorithms implemented on int vector-s

! If you want to use these algorithms on real numbers (float, double) you will need to change the code at multiple locations

```fix
real number math and comparision is "buggy".
eg.: 0.1 + 0.2 == 0.30000000000000004
so when comparing real numbers always use an epsilon error margin like:
// eps := 0.01
// got result := 0.30000000000000004
// expected result := 0.3
abs(expected result - got result) < eps

-> if their difference is really small then they are equal
```

* [sum](./sum.md) összegzés tétele
* [count](./count.md) megszámlálás tétele
* [any / some](./any.md) eldöntés tétele
* [find index](./find_idx.md) kiválasztás tétele
* [find value](./find_val.md) keresés tétele
* [copy](./copy.md) másolás tétele
* [filter](./filter.md) kiválogatás tétele
* [smallest / largest](./min_max.md) szélsőérték keresés
* [index of smallest / largest](./min_max_idx.md) szélsőérték indexének keresése (ez inkább struct-oknál hasznos)
* [bubble sort](./bubble_sort.md) buborék rendezés
* [reverse](./reverse.md) tükrözés
