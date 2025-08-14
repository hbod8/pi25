add_library(bindings STATIC
  bindings.c
  bindings.h)

target_link_libraries(bindings
  lua
)

target_include_directories(bindings INTERFACE ${CMAKE_CURRENT_LIST_DIR})
