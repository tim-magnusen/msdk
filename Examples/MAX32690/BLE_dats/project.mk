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

# Optimize for size
MXC_OPTIMIZE_CFLAGS = -Os

# Disable central and observer.  They're
# not needed for this server app.
INIT_PERIPHERAL = 1
INIT_BROADCASTER = 1
INIT_CENTRAL = 0
INIT_OBSERVER = 0

# Add services directory to build
IPATH += services
VPATH += services
