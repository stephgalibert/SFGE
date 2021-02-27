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

#include "mock/script.hpp"

#include <cassert>

ScriptMock::ScriptMock(ObjectRegister *objRegister)
    : m_objRegister(objRegister)
{
    if (m_objRegister) {
        m_objRegister->increment();
    }
}
ScriptMock::~ScriptMock()
{
    if (m_objRegister) {
        m_objRegister->decrement();
    }
}

void ScriptMock::setStateManager(ScriptableStates *states)
{
    assert(states);
    m_states = states;
}

void ScriptMock::onAwake()
{
    if (m_states) {
        m_states->insert(ScriptableState::Awake);
    }
}

void ScriptMock::onUpdate(float dt)
{
    if (m_states) {
        m_states->insert(ScriptableState::Update);
    }
}

void ScriptMock::onDestroy()
{
    if (m_states) {
        m_states->insert(ScriptableState::Destroy);
    }
}


ScriptMockAlpha::ScriptMockAlpha(ObjectRegister *objRegister)
    : ScriptMock(objRegister)
{
}

int ScriptMockAlpha::getType() const
{
    return 0;
}


ScriptMockBeta::ScriptMockBeta(ObjectRegister *objRegister)
    : ScriptMock(objRegister)
{
}

int ScriptMockBeta::getType() const
{
    return 1;
}