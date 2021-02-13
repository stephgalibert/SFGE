#pragma once

#include <ecge/components/ascript.h>
#include <ecge/event.h>
#include <ecge/logger/logger.h>

class TestScript : public ecge::ecs::AScript
{
public:
    TestScript();
    virtual ~TestScript();

    void onKeyboardEvent(const ecge::input::KeyboardEvent &event) override;

    void onAwake() override;
    void onUpdate(float dt) override;
    void onDestroy() override;

private:
    std::shared_ptr<ecge::ILogger> m_logger;
};
