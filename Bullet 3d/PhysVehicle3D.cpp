#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Blue;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	//creacio de cos
	Cube chassis(info.chassis_size.x - 0.5 , info.chassis_size.y, info.chassis_size.z - 3);
	Cube body(info.chassis_size.x + 1, info.chassis_size.y - 1, info.chassis_size.z + 2 );
	Cube bodyleght(info.chassis_size.x - 1, info.chassis_size.y - 1.5, info.chassis_size.z - 2 );
	Cube bodyfront(info.chassis_size.x + 1, info.chassis_size.y - 1.5, info.chassis_size.z - 3 );
	Cube aler1(info.chassis_size.x - 2, info.chassis_size.y - 1.5, info.chassis_size.z - 3.5);
	Cube aler2(info.chassis_size.x - 2, info.chassis_size.y - 2, info.chassis_size.z);
	//Cube aler3(info.chassis_size.x + 1.9, info.chassis_size.y - 1.5, info.chassis_size.z - 3 );

	//colors
	//body.color = Red;

	//position world(x,y,z)
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&body.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&bodyleght.transform);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&bodyfront.transform);

	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();

	// position (x,y,z) from car
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z - 1);
	btVector3 offset2(info.chassis_offset.x, info.chassis_offset.y - 0.5, info.chassis_offset.z);
	btVector3 offset3(info.chassis_offset.x, info.chassis_offset.y - 0.5, info.chassis_offset.z);
	btVector3 offset4(info.chassis_offset.x, info.chassis_offset.y - 0.7, info.chassis_offset.z);
	btVector3 offset5(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	offset2 = offset2.rotate(q.getAxis(), q.getAngle());
	offset3 = offset3.rotate(q.getAxis(), q.getAngle());
	offset4 = offset4.rotate(q.getAxis(), q.getAngle());
	offset5 = offset5.rotate(q.getAxis(), q.getAngle());

	//aluras dentro de el coche
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	body.transform.M[12] += offset2.getX();
	body.transform.M[13] += offset2.getY();
	body.transform.M[14] += offset2.getZ();
	bodyleght.transform.M[12] += offset3.getX();
	bodyleght.transform.M[13] += offset3.getY();
	bodyleght.transform.M[14] += offset3.getZ();
	bodyfront.transform.M[12] += offset4.getX();
	bodyfront.transform.M[13] += offset4.getY();
	bodyfront.transform.M[14] += offset4.getZ();
	aler1.transform.M[12] += offset5.getX();
	aler1.transform.M[13] += offset5.getY();
	aler1.transform.M[14] += offset5.getZ();


	chassis.Render();
	body.Render();
	bodyleght.Render();
	bodyfront.Render();
	aler1.Render();
	//aler2.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}