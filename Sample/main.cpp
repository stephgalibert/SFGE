#include <SFML/Graphics.hpp>

#include "testscene.hpp"

#include "sfge/baseapplication.hpp"

int main()
{
    sfge::BaseApplication app;
    app.init();
    app.loadScene(std::make_unique<TestScene>());
    return app.run();
}