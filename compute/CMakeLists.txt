
add_library(tensor-example
        src/compute/compute.hpp
        src/compute/compute.cpp
        )

target_include_directories(tensor-example
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        )

target_link_libraries(tensor-example tensor)
