#! /usr/bin/env python3

################################################################################
 # Copyright (C) 2020 Maxim Integrated Products, Inc., All Rights Reserved.
 #
 # Permission is hereby granted, free of charge, to any person obtaining a
 # copy of this software and associated documentation files (the "Software"),
 # to deal in the Software without restriction, including without limitation
 # the rights to use, copy, modify, merge, publish, distribute, sublicense,
 # and/or sell copies of the Software, and to permit persons to whom the
 # Software is furnished to do so, subject to the following conditions:
 #
 # The above copyright notice and this permission notice shall be included
 # in all copies or substantial portions of the Software.
 #
 # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 # OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 # MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 # IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 # OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 # ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 # OTHER DEALINGS IN THE SOFTWARE.
 #
 # Except as contained in this notice, the name of Maxim Integrated
 # Products, Inc. shall not be used except as stated in the Maxim Integrated
 # Products, Inc. Branding Policy.
 #
 # The mere transfer of this software does not imply any licenses
 # of trade secrets, proprietary technology, copyrights, patents,
 # trademarks, maskwork rights, or any other form of intellectual
 # property whatsoever. Maxim Integrated Products, Inc. retains all
 # ownership rights.
 #
 ###############################################################################

## dtm_sweep.py
 #
 # Sweep connection parameters.
 #
 # Ensure that both targets are built with BT_VER := 9
 #

import sys
import argparse
from argparse import RawTextHelpFormatter
from time import sleep
import itertools
from mini_RCDAT_USB import mini_RCDAT_USB
from BLE_hci import BLE_hci
from BLE_hci import Namespace
import socket
import time
import os.path
import json
import mxc_radio
from termcolor import colored


from json import JSONEncoder

if socket.gethostname() == "wall-e":
    rf_switch = True
else:
    rf_switch = False
TRACE_INFO = 2
TRACE_WARNING =  1
TRACE_ERROR = 0

traceLevel = TRACE_INFO

def printTrace(label, msg,callerLevel, color='white'):
    if  callerLevel <= traceLevel:
        print(colored(label + ": ", color), colored(msg, color))

def printWarning(msg):
    printTrace('Warning', msg, TRACE_WARNING, 'yellow')

def printInfo(msg):
    printTrace('Info', msg, TRACE_INFO, 'green')

def printError(msg):
    printTrace('Error', msg, TRACE_ERROR, 'red')

dbbFile = 'dbb_reference.json'


# Setup the command line description text
descText = """
Run Calibration and Initialization Tests
"""

# Parse the command line arguments
parser = argparse.ArgumentParser(description=descText, formatter_class=RawTextHelpFormatter)
parser.add_argument('serialPort',help='Serial port for slave device')
parser.add_argument('board',  help='Board to read Cal Values')

# parser.add_argument('-r', '--results', default='',help='File to store results')
parser.add_argument('-urd', '--update-reference-dbb', action='store_true')
parser.add_argument('-ura', '--update-reference-afe', action='store_true')
parser.add_argument('-vd', '--verify-dbb',  action='store_true')
parser.add_argument('-p', '--print',  action='store_true')
parser.add_argument('-f', '--file',  default=dbbFile)





args = parser.parse_args()
print(args)

print("--------------------------------------------------------------------------------------------")

print("Serial Port   :", args.serialPort)
dbbFile = args.file



# Open the results file, write the parameters

# if args.results != '':
#     results = open(args.results, "a")    

def main():
    # Create the BLE_hci objects
    hciInterface  = BLE_hci(Namespace(serialPort=args.serialPort,  monPort="", baud=115200, id=1))

    board = args.board.lower()
    dbb = mxc_radio.DBB(hciInterface=hciInterface, board=board)
    dbbReadout = dbb.readAll()
    

    
    if args.update_reference_dbb:
        with open(dbbFile, 'w') as write:
            json.dump(dbbReadout, write)
    
    

    if args.print:
        print(colored(dbbReadout, 'green'))

    if args.verify_dbb:
        dbbRef = {}
        if(os.path.exists(dbbFile)):
            with open(dbbFile, 'r') as read:
                dbbRef = json.load(read)
            print('DBB Match', dbbRef == dbbReadout)
        else:
            print(f'{dbbFile} Does Not Exist!')
    
    sys.exit(0)

if __name__ == "__main__":
    main()
