#include <GL/glut.h>
#include <math.h>

void display();
void reshape(int, int);

void init()
{
    glClearColor(0.1, 0.1, 0.1, 0.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(200, 80);
    glutInitWindowSize(800, 800);

    glutCreateWindow("SPEAKER - KELOMPOK 6");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}


float anglex = 21.0, angley = -21.0;
int   zoom = -10;



void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, zoom);
    glRotatef(anglex, 1.0, 0.0, 0.0);
    glRotatef(angley, 0.0, 1.0, 0.0);



{ // BADAN SPEAKER
    glBegin(GL_QUADS);

    // DEPAN
    glColor3f ( 1.0, 1.0, 1.0);
    glVertex3f(-1.0,  2.0,  1.0);
    glVertex3f(-1.0, -2.0,  1.0);
    glVertex3f( 1.0, -2.0,  1.0);
    glVertex3f( 1.0,  2.0,  1.0);

    // BELAKANG

    glVertex3f( 1.0 ,  2.0 , -1.0 );
    glVertex3f( 1.0 , -2.0 , -1.0 );
    glVertex3f(-1.0 , -2.0 , -1.0 );
    glVertex3f(-1.0 ,  2.0 , -1.0 );

    // KANAN

    glVertex3f( 1.0,    2.0,  1.0 );
    glVertex3f( 1.0,   -2.0,  1.0 );
    glVertex3f( 1.0,   -2.0, -1.0 );
    glVertex3f( 1.0,    2.0, -1.0 );

    // KIRI

    glVertex3f(-1.0,  2.0, -1.0);
    glVertex3f(-1.0, -2.0, -1.0);
    glVertex3f(-1.0, -2.0,  1.0);
    glVertex3f(-1.0,  2.0,  1.0);

    // ATAS

    glVertex3f(-1.0,  2.0, -1.0);
    glVertex3f(-1.0,  2.0,  1.0);
    glVertex3f( 1.0,  2.0,  1.0);
    glVertex3f( 1.0,  2.0, -1.0);

    // BAWAH

    glVertex3f(-1.0, -2.0, -1.0);
    glVertex3f(-1.0, -2.0,  1.0);
    glVertex3f( 1.0, -2.0,  1.0);
    glVertex3f( 1.0, -2.0, -1.0);

    glEnd();
}

{

}

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
