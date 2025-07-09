#pragma once
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

// VMA内存分配器
#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

// 前向声明
class Renderer;
class Swapchain;

class VulkanContext {
public:
    VulkanContext();
    ~VulkanContext();
    
    bool Initialize();
    void Cleanup();
    bool ShouldClose();
    void DrawFrame();
    
    // 窗口大小变化处理
    void OnWindowResize();
    
    // Getter接口
    VkInstance GetInstance() const { return instance; }
    VkPhysicalDevice GetPhysicalDevice() const { return physicalDevice; }
    VkDevice GetDevice() const { return device; }
    VkQueue GetGraphicsQueue() const { return graphicsQueue; }
    VkSurfaceKHR GetSurface() const { return surface; }
    uint32_t GetGraphicsQueueFamily() const { return graphicsQueueFamily; }
    VkExtent2D GetSwapchainExtent() const;
    VkFramebuffer GetCurrentFramebuffer() const;
    VkRenderPass GetRenderPass() const;
    
    // VMA分配器
    VmaAllocator GetAllocator() const { return allocator; }
    
    // 同步对象
    VkSemaphore GetImageAvailableSemaphore() const { return imageAvailableSemaphores[currentFrame]; }
    VkSemaphore GetRenderFinishedSemaphore() const { return renderFinishedSemaphores[currentFrame]; }
    VkFence GetInFlightFence() const { return inFlightFences[currentFrame]; }
    size_t GetCurrentFrame() const { return currentFrame; }
    void AdvanceFrame() { currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT; }

private:
    // Vulkan核心对象
    VkInstance instance = VK_NULL_HANDLE;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;
    VkQueue graphicsQueue = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    uint32_t graphicsQueueFamily = 0;
    
    // VMA内存分配器
    VmaAllocator allocator = VK_NULL_HANDLE;
    
    // 调试消息
    VkDebugUtilsMessengerEXT debugMessenger = VK_NULL_HANDLE;
    
    // 同步对象
    static const int MAX_FRAMES_IN_FLIGHT = 2;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    size_t currentFrame = 0;
    
    // 模块
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Swapchain> swapchain;
    
    // GLFW窗口
    GLFWwindow* window = nullptr;
    
    // 初始化各阶段
    bool InitInstance();
    bool SetupDebugMessenger();
    bool CreateSurface();
    bool PickPhysicalDevice();
    bool CreateLogicalDevice();
    bool CreateSyncObjects();
    bool InitVMA();
    
    // 清理
    void CleanupSwapchain();
    void RecreateSwapchain();
}; 