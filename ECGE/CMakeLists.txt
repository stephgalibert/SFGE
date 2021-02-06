cmake_minimum_required (VERSION 3.8)

project ("ecge" VERSION 0.1.0 DESCRIPTION "Simple & Fast Game Engine Library")

# On windows, SFML_DIR needs to be set manually in the CMakeCache
find_package (SFML 2.5.1 COMPONENTS system graphics window audio REQUIRED)
find_package (box2d 2.4.1 REQUIRED)
find_package (spdlog 1.8.2 REQUIRED)

find_package (Boost 1.71 REQUIRED COMPONENTS system)

set (SRCS
	"src/baseapplication.cpp"
	"src/scene/scenemanager.cpp"
	"src/scene/ascene.cpp"
	"src/input/eventprocessor.cpp"
	"src/gameobject/agameobject.cpp"
	"src/scene/scenegraph.cpp"
	"src/ecs/systems/rendersystem.cpp"
	"src/ecs/components/component.cpp"
	"src/ecs/systems/physicssystem.cpp"
	"src/ecs/components/transformable.cpp"
	"src/ecs/components/renderable.cpp"
	"src/ecs/components/rigidbody.cpp"
	"src/logger/logger.cpp"
	"src/logger/spdloglogger.cpp"
	"src/ecs/componentsevents.cpp"
	"src/config/inifile.cpp"
	"src/config/configurationmanager.cpp"
	"src/config/rendererconfiguration.cpp")

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
