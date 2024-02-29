/**
 * @file host_messaging.h
 * @author Frederich Stine
 * @brief eCTF Host Messaging Header
 * @date 2024
 *
 * This source file is part of an example system for MITRE's 2024 Embedded System CTF (eCTF).
 * This code is being provided only for educational purposes for the 2024 MITRE eCTF competition,
 * and may not meet MITRE standards for quality. Use this code at your own risk!
 *
 * @copyright Copyright (c) 2024 The MITRE Corporation
 */

#ifndef __HOST_MESSAGING__
#define __HOST_MESSAGING__

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

// Macro definitions to print the specified format for error messages
#define print_error(...) printf("\nerror: "); printf(__VA_ARGS__); printf("\n"); fflush(stdout)
#define print_hex_error(...) printf("\nerror: "); print_hex(__VA_ARGS__); printf("\n"); fflush(stdout)

// Macro definitions to print the specified format for success messages
#define print_success(...) printf("\nsuccess: "); printf(__VA_ARGS__); printf("\n"); fflush(stdout)
#define print_hex_success(...) printf("\nsuccess: "); print_hex(__VA_ARGS__); printf("\n"); fflush(stdout)

// Macro definitions to print the specified format for debug messages
#define print_debug(...) printf("\ndebug: "); printf(__VA_ARGS__); printf("\n"); fflush(stdout)
#define print_hex_debug(...) printf("\ndebug: "); print_hex(__VA_ARGS__); printf("\n"); fflush(stdout)

// Macro definitions to print the specified format for info messages
#define print_info(...) printf("\ninfo: "); printf(__VA_ARGS__); printf("\n"); fflush(stdout)
#define print_hex_info(...) printf("\ninfo: "); print_hex(__VA_ARGS__); printf("\n"); fflush(stdout)

// Macro definitions to print the specified format for ack messages
#define print_ack() printf("\nack\n\n"); fflush(stdout)

// Print a message through USB UART and then receive a line over USB UART
void recv_input(const char *msg, char *buf);

// Prints a buffer of bytes as a hex string
void print_hex(uint8_t *buf, size_t len);

#endif
