# Install GridRover Services - Robust Configuration

## Step 1: Configure Robust Bluetooth

Run this first to make Bluetooth as robust as possible:

```bash
sudo ./configure_robust_bluetooth.sh
```

This will:
- Prevent Bluetooth from sleeping (disable USB autosuspend)
- Configure aggressive reconnection attempts (10 retries)
- Prevent idle disconnections
- Block your Mac from connecting (if you provide its MAC address)
- Keep PS4 controller trusted and ready

**Reboot after this step.**

## Step 2: Install Services

After reboot, install the auto-start services:

### Install Connection Monitor (checks every 5 seconds)
```bash
sudo cp ps4-bluetooth-monitor.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl enable ps4-bluetooth-monitor.service
sudo systemctl start ps4-bluetooth-monitor.service
```

### Install Teleop Service
```bash
sudo ./install_teleop_service.sh
```

## Step 3: Verify Installation

```bash
sudo systemctl status ps4-bluetooth-monitor
sudo systemctl status gridrover-teleop
```

## How It Works

**Connection Monitor:**
- Checks controller connection every 5 seconds
- Automatically reconnects if disconnected
- No manual intervention needed
- Just press PS button and it reconnects immediately

**Robustness Features:**
- ✓ Bluetooth never sleeps (USB autosuspend disabled)
- ✓ 10 reconnection attempts with smart intervals
- ✓ Continuous monitoring every 5 seconds
- ✓ Auto-reconnect on wake from sleep
- ✓ Mac blocked from stealing connection
- ✓ Works even after going out of range

## View Logs

```bash
# Monitor connection status (live)
sudo journalctl -u ps4-bluetooth-monitor -f

# Teleop logs
sudo journalctl -u gridrover-teleop -f
```

## Manual Reconnect

If needed:
```bash
sudo ./bluetooth_reconnect.sh
```

## Testing

```bash
# Check controller device
ls /dev/input/js*

# Test topics
ros2 topic echo /ps4/left_stick_y
ros2 topic echo /ps4/right_stick_x
ros2 topic echo /ps4/button_l1
```
