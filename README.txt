Materie: Elemente de Grafica pe Calculator 
Tema: Tema 1 - Geometry Wars

Nume: Rusu
Prenume: Alina Nicoleta
Grupa: 331CC

Cuprins:

1. Cerinta
2. Input Tastatura
3. Implementare
4. Continutul Arhivei
5. Testare
6. Functionalitati

1. Cerinta

-Utilizand framework-ul oferit la laborator, am implementat un joc de tipul Geometry Wars.

-Terenul de joc este suprafata pe care se desfasoara jocul si am reprezentat-o printr-un dreptunghi
de dimensiuni mari relativ la restul componentelor jocului.

-Jucatorul este reprezentat in acest joc de o nava spatiala. Nava este construita ca un cerc, avand 
in interiorul sau un poligon.

2. Input Tastatura

Taste :

-"Key LEFT" - rotire a navei la stanga
-"Key RIGHT" - rotire a navei la dreapta
-"Key UP" - deplasare inainte
-"Key DOWN" - activare/dezactivare a armei navei

3. Implementare

--Am lucrat in Microsoft visual studio 2012 pe sistemul de operare: Windows 7 (64 bit);

--Am lucrat pe scheletul laboratorului 2.

--Consider important de precizat cum am implementat coliziunea dintre arma navei si inamici:

-am luat 4 puncte pe una din laturile exterioare ale triungiului armei plus inca 4 pe cealalta plus varful triunghiului armei si punctele de la baza triunghiului armei

-am facut o functie care calculeaza distanta de la centrul fiecarui tip de inamici (cei 4) care returneaza 1 daca exista o distanta mai mica decat raza cercului navei si 0 daca nu.

--O scurta SCHEMA a programului:

----- NAVA ----
Nava e formata din:
	-cerc
	-poligon
	-arma (triunghi):
		-se dezactiveaza/activeaza la apasarea tastei "DOWN"
		-creste viteza navei cand arma nu e activata si scade cand e activata

	Nava are urmatoarele proprietati:
		-pozitionata in (0, 0) initial;
		-deplasare inainte
		-rotatie
		-coliziune cu inamici
		-nu iese din terenul de joc
		-moare si se afiseaza "GAME OVER" cand isi pierde cele 3 vieti
		-castiga si se afiseaza "AI CASTIGAT !!" cand acumuleaza un scor de 15 puncte


---- INAMICI ----
	-4 tipuri de inamici de diferite forme geometrice

	Inamicii au urmatoarele proprietati:
		-pozitionati initial in cele 4 colturi ale ecranului
		-sunt omorati de nava
		-cand mor, dispar
		-dupa un intersal de cateva secunde, date in cod, ei se translateaza pe ecran din nou, avand rolul unor alti inamici, atacand in continuare


---- SCOR ----
	-initial e 1
	-creste la coliziunea navei cu inamicii, nava fiind cea care ataca
	-creste cu un nr > 1 atunci cand inamicii noi aparuti se translateaza sub arma
	-la scor >= 15, nava castiga


---- VIETI ----
	-initial 3
	-scad cu 1 la coliziunea inamic-nava (inamicii ataca)
	-scad cu 1 cand inamicul nou aparut se translateaza sub nava;
 

---- NIVEL ----- 
	-initial 1
	-(neterminat, apartine bonusului)

4. Continutul Arhivei

-In arhiva este scheletul laboratorului 2 plus codul meu pe care l-am scris in totalitate in main, in Transform2D.cpp am scris matricile pentru translatie si rotatie iar in DrawingWindow.cpp am schimbat culoarea fundalului;
-README.

5.Testare

-Tema a fost testata si rulata pe IDE Visiual Studio 2012 in Windows 7.

6. Functionalitati

-Nava se afla initial in centrul ferestrei (0, 0). Nava se roteste, se deplaseaza inainte, ataca cu ajutorul burghiului.

-Inamicii se deplaseaza intotdeauna spre nava incercand sa o distruga. Acest lucru de petrece atunci cand nava isi pierde cele 3 vieti. 

-O viata se pierde atunci cand un inamic atinge nava.
Scopul navei este sa omoare inamicii, acestia mor cand nava ii atinge cu arma sa (triunghiul), iar cand nava acumuleaza un puctaj mai mare de 15 puncte, castiga. Un punct este acumulat cand omoara un inamic. (coliziuni intre nava - inamici).
