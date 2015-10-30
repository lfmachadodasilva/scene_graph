/* 
* File:   Main.cpp
* Author: Luiz Felipe Machado da Silva
*/

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

#include "VVector.h"
#include "Node.h"
#include "Entity.h"
#include "Material.h"
#include "Light.h"
#include "Cube.h"
#include "Camera.h"
#include "Color.h"
#include "Scene.h"
#include "Transform.h"
#include "Mesh.h"
#include "Sphere.h"
#include "Environ.h"
#include "Fog.h"
#include "Texture.h"

static Scene * scene;

//-----------------------------------------------------------------------------------------------------------

static void createScene(void) {

	scene = new Scene();

	#pragma region Fog
	{
		Environ * environ = new Environ();
		Fog * fog = new Fog();
		fog->setColor(0.0f, 0.0f, 0.0f, 0.0f);
		fog->setDistance(1.0f, 3.0f);
		environ->addNode(fog);
		scene->addNode(environ);
	}
	#pragma endregion

	#pragma region Camera
	{//Create camera
		Camera * camera = new Camera();
		camera->setZfar(100.0f);
		camera->setZnear(0.1f);
		camera->setfovy(50.0f);
		camera->setEye(VVector(1.5f, 1.5f, 1.5f));
		camera->setCenter(VVector(0.0f, -1.5f, 0.0f));
		camera->setUp(VVector(0.0f, 1.0f, 0.0f));
		scene->addNode(camera);
		scene->setCamera(camera);
	}//---
	#pragma endregion

	#pragma region paper
	{
		Material * paperM = new Material();
		paperM->setAmbient(0.7f, 0.7f, 0.7f, 1.0f);
		paperM->setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
		paperM->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Texture * paperTexture = new Texture();
		paperTexture->setTexture(GL_TEXTURE_2D);
		paperTexture->setType(GL_LINEAR);
		paperTexture->loadTextureFile("opengl.bmp");

		Transform * paperT = new Transform();
		Cube * paper = new Cube();
		paper->setSize(VVector(0.15f, 0.001f, 0.15f));
		paper->setTextureSize(1.0f);
		paper->setOffSet(0.75f, 1.0f);
		Entity * paperE = new Entity();
		paperE->setShape(paper);
		paperE->setAppearence(paperTexture);
		paperT->addNode(paperE);
		paperT->translate(0.4f, 0.04f, 0.7f);
		scene->addNode(paperT);

	}
	#pragma endregion

	#pragma region Floor
	{//Create floor
		Material * floorM = new Material();
		floorM->setAmbient(0.7f, 0.7f, 0.7f, 1.0f);
		floorM->setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
		floorM->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Texture * floorTexture = new Texture();
		floorTexture->setTexture(GL_TEXTURE_2D);
		floorTexture->setType(GL_LINEAR);
		floorTexture->loadTextureFile("floor.bmp");

		Transform * floorT = new Transform();
		Cube * floorCube = new Cube();
		floorCube->setSize(VVector(1.5f, 0.01f, 1.5f));
		floorCube->setTextureSize(2.0f);
		Entity * floorEntity = new Entity();
		floorEntity->setShape(floorCube);
		floorEntity->setAppearence(floorTexture);
		floorT->addNode(floorEntity);
		floorT->translate(-0.25f, -0.301f, -0.25f);
		scene->addNode(floorT);
	}
	#pragma endregion

	#pragma region Table
	{//Create Table		

		Material * woodM = new Material();
		woodM->setAmbient(0.4f, 0.2f, 0.0f, 1.0f);
		woodM->setDiffuse(0.4f, 0.2f, 0.0f, 1.0f);
		woodM->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Texture * woodT = new Texture();
		woodT->setTexture(GL_TEXTURE_2D);
		woodT->setType(GL_NEAREST);
		woodT->loadTextureFile("wood.bmp");

		{//Top table
			Transform * tableTop = new Transform();
			Cube * topTableCube = new Cube();
			topTableCube->setSize(VVector(1.0f, 0.04f, 1.0f));
			topTableCube->setTextureSize(1.0f);
			Entity * topTableEntity = new Entity();
			topTableEntity->setShape(topTableCube);
			topTableEntity->setAppearence(woodT);
			tableTop->addNode(topTableEntity);
			scene->addNode(tableTop);
		}//---

		{//front left feet table
			Transform * frontLeftTableFeet = new Transform();
			Cube * frontLeftTableFeetCube = new Cube();
			frontLeftTableFeetCube->setSize(VVector(0.1f, 0.3f, 0.1f));
			frontLeftTableFeetCube->setTextureSize(1.0f);
			Entity * frontLeftTableFeetEntity = new Entity();
			frontLeftTableFeetEntity->setShape(frontLeftTableFeetCube);
			frontLeftTableFeetEntity->setAppearence(woodT);
			frontLeftTableFeet->addNode(frontLeftTableFeetEntity);
			frontLeftTableFeet->translate(0.9f, -0.3f, 0.9f); 
			scene->addNode(frontLeftTableFeet);
		}//---

		{//front left feet table
			Transform * frontRightTableFeet = new Transform();
			Cube * frontRightTableFeetCube = new Cube();
			frontRightTableFeetCube->setSize(VVector(0.1f, 0.3f, 0.1f));
			frontRightTableFeetCube->setTextureSize(1.0f);
			Entity * frontRightTableFeetEntity = new Entity();
			frontRightTableFeetEntity->setShape(frontRightTableFeetCube);
			frontRightTableFeetEntity->setAppearence(woodT);
			frontRightTableFeet->addNode(frontRightTableFeetEntity);
			frontRightTableFeet->translate(0.0f, -0.3f, 0.9f); 
			scene->addNode(frontRightTableFeet);
		}//---

		{//back left feet table
			Transform * backLeftTableFeet = new Transform();
			Cube * backLeftTableFeetCube = new Cube();
			backLeftTableFeetCube->setSize(VVector(0.1f, 0.3f, 0.1f));
			backLeftTableFeetCube->setTextureSize(1.0f);
			Entity * backLeftTableFeetEntity = new Entity();
			backLeftTableFeetEntity->setShape(backLeftTableFeetCube);
			backLeftTableFeetEntity->setAppearence(woodT);
			backLeftTableFeet->addNode(backLeftTableFeetEntity);
			backLeftTableFeet->translate(0.9f, -0.3f, 0.0f); 
			scene->addNode(backLeftTableFeet);
		}//---

		{//back right feet table
			Transform * backRightTableFeet = new Transform();
			Cube * backRightTableFeetCube = new Cube();
			backRightTableFeetCube->setSize(VVector(0.1f, 0.3f, 0.1f));
			backRightTableFeetCube->setTextureSize(1.0f);
			Entity * backRightTableFeetEntity = new Entity();
			backRightTableFeetEntity->setShape(backRightTableFeetCube);
			backRightTableFeetEntity->setAppearence(woodT);
			backRightTableFeet->addNode(backRightTableFeetEntity);
			backRightTableFeet->translate(0.0f, -0.3f, 0.0f); 
			scene->addNode(backRightTableFeet);
		}//---
	}
	#pragma endregion

	#pragma region Cube
	{
		Material * cubeM1 = new Material();
		cubeM1->setAmbient(0.8f, 0.8f, 0.0f, 1.0f);
		cubeM1->setDiffuse(0.8f, 0.8f, 0.0f, 1.0f);
		cubeM1->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Material * cubeM2 = new Material();
		cubeM2->setAmbient(0.0f, 0.0f, 0.3f, 1.0f);
		cubeM2->setDiffuse(0.0f, 0.0f, 0.3f, 1.0f);
		cubeM2->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		{//Cube 1
			Transform * cube1T = new Transform();
			Cube * cube1Cube = new Cube();
			cube1Cube->setSize(VVector(0.1f, 0.1f, 0.1f));
			Entity * cube1Entity = new Entity();
			cube1Entity->setShape(cube1Cube);
			cube1Entity->setAppearence(cubeM1);
			cube1T->addNode(cube1Entity);
			cube1T->translate(0.6f, 0.02f, 0.1f); 
			cube1T->scale(2.0f, 2.0f, 1.0f);
			scene->addNode(cube1T);
		}

		{//Cube 2
			Transform * cube2T = new Transform();
			Cube * cube2Cube = new Cube();
			cube2Cube->setSize(VVector(0.1f, 0.1f, 0.1f));
			Entity * cube2Entity = new Entity();
			cube2Entity->setShape(cube2Cube);
			cube2Entity->setAppearence(cubeM1);
			cube2T->addNode(cube2Entity);
			cube2T->translate(0.2f, 0.125f, 0.3005f); 
			cube2T->rotate(60.0f, 2.0f, 0.0f, 0.0f);
			scene->addNode(cube2T);
		}

		{//Cube 3
			Transform * cube3T = new Transform();
			Cube * cube3Cube = new Cube();
			cube3Cube->setSize(VVector(0.2f, 0.1f, 0.2f));
			Entity * cube3Entity = new Entity();
			cube3Entity->setShape(cube3Cube);
			cube3Entity->setAppearence(cubeM2);
			cube3T->addNode(cube3Entity);
			cube3T->translate(0.1f, 0.02f, 0.1f); 
			scene->addNode(cube3T);
		}
	}
	#pragma endregion

	#pragma region Bunny
	{
		Material * bunnyM = new Material();
		bunnyM->setAmbient(0.7f, 0.7f, 0.7f, 1.0f);
		bunnyM->setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
		bunnyM->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Material * bunnyMRed = new Material();
		bunnyMRed->setAmbient(0.5f, 0.0f, 0.0f, 1.0f);
		bunnyMRed->setDiffuse(0.5f, 0.0f, 0.0f, 1.0f);
		bunnyMRed->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Mesh * bunny = new Mesh();
		bunny->loadGeometry("bunny.msh");

		Transform * bunnyT1 = new Transform();
		Entity * bunny1Entity = new Entity();
		bunny1Entity->setShape(bunny);
		bunny1Entity->setAppearence(bunnyMRed);
		bunnyT1->translate(0.5f, 0.007f, 0.5);
		bunnyT1->addNode(bunny1Entity);
		scene->addNode(bunnyT1);

		Transform * bunnyT2 = new Transform();
		Entity * bunny2Entity = new Entity();
		bunny2Entity->setShape(bunny);
		bunny2Entity->setAppearence(bunnyM);
		bunnyT2->translate(0.8f, 0.001f, 0.7f);
		//bunnyT2->scale(2.0f, 2.1f, 2.1f);
		bunnyT2->addNode(bunny2Entity);
		scene->addNode(bunnyT2);
	}
	#pragma endregion

	#pragma region Ball
	{
		Material * ballM = new Material();
		ballM->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
		ballM->setDiffuse(0.3f, 0.3f, 0.3f, 1.0f);
		ballM->setSpeculate(0.3f, 0.3f, 0.3f, 1.0f);

		Transform * ballT = new Transform();
		Sphere * ball = new Sphere();
		ball->setRadius(0.1f);
		Entity * ballE = new Entity();
		ballE->setAppearence(ballM);
		ballE->setShape(ball);
		ballT->addNode(ballE);
		ballT->translate(0.1f, 0.14, 0.8f);
		scene->addNode(ballT);
	}
	#pragma endregion

	#pragma region Light
	{//Create light
		Light *light = new Light();
		light->setLocation(VVector(2.0f, 2.0f, 2.0f));
		light->setAmbient(0.5f, 0.5f, 0.5f, 1.0f);
		light->setDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
		light->setSpeculate(0.5f, 0.5f, 0.5f, 1.0f);
		scene->addNode(light);
	}
	#pragma endregion 
}

//-----------------------------------------------------------------------------------------------------------

static void redraw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	scene->setupCamera();

	scene->setupLight();

	scene->render();

	glutSwapBuffers();
}

//-----------------------------------------------------------------------------------------------------------

static void initialize(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-----------------------------------------------------------------------------------------------------------

static void keyboard (unsigned char key, int x, int y)
{
  switch (key) {
  case 'q': exit(-1);
  }
  redraw();
}

//-----------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(800, 640);
    glutCreateWindow("Trabalho 2 CG Correcao");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(redraw);
    createScene();
	initialize();
    glutMainLoop();
    return 0;
}

//-----------------------------------------------------------------------------------------------------------