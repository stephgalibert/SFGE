#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace ecge::config
{
    struct IConfiguration {
        virtual ~IConfiguration() = default;

        [[nodiscard]] virtual std::string getName() const = 0;
        [[nodiscard]] virtual std::vector<std::string> getKeys() const = 0;
        [[nodiscard]] virtual std::string getValue(const std::string &key) const = 0;

        virtual void set(const std::string &key, const std::string &value) = 0;
        virtual void reset() = 0;
    };
}// namespace ecge::config