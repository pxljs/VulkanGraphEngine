#pragma once

#include "Swapchain.hpp"
#include "Command.hpp"
#include "vulkan/vulkan.h"
#include <vector>

class VulkanContext {
public:
    bool Initialize();
    void DrawFrame();
    void Cleanup();
    bool ShouldClose();

private:
    // Vulkan核心对象
    VkInstance instance = VK_NULL_HANDLE;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;
    VkQueue graphicsQueue = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    VkRenderPass renderPass = VK_NULL_HANDLE;
    VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;
    VkPipeline graphicsPipeline = VK_NULL_HANDLE;

    // 着色器模块
    VkShaderModule vertShaderModule = VK_NULL_HANDLE;
    VkShaderModule fragShaderModule = VK_NULL_HANDLE;

    // 同步对象
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    size_t currentFrame = 0;

    // 交换链和命令相关
    Swapchain* m_swapchain = nullptr;
    Command* m_command = nullptr;

    // 初始化各阶段
    bool InitInstance();
    bool PickPhysicalDevice();
    bool CreateLogicalDevice();
    bool CreateSurface();
    bool CreateRenderPass();
    bool CreateGraphicsPipeline();
    bool CreateSyncObjects();
    void CleanupSwapchain();
    void RecreateSwapchain();
};