#include <SFML/Graphics.hpp>

#include "testscene.hpp"

#include "ecge/baseapplication.hpp"

int main()
{
    ecge::BaseApplication app;
    app.init();
    app.loadScene(std::make_unique<TestScene>());
    return app.run();
}