namespace sfge::services
{
    template<typename InterfaceT, typename ServiceT>
    typename std::enable_if_t<std::is_base_of_v<InterfaceT, ServiceT>>
    ServiceLocator::Provide()
    {
        auto &services = getServices();
        const std::size_t id = typeid(InterfaceT).hash_code();
        assert(services.find(id) == services.end());
        std::shared_ptr<void> instance = std::make_shared<ServiceT>();
        services.template insert(std::make_pair(id, instance));
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