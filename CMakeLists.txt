cmake_minimum_required(VERSION 3.20)
project(VulkanGraphEngine)

set(CMAKE_CXX_STANDARD 17)

# 查找依赖包
find_package(Vulkan REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# 添加VMA头文件路径（假设VMA在third_party目录）
include_directories(third_party/vma)

# 添加源文件
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.hpp
)

# 排除core目录下的旧文件
list(FILTER SRC_FILES EXCLUDE REGEX "src/core/.*")

add_executable(VulkanGraphEngine ${SRC_FILES})

# 包含目录
target_include_directories(VulkanGraphEngine PRIVATE 
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    src
)

# 链接库
target_link_libraries(VulkanGraphEngine PRIVATE 
    ${Vulkan_LIBRARIES}
    ${GLFW_LIBRARIES}
)

# 编译选项
target_compile_options(VulkanGraphEngine PRIVATE ${GLFW_CFLAGS_OTHER})

# 着色器编译（可选）
find_program(GLSLC glslc)
if(GLSLC)
    add_custom_target(shaders
        COMMAND ${GLSLC} -o shaders/triangle.vert.spv shaders/triangle.vert
        COMMAND ${GLSLC} -o shaders/triangle.frag.spv shaders/triangle.frag
        DEPENDS shaders/triangle.vert shaders/triangle.frag
        COMMENT "Compiling shaders"
    )
    add_dependencies(VulkanGraphEngine shaders)
endif()
