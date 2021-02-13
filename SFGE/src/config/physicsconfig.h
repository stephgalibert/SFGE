#pragma once

#include "iconfiguration.h"

namespace sfge::config
{
    class Physics : public IConfiguration
    {
    public:
        enum class Key : int32_t
        {
            PixelsPerMeter = 0
        };

    public:
        [[nodiscard]] static const auto &GetDefault();

    public:
        Physics();

        void setValue(const std::string &key, const std::string &value) override;
        void reset() override;

        [[nodiscard]] std::string getName() const override;
        const std::unordered_map<std::string, std::string> &getKeysValues() const override;

        [[nodiscard]] std::string getValue(Key key) const;
        void setValue(Key key, int value);
        void setValue(Key key, float value);
        void setValue(Key key, const std::string &value);

    public:
        template<typename T>
        typename std::enable_if_t<std::is_same_v<int, T>, T>
        getValue(Key key) const
        {
            return std::stoi(m_values.at(KeyToString(key)));
        }

        template<typename T>
        typename std::enable_if_t<std::is_same_v<float, T>, T>
        getValue(Key key) const
        {
            return std::stof(m_values.at(KeyToString(key)));
        }

    private:
        [[nodiscard]] static std::string KeyToString(Key key);

    private:
        std::unordered_map<std::string, std::string> m_values;
    };
}// namespace sfge::config