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

#define BIT_EVENT_KBD_IDX 1
#define BIT_EVENT_MOUSE_BTN_IDX 2
#define BIT_EVENT_MOUSE_MOV_IDX 4

namespace sfge::ecs
{
    void Input::setMouseMove(bool value)
    {
        if (value) {
            m_capacitive |= BIT_EVENT_MOUSE_MOV_IDX;
        } else {
            m_capacitive = ~(m_capacitive & BIT_EVENT_MOUSE_MOV_IDX);
        }
    }

    void Input::setMouseButton(bool value)
    {
        if (value) {
            m_capacitive |= BIT_EVENT_MOUSE_BTN_IDX;
        } else {
            m_capacitive = ~(m_capacitive & BIT_EVENT_MOUSE_BTN_IDX);
        }
    }

    void Input::setKeyboardButton(bool value)
    {
        if (value) {
            m_capacitive |= BIT_EVENT_KBD_IDX;
        } else {
            m_capacitive = ~(m_capacitive & BIT_EVENT_KBD_IDX);
        }
    }

    bool Input::getMouseMove() const
    {
        return m_capacitive & BIT_EVENT_MOUSE_MOV_IDX;
    }

    bool Input::getMouseButton() const
    {
        return m_capacitive & BIT_EVENT_MOUSE_BTN_IDX;
    }

    bool Input::getKeyboardButton() const
    {
        return m_capacitive & BIT_EVENT_KBD_IDX;
    }
}// namespace sfge::ecs