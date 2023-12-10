#include <GL/glut.h>
#include <math.h>

const float PI = 3.1415926535f;

// Sun position and color
float sun_x = 0.0f;
float sun_y = 0.0f;
float sun_radius = 0.2f;
float sun_color_r = 1.0f;
float sun_color_g = 1.0f;
float sun_color_b = 0.0f;

// Sky color
float sky_color_r = 0.0f;
float sky_color_g = 0.5f;
float sky_color_b = 1.0f;

// Angle for sun movement
float angle = 0.0f;

// Sunrise and sunset flags
bool sunrise = true;

void drawSky() {
  glBegin(GL_QUADS);
    glColor3f(sky_color_r, sky_color_g, sky_color_b);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
  glEnd();
}

void drawSun() {
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(sun_color_r, sun_color_g, sun_color_b);
    glVertex2f(sun_x, sun_y);
    for (int i = 0; i <= 360; i++) {
      float x = sun_radius * cos(i * PI / 180.0f) + sun_x;
      float y = sun_radius * sin(i * PI / 180.0f) + sun_y;
      glVertex2f(x, y);
    }
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  drawSky();

  // Update sun position and color based on angle
  if (sunrise) {
    angle += 0.01f;
    sun_x = -1.0f + 2.0f * angle;
    sun_color_r = 1.0f - angle;
    sun_color_g = angle;
  } else {
    angle -= 0.01f;
    sun_x = -1.0f + 2.0f * angle;
    sun_color_r = angle;
    sun_color_g = 1.0f - angle;
  }

  // Change direction after reaching top or bottom
  if (sunrise && sun_x > 1.0f) {
    sunrise = false;
  } else if (!sunrise && sun_x < -1.0f) {
    sunrise = true;
  }

  drawSun();

  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Sunrise and Sunset");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  glutMainLoop();

  return 0;
}

