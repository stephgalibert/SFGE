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

#include "sfge/pimpl.hpp"
#include "sfge/services/itextureloaderservice.h"

#include <memory>

namespace sfge::resources
{
    class TextureLoaderPrivate;

    class TextureLoader : public services::ITextureLoaderService
    {
    public:
        TextureLoader();
        ~TextureLoader();

        bool load(const std::string &key, const std::string &path) override;
        void clear() override;

        [[nodiscard]] sf::Texture *getTexture(const std::string &key) const override;

    private:
        explicit TextureLoader(TextureLoaderPrivate *dd);
        PIMPL_DECLARE_PRIVATE(TextureLoader);
    };
}// namespace sfge::resources
