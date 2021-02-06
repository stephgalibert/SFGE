namespace ecge::config
{
    template<typename T>
    T IniFile::get(const std::string &key)
    {
        return m_ptree.template get<T>(key);
    }

    template<typename T>
    void IniFile::put(const std::string &key, const T &value)
    {
        m_ptree.put(key, value);
    }
}// namespace ecge::config