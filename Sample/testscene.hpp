#pragma once

#include "ecge/ascene.hpp"
#include "ecge/logger/logger.h"

class TestScene : public ecge::AScene
{
public:
    TestScene();
    void init() override;

private:
    std::shared_ptr<ecge::ILogger> m_logger;
};