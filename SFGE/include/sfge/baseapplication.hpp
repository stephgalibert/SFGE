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

#include "pimpl.hpp"

#include <SFML/Graphics.hpp>

#include <cstdint>
#include <memory>

namespace sfge
{
    class BaseApplicationPrivate;
    class AScene;

    class BaseApplication
    {
    public:
        BaseApplication();
        virtual ~BaseApplication();

        virtual bool init();
        int32_t run();

        void loadScene(std::unique_ptr<AScene> scene);

    private:
        explicit BaseApplication(BaseApplicationPrivate *dd);
        PIMPL_DECLARE_PRIVATE(BaseApplication);

    private:
        [[nodiscard]] bool isRunnable() const;
        static void LoadServices();
    };
}// namespace sfge