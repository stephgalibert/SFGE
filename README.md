[![Build Status](https://travis-ci.com/stephgalibert/sfge.svg?token=4xRtKLGfqqmAj18wsve3&branch=main)](https://travis-ci.com/stephgalibert/sfge)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=stephgalibert_SFGE&metric=coverage)](https://sonarcloud.io/dashboard?id=stephgalibert_SFGE)
[![GitHub license](https://img.shields.io/github/license/stephgalibert/SFGE)](https://github.com/stephgalibert/SFGE/blob/main/LICENSE)

[![SonarCloud](https://sonarcloud.io/images/project_badges/sonarcloud-white.svg)](https://sonarcloud.io/dashboard?id=stephgalibert_SFGE)

---
# SFGE
Simple & Fast 2D Game Engine SDK.  
For those who don't want to use powerful engines that do too much for you.

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
* `Scripts/deps.sh`
* `Scripts/build.sh`

## Documentation
* Check the [Online doxygen documentation](https://stephgalibert.github.io/SFGE/)
* Run CMake with `-DDOCS=ON`
* `make docs`

## Tests
* Run CMake with `-DTESTS=ON`
* `make test`

## Run
* ./sample

## TODO before v1.0
* Last update: 06/03/2021

| Feature | Note | Estimated Time |
| :-----: | ----- | :------------: |
| Version | - | -
| Tests   | Unit tests with GTests | -
| Documentation | With Doxygen | -
| Rendering | Shaders | 3d
| Handle different shapes | Circle, complex, ... | 3d
| GameObjects type | Lights | 3d
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
