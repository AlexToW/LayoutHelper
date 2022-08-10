# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\LayoutHelper_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LayoutHelper_autogen.dir\\ParseCache.txt"
  "LayoutHelper_autogen"
  )
endif()
