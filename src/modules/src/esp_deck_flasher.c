/**
 * ,---------,       ____  _ __
 * |  ,-^-,  |      / __ )(_) /_______________ _____  ___
 * | (  O  ) |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * | / ,--´  |    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *    +------`   /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2021 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file esp_deck_flasher.c
 * Handles flashing of binaries on the ESP32
 *  
 */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG_MODULE "ESPFL"
#include "debug.h"

#include "deck_core.h"
#include "esp_deck_flasher.h"
#include "esp_rom_bootloader.h"
#include "mem.h"

#include "FreeRTOS.h"
#include "task.h"

#include "aideck.h"
#include "deck.h"
#include "uart2.h"

static bool hasStarted = false;

bool espDeckFlasherCheckVersionAndBoot()
{
    hasStarted = true;
    return true;
}