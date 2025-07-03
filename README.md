# VulkanGraphEngine

A modular real-time rendering core engine built with Vulkan API and a RenderGraph architecture.  
This project simulates a lightweight graphics engine core suitable for engine development roles.

## ✨ Features
- Vulkan-based rendering context
- FrameGraph-based Pass scheduling
- Hot-reload shader pipeline (planned)
- Compute Shader support (planned)

## 🧱 Structure
- `core/`: Vulkan initialization & frame control
- `graph/`: RenderPass and RenderGraph system
- `passes/`: Custom rendering passes

## 🔧 Requirements
- CMake 3.20+
- Vulkan SDK 1.3+
- GLFW or SDL2
