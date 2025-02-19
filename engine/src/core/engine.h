/**
 * @file engine.h
 * @brief This file contains structures and logic pertaining to the
 * overall engine application itself. 
 * The application is responsible for managing both the platform layers
 * as well as all systems within the engine.
 * @copyright Kulpan Game Engine
 */

#pragma once

#include "defines.h"
#include "systems/font_system.h"
#include "renderer/renderer_types.inl"

struct game;

/** 
 * @brief Represents configuration for the application. The application config
 * is fed to the engine on creation, so it knows hot to configure itself internally.
 */
typedef struct application_config {
    /** @brief Window starting position x axis, if applicable. */
    i16 start_pos_x;

    /** @brief Window starting position y axis, if applicable. */
    i16 start_pos_y;

    /** @brief Window starting width, if applicable. */
    i16 start_width;

    /** @brief Window starting height, if applicable. */
    i16 start_height;

    /** @brief The application name used in windowing, if applicable. */
    char* name;

    /** @brief Configuration for the font system. */
    font_system_config font_config;

    /** @brief A darray of render view configurations. */
    render_view_config* render_views;
} application_config;

/**
 * @brief Creates the engine, standing up the platform layer and all
 * underlying subsystems.
 * @param game_inst A pointer to the application instance associated with the engine
 * @returns True on success; otherwise false.
 */
KAPI b8 engine_create(struct game* game_inst);

/**
 * @brief Starts the main engine loop.
 * @returns True on success; otherwise false.
 */
KAPI b8 engine_run();