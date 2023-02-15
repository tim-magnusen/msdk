# This file can be used to set build configuration
# variables.  These variables are defined in a file called 
# "Makefile" that is located next to this one.

# For instructions on how to use this system, see
# https://github.com/Analog-Devices-MSDK/VSCode-Maxim/tree/develop#build-configuration

# **********************************************************

# If you have secure version of MCU, set SBT=1 to generate signed binary
# For more information on how sing process works, see
# https://www.analog.com/en/education/education-library/videos/6313214207112.html
SBT=0

# Enable CORDIO library
LIB_CORDIO = 1

# Set CORDIO library options
TOKEN = 0
BLE_CONTROLLER = 1

# TRACE option
# Set to 2 to enable serial port trace messages
# Set to 0 to disable
TRACE = 0

# Optimize for size
MXC_OPTIMIZE_CFLAGS = -Os
