#!/bin/bash
# Installation script for GridRover Teleop systemd service

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SERVICE_FILE="$SCRIPT_DIR/gridrover-teleop.service"
SYSTEMD_DIR="/etc/systemd/system"

echo "GridRover Teleop Service Installer"
echo "===================================="
echo ""

# Check if running as root
if [ "$EUID" -ne 0 ]; then
    echo "Error: This script must be run as root (use sudo)"
    exit 1
fi

# Check if service file exists
if [ ! -f "$SERVICE_FILE" ]; then
    echo "Error: Service file not found at $SERVICE_FILE"
    exit 1
fi

echo "Installing gridrover-teleop.service to $SYSTEMD_DIR..."
cp "$SERVICE_FILE" "$SYSTEMD_DIR/gridrover-teleop.service"

echo "Setting proper permissions..."
chmod 644 "$SYSTEMD_DIR/gridrover-teleop.service"

echo "Reloading systemd daemon..."
systemctl daemon-reload

echo "Enabling service to start on boot..."
systemctl enable gridrover-teleop.service

echo ""
echo "Installation complete!"
echo ""
echo "Service commands:"
echo "  Start service:   sudo systemctl start gridrover-teleop"
echo "  Stop service:    sudo systemctl stop gridrover-teleop"
echo "  Restart service: sudo systemctl restart gridrover-teleop"
echo "  Check status:    sudo systemctl status gridrover-teleop"
echo "  View logs:       sudo journalctl -u gridrover-teleop -f"
echo "  Disable auto-start: sudo systemctl disable gridrover-teleop"
echo ""
echo "The service will now start automatically on system boot."
echo "To start it now, run: sudo systemctl start gridrover-teleop"
