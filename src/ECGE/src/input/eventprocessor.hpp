#pragma once

#include <SFML/Graphics.hpp>

#include <functional>
#include <unordered_map>

namespace ecge
{
	struct EventListener;

	class EventProcessor
	{
	public:
        explicit EventProcessor(EventListener *listener);
		~EventProcessor() = default;

		void process(const sf::Event &event);

	private:
        void onWindowClosing(const sf::Event &event);
		void onKeyboardEvent(const sf::Event &event);
		void onMouseButtonEvent(const sf::Event &event);
		void onMouseMoveEvent(const sf::Event &event);
		void onWindowResized(const sf::Event &event);
		void onFocusChanged(const sf::Event &event);

	private:
		std::unordered_map<sf::Event::EventType, std::function<void(const sf::Event&)>> m_events;
		EventListener *m_listener;
	};
}