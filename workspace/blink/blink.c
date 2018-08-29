

#include <sys/mman.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>
#include <time.h>
#include <taskLib.h>
#include <stdio.h>
#include <kernelLib.h>
#include <semLib.h>
#include <intLib.h>
#include <iv.h>

//#include <xlnx_zynq7k.h>

/*
 * Next macros provides location of knobs and LEDs peripherals
 * implemented in MZ_APO FPGA design.
 *
 * The complete list of peripheral implemented in the design
 * can be found on the page
 *   https://cw.fel.cvut.cz/wiki/courses/b35apo/documentation/mz_apo/start
 */

/*
 * Base address of the region used for mapping of the knobs and LEDs
 * peripherals in the ARM Cortex-A9 physical memory address space.
 */
#define SPILED_REG_BASE_PHYS 0x43c40000

/* Valid address range for the region */
#define SPILED_REG_SIZE      0x00004000

/*
 * Byte offset of the register which controls individual LEDs
 * in the row of 32 yellow LEDs. When the corresponding bit
 * is set (value 1) then the LED is lit.
 */
#define SPILED_REG_LED_LINE_o           0x004

/*
 * The register to control 8 bit RGB components of brightness
 * of the first RGB LED
 */
#define SPILED_REG_LED_RGB1_o           0x010

/*
 * The register to control 8 bit RGB components of brightness
 * of the second RGB LED
 */
#define SPILED_REG_LED_RGB2_o           0x014

/*
 * The register which combines direct write to RGB signals
 * of the RGB LEDs, write to the keyboard scan register
 * and control of the two additional individual LEDs.
 * The direct write to RGB signals is orred with PWM
 * signal generated according to the values in previous
 * registers.
 */
#define SPILED_REG_LED_KBDWR_DIRECT_o   0x018

/*
 * Register providing access to unfiltered encoder channels
 * and keyboard return signals.
 */
#define SPILED_REG_KBDRD_KNOBS_DIRECT_o 0x020

/*
 * The register representing knobs positions as three
 * 8-bit values where each value is incremented
 * and decremented by the knob relative turning.
 */
#define SPILED_REG_KNOBS_8BIT_o         0x024



/*
 * The main entry into example program
 */
int main(int argc, char *argv[])
{


  while (1) {
     uint32_t rgb_knobs_value;
     int int_val;
     unsigned int uint_val;

     /* Initialize structure to 0 seconds and 200 milliseconds */
    // struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 200 * 1000 * 1000};

     /*
      * Access register holding 8 bit relative knobs position
      * The type "(volatile uint32_t*)" casts address obtained
      * as a sum of base address and register offset to the
      * pointer type which target in memory type is 32-bit unsigned
      * integer. The "volatile" keyword ensures that compiler
      * cannot reuse previously read value of the location.
      */
     rgb_knobs_value = *(volatile uint32_t*)(SPILED_REG_BASE_PHYS + SPILED_REG_KNOBS_8BIT_o);

     /* Store the read value to the register controlling individual LEDs */
     *(volatile uint32_t*)(SPILED_REG_BASE_PHYS + SPILED_REG_LED_LINE_o) = rgb_knobs_value;

     /*
      * Store RGB knobs values to the corersponding components controlling
      * a color/brightness of the RGB LEDs
      */
    //*(volatile uint32_t*)(SPILED_REG_BASE_PHYS + SPILED_REG_LED_RGB1_o) = rgb_knobs_value;

    //*(volatile uint32_t*)(SPILED_REG_BASE_PHYS + SPILED_REG_LED_RGB2_o) = rgb_knobs_value;

     /* Assign value read from knobs to the basic signed and unsigned types */
     int_val = rgb_knobs_value;
     uint_val = rgb_knobs_value;

     /* Print values */
     printf("int %10d uint 0x%08x\n", int_val, uint_val);

     /*
      * Wait for time specified by "loop_delay" variable.
      * Use monotonic clocks as time reference to ensure
      * that wait interval is not prolonged or shortened
      * due to real time adjustment.
      */
     //clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
     //sleep(2000);
  } 

  return 0;
}
