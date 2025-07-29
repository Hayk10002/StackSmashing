#!/bin/bash
set -e

if [[ $# -eq 0 ]]; then
    echo "No arguments provided"
    exit 1
fi

echo "[*] Installing pwntools..."
pip install --upgrade pip
pip install pwntools

echo "[*] Running exploit..."
cd "$(dirname "$0")"
python3 exploit.py "$1"