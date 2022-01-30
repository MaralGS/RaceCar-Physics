#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;
struct MapObj
{
	p2DynArray<PhysBody3D*>		phys_obj;
	p2DynArray<Cube*>			prim_obj;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void CreateObject(const vec3 pos, const vec3 dim, Color bColor);
	void CreateRamp(const vec3 pos, const vec3 dim,float angle, const vec3 u,Color bColor);
	void CreateSensor(const vec3 pos, const vec3 dim, int id);
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void CreateConstrain(const vec3 pos, const vec3 dim, Color bColor);
	void MoveConstrain(Cube& constrain, const vec3 pos);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* DeadSensor;
	bool left = true;
	float timer = 0.0f;
	float movement = 0.0f;
	Sphere Bola;
	Cube Ramp;
	Cube* Const[100];

	MapObj obj;
	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
};
