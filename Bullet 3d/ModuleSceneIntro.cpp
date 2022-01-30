#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{

	LOG("Loading Intro assets");
	bool ret = true;
	CreateObject({ -70,40,0 }, { 15,2,15 }, Red);
	CreateObject({ 90,15,270 }, { 100,2,250 }, Red);
	CreateObject({ -70,40,48.5f }, { 15,2,80 }, Brown);
	CreateObject({ -38.5f,40,81 }, { 50,2,15 }, Brown);
	CreateObject({ -6,40,79 }, { 15,2,1.5 }, Brown);
	CreateObject({ -6,40,83 }, { 15,2,1.5 }, Brown);
	CreateObject({ 15.5f,40,81 }, { 30,2,15 }, Brown);
	CreateObject({ 15.5f,40,81 }, { 30,2,15 }, Brown);

	CreateRamp({ 45.5f,45,81 }, { 30,2,15 }, 20, { 0, 0, 1 }, Brown);
	CreateRamp({ 155.5f,45,81 }, { 30,2,15 }, -20, { 0, 0, 1 }, Brown);
	CreateRamp({ 180.5f,38,81 }, { 30,2,15 }, -10, { 0, 0, 1 }, Brown);

	CreateObject({ 210.5f,35.5,81 }, { 30,2,15 }, Brown);
	CreateRamp({ 228,35.5,81 }, { 30,2,15 }, 90, { 0,0,1 }, White);
	CreateObject({ 220,35.5,48.5f }, { 15,2,80 }, Brown);
	CreateObject({ 205,35.5,10.5f }, { 15,2,80 }, Brown);
	CreateObject({ 220,35.5,-50.5f }, { 15,2,80 }, Brown);

	CreateObject({ 220,15.5,-100.5f }, { 30,20,30 }, Brown);
	CreateObject({ 200,0.5,-120.5f }, { 30,20,30 }, Brown);
	CreateObject({ 180,-5.5,-140.5f }, { 20,20,20 }, Brown); 
	CreateRamp({ 160,5,-140.5f }, { 40,2,20 }, -4, { 0,0,1 }, Brown);

	CreateObject({ 90,5,-145.5 }, { 100,2,30 }, Brown);
	CreateObject({ 40,5,-95.5 }, { 30,2,100 }, Brown);
	CreateObject({ 90,5,-55.5 }, { 100,2,30 }, Brown);
	CreateObject({ 120,5,-10.5 }, { 20,2,60 }, Brown);

	CreateObject({ 90,7,-145.5 }, { 3,3,3 }, Red);
	CreateObject({ 120,7,-135.5 }, { 3,3,3 }, Red);
	CreateObject({ 135,7,-155.5 }, { 3,3,3 }, Red);
	CreateObject({ 55,7,-155.5 }, { 3,3,3 }, Red);
	CreateObject({ 55,7,-129.5 }, { 3,3,3 }, Red);
	CreateObject({ 88,7,-155.5 }, { 3,3,3 }, Red);



	CreateRamp({ 90, 5, -55.5 }, { 3,10,8 }, -60, { 1, 0, 1 }, Red);
	CreateRamp({ 60, 4, -45.5 }, { 3,10,8 }, -60, { 1, 1, 1 }, Red);

	CreateRamp({ 120,10,30.5 }, { 20,2,30 }, -20, { 1, 0, 0 }, Green);
	CreateRamp({ 117,20,45.5 }, { 20,2,30 }, -40, { 1, 0, 0 }, Green);
	CreateRamp({ 114,40,62.5 }, { 20,2,30 }, -60, { 1, 0, 0 }, Green);
	CreateRamp({ 111,52,70 }, { 20,2,30 }, -90, { 1, 0, 0 }, Green);
	CreateRamp({ 108,77,65.5 }, { 20,2,30 }, -110, { 1, 0, 0 }, Green);
	CreateRamp({ 105,83,60.5 }, { 20,2,30 }, -130, { 1, 0, 0 }, Green);
	CreateRamp({ 102,90,55.5 }, { 20,2,30 }, -150, { 1, 0, 0 }, Green);
	CreateRamp({ 99,98,35.5 }, { 20,2,30 }, -180, { 1, 0, 0 }, Green);
	CreateRamp({ 96,90,15.5 }, { 20,2,30 }, 150, { 1, 0, 0 }, Green);
	CreateRamp({ 93,83,10.5 }, { 20,2,30 }, 130, { 1, 0, 0 }, Green);
	CreateRamp({ 90,77,5.5 }, { 20,2,30 }, 110, { 1, 0, 0 }, Green);
	CreateRamp({ 90,52,0 }, { 20,2,30 }, 90, { 1, 0, 0 }, Green);
	CreateRamp({ 90,40,1.5 }, { 20,2,30 }, 60, { 1, 0, 0 }, Green);
	CreateRamp({ 90,20,17.5 }, { 20,2,30 }, 40, { 1, 0, 0 }, Green);
	CreateRamp({ 90,11,27.5 }, { 20,2,30 }, 10, { 1, 0, 0 }, Green);
	CreateObject({ 90,9,45 }, { 20,2,30 }, Brown);
	CreateRamp({ 90,11,65 }, { 20,2,30 }, -20, { 1,0,0 }, Brown);


	//Arrow 1
	Const[1] = new Cube(20, 10, 2);
	Const[1]->color = Red;

	Const[2] = new Cube(10, 10, 2);
	Const[2]->color = Red;
	Const[2]->SetRotation(45, { 0, 0, 1 });

	//Arrow 2
	Const[3] = new Cube(20, 10, 2);
	Const[3]->color = Red;
	Const[3]->SetRotation(90, { 0, 1, 0 });

	Const[4] = new Cube(2, 10, 10);
	Const[4]->color = Red;
	Const[4]->SetRotation(45, { 1, 0, 0 });

	//Arrow 3
	Const[5] = new Cube(20, 10, 2);
	Const[5]->color = Red;

	Const[6] = new Cube(10, 10, 2);
	Const[6]->color = Red;
	Const[6]->SetRotation(45, { 0, 0, 1 });

	//Arrow 4
	Const[7] = new Cube(20, 10, 2);
	Const[7]->color = Red;
	Const[7]->SetRotation(90, { 0, 1, 0 });

	Const[8] = new Cube(2, 10, 10);
	Const[8]->color = Red;
	Const[8]->SetRotation(45, { 1, 0, 0 });

	//Arrow 5
	Const[9] = new Cube(20, 10, 2);
	Const[9]->color = Red;

	Const[10] = new Cube(10, 10, 2);
	Const[10]->color = Red;
	Const[10]->SetRotation(45, { 0, 0, 1 });

	//Arrow 6
	Const[11] = new Cube(20, 10, 2);
	Const[11]->color = Red;
	Const[11]->SetRotation(90, { 0, 1, 0 });

	Const[12] = new Cube(2, 10, 10);
	Const[12]->color = Red;
	Const[12]->SetRotation(45, { 1, 0, 0 });

	//Arrow 7
	Const[13] = new Cube(20, 10, 2);
	Const[13]->color = Red;
	Const[13]->SetRotation(90, { 0, 0, 1 });

	Const[14] = new Cube(10, 10, 2);
	Const[14]->color = Red;
	Const[14]->SetRotation(45, { 0, 0, 1 });

	//Left Wall
	CreateObject({ 300,0,0 }, { 2,600,600 }, BrightBlue);
	//Top Wall
	CreateObject({ 100,200,0 }, { 600,2,600 }, BrightBlue);
	//BotWall
	CreateObject({ 100,-200,0 }, { 600,2,600 }, BrightBlue);
	//RightWall
	CreateObject({ -100,0,0 }, { 2,600,600 }, BrightBlue);
	//FrontWall
	CreateObject({ 100,-280,135 }, { 600,600,2 }, BrightBlue);
	CreateObject({ 100,340,135 }, { 600,600,2 }, BrightBlue);
	CreateObject({ 400,230,135 }, { 600,600,2 }, BrightBlue);
	CreateObject({ -225,230,135 }, { 600,600,2 }, BrightBlue);
	//BackWall
	CreateObject({ 100,0,-200 }, { 600,600,2 }, White);

	CreateObject({0,-50,0}, {1000,1,1000}, Black);

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0,0);
	p.axis = true;
	p.Render();
	if (left == true) {
		if (movement < 10) {
			movement += 0.1f;
		}
		else if (movement > 10) {
			left = false;
		}
	}
	if (left == false) {
		if (movement > 0) {
			movement -= 0.1f;
		}
		else if (movement < 0) {
			left = true;
		}
	}
	Const[1]->SetPos(-75 + movement, 50, 100);
	Const[2]->SetPos(-65 + movement, 50, 100);

	Const[3]->SetPos(220, 60, 75 + movement);
	Const[4]->SetPos(220, 60, 65 + movement);

	Const[5]->SetPos(220 + movement, 55, -140);
	Const[6]->SetPos(210 + movement, 55, -140);

	Const[7]->SetPos(15, 20, -150 + movement);
	Const[8]->SetPos(15, 20, -140 + movement);
	
	Const[9]->SetPos(40 + movement, 20, -30 );
	Const[10]->SetPos(50 + movement, 20, -30 );

	Const[11]->SetPos(120, 20, -60 + movement);
	Const[12]->SetPos(120, 20, -50 + movement);

	Const[13]->SetPos(85, 60 + movement, 120);
	Const[14]->SetPos(85, 50 + movement, 120);

	for (int i = 1; i < 15; i++)
		Const[i]->Render();

	for (int i = 0; i < obj.prim_obj.Count(); i++)
		obj.prim_obj[i]->Render();
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

}

void ModuleSceneIntro::CreateObject(const vec3 pos, const vec3 dim, Color bColor)
{
	// Create a cube to render a building
	Cube* Ground;
	Ground = new Cube(dim.x, dim.y, dim.z);
	Ground->color = bColor;
	Ground->SetPos(pos.x, pos.y + 1, pos.z);
	obj.prim_obj.PushBack(Ground);
	obj.phys_obj.PushBack(App->physics->AddBody(*Ground, this, 0.0f, false));
}
void ModuleSceneIntro::CreateRamp(const vec3 pos, const vec3 dim, float angle, const vec3 u, Color bColor)
{
	// Create a cube to render a building
	Cube* o;
	o = new Cube(dim.x, dim.y, dim.z);
	o->color = bColor;
	o->SetPos(pos.x, pos.y + 1, pos.z);
	o->SetRotation(angle, { u.x, u.y, u.z });
	obj.prim_obj.PushBack(o);
	obj.phys_obj.PushBack(App->physics->AddBody(*o,this,0.0f,false));
}

void ModuleSceneIntro::CreateConstrain(const vec3 pos, const vec3 dim, Color bColor) {
	Cube* Constrain;
	Constrain = new Cube(dim.x, dim.y, dim.z);
	Constrain->color = bColor;
	Constrain->SetPos(pos.x + movement, pos.y + 1, pos.z);
	obj.prim_obj.PushBack(Constrain);
	obj.phys_obj.PushBack(App->physics->AddBody(*Constrain, this, 0.0f, false));
}

void ModuleSceneIntro::MoveConstrain(Cube& constrain, const vec3 pos) {
	constrain.SetPos(pos.x + 10, pos.y,pos.z);
}
