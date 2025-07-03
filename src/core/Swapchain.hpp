#pragma once

class VulkanContext;

class Swapchain {
public:
    Swapchain(VulkanContext* context);
    bool Initialize();
    void Cleanup();
    void Present();
}; 