#pragma once

#include "ecge/pimpl.hpp"

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

namespace ecge
{
	class AScenePrivate;
	class AGameObject;

	class AScene
	{
	public:
		AScene();
		virtual ~AScene();

		virtual void init();

		void setRenderTarget(sf::RenderTarget* target);

		void stop();
        void onKeyboardEvent(sf::Keyboard::Key key, bool pressed);
        void onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed);

        void update(float dt);
		void draw();

    protected:
        template <typename T, typename ... Args>
        std::unique_ptr<AGameObject> &instantiate(Args&&... args) {
            return addGameObject( std::make_unique<T>(std::forward<Args>(args)...) );
        }

	    [[nodiscard]] entt::registry &registry();
	    [[nodiscard]] const entt::registry &registry() const;

    private:
        explicit AScene(AScenePrivate *dd);
        PIMPL_DECLARE_PRIVATE(AScene);
        std::unique_ptr<AGameObject> &addGameObject(std::unique_ptr<AGameObject> obj);
    };
}