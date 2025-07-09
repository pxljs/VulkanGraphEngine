#pragma once
#include <vulkan/vulkan.h>
#include <memory>

class VulkanContext;
class CommandManager;

class Renderer {
public:
    Renderer(VulkanContext* context);
    ~Renderer();
    
    bool Initialize();
    void Cleanup();
    
    // 渲染循环
    void BeginFrame();
    void EndFrame();
    
    // 渲染命令
    void BeginRenderPass(VkCommandBuffer commandBuffer);
    void EndRenderPass(VkCommandBuffer commandBuffer);
    void DrawTriangle(VkCommandBuffer commandBuffer);
    
    // 窗口大小变化处理
    void OnWindowResize();
    
    // Getter方法
    VkCommandBuffer GetCurrentCommandBuffer();
    VkRenderPass GetRenderPass() const { return renderPass; }
    
private:
    VulkanContext* context;
    std::unique_ptr<CommandManager> commandManager;
    
    // 渲染相关
    VkRenderPass renderPass = VK_NULL_HANDLE;
    VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;
    VkPipeline graphicsPipeline = VK_NULL_HANDLE;
    
    // 着色器
    VkShaderModule vertShaderModule = VK_NULL_HANDLE;
    VkShaderModule fragShaderModule = VK_NULL_HANDLE;
    
    bool CreateRenderPass();
    bool CreateGraphicsPipeline();
    void DestroyGraphicsPipeline();
}; 