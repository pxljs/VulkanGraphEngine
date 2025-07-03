#include "VulkanContext.hpp"
#include <iostream>
#include "Swapchain.hpp"
#include "Command.hpp"

bool VulkanContext::Initialize() {
    std::cout << "Vulkan initialized (stub)." << std::endl;
    m_swapchain = new Swapchain(this);
    m_command = new Command(this);
    if (!m_swapchain->Initialize() || !m_command->Initialize()) {
        return false;
    }
    return true;
}

void VulkanContext::DrawFrame() {
    m_command->BeginFrame();
    // ...渲染命令录制...
    m_command->EndFrame();
    m_swapchain->Present();
}

void VulkanContext::Cleanup() {
    if (m_command) {
        m_command->Cleanup();
        delete m_command;
        m_command = nullptr;
    }
    if (m_swapchain) {
        m_swapchain->Cleanup();
        delete m_swapchain;
        m_swapchain = nullptr;
    }
    std::cout << "Cleanup (stub)." << std::endl;
}

bool VulkanContext::ShouldClose() {
    static int frameCount = 0;
    return ++frameCount > 300; // Simulate window closing after 300 frames
}
