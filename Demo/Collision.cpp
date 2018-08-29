#include "Collision.h"


namespace Collision {
	void Manager::Update() {
		if (colliders.size() < 2) return;
		auto end = colliders.end();
		auto preend = end; --preend;
		for (auto i = colliders.begin(); i != preend; )
		{
			for (auto j = ++i; j != end; ++j) {
				if ((*i)->Test(*j))
					CollisionHappened.Process(*i, *j);
			}
		}
	}
}