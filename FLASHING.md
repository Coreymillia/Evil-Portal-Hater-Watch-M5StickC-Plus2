# Flashing Instructions

## Method 1: M5Burner (Recommended - Easiest)

### What You Need
- M5StickC Plus2 device
- USB-C cable (must support data transfer)
- M5Burner software ([Download here](https://docs.m5stack.com/en/download))

### Steps
1. **Download Firmware**
   - Use `PortalHaterv1.0.8-MERGED.bin` from the firmware folder

2. **Open M5Burner**
   - Launch M5Burner application

3. **Connect Device**
   - Plug M5StickC Plus2 into your computer via USB-C
   - M5Burner should auto-detect the port

4. **Flash**
   - Click "Burn" button
   - Select `PortalHaterv1.0.8-MERGED.bin`
   - Wait for flashing to complete (about 20-30 seconds)

5. **Done!**
   - Device will auto-restart with Portal Killer Watch

---

## Method 2: esptool.py (Command Line)

### What You Need
- Python 3.x installed
- esptool.py (`pip install esptool`)

### Linux/Mac
```bash
# Install esptool if needed
pip3 install esptool

# Flash the firmware (adjust port if needed)
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 \
  write_flash 0x0 PortalHaterv1.0.8-MERGED.bin
```

### Windows
```bash
# Install esptool if needed
pip install esptool

# Flash the firmware (adjust COM port)
esptool.py --chip esp32 --port COM3 --baud 921600 ^
  write_flash 0x0 PortalHaterv1.0.8-MERGED.bin
```

### Find Your Port
**Linux:** `/dev/ttyUSB0` or `/dev/ttyACM0`
**Mac:** `/dev/cu.usbserial-*`
**Windows:** `COM3`, `COM4`, etc. (check Device Manager)

---

## Method 3: PlatformIO (For Developers)

### What You Need
- PlatformIO installed (VSCode extension or CLI)
- Source code from `/source/` folder

### Steps
```bash
# Navigate to source folder
cd source/

# Build and flash
pio run --target upload
```

---

## Troubleshooting

### Device Not Detected
- **Try different USB cable** (must support data, not just power)
- **Try different USB port** on your computer
- **Install drivers** (usually automatic, but may need CP210x or CH340 drivers)
- **Hold reset button** while connecting

### Flash Failed / Timeout
- **Lower baud rate:** Use `115200` instead of `921600`
  ```bash
  esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 115200 \
    write_flash 0x0 PortalHaterv1.0.8-MERGED.bin
  ```
- **Erase flash first:**
  ```bash
  esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash
  ```

### Permission Denied (Linux)
```bash
# Add yourself to dialout group
sudo usermod -a -G dialout $USER

# Or use sudo for single flash
sudo esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 \
  write_flash 0x0 PortalHaterv1.0.8-MERGED.bin
```

### Wrong Firmware File
- **Always use the MERGED file** (`PortalHaterv1.0.8-MERGED.bin`)
- This includes bootloader, partitions, and app
- The non-MERGED file is only the app partition (for updates)

---

## Verification

After flashing, your device should:
1. Show "PORTAL KILLER WATCH" splash screen
2. Display current time
3. Show "Portal Killer: OFF" at bottom
4. Respond to button presses

If you see this, flashing was successful! 🎉

---

## First Time Setup

1. **Set the time:**
   - Hold B button for 1 second
   - Select "Set Time"
   - Adjust hours and minutes with B button
   - Press A to confirm

2. **Configure settings:**
   - Screen Timeout (optional)
   - Shake to Wake (optional)
   - Clock Color (optional)

3. **Start Portal Hunting:**
   - Press A button to activate
   - Watch will scan every 30 seconds

---

## Need Help?

If you're still having issues:
1. Check the README.md troubleshooting section
2. Open an issue on GitHub
3. Verify MD5 checksums of firmware files
