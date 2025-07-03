#pragma once

#include "Swapchain.hpp"
#include "Command.hpp"

class VulkanContext {
public:
    bool Initialize();
    void DrawFrame();
    void Cleanup();
    bool ShouldClose();

private:
    Swapchain* m_swapchain = nullptr;
    Command* m_command = nullptr;
};
