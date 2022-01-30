#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include <string>
using namespace std;

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 100.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	void Reset();
	void Reset1();
	bool CleanUp();
	void ResetRotation();

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	float time;
	float timeaux = 0.0f;
	bool spacer = false;
	bool dead = false;
	string turbo;


	bool zeroAux;
	bool zeroAux1;
};