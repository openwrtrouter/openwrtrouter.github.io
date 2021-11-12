#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "miniupnpc::miniupnpc" for configuration "Release"
set_property(TARGET miniupnpc::miniupnpc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(miniupnpc::miniupnpc PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libminiupnpc.so.2.2.2"
  IMPORTED_SONAME_RELEASE "libminiupnpc.so.17"
  )

list(APPEND _IMPORT_CHECK_TARGETS miniupnpc::miniupnpc )
list(APPEND _IMPORT_CHECK_FILES_FOR_miniupnpc::miniupnpc "${_IMPORT_PREFIX}/lib/libminiupnpc.so.2.2.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
