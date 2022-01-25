add_library(OptionalFunctions Optional.cpp)

# anybody who links to this lib shall needs to include the current source directory
target_include_directories(OptionalFunctions 
                    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
                            )

install(TARGETS OptionalFunctions DESTINATION lib)
install(FILES OptionalHeaders.h DESTINATION include)