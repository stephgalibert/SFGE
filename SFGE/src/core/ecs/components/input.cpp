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

#include "sfge/components/input.hpp"

namespace sfge::ecs
{
    void Input::setMouseMove(bool value)
    {
        m_mouseMove = value;
    }

    void Input::setMouseButton(bool value)
    {
        m_mouseButton = value;
    }

    void Input::setKeyboardButton(bool value)
    {
        m_keyboardButton = value;
    }

    bool Input::getMouseMove() const
    {
        return m_mouseMove;
    }

    bool Input::getMouseButton() const
    {
        return m_mouseButton;
    }

    bool Input::getKeyboardButton() const
    {
        return m_keyboardButton;
    }
}// namespace sfge::ecs