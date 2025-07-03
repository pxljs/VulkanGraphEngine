#pragma once

class VulkanContext {
public:
    bool Initialize();
    void DrawFrame();
    void Cleanup();
    bool ShouldClose();
};
