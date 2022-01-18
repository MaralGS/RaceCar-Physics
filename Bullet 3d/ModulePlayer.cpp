#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 2, 4);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width + 1.4f * wheel_width, connection_height + 0.5f, half_length - wheel_radius + 1.5);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width - 1.4f * wheel_width, connection_height + 0.5f, half_length - wheel_radius + 1.5);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width + 1.5f * wheel_width, connection_height + 0.4f, -half_length + wheel_radius - 1.3);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width - 1.5f * wheel_width, connection_height + 0.4, -half_length + wheel_radius - 1.3);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(-70, 42, 0);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = App->physics->totalForce = 0.0f;
	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
		zeroAux = false;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
		zeroAux = false;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT && spacer == false) {
   		App->physics->fimp += 250;
		if (App->physics->fimp >= 22500) {
			App->physics->fimp = 22500;
			spacer = true;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP || spacer == true) {
		App->physics->fimp -= 250;
		App->physics->fimpaux += 50;
		if (App->physics->fimp <= 0) {
			App->physics->fimp = 0;
		}
		spacer = true;
	}

	if (App->physics->fimpaux >= 22500) {
		App->physics->fimpaux = 0;
	}

	if (App->physics->fimpaux <= 0) {
		spacer = false;
	}

	brake += App->physics->Fdragx;

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		zeroAux = false;
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		zeroAux = false;
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT && App->player->vehicle->GetKmh() <= 0.01)
	{
		acceleration = MAX_ACCELERATION / -4;
		zeroAux = false;
	}

	if (acceleration == 0 && zeroAux == false) {
		zeroAux = false;
	}
	
	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT && App->player->vehicle->GetKmh() > 0)
	{
		brake = BRAKE_POWER;
		zeroAux = false;
	}

	App->physics->totalForce = acceleration + App->physics->fimp;
	
	if (App->input->GetKey(SDL_SCANCODE_0) == KEY_DOWN || zeroAux == true)
	{
		Reset();
	}

	if (App->input->GetKey(SDL_SCANCODE_0) == NULL && zeroAux == false)
	{
		vehicle->ApplyEngineForce(App->physics->totalForce);
		vehicle->Brake(brake);
	}

	vehicle->Turn(turn);
	vehicle->Render();

	float timer = SDL_GetTicks() / 1000;
	time = 180 - timer;
	char title[80];
	sprintf_s(title, "%.1f Km/h"  "\t %.2f s", vehicle->GetKmh(),time);
	App->window->SetTitle(title);

	if (dead == true)
	{
		Reset();
	}
	else
	{
		dead = false;
	}

	return UPDATE_CONTINUE;
}

void ModulePlayer::Reset() {
	App->physics->fimp = 0.0f;
	vehicle->SetPos(-70, 42, 0);
	vehicle->Brake(1000);
	zeroAux = true;
}