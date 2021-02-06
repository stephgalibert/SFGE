#include "inifile.h"

#include <boost/property_tree/ini_parser.hpp>

#include <iostream>

namespace ecge::config
{
    bool IniFile::parse(const std::string &filename)
    {
        try {
            boost::property_tree::ini_parser::read_ini(filename, m_ptree);
        } catch (const boost::property_tree::ini_parser_error &exception) {
            // TODO: Logger when remove is fixed
            std::cerr << exception.what() << std::endl;
            return false;
        }
        return true;
    }

    bool IniFile::write(const std::string &filename) const
    {
        try {
            boost::property_tree::ini_parser::write_ini(filename, m_ptree);
        } catch (const boost::property_tree::ini_parser_error &exception) {
            // TODO: Logger when remove is fixed
            std::cerr << exception.what() << std::endl;
            return false;
        }
        return true;
    }
}// namespace ecge::config