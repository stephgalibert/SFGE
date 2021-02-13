namespace sfge::config
{
    template<typename T>
    T IniConfig::get(const std::string &key)
    {
        return m_ptree.template get<T>(key);
    }

    template<typename T>
    void IniConfig::put(const std::string &key, const T &value)
    {
        m_ptree.put(key, value);
    }
}// namespace sfge::config