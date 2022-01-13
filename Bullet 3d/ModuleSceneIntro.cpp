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
	CreateObject({0,0,10},{20,20,20}, Red);
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
	Cube* o;
	o = new Cube(dim.x, dim.y, dim.z);
	o->color = bColor;
	o->SetPos(pos.x, pos.y + 1, pos.z);
	obj.prim_obj.PushBack(o);
	obj.phys_obj.PushBack(App->physics->AddBody(*o,0.0f));
}
