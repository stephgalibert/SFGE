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

#include "sfge/components/base/ascript.hpp"
#include "sfge/components/base/component.hpp"

#include <memory>
#include <vector>

namespace sfge::input
{
    struct KeyboardEvent;
    struct MouseButtonEvent;
}// namespace sfge::input

namespace sfge::ecs
{
    class Scriptable : public Component
    {
    public:
        void onCollisionEnter(AGameObject *collided);
        void onCollisionExit(AGameObject *collided);

        void update(float dt);
        void destroy();

        void onKeyboardEvent(const input::KeyboardEvent &event);
        void onMouseButtonEvent(const input::MouseButtonEvent &event);

        [[nodiscard]] std::size_t getSize() const;

    public:
        template<typename T, typename... Args>
        std::shared_ptr<T> addScript(Args &&...);

        template<typename T>
        std::shared_ptr<T> getScript() const;

        template<typename T>
        std::size_t removeScript();

    private:
        std::vector<std::shared_ptr<AScript>> m_scripts;
    };


    template<typename T, typename... Args>
    std::shared_ptr<T> Scriptable::addScript(Args &&... args)
    {
        auto script = std::make_shared<T>(std::forward<Args>(args)...);
        m_scripts.push_back(script);
        return script;
    }

    template<typename T>
    std::shared_ptr<T> Scriptable::getScript() const
    {
        const auto found = std::find_if(m_scripts.begin(), m_scripts.end(), [&](const auto &script) {
            return typeid(T) == typeid(*script);
        });
        if (found != m_scripts.end()) {
            return std::static_pointer_cast<T>(*found);
        }
        return nullptr;
    }

    template<typename T>
    std::size_t Scriptable::removeScript()
    {
        auto f = [&](const auto &script) {
            if (typeid(T) == typeid(*script)) {
                script->onDestroy();
                return true;
            }
            return false;
        };

        m_scripts.erase(std::remove_if(m_scripts.begin(), m_scripts.end(), f), m_scripts.end());
        return m_scripts.size();
    }
}// namespace sfge::ecs
