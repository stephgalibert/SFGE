#include "testscript.h"
#include <ecge/agameobject.hpp>

TestScript::TestScript()
{
}

TestScript::~TestScript()
{
    ecge::Logger::RemoveLogger(m_logger);
}

void TestScript::onAwake()
{
    m_logger = ecge::Logger::CreateLogger("TestScript" + std::to_string(m_gameObject->getId()));
    m_logger->addLoggingFile("logs/sample.txt");

    m_logger->info("onAwake");
}

void TestScript::onUpdate(float dt)
{
    m_logger->info("onUpdate");
}

void TestScript::onDestroy()
{
    m_logger->info("onDestroy");
}
