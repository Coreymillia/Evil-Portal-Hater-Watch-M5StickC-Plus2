# Portal Killer Watch v1.1.3

> **Discrete Portal Defense with Savage Insults**  
> A watch that roasts data thieves and attacks evil portals

![Version](https://img.shields.io/badge/version-1.1.3-blue.svg)
![Platform](https://img.shields.io/badge/platform-M5StickC%20Plus2-orange.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

---

## 🎯 What Is This?

**Portal Killer Watch** is a discrete defense tool disguised as a simple watch. When activated, it automatically detects and attacks evil WiFi portals by flooding their credential capture systems with garbage data and savage insults.

**Key Features:**
- 🕐 **Looks like a watch** - Discrete and unassuming
- 🛡️ **Active defense** - Automatically scans and attacks evil portals
- 💬 **460+ savage insults** - Roasts data thieves with style
- 💾 **Persistent settings** - All preferences survive reboot
- 🎯 **Smart detection** - Works with any portal gateway IP
- 🔥 **Dual attack mode** - Targets generic portals AND NEMO/Bruce specifically

---

## 🚀 Quick Start

### Flash to Device

```bash
esptool --port /dev/ttyACM0 write-flash 0x0 PortalHaterv1.1.3-MERGED.bin
```

### Controls

**Main Clock Screen:**
- **Button A** - Toggle Portal Killer ON/OFF
- **Button B** (short) - Cycle brightness (11 levels)
- **Button B** (hold 1s) - Enter settings menu

**Settings Menu:**
- **Button A** - Select menu item
- **Button B** - Navigate UP ⬆️
- **PWR Button** - Navigate DOWN ⬇️

**Settings Submenus:**
- **Button A** - Save & exit
- **Button B** - Change value (time, color, etc.)
- **PWR Button** - Toggle ON/OFF (timeout/shake features)

---

## 🎮 Features

### Core Functionality

#### Portal Killer Mode
- Scans for open WiFi networks every 30 seconds
- Automatically detects evil portals
- Connects and floods them with fake credentials
- Uses different savage insults for each request
- Tracks kill count on screen

#### Smart Gateway Detection (v1.1.3)
- **Auto-detects portal IP** - works with any gateway
- Supports `192.168.4.1` (WiFi Pineapple)
- Supports `172.0.0.1` (NEMO, Bruce)
- Supports custom gateway IPs

#### Dual Attack Strategy (v1.1.3)
**Generic Portal Attack:**
- Endpoints: `/login`, `/auth`, `/signin`, `/portal`, `/admin`
- Format: `username=hacker&password=<insult>&email=trash@dump.com`

**NEMO/Bruce Portal Attack:**
- Endpoint: `/post` (hit multiple times)
- Format: `email=trash@garbage.com&password=<insult>`

#### Attack Pattern
- 3 attack rounds per portal
- 8 endpoints per round (5 generic + 3 NEMO)
- **24 total POST requests** with garbage data
- Different random insult for each request
- Portal logs flooded with trash! 🗑️

### Clock & Display

- **8 clock colors** - Red, Orange, Green, Cyan, Blue, Magenta, Yellow, White
- **11 brightness levels** - 25 to 255
- **24-hour format** - Configurable (default: enabled)
- **Time setting** - Adjustable hours and minutes
- **Portal status** - Shows active scanning, kill count

### Power Management

#### Screen Timeout
- **5 duration options** - 10s, 30s, 60s, 120s, 300s
- **Toggle ON/OFF** - PWR button
- Saves last used settings
- Portal Killer continues running when screen is off

#### Shake to Wake
- **3 sensitivity levels** - Light, Medium, Heavy
- **Toggle ON/OFF** - PWR button
- Wake screen by shaking the watch
- Configurable acceleration thresholds

### Settings Persistence (v1.1.0)

**All settings survive reboot:**
- ✅ Clock color
- ✅ Brightness level
- ✅ Screen timeout (state + duration)
- ✅ Shake to wake (state + sensitivity)
- ✅ 24-hour format preference

Uses ESP32 NVS (Non-Volatile Storage) - settings stored in flash memory.

---

## 💬 The Insults

**460+ savage roasts** targeting data thieves and portal hackers:

```
"Your portal is garbage!"
"Stealing data? Pathetic."
"You're a script kiddie!"
"Your encryption is weak!"
"Zero-day? More like zero-brain!"
"You hack like you're afraid of success."
"Your brain runs on trial versions with watermark restrictions."
"You're the tutorial boss that everyone beats by accident."
"If stupidity was encrypted, you'd finally crack something."
```

And **450+ more**... Each insult is randomly selected for maximum variety!

---

## 🎯 Targets

### Tested & Verified

| Portal Type | Status | Gateway IP | Attack Format |
|-------------|--------|------------|---------------|
| WiFi Pineapple | ✅ | 192.168.4.1 | Generic |
| NEMO Portal | ✅ | 172.0.0.1 | NEMO-specific |
| Bruce Portal | ✅ | 172.0.0.1 | NEMO-specific |
| Generic Evil Portals | ✅ | Various | Generic |
| Custom Captive Portals | ✅ | Auto-detected | Dual attack |

### What NEMO Sees

**Before Portal Killer:**
```
Email: user@example.com
Password: MyPassword123
```

**After Portal Killer v1.1.3:**
```
Email: trash8234@Yourskil.com
Password: You hack like you're afraid of success.
---
Email: trash2941@garbage.com
Password: Your brain runs on trial versions.
---
Email: trash7123@dump.com
Password: You're a glitch in human form.
---
[+456 more insult-filled entries...]
```

**Their logs get completely flooded!** 🎯

---

## 📦 Technical Details

### Hardware

- **Device:** M5StickC Plus2
- **MCU:** ESP32-PICO-V3-02
- **WiFi:** 802.11 b/g/n
- **Display:** 135×240 LCD
- **Buttons:** A, B, PWR
- **IMU:** For shake detection

### Software

- **Framework:** Arduino (ESP32)
- **Libraries:** M5StickCPlus2, WiFi, HTTPClient, Preferences
- **Flash Size:** ~1.1 MB (merged binary)
- **RAM Usage:** 16.9% (55 KB)
- **Flash Usage:** 81.3% (1.06 MB)

### Code Structure

```
src/main.cpp
├── Clock display & time management
├── Portal detection & scanning
├── Attack logic (dual format)
├── Menu system (flicker-free)
├── Settings persistence (NVS)
├── Screen timeout & wake
└── 460+ insult database
```

### Performance

- **Menu rendering:** Flicker-free, smooth 60+ FPS
- **Scan interval:** 30 seconds (configurable)
- **Attack duration:** ~5 seconds per portal
- **Battery life:** Several hours of active scanning

---

## 🛠️ Building from Source

### Requirements

- PlatformIO Core
- ESP32 toolchain
- M5StickCPlus2 library v1.0.2

### Build Commands

```bash
# Clone repository
git clone https://github.com/yourusername/PortalKillerWatch.git
cd PortalKillerWatch

# Install dependencies
pio lib install

# Build
pio run

# Create merged binary (includes bootloader)
esptool --chip esp32 merge-bin \
  -o PortalHaterv1.1.3-MERGED.bin \
  --flash-mode dio \
  --flash-freq 40m \
  --flash-size 4MB \
  0x1000 .pio/build/m5stick-c-plus2/bootloader.bin \
  0x8000 .pio/build/m5stick-c-plus2/partitions.bin \
  0xe000 ~/.platformio/packages/framework-arduinoespressif32/tools/partitions/boot_app0.bin \
  0x10000 .pio/build/m5stick-c-plus2/firmware.bin

# Flash to device
esptool --port /dev/ttyACM0 write-flash 0x0 PortalHaterv1.1.3-MERGED.bin
```

### platformio.ini

```ini
[env:m5stick-c-plus2]
platform = espressif32
board = m5stick-c
framework = arduino

monitor_speed = 115200
upload_speed = 1500000

lib_deps = 
    m5stack/M5StickCPlus2@^1.0.2
    
build_flags = 
    -DCORE_DEBUG_LEVEL=0
```

---

## 📋 Version History

### v1.1.3 (November 16, 2025) - NEMO Portal Support
- ✅ Smart gateway IP detection (works with any portal)
- ✅ NEMO portal attack support (172.0.0.1)
- ✅ Bruce portal compatibility
- ✅ Dual attack format (generic + NEMO-specific)
- ✅ 24 POST requests per portal (increased spam)

### v1.1.2 (November 16, 2025) - Navigation & Polish
- ✅ Fixed navigation (B=Up, PWR=Down)
- ✅ Eliminated screen flicker in all menus
- ✅ Smooth, professional UI experience
- ✅ Optimized redraw logic (~90% reduction)

### v1.1.1 (November 16, 2025) - Menu Controls
- ✅ PWR button navigates in main menu
- ✅ PWR button toggles ON/OFF in settings
- ✅ Fixed stuck-ON bug for timeout/shake features

### v1.1.0 (November 16, 2025) - Persistent Settings
- ✅ All settings survive reboot
- ✅ ESP32 NVS storage implementation
- ✅ Auto-save on menu changes
- ✅ Auto-load on startup

### v1.0.9 (Base) - Core Features
- ✅ Portal Killer active scanning
- ✅ 460+ savage insults
- ✅ Discrete watch interface
- ✅ Clock display with customization
- ✅ Screen timeout & shake to wake

---

## 🎨 Screenshots

### Clock Display
```
┌─────────────────┐
│  PORTAL KILLER  │
│     WATCH       │
│                 │
│   12:34:56      │  ← Clock (8 colors)
│                 │
│ PORTAL KILLER:  │
│ ACTIVE          │
│ Kills: 5        │
│ Scanning...     │
│                 │
│ A:Off  B:Bright │
└─────────────────┘
```

### Attack in Progress
```
┌─────────────────┐
│   12:34:56      │
│                 │
│ ATTACKING:      │
│ NEMO Free WiFi  │
│                 │
│ Your portal is  │
│ garbage! You're │
│ a script kiddie!│
│                 │
│ Gateway: 172.0.0.1 │
└─────────────────┘
```

### Settings Menu
```
┌─────────────────┐
│   SETTINGS      │
│                 │
│ ▶ Set Time      │  ← Selected (green)
│   Screen Timeout│
│   Shake to Wake │
│   Clock Color   │
│   Exit Menu     │
│                 │
│ Timeout:ON Shake:OFF │
│ A:Sel B:Up PWR:Down  │
└─────────────────┘
```

---

## 🔒 Legal & Ethics

### Intended Use

This tool is designed for:
- **Security research** - Testing your own networks
- **Educational purposes** - Understanding captive portals
- **Authorized penetration testing** - With proper permissions
- **Personal protection** - Defending against rogue portals

### Important Notes

⚠️ **Only use on networks you own or have explicit permission to test.**

- Attacking networks without authorization is **illegal**
- This tool is for **defensive** purposes
- The author is not responsible for misuse
- Always comply with local laws and regulations

### Ethical Guidelines

✅ **DO:**
- Test your own networks
- Use in authorized pen-testing
- Learn about portal defense
- Protect yourself from rogue portals

❌ **DON'T:**
- Attack public networks
- Use without permission
- Deploy in production environments without authorization
- Violate computer fraud laws

---

## 🤝 Contributing

Contributions are welcome! Please:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Ideas for Contributions

- Additional portal attack patterns
- More insult categories
- Battery life optimizations
- Additional device support (M5Cardputer, etc.)
- UI improvements
- Documentation enhancements

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **M5Stack** - For the excellent M5StickC Plus2 hardware
- **Evil Portal community** - For understanding portal mechanics
- **Security researchers** - For identifying portal vulnerabilities
- **Open source contributors** - For libraries and tools

### Inspiration

- NEMO portal project (n0xa/m5stick-nemo)
- WiFi Pineapple defense concepts
- Captive portal security research

---

## 📞 Support

- **Issues:** [GitHub Issues](https://github.com/yourusername/PortalKillerWatch/issues)
- **Discussions:** [GitHub Discussions](https://github.com/yourusername/PortalKillerWatch/discussions)
- **Documentation:** See changelogs for detailed version notes

---

## 🎊 Ready to Deploy!

```bash
# Quick flash command
esptool --port /dev/ttyACM0 write-flash 0x0 PortalHaterv1.1.3-MERGED.bin

# Your watch is now a portal killer! 🎯
```

**Features:**
- ✨ Persistent settings
- 🎮 Intuitive navigation
- 🚀 Zero flicker
- 💾 Full control
- 🛡️ NEMO support
- 🧠 Smart gateway detection

**Now go roast some data thieves!** 😈💥

---

Made with 💀 by portal defense enthusiasts
