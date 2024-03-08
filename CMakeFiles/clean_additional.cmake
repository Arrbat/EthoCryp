# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/EthoCryp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/EthoCryp_autogen.dir/ParseCache.txt"
  "EthoCryp_autogen"
  )
endif()
