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

namespace sfge::services
{
    template<typename InterfaceT, typename ServiceT>
    typename std::enable_if_t<std::is_base_of_v<InterfaceT, ServiceT>, std::shared_ptr<InterfaceT>>
    ServiceLocator::Provide()
    {
        auto &services = getServices();
        const std::size_t id = typeid(InterfaceT).hash_code();
        assert(services.find(id) == services.end());
        std::shared_ptr<InterfaceT> instance = std::make_shared<ServiceT>();
        services.template insert(std::make_pair(id, instance));
        return instance;
    }

    template<typename ServiceT>
    std::shared_ptr<ServiceT> ServiceLocator::Get()
    {
        auto &services = getServices();
        const std::size_t id = typeid(ServiceT).hash_code();
        const auto found = services.find(id);
        assert(found != services.end());
        return std::static_pointer_cast<ServiceT>(found->second);
    }
}// namespace sfge::services