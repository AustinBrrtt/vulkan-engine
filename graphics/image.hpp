//
// Created by austin on 10/15/19.
//

#ifndef VULKAN_ENGINE_IMAGE_HPP
#define VULKAN_ENGINE_IMAGE_HPP

#include <optional>
#include <vulkan/vulkan.hpp>
#include <vma.hpp>
#include "device.hpp"

namespace Graphics {
	class Image {
	public:
		Image() = default;
		Image(vma::Allocator& allocator, Device* device, uint32_t width, uint32_t height, uint32_t mipLevels,
			  vk::Format format, vk::ImageTiling tiling, vk::ImageUsageFlags const& imageUsage,
			  vk::ImageAspectFlags const& aspectMask, vk::SampleCountFlagBits const& sampleCount,
			  vma::MemoryUsage memoryUsage);
		Image(vk::Image image, vk::ImageView view, vma::Allocation allocation);
		Image(vk::Image image, vk::ImageView view);
		~Image();

		operator vk::Image(); // NOLINT
		operator vk::ImageView(); // NOLINT
	private:
		vk::Image image;
		vk::ImageView view;
		std::optional<vma::Allocation> allocation;
		vk::ImageView* attachments{};
	};
}
#endif //VULKAN_ENGINE_IMAGE_HPP
