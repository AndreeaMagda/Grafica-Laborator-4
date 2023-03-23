/*

*/
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"
#include "glut.h"
#include "lab4.h"

static GLfloat x = 0, y = 0, z=0, alfa=0;


void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);//cod culoare rgb +transparenta
}//vreau sa curete ecranul cu alb

void CALLBACK MutaStanga()
{
    x = x - 10;
}

void CALLBACK MutaDreapta()
{
    x = x + 10;
}

void CALLBACK MutaSus()
{
    y = y + 10;

}
void CALLBACK MutaJos()
{
    y = y - 10;

}

void CALLBACK rot_z_up(AUX_EVENTREC* event)
{
    alfa = alfa + 5;
}

void CALLBACK rot_z_down(AUX_EVENTREC* event)
{
    alfa = alfa - 5;
}



void CALLBACK display()
{
    GLUquadricObj *obj1 = 0;
    GLUquadricObj* obj2 = 0;
    GLUquadricObj* obj3 = 0;
    GLUquadricObj* obj4 = 0;
    GLUquadricObj* obj5 = 0;
    GLUquadricObj* obj6 = 0;
    GLUquadricObj* obj7 = 0;

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   
    glTranslatef(x, y, z);
    glRotatef(alfa, 1, 1, 1);

    
    obj1 = gluNewQuadric();
    gluQuadricDrawStyle(obj1, GLU_SILHOUETTE);
    gluQuadricNormals(obj1, GLU_SMOOTH);
    gluQuadricTexture(obj1, GL_TRUE);
    gluQuadricOrientation(obj1, GLU_OUTSIDE);


    obj2 = gluNewQuadric();
    gluQuadricDrawStyle(obj2, GLU_SILHOUETTE);
    gluQuadricNormals(obj2, GLU_SMOOTH);
    gluQuadricTexture(obj2, GL_TRUE);
    gluQuadricOrientation(obj2, GLU_OUTSIDE);

    obj3 = gluNewQuadric();
    gluQuadricDrawStyle(obj3, GLU_SILHOUETTE);
    gluQuadricNormals(obj3, GLU_SMOOTH);
    gluQuadricTexture(obj3, GL_TRUE);
    gluQuadricOrientation(obj3, GLU_OUTSIDE);

    obj4 = gluNewQuadric();
    gluQuadricDrawStyle(obj4, GLU_FILL);
    gluQuadricNormals(obj4, GLU_SMOOTH);
    gluQuadricTexture(obj4, GL_TRUE);
    gluQuadricOrientation(obj4, GLU_OUTSIDE);

    obj5 = gluNewQuadric();
    gluQuadricDrawStyle(obj5, GLU_FILL);
    gluQuadricNormals(obj5, GLU_SMOOTH);
    gluQuadricTexture(obj5, GL_TRUE);
    gluQuadricOrientation(obj5, GLU_OUTSIDE);

    obj6 = gluNewQuadric();
    gluQuadricDrawStyle(obj6, GLU_FILL);
    gluQuadricNormals(obj6, GLU_SMOOTH);
    gluQuadricTexture(obj6, GL_TRUE);
    gluQuadricOrientation(obj6, GLU_OUTSIDE);

    obj7 = gluNewQuadric();
    gluQuadricDrawStyle(obj7, GLU_FILL);
    gluQuadricNormals(obj7, GLU_SMOOTH);
    gluQuadricTexture(obj7, GL_TRUE);
    gluQuadricOrientation(obj7, GLU_OUTSIDE);
    

    //Sphere
    glPushMatrix(); 
    glColor3f(0.6, 0.0, 1.0);
    glTranslatef(-200, 0, 0);
    gluSphere(obj1, 20, 50, 10);
    glPopMatrix();

    //cylinder
    glPushMatrix();
    glColor3f(0.0, 0.9, 0.1);
    glTranslatef(-150, 0, 0);
    gluCylinder(obj2, 20, 20,50,50,10);
    glPopMatrix();

    //Con
    glPushMatrix();
    glColor3f(1.0, 0.9, 0.1);
    glTranslatef(-100, 0, 0);
    gluCylinder(obj2, 20, 1, 50, 50, 10);
    glPopMatrix();


    //Disk
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.7);
    glTranslatef(-50, 0, 0);
    gluDisk(obj4,10,20,50,20);
    glPopMatrix();


    //Disk2
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.7);
    glTranslatef(0, 0, 0);
    gluDisk(obj5, 0, 20, 50, 20);
    glPopMatrix();

    //Partial Disk
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.7);
    glTranslatef(30, 0, 0);
    gluPartialDisk(obj6, 20, 30, 50, 20,20,50);
    glPopMatrix();

    //Partial Disk2
    glPushMatrix();
    glColor3f(0.2, .2, 0.2);
    glTranslatef(70, 0, 0);
    gluPartialDisk(obj7, 1, 30, 50, 60, 50, 90);
    glPopMatrix();

     
   

    gluDeleteQuadric(obj1);
    gluDeleteQuadric(obj2);
    gluDeleteQuadric(obj3);
    gluDeleteQuadric(obj4);
    gluDeleteQuadric(obj5);
    gluDeleteQuadric(obj6);
    
    glFlush();
}

#define ISOTROPIC
#ifdef ISOTROPIC
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) {
        return;
    }
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        glOrtho(-160.0, 160.0, 160.0 * (GLfloat)h / (GLfloat)w, -160.0 * (GLfloat)h / (GLfloat)w, -1000.0, 1000.0);
    }
    else {
        glOrtho(-160.0 * (GLfloat)w / (GLfloat)h, 160.0 * (GLfloat)w / (GLfloat)h, -160.0, 160.0, -1000.0, 1000.0);
    
    }
    glMatrixMode(GL_MODELVIEW);
}
#else
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;			//transformare anizotropica, forma se modifica functie de forma(dimens) viewportului
    glViewport(0, 0, w, h);	//daca w>h stabilim ca baza inaltime, si stab unit logica de dimens in fct de h(h/320, 320 lungime lat patrat)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-160.0, 160.0, -160.0, 160.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
#endif

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 800, 600);
    auxInitWindow("Un patrat");
    myInit();
    auxKeyFunc(AUX_LEFT, MutaStanga);
    auxKeyFunc(AUX_RIGHT, MutaDreapta);
    auxKeyFunc(AUX_UP, MutaSus);
    auxKeyFunc(AUX_DOWN, MutaJos);
    auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
    auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
    
   //auxWireSphere(myReshape);

    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
