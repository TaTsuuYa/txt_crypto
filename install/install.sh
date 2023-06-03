#!/bin/bash

# Define variables
SCRIPT_DIR="$(pwd)"

PROGRAM_NAME="crytxt"
INSTALL_DIR="/usr/local/bin"
SOURCE_DIR="${SCRIPT_DIR}/../src"

# Change to the source directory
cd "${SOURCE_DIR}"

# Compile the program
echo "Compiling..."
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o "${PROGRAM_NAME}"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    # Copy the executable to the installation directory
    mv "${PROGRAM_NAME}" "${INSTALL_DIR}"
    echo "Installation completed."
    # Delete the source directory
    read -p "Do you want to delete the source directory? (Y/N): " answer
    if [ "${answer}" = "Y" ] || [ "${answer}" = "y" ]; then
	    cd ..
	    DIR="$(pwd)"
	    rm -rf "${DIR}"
	    echo "Source directory deleted."
    else
	    echo "Source directory not deleted."
    fi
else
    echo "Compilation failed. Installation aborted."
fi

