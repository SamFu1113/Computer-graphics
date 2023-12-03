#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>

void init(void){
     glClearColor(1.0,1.0,1.0,0.0);
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0.0,400.0,0.0,400.0);
}
const GLfloat Pi = 3.1415926536f;
const GLint N = 1000;




void drow(void){
     glClear(GL_COLOR_BUFFER_BIT);
     int r=50;
     glColor3f(1,0,0);
     glBegin(GL_POLYGON);
     for(int j=0; j<N; j++)
     	glVertex2f(200+r*cos(j),200+r*sin(j));
     glEnd();

     glColor3f(0,1,0);
     glBegin(GL_POINTS);
     for(int j=0; j<N; j++)
     	glVertex2f(100+r*cos(j),100+r*sin(j));
     glEnd();

     glColor3f(0,0,1);
     glBegin(GL_LINES);
     for(int j=0; j<N; j++)
     	glVertex2f(300+r*cos(j),330+r*sin(j));
     glEnd();

     glColor3f(1,1,0);
     glBegin(GL_LINE_LOOP);
     for(int j=0; j<5; j++)
     	glVertex2f(100+r*cos(j),300+r*sin(j));
     glEnd();

     glColor3f(0,1,1);
     glBegin(GL_LINE_STRIP);
     for(int j=0; j<5; j++)
     	glVertex2f(300+r*cos(j),100+r*sin(j));
     glEnd();

     glColor3f(1,0,1);
     glBegin(GL_TRIANGLES);
     for(int j=0; j<3; j++)
     	glVertex2f(200+r*cos(j),300+r*sin(j));
     glEnd();

     glColor3f(0,0,0);
     glBegin(GL_QUADS);
     for(int j=0; j<4; j++)
     	glVertex2f(200+r*cos(j),100+r*sin(j));
     glEnd();

     glColor3f(0.5,0.5,0);
     glBegin(GL_TRIANGLE_STRIP);
     glVertex2f(300,270);
     glVertex2f(315,250);
     glVertex2f(325,210);
     glVertex2f(340,260);
     glVertex2f(360,190);
     glEnd();


     glColor3f(0.5,0,0.5);
     glBegin(GL_QUAD_STRIP);
     glVertex2f(40,200);
     glVertex2f(65,220);
     glVertex2f(75,250);
     glVertex2f(120,180);
     glVertex2f(145,210);
     glVertex2f(160,250);
     glVertex2f(185,200);
     glEnd();

     glColor3f(0,0.5,0.5);
     glBegin(GL_TRIANGLE_FAN);
     glVertex2f(150,50);
     glVertex2f(250,60);
     glVertex2f(235,70);
     glVertex2f(215,80);
     glVertex2f(185,90);
     glEnd();






     glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("B0329044's-1");
    init();
    glutDisplayFunc(drow);
    glutMainLoop();
}
