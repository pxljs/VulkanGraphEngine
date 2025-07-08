#include "VulkanContext.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Swapchain.hpp"
#include "Command.hpp"

static std::vector<char> ReadFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);
    if (!file.is_open()) throw std::runtime_error("failed to open file!");
    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();
    return buffer;
}

bool VulkanContext::Initialize() {
    if (!InitInstance()) return false;
    if (!PickPhysicalDevice()) return false;
    if (!CreateLogicalDevice()) return false;
    if (!CreateSurface()) return false;
    if (!CreateRenderPass()) return false;
    if (!CreateGraphicsPipeline()) return false;
    if (!CreateSyncObjects()) return false;

    m_swapchain = new Swapchain(this);
    m_command = new Command(this);
    if (!m_swapchain->Initialize() || !m_command->Initialize()) return false;

    std::cout << "VulkanContext initialized successfully." << std::endl;
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
