cmake_minimum_required(VERSION 3.20)
project(VulkanGraphEngine)

set(CMAKE_CXX_STANDARD 17)

# Vulkan SDK path (optional: use system path if not set)
find_package(Vulkan REQUIRED)

# Add source files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.hpp
)

add_executable(VulkanGraphEngine ${SRC_FILES})
target_include_directories(VulkanGraphEngine PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(VulkanGraphEngine PRIVATE ${Vulkan_LIBRARIES})
