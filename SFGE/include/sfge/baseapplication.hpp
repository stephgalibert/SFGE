#pragma once

#include "pimpl.hpp"

#include <SFML/Graphics.hpp>

#include <cstdint>
#include <memory>

namespace sfge
{
    class BaseApplicationPrivate;
    class AScene;

    class BaseApplication
    {
    public:
        BaseApplication();
        virtual ~BaseApplication();

        virtual bool init();
        int32_t run();

        void loadScene(std::unique_ptr<AScene> scene);

    private:
        explicit BaseApplication(BaseApplicationPrivate *dd);
        PIMPL_DECLARE_PRIVATE(BaseApplication);

    private:
        [[nodiscard]] bool isRunnable() const;
    };
}// namespace sfge