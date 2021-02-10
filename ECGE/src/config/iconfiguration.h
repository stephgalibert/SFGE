#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace ecge::config
{
    struct IConfiguration {
        virtual ~IConfiguration() = default;

        virtual void setValue(const std::string &key, const std::string &value) = 0;
        virtual void reset() = 0;

        [[nodiscard]] virtual std::string getName() const = 0;
        [[nodiscard]] virtual const std::unordered_map<std::string, std::string> &getKeysValues() const = 0;
    };
}// namespace ecge::config