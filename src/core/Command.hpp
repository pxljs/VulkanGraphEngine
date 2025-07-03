#pragma once

class VulkanContext;

class Command {
public:
    Command(VulkanContext* context);
    bool Initialize();
    void Cleanup();
    void BeginFrame();
    void EndFrame();
}; 