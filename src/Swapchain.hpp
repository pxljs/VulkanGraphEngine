#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <memory>

class VulkanContext;

class Swapchain {
public:
    Swapchain(VulkanContext* context);
    ~Swapchain();
    
    bool Initialize();
    void Cleanup();
    
    // 交换链操作
    uint32_t AcquireNextImage(VkSemaphore semaphore, VkFence fence);
    bool PresentImage(uint32_t imageIndex, VkSemaphore waitSemaphore);
    
    // 获取交换链信息
    VkFormat GetImageFormat() const { return swapchainImageFormat; }
    VkExtent2D GetExtent() const { return swapchainExtent; }
    VkFramebuffer GetFramebuffer(uint32_t index) const;
    size_t GetImageCount() const { return swapchainImages.size(); }
    
    // 窗口大小变化处理
    void Recreate();
    
private:
    VulkanContext* context;
    
    VkSwapchainKHR swapchain = VK_NULL_HANDLE;
    std::vector<VkImage> swapchainImages;
    std::vector<VkImageView> swapchainImageViews;
    std::vector<VkFramebuffer> swapchainFramebuffers;
    VkFormat swapchainImageFormat;
    VkExtent2D swapchainExtent;
    
    bool CreateSwapchain();
    bool CreateImageViews();
    bool CreateFramebuffers();
    void CleanupSwapchain();
    
    // 交换链支持查询
    VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
}; 