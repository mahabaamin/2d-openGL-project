#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include <stdlib.h>
#include <windows.h>


void display();
void reshape(int w,int h);
void timer(int);
void timer2(int);

void init(){
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
float y=0;
float x=0;
float n=0;
int state=1;
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("(2d)");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000,timer,0);
    glutTimerFunc(2500/60,timer2,0);

    init();

    glutMainLoop();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //sun
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    double angle;
    for(int i=0;i<360;i++)
    {
        angle= i*(3.14/180);
        glVertex2f(0.9*cos(angle)-8+x,1.1*sin(angle)+8.8);
    }
    glEnd();

    //cloud circles
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    double anglec;
    for(int i=0;i<360;i++)
    {
        anglec= i*(3.14/180);
        glVertex2f(1*cos(anglec)+7.5+y,1.1*sin(anglec)+7);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    double anglec2;
    for(int i=0;i<360;i++)
    {
        anglec2= i*(3.14/180);
        glVertex2f(1*cos(anglec2)+8.5+y,1.1*sin(anglec2)+7);
    }
    glEnd();

    //cloud oval
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    double anglecc;
    for(int i=0;i<360;i++)
    {
        anglecc= i*(3.14/180);
        glVertex2f(2*cos(anglecc)+8+y,1.1*sin(anglecc)+6);
    }
    glEnd();

    //grass
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex2f(-10,-2);
    glVertex2f(10,-2);
    glVertex2f(10,-10);
    glVertex2f(-10,-10);
    glEnd();

    //tree branch
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.1,0.1);
    glVertex2f(-4.5,3);
    glVertex2f(-3.5,3);
    glVertex2f(-3.5,-2);
    glVertex2f(-4.5,-2);
    glEnd();

    //tree
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    glVertex2f(-2,4);
    glVertex2f(-6,4);
    glVertex2f(-4,8);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    glVertex2f(-1,1);
    glVertex2f(-7,1);
    glVertex2f(-4,6);
    glEnd();


    //tree branch 2
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.1,0.1);
    glVertex2f(4.8,0);
    glVertex2f(5.3,0);
    glVertex2f(5.3,-2);
    glVertex2f(4.8,-2);
    glEnd();

    //tree 2
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    glVertex2f(4,1.8);
    glVertex2f(6,1.8);
    glVertex2f(5,4);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    glVertex2f(3.5,0);
    glVertex2f(6.5,0);
    glVertex2f(5,3);
    glEnd();


    //rotating ball
    glRotatef(n,0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    double angle13;
    for(int i=0;i<360;i++)
    {
        angle13= i*(3.14/180);
        glVertex2f(1*cos(angle13)-5,1*sin(angle13)-5);
    }
    glEnd();



    glutSwapBuffers();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

void timer (int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    switch(state)
    {
     case 1:
        if(x<16){
            x+=0.1;
            y-=0.1;}
        else
            state=0;
        break;
     case 0:
        if(x>0){
            x-=0.1;
            y+=0.1;}
        else
            state=1;
        break;
    }
}


void timer2(int)
{
    glutPostRedisplay();
    glutTimerFunc(2500/60,timer2,0);
    n-=5;
}
