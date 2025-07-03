#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

using namespace std;
const int steps = 100;
const float angle = 3.1415926 * 2.f/steps;

void drawCircle (float red, float green, float blue) 
{
    float oldX = 0;
    float oldY = 1;
    float radius =1.0f;

    for(int i =0; i<=steps; i++)
    {
        float newX = radius * sin(angle*i);
        float newY = -radius * cos(angle*i);

        glColor3f(red,green,blue);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(oldX,oldY,0.0f);
        glVertex3f(newX, newY, 0.0f);
        glEnd();

        oldX = newX;
        oldY = newY;
    }
}

int main()
{
    GLFWwindow* window;

    if(!glfwInit())
    {
        cout<< "Error";
        exit(-1);
    }

    window = glfwCreateWindow(800,800,"Hello",0,0);
    if(!window)
    {
        cout<<"Window creation error";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Setting up the Matrix Pipeline
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.1,0.1,1); // To Scale the screen coordinates span from [-1;1] -> [-10;10]


    //bool toggle = false;
    // float xPos =0;
    // float yPos =0;
    // float radius =1.0f;
    float angle_e = 0;
    float angle_m = 0;
    while(!glfwWindowShouldClose(window))
    {

        glClearColor(1,1,1,0); //To fill the screen with color
        
        glClear(GL_COLOR_BUFFER_BIT);   //To clear the screen color pixels

        
        //Drawing A triangle
        //Actual begin and end for one triangle
        // glBegin(GL_TRIANGLES);
        
        // glColor3f(1.0f,0.f,0.f);    //color values,
        // glVertex3f(-0.6f, -0.4f, 0.f);
        // glColor3f(0.0f,1.0f,0.f);
        // glVertex3f(0.6f, -0.4f, 0.f);
        // glColor3f(0.f,0.f,1.0f);
        // glVertex3f(0.f, 0.6f, 0.f);
        
        // glEnd();

        //Drawing a Circle
        //Storing previous points coordinates outside the loop
        // float prevX = xPos;
        // float prevY = yPos - radius;
        // //Create a loop and rotate the triangle
        // for(int i = 0; i <= steps; i++)
        // {

        //     float newX = radius * sin(angle*i); //Calculating the angles for the current Steps
        //     float newY = -radius * cos(angle*i);
            

        //     glBegin(GL_TRIANGLES);
        //     glColor3f(0,0.5f,0);
        //     glVertex3f(0.0f,0.0f,0.0f); //Starting Point
        //     glVertex3f(prevX, prevY, 0.0f); //Initial point from the Y axis
        //     glVertex3f(newX, newY, 0.0f); // New rotated points.
        //     glEnd();

        //     prevX = newX;   // Saving the old values for next cycle steps
        //     prevY = newY;

        // }

        //Drawing the solarsystem
        angle_e += 1;
        angle_m += 3;
        //the Sun 
        drawCircle(1,1,0);

        {
            glPushMatrix();
            glRotatef(angle_e,0,0,1); // Rotate the angle aroudn the Z axis
            glTranslatef(0,5,0); //Up the current coordinate system up to 5 units
            glScalef(0.6,0.6,1);
            drawCircle(0,0.3,1);
            {
                glPushMatrix();
                glRotatef(angle_m,0,0,1);
                glTranslatef(0,2,0);
                glScalef(0.3,0.3,1);
                drawCircle(0.5,0.1,1);
                glPopMatrix();
            }
            glPopMatrix();
        }

        glfwSwapBuffers(window); //To present the Frame ot actual window, swaps to the off screen buffer whcih is then presented
        glfwPollEvents();   //To process the current Events 
    }

    glfwTerminate();

}