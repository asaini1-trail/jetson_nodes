#!/bin/bash
# Configure Bluetooth for maximum robustness with PS4 controller

echo "=========================================="
echo "Robust Bluetooth Configuration"
echo "=========================================="
echo ""

PS4_MAC="90:89:5F:CA:48:1E"

# Get your Mac's Bluetooth MAC if you know it
read -p "Enter your Mac's Bluetooth MAC address (or press Enter to skip): " MAC_MAC

echo ""
echo "Step 1: Stopping Bluetooth service..."
sudo systemctl stop bluetooth
sleep 2

echo "Step 2: Configuring Bluetooth settings..."

# Configure Bluetooth for robustness
sudo tee /etc/bluetooth/main.conf > /dev/null << 'EOF'
[General]
Name = GridRover
Class = 0x000100
DiscoverableTimeout = 0
PairableTimeout = 0
Discoverable = false
Pairable = false
AlwaysPairable = false

# Disable auto-suspend
ControllerMode = dual
FastConnectable = true
Privacy = off

[Policy]
AutoEnable = true
ReconnectAttempts = 10
ReconnectIntervals = 1,1,2,3,5,8,13,21,34,55

[LE]
MinConnectionInterval = 7
MaxConnectionInterval = 9
ConnectionLatency = 0
ConnectionSupervisionTimeout = 420
EOF

echo "✓ Bluetooth main config updated"

# Configure USB power management to prevent Bluetooth sleep
echo "Step 3: Disabling USB autosuspend for Bluetooth..."

# Find Bluetooth USB device
BT_USB_ID=$(lsusb | grep -i bluetooth | awk '{print $6}')

if [ -n "$BT_USB_ID" ]; then
    VENDOR_ID=$(echo $BT_USB_ID | cut -d: -f1)
    PRODUCT_ID=$(echo $BT_USB_ID | cut -d: -f2)

    # Create udev rule to disable autosuspend
    sudo tee /etc/udev/rules.d/50-bluetooth-no-suspend.rules > /dev/null << EOF
# Disable autosuspend for Bluetooth adapter
ACTION=="add", SUBSYSTEM=="usb", ATTR{idVendor}=="$VENDOR_ID", ATTR{idProduct}=="$PRODUCT_ID", ATTR{power/autosuspend}="-1"
EOF

    echo "✓ Created udev rule for Bluetooth adapter ($BT_USB_ID)"
fi

# Prevent all USB devices from sleeping (more aggressive)
sudo tee -a /etc/udev/rules.d/50-usb-no-suspend.rules > /dev/null << 'EOF'
# Prevent USB suspend globally
ACTION=="add", SUBSYSTEM=="usb", ATTR{power/autosuspend}="-1"
EOF

echo "✓ Created global USB no-suspend rule"

# Configure kernel parameters
echo "Step 4: Configuring kernel Bluetooth parameters..."

sudo tee /etc/modprobe.d/bluetooth.conf > /dev/null << 'EOF'
# Bluetooth kernel parameters for stability
options bluetooth disable_ertm=1
options btusb enable_autosuspend=0
EOF

echo "✓ Bluetooth kernel parameters configured"

# Reload udev rules
sudo udevadm control --reload-rules
sudo udevadm trigger

echo ""
echo "Step 5: Starting Bluetooth service..."
sudo systemctl start bluetooth
sleep 3

# Configure adapter
echo "Step 6: Configuring adapter settings..."
sudo hciconfig hci0 up
sudo hciconfig hci0 sspmode 1
sudo hciconfig hci0 piscan

# Block Mac if MAC address provided
if [ -n "$MAC_MAC" ]; then
    echo ""
    echo "Step 7: Blocking Mac ($MAC_MAC)..."
    bluetoothctl block "$MAC_MAC"
    echo "✓ Mac blocked from connecting"
fi

# Ensure PS4 controller is trusted and unblocked
echo ""
echo "Step 8: Ensuring PS4 controller is trusted..."
bluetoothctl trust "$PS4_MAC"
bluetoothctl unblock "$PS4_MAC"

echo ""
echo "=========================================="
echo "✓ Configuration Complete"
echo "=========================================="
echo ""
echo "Changes made:"
echo "  ✓ Bluetooth configured for maximum reconnection attempts"
echo "  ✓ USB autosuspend disabled (prevents Bluetooth sleep)"
echo "  ✓ Kernel parameters optimized"
echo "  ✓ PS4 controller trusted and unblocked"
if [ -n "$MAC_MAC" ]; then
    echo "  ✓ Mac blocked from connecting"
fi
echo ""
echo "Reboot recommended for all changes to take effect."
echo ""
read -p "Reboot now? (y/n): " REBOOT

if [ "$REBOOT" = "y" ] || [ "$REBOOT" = "Y" ]; then
    echo "Rebooting in 5 seconds..."
    sleep 5
    sudo reboot
else
    echo ""
    echo "Reboot later with: sudo reboot"
fi
