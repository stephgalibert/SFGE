cmake_minimum_required (VERSION 3.8)

set (TARGET "sample")

set (SRCS "main.cpp"
    "testscene.cpp"
    "testgameobject.cpp"
    "testscript.cpp")

add_executable (${TARGET} ${SRCS})

set_target_properties (${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")

target_link_libraries (${TARGET} PUBLIC "ecge")
