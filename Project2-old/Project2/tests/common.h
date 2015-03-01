/**
 * @file   common.h
 *
 * @brief Some common macros.
 *
 * CSC 460/560 Real Time Operating Systems - Mantis Cheng
 *
 * @author Scott Craig
 * @author Justin Tanner
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef __COMMON_H__
#define __COMMON_H__


#define Disable_Interrupt()     asm volatile ("cli"::)
#define Enable_Interrupt()     asm volatile ("sei"::)

#endif
