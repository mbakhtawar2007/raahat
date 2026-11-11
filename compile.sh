#!/bin/bash
# Raahat — compile (Linux / macOS)
# Run from the project folder:  bash compile.sh   then   ./raahat
set -e
g++ -std=c++17 -Wall -Wextra src/*.cpp -o raahat
echo "Compiled OK. Run: ./raahat"
