#pragma once
#include <vulkan/vulkan.h>
#include <vector>

class VulkanContext;

class CommandManager {
public:
    CommandManager(VulkanContext* context);
    ~CommandManager();
    
    bool Initialize();
    void Cleanup();
    
    // 命令缓冲区管理
    VkCommandBuffer BeginSingleTimeCommands();
    void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
    
    // 帧命令缓冲区
    VkCommandBuffer GetCurrentCommandBuffer();
    void BeginFrame();
    void EndFrame();
    
    // 获取命令池
    VkCommandPool GetCommandPool() const { return commandPool; }
    
private:
    VulkanContext* context;
    VkCommandPool commandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> commandBuffers;
    size_t currentFrame = 0;
    
    bool CreateCommandPool();
    bool CreateCommandBuffers();
}; 