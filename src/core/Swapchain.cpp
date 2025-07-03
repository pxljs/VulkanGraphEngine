#include "Swapchain.hpp"
#include "VulkanContext.hpp"
#include <iostream>

Swapchain::Swapchain(VulkanContext* context) {
    // 记录context指针
}

bool Swapchain::Initialize() {
    std::cout << "Swapchain initialized (stub)." << std::endl;
    return true;
}

void Swapchain::Cleanup() {
    std::cout << "Swapchain cleanup (stub)." << std::endl;
}

void Swapchain::Present() {
    std::cout << "Swapchain present (stub)." << std::endl;
} 