#include <iostream>

#include "CaveGeneration.hpp"

#include <SFML/Graphics.hpp>

/**
 * Sample
 */
Sample

        sf::VertexArray
        toVertices(const std::vector<std::vector<bool>> &map)
{
    const std::size_t totalSize = map.size() * map[0].size();
    const std::size_t size = 10;
    sf::VertexArray vertices(sf::Quads, 4 * totalSize);

    for (std::size_t j = 0; j < map.size(); ++j) {
        for (std::size_t i = 0; i < map[j].size(); ++i) {
            const std::size_t index = (j * map[j].size() + i) * 4;
            const sf::Color color = (map[j][i]) ? sf::Color::White : sf::Color::Black;

            vertices[index + 0].position.x = i * size;
            vertices[index + 0].position.y = j * size;
            vertices[index + 0].color = color;

            vertices[index + 1].position.x = i * size + size;
            vertices[index + 1].position.y = j * size;
            vertices[index + 1].color = color;

            vertices[index + 2].position.x = i * size + size;
            vertices[index + 2].position.y = j * size + size;
            vertices[index + 2].color = color;

            vertices[index + 3].position.x = i * size;
            vertices[index + 3].position.y = j * size + size;
            vertices[index + 3].color = color;
        }
    }
    return vertices;
}

//int main(void)
//{
//    Lehmer32 rnd(0);
//
//    CaveGeneration caveGeneration(78515, 300, 250);
//    caveGeneration.generate();
//    caveGeneration.dump();
//
//    const auto &data = caveGeneration.getGenerated();
//
//    sf::RenderWindow window;
//    window.create(sf::VideoMode(1280, 720), "SFML Works!");
//
//    //sf::Shape* shape = new sf::RectangleShape({50, 50});
//    //shape->setFillColor(sf::Color::Red);
//    sf::VertexArray vertices = toVertices(data);
//    sf::Clock clock;
//    float lastInput = 0;
//    float zoom = 1.f;
//
//    sf::View view;
//    view.setSize({1280, 720});
//    window.setView(view);
//
//    while (window.isOpen()) {
//        const float dt = clock.restart().asMilliseconds();
//
//        sf::Event events;
//        while (window.pollEvent(events)) {
//            if (events.type == sf::Event::Closed) {
//                window.close();
//            } else if (events.type == sf::Event::Resized) {
//                view.setSize(events.size.width, events.size.height);
//                window.setView(view);
//            }
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
//            const int seed = rnd.genInt(0, 0xffffffff);
//            std::clog << "New generation, seed=" << seed << std::endl;
//            caveGeneration.setSeed(seed);
//            caveGeneration.generate();
//            vertices = toVertices(caveGeneration.getGenerated());
//        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
//            if (lastInput > 100.f) {
//                lastInput = 0;
//                view.setCenter(view.getCenter().x - 10, view.getCenter().y);
//                window.setView(view);
//            }
//        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//            if (lastInput > 100.f) {
//                lastInput = 0;
//                view.setCenter(view.getCenter().x + 10, view.getCenter().y);
//                window.setView(view);
//            }
//        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
//            if (lastInput > 100.f) {
//                lastInput = 0;
//                view.setCenter(view.getCenter().x, view.getCenter().y - 10);
//                window.setView(view);
//            }
//        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//            if (lastInput > 100.f) {
//                lastInput = 0;
//                view.setCenter(view.getCenter().x, view.getCenter().y + 10);
//                window.setView(view);
//            }
//        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
//            if (lastInput > 100.f) {
//                lastInput = 0;
//                if (zoom < 1.f) zoom = 1.1f;
//                else
//                    zoom += 0.1f;
//                view.zoom(zoom);
//                window.setView(view);
//            }
//        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
//            if (lastInput > 100) {
//                lastInput = 0;
//                if (zoom > 1.f) zoom = 0.9f;
//                else
//                    zoom -= 0.1f;
//                view.zoom(zoom);
//                window.setView(view);
//            }
//        }
//
//        lastInput += dt;
//
//        window.clear();
//        window.draw(vertices);
//        //window.draw(*shape);
//        window.display();
//    }
//    return 0;
//}