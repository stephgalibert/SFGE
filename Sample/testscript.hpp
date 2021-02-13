#pragma once

#include <sfge/components/ascript.hpp>
#include <sfge/event.hpp>
#include <sfge/logger/logger.hpp>

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
