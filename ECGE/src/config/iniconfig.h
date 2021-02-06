#pragma once

#include "ecge/logger/logger.h"

#include <boost/property_tree/ptree.hpp>

namespace ecge::config
{
    class IniConfig
    {
    public:
        IniConfig();
        ~IniConfig();

        [[nodiscard]] bool parse(const std::string &filename);
        [[nodiscard]] bool write(const std::string &filename) const;

    public:
        template<typename T>
        [[nodiscard]] T get(const std::string &key);

        template<typename T>
        void put(const std::string &key, const T &value);

    private:
        std::shared_ptr<ILogger> m_logger;
        boost::property_tree::ptree m_ptree;
    };
}// namespace ecge::config

#include "iniconfig.inl"
