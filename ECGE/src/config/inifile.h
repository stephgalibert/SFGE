#pragma once

#include <boost/property_tree/ptree.hpp>

namespace ecge::config
{
    class IniFile
    {
    public:
        bool parse(const std::string &filename);
        bool write(const std::string &filename) const;

    public:
        template<typename T>
        T get(const std::string &key);

        template<typename T>
        void put(const std::string &key, const T &value);

    private:
        boost::property_tree::ptree m_ptree;
    };
}// namespace ecge::config

#include "inifile.inl"
