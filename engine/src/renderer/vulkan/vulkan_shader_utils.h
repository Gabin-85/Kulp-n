/**
 * @file vulkan_shader_utils.h
 * @brief A collection of shader utility functions.
 * @copyright Kulpan Game Engine
 */

#pragma once

#include "vulkan_types.inl"

/**
 * @brief Create a shader module object
 * 
 * @param context A pointer to the Vulkan context.
 * @param name The name of the shader module.
 * @param type_str A string representation of the shader type.
 * @param shader_stage_flag The flag indicating the shader stage.
 * @param stage_index The index of the shader stage.
 * @param shader_stages An array of shader stages.
 * @return True on success; otherwise false.
 */
b8 create_shader_module(
    vulkan_context* context,
    const char* name,
    const char* type_str,
    VkShaderStageFlagBits shader_stage_flag,
    u32 stage_index,
    vulkan_shader_stage* shader_stages);
