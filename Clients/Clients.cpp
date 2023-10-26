#include "stdafx.h"
#include "GameFrameWork.h"

GameFrameWork* g_GameFrameWork;

void RenderScene(void)
{
	g_GameFrameWork->RenderScene();
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	g_GameFrameWork->MouseInput(button, state, x, y);
}

void KeyInput(unsigned char key, int x, int y)
{
	g_GameFrameWork->KeyInput(key, KS_DOWN);
}

void KeyUpInput(unsigned char key, int x, int y)
{
	g_GameFrameWork->KeyInput(key, KS_UP);
}

void SpecialKeyInput(int key, int x, int y)
{
	g_GameFrameWork->KeyInput(key, KS_DOWN);
}

void SpecialKeyUpInput(int key, int x, int y)
{
	g_GameFrameWork->KeyInput(key, KS_UP);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(g_WindowSizeX / 2, g_WindowSizeY / 2);
	glutInitWindowSize(g_WindowSizeX, g_WindowSizeY);
	glutCreateWindow("Studying_Client");

	glewInit();
	g_GameFrameWork = new GameFrameWork();

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutMouseFunc(MouseInput);
	glutKeyboardFunc(KeyInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutSpecialFunc(SpecialKeyInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	glutMainLoop();
	delete g_GameFrameWork;
	return 0;
}

