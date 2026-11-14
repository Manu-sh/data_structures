# data_structures
A collection of generics data structures (WIP)
this project is header only and replace the old [my_collections](https://github.com/Manu-sh/my_collections) which was more flexible because allow you to create a single object file for each "template" but also add unecessary pain to handle this edge case

here is how you can include into a cmake project:

```cmake
include(FetchContent)
FetchContent_Declare(
  data_structures
  GIT_REPOSITORY https://github.com/Manu-sh/data_structures.git
  SOURCE_SUBDIR  "no-cmake-here"
)

FetchContent_MakeAvailable(data_structures)
target_include_directories(${PROJECT_NAME} PRIVATE "${data_structures_SOURCE_DIR}/include")
```


###### Copyright © 2026, [Manu-sh](https://github.com/Manu-sh), s3gmentationfault@gmail.com. Released under the [MIT license](LICENSE).
