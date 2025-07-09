#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <string>

namespace VulkanUtils {
    // 调试回调
    VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);
    
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
                                         const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, 
                                      const VkAllocationCallbacks* pAllocator);
    
    // 物理设备选择
    VkPhysicalDevice PickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);
    bool IsDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);
    bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
    
    // 队列族查找
    uint32_t FindQueueFamily(VkPhysicalDevice device, VkSurfaceKHR surface);
    
    // 交换链支持检查
    bool QuerySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR surface);
    
    // 工具函数
    std::vector<char> ReadFile(const std::string& filename);
    VkShaderModule CreateShaderModule(VkDevice device, const std::vector<char>& code);
} 