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

namespace sfge::config
{
    std::string Physics::GetPixelsPerMeterKeyName()
    {
        return "PixelsPerMeter";
    }

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
        const bool ret = setValue(GetPixelsPerMeterKeyName(), value);
        if (!ret) {
            std::cout << "failed to set pixels per meter, value=" << value << std::endl;
        }
    }

    float Physics::getPixelsPerMeter() const
    {
        return getValueFloat(GetPixelsPerMeterKeyName());
    }

    const std::set<KeyDefinition> &Physics::getKeyDefinitions() const
    {
        static const std::set<KeyDefinition> keys = {
                {{GetPixelsPerMeterKeyName(), Type::Float, 50.0f}}};
        return keys;
    }
}// namespace sfge::config
