#include "VulkanContext.hpp"
#include <iostream>

bool VulkanContext::Initialize() {
    std::cout << "Vulkan initialized (stub)." << std::endl;
    return true;
}

void VulkanContext::DrawFrame() {
    std::cout << "Drawing frame (stub)." << std::endl;
}

void VulkanContext::Cleanup() {
    std::cout << "Cleanup (stub)." << std::endl;
}

bool VulkanContext::ShouldClose() {
    static int frameCount = 0;
    return ++frameCount > 300; // Simulate window closing after 300 frames
}
