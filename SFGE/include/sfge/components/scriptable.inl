namespace sfge::ecs
{
    template<typename T>
    decltype(auto) Scriptable::addScript()
    {
        m_scripts.push_back(std::make_unique<T>());
        return m_scripts.back();
    }

    template<typename T>
    void Scriptable::removeScript()
    {
        auto f = [&](const auto &script) {
            if (typeid(T) == typeid(*script)) {
                script->onDestroy();
                return true;
            }
            return false;
        };

        m_scripts.erase(std::remove_if(m_scripts.begin(), m_scripts.end(), f), m_scripts.end());
    }
}// namespace sfge::ecs