#!/bin/bash

# This script compiles the program and executes it.

clear
# Load variables from config
source "./config"

echo -e "${COLOR_YELLOW}Cleaning and compiling...${COLOR_RESET}"

if [ ! -d "build" ]; then
  mkdir build
fi

make clean
make

if [ $? -ne 0 ]; then
  echo -e "${COLOR_RED}Compile error.${COLOR_RESET}"
else
  echo -e "${COLOR_GREEN}Successful build.${COLOR_RESET}"
  echo -e "${COLOR_YELLOW}Executing...${COLOR_RESET}"
  ./build/${PROGRAM_NAME}
  if [ $? -ne 0 ]; then
    echo -e "${COLOR_RED}Execution error.${COLOR_RESET}"
  else
    echo -e "${COLOR_GREEN}Execution successful.${COLOR_RESET}"
  fi
fi
