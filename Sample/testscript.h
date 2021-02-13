#pragma once

#include <sfge/components/ascript.h>
#include <sfge/event.h>
#include <sfge/logger/logger.h>

class TestScript : public sfge::ecs::AScript
{
public:
    TestScript();
    virtual ~TestScript();

    void onKeyboardEvent(const sfge::input::KeyboardEvent &event) override;

    void onAwake() override;
    void onUpdate(float dt) override;
    void onDestroy() override;

private:
    std::shared_ptr<sfge::ILogger> m_logger;
};
