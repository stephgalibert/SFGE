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

#pragma once

#include <sfge/components/base/ascript.hpp>
#include <sfge/event.hpp>
#include <sfge/logger/logger.hpp>

class TestScript : public sfge::ecs::AScript
{
public:
    TestScript();
    virtual ~TestScript();

    void onCollisionEnter(sfge::AGameObject *collided) override;
    void onCollisionExit(sfge::AGameObject *collided) override;

    void onKeyboardEvent(const sfge::input::KeyboardEvent &event) override;

    void onAwake() override;
    void onUpdate(float dt) override;
    void onDestroy() override;

private:
    std::shared_ptr<sfge::ILogger> m_logger;
};
