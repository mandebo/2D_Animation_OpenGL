
/*

*/
#include < windows.h> //basic header files
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <GL\glut.h> // handle windows for you
#include <math.h>
#include <string>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500
#define PI 3.141592653
#define FPS 30
#define DEG2RAD 3.14159/180.0

int x = 100;
int y = 50;
int dx = 2;
int dy = 2;
int state = 1;
float angle = 1;
float at = 0.1;
float  counter = 0;
float s_counter = 0;
float speed = 0;
float cloud = 0;
float dc = 1;
float reflect = 180;
float db = 0;
float db2 = 0;
float ab = 0;
float i = 0;
int framenumber = 30;
float nongle = 10.0;
float db3 = 0;
float ab3 = 0;
float pingu = 0;
float pingu1 = 0;
GLfloat R_angle = 0;
float fly = 0;
float walk = 0;
float speed1 = 0;
float speed2 = 0;
float speed3 = 0;
//penguin swim
float sw = 0;
float swim = 1;
//new variable
float brad = 0;
float brad2 = 0;
float ux = 0;
float uc = 1;
int dex = 2;

//circle
void nGon(int n, int x, int y, int r) {


	double inc = 1 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 1 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();

}

void nGon2(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

//characters
void gunter(int x, int y)
{

	// outer badan
	glColor3ub(0, 0, 80);
	glPushMatrix();
	//glScalef(-1, 1, 1);
	glTranslatef(pingu, pingu1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x, y + 120 / 2);
	glEnd();

	//outer kepala

	glColor3ub(0, 0, 80);
	nGon(200, x + 50 / 2, y + 120 / 2, 50 / 2);

	//inner badan

	glColor3ub(255, 255, 180);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30 / 2, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x + 25 / 2, y + 120 / 2);
	glEnd();

	//inner kepala
	glColor3ub(255, 255, 180);
	nGon(200, x + 63 / 2, y + 120 / 2, 38 / 2);

	//mata kiri

	glColor3ub(0, 0, 0);
	nGon2(200, x + 55 / 2, y + 120 / 2, 10 / 2);

	// right eyes
	glColor3ub(0, 0, 0);
	nGon2(200, x + 100 / 2, y + 120 / 2, 10 / 2);

	// left eye bowls
	glColor3ub(255, 255, 255);
	nGon2(200, x + 60 / 2, y + 120 / 2, 5 / 2);

	//right  eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 105 / 2, y + 120 / 2, 5 / 2);

	//beaks
	glColor3ub(250, 169, 69);

	glBegin(GL_POLYGON);
	glVertex2i(x + 80 / 2, y + 120 / 2);
	glVertex2i(x + 120 / 2, y + 100 / 2);
	glVertex2i(x + 80 / 2, y + 95 / 2);



	glEnd();


	//left hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x, y + 100 / 2);

	glVertex2i(x - 25 / 2, y + 50 / 2);
	glVertex2i(x, y + 60 / 2);


	glEnd();


	//right hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 100 / 2);
	glVertex2i(x + 125 / 2, y + 50 / 2);
	glVertex2i(x + 100 / 2, y + 60 / 2);

	glEnd();
	glPopMatrix();







}

void fisherman(int x, int y)
{

	//shoulder
	glColor3ub(175, 238, 238);
	glPushMatrix();
	glTranslatef(db, 0, 0);
	glTranslatef(db2, ab, 0);
	glBegin(GL_POLYGON);

	glVertex2i(x - 20 / 2, y + 80 / 2);
	glVertex2i(x + 120 / 2, y + 80 / 2);
	glVertex2i(x + 110 / 2, y + 170 / 2);
	glVertex2i(x - 10 / 2, y + 170 / 2);
	glEnd();

	//left hand
	glColor3ub(175, 238, 238);
	glBegin(GL_POLYGON);
	glVertex2i(x - 50 / 2, y + 95 / 2);
	glVertex2i(x - 30 / 2, y + 95 / 2);
	glVertex2i(x - 10 / 2, y + 135 / 2);
	glVertex2i(x - 10 / 2, y + 170 / 2);
	glEnd();

	//right hand
	glColor3ub(175, 238, 238);
	glBegin(GL_POLYGON);
	glVertex2i(x + 130 / 2, y + 95 / 2);
	glVertex2i(x + 150 / 2, y + 95 / 2);
	glVertex2i(x + 110 / 2, y + 170 / 2);
	glVertex2i(x + 110 / 2, y + 135 / 2);
	glEnd();

	//left palm
	glColor3ub(255, 203, 164);
	nGon2(250, x + 140 / 2, y + 95 / 2, 10 / 2);

	//right palm
	glColor3ub(255, 203, 164);
	nGon2(250, x - 40 / 2, y + 95 / 2, 10 / 2);




	//lower body
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);

	glVertex2i(x - 20 / 2, y + 65 / 2);
	glVertex2i(x - 15 / 2, y + 35 / 2);
	glVertex2i(x + 110 / 2, y + 35 / 2);
	glVertex2i(x + 120 / 2, y + 65 / 2);

	glEnd();

	// left leg
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);
	glVertex2i(x - 5 / 2, y + 20 / 2);
	glVertex2i(x + 10 / 2, y + 20 / 2);
	glVertex2i(x + 10 / 2, y + 35 / 2);
	glVertex2i(x - 5 / 2, y + 35 / 2);
	glEnd();

	//right leg
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);
	glVertex2i(x + 90 / 2, y + 20 / 2);
	glVertex2i(x + 105 / 2, y + 20 / 2);
	glVertex2i(x + 105 / 2, y + 35 / 2);
	glVertex2i(x + 90 / 2, y + 35 / 2);
	glEnd();

	//left shoes
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x - 10 / 2, y + 10 / 2);
	glVertex2i(x + 10 / 2, y + 10 / 2);
	glVertex2i(x + 10 / 2, y + 20 / 2);
	glVertex2i(x - 5 / 2, y + 20 / 2);
	glEnd();

	//right shoes
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 90 / 2, y + 10 / 2);
	glVertex2i(x + 110 / 2, y + 10 / 2);
	glVertex2i(x + 105 / 2, y + 20 / 2);
	glVertex2i(x + 90 / 2, y + 20 / 2);
	glEnd();




	//belt
	glColor3ub(0, 100, 80);
	glBegin(GL_POLYGON);
	glVertex2i(x - 25 / 2, y + 65 / 2);
	glVertex2i(x + 125 / 2, y + 65 / 2);
	glVertex2i(x + 125 / 2, y + 80 / 2);
	glVertex2i(x - 25 / 2, y + 80 / 2);
	glEnd();


	//belt bulk
	glColor3ub(220, 220, 220);
	glBegin(GL_POLYGON);
	glVertex2i(x - 3.5, y + 65 / 2);
	glVertex2i(x, y + 65 / 2);
	glVertex2i(x, y + 80 / 2);
	glVertex2i(x - 5, y + 80 / 2);

	glEnd();

	//right belt bulk
	glColor3ub(220, 220, 220);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 65 / 2);
	glVertex2i(x + 110 / 2, y + 65 / 2);
	glVertex2i(x + 110 / 2, y + 80 / 2);
	glVertex2i(x + 100 / 2, y + 80 / 2);
	glEnd();



	//strap left
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10 / 2, y + 80 / 2);
	glVertex2i(x, y + 80 / 2);
	glVertex2i(x, y + 170 / 2);
	glVertex2i(x, y + 170 / 2);
	glEnd();

	//strap right
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 80 / 2);
	glVertex2i(x + 110 / 2, y + 80 / 2);
	glVertex2i(x + 100 / 2, y + 170 / 2);
	glVertex2i(x + 98 / 2, y + 170 / 2);
	glEnd();

	//kepala
	glColor3ub(255, 203, 164);
	glBegin(GL_POLYGON);
	glVertex2i(x, y + 150 / 2);
	glVertex2i(x + 100 / 2, y + 150 / 2);
	glVertex2i(x + 100 / 2, y + 250 / 2);
	glVertex2i(x, y + 250 / 2);
	glEnd();

	//left sideburn
	glBegin(GL_POLYGON);
	glColor3ub(165, 42, 42);
	glVertex2i(x, y + 200 / 2);
	glVertex2i(x + 10 / 2, y + 250 / 2);
	glVertex2i(x, y + 250 / 2);
	glEnd();

	//right sideburn
	glBegin(GL_POLYGON);
	glColor3ub(165, 42, 42);
	glVertex2i(x + 100 / 2, y + 200 / 2);
	glVertex2i(x + 90 / 2, y + 250 / 2);
	glVertex2i(x + 100 / 2, y + 250 / 2);
	glEnd();

	//hat punya bawah
	glBegin(GL_POLYGON);
	glColor3ub(139, 0, 0);
	glVertex2i(x - 5 / 2, y + 250 / 2);
	glVertex2i(x + 105 / 2, y + 250 / 2);
	glVertex2i(x + 105 / 2, y + 260 / 2);
	glVertex2i(x - 5 / 2, y + 260 / 2);
	glEnd();
	//hat punya atas
	glColor3ub(180, 0, 0);
	nGon(250, x + 50 / 2, y + 260 / 2, 48 / 2);

	//mata
	glColor3ub(0, 0, 0);
	nGon2(250, x + 30 / 2, y + 220 / 2, 4 / 2);
	nGon2(250, x + 70 / 2, y + 220 / 2, 4 / 2);

	//left eyebrows
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 25 / 2, y + 225 / 2);
	glVertex2i(x + 35 / 2, y + 228 / 2);
	glVertex2i(x + 35 / 2, y + 232 / 2);
	glVertex2i(x + 25 / 2, y + 230 / 2);
	glEnd();

	//right eyebrows
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 75 / 2, y + 225 / 2);
	glVertex2i(x + 65 / 2, y + 228 / 2);
	glVertex2i(x + 65 / 2, y + 232 / 2);
	glVertex2i(x + 75 / 2, y + 230 / 2);
	glEnd();


	//hidung
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x + 50 / 2, y + 200 / 2);
	glVertex2i(x + 50 / 2, y + 190 / 2);
	glEnd();

	glPopMatrix();









}

void fisherman2(int x, int y)
{

	//shoulder
	glColor3ub(175, 238, 238);
	glPushMatrix();
	glTranslatef(walk, fly, 0);

	glTranslatef(db3, ab3, 0);
	glBegin(GL_POLYGON);

	glVertex2i(x - 20 / 2, y + 80 / 2);
	glVertex2i(x + 120 / 2, y + 80 / 2);
	glVertex2i(x + 110 / 2, y + 170 / 2);
	glVertex2i(x - 10 / 2, y + 170 / 2);
	glEnd();
	//left hand




	glColor3ub(175, 238, 238);

	glBegin(GL_POLYGON);
	glVertex2i(x - 50 / 2, y + 95 / 2);
	glVertex2i(x - 30 / 2, y + 95 / 2);
	glVertex2i(x - 10 / 2, y + 135 / 2);
	glVertex2i(x - 10 / 2, y + 170 / 2);
	glEnd();


	//right hand
	glColor3ub(175, 238, 238);
	glBegin(GL_POLYGON);
	glVertex2i(x + 130 / 2, y + 95 / 2);
	glVertex2i(x + 150 / 2, y + 95 / 2);
	glVertex2i(x + 110 / 2, y + 170 / 2);
	glVertex2i(x + 110 / 2, y + 135 / 2);
	glEnd();

	//left palm
	glColor3ub(255, 203, 164);
	nGon2(250, x + 140 / 2, y + 95 / 2, 10 / 2);

	//right palm
	glColor3ub(255, 203, 164);
	nGon2(250, x - 40 / 2, y + 95 / 2, 10 / 2);




	//lower body
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);

	glVertex2i(x - 20 / 2, y + 65 / 2);
	glVertex2i(x - 15 / 2, y + 35 / 2);
	glVertex2i(x + 110 / 2, y + 35 / 2);
	glVertex2i(x + 120 / 2, y + 65 / 2);

	glEnd();

	// left leg
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);
	glVertex2i(x - 5 / 2, y + 20 / 2);
	glVertex2i(x + 10 / 2, y + 20 / 2);
	glVertex2i(x + 10 / 2, y + 35 / 2);
	glVertex2i(x - 5 / 2, y + 35 / 2);
	glEnd();

	//right leg
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);
	glVertex2i(x + 90 / 2, y + 20 / 2);
	glVertex2i(x + 105 / 2, y + 20 / 2);
	glVertex2i(x + 105 / 2, y + 35 / 2);
	glVertex2i(x + 90 / 2, y + 35 / 2);
	glEnd();

	//left shoes
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x - 10 / 2, y + 10 / 2);
	glVertex2i(x + 10 / 2, y + 10 / 2);
	glVertex2i(x + 10 / 2, y + 20 / 2);
	glVertex2i(x - 5 / 2, y + 20 / 2);
	glEnd();

	//right shoes
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 90 / 2, y + 10 / 2);
	glVertex2i(x + 110 / 2, y + 10 / 2);
	glVertex2i(x + 105 / 2, y + 20 / 2);
	glVertex2i(x + 90 / 2, y + 20 / 2);
	glEnd();




	//belt
	glColor3ub(0, 100, 80);
	glBegin(GL_POLYGON);
	glVertex2i(x - 25 / 2, y + 65 / 2);
	glVertex2i(x + 125 / 2, y + 65 / 2);
	glVertex2i(x + 125 / 2, y + 80 / 2);
	glVertex2i(x - 25 / 2, y + 80 / 2);
	glEnd();


	//belt bulk
	glColor3ub(220, 220, 220);
	glBegin(GL_POLYGON);
	glVertex2i(x - 3.5, y + 65 / 2);
	glVertex2i(x, y + 65 / 2);
	glVertex2i(x, y + 80 / 2);
	glVertex2i(x - 5, y + 80 / 2);

	glEnd();

	//right belt bulk
	glColor3ub(220, 220, 220);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 65 / 2);
	glVertex2i(x + 110 / 2, y + 65 / 2);
	glVertex2i(x + 110 / 2, y + 80 / 2);
	glVertex2i(x + 100 / 2, y + 80 / 2);
	glEnd();



	//strap left
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10 / 2, y + 80 / 2);
	glVertex2i(x, y + 80 / 2);
	glVertex2i(x, y + 170 / 2);
	glVertex2i(x, y + 170 / 2);
	glEnd();

	//strap right
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 80 / 2);
	glVertex2i(x + 110 / 2, y + 80 / 2);
	glVertex2i(x + 100 / 2, y + 170 / 2);
	glVertex2i(x + 98 / 2, y + 170 / 2);
	glEnd();

	//kepala
	glColor3ub(255, 203, 164);
	glBegin(GL_POLYGON);
	glVertex2i(x, y + 150 / 2);
	glVertex2i(x + 100 / 2, y + 150 / 2);
	glVertex2i(x + 100 / 2, y + 250 / 2);
	glVertex2i(x, y + 250 / 2);
	glEnd();

	//left sideburn
	glBegin(GL_POLYGON);
	glColor3ub(165, 42, 42);
	glVertex2i(x, y + 200 / 2);
	glVertex2i(x + 10 / 2, y + 250 / 2);
	glVertex2i(x, y + 250 / 2);
	glEnd();

	//right sideburn
	glBegin(GL_POLYGON);
	glColor3ub(165, 42, 42);
	glVertex2i(x + 100 / 2, y + 200 / 2);
	glVertex2i(x + 90 / 2, y + 250 / 2);
	glVertex2i(x + 100 / 2, y + 250 / 2);
	glEnd();

	//hat punya bawah
	glBegin(GL_POLYGON);
	glColor3ub(139, 0, 0);
	glVertex2i(x - 5 / 2, y + 250 / 2);
	glVertex2i(x + 105 / 2, y + 250 / 2);
	glVertex2i(x + 105 / 2, y + 260 / 2);
	glVertex2i(x - 5 / 2, y + 260 / 2);
	glEnd();
	//hat punya atas
	glColor3ub(180, 0, 0);
	nGon(250, x + 50 / 2, y + 260 / 2, 48 / 2);

	//mata
	glColor3ub(0, 0, 0);
	nGon2(250, x + 30 / 2, y + 220 / 2, 4 / 2);
	nGon2(250, x + 70 / 2, y + 220 / 2, 4 / 2);

	//left eyebrows
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 25 / 2, y + 225 / 2);
	glVertex2i(x + 35 / 2, y + 228 / 2);
	glVertex2i(x + 35 / 2, y + 232 / 2);
	glVertex2i(x + 25 / 2, y + 230 / 2);
	glEnd();

	//right eyebrows
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 75 / 2, y + 225 / 2);
	glVertex2i(x + 65 / 2, y + 228 / 2);
	glVertex2i(x + 65 / 2, y + 232 / 2);
	glVertex2i(x + 75 / 2, y + 230 / 2);
	glEnd();


	//hidung
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x + 50 / 2, y + 200 / 2);
	glVertex2i(x + 50 / 2, y + 190 / 2);
	glEnd();

	glPopMatrix();









}

void fisherman3(int x, int y)
{

	//shoulder
	glColor3ub(175, 238, 238);
	glPushMatrix();
	glTranslatef(brad, 0, 0);
	glTranslatef(brad2, ux, 0);
	glBegin(GL_POLYGON);

	glVertex2i(x - 20 / 2, y + 80 / 2);
	glVertex2i(x + 120 / 2, y + 80 / 2);
	glVertex2i(x + 110 / 2, y + 170 / 2);
	glVertex2i(x - 10 / 2, y + 170 / 2);
	glEnd();

	//left hand
	glColor3ub(175, 238, 238);
	glBegin(GL_POLYGON);
	glVertex2i(x - 50 / 2, y + 95 / 2);
	glVertex2i(x - 30 / 2, y + 95 / 2);
	glVertex2i(x - 10 / 2, y + 135 / 2);
	glVertex2i(x - 10 / 2, y + 170 / 2);
	glEnd();

	//right hand
	glColor3ub(175, 238, 238);
	glBegin(GL_POLYGON);
	glVertex2i(x + 130 / 2, y + 95 / 2);
	glVertex2i(x + 150 / 2, y + 95 / 2);
	glVertex2i(x + 110 / 2, y + 170 / 2);
	glVertex2i(x + 110 / 2, y + 135 / 2);
	glEnd();

	//left palm
	glColor3ub(255, 203, 164);
	nGon2(250, x + 140 / 2, y + 95 / 2, 10 / 2);

	//right palm
	glColor3ub(255, 203, 164);
	nGon2(250, x - 40 / 2, y + 95 / 2, 10 / 2);




	//lower body
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);

	glVertex2i(x - 20 / 2, y + 65 / 2);
	glVertex2i(x - 15 / 2, y + 35 / 2);
	glVertex2i(x + 110 / 2, y + 35 / 2);
	glVertex2i(x + 120 / 2, y + 65 / 2);

	glEnd();

	// left leg
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);
	glVertex2i(x - 5 / 2, y + 20 / 2);
	glVertex2i(x + 10 / 2, y + 20 / 2);
	glVertex2i(x + 10 / 2, y + 35 / 2);
	glVertex2i(x - 5 / 2, y + 35 / 2);
	glEnd();

	//right leg
	glColor3ub(0, 100, 100);
	glBegin(GL_POLYGON);
	glVertex2i(x + 90 / 2, y + 20 / 2);
	glVertex2i(x + 105 / 2, y + 20 / 2);
	glVertex2i(x + 105 / 2, y + 35 / 2);
	glVertex2i(x + 90 / 2, y + 35 / 2);
	glEnd();

	//left shoes
	glColor3ub(255, 203, 164);
	glBegin(GL_POLYGON);
	glVertex2i(x - 10 / 2, y + 10 / 2);
	glVertex2i(x + 10 / 2, y + 10 / 2);
	glVertex2i(x + 10 / 2, y + 20 / 2);
	glVertex2i(x - 5 / 2, y + 20 / 2);
	glEnd();

	//right shoes
	glColor3ub(255, 203, 164);
	glBegin(GL_POLYGON);
	glVertex2i(x + 90 / 2, y + 10 / 2);
	glVertex2i(x + 110 / 2, y + 10 / 2);
	glVertex2i(x + 105 / 2, y + 20 / 2);
	glVertex2i(x + 90 / 2, y + 20 / 2);
	glEnd();




	//belt
	glColor3ub(0, 100, 80);
	glBegin(GL_POLYGON);
	glVertex2i(x - 25 / 2, y + 65 / 2);
	glVertex2i(x + 125 / 2, y + 65 / 2);
	glVertex2i(x + 125 / 2, y + 80 / 2);
	glVertex2i(x - 25 / 2, y + 80 / 2);
	glEnd();


	//belt bulk
	glColor3ub(220, 220, 220);
	glBegin(GL_POLYGON);
	glVertex2i(x - 3.5, y + 65 / 2);
	glVertex2i(x, y + 65 / 2);
	glVertex2i(x, y + 80 / 2);
	glVertex2i(x - 5, y + 80 / 2);

	glEnd();

	//right belt bulk
	glColor3ub(220, 220, 220);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 65 / 2);
	glVertex2i(x + 110 / 2, y + 65 / 2);
	glVertex2i(x + 110 / 2, y + 80 / 2);
	glVertex2i(x + 100 / 2, y + 80 / 2);
	glEnd();



	//strap left
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10 / 2, y + 80 / 2);
	glVertex2i(x, y + 80 / 2);
	glVertex2i(x, y + 170 / 2);
	glVertex2i(x, y + 170 / 2);
	glEnd();

	//strap right
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 80 / 2);
	glVertex2i(x + 110 / 2, y + 80 / 2);
	glVertex2i(x + 100 / 2, y + 170 / 2);
	glVertex2i(x + 98 / 2, y + 170 / 2);
	glEnd();

	//kepala
	glColor3ub(255, 203, 164);
	glBegin(GL_POLYGON);
	glVertex2i(x, y + 150 / 2);
	glVertex2i(x + 100 / 2, y + 150 / 2);
	glVertex2i(x + 100 / 2, y + 250 / 2);
	glVertex2i(x, y + 250 / 2);
	glEnd();

	//left sideburn
	glBegin(GL_POLYGON);
	glColor3ub(165, 42, 42);
	glVertex2i(x, y + 200 / 2);
	glVertex2i(x + 10 / 2, y + 250 / 2);
	glVertex2i(x, y + 250 / 2);
	glEnd();

	//right sideburn
	glBegin(GL_POLYGON);
	glColor3ub(165, 42, 42);
	glVertex2i(x + 100 / 2, y + 200 / 2);
	glVertex2i(x + 90 / 2, y + 250 / 2);
	glVertex2i(x + 100 / 2, y + 250 / 2);
	glEnd();

	//hat punya bawah
	glBegin(GL_POLYGON);
	glColor3ub(139, 0, 0);
	glVertex2i(x - 5 / 2, y + 250 / 2);
	glVertex2i(x + 105 / 2, y + 250 / 2);
	glVertex2i(x + 105 / 2, y + 260 / 2);
	glVertex2i(x - 5 / 2, y + 260 / 2);
	glEnd();
	//hat punya atas
	glColor3ub(180, 0, 0);
	nGon(250, x + 50 / 2, y + 260 / 2, 48 / 2);

	//mata
	glColor3ub(0, 0, 0);
	nGon2(250, x + 30 / 2, y + 220 / 2, 4 / 2);
	nGon2(250, x + 70 / 2, y + 220 / 2, 4 / 2);

	//left eyebrows
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 25 / 2, y + 225 / 2);
	glVertex2i(x + 35 / 2, y + 228 / 2);
	glVertex2i(x + 35 / 2, y + 232 / 2);
	glVertex2i(x + 25 / 2, y + 230 / 2);
	glEnd();

	//right eyebrows
	glColor3ub(165, 42, 42);
	glBegin(GL_POLYGON);
	glVertex2i(x + 75 / 2, y + 225 / 2);
	glVertex2i(x + 65 / 2, y + 228 / 2);
	glVertex2i(x + 65 / 2, y + 232 / 2);
	glVertex2i(x + 75 / 2, y + 230 / 2);
	glEnd();


	//hidung
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x + 50 / 2, y + 200 / 2);
	glVertex2i(x + 50 / 2, y + 190 / 2);
	glEnd();

	glPopMatrix();









}

void triangle()
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(600, 250, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-600, -250, 0);
	glColor3ub(255, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(500, 250);
	glVertex2f(700, 250);
	glVertex2f(600, 350);

	glEnd();
	glPopMatrix();
}

//spinning propeller
void propeller(int x, int y)
{
	//pole
	glPushMatrix();
	glTranslatef(db, ab, 0);
	glColor3ub(192, 192, 192);

	glBegin(GL_POLYGON);
	glVertex2i(x + 240 / 2, y + 25 / 2);
	glVertex2i(x + 280 / 2, y + 25 / 2);
	glVertex2i(x + 280 / 2, y + 40 / 2);
	glVertex2i(x + 243 / 2, y + 40 / 2);

	glEnd();

	glPushMatrix();
	glTranslatef(x + 280 / 2, y + 32.5 / 2, 0);
	glRotatef(R_angle, 0, 0, 1);
	glTranslatef(-(x + 280 / 2), -(y + 32.5 / 2), 0);


	//triangles
	glColor3ub(192, 192, 192);

	glBegin(GL_POLYGON);
	glVertex2i(x + 280 / 2, y + 32.5 / 2);
	glVertex2i(x + 295 / 2, y + 55.5 / 2);
	glVertex2i(x + 265 / 2, y + 55.5 / 2);
	glEnd();
	//nGon(250,x + 280 / 2,y + 55.5/2, 7);

	//TRIANGLES 2

	glBegin(GL_POLYGON);
	glVertex2i(x + 280 / 2, y + 32.5 / 2);
	glVertex2i(x + 295 / 2, y + 7.5 / 2);
	glVertex2i(x + 265 / 2, y + 7.5 / 2);
	glEnd();

	//nGon2(250, x + 280 / 2, y + 7.5 / 2, 7);



	glColor3ub(192, 192, 192);
	nGon2(250, x + 280 / 2, y + 32.5 / 2, 6);

	glPopMatrix();
	glPopMatrix();

}

void propeller2(int x, int y)
{
	//pole
	glPushMatrix();
	glTranslatef(db3, ab3, 0);
	glColor3ub(192, 192, 192);

	glBegin(GL_POLYGON);
	glVertex2i(x + 240 / 2, y + 25 / 2);
	glVertex2i(x + 280 / 2, y + 25 / 2);
	glVertex2i(x + 280 / 2, y + 40 / 2);
	glVertex2i(x + 243 / 2, y + 40 / 2);

	glEnd();

	glPushMatrix();
	glTranslatef(x + 280 / 2, y + 32.5 / 2, 0);
	glRotatef(R_angle, 0, 0, 1);
	glTranslatef(-(x + 280 / 2), -(y + 32.5 / 2), 0);


	//triangles
	glColor3ub(192, 192, 192);

	glBegin(GL_POLYGON);
	glVertex2i(x + 280 / 2, y + 32.5 / 2);
	glVertex2i(x + 295 / 2, y + 55.5 / 2);
	glVertex2i(x + 265 / 2, y + 55.5 / 2);
	glEnd();
	//nGon(250, x + 280 / 2, y + 7.5 / 2, 7);

	//TRIANGLES 2

	glBegin(GL_POLYGON);
	glVertex2i(x + 280 / 2, y + 32.5 / 2);
	glVertex2i(x + 295 / 2, y + 7.5 / 2);
	glVertex2i(x + 265 / 2, y + 7.5 / 2);
	glEnd();
	//nGon2(250, x + 280 / 2, y + 7.5 / 2, 7);




	glColor3ub(192, 192, 192);
	nGon2(250, x + 280 / 2, y + 32.5 / 2, 7);

	glPopMatrix();
	glPopMatrix();

}
//boat
void boat(int x, int y)
{


	glColor3ub(210, 105, 30);
	glPushMatrix();

	glTranslatef(db, ab, 0);
	//body of sampan
	glBegin(GL_POLYGON);
	glVertex2i(x - 30 / 2, y + 10 / 2);
	glVertex2i(x + 240 / 2, y + 10 / 2);
	glVertex2i(x + 250 / 2, y + 80 / 2);
	glVertex2i(x - 70 / 2, y + 100 / 2);
	glEnd();

	//decoration boat


	glColor3ub(0, 0, 0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(x - 58 / 2, y + 70 / 2);
	glVertex2i(x + 243 / 2, y + 60 / 2);
	glEnd();

	glColor3ub(0, 0, 0);
	glLineWidth(2.0);

	glBegin(GL_LINES);
	glVertex2i(x - 37 / 2, y + 35 / 2);
	glVertex2i(x + 248 / 2, y + 35 / 2);
	glEnd();

	glPopMatrix();
	propeller(x, y);

}

void boat2(int x, int y)
{


	glColor3ub(210, 105, 30);
	//body of sampan
	glPushMatrix();
	glTranslatef(db3, ab3, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x - 30 / 2, y + 10 / 2);
	glVertex2i(x + 240 / 2, y + 10 / 2);
	glVertex2i(x + 250 / 2, y + 80 / 2);
	glVertex2i(x - 70 / 2, y + 100 / 2);
	glEnd();

	//decoration boat


	glColor3ub(0, 0, 0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(x - 58 / 2, y + 70 / 2);
	glVertex2i(x + 243 / 2, y + 60 / 2);
	glEnd();

	glColor3ub(0, 0, 0);
	glLineWidth(2.0);

	glBegin(GL_LINES);
	glVertex2i(x - 37 / 2, y + 35 / 2);
	glVertex2i(x + 248 / 2, y + 35 / 2);
	glEnd();

	glPopMatrix();
	propeller2(x, y);
}

void boat3(int x, int y)
{

	glColor3ub(210, 105, 30);
	glPushMatrix();
	glTranslatef(brad, 0, 0);
	//body of sampan
	glBegin(GL_POLYGON);
	glVertex2i(x - 30 / 2, y + 10 / 2);
	glVertex2i(x + 240 / 2, y + 10 / 2);
	glVertex2i(x + 280 / 2, y + 100 / 2);
	glVertex2i(x - 40 / 2, y + 80 / 2);
	glEnd();

	//decoration boat


	glColor3ub(0, 0, 0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(x - 40 / 2, y + 60 / 2);
	glVertex2i(x + 270 / 2, y + 80 / 2);
	glEnd();

	glColor3ub(0, 0, 0);
	glLineWidth(2.0);

	glBegin(GL_LINES);
	glVertex2i(x - 40 / 2, y + 40 / 2);
	glVertex2i(x + 260 / 2, y + 50 / 2);
	glEnd();

	glPopMatrix();

}

//i close bezier function
/*
//curve function
void bezier(GLfloat x[], GLfloat y[])
{
	//GLfloat x[4], y[4];
	GLfloat xt[200], yt[200], t;
	int i;

	//x[0] = 50; x[1] = 150; x[2] = 200; x[3] = 300;
	//y[0] = 250; y[1] = 500; y[2] = 450; y[3] = 450;

	for (i = 0, t = 0; t <= 1; i++, t = t + 0.01)
	{
		xt[i] = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
		yt[i] = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];

	}
	glPointSize(4);
	glColor3b(0, 0, 0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < 200; i++)
	{
		glVertex2i(xt[i], yt[i]);
	}
	glEnd();
}
*/

void cage()
{

	//below cage
	glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	glColor3ub(96, 130, 182);
	glBegin(GL_POLYGON);
	glVertex2i(x - 20, y - 5);
	glVertex2i(x + 145, y - 5);
	glVertex2i(x + 145, y + 5);
	glVertex2i(x - 20, y + 5);

	glEnd();

	//middle cage
	glColor3ub(173, 216, 230);
	glBegin(GL_POLYGON);
	glVertex2i(x - 20, y + 5);
	glVertex2i(x - 15, y + 5);
	glVertex2i(x - 15, y + 170);
	glVertex2i(x - 20, y + 170);
	glEnd();



	glColor3ub(173, 216, 230);
	glBegin(GL_POLYGON);
	glVertex2i(x + 20, y + 5);
	glVertex2i(x + 25, y + 5);
	glVertex2i(x + 25, y + 170);
	glVertex2i(x + 20, y + 170);
	glEnd();



	glColor3ub(173, 216, 230);
	glBegin(GL_POLYGON);
	glVertex2i(x + 60, y + 5);
	glVertex2i(x + 65, y + 5);
	glVertex2i(x + 65, y + 170);
	glVertex2i(x + 60, y + 170);
	glEnd();


	glColor3ub(173, 216, 230);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100, y + 5);
	glVertex2i(x + 105, y + 5);
	glVertex2i(x + 105, y + 170);
	glVertex2i(x + 100, y + 170);
	glEnd();



	glColor3ub(173, 216, 230);
	glBegin(GL_POLYGON);
	glVertex2i(x + 140, y + 5);
	glVertex2i(x + 145, y + 5);
	glVertex2i(x + 145, y + 170);
	glVertex2i(x + 140, y + 170);
	glEnd();

	//upper cage
	glColor3ub(96, 130, 182);
	glBegin(GL_POLYGON);
	glVertex2i(x - 20, y + 170);
	glVertex2i(x + 145, y + 170);
	glVertex2i(x + 145, y + 175);
	glVertex2i(x - 20, y + 175);

	glEnd();
	glPopMatrix();












}


//background scene 2
void beach(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + h, y);
	glVertex2i(x + w, y + 300);
	glVertex2i(x, y + 300);
	glEnd();
}

void colorBeach(int x, int y, int w) {
	int h = 0.6 * w;
	glColor3ub(249, 209, 153);
	beach(x, y, w, h);
}

void ocean(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(w - 100, y + h);
	glEnd();
}

void colorOcean(int x, int y, int w) {
	int h = 0.43 * w;
	glColor3ub(0, 94, 184);
	ocean(x, y, w, h);
}

void beachWave(int n, int x, int y, int r) {


	double inc = 1 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(0, 94, 184);
	for (double theta = 0.0; theta <= 1 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();

}

void sky(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void colorSky(int x, int y, int w) {
	int h = 0.2 * w;
	glColor3ub(0, 191, 255);
	sky(x, y, w, h);
}

void mountain(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + h, y + h);
	glVertex2i(x + ((x + w) - (x + h)), y + h);
	glEnd();

}

void colorMountain(int x, int y, int w) {
	int h = 0.7 * w;
	glColor3ub(220, 216, 199);
	mountain(x, y, w, h);
}

void sunCore(int n, int x, int y, int r) {

	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(255, 140, 0);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void cloudStack(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;

	glPushMatrix();
	glTranslatef(cloud, 0, 0);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 224);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
	glPopMatrix();
}

void fallCoco(int n, int x, int y, int r) {


	double inc = 1 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(126, 96, 79);
	for (double theta = 0.0; theta <= 1 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();

}

void treePolygon(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i((y - w) + x, y);
	glVertex2i(((2 * x) - ((y - w) + x)) + x, y + w);
	glVertex2i(h - (y - w), y + w);
	glEnd();

}

void colorTree(int x, int y, int w) {
	int h = 0.5 * w;
	glColor3ub(168, 113, 90);
	treePolygon(x, y, w, h);
}

void coconut(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(147, 175, 0);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}


void coconutLeaf1() {
	glBegin(GL_TRIANGLES);
	glColor3ub(197, 217, 68);
	glVertex2i(45, 270);
	glVertex2i(170, 240);
	glVertex2i(110, 290);

	glEnd();

}

void coconutLeaf2() {
	glBegin(GL_TRIANGLES);
	glColor3ub(197, 217, 68);
	glVertex2i(45, 270);
	glVertex2i(180, 300);
	glVertex2i(110, 320);

	glEnd();

}
void coconutLeaf3() {
	glBegin(GL_TRIANGLES);
	glColor3ub(197, 217, 68);
	glVertex2i(45, 270);
	glVertex2i(90, 350);
	glVertex2i(180, 350);

	glEnd();

}
void coconutLeaf4() {
	glBegin(GL_TRIANGLES);
	glColor3ub(197, 217, 68);
	glVertex2i(55, 270);
	glVertex2i(-20, 255);
	glVertex2i(20, 290);

	glEnd();

}
void coconutLeaf5() {
	glBegin(GL_TRIANGLES);
	glColor3ub(197, 217, 68);
	glVertex2i(55, 270);
	glVertex2i(-40, 300);
	glVertex2i(35, 330);

	glEnd();

}
void coconutLeaf6() {
	glBegin(GL_TRIANGLES);
	glColor3ub(197, 217, 68);
	glVertex2i(45, 270);
	glVertex2i(47, 365);
	glVertex2i(115, 390);

	glEnd();

}

//background for scene 1
void allBlue(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void seaColor(int x, int y, int w) {
	int h = 0.25 * w;
	glColor3ub(0, 94, 184);
	allBlue(x, y, w, h);
}

void daySky(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void skyColor(int x, int y, int w) {
	int h = 0.25 * w;
	glColor3ub(0, 191, 255);
	daySky(x, y, w, h);
}

void dayMountain(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + h, y + h);
	glVertex2i(x + ((x + w) - (x + h)), y + h);
	glEnd();

}

void mountainColor(int x, int y, int w) {
	int h = 0.7 * w;
	glColor3ub(220, 216, 199);
	dayMountain(x, y, w, h);
}




//dialog 

void drawText(const char* text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void Rdialog(int x, int y)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10, y);
	glVertex2i(x + 150, y);
	glVertex2i(x + 150, y + 50);
	glVertex2i(x - 10, y + 50);
	glEnd();

	//dialog tail
	glBegin(GL_POLYGON);
	glVertex2i(x + 5, y);
	glVertex2i(x + 5, y - 10);
	glVertex2i(x + 15, y);
	glEnd();

}
void long_Rdialog(int x, int y)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10, y);
	glVertex2i(x + 200, y);
	glVertex2i(x + 200, y + 50);
	glVertex2i(x - 10, y + 50);
	glEnd();

	//dialog tail
	glBegin(GL_POLYGON);
	glVertex2i(x + 5, y);
	glVertex2i(x + 5, y - 10);
	glVertex2i(x + 15, y);
	glEnd();

}

void Ldialog(int x, int y)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10, y);
	glVertex2i(x + 150, y);
	glVertex2i(x + 150, y + 50);
	glVertex2i(x - 10, y + 50);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(x + 145, y);
	glVertex2i(x + 145, y - 10);
	glVertex2i(x + 135, y);
	glEnd();
}
void long_Ldialog(int x, int y)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex2i(x - 10, y);
	glVertex2i(x + 170, y);
	glVertex2i(x + 170, y + 50);
	glVertex2i(x - 10, y + 50);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(x + 145, y);
	glVertex2i(x + 145, y - 10);
	glVertex2i(x + 135, y);
	glEnd();

}
void Write()
{
	std::string text;

	if (counter > 100 && counter < 150)
	{
		Rdialog(700, 250);
		glColor3ub(0, 0, 0);
		text = "no fish today :(";
		drawText(text.data(), text.size(), 560, 320);

	}
	else if (counter > 160 && counter < 210)
	{
		Rdialog(20, 250);
		glColor3ub(255, 0, 0);
		text = "SQUEAK! SQUEAK!";
		drawText(text.data(), text.size(), 25, 320);

	}

	else if (counter > 215 && counter < 265)
	{
		Rdialog(20, 250);
		glColor3ub(255, 0, 0);
		text = "SQUEAK! SQUEAK!";
		drawText(text.data(), text.size(), 25, 320);

	}
	else if (counter > 250 && counter < 300)
	{
		long_Rdialog(700, 250);
		glColor3ub(0, 0, 0);
		text = "what is that sound?";
		drawText(text.data(), text.size(), 560, 320);

	}
	else if (counter > 320 && counter < 370)
	{
		long_Rdialog(700, 250);
		glColor3ub(0, 0, 0);
		text = "i better go and check";
		drawText(text.data(), text.size(), 560, 320);

	}
	else if (counter > 520 && counter < 580)
	{

		long_Rdialog(150, 150);
		glColor3ub(255, 0, 0);
		text = "help! im trapped :,(";
		drawText(text.data(), text.size(), 120, 200);

	}


	if (counter > 610 && counter < 635)
	{
		long_Ldialog(625, 210);
		glColor3ub(0, 0, 0);
		text = "Oh no that penguin ";
		drawText(text.data(), text.size(), 500, 280);
		text = "is trapped! ";
		drawText(text.data(), text.size(), 500, 260);
	}

	else if (counter > 1055 && counter < 1185)
	{
		Ldialog(40, 150);
		glColor3ub(0, 0, 0);
		text = "Thankyou mr ";
		drawText(text.data(), text.size(), 30, 215);
		text = "fisherman ";
		drawText(text.data(), text.size(), 30, 195);

	}

	else if (counter > 1190 && counter < 1240)
	{
		Ldialog(40, 150);
		glColor3ub(0, 0, 0);
		text = "I will remember ";
		drawText(text.data(), text.size(), 30, 215);
		text = "your kindness ";
		drawText(text.data(), text.size(), 30, 195);

	}
	else if (counter > 1250 && counter < 1300)
	{
		long_Rdialog(330, 150);
		glColor3ub(0, 0, 0);
		text = "You are free ";
		drawText(text.data(), text.size(), 285, 220);
		text = "now buddy ";
		drawText(text.data(), text.size(), 285, 200);
	}
	else if (counter > 1500 && counter < 1550) {
		glColor3ub(0, 0, 0);
		text = "One";
		drawText(text.data(), text.size(), 360, 330);
		text = "Week";
		drawText(text.data(), text.size(), 360, 310);
		text = "Later";
		drawText(text.data(), text.size(), 360, 290);
	}
	// bread
	else if (counter > 1595 && counter < 1630)
	{
		Rdialog(530, 250);
		glColor3ub(0, 0, 0);
		text = "Oh no, my boat!";
		drawText(text.data(), text.size(), 430, 330);
	}
	else if (counter > 1650 && counter < 1700)
	{
		long_Rdialog(550, 250);
		glColor3ub(0, 0, 0);
		text = "Hey,its the penguin!";
		drawText(text.data(), text.size(), 440, 330);

	}
	else if (counter > 1725 && counter < 1740) {
		long_Ldialog(200, 200);
		glColor3ub(255, 0, 0);
		text = "(hey,ocean man!)";
		drawText(text.data(), text.size(), 160, 270);
	}
	else if (counter > 1750 && counter < 1782) {
		long_Ldialog(200, 200);
		glColor3ub(255, 0, 0);
		text = "(i think he";
		drawText(text.data(), text.size(), 160, 270);
		text = "needs help)";
		drawText(text.data(), text.size(), 160, 250);
	}
	else if (counter > 1785 && counter < 1800) {
		long_Ldialog(200, 200);
		glColor3ub(255, 0, 0);
		text = "(guys come here!)";
		drawText(text.data(), text.size(), 160, 270);
	}
	else if (counter > 1870 && counter < 1895) {
		long_Ldialog(200, 200);
		glColor3ub(255, 0, 0);
		text = "(lets help him!)";
		drawText(text.data(), text.size(), 160, 270);
	}
	else if (counter > 1970 && counter < 1990) {
		Rdialog(530, 250);
		glColor3ub(0, 0, 0);
		text = "Yay,they are";
		drawText(text.data(), text.size(), 420, 345);
		text = "helping me.";
		drawText(text.data(), text.size(), 420, 325);
	}

	//scene4 dialog
	else if (counter > 2345 && counter < 2365) {
		Rdialog(770, 220);
		glColor3ub(0, 0, 0);
		text = "Thanks guys:)";
		drawText(text.data(), text.size(), 610, 300);

	}
	else if (counter > 2370 && counter < 2390) {
		long_Ldialog(500, 220);
		glColor3ub(255, 0, 0);
		text = "(i also want";
		drawText(text.data(), text.size(), 400, 300);
		text = "to thank him)";
		drawText(text.data(), text.size(), 400, 280);
	}
	else if (counter > 2410 && counter < 2430) {
		long_Ldialog(500, 220);
		glColor3ub(255, 0, 0);
		text = "(by giving the";
		drawText(text.data(), text.size(), 400, 300);
		text = "big fish)";
		drawText(text.data(), text.size(), 400, 280);
	}
	else if (counter > 2500 && counter < 2535) {
		long_Rdialog(770, 220);
		glColor3ub(255, 0, 0);
		text = "is for me? aww";
		drawText(text.data(), text.size(), 610, 300);

	}
	else if (counter > 2535 && counter < 2565) {
		Rdialog(770, 220);
		glColor3ub(255, 0, 0);
		text = "thanks pingu!";
		drawText(text.data(), text.size(), 610, 300);
		text =  "cya!";
		drawText(text.data(), text.size(), 610, 280);

	}
	if (counter > 2565 && counter < 2580) {
		long_Ldialog(500, 220);
		glColor3ub(255, 0, 0);
		text = "*QUACK *QUACK";
		drawText(text.data(), text.size(), 400, 300);
		text = "*QUACK *QUACK";
		drawText(text.data(), text.size(), 400, 280);
	}




}


void drawWindmill() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(framenumber * (180.0 / 46), 0, 0, 1);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f, 0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

//scene 1
void part1()
{
	glBegin(GL_POLYGON);
	glBegin(GL_TRIANGLES);

	seaColor(0, 0, 1000);
	skyColor(0, 250, 1000);
	for (int i = 0; i < 1000; i += 750) {
		mountainColor(i, 250, 250);
	}
	for (int j = 225; j < 1000; j += 380) {
		mountainColor(j, 250, 170);
	}
	sunCore(50, 510, 410, 35);
	//upper line cloud
	for (int x = 460; x <= 580; x += 25) {
		cloudStack(50, x, 395, 20);
	}
	//bottom line cloud
	for (int y = 480; y <= 550; y += 30) {
		cloudStack(50, y, 370, 20);
	}
	//left cloudstack


	glEnd();
	glPushMatrix();
	fisherman(800, 150);
	boat(800, 150);
	glPopMatrix();

	Write();
}
//scene 2
void part2()
{
	glColor3ub(0, 0, 0);

	colorBeach(0, 0, 600);
	gunter(120, 50);
	cage();
	beachWave(100, 625, 0, 301);

	colorSky(0, 300, 1000);
	colorMountain(0, 300, 250);
	colorMountain(225, 300, 170);
	colorMountain(370, 300, 250);

	sunCore(50, 840, 430, 35);
	//upper line cloud
	for (int x = 780; x <= 910; x += 25) {
		cloudStack(50, x, 420, 20);
	}
	//bottom line cloud
	for (int y = 810; y <= 890; y += 30) {
		cloudStack(50, y, 400, 20);
	}

	colorOcean(350, 0, 700);
	colorTree(40, 150, 130);
	//old coconut on beach detail
	for (int j = 30; j < 110; j += 25) {
		fallCoco(10, j, 150, 10);
	}
	coconutLeaf1();
	coconutLeaf2();
	coconutLeaf3();
	coconutLeaf4();
	coconutLeaf5();
	coconutLeaf6();

	// top coconut fruit
	for (int l = 40; l < 75; l += 13) {
		coconut(10, l, 275, 10);
	}
	//bottom coconut fruit
	for (int z = 42; z < 72; z += 17) {
		coconut(10, z, 260, 10);
	}


	fisherman2(900, 100);
	boat2(900, 100);

	Write();


}


//part bread(scene 3 & 4)


void rightSea(int x, int y) {

	glColor3ub(0, 87, 105);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 300, y);
	glVertex2i(x + 300, y + 270);
	glVertex2i(x, y + 270);
	glEnd();

}

void rightBeach(int x, int y) {

	//sand
	glColor3ub(179, 162, 133);
	glBegin(GL_POLYGON);
	glVertex2i(x + 150, y);
	glVertex2i(x + 900, y);
	glVertex2i(x + 900, y + 270);
	glVertex2i(x + 150, y + 270);
	glEnd();

	//
}

void manHouse(int x, int y) {

	//rooftop
	glColor3ub(103, 98, 88);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 150, y);
	glVertex2i(x + 150, y + 40);
	glVertex2i(x + 30, y + 40);
	glEnd();

	//body
	glColor3ub(186, 140, 99);
	glBegin(GL_POLYGON);
	glVertex2i(x + 20, y - 70);
	glVertex2i(x + 150, y - 70);
	glVertex2i(x + 150, y);
	glVertex2i(x + 20, y);
	glEnd();

	//door
	glColor3ub(169, 169, 169);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30, y - 70);
	glVertex2i(x + 60, y - 70);
	glVertex2i(x + 60, y - 25);
	glVertex2i(x + 30, y - 25);
	glEnd();

	//single windows
	glColor3ub(169, 169, 169);
	glBegin(GL_POLYGON);
	glVertex2i(x + 80, y - 35);
	glVertex2i(x + 140, y - 35);
	glVertex2i(x + 140, y - 10);
	glVertex2i(x + 80, y - 10);
	glEnd();

	//frontfront pole
	glColor3ub(103, 98, 88);
	glBegin(GL_POLYGON);
	glVertex2i(x + 20, y - 100);
	glVertex2i(x + 30, y - 100);
	glVertex2i(x + 30, y - 70);
	glVertex2i(x + 20, y - 70);
	glEnd();

	//frontback pole
	glColor3ub(103, 98, 88);
	glBegin(GL_POLYGON);
	glVertex2i(x + 60, y - 90);
	glVertex2i(x + 70, y - 90);
	glVertex2i(x + 70, y - 70);
	glVertex2i(x + 60, y - 70);
	glEnd();

	//backfront pole
	glColor3ub(103, 98, 88);
	glBegin(GL_POLYGON);
	glVertex2i(x + 100, y - 100);
	glVertex2i(x + 110, y - 100);
	glVertex2i(x + 110, y - 70);
	glVertex2i(x + 100, y - 70);
	glEnd();

	//backback pole
	glColor3ub(103, 98, 88);
	glBegin(GL_POLYGON);
	glVertex2i(x + 140, y - 90);
	glVertex2i(x + 150, y - 90);
	glVertex2i(x + 150, y - 70);
	glVertex2i(x + 140, y - 70);
	glEnd();

}

void allBlueNight(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void seaColorNight(int x, int y, int w) {
	int h = 0.25 * w;
	glColor3ub(0, 87, 105);
	allBlueNight(x, y, w, h);
}

void nightSky(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void nightSkyColor(int x, int y, int w) {
	int h = 0.25 * w;
	glColor3ub(12, 20, 69);
	nightSky(x, y, w, h);
}

void nightMountain(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + h, y + h);
	glVertex2i(x + ((x + w) - (x + h)), y + h);
	glEnd();

}

void mountainColor2(int x, int y, int w) {
	int h = 0.7 * w;
	glColor3ub(69, 87, 95);
	nightMountain(x, y, w, h);
}

void moonBase(int n, int x, int y, int r) {

	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(252, 210, 52);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void crescentMoon(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(12, 20, 69);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}
//for generating random twinkle stars
void randomStar(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(252, 210, 52);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();

}

void beachWaveNight(int n, int x, int y, int r) {


	double inc = 1 * PI / (double)n;
	glBegin(GL_POLYGON);
	glColor3ub(0, 87, 105);
	for (double theta = 0.0; theta <= 1 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}

	glEnd();

}

void gunterF0(int x, int y)
{

	// outer badan
	glColor3ub(0, 0, 80);
	glPushMatrix();
	glTranslatef(speed, sw, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x, y + 120 / 2);
	glEnd();

	//outer kepala

	glColor3ub(0, 0, 80);
	nGon(200, x + 50 / 2, y + 120 / 2, 50 / 2);

	//inner badan

	glColor3ub(255, 255, 180);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30 / 2, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x + 25 / 2, y + 120 / 2);
	glEnd();

	//inner kepala
	glColor3ub(255, 255, 180);

	nGon(200, x + 63 / 2, y + 120 / 2, 38 / 2);

	//mata kiri

	glColor3ub(0, 0, 0);

	nGon2(200, x + 55 / 2, y + 120 / 2, 10 / 2);

	// right eyes
	glColor3ub(0, 0, 0);

	nGon2(200, x + 100 / 2, y + 120 / 2, 10 / 2);

	// left eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 60 / 2, y + 120 / 2, 5 / 2);

	//right  eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 105 / 2, y + 120 / 2, 5 / 2);

	//beaks
	glColor3ub(250, 169, 69);

	glBegin(GL_POLYGON);
	glVertex2i(x + 80 / 2, y + 120 / 2);
	glVertex2i(x + 120 / 2, y + 100 / 2);
	glVertex2i(x + 80 / 2, y + 95 / 2);



	glEnd();


	//left hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x, y + 100 / 2);

	glVertex2i(x - 25 / 2, y + 50 / 2);
	glVertex2i(x, y + 60 / 2);


	glEnd();


	//right hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 100 / 2);
	glVertex2i(x + 125 / 2, y + 50 / 2);
	glVertex2i(x + 100 / 2, y + 60 / 2);

	glEnd();
	glPopMatrix();







}
void gunterF1(int x, int y)
{

	// outer badan
	glColor3ub(65, 105, 225);
	glPushMatrix();
	glTranslatef(speed1, sw, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x, y + 120 / 2);
	glEnd();

	//outer kepala

	glColor3ub(65, 105, 225);
	nGon(200, x + 50 / 2, y + 120 / 2, 50 / 2);

	//inner badan

	glColor3ub(255, 255, 180);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30 / 2, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x + 25 / 2, y + 120 / 2);
	glEnd();

	//inner kepala
	glColor3ub(255, 255, 180);

	nGon(200, x + 63 / 2, y + 120 / 2, 38 / 2);

	//mata kiri

	glColor3ub(0, 0, 0);

	nGon2(200, x + 55 / 2, y + 120 / 2, 10 / 2);

	// right eyes
	glColor3ub(0, 0, 0);

	nGon2(200, x + 100 / 2, y + 120 / 2, 10 / 2);

	// left eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 60 / 2, y + 120 / 2, 5 / 2);

	//right  eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 105 / 2, y + 120 / 2, 5 / 2);

	//beaks
	glColor3ub(250, 169, 69);

	glBegin(GL_POLYGON);
	glVertex2i(x + 80 / 2, y + 120 / 2);
	glVertex2i(x + 120 / 2, y + 100 / 2);
	glVertex2i(x + 80 / 2, y + 95 / 2);



	glEnd();


	//left hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x, y + 100 / 2);

	glVertex2i(x - 25 / 2, y + 50 / 2);
	glVertex2i(x, y + 60 / 2);


	glEnd();


	//right hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 100 / 2);
	glVertex2i(x + 125 / 2, y + 50 / 2);
	glVertex2i(x + 100 / 2, y + 60 / 2);

	glEnd();
	glPopMatrix();







}
void gunterF2(int x, int y)
{

	// outer badan
	glColor3ub(95, 158, 160);
	glPushMatrix();
	glTranslatef(speed2, sw, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x, y + 120 / 2);
	glEnd();

	//outer kepala

	glColor3ub(95, 158, 160);
	nGon(200, x + 50 / 2, y + 120 / 2, 50 / 2);

	//inner badan

	glColor3ub(255, 255, 180);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30 / 2, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x + 25 / 2, y + 120 / 2);
	glEnd();

	//inner kepala
	glColor3ub(255, 255, 180);

	nGon(200, x + 63 / 2, y + 120 / 2, 38 / 2);

	//mata kiri

	glColor3ub(0, 0, 0);

	nGon2(200, x + 55 / 2, y + 120 / 2, 10 / 2);

	// right eyes
	glColor3ub(0, 0, 0);

	nGon2(200, x + 100 / 2, y + 120 / 2, 10 / 2);

	// left eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 60 / 2, y + 120 / 2, 5 / 2);

	//right  eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 105 / 2, y + 120 / 2, 5 / 2);

	//beaks
	glColor3ub(250, 169, 69);

	glBegin(GL_POLYGON);
	glVertex2i(x + 80 / 2, y + 120 / 2);
	glVertex2i(x + 120 / 2, y + 100 / 2);
	glVertex2i(x + 80 / 2, y + 95 / 2);



	glEnd();


	//left hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x, y + 100 / 2);

	glVertex2i(x - 25 / 2, y + 50 / 2);
	glVertex2i(x, y + 60 / 2);


	glEnd();


	//right hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 100 / 2);
	glVertex2i(x + 125 / 2, y + 50 / 2);
	glVertex2i(x + 100 / 2, y + 60 / 2);

	glEnd();
	glPopMatrix();







}
void gunterF3(int x, int y)
{

	// outer badan
	glColor3ub(25, 25, 112);
	glPushMatrix();
	glTranslatef(speed3, sw, 0);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x, y + 120 / 2);
	glEnd();

	//outer kepala

	glColor3ub(25, 25, 112);
	nGon(200, x + 50 / 2, y + 120 / 2, 50 / 2);

	//inner badan

	glColor3ub(255, 255, 180);
	glBegin(GL_POLYGON);
	glVertex2i(x + 30 / 2, y);
	glVertex2i(x + 100 / 2, y);
	glVertex2i(x + 100 / 2, y + 120 / 2);
	glVertex2i(x + 25 / 2, y + 120 / 2);
	glEnd();

	//inner kepala
	glColor3ub(255, 255, 180);

	nGon(200, x + 63 / 2, y + 120 / 2, 38 / 2);

	//mata kiri

	glColor3ub(0, 0, 0);

	nGon2(200, x + 55 / 2, y + 120 / 2, 10 / 2);

	// right eyes
	glColor3ub(0, 0, 0);

	nGon2(200, x + 100 / 2, y + 120 / 2, 10 / 2);

	// left eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 60 / 2, y + 120 / 2, 5 / 2);

	//right  eye bowls

	glColor3ub(255, 255, 255);
	nGon2(200, x + 105 / 2, y + 120 / 2, 5 / 2);

	//beaks
	glColor3ub(250, 169, 69);

	glBegin(GL_POLYGON);
	glVertex2i(x + 80 / 2, y + 120 / 2);
	glVertex2i(x + 120 / 2, y + 100 / 2);
	glVertex2i(x + 80 / 2, y + 95 / 2);



	glEnd();


	//left hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x, y + 100 / 2);

	glVertex2i(x - 25 / 2, y + 50 / 2);
	glVertex2i(x, y + 60 / 2);


	glEnd();


	//right hand
	glColor3ub(0, 0, 80);

	glBegin(GL_POLYGON);
	glVertex2i(x + 100 / 2, y + 100 / 2);
	glVertex2i(x + 125 / 2, y + 50 / 2);
	glVertex2i(x + 100 / 2, y + 60 / 2);

	glEnd();
	glPopMatrix();







}

void fish()
{

	glBegin(GL_POLYGON);	// draw body
	glColor3ub(176, 224, 230);
	glVertex2i(x + 660, y + 90);
	glVertex2i(x + 675, y + 130);
	glVertex2i(x + 690, y + 90);
	glVertex2i(x + 675, y + 60);
	glEnd();

	//biji mata
	glColor3ub(0, 0, 0);
	nGon2(250, x + 675, y + 70, 2);
	glPushMatrix();

	glBegin(GL_TRIANGLES);			//draw tail
	glColor3ub(176, 224, 230);
	glVertex2i(x + 660, y + 140);
	glVertex2i(x + 675, y + 128);
	glVertex2i(x + 690, y + 140);
	glEnd();
}


void scene3() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glBegin(GL_TRIANGLES);

	seaColorNight(0, 0, 1000);
	nightSkyColor(0, 250, 1000);
	//generate random stars
	for (int i = 0; i < 50; i++) {
		randomStar(10, rand() % 1000, rand() % 500, 1);
	}
	seaColorNight(0, 0, 1000);
	for (int i = 0; i < 1000; i += 750) {
		mountainColor2(i, 250, 250);
	}
	for (int j = 225; j < 1000; j += 380) {
		mountainColor2(j, 250, 170);
	}
	//stacked circle creates crescent
	moonBase(50, 510, 415, 35);
	crescentMoon(50, 523, 412, 28);



	gunterF1(-80, 113);
	gunterF3(-120, 110);
	fisherman3(275, 100);
	boat3(250, 90);
	gunterF0(-58, 75);
	gunterF2(-95, 70);
	Write();

	glEnd();

}

//scene4 - stronk bunch of penguin help stuck fisherman
void scene4() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glBegin(GL_TRIANGLES);

	nightSkyColor(0, 250, 1000);
	//generate random stars
	for (int i = 0; i < 50; i++) {
		randomStar(10, rand() % 1000, rand() % 500, 1);
	}
	rightBeach(100, 0);
	rightSea(0, 0);
	beachWaveNight(100, 300, 0, 271);
	//mountain lol
	mountainColor2(-50, 271, 170);
	mountainColor2(350, 270, 260);
	mountainColor2(450, 270, 260);
	mountainColor2(620, 270, 170);
	mountainColor2(780, 270, 240);
	//
	moonBase(50, 240, 415, 35);
	crescentMoon(50, 253, 412, 28);
	manHouse(850, 225);

	//front fisher penguin
	gunterF1(-1250, 113);
	//behind fisher
	gunterF3(-1270, 110);
	fisherman3(-880, 100);
	boat3(-900, 90);
	gunterF0(-1208, 75);
	//p front gunter
	gunterF2(-1270, 70);
	Write();
	//fish();

	glEnd();
}

//weeklater
void weekBackground(int x, int y) {
	//weekbg

	glColor3ub(70, 130, 180);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(1000, 0);
	glVertex2i(1000, 500);
	glVertex2i(0, 500);
	glEnd();

}

//week
void weekLater() {

	weekBackground(0, 0);
	gunterF0(300, 150);
	fisherman3(600, 145);
	Write();
}


//animation
void idle(int value)
{
	DWORD start = GetTickCount64();
	while (GetTickCount64() - start < 30 / FPS);
	counter++;
	s_counter++;
	//part 1
	if (counter > 10 && counter < 100)
	{
		db -= 2; // boat speed
		R_angle += 5;
	}
	if (counter > 100 && counter < 375)
	{
		R_angle += 5;
	}
	if (counter > 375 && counter < 500)
	{
		db -= 5;
		ab -= 0.5;
		R_angle += 10;
	}
	if (counter > 500 && counter < 550)
	{
		db3 -= 1;
		R_angle += 5;

	}

	//part 2
	if (counter > 550 && counter < 600)
	{
		db3 -= 1;
		R_angle += 5;

	}
	if (counter > 600 && counter < 610)
	{
		db3 -= 0.5;
		R_angle += 5;
	}
	if (counter > 610 && counter < 650)
	{
		R_angle += 5;
	}

	if (counter > 650 && counter < 790)
	{
		db3 -= 3;
		R_angle += 15;
	}
	if (counter > 815 && counter < 830)
	{
		fly += 2;
	}
	if (counter > 830 && counter < 845)
	{
		walk -= 7.8;
	}
	if (counter > 860 && counter < 880)
	{
		fly -= 5;
	}
	if (counter > 910 && counter < 1105)
	{
		angle++;
	}
	if (counter > 1310 && counter < 1500)
	{
		pingu += 1;
		pingu1 -= 1;
	}

	if (counter > 600 && counter < 865)
	{
		pingu += dx;
		if (pingu > 5)
		{
			dx *= -1;
		}
		else if (pingu == 0)
		{
			dx *= -1;
		}
	}

	/*
	* if (counter > 1500 && counter < 1550)
	{

	}


	*/

	//part bread


	if (counter > 1550 && counter < 1600) {
		brad += 4;
	}

	if (counter > 1600 && counter < 1650)
	{
		brad2 += uc;
		if (brad2 > 15)
		{
			uc *= -1;
		}
		else if (brad2 == 0)
		{
			uc *= -1;
		}
		ux += dex;
		if (ux > 15) {
			dex *= -1;

		}
		else if (ux == 0) {
			dex *= -1;
		}
	}

	if (counter > 1650 && counter < 1740) {

		speed += 4;
		//swimming
		sw += swim;
		if (sw > 15) {
			swim *= -1;
		}
		else if (sw == 0) {
			swim *= -1;
		}

	}
	//fren come
	if (counter > 1800 && counter < 1885) {
		speed1 += 4;
		speed2 += 4;
		speed3 += 4;
		//swimming
		sw += swim;
		if (sw > 15) {
			swim *= -1;
		}
		else if (sw == 0) {
			swim *= -1;
		}
	}
	//penguin getting ready to push boat
	if (counter > 1900 && counter < 1980) {
		speed += 1.3;
		speed1 += 3.8;
		speed2 += 3.8;
		speed3 += 2.5;
		//swimming
		sw += swim;
		if (sw > 15) {
			swim *= -1;
		}
		else if (sw == 0) {
			swim *= -1;
		}
	}
	//helping hooman
	if (counter > 1985 && counter < 2095) {
		brad += 4.5;
		speed += 4.5;
		speed1 += 4.5;
		speed2 += 4.5;
		speed3 += 4.5;
		//swimming
		sw += swim;
		if (sw > 15) {
			swim *= -1;
		}
		else if (sw == 0) {
			swim *= -1;
		}
	}


	//scene4 animation
	if (counter > 2100 && counter < 2245) {
		brad += 4.8;
		speed += 4.8;
		speed1 += 4.8;
		speed2 += 4.8;
		speed3 += 4.8;

		//swimming
		sw += swim;
		if (sw > 15) {
			swim *= -1;
		}
		else if (sw == 0) {
			swim *= -1;
		}
	}
	//fisherman walk to beach
	if (counter > 2250 && counter < 2320) {
		brad2 += 4.2;
		ux -= 0.4;

	}
	//penguin reposition
	if (counter > 2255 && counter < 2350) {

		speed += 1.5;
		speed1 -= 0.8;
		speed2 -= 1;


	}
	//pingu give fish
	if (counter > 2435 && counter < 2460) {
		speed += 4.2;
	}
	if (counter > 2465 && counter < 2490) {
		brad2 += uc;
		if (brad2 > 15)
		{
			uc *= -1;
		}
		else if (brad2 == 0)
		{
			uc *= -1;
		}
	}

	if (counter > 2565 && counter < 2650) {
		sw -= 5.5;
	}
	//end of scene 4



	cloud += dc;
	if (cloud > 10)
	{
		dc *= -1;
	}
	else if (cloud == 0)
	{
		dc *= -1;
	}


	glutPostRedisplay();
	glutTimerFunc(25, idle, 0);
}


void display() // redraw everytime all action takes place
{
	glClear(GL_COLOR_BUFFER_BIT); // reference to glClearColor

	


	if (s_counter < 500)
	{
		part1();
	}
	else if (s_counter > 500 && s_counter < 1500)
	{
		part2();
	}
	else if (counter > 1500 && counter < 1550) {
		weekLater();
	}


	else if (counter > 1550 && counter < 2100)
	{
		scene3();
	}
	else if (counter > 2100 && counter < 2800)
	{
		scene4();
	}
	 if (counter > 2460 && counter < 2480)
	{
		fish();
	}



	glutSwapBuffers();
	//glFlush(); // sends pixels to the screen / force screen to update
	 // BECAUSE we have double buffered windows
}

void InitGl()
{
	glClearColor(255, 255, 255, 0.0); // set background color
	glMatrixMode(GL_PROJECTION);// to set 2D
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); // setting the camera
	glPointSize(10.0);

}
int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("MandebIdol");// create window
	glutDisplayFunc(display); // function pointer
	//glutIdleFunc(idle);
	InitGl();
	glutTimerFunc(25, idle, 0);
	glutMainLoop();

}