#pragma once

#include "iconfiguration.h"

namespace ecge::config
{
    class RendererConfiguration : public IConfiguration
    {
    public:
        [[nodiscard]] static std::unordered_map<std::string, std::string> GetDefault();

    public:
        RendererConfiguration();

        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::vector<std::string> getKeys() const override;
        [[nodiscard]] std::string getValue(const std::string &key) const override;
        void set(const std::string &key, const std::string &value) override;
        void reset() override;

    private:
        std::unordered_map<std::string, std::string> m_values;
    };
}// namespace ecge::config
