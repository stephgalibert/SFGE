#pragma once

#include "sfge/logger/logger.hpp"
#include "sfge/scene/ascene.hpp"

class TestScene : public sfge::AScene
{
public:
    TestScene();
    void init() override;

private:
    std::shared_ptr<sfge::ILogger> m_logger;
};