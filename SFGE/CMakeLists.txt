cmake_minimum_required (VERSION 3.8)

project ("sfge" VERSION 0.1.0 DESCRIPTION "Simple & Fast Game Engine Library")

# On windows, SFML_DIR needs to be set manually in the CMakeCache
find_package (SFML 2.5.1 COMPONENTS system graphics window audio REQUIRED)
find_package (box2d 2.4.1 REQUIRED)
find_package (spdlog 1.8.2 REQUIRED)

find_package (Boost 1.71 REQUIRED COMPONENTS system)

set (SRCS "src/baseapplication.cpp"
		"src/logger/logger.cpp"
		"src/logger/spdloglogger.cpp"
		"src/config/iniconfig.cpp"
		"src/config/configurationmanager.cpp"
		"src/config/rendererconfig.cpp"
		"src/config/physicsconfig.cpp"
		"src/core/input/eventprocessor.cpp"
		"src/core/gameobject/agameobject.cpp"
		"src/core/scene/scenemanager.cpp"
		"src/core/scene/ascene.cpp"
		"src/core/scene/scenegraph.cpp"
		"src/core/ecs/componentsevents.cpp"
		"src/core/ecs/systems/rendersystem.cpp"
		"src/core/ecs/systems/scriptsystem.cpp"
		"src/core/ecs/systems/inputsystem.cpp"
		"src/core/ecs/systems/physicssystem.cpp"
		"src/core/ecs/components/component.cpp"
		"src/core/ecs/components/transformable.cpp"
		"src/core/ecs/components/renderable.cpp"
		"src/core/ecs/components/rigidbody.cpp"
		"src/core/ecs/components/scriptable.cpp"
		"src/core/ecs/components/ascript.cpp"
		"src/core/ecs/components/input.cpp")

add_library (${PROJECT_NAME} SHARED ${SRCS})

target_include_directories (${PROJECT_NAME} PRIVATE "src")
target_include_directories (${PROJECT_NAME} PUBLIC "include")

set_target_properties (${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set_target_properties (${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set_target_properties (${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set_target_properties (${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

if(MSVC)
	set_target_properties (${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR})

target_link_libraries (${PROJECT_NAME} PUBLIC
		sfml-system sfml-graphics sfml-window sfml-audio
		Boost::system
		box2d spdlog::spdlog)
