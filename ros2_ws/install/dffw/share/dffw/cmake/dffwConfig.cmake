# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dffw_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dffw_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dffw_FOUND FALSE)
  elseif(NOT dffw_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dffw_FOUND FALSE)
  endif()
  return()
endif()
set(_dffw_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dffw_FIND_QUIETLY)
  message(STATUS "Found dffw: 0.0.0 (${dffw_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dffw' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dffw_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dffw_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dffw_DIR}/${_extra}")
endforeach()
