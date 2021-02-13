#pragma once

#include "sfge/ascene.hpp"
#include "sfge/logger/logger.h"

class TestScene : public sfge::AScene
{
public:
    TestScene();
    void init() override;

private:
    std::shared_ptr<sfge::ILogger> m_logger;
};