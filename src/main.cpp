#include "core/VulkanContext.hpp"

int main() {
    VulkanContext context;
    if (!context.Initialize()) {
        return -1;
    }

    while (!context.ShouldClose()) {
        context.DrawFrame();
    }

    context.Cleanup();
    return 0;
}
