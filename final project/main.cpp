/*
用陣列去存，rock和srock為三個點，pp為方形的四個點和頭頂，apple candy為中心，
gap為pp的中心x座標在gap的x_min和x_max中間時，掉下去死亡。
*/
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
GLfloat X=200.0f, Y=40.0f;
GLint life,score,wwin;
GLint rx, rx1, rx2,srx, srx1, srx2, ry=570, tt=100;
GLint ap, ca, gp;

float xr = 0, yr = 0;

double n = 3.141592653589793238462643;
#define _USE_MATH_DEFINES
class s
{
      public:
         float x, y, r;
};
s rocks[3];
s rocks1[3];
s rocks2[3];

s srocks[3];
s srocks1[3];
s srocks2[3];

s apples[100];
s candys[100];
s gaps[4];
s pps[5];
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

void Drawing();
void DrawPolygon(int , int);
void OnMouse(int, int, int, int);
void OnKeyboard(unsigned char, int, int);

void Initialization();
void OnDisplay();
void OnReshape(int , int );

void drawString(const char* str);

int winWidth(400), winHeight(600);

#define MAX_CHAR 128
//-----------------------------------------------------------

void rock(int x, int y){ /////rock

	glColor3f(0.5,0.5,0.5);
    glBegin (GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x,y-30);
	glEnd ( );

	rocks[0].x = x-10;
	rocks[0].y = y;
	rocks[1].x = x+10;
	rocks[1].y = y;
	rocks[2].x = x;
	rocks[2].y = y-30;
}
void rock1(int x, int y){ /////rock1

	glColor3f(0.5,0.5,0.5);
    glBegin (GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x,y-30);
	glEnd ( );

	rocks1[0].x = x-10;
	rocks1[0].y = y;
	rocks1[1].x = x+10;
	rocks1[1].y = y;
	rocks1[2].x = x;
	rocks1[2].y = y-30;
}

void rock2(int x, int y){  /////rock2

	glColor3f(0.5,0.5,0.5);
    glBegin (GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x,y-30);
	glEnd ( );

	rocks2[0].x = x-10;
	rocks2[0].y = y;
	rocks2[1].x = x+10;
	rocks2[1].y = y;
	rocks2[2].x = x;
	rocks2[2].y = y-30;
}

void srock(int x, int y){  //////srock

	glColor3f(1,0,0);
    glBegin (GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x,y-30);
	glEnd ( );

	glColor3f(0,0,0);
    glBegin (GL_POLYGON);
        glVertex2f(x-7,y-3);
        glVertex2f(x+7,y-3);
        glVertex2f(x,y-27);
	glEnd ( );

	srocks[0].x = x-10;
	srocks[0].y = y;
	srocks[1].x = x+10;
	srocks[1].y = y;
	srocks[2].x = x;
	srocks[2].y = y-30;
}

void srock1(int x, int y){  //////srock1

	glColor3f(1,0,0);
    glBegin (GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x,y-30);
	glEnd ( );

	glColor3f(0,0,0);
    glBegin (GL_POLYGON);
        glVertex2f(x-7,y-3);
        glVertex2f(x+7,y-3);
        glVertex2f(x,y-27);
	glEnd ( );

	srocks1[0].x = x-10;
	srocks1[0].y = y;
	srocks1[1].x = x+10;
	srocks1[1].y = y;
	srocks1[2].x = x;
	srocks1[2].y = y-30;
}

void srock2(int x, int y){  /////srock2

	glColor3f(1,0,0);
    glBegin (GL_POLYGON);
        glVertex2f(x-10,y);
        glVertex2f(x+10,y);
        glVertex2f(x,y-30);
	glEnd ( );

	glColor3f(0,0,0);
    glBegin (GL_POLYGON);
        glVertex2f(x-7,y-3);
        glVertex2f(x+7,y-3);
        glVertex2f(x,y-27);
	glEnd ( );

	srocks2[0].x = x-10;
	srocks2[0].y = y;
	srocks2[1].x = x+10;
	srocks2[1].y = y;
	srocks2[2].x = x;
	srocks2[2].y = y-30;
}

void apple(int x, int y){   /////apple

    glColor3f(1,0,1);
    int len = 10;
    glBegin (GL_POLYGON);
    int m = 100;
	for (int i=0; i<m; i++){
        glVertex2f(x+len*cos(2 * n / m*i), y+len*sin(2 * n / m*i));
        apples[i].x = x+len*cos(2 * n / m*i);
        apples[i].y = y+len*sin(2 * n / m*i);
	}
	apples[0].x = x;
	apples[0].y = y;
	glEnd ( );



}

void candy(int x, int y){   //////candy

    glColor3f(0.92,0.89,0.41);
    int len = 10;
    glBegin (GL_POLYGON);
    int m = 100;
	for (int i=0; i<m; i++){
        glVertex2f(x+len*cos(2 * n / m*i), y+len*sin(2 * n / m*i));
        candys[i].x = x+len*cos(2 * n / m*i);
        candys[i].y = y+len*sin(2 * n / m*i);
	}
	candys[0].x = x;
	candys[0].y = y;
    glEnd ( );



}

void gap_point(int x,int y){   /////gap_point

    glColor3f(0,0,0);
    int len = 5;
    glBegin (GL_POLYGON);
    int m = 100;
	for (int i=0; i<m; i++)
        glVertex2f(x+len*cos(2 * n / m*i), y+len*sin(2 * n / m*i));
	glEnd ( );

}

void gap(int x, int y){   ///////gap

    glColor3f(0,0,0);
    int len = 5;
    glBegin (GL_POLYGON);
        glVertex2f(x-20, y-5);
        glVertex2f(x-20, y+5);
        glVertex2f(x+20, y+5);
        glVertex2f(x+20, y-5);
	glEnd ( );

	gaps[0].x = x-20;
	gaps[0].y = y-5;
    gaps[1].x = x-20;
	gaps[1].y = y+5;
    gaps[2].x = x+20;
	gaps[2].y = y+5;
    gaps[3].x = x+20;
	gaps[3].y = y-5;
}

void circle(int x, int y, int len){
    glColor3f(2,0.45,0.15);
    glBegin (GL_POLYGON);
    int m = 100;
	for (int i=0; i<m; i++)
        glVertex2f(x+len*cos(2 * n / m*i), y+len*sin(2 * n / m*i));
	glEnd ( );

}

void square11(int x,int y){
    glColor3f(1,0.45,0.15);
    glBegin(GL_POLYGON);
    glVertex2f(x-20,y-20);
    glVertex2f(x-20,y);
    glVertex2f(x+20,y);
    glVertex2f(x+20,y-20);
	glEnd ( );
}

void eyes(int x,int y){

    int len = 5;
    glColor3f(0,0,0);
    glBegin (GL_POLYGON);
    int m = 100;
	for (int i=0; i<m; i++)
        glVertex2f(x-10+len*0.8*cos(2 * n / m*i), y+5+len*1.2*sin(2 * n / m*i));
	glEnd ( );

	glColor3f(1,1,1);
    glBegin (GL_POLYGON);
	for (int i=0; i<m; i++)
        glVertex2f(x-10+2*cos(2 * n / m*i), y+7+2*sin(2 * n / m*i));
	glEnd ( );


    glColor3f(0,0,0);
    glBegin (GL_POLYGON);
	for (int i=0; i<m; i++)
        glVertex2f(x+10+len*0.8*cos(2 * n / m*i), y+5+len*1.2*sin(2 * n / m*i));
	glEnd ( );

	glColor3f(1,1,1);
    glBegin (GL_POLYGON);
	for (int i=0; i<m; i++)
        glVertex2f(x+10+2*cos(2 * n / m*i), y+7+2*sin(2 * n / m*i));
	glEnd ( );

}

void mouth(int x, int y){
    int len = 5;
    glColor3f(1,0.5,0.5);
    glBegin (GL_POLYGON);
    int m = 100;
	for (int i=0; i<m; i++)
        glVertex2f(x+len*1.5*cos(2 * n / m*i), y-8-len*0.8*sin(2 * n / m*i));
	glEnd ( );


    len = 2;
	glColor3f(1,0.8,0.5);
    glBegin (GL_POLYGON);
	for (int i=0; i<m; i++)
        glVertex2f(x-1+len*1.5*cos(2 * n / m*i), y-7-len*0.8*sin(2 * n / m*i));
	glEnd ( );


}

void pp(){  //////pp
    int len = 20;
    circle(X,Y,len);
    square11(X,Y);
    eyes(X,Y);
    mouth(X,Y);
    pps[0].x = X-20;
    pps[0].y = Y-20;
    pps[1].x = X-20;
    pps[1].y = Y;
    pps[2].x = X+20;
    pps[2].y = Y;
    pps[3].x = X+20;
    pps[3].y = Y-20;
    pps[4].x = X;
    pps[4].y = Y+20;


    //glutSwapBuffers();
}

void SpecialKey(GLint key,GLint x,GLint y)    ///////////control pp
{

	if(key==GLUT_KEY_LEFT)
	{
		X-=10;
		pp();
	}

	if(key==GLUT_KEY_RIGHT)
	{
		X+=10;
		pp();
	}
	//pp();
}

void over(void){   ////////game over
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,200);
    glVertex2f(0,400);
    glVertex2f(400,400);
    glVertex2f(400,200);
    glEnd();


    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(50,200);
    glVertex2f(0,250);
    glVertex2f(350,400);
    glVertex2f(400,350);
	glEnd ( );

	glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,350);
    glVertex2f(50,400);
    glVertex2f(400,250);
    glVertex2f(350,200);
	glEnd ( );
	glFlush ( );
}

void win(void){    //////win
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,200);
    glVertex2f(0,400);
    glVertex2f(400,400);
    glVertex2f(400,200);
    glEnd();

    glColor3f(0,1,0);
    glBegin (GL_LINE_LOOP);
    glLineWidth(10);
    int m = 100;
	for (int i=0; i<m; i++)
        glVertex2f(200+100*cos(2 * n / m*i), 300+100*sin(2 * n / m*i));
	glEnd ( );

	glFlush ( );
}

void DrawPOLYGON (void) ////level 1
{
    int x_max=400;
    int y_max=600;
    srand (time(NULL));
	glLineWidth(5);
    pp();
    rock(rx,ry);
    rock1(rx1,ry);
    rock2(rx2,ry);
    //rock over
     glutSwapBuffers();
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            if(pps[i].x == rocks[j].x && pps[i].y == rocks[j].y){
                life--;
            }
            else if(pps[i].x == rocks1[j].x && pps[i].y == rocks1[j].y){
                life--;
            }
            else if(pps[i].x == rocks2[j].x && pps[i].y == rocks2[j].y){
                life--;
            }
        }
    }
    glutSwapBuffers();
    if(life <= 0){
        over();
        }
    if(wwin == score){
        win();
    }
    glFlush ( );
}

void DrawPOLYGON2 (void) ////level 2
{
    int x_max=400;
    int y_max=600;
    srand (time(NULL));
	glLineWidth(5);
    pp();
    if(score%4 == 0){
        apple(ap,ry);
        for(int i=0; i<5; i++){
            if(pps[i].x == apples[0].x && pps[i].y == apples[0].y){
                life++;
            }
        }
    }
    rock(rx,ry);
    rock1(rx1,ry);
    rock2(rx2,ry);
    //rock over
     glutSwapBuffers();

     for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            if(pps[i].x == rocks[j].x && pps[i].y == rocks[j].y){
                life--;
            }
            else if(pps[i].x == rocks1[j].x && pps[i].y == rocks1[j].y){
                life--;
            }
            else if(pps[i].x == rocks2[j].x && pps[i].y == rocks2[j].y){
                life--;
            }
        }

    }

    if(life <= 0){
        over();
    }
    if(wwin == score){
        win();
    }
    glFlush ( );
}

void DrawPOLYGON3 (void)////level 3
{
    int x_max=400;
    int y_max=600;
    srand (time(NULL));
	glLineWidth(5);
    pp();

    if(score%4 == 0){
        apple(ap,ry);
        for(int i=0; i<5; i++){

            if(pps[i].x == apples[0].x && pps[i].y == apples[0].y){
                life++;
            }
        }
    }

    if(score%3 == 0){
        srock(srx,ry);
        for(int i=0; i<5;i++){
                for(int j=0; j<3; j++){
                    if(pps[i].x == srocks[j].x && pps[i].y == srocks[j].y){
                            life = life-2;
                    }
                }
        }
    }
    rock(rx,ry);
    rock1(rx1,ry);
    rock2(rx2,ry);
    //rock over
     glutSwapBuffers();

     for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            if(pps[i].x == rocks[j].x && pps[i].y == rocks[j].y){
                life--;
            }
            else if(pps[i].x == rocks1[j].x && pps[i].y == rocks1[j].y){
                life--;
            }
            else if(pps[i].x == rocks2[j].x && pps[i].y == rocks2[j].y){
                life--;
            }
        }
    }

    if(life <= 0){
        over();
    }
    if(wwin == score){
        win();
    }
    glFlush ( );
}

void DrawPOLYGON4 (void)////level 4
{
    int x_max=400;
    int y_max=600;
    srand (time(NULL));
	glLineWidth(5);
    pp();

    if(score%3 == 0){
        apple(ap,ry);
        for(int i=0; i<5; i++){
            if(pps[i].x == apples[0].x && pps[i].y == apples[0].y){
                life++;
            }
        }
    }

    srock(srx,ry);
    srock1(srx1,ry);
    srock2(srx2,ry);
    //rock over
     glutSwapBuffers();

     for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            if(pps[i].x == srocks[j].x && pps[i].y == srocks[j].y){
                life = life-3;
            }
            else if(pps[i].x == srocks1[j].x && pps[i].y == srocks1[j].y){
                life = life-3;
            }
            else if(pps[i].x == srocks2[j].x && pps[i].y == srocks2[j].y){
                life = life-3;
            }
        }
    }
    if(life <= 0){
        over();
    }
    if(wwin == score){
        win();
    }

    glFlush ( );
}

void DrawPOLYGON5 (void)////level 5
{
    int x_max=400;
    int y_max=600;
    srand (time(NULL));
	glLineWidth(5);
    pp();

    if(score%3 == 0){
        apple(ap,ry);
        for(int i=0; i<5; i++){
            if(pps[i].x == apples[0].x && pps[i].y == apples[0].y){
                life++;
            }
        }
    }

    if(score%6 == 0){
        candy(ca,ry);
        for(int i=0; i<5; i++){
            if(pps[i].x == candys[0].x && pps[i].y == candys[0].y){
                life=life+5;
            }
        }
    }
    if((score+1)%2 != 0){
        gap_point(200,15);
    }
    if((score)%2 != 0){
        gap(200,15);

    }else{
        gap(1000,15);
    }
    srock(srx,ry);
    srock1(srx1,ry);
    srock2(srx2,ry);
    //rock over
     glutSwapBuffers();
     for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            if(pps[i].x == srocks[j].x && pps[i].y == srocks[j].y){
                life = life-3;
            }
            else if(pps[i].x == srocks1[j].x && pps[i].y == srocks1[j].y){
                life = life-3;
            }
            else if(pps[i].x == srocks2[j].x && pps[i].y == srocks2[j].y){
                life = life-3;
            }
        }
    }

    if(pps[4].x >= gaps[0].x && pps[4].x <= gaps[2].x){
            life = life-100;
            over();
        }


    if(life <= 0){
        over();
    }
    if(wwin == score){
        win();
    }
    glFlush ( );
}

void Drawing()  ////////////////no
{
}

void selectFont(int size, int charset, const char* face) {   /////////////no
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}

void OnReshape(int w, int h)   ///////////no
{
	winWidth = w;
	winHeight = h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawString(const char* str)  //////////////string
{
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) {
		isFirstCall = 0;
		lists = glGenLists(MAX_CHAR);
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	for (; *str != '\0'; ++str) {
		glCallList(lists + *str);
	}
}

void init (void){
    glClearColor (1.0, 1.0, 1.0, 0.0);
     // Set display-window color to white.
    glMatrixMode (GL_PROJECTION);
           // Set projection parameters.
    gluOrtho2D (0.0, 400.0, 0.0, 600.0);
}

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
}

void border(void)      /////////border
{
    glLineWidth(20);
    glColor3f (0.54, 0.27, 0.074);
    glBegin (GL_LINES);
        glVertex2i (0,0);       // Specify line-segment geometry.
        glVertex2i (0,600);
        glVertex2i (0, 0);       // Specify line-segment geometry.
        glVertex2i (400, 0);
        glVertex2i (0,600);
        glVertex2i (400,600);
        glVertex2i (400, 0);
        glVertex2i (400,600);
    glEnd ( );
}
void background(void)     ///////////////background
{
    glBegin (GL_POLYGON);
        glVertex2i (0,0);       // Specify line-segment geometry.
        glVertex2i (0,600);
        glVertex2i (0, 0);       // Specify line-segment geometry.
        glVertex2i (400, 0);
        glVertex2i (0,600);
        glVertex2i (400,600);
        glVertex2i (400, 0);
        glVertex2i (400,600);
    glEnd ( );
}

void createMenu(void){         //////////////////frist bg
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("classic", 1);
    glutAddMenuEntry("easy", 2);
    glutAddMenuEntry("normal", 3);
    glutAddMenuEntry("hard", 4);
    glutAddMenuEntry("devil", 5);
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Level", submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void timerFunc(int value){     ///////////////////to control rock to move
    srand(time(NULL));
    ry = ry-10;
    if(ry==10){
        ry=570;
        score++;            //////////////////////a circle of rock, add score
        for(;;){
        rx  = rand() % (370) + 30;
        if(rx%10 == 0)
            break;
        }
        for(;;){
            rx1  = rand() % (370) + 30;
            if(rx1%10 == 0)
                break;
        }
        for(;;){
            rx2  = rand() % (370) + 30;
            if(rx2%10 == 0)
                break;
        }
        for(;;){
            srx  = rand() % (370) + 30;
            if(srx%10 == 0)
                break;
        }
        for(;;){
            srx1  = rand() % (370) + 30;
            if(srx1%10 == 0)
                break;
        }
        for(;;){
            srx2  = rand() % (370) + 30;
            if(srx2%10 == 0)
                break;
        }
        for(;;){
            ap  = rand() % (370) + 30;
            if(ap%10 == 0)
                break;
        }
        for(;;){
            ca  = rand() % (370) + 30;
            if(ca%10 == 0)
                break;
        }
        for(;;){
            gp  = rand() % (300) + 50;
            if(gp%10 == 0)
                break;
        }
    }
    if(score == wwin){
        win();
    }

    glutPostRedisplay();
    glutTimerFunc(tt, timerFunc, 1);
}

void display(void){  //////////////main
  glClear(GL_COLOR_BUFFER_BIT);
  if(value == 1){
     glColor3f (1.0, 0.6, 0.47);
     glutPostRedisplay();
     background();
     border();
     DrawPOLYGON();
  }else if(value == 2){
     glColor3f (1.0, 0.68, 0.72);
     glutPostRedisplay();
     background();
     border();
     DrawPOLYGON2();
  }else if(value == 3){
     glColor3f (0.53, 0.8, 1.0);
     glutPostRedisplay();
     background();
     border();
     DrawPOLYGON3();
  }else if(value == 4){
     glColor3f (0.6, 1.0, 0.6);
     glutPostRedisplay();
     background();
     border();
     DrawPOLYGON4();
  }else if(value == 5){
     glColor3f (0.56, 0.73, 0.56);
     glutPostRedisplay();
     background();
     border();
     DrawPOLYGON5();
  }else
    {

	Drawing();
	selectFont(48, ANSI_CHARSET, "Comic Sans MS");
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2i(0, winHeight-45);
	drawString("      PLAY A GAME");
    glRasterPos2i(0, winHeight-85);
    drawString("rule: ");
    glRasterPos2i(0, winHeight-125);
    drawString("1.over 20 rock to win");
    glRasterPos2i(0, winHeight-165);
    drawString("2.life is 1, when life=0 die");
    glRasterPos2i(0, winHeight-205);
    drawString("3.rock will loss 1 life");
    glRasterPos2i(0, winHeight-245);
    drawString("4.srock will loss 3 life");
    glRasterPos2i(0, winHeight-285);
    drawString("5.apple can add 1 life");
    glRasterPos2i(0, winHeight-325);
    drawString("6.candy can add 5 life");
    glRasterPos2i(0, winHeight-365);
    drawString("7.gap will directly die");
    glRasterPos2i(0, winHeight-405);
    drawString("@gap will in middle");
    glRasterPos2i(0, winHeight-485);
    drawString("      click right mouse");
	glutSwapBuffers();
    }

    glFlush();
}

int main(int argc, char **argv){
    life = 1;
    score = 0;        //////////////start score=0
    wwin=20;          //////////////score =20, win
    srand(time(NULL));
    for(;;){
        rx  = rand() % (370) + 30;
        if(rx%10 == 0)
            break;
    }
    for(;;){
        rx1  = rand() % (370) + 30;
        if(rx1%10 == 0)
            break;
    }
    for(;;){
        rx2  = rand() % (370) + 30;
        if(rx2%10 == 0)
            break;
    }
     for(;;){
        srx  = rand() % (370) + 30;
        if(srx%10 == 0)
            break;
    }
    for(;;){
        srx1  = rand() % (370) + 30;
        if(srx1%10 == 0)
            break;
    }
    for(;;){
        srx2  = rand() % (370) + 30;
        if(srx2%10 == 0)
            break;
    }
    for(;;){
        ap  = rand() % (370) + 30;
        if(ap%10 == 0)
            break;
    }
    for(;;){
        ca  = rand() % (370) + 30;
        if(ca%10 == 0)
            break;
    }
    for(;;){
        gp  = rand() % (300) + 50;
        if(gp%10 == 0)
            break;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(400,600);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("game");
    init ( );
    createMenu();
    ry=570;
    glutSpecialFunc(&SpecialKey);
    glutDisplayFunc(display);
    glutTimerFunc(tt, timerFunc, 1);
    glutReshapeFunc(OnReshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}
