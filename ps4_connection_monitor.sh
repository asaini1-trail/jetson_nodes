#!/bin/bash
# Continuous monitoring and auto-reconnect for PS4 controller

PS4_MAC="90:89:5F:CA:48:1E"
CHECK_INTERVAL=5  # Check every 5 seconds

echo "PS4 Controller Monitor Started"
echo "Monitoring connection to: $PS4_MAC"
echo "Check interval: ${CHECK_INTERVAL}s"

while true; do
    # Check if controller is connected
    if ! bluetoothctl info "$PS4_MAC" 2>/dev/null | grep -q "Connected: yes"; then
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] Controller disconnected. Attempting reconnect..."

        # Ensure Bluetooth adapter is up
        sudo hciconfig hci0 up 2>/dev/null

        # Try to reconnect
        bluetoothctl connect "$PS4_MAC" 2>&1 | grep -v "Failed to connect\|Connection successful" &

        # Wait a bit before checking again
        sleep 2

        # Check if reconnection succeeded
        if bluetoothctl info "$PS4_MAC" 2>/dev/null | grep -q "Connected: yes"; then
            echo "[$(date '+%Y-%m-%d %H:%M:%S')] ✓ Controller reconnected successfully"
        else
            echo "[$(date '+%Y-%m-%d %H:%M:%S')] Waiting for controller (press PS button)..."
        fi
    fi

    sleep "$CHECK_INTERVAL"
done
