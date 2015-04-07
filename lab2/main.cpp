//Materie: Elemente de Grafica pe Calculator 
//Tema: Tema 1 - Geometry Wars
//
//Nume: Rusu
//Prenume: Alina Nicoleta
//Grupa: 331CC

#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Transform3D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

#define PI 3.14159265358979323846
#define inf 1000000
using namespace std;

Visual2D *v1d1;
//-------------------------------------------------------//

Line2D *lright;
Line2D *lleft;
Line2D *lup;
Line2D *ldown;

//--------------------------------------------------------//
//nava:
Circle2D *circle;
Polygon2D *nava;
Polygon2D *arma;

//--------------------------------------------------------//
//inamici:
Rectangle2D *inamic11, *inamic12; Rectangle2D *inamic21;
Rectangle2D *inamic11_rezerva, *inamic12_rezerva; 
Polygon2D *inamic22;
Rectangle2D *inamic31, *inamic32, *inamic33, *inamic34; Polygon2D *inamic41, *inamic42, *inamic43, *inamic44;
Circle2D *inamic45;

//superinamic
Polygon2D *s1;
Circle2D *s2, *s3, *s4, *s5, *s0;

//-------------------------------------------------------//

//coordonate centru nava
float xCentru = 0;
float yCentru = 0;

//coordonate varf arma
float xVarf;
float yVarf;
//coordonate baza arma
float xArma1;
float yArma1;
float xArma2;
float yArma2;

//coordonate centru inamic
float b11x, b12x, b13x, b14x;
float b11y, b12y, b13y, b14y;
float b21x, b22x, b23x, b24x;
float b21y, b22y, b23y, b24y;

//pt nava
int raza = 4.2;
int lg_arma = 10.8;
int b = 1; // 1 daca e activat, 0 daca nu e activata arma

float x, y;

//unghiul unde am ajuns:
float u = 0;
//unghiul dupa care se face rotatia:
float unghi=0;
//--------------------------------------------------------//

float dx1 = 0;
float dy1 = 0;
float dx2 = 0;
float dy2 = 0;
float dx3 = 0;
float dy3 = 0;
float dx4 = 0;
float dy4 = 0;

//float dx = 0;
//float dy = 0;

//razele inamicilor
float r1 = 2.5;
float r2 = 2;
float r3 = 3;
float r4 = 3;

float pasxi1, pasxi2, pasxi3, pasxi4, pasx, pasxi1_rezerva;
float pasyi1, pasyi2, pasyi3, pasyi4, pasy, pasyi1_rezerva;

//int xi, xi2, xi3, x4;
//int yi, yi2, yi3, y4;
//------------------------------------------------------//

//loviri superinamic
int hit = 0;

//pt scor
int scor = 0;

//pt vieti
int life = 3;

//pt nivel
int level = 1;

bool activati1 = true;
bool activati2 = true;
bool activati3 = true;
bool activati4 = true;

bool activatl1 = true;
bool activatl2 = true;
bool activatl3 = true;
bool activatl4 = true;

bool GO_activat = false;
bool AC_activat = false;

bool Lactivat = true;

bool activS = true;

//score
Text* scorA,*scorAa;
//life
Text* lifeA,*lifeAa;
//nivele
Text* levelA,*levelAa;
Text *GO;
Text *AC;

//timpi
clock_t start=clock();
clock_t acum, acum2, acum3, acum4;

//functie care calculeaza distanta 
float get_dist(float x1, float x2, float y1, float y2) {
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

//functie care face rotatia 
float rotX(float xCentru, float nrx, float yCentru, float nry, float u) {
	return (xCentru +nrx)*cos(u)- (yCentru + nry)*sin(u) + xCentru - xCentru * cos(u) +yCentru * sin(u); 
}

float rotY(float xCentru, float nrx, float yCentru, float nry, float u) {
	return (xCentru +nrx)*sin(u) + (yCentru + nry)*cos(u) + yCentru - xCentru * sin(u) - yCentru * cos(u); 
}

int kill_nava (float xCentru, float yCentru, float xInamic, float yInamic, float r) {
	float d;
	d = get_dist(xCentru, xInamic, yCentru, yInamic);
	if (d <= r + raza) return 1;
	else return 0;
}

int kill(float xCentru, float yCentru, float xInamic, float yInamic, float r, float u) {
	float xArma1, xAxrma2, xVarf, b11x, b12x, b13x, b14x, b21x, b22x, b23x, b24x;
	float yArma1, yAxrma2, yVarf, b11y, b12y, b13y, b14y, b21y, b22y, b23y, b24y;
	float d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
	xArma1= rotX(xCentru, 5, yCentru, 3, u);
	yArma1= rotY(xCentru, 5, yCentru, 3, u);
	xArma2 = rotX(xCentru, 5, yCentru, -3, u);
	yArma2 = rotY(xCentru, 5, yCentru, -3, u);
	xVarf = rotX(xCentru, 15, yCentru, 0, u);
	yVarf = rotY(xCentru, 15, yCentru, 0, u);
	b11x = rotX(xCentru, 6.5, yCentru, 2.5, u);
	b11y = rotY(xCentru, 6.5, yCentru, 2.5, u);	
	b12x = rotX(xCentru, 8.5, yCentru, 1.5, u);
	b12y = rotY(xCentru, 8.5, yCentru, 1.5, u);
	b13x = rotX(xCentru, 10, yCentru, 1, u);
	b13y = rotY(xCentru, 10, yCentru, 1, u);
	b14x = rotX(xCentru, 12, yCentru, 0.75, u);
	b14y = rotY(xCentru, 12, yCentru, 0.75, u);
	b21x = rotX(xCentru, 6.5, yCentru, -2.5, u);	
	b21y = rotY(xCentru, 6.5, yCentru, -2.5, u);		
	b22x = rotX(xCentru, 8.5, yCentru, -1.5, u);	
	b22y = rotY(xCentru, 8.5, yCentru, -1.5, u);		
	b23x = rotX(xCentru, 10, yCentru, -1, u);	
	b23y = rotY(xCentru, 10, yCentru, -1, u);
	b24x = rotX(xCentru, 12, yCentru, -0.75, u);
	b24y = rotY(xCentru, 12, yCentru, -0.75, u);

	d1 = get_dist(b11x,xInamic,b11y,yInamic);
	d2 = get_dist(b12x,xInamic,b12y,yInamic);
	d3 = get_dist(b13x,xInamic,b13y,yInamic);
	d4 = get_dist(b14x,xInamic,b14y,yInamic);
	d5 = get_dist(b21x,xInamic,b21y,yInamic);
	d6 =  get_dist(b22x,xInamic,b22y,yInamic);
	d7 = get_dist(b23x,xInamic,b23y,yInamic);
	d11 = get_dist(b24x,xInamic,b24y,yInamic);
	d8 = get_dist(xArma1,xInamic,yArma1,yInamic);
	d9 = get_dist(xArma2,xInamic,yArma2,yInamic);
	d10 = get_dist(xVarf,xInamic,yVarf,yInamic); 

	if (d1 < r || d2 < r || d3 < r || d4 < r || d5 < r || d6 < r || d7 < r || d8 < r || d9 < r || d10 < r )
		return 1;
	else return 0;
}


//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{
	v1d1 = new Visual2D(-80,-80,80,80,0,0,DrawingWindow::width,DrawingWindow::height); 
	v1d1->tipTran(true);
	v1d1->cadruPoarta(Color(1,0,0));
	v1d1->cadruFereastra(Color(0,1,1));
	addVisual2D(v1d1);

	lright = new Line2D(Point2D(65,65),Point2D(65,-65),Color(1,0,1));
	addObject2D_to_Visual2D(lright,v1d1);
	lleft = new Line2D(Point2D(-65,65),Point2D(-65,-65),Color(1,0,1));
	addObject2D_to_Visual2D(lleft,v1d1);
	lup = new Line2D(Point2D(-65,65),Point2D(65,65),Color(1,0,1));
	addObject2D_to_Visual2D(lup,v1d1);
	ldown = new Line2D(Point2D(-65,-65),Point2D(65,-65),Color(1,0,1));
	addObject2D_to_Visual2D(ldown,v1d1);

	//nava:
	circle= new Circle2D(Point2D(0,0),4.2,Color(1,0,1),false);
	nava = new Polygon2D(Color(1,0,1),false);
	nava->addPoint(Point2D(3,1.5));  //1
	nava->addPoint(Point2D(0,3.5));  //2
	nava->addPoint(Point2D(-2.5,0)); //3
	nava->addPoint(Point2D(0,-3.5)); //4
	nava->addPoint(Point2D(3,-1.5)); //5
	nava->addPoint(Point2D(1,-2.5)); //6
	nava->addPoint(Point2D(-0.5,0)); //7
	nava->addPoint(Point2D(1,2.5));  //8
	arma = new Polygon2D(Color(1,0,1),true);
	arma->addPoint(Point2D(5,2.7));
	arma->addPoint(Point2D(5,-2.7));
	arma->addPoint(Point2D(16,0));

	//inamic 1:
	inamic11 = new Rectangle2D (Point2D(-55, 52), 3, 3, Color(0,1,1), false);// addObject2D(inamic11);
	inamic12 = new Rectangle2D (Point2D(-53, 50), 3, 3, Color(0,1,1), false);// addObject2D(inamic12);
	pasxi1 = -53.5;
	pasyi1 = 52.5;

	//inamic 2:
	inamic21 = new Rectangle2D (Point2D(51, 51), 4, 4, Color(0,1,0), false); 
	inamic22 = new Polygon2D(Color(1, 1, 0),true);
	inamic22->addPoint(Point2D(51, 53)); //1
	inamic22->addPoint(Point2D(53, 55));   //2
	inamic22->addPoint(Point2D(55, 53)); //3
	inamic22->addPoint(Point2D(53, 51));
	pasxi2 = 53;
	pasyi2 = 53;

	//inamic 3:
	inamic31 = new Rectangle2D (Point2D(47, -55), 2, 2, Color(1,1,0), false);
	inamic32 = new Rectangle2D (Point2D(47, -53), 2, 2, Color(1,0,0), true);
	inamic33 = new Rectangle2D (Point2D(49, -53), 2, 2, Color(1,1,0), false);
	inamic34 = new Rectangle2D (Point2D(51, -53), 2, 2, Color(1,0,0), true); 
	pasxi3 = 50;
	pasyi3 = -54;

	//inamic 4:
	inamic41 = new Polygon2D(Color(1,1,0),false);
	inamic41->addPoint(Point2D(-52, -49));   //1
	inamic41->addPoint(Point2D(-50, -49));   //2
	inamic41->addPoint(Point2D(-52, -51.5)); //3
	inamic42 = new Polygon2D(Color(1,1,0),false);
	inamic42->addPoint(Point2D(-51.5, -52));
	inamic42->addPoint(Point2D(-49, -52));   //1
	inamic42->addPoint(Point2D(-49, -54));   //2
	inamic43 = new Polygon2D(Color(1,1,0),false);
	inamic43->addPoint(Point2D(-52, -55));   //3
	inamic43->addPoint(Point2D(-54, -55));
	inamic43->addPoint(Point2D(-52, -52.5)); //1
	inamic44 = new Polygon2D(Color(1,1,0),false);
	inamic44->addPoint(Point2D(-52.5, -52)); //2
	inamic44->addPoint(Point2D(-55, -52));  //3
	inamic44->addPoint(Point2D(-55, -50));
	inamic45= new Circle2D(Point2D(-52, -52),0.4,Color(1,0,0),true);
	pasxi4 = -52;
	pasyi4 = -52;

	addObject2D_to_Visual2D(circle,v1d1);
	addObject2D_to_Visual2D(nava,v1d1);
	addObject2D_to_Visual2D(arma,v1d1);

	addObject2D_to_Visual2D(inamic11,v1d1);
	addObject2D_to_Visual2D(inamic12,v1d1);

	addObject2D_to_Visual2D(inamic21,v1d1);
	addObject2D_to_Visual2D(inamic22,v1d1);

	addObject2D_to_Visual2D(inamic31,v1d1);
	addObject2D_to_Visual2D(inamic32,v1d1);
	addObject2D_to_Visual2D(inamic33,v1d1);
	addObject2D_to_Visual2D(inamic34,v1d1);		
	addObject2D_to_Visual2D(inamic41,v1d1);
	addObject2D_to_Visual2D(inamic42,v1d1);
	addObject2D_to_Visual2D(inamic43,v1d1);
	addObject2D_to_Visual2D(inamic44,v1d1);
	addObject2D_to_Visual2D(inamic45,v1d1);

	// afisare scor:
	scorA = new Text("Score",Point2D(30,70),Color(0,1,0),BITMAP_9_BY_15);
	addText_to_Visual2D(scorA,v1d1);

	scorAa = new Text("1",Point2D(30,75),Color(0,1,0),BITMAP_9_BY_15);
	addText_to_Visual2D(scorAa,v1d1);

	//afisare vieti
	lifeA = new Text("Life",Point2D(10,70),Color(0,1,0),BITMAP_9_BY_15);
	addText_to_Visual2D(lifeA,v1d1);

	lifeAa = new Text("3",Point2D(10,75),Color(0,1,0),BITMAP_9_BY_15);
	addText_to_Visual2D(lifeAa,v1d1);

	//afisare nivel
	levelA = new Text("Level",Point2D(-10,70),Color(0,1,0),BITMAP_9_BY_15);
	addText_to_Visual2D(levelA,v1d1);

	levelAa = new Text("1",Point2D(-10,75),Color(0,1,0),BITMAP_9_BY_15);
	addText_to_Visual2D(levelAa,v1d1);

	//afisare "GAME OVER"
	GO = new Text("GAME OVER",Point2D(-12,2),Color(0,1,0),BITMAP_9_BY_15);
	//addText_to_Visual2D(GO,v1d1);

	//afisare "AI CASTIGAT !!"
	AC = new Text("AI CASTIGAT !!",Point2D(-12,2),Color(0,1,0),BITMAP_9_BY_15);
	//addText_to_Visual2D(AC,v1d1);
}


//functia care permite animatia
void DrawingWindow::onIdle()
{
	//miscare inamic 1
	acum=clock();
	double duration =(double)(acum - start) / CLOCKS_PER_SEC;
	//cout <<"durata" <<duration << endl;
	int dur=(int)duration;
	if((!activati1) && dur % 20 == 0)
	{
		addObject2D_to_Visual2D(inamic11,v1d1);
		addObject2D_to_Visual2D(inamic12,v1d1);
		activati1=true;
	}

	//---
	dx1 = (xCentru - pasxi1)* 0.001f; // dx = cu cat se muta pe x inamicul
	dy1 = (yCentru - pasyi1)* 0.001f; // dy = cu cat se muta pe y inamicul

	pasxi1 += dx1;
	pasyi1 += dy1;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx1, dy1);
	Transform2D::applyTransform_o(inamic11);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx1,dy1);
	Transform2D::applyTransform_o(inamic12);
	//----------------------------------------------------------------------

	//miscare inamic 2
	acum2=clock();
	double duration2 =(double)(acum2 - start) / CLOCKS_PER_SEC;
	//cout <<"durata2" <<duration2 << endl;
	int dur2=(int)duration2;
	if((!activati2) && dur2 % 20 == 0 )
	{
		addObject2D_to_Visual2D(inamic21,v1d1);
		addObject2D_to_Visual2D(inamic22,v1d1);
		activati2=true;
	}

	//--
	dx2 = (xCentru - pasxi2) * 0.001f;
	dy2 = (yCentru - pasyi2) * 0.001f;

	pasxi2 += dx2;
	pasyi2 += dy2;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx2, dy2);
	Transform2D::applyTransform_o(inamic21);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx2,dy2);
	Transform2D::applyTransform_o(inamic22);
	//-------------------------------------------------------------------------

	//miscare inamic 3
	acum3=clock();
	double duration3 =(double)(acum3 - start) / CLOCKS_PER_SEC;
	//cout <<"durata3" <<duration3 << endl;
	int dur3=(int)duration3;
	if((!activati3) && dur3 % 15==0)
	{
		addObject2D_to_Visual2D(inamic31,v1d1);
		addObject2D_to_Visual2D(inamic32,v1d1);
		addObject2D_to_Visual2D(inamic33,v1d1);
		addObject2D_to_Visual2D(inamic34,v1d1);
		activati3=true;
	}

	//--
	dx3 = (xCentru - pasxi3) * 0.001f;
	dy3 = (yCentru - pasyi3) * 0.001f;

	pasxi3 += dx3;
	pasyi3 += dy3;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx3, -dx3);
	Transform2D::applyTransform_o(inamic31);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx3, -dx3);
	Transform2D::applyTransform_o(inamic32);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx3, -dx3);
	Transform2D::applyTransform_o(inamic33);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx3, -dx3);
	Transform2D::applyTransform_o(inamic34);
	//-----------------------------------------------------------------------

	//miscare inamic 4
	acum4=clock();
	double duration4 =(double)(acum4 - start) / CLOCKS_PER_SEC;
	int dur4=(int)duration4;
	if((!activati4) && dur4 % 15 == 0 )
	{
		addObject2D_to_Visual2D(inamic41,v1d1);
		addObject2D_to_Visual2D(inamic42,v1d1);
		addObject2D_to_Visual2D(inamic43,v1d1);
		addObject2D_to_Visual2D(inamic44,v1d1);
		addObject2D_to_Visual2D(inamic45,v1d1);
		activati4=true;
	}

	//--
	dx4 = (xCentru - pasxi4) * 0.001f; // dx = cat vrei sa te muti pe x
	dy4 = (yCentru - pasyi4) * 0.001f; // dy = cat vrei sa te muti pe y

	pasxi4 += dx4;
	pasyi4 += dy4;

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx4, dy4);
	Transform2D::applyTransform_o(inamic41);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx4, dy4);
	Transform2D::applyTransform_o(inamic42);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx4, dy4);
	Transform2D::applyTransform_o(inamic43);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx4, dy4);
	Transform2D::applyTransform_o(inamic44);

	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(dx4, dy4);
	Transform2D::applyTransform_o(inamic45);
	//--------------------------------------------------------------------------------------

	//moarte inamic 1
	if(kill(xCentru, yCentru, pasxi1, pasyi1, r1, u) == 1 && b==1) {
		removeObject2D_from_Visual2D(inamic11,v1d1);
		removeObject2D_from_Visual2D(inamic12,v1d1);
		if(activati1) {
			scor += 1; 
			activati1=false;
			char buff[100];
			removeText_from_Visual2D(scorAa,v1d1);	
			scorAa = new Text(itoa(scor,buff,10),Point2D(30,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(scorAa,v1d1);
		}
	}

	//moarte inamic 2
	if(kill(xCentru, yCentru, pasxi2, pasyi2, r2, u) == 1 && b==1) {
		removeObject2D_from_Visual2D(inamic21,v1d1);
		removeObject2D_from_Visual2D(inamic22,v1d1);
		if(activati2) {
			scor += 1; 
			activati2=false;
			char buff2[100];
			removeText_from_Visual2D(scorAa,v1d1);	
			scorAa = new Text(itoa(scor,buff2,10),Point2D(30,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(scorAa,v1d1);
		}
	}

	//moarte inamic 3
	if(kill(xCentru, yCentru, pasxi3, pasyi3, r3, u) == 1 && b==1) {
		removeObject2D_from_Visual2D(inamic31,v1d1);
		removeObject2D_from_Visual2D(inamic32,v1d1);
		removeObject2D_from_Visual2D(inamic33,v1d1);
		removeObject2D_from_Visual2D(inamic34,v1d1);
		if(activati3) {
			scor += 1; 
			activati3=false;
			char buff3[100];
			removeText_from_Visual2D(scorAa,v1d1);	
			scorAa = new Text(itoa(scor,buff3,10),Point2D(30,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(scorAa,v1d1);
		}
	}

	//moarte inamic 4
	if(kill(xCentru, yCentru, pasxi4, pasyi4, r4, u) == 1 && b==1) {
		removeObject2D_from_Visual2D(inamic41,v1d1);
		removeObject2D_from_Visual2D(inamic42,v1d1);
		removeObject2D_from_Visual2D(inamic43,v1d1);
		removeObject2D_from_Visual2D(inamic44,v1d1);
		removeObject2D_from_Visual2D(inamic45,v1d1);
		if(activati4) {
			scor += 1; 
			activati4=false;
			char buff4[100];
			removeText_from_Visual2D(scorAa,v1d1);	
			scorAa = new Text(itoa(scor,buff4,10),Point2D(30,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(scorAa,v1d1);
		}
	}

	//nava e omorata de inamicul 1
	if (kill_nava (xCentru, yCentru, pasxi1, pasyi1, r1) == 1) {
		if(activatl1) {
			life--; 
			activatl1=false;
			char buffl[100];
			removeText_from_Visual2D(lifeAa,v1d1);	
			lifeAa = new Text(itoa(life,buffl,10),Point2D(10,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(lifeAa,v1d1);
		}
	}

	//nava e omorata de inamicul 2
	if (kill_nava (xCentru, yCentru, pasxi2, pasyi2, r2) == 1) {
		if (activatl2) {
			//life--;
			activatl2 = false;
			char buffl2[100];
			removeText_from_Visual2D(lifeAa,v1d1);	
			lifeAa = new Text(itoa(life,buffl2,10),Point2D(10,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(lifeAa,v1d1);
		}
	}

	//nava e omorata de inamicul 3
	if (kill_nava (xCentru, yCentru, pasxi3, pasyi4, r3) == 1) {
		if (activatl3) {
			life--;
			activatl3 = false;
			char buffl3[100];
			removeText_from_Visual2D(lifeAa,v1d1);	
			lifeAa = new Text(itoa(life,buffl3,10),Point2D(10,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(lifeAa,v1d1);
		}
	}

	//nava e omorata de inamicul 4
	if (kill_nava (xCentru, yCentru, pasxi4, pasyi4, r4) == 1) {
		if (activatl4) {
			life--;
			activatl4 = false;
			char buffl4[100];
			removeText_from_Visual2D(lifeAa,v1d1);	
			lifeAa = new Text(itoa(life,buffl4,10),Point2D(10,75),Color(0,1,0),BITMAP_9_BY_15);
			addText_to_Visual2D(lifeAa,v1d1);
		}
	}

	//GAME OVER
	if (life == 0) {
		removeObject2D_from_Visual2D(circle,v1d1);
		removeObject2D_from_Visual2D(nava,v1d1);
		removeObject2D_from_Visual2D(arma,v1d1);
		removeObject2D_from_Visual2D(inamic11,v1d1);
		removeObject2D_from_Visual2D(inamic12,v1d1);
		removeObject2D_from_Visual2D(inamic21,v1d1);
		removeObject2D_from_Visual2D(inamic22,v1d1);
		removeObject2D_from_Visual2D(inamic31,v1d1);
		removeObject2D_from_Visual2D(inamic32,v1d1);
		removeObject2D_from_Visual2D(inamic33,v1d1);
		removeObject2D_from_Visual2D(inamic34,v1d1);
		removeObject2D_from_Visual2D(inamic41,v1d1);
		removeObject2D_from_Visual2D(inamic42,v1d1);
		removeObject2D_from_Visual2D(inamic43,v1d1);
		removeObject2D_from_Visual2D(inamic44,v1d1);
		removeObject2D_from_Visual2D(inamic45,v1d1);
		removeText_from_Visual2D(scorA,v1d1);
		removeText_from_Visual2D(scorAa,v1d1);
		removeText_from_Visual2D(lifeA,v1d1);
		removeText_from_Visual2D(lifeAa,v1d1);
		removeText_from_Visual2D(levelA,v1d1);
		removeText_from_Visual2D(levelAa,v1d1);
		GO_activat = true;
		activati1 = false;
		activati2 = false;
		activati3 = false;
		activati4 = false;
	}


	if (GO_activat) {
		addText_to_Visual2D(GO,v1d1);
	}

	if (scor >= 20) {
		AC_activat = true;
	}

	if (AC_activat) {
		addText_to_Visual2D(AC,v1d1);
		removeObject2D_from_Visual2D(circle,v1d1);
		removeObject2D_from_Visual2D(nava,v1d1);
		removeObject2D_from_Visual2D(arma,v1d1);
		removeObject2D_from_Visual2D(inamic11,v1d1);
		removeObject2D_from_Visual2D(inamic12,v1d1);
		removeObject2D_from_Visual2D(inamic21,v1d1);
		removeObject2D_from_Visual2D(inamic22,v1d1);
		removeObject2D_from_Visual2D(inamic31,v1d1);
		removeObject2D_from_Visual2D(inamic32,v1d1);
		removeObject2D_from_Visual2D(inamic33,v1d1);
		removeObject2D_from_Visual2D(inamic34,v1d1);
		removeObject2D_from_Visual2D(inamic41,v1d1);
		removeObject2D_from_Visual2D(inamic42,v1d1);
		removeObject2D_from_Visual2D(inamic43,v1d1);
		removeObject2D_from_Visual2D(inamic44,v1d1);
		removeObject2D_from_Visual2D(inamic45,v1d1);
		removeText_from_Visual2D(scorA,v1d1);
		removeText_from_Visual2D(scorAa,v1d1);
		removeText_from_Visual2D(lifeA,v1d1);
		removeText_from_Visual2D(lifeAa,v1d1);
		removeText_from_Visual2D(levelA,v1d1);
		removeText_from_Visual2D(levelAa,v1d1);
	}

}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{
	v1d1->poarta(0,0,width,height); 
}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	switch(key)
	{
	case 27 : exit(0);
	case GLUT_KEY_RIGHT: {
		u -= PI/9;
		unghi=-PI/9;		
		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-xCentru, -yCentru);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(xCentru, yCentru);
		Transform2D::applyTransform_o(nava);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-xCentru, -yCentru);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(xCentru, yCentru);
		Transform2D::applyTransform_o(circle);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-xCentru, -yCentru);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(xCentru, yCentru);
		Transform2D::applyTransform_o(arma);
		break;
						 }
	case GLUT_KEY_LEFT:  {
		u += PI/9;
		unghi=PI/9;
		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-xCentru, -yCentru);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(xCentru, yCentru);
		Transform2D::applyTransform_o(nava);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-xCentru,-yCentru);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(xCentru, yCentru);
		Transform2D::applyTransform_o(circle);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-xCentru, -yCentru);
		Transform2D::rotateMatrix(unghi);
		Transform2D::translateMatrix(xCentru, yCentru);
		Transform2D::applyTransform_o(arma);
		break;
						 }
	case GLUT_KEY_UP:    {

		cout <<"arma " << arma->transf_points.back()->x << " " << arma->transf_points.back()->y << endl;
		cout <<"centru " << xCentru << " " << yCentru << endl;

		x = arma->transf_points.back()->x-xCentru;
		y = arma->transf_points.back()->y-yCentru;

		// limite
		if (b == 1) {
			x*=0.2;
			y*=0.2;
			if ((xCentru + raza + lg_arma > 62)) {
				if(((cos(u) >=0))) x=0;
			}
			if ((xCentru - raza - lg_arma < -62)) {
				if(((cos(u) <=0))) x=0;
			}
			if ((yCentru + raza + lg_arma > 62) ) {
				if(((sin(u) >=0))) y=0;
			}
			if ((yCentru - raza - lg_arma < -62)) {
				if(((sin(u) <=0))) y=0;
			}
		}

		else
		{
			x*=0.6;
			y*=0.6;
			if ((xCentru + raza > 60)) {
				if(cos(u) >= 0) x=0;
			}
			if ((xCentru - raza < -60)) {
				if(cos(u) <= 0) x=0;
			}
			if ((yCentru + raza > 60) ) {
				if(sin(u) >= 0) y=0;
			}
			if ((yCentru - raza < -60)) {
				if(sin(u) <= 0) y=0;
			}
		}

		/*x*=0.2;
		y*=0.2;*/
		xCentru += x;
		yCentru += y;

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(x, y);
		Transform2D::applyTransform_o(nava);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(x, y);
		Transform2D::applyTransform_o(circle);

		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(x, y);
		Transform2D::applyTransform_o(arma);
		break;
						 }

	case GLUT_KEY_DOWN: {
		if(b==1) {
			removeObject2D_from_Visual2D(arma,v1d1);
			b=0;
		}
		else {
			addObject2D_to_Visual2D(arma,v1d1);
			b=1;
		}
		break;
						}
	}
}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{

}

int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 700,700, 250, 0, "Tema 1 EGC");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	return 0;
}