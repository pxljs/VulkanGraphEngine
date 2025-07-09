# Vulkan Graph Engine

一个基于Vulkan API的模块化实时渲染引擎，采用RenderGraph架构设计。
本项目实现了一个轻量级的图形引擎核心，适合引擎开发角色。

## ✨ 功能特性

- **Vulkan基础框架**：完整的Vulkan初始化流程和渲染循环
- **模块化设计**：Context、Command、Swapchain、Renderer分离
- **VMA内存管理**：集成Vulkan Memory Allocator简化内存管理
- **DebugMessenger**：调试信息输出和验证层支持
- **窗口Resize支持**：自动处理窗口大小变化和交换链重建
- **最小三角形渲染**：完整的渲染管线演示

## 🧱 项目结构

```
src/
├── VulkanContext.hpp/cpp      # Vulkan核心上下文管理
├── VulkanUtils.hpp/cpp        # 工具函数和调试回调
├── CommandManager.hpp/cpp     # 命令池和命令缓冲区管理
├── Swapchain.hpp/cpp          # 交换链和帧缓冲管理
├── Renderer.hpp/cpp           # 渲染器和管线管理
└── main.cpp                   # 主程序入口

shaders/
├── triangle.vert              # 顶点着色器
└── triangle.frag              # 片段着色器

third_party/
└── vma/                       # Vulkan Memory Allocator
```

## 🔧 依赖要求

- **CMake 3.20+**
- **Vulkan SDK 1.3+**
- **GLFW 3.3+**
- **C++17**

## 🚀 编译运行

```bash
# 创建构建目录
mkdir build && cd build

# 配置项目
cmake ..

# 编译
make

# 运行
./VulkanGraphEngine
```

## 📋 模块说明

### VulkanContext
- 管理Vulkan实例、物理设备、逻辑设备
- 集成VMA内存分配器
- 处理窗口创建和事件
- 管理同步对象（信号量、栅栏）

### CommandManager
- 命令池和命令缓冲区管理
- 支持单次命令和帧命令缓冲区
- 双缓冲设计

### Swapchain
- 交换链创建和管理
- 图像视图和帧缓冲
- 窗口Resize自动处理

### Renderer
- 渲染通道和图形管线
- 着色器加载和管理
- 渲染命令录制

### VulkanUtils
- 物理设备选择工具
- 调试回调函数
- 着色器加载工具

## 🎯 开发计划

- [x] 基础Vulkan框架
- [x] 模块化架构
- [x] 三角形渲染Demo
- [x] 窗口Resize支持
- [x] VMA内存管理
- [x] DebugMessenger
- [ ] RenderGraph系统
- [ ] 计算着色器支持
- [ ] 着色器热重载
- [ ] 多线程渲染

## 📝 注意事项

1. 确保Vulkan SDK正确安装并配置环境变量
2. GLFW库需要正确安装（Windows用户可能需要手动配置）
3. VMA库需要下载完整版本替换占位符
4. 着色器需要编译为SPIR-V格式（.spv文件）

## 🤝 贡献

欢迎提交Issue和Pull Request来改进这个项目！
