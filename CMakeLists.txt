cmake_minimum_required(VERSION 3.20)
project(grid-tactics LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

# --------------
# Gremlin Engine
# --------------

add_library(gremlin STATIC
	src/gremlin/core/Application.cpp
	src/gremlin/core/ProcessManager.cpp
	src/gremlin/render/Renderer.cpp
	src/gremlin/platform/Window.cpp
	src/gremlin/platform/Input.cpp
)

target_include_directories(gremlin
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(gremlin
	PUBLIC SDL3::SDL3
)

# -------------------
# Grid Tactics (game)
# -------------------

add_executable(grid_tactics
	src/game/main.cpp
	src/game/Game.cpp
)

target_link_libraries(grid_tactics
	PRIVATE gremlin
)

set_target_properties(grid_tactics PROPERTIES OUTPUT_NAME "grid-tactics")