#pragma once

#include "sfge/ascene.hpp"
#include "ecs/systems/rendersystem.hpp"
#include "ecs/systems/physicssystem.hpp"
#include "scenegraph.hpp"

#include <memory>

namespace sfge
{
	class AScenePrivate
	{
	public:
	private:
		explicit AScenePrivate(AScene *qq);
        PIMPL_DECLARE_PUBLIC(AScene);

		entt::registry m_registry;
		SceneGraph m_graph;
		RenderSystem m_renderSystem;
        PhysicsSystem m_physicsSystem;
	};
}