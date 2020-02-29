// SPDX-License-Identifier: Beerware
/**
 * @file  Tamago.h
 * @brief Tamago game handler
 */
#pragma once

#include <stdint.h>

#define REFRESH_RATE_IN_MS    500   ///< Display refresh rate in ms
#define SPEED_FACTOR            1.f ///< Game speed factor

#define LEN_IDLE_EGG            2   ///< Length, Egg idle animation
#define LEN_IDLE_BABYTCHI      36   ///< Length, Babytchi idle animation
#define LEN_IDLE_MARUTCHI      28   ///< Length, Marutchi idle animation
#define LEN_IDLE_TAMATCHI       0   ///< Todo
#define LEN_IDLE_KUCHITAMATCHI  0   ///< Todo
#define LEN_IDLE_MAMETCHI       0   ///< Todo
#define LEN_IDLE_GINJIROTCHI    0   ///< Todo
#define LEN_IDLE_MASKUTCHI      0   ///< Todo
#define LEN_IDLE_KUCHIPATCHI    0   ///< Todo
#define LEN_IDLE_NYOROTCHI      0   ///< Todo
#define LEN_IDLE_TARAKOTCHI     0   ///< Todo
#define LEN_IDLE_OYAJITCHI      0   ///< Todo

/**
 * @enum    AnimOffset
 * @brief   Animation offsets
 */
typedef enum
{
    OFFSET_IDLE_EGG           =    0, ///< Offset, Egg idle animation
    OFFSET_IDLE_BABYTCHI      =  128, ///< Offset, Babytchi idle animation
    OFFSET_IDLE_MARUTCHI      = 2432, ///< Offset, Marutchi idle animation
    OFFSET_IDLE_TAMATCHI      = 4224, ///< Offset, Tamatchi idle animation
    OFFSET_IDLE_KUCHITAMATCHI = 4352, ///< Offset, Kuchitamatchi idle animation
    OFFSET_IDLE_MAMETCHI      = 5376, ///< Offset, Mametchi idle animation
    OFFSET_IDLE_GINJIROTCHI   = 5504, ///< Offset, Ginjirotchi idle animation
    OFFSET_IDLE_MASKUTCHI     = 6272, ///< Offset, Maskutchi idle animation
    OFFSET_IDLE_KUCHIPATCHI   = 7040, ///< Offset, Kuchipatchi idle animation
    OFFSET_IDLE_NYOROTCHI     = 8832, ///< Offset, Nyorotchi idle animation
    OFFSET_IDLE_TARAKOTCHI    = 9856, ///< Offset, Tarakotchi idle animation
    OFFSET_IDLE_OYAJITCHI     = 9984  ///< Offset, Oyajotchi idle animation

} AnimOffset;

/**
 * @struct Animation
 * @brief  Animation
 */
typedef struct
{
    uint8_t    au8Buffer[32][16]; ///< Buffer
    AnimOffset eOffset;           ///< Animation offset
    uint8_t    u8Length;          ///< Animation length/number of frames

} Animation;

/**
 * @enum  Evolution
 * @brief Tamago evolutions
 */
typedef enum
{
    EGG = 0,       ///< Egg
    BABYTCHI,      ///< Baby, from Egg
    MARUTCHI,      ///< Child, from Babytchi
    TAMATCHI,      ///< Teen, good care from Marutchi
    KUCHITAMATCHI, ///< Teen, bad care from Marutchi
    MAMETCHI,      ///< Adult, perfect care from Tamatchi
    GINJIROTCHI,   ///< Adult, above average care from Tamatchi
    MASKUTCHI,     ///< Adult, average care from Tamatchi
    KUCHIPATCHI,   ///< Adult, below average care from Tamatchi, perfect care from Kuchitamatchi
    NYOROTCHI,     ///< Adult, bad care from Tamatchi, average care from Kuchitamatchi
    TARAKOTCHI,    ///< Adult, Horrible care from both
    OYAJITCHI,     ///< Special, no discipline until it evolves to Maskutchi, perfect care from Maskutchi
    DEAD           ///< Dead

} Evolution;

/**
 * @struct Stats
 * @brief  Pet statistics
 */
typedef struct
{
    uint8_t   u8Age;           ///< Age in days
    uint16_t  u16CareMistages; ///< Number of care mistakes
    Evolution eEvolution;      ///< Current evolution

} Stats;

int Tamago_Init(void);