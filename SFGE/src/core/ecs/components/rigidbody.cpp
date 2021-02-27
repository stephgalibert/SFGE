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

#include "sfge/components/rigidbody.hpp"

namespace sfge::ecs
{
    RigidBody::Config::Config()
    {
        bodyDef.type = b2_dynamicBody;
    }

    void RigidBody::setBody(b2Body *body)
    {
        m_body = body;
    }

    void RigidBody::setConfig(const Config &config)
    {
        m_config = config;
        getRegistry()->patch<RigidBody>(getEntity());
    }

    b2Body *RigidBody::body() const
    {
        return m_body;
    }

    RigidBody::Config RigidBody::config() const
    {
        return m_config;
    }
}// namespace sfge::ecs