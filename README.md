# POO1
Cerinta tema: 

Clasa "polinom" (polinom cu coeficienti double), avand:
-
membri privati pentru vectorul de coeficienti si numarul de elemente
(sau gradul);
-
constructori pentru initializare si copiere (sa poata lucra si cu
numere reale (privite ca polinoame de grad
0));
-
metode publice pentru citire si afisare;
-
metoda
-
operator public de atribuire =; se scrie in doua variante,
pentru a putea lucra cu operanzi
polinom
-
polinom, polinom
-
real (un
real fiind privit ca un polinom de grad 0);
-
metoda
-
operator publica [] (furnizeaza o referinta la coeficientul
de
grad n din polinom); implementarea
se va face astfel incat daca p este
obiect "polinom", i este un intreg si x un real, sa fie posibile
constructii ca:
"cin>>p[i]", "cout<<p[i]", "p[i]=x", "x=p[i]", cu
efectul obisnuit;
-
operatori friend: + (in dou
a variante: suma si polinomul insusi (unar)),
-
(in doua variante: diferenta si
opusul (unar)), * (inmultirea),
/ (catul), % (restul), ^ (ridicarea la putere naturala), +=,
-
=, *=, /=
(cu efectul
cunoscut), == (testarea egalitatii), != (testarea
neegalit
atii), !(daca polinomul este nul furnizeaza intregul 0,
altfel
furnizeaza intregul 1); operatorii binari +,
-
, *, /, +=,
-
=, *=, /=,
==, != se vor
scrie in trei variante, pentru
a putea lucra cu operanzi
polinom
-
polinom, real
-
pol
inom, polinom
-
real (realul
e
privit ca
polinom de grad 0);
-
metoda
-
operator publica () pentru calcului valorii polinomului intr
-
un
punct;
-
functie friend "grad" care furnizeaza gradul.
Program pentru determinarea celui mai mare divizor comun a doua polinoame
(algoritum
ul lui Euclid).
Pentru clasa "polinom" se va scrie un fisier header si un fisier de
implementare. Acesta va contine si
definitia polinomului "X". Programul 
se va scrie ca un project.
