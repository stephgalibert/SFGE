#pragma once

#include "iconfiguration.h"

namespace ecge::config
{
    class PhysicsConfiguration : public IConfiguration
    {
    public:
        std::string getName() const override;
        std::vector<std::string> getKeys() const override;
        std::string getValue(const std::string &key) const override;
        void set(const std::string &key, const std::string &value) override;
        void reset() override;
    };
}// namespace ecge::config
