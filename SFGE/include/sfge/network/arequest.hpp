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

namespace sfge::network
{
    class ARequest
    {
    public:
        ARequest() = default;
        virtual ~ARequest() = default;

        // to_bytearray() const;

    protected:
        // virtual get_body() const = 0;

    private:
        // request_id;
        // message_id;

        // message_type (non, con, ack, error)
    };
}// namespace sfge::network
