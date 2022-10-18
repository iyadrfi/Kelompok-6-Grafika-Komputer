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

{ // BAGIAN WARNA HITAM
    glBegin(GL_QUADS);

    // Bagian Atas
    glColor3f ( 0.0, 0.0, 0.0);
    glVertex3f(-1.0, 2.0, 1.075);
    glVertex3f(-1.0, 1.9, 1.075);
    glVertex3f( 1.0, 1.9, 1.075);
    glVertex3f( 1.0, 2.0, 1.075);

    glVertex3f(-1.0, 2.0, 1.075);
    glVertex3f(-1.0, 2.0, 1.0);
    glVertex3f( 1.0, 2.0, 1.0);
    glVertex3f( 1.0, 2.0, 1.075);

    // Bagian Bawah
    glVertex3f(-1.0, -2.0, 1.075);
    glVertex3f(-1.0, -1.9, 1.075);
    glVertex3f( 1.0, -1.9, 1.075);
    glVertex3f( 1.0, -2.0, 1.075);

    glVertex3f(-1.0, -2.0, 1.075);
    glVertex3f(-1.0, -2.0, 1.0);
    glVertex3f( 1.0, -2.0, 1.0);
    glVertex3f( 1.0, -2.0, 1.075);

    // Bagian Kanan
    glVertex3f( 1.0,  2.0, 1.075);
    glVertex3f( 0.9,  2.0, 1.075);
    glVertex3f( 0.9, -2.0, 1.075);
    glVertex3f( 1.0, -2.0, 1.075);

    glVertex3f( 1.0, -2.0,  1.075);
    glVertex3f( 1.0, -2.0,  1.0);
    glVertex3f( 1.0,  2.0,  1.0);
    glVertex3f( 1.0,  2.0,  1.075);

    // Bagian Kiri
    glVertex3f(-1.0,  2.0, 1.075);
    glVertex3f(-0.9,  2.0, 1.075);
    glVertex3f(-0.9, -2.0, 1.075);
    glVertex3f(-1.0, -2.0, 1.075);

    glVertex3f(-1.0,   2.0,  1.075);
    glVertex3f(-1.0,   2.0,  1.0);
    glVertex3f(-1.0,  -2.0,  1.0);
    glVertex3f(-1.0,  -2.0,  1.075);

    glEnd();
}

{ // BADAN SPEAKER
    glBegin(GL_QUADS);

    // DEPAN
    glColor3f ( 0.05, 0.05, 0.05);
    glVertex3f(-1.0,  2.0,  1.0);
    glVertex3f(-1.0, -2.0,  1.0);
    glVertex3f( 1.0, -2.0,  1.0);
    glColor3f ( 0.12, 0.12, 0.12);
    glVertex3f( 1.0,  2.0,  1.0);

    // BELAKANG
    glColor3f ( 0.70,  0.56,  0.39);
    glVertex3f( 1.0 ,  2.0 , -1.0 );
    glVertex3f( 1.0 , -2.0 , -1.0 );
    glVertex3f(-1.0 , -2.0 , -1.0 );
    glVertex3f(-1.0 ,  2.0 , -1.0 );

    // KANAN
    glColor3f ( 0.70,  0.56,  0.39);
    glVertex3f( 1.0,    2.0,  1.0 );
    glVertex3f( 1.0,   -2.0,  1.0 );
    glVertex3f( 1.0,   -2.0, -1.0 );
    glVertex3f( 1.0,    2.0, -1.0 );

    // KIRI
    glColor3f ( 0.70,  0.56,  0.39);
    glVertex3f(-1.0,  2.0, -1.0);
    glVertex3f(-1.0, -2.0, -1.0);
    glVertex3f(-1.0, -2.0,  1.0);
    glVertex3f(-1.0,  2.0,  1.0);

    // ATAS
    glColor3f ( 0.87,  0.69,  0.48);
    glVertex3f(-1.0,  2.0, -1.0);
    glVertex3f(-1.0,  2.0,  1.0);
    glVertex3f( 1.0,  2.0,  1.0);
    glVertex3f( 1.0,  2.0, -1.0);

    // BAWAH
    glColor3f ( 0.18,  0.12,  0.12);
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
