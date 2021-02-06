#pragma once

#include "iconfiguration.h"

namespace ecge::config
{
    class RendererConfiguration : public IConfiguration
    {
    public:
        enum class Key : int32_t
        {
            Width = 0,
            Height,
            AntiAliasing
        };

    public:
        [[nodiscard]] static std::string KeyToString(Key key);
        [[nodiscard]] static std::unordered_map<std::string, std::string> GetDefault();

    public:
        RendererConfiguration();

        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::vector<std::string> getKeys() const override;
        [[nodiscard]] std::string getValue(const std::string &key) const override;
        void set(const std::string &key, const std::string &value) override;
        void reset() override;

        [[nodiscard]] std::string getValue(Key key) const;

    private:
        std::unordered_map<std::string, std::string> m_values;
    };
}// namespace ecge::config
