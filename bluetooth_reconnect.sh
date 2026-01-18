#!/bin/bash
# Robust PS4 Controller Reconnect with retry logic

PS4_MAC="90:89:5F:CA:48:1E"

echo "Reconnecting to PS4 controller: $PS4_MAC"

# Power on Bluetooth adapter
sudo hciconfig hci0 up
sudo hciconfig hci0 piscan

# Try to connect with retries
MAX_RETRIES=3
RETRY_COUNT=0

while [ $RETRY_COUNT -lt $MAX_RETRIES ]; do
    echo "Attempt $((RETRY_COUNT + 1)) of $MAX_RETRIES..."

    bluetoothctl << BTEOF
power on
connect $PS4_MAC
quit
BTEOF

    sleep 3

    # Check if connected
    if bluetoothctl info $PS4_MAC | grep -q "Connected: yes"; then
        echo "✓ Controller connected successfully"
        exit 0
    fi

    RETRY_COUNT=$((RETRY_COUNT + 1))
    [ $RETRY_COUNT -lt $MAX_RETRIES ] && sleep 2
done

echo "✗ Failed to connect after $MAX_RETRIES attempts."
echo "Press PS button on controller and run this script again."
exit 1
