[![Build Status](https://travis-ci.com/stephgalibert/sfge.svg?token=4xRtKLGfqqmAj18wsve3&branch=main)](https://travis-ci.com/stephgalibert/sfge)

# SFGE

Simple & Fast 2D Game Engine SDK - using SFML

## Dependencies

| Name   | Version | Type    | Link |
| :----: | :----: | :------: | :------------------------------------------------------: |
| SFML   | 2.5.1  | Renderer | https://github.com/SFML/SFML/tree/2.5.1                  |
| Box2D  | v2.4.1 | Physics  | https://github.com/erincatto/box2d/tree/v2.4.1           |
| Entt   | v3.6.0 | ECS      | https://github.com/skypjack/entt/tree/v3.6.0             |
| Spdlog | v1.8.2 | Logger   | https://github.com/gabime/spdlog/tree/v1.8.2             |
| Boost  | 1.71.0 | Utility  | https://www.boost.org/users/history/version_1_71_0.html  |
| GTests | 1.10.0 | Tests    | https://github.com/google/googletest/tree/release-1.10.0 | 
 
## Build

* `scripts/deps.sh`
* `scripts/build.sh`

## Tests

* Run CMake with `-DTests=ON`
* `make test`

## Run

* ./sample

## TODO before v1.0

| Feature | Note | Estimated Time |
| :-----: | ----- | :------------: |
| Tests   | Unit tests - Library to define | 5d
| Documentation | With Doxygen | 5d 
| Collisions | Use box2d API | 1d
| Resources | Textures, Audio (musics, sounds) | 1d
| Rendering | Textures, Shaders | 3d
| Handle different shapes | Circle, complex, ... | 3d
| GameObjects type | Lights, Camera | 3d
| GameObjects Management | GetByType (with templates), GetByName | 2d
| Engine Configuration | Error management | 2d
| GUI | Integrate GUI library (TGUI?) | 5d
| QoL | Improve APIs, Remove useless deps (boost-all i'm looking at you) | -

  
## Enhancement

| Feature                   | Note                 | Estimated Time |
| :-----------------------: | -------------------- | :------------: |
| Scene Graph               | Parenting            | -              |
| Support Joystick          | -                    | -              |
| Network Module            | Generic UDP Protocol | -              |
| Generic Renderer Library  | SFML, SDL, ...       | -              |
