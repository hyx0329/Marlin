/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * ASTER L1/LT1 mother board AST_E3_V1 (STM32F103RET6) pin assignments
 *
 * This is a dual-chip printer board and this config only describe the
 * printer part.
 */

#define DEFAULT_MACHINE_NAME "ASTER LT1"
#define BOARD_INFO_NAME      "ASTER_E3V1"

// Avoid conflict with TIMER_SERVO when using the STM32 HAL
#define TEMP_TIMER  5

//
// It is required to disable JTAG function because its pins are
// used as GPIO to drive the Y axis stepper.
// DO NOT ENABLE!
//
#define DISABLE_JTAG

// Enable EEPROM Emulation for this board as it doesn't have EEPROM
// (for the printer part, to be specific)
#if ANY(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION)
  #define FLASH_EEPROM_EMULATION
  #define MARLIN_EEPROM_SIZE              0x1000  // 4K
#endif

// L1/LT1 uses 2 different configurations for difference in BLTouch feature
#if ENABLED(BLTOUCH)
  // Here the BLTouch is also used for Z min probe
  // So USE_PROBE_FOR_Z_HOMING must be defined
  #define Z_MIN_PIN         PB10
  #define Z_MIN_PROBE_PIN   PB10
  #define SERVO0_PIN        PB2   // BLTouch

  // This one is actually the one for switch at Z_MIN_PIN
  // But we have BLTouch
  #define CHDK_PIN          PC0
#else
  #define Z_MIN_PIN         PC0
  #define CHDK_PIN          PB10
  #define Z_MIN_PROBE_PIN   PC0
#endif

//
// Limit Switches
//
#define X_MIN_PIN         PC14
#define Y_MIN_PIN         PC15
//#define Z_MIN_PIN         PC0
#define X_MAX_PIN         -1
#define Y_MAX_PIN         -1
#define Z_MAX_PIN         -1
//#define Z_MIN_PROBE_PIN   PC0

//
// Steppers
//
#define X_STEP_PIN         PB6
#define X_DIR_PIN          PB3
#define X_ENABLE_PIN       PA12

#define Y_STEP_PIN         PD2
#define Y_DIR_PIN          PC10
#define Y_ENABLE_PIN       X_ENABLE_PIN

#define E0_STEP_PIN        PC7
#define E0_DIR_PIN         PC6
#define E0_ENABLE_PIN      X_ENABLE_PIN

#define Z_STEP_PIN        PA11
#define Z_DIR_PIN         PA8
#define Z_ENABLE_PIN      PA15


#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Software serial is used according to the pins below
   */

  //
  // Software serial
  //


  #define X_SERIAL_TX_PIN                   PB5
  #define X_SERIAL_RX_PIN                   PB4

  #define Y_SERIAL_TX_PIN                   PC12
  #define Y_SERIAL_RX_PIN                   PC11

  #define E0_SERIAL_TX_PIN                  PC9
  #define E0_SERIAL_RX_PIN                  PC8

  #define Z_SERIAL_TX_PIN                   PA10
  #define Z_SERIAL_RX_PIN                   PA9

  // Reduce baud rate to improve software serial reliability
  #ifndef TMC_BAUD_RATE
    #define TMC_BAUD_RATE                  19200
  #endif
#endif


//
// Heaters / Fans
//
#define HEATER_0_PIN       PB9
#define HEATER_BED_PIN     PB8
#define FAN0_PIN            PC13

//
// Temperature Sensors
//
#define TEMP_BED_PIN       PC3  // ANALOG NUMBERING
#define TEMP_0_PIN         PC2  // ANALOG NUMBERING

//
// SDCard/LCD
//

#define ONBOARD_SD_CS_PIN   PB12
#define SDSS                ONBOARD_SD_CS_PIN

//EXP2
#define ENABLE_SPI2
#define FORCE_SOFT_SPI

// Onboard SD Card
#define SD_MISO_PIN        PB14
#define SD_SS_PIN          PB12
#define SD_SCK_PIN         PB13
#define SD_MOSI_PIN        PB15
#define SD_DETECT_PIN      PB11

#define BTN_EN1            PA5
#define BTN_EN2            PA4
#define KILL_PIN           -1

//EXP1
#define BEEPER_PIN          PA0
#define BTN_ENC             PA1
#define LCD_PINS_EN         PB1
#define LCD_PINS_RS         PB0
#define LCD_PINS_D4         PA6
#define LCD_PINS_D5         -1	//PA7
#define LCD_PINS_D6         -1	//PC4
#define LCD_PINS_D7         -1	//PC5

#define DOGLCD_CS                PB1
#define DOGLCD_A0                PB0

#define ST7920_DELAY_1 DELAY_NS(0)
#define ST7920_DELAY_2 DELAY_NS(400)
#define ST7920_DELAY_3 DELAY_NS(0)
