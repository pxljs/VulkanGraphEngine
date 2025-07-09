#include "VulkanContext.hpp"
#include "Renderer.hpp"
#include "Swapchain.hpp"
#include "VulkanUtils.hpp"
#include <iostream>
#include <stdexcept>

static void FramebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto context = reinterpret_cast<VulkanContext*>(glfwGetWindowUserPointer(window));
    context->OnWindowResize();
}

int main() {
    try {
        VulkanContext context;
        
        if (!context.Initialize()) {
            std::cerr << "Failed to initialize Vulkan context!" << std::endl;
            return -1;
        }
        
        // 设置窗口大小变化回调
        glfwSetFramebufferSizeCallback(context.GetWindow(), FramebufferResizeCallback);
        glfwSetWindowUserPointer(context.GetWindow(), &context);
        
        std::cout << "Vulkan engine initialized successfully!" << std::endl;
        
        // 主渲染循环
        while (!context.ShouldClose()) {
            glfwPollEvents();
            context.DrawFrame();
        }
        
        context.Cleanup();
        std::cout << "Vulkan engine cleaned up successfully!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}
