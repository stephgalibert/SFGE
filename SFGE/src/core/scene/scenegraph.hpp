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

#include <memory>
#include <vector>

namespace sfge
{
    class ILogger;
    class AGameObject;

    class SceneGraph
    {
    public:
        SceneGraph();
        ~SceneGraph();

        void insert(const std::shared_ptr<AGameObject> &obj);
        void clear();

    private:
        std::shared_ptr<ILogger> m_logger;
        std::vector<std::shared_ptr<AGameObject>> m_gameObjects;
    };
}// namespace sfge
