///
///	This class is designed to be the one place where all
///	shapes are created. It utilizes the UShapeBuilder class
///	to build the shapes into GLMesh structs. The individual
///	shape structs are then added to a vector called "scene" that is
///	then passed to the main render method in the source class
///	(5-3 Texturing a Pyramid.cpp)
///
///
///	Follow the standard shown below in the <summary> to see
///	how to build a shape
///




#include "SceneBuilder.h"
#include "ShapeBuilder.h"
#include "Mesh.h"

using namespace std;


void SceneBuilder::UBuildScene(vector<GLMesh>& scene)
{




	// seed the rand() function once
	srand(time(nullptr));


	/// <summary>
	///
	///BUILDING A SHAPE:
	///To build a shape, follow the following standard:
	///
	///		GLMesh <glmesh_name>
	///		<glmesh_name>.p = {
	///		red float, green float, blue float, alpha float,
	///		x scale float, y scale float, z scale float,
	///		x rotation degrees float, 1.0f, 0.0f, 0.0f,
	///		y rotation degrees float, 0.0f, 1.0f, 0.0f,
	///		z rotation degrees float, 0.0f, 0.0f, 1.0f,
	///		x translate float, y translate float, z translate float,
	///		x texture scale float, y texture scale float
	///		};
	///		<glmesh_name>.texFilename = "textures\\[filename.filetype]";
	///		<glmesh_name>.length = float;
	///		<glmesh_name>.height = float;
	///		<glmesh_name>.radius = float;
	///		<glmesh_name>.number_of_sides = float;
	///		ShapeBuilder::<ShapeBuilderMethod>(<glmesh_name>);
	///		**OR**
	///		ShapeBuilder::<ShapeBuild "Rainbow" Shape>(<glmesh_name>, rand() % 100 + 1);
	///		scene.push_back(<glmesh_name>);
	///
	///
	///
	///
	///
	///
	/// </summary>
	/// <param name="scene"></param>




	// PEN BODY
	GLMesh cyl_gMesh01;
	cyl_gMesh01.p = {
		1.0f, 1.0f, 1.0f, 1.0f,
		0.25f, 1.0f, 0.25f,
		-90.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		45.0f, 0.0f, 0.0f, 1.0f,
		-5.0f, 0.10f, 3.0f,
		1.0f, 1.0f
	};
	cyl_gMesh01.height = 4.0f;
	cyl_gMesh01.radius = 0.5f;
	cyl_gMesh01.number_of_sides = 128.0f;
	cyl_gMesh01.texFilename = "textures\\PenBodyTexture.png";
	ShapeBuilder::UBuildCylinder(cyl_gMesh01);
	scene.push_back(cyl_gMesh01);



	// PEN CLIP
	GLMesh cyl_gMesh02;
	cyl_gMesh02.p = {
		1.0f, 1.0f, 1.0f, 1.0f,
		0.25f, 1.0f, 0.02f,
		-90.0f, 1.0f, 0.0f, 0.0f,
		-55.0f, 0.0f, 1.0f, 0.0f,
		45.0f, 0.0f, 0.0f, 1.0f,
		-5.5f, 0.20f, 2.5f,
		1.0f, 1.0f
	};
	cyl_gMesh02.height = 1.5f;	cyl_gMesh02.radius = 0.4f;	cyl_gMesh02.number_of_sides = 16.0f;
	cyl_gMesh02.texFilename = "textures\\grey.png";
	ShapeBuilder::UBuildCylinder(cyl_gMesh02);
	scene.push_back(cyl_gMesh02);



	// PEN BUTT
	GLMesh cyl_gMesh03;
	cyl_gMesh03.p = {
		1.0f, 1.0f, 1.0f, 1.0f,
		0.25f, 1.0f, 0.25f,
		-90.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		45.0f, 0.0f, 0.0f, 1.0f,
		-5.0f, 0.1f, 3.0f,
		1.0f, 1.0f
	};

	cyl_gMesh03.height = 3.0f;	cyl_gMesh03.radius = 0.35f;	cyl_gMesh03.number_of_sides = 128.0f;
	cyl_gMesh03.texFilename = "textures\\grey.png";
	ShapeBuilder::UBuildCylinder(cyl_gMesh03);
	scene.push_back(cyl_gMesh03);


	// PEN TIP
	GLMesh con_gMesh01;
	con_gMesh01.p = {
		1.0f, 1.0f, 1.0f, 1.0f,
		0.25f, 0.5f, 0.25f,
		-90.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		45.0f, 0.0f, 0.0f, 1.0f,
		-7.85f, 0.1f, 0.15f,
		1.0f, 1.0f
	};
	con_gMesh01.height = 1.0f;	con_gMesh01.radius = 0.5f;	con_gMesh01.number_of_sides = 128.0f;
	con_gMesh01.texFilename = "textures\\pen_tip.png";
	ShapeBuilder::UBuildCone(con_gMesh01);
	scene.push_back(con_gMesh01);



	// DESK
	GLMesh plan_gMesh01;
	plan_gMesh01.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		16.0f, 2.0f, 16.0f,					// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		45.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		1.0f, 0.0f, 0.0f,					// translate x, y, z
		1.0f, 1.0f
	};
	plan_gMesh01.texFilename = "textures\\DeskTexture.png";
	ShapeBuilder::UBuildPlane(plan_gMesh01);
	scene.push_back(plan_gMesh01);


	// BOOK
	GLMesh book_gMesh01;
	book_gMesh01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		8.0f,	1.0f,	6.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		132.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		0.0f,	0.0f,	-4.0f,
		2.75f,	2.0f
	};
	book_gMesh01.texFilename = "textures\\BookTexture.png";
	ShapeBuilder::UBuildCube(book_gMesh01);
	scene.push_back(book_gMesh01);

	// ORANGE CYLINDER
	GLMesh orange_gMesh01;
	orange_gMesh01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.0f,	1.0f,	1.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		1.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		10.0f,	0.0f,	-5.5f,
		1.0f,	1.0f
	};
	orange_gMesh01.height = 1.0f;
	orange_gMesh01.radius = 1.0f;
	orange_gMesh01.number_of_sides = 128.0f;
	orange_gMesh01.texFilename = "textures\\orangetexture.png";
	ShapeBuilder::UBuildCylinder(orange_gMesh01);
	scene.push_back(orange_gMesh01);

	// Fix when the sphere shape builder is finished.
	//// ORANGE
	//GLMesh orange_gMesh01;
	//orange_gMesh01.p = {
	//	1.0f,	1.0f,	1.0f,	1.0f,
	//	1.0f,	1.0f,	1.0f,
	//	0.0f,	1.0f,	0.0f,	0.0f,
	//	1.0f,	0.0f,	1.0f,	0.0f,
	//	0.0f,	0.0f,	0.0f,	1.0f,
	//	0.0f,	0.0f,	-4.0f,
	//	1.0f,	1.0f
	//};
	//orange_gMesh01.texFilename = "textures\\OrangeTexture.png";
	//ShapeBuilder::UBuildSphere(orange_gMesh01);
	//scene.push_back(orange_gMesh01);

	// GUITAR PICK PYRAMID TOP
	GLMesh guitarPyramidTop_01;
	guitarPyramidTop_01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.8f,	0.8f,	0.8f,
		0.0f,	1.0f,	0.0f,	0.0f,
		65.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-4.0f,	0.18f,	1.0f,
		0.75f,	0.75f
	};
	guitarPyramidTop_01.height = 0.8f;
	guitarPyramidTop_01.radius = 0.5;
	guitarPyramidTop_01.number_of_sides = 3.0f;
	guitarPyramidTop_01.texFilename = "textures\\PyramidTexture.png";
	ShapeBuilder::UBuildCone(guitarPyramidTop_01);
	scene.push_back(guitarPyramidTop_01);

	// GUITAR PICK PYRAMID BOTTOM
	GLMesh guitarPyramidBottom_01;
	guitarPyramidBottom_01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.8f,	0.8f,	0.8f,
		0.0f,	1.0f,	0.0f,	0.0f,
		65.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-4.0f,	0.1f,	1.0f,
		1.0f,	1.0f
	};
	guitarPyramidBottom_01.height = 0.1f;
	guitarPyramidBottom_01.radius = 0.5;
	guitarPyramidBottom_01.number_of_sides = 3.0f;
	guitarPyramidBottom_01.texFilename = "textures\\PyramidTexture.png";
	ShapeBuilder::UBuildCylinder(guitarPyramidBottom_01);
	scene.push_back(guitarPyramidBottom_01);


}

