add_library(assets INTERFACE
  font.h
  sample.h
)

target_include_directories(assets INTERFACE ${CMAKE_CURRENT_LIST_DIR})
