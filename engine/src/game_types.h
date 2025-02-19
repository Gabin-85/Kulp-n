/**
 * @file game_types.h

 * @brief This file contains types to be consumed by the game library.
 * @copyright Kulpan Game Engine
 */

#pragma once

#include "core/engine.h"
#include "memory/linear_allocator.h"

struct render_packet;

typedef struct game_frame_data {
    // A darray of world geometries to be rendered this frame.
    geometry_render_data* world_geometries;
} game_frame_data;

/**
 * @brief Represents the basic game state in a game.
 * Called for creation by the application.
 */
typedef struct game {
    /** @brief The application configuration. */
    application_config app_config;

    /**
     * @brief Function pointer to the game's boot sequence. This should 
     * fill out the application config with the game's specific requirements.
     * @param game_inst A pointer to the game instance.
     * @returns True on success; otherwise false.
     */
    b8 (*boot)(struct game* game_inst);

    /** 
     * @brief Function pointer to game's initialize function. 
     * @param game_inst A pointer to the game instance.
     * @returns True on success; otherwise false.
     * */
    b8 (*initialize)(struct game* game_inst);

    /** 
     * @brief Function pointer to game's update function. 
     * @param game_inst A pointer to the game instance.
     * @param delta_time The time in seconds since the last frame.
     * @returns True on success; otherwise false.
     * */
    b8 (*update)(struct game* game_inst, f32 delta_time);

    /** 
     * @brief Function pointer to game's render function. 
     * @param game_inst A pointer to the game instance.
     * @param packet A pointer to the packet to be populated by the game.
     * @param delta_time The time in seconds since the last frame.
     * @returns True on success; otherwise false.
     * */
    b8 (*render)(struct game* game_inst, struct render_packet* packet, f32 delta_time);

    /** 
     * @brief Function pointer to handle resizes, if applicable. 
     * @param game_inst A pointer to the game instance.
     * @param width The width of the window in pixels.
     * @param height The height of the window in pixels.
     * */
    void (*on_resize)(struct game* game_inst, u32 width, u32 height);

    /**
     * @brief Shuts down the game, prompting release of resources.
     * @param game_inst A pointer to the game instance.
     */
    void (*shutdown)(struct game* game_inst);

    /** @brief The required size for the game state. */
    u64 state_memory_requirement;

    /** @brief Game-specific game state. Created and managed by the game. */
    void* state;

    /** @brief A block of memory to hold the engine state. Created and managed by the engine. */
    void* engine_state;

    /** 
     * @brief An allocator used for allocations needing to be made every frame. Contents are wiped
     * at the beginning of the frame.
     */
    linear_allocator frame_allocator;

    /** @brief Data which is built up, used and discarded every frame. */
    game_frame_data frame_data;
} game;