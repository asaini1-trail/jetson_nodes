#!/bin/bash

# Script to install the rover_sw_pwrtrain_24b systemd service

set -e

SERVICE_FILE="rover-pwrtrain.service"
SYSTEMD_DIR="/etc/systemd/system"

echo "Installing rover_sw_pwrtrain_24b systemd service..."

# Copy service file to systemd directory
echo "Copying service file to $SYSTEMD_DIR..."
sudo cp "$SERVICE_FILE" "$SYSTEMD_DIR/"

# Reload systemd daemon
echo "Reloading systemd daemon..."
sudo systemctl daemon-reload

# Enable the service to start on boot
echo "Enabling service to start on boot..."
sudo systemctl enable rover-pwrtrain.service

echo ""
echo "Installation complete!"
echo ""
echo "Available commands:"
echo "  sudo systemctl start rover-pwrtrain     # Start the service"
echo "  sudo systemctl stop rover-pwrtrain      # Stop the service"
echo "  sudo systemctl restart rover-pwrtrain   # Restart the service"
echo "  sudo systemctl status rover-pwrtrain    # Check service status"
echo "  journalctl -u rover-pwrtrain -f         # View live logs"
echo "  journalctl -u rover-pwrtrain -n 50      # View last 50 log lines"
echo ""
echo "To start the service now, run:"
echo "  sudo systemctl start rover-pwrtrain"
