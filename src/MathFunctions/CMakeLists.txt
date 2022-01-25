add_library(MathFunctions mysqrt.cpp)

# anybody who links to this lib shall needs to include the current source directory
target_include_directories(MathFunctions 
                    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
                            )


install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)