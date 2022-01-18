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
	CreateObject({-70,20,0},{15,2,15}, Red);
	CreateObject({-70,20,48.5f},{15,2,80}, White);
	CreateObject({-38.5f,20,81},{50,2,15}, White);
	CreateObject({-6,20,79},{15,2,1.5}, White);
	CreateObject({-6,20,83},{15,2,1.5}, White);
	CreateObject({15.5f,20,81},{30,2,15}, White);
	CreateObject({15.5f,20,81},{30,2,15}, White);

	CreateRamp({ 45.5f,25,81 }, { 30,2,15 }, 20, { 0, 0, 1 }, White);
	CreateRamp({ 155.5f,25,81 }, { 30,2,15 }, -20, { 0, 0, 1 }, White);
	CreateRamp({ 180.5f,18,81 }, { 30,2,15 }, -10, { 0, 0, 1 }, White);

	CreateObject({ 210.5f,15.5,81 }, { 30,2,15 }, White);
	CreateObject({ 220,15.5,48.5f }, { 7,2,80 }, White);
	CreateObject({ 215,15.5,10.5f }, { 7,2,80 }, White);
	CreateObject({ 220,15.5,-50.5f }, { 7,2,80 }, White);

	for (int i = 0; i < 40; i++) {
		CreateRamp({ 220,0.5,-110.5 }, { 10,2,15 }, i*5, { 1, 0, 0 }, White);
	}
	for (int i = 0; i < 40; i++) {
		CreateRamp({ 220,-10.5,-130.5 }, { 10,2,15 }, i*5, { 1, 0, 0 }, White);
	}
	for (int i = 0; i < 40; i++) {
		CreateRamp({ 190,-21.5,-145.5 }, { 100,2,15 }, i*5, { 1, 0, 0 }, White);
	}

	CreateObject({ 90,-15,-145.5 }, { 100,2,30 }, White);
	CreateObject({ 40,-15,-95.5 }, { 30,2,100 }, White);
	CreateObject({ 90,-15,-55.5 }, { 100,2,30 }, White);
	CreateObject({ 120,-15,-10.5 }, { 20,2,60 }, White);

	CreateObject({ 90,-13,-145.5 }, { 3,3,3 }, Red);
	CreateObject({ 120,-13,-135.5 }, { 3,3,3 }, Red);
	CreateObject({ 135,-13,-155.5 }, { 3,3,3 }, Red);
	CreateObject({ 55,-13,-155.5 }, { 3,3,3 }, Red);
	
	Sphere s(4);
	s.SetPos(45, 0, -105.5);
	App->physics->AddBody(s);
	
	Sphere s2(4);
	s2.SetPos(40, 0, -85.5);
	App->physics->AddBody(s2);
	
	Sphere s3(4);
	s3.SetPos(30, 0, -50.5);
	App->physics->AddBody(s3);
	
	CreateRamp({90, -15, -55.5}, { 3,10,8 }, -60, { 1, 0, 1 }, Red);
	CreateRamp({60, -16, -45.5}, { 3,10,8 }, -60, { 1, 1, 1 }, Red);
	
	CreateRamp({ 120,-10,30.5 }, { 20,2,30 }, -20, { 1, 0, 0 }, Green);
	CreateRamp({ 117,0,45.5 }, { 20,2,30 }, -40, { 1, 0, 0 }, Green);
	CreateRamp({ 114,20,62.5 }, { 20,2,30 }, -60, { 1, 0, 0 }, Green);
	CreateRamp({ 111,32,70 }, { 20,2,30 }, -90, { 1, 0, 0 }, Green);
	CreateRamp({ 108,57,65.5 }, { 20,2,30 }, -110, { 1, 0, 0 }, Green);
	CreateRamp({ 105,63,60.5 }, { 20,2,30 }, -130, { 1, 0, 0 }, Green);
	CreateRamp({ 102,70,55.5 }, { 20,2,30 }, -150, { 1, 0, 0 }, Green);
	CreateRamp({ 99,78,35.5 }, { 20,2,30 }, -180, { 1, 0, 0 }, Green);	
	CreateRamp({ 96,70,15.5 }, { 20,2,30 }, 150, { 1, 0, 0 }, Green);
	CreateRamp({ 93,63,10.5 }, { 20,2,30 }, 130, { 1, 0, 0 }, Green);
	CreateRamp({ 90,57,5.5 }, { 20,2,30 }, 110, { 1, 0, 0 }, Green);
	CreateRamp({ 90,32,0 }, { 20,2,30 }, 90, { 1, 0, 0 }, Green);
	CreateRamp({ 90,20,1.5 }, { 20,2,30 }, 60, { 1, 0, 0 }, Green);
	CreateRamp({ 90,0,17.5 }, { 20,2,30 }, 40, { 1, 0, 0 }, Green);
	CreateRamp({ 90,-9,27.5 }, { 20,2,30 }, 10, { 1, 0, 0 }, Green);
	CreateObject({ 90,-11,45 }, {20,2,30},Blue);
	CreateRamp({ 90,-9,65 }, { 20,2,30 }, -20, { 1,0,0 }, Blue);

	Cylinder c(10, 8);
	c.SetPos(90, 10, 135);
	c.SetRotation(90, {0,1,0});
	App->physics->AddBody(c,0);

	//Left Wall
	CreateObject({300,0,0}, {2,600,600 }, BrightBlue);
	//Top Wall
	CreateObject({100,200,0}, { 600,2,600 }, BrightBlue);
	//BotWall
	CreateObject({ 100,-200,0 }, { 600,2,600 }, BrightBlue);
	//RightWall
	CreateObject({-100,0,0}, {2,600,600 }, BrightBlue);
	//FrontWall
	CreateObject({100,0,200 }, { 600,600,2}, BrightBlue);
	//BackWall
	CreateObject({100,0,-200}, { 600,600,2}, BrightBlue);
	
	CreateSensor({ 0,0,0 }, { 100,0,100 });

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

void ModuleSceneIntro::CreateSensor(const vec3 pos, const vec3 dim)
{
	// Create a cube to render a building
	Cube* Sensor;
	Sensor = new Cube(100, 0, 100);
	Sensor->SetPos(pos.x, pos.y + 1, pos.z);
	DeadSensor = App->physics->AddBody(*Sensor, this, 0.0f, true);
}
