//
// Created by austin on 10/6/19.
//

#include "window.hpp"
#include "../logger/logger.hpp"

namespace glfw{

    Window::Window(int width, int height, std::string const& title) {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    }

    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool Window::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    vk::SurfaceKHR Window::createSurface(vk::Instance& instance) {
        VkSurfaceKHR c_surface;
        Logger::assertTrue(glfwCreateWindowSurface(static_cast<VkInstance>(instance), window, nullptr, &c_surface) == VK_SUCCESS,
                           "Window surface creation failed.");
        return vk::SurfaceKHR(c_surface);
    }

    void appendRequiredExtensions(std::vector<const char *> &instanceExtensions) {
        uint32_t glfwRequiredExtensionsCount;
        auto glfwRequiredExtensions = glfwGetRequiredInstanceExtensions(&glfwRequiredExtensionsCount);
        for (uint32_t i = 0; i < glfwRequiredExtensionsCount; ++i) {
            instanceExtensions.push_back(glfwRequiredExtensions[i]);
        }
    }

    void tick() {
        glfwPollEvents();
    }
}