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

#include "physicsconfig.hpp"
#include <iostream>

#define PIXELS_PER_METER_KEY_NAME "PixelsPerMeter"

namespace sfge::config
{
    Physics::Physics()
    {
        reset();
    }

    std::string Physics::getName() const
    {
        return "Physics";
    }

    void Physics::setPixelsPerMeter(float value)
    {
        const bool ret = setValue(PIXELS_PER_METER_KEY_NAME, value);
        if (!ret) {
            std::cout << "failed to set pixels per meter, value=" << value << std::endl;
        }
    }

    float Physics::getPixelsPerMeter() const
    {
        return getValueFloat(PIXELS_PER_METER_KEY_NAME);
    }

    const std::set<KeyInfo> &Physics::getKeys() const
    {
        static const std::set<KeyInfo> keys = {
                {{PIXELS_PER_METER_KEY_NAME, Type::Float, "50.0"}}};
        return keys;
    }
}// namespace sfge::config
