[![Build Status](https://travis-ci.com/stephgalibert/sfge.svg?token=4xRtKLGfqqmAj18wsve3&branch=main)](https://travis-ci.com/stephgalibert/sfge)

# SFGE

Simple & Fast 2D Game Engine SDK - using the SFML

## Dependencies

* [Box2D](https://github.com/erincatto/box2d/tree/v2.4.1)   
* [Entt](https://github.com/skypjack/entt/tree/v3.6.0)
* [SFML](https://github.com/SFML/SFML/tree/2.5.1)
* [Spdlog](https://github.com/gabime/spdlog/tree/v1.8.2)
* [Boost](https://www.boost.org/users/history/version_1_71_0.html)
  
## Build

* `scripts/deps.sh`
* `scripts/build.sh`

## Run

* ./sample

## TODO before v1.0

* Collisions
  * Use box2d API
* Rendering
  * Textures
  * Shaders
* GameObjects specializations
  * Lights
  * Cameras
* GameObjects management
  * GetByType
    * Using templates
  * GetByName
* Quality
  * refactor
  * improve APIs
  * Use boost logger
