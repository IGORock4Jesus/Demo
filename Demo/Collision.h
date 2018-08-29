#pragma once

#include <list>
#include <d3dx9.h>
#include "Event.h"


namespace Collision {

	// Луч
	struct Ray
	{
		D3DXVECTOR3 point , // точка
			direction; // направление
	};

	class Base {
	public:
		virtual bool Test(const Ray* ray) { return false; }
		virtual bool Test(const Base* collision) { return false; }
	};

	class Manager {
		std::list<Base*> colliders;
	public:
		Event<Base*, Base*> CollisionHappened;

		void Update();
	};
}
