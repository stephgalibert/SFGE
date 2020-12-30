#pragma once

#include "pimpl.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <cstdint>

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

    protected:
//        virtual void onWindowClosing();
//	    virtual void onKeyboardEvent(sf::Keyboard::Key key, bool pressed);
//	    virtual void onMouseButtonEvent(sf::Mouse::Button button, int x, int y, bool pressed);
	    // ...

    private:
        explicit BaseApplication(BaseApplicationPrivate *dd);
        PIMPL_DECLARE_PRIVATE(BaseApplication);

    private:
        [[nodiscard]] bool isRunnable() const;
    };
}