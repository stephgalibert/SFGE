#pragma once

#include "sfge/logger/logger.h"
#include "sfge/scene/ascene.hpp"

class TestScene : public sfge::AScene
{
public:
    TestScene();
    void init() override;

private:
    std::shared_ptr<sfge::ILogger> m_logger;
};