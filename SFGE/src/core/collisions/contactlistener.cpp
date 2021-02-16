//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#include "contactlistener.hpp"
#include "sfge/components/scriptable.hpp"
#include "sfge/gameobject/agameobject.hpp"

#include <box2d/b2_contact.h>

#include <iostream>

namespace sfge
{
    void ContactListener::BeginContact(b2Contact *contact)
    {
        b2Fixture *a = contact->GetFixtureA();
        b2Fixture *b = contact->GetFixtureB();

        auto obj1 = reinterpret_cast<AGameObject *>(a->GetBody()->GetUserData().pointer);
        auto obj2 = reinterpret_cast<AGameObject *>(b->GetBody()->GetUserData().pointer);

        auto &scriptable1 = obj1->component<ecs::Scriptable>();
        scriptable1.onCollisionEnter(obj2);

        auto &scriptable2 = obj2->component<ecs::Scriptable>();
        scriptable2.onCollisionEnter(obj1);
    }
    void ContactListener::EndContact(b2Contact *contact)
    {
        b2Fixture *a = contact->GetFixtureA();
        b2Fixture *b = contact->GetFixtureB();

        auto obj1 = reinterpret_cast<AGameObject *>(a->GetBody()->GetUserData().pointer);
        auto obj2 = reinterpret_cast<AGameObject *>(b->GetBody()->GetUserData().pointer);

        auto &scriptable1 = obj1->component<ecs::Scriptable>();
        scriptable1.onCollisionExit(obj2);

        auto &scriptable2 = obj2->component<ecs::Scriptable>();
        scriptable2.onCollisionExit(obj1);
    }
    void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
    {
        // TBD
    }
    void ContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
    {
        // TBD
    }
}// namespace sfge