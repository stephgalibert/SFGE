#include "iniconfig.h"

#include <boost/property_tree/ini_parser.hpp>

#include <iostream>

namespace ecge::config
{
    IniConfig::IniConfig()
    {
        m_logger = Logger::CreateLogger("IniConfig");
        m_logger->addLoggingFile("logs/log.txt");
    }

    IniConfig::~IniConfig()
    {
        Logger::RemoveLogger("IniConfig");
    }

    bool IniConfig::parse(const std::string &filename)
    {
        try {
            boost::property_tree::ini_parser::read_ini(filename, m_ptree);
        } catch (const boost::property_tree::ini_parser_error &exception) {
            m_logger->info(exception.what());
            return false;
        }
        return true;
    }

    bool IniConfig::write(const std::string &filename) const
    {
        try {
            boost::property_tree::ini_parser::write_ini(filename, m_ptree);
        } catch (const boost::property_tree::ini_parser_error &exception) {
            m_logger->info(exception.what());
            return false;
        }
        return true;
    }
}// namespace ecge::config