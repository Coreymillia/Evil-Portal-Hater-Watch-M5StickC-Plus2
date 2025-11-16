# 🎯 Portal Killer Watch

> A cybersecurity wearable that detects and counter-attacks evil WiFi portals with 420 savage insults

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-1.0.8-blue.svg)](https://github.com/yourusername/PortalKillerWatch/releases)
[![Hardware](https://img.shields.io/badge/hardware-M5StickC%20Plus2-red.svg)](https://docs.m5stack.com/en/core/M5StickC%20PLUS2)
[![Platform](https://img.shields.io/badge/platform-ESP32-green.svg)](https://www.espressif.com/en/products/socs/esp32)

<div align="center">
  <img src="https://img.shields.io/badge/Status-Stable-brightgreen" alt="Status">
  <img src="https://img.shields.io/badge/Insults-420-orange" alt="Insults">
  <img src="https://img.shields.io/badge/WiFi-Security-blue" alt="WiFi Security">
</div>

---

## 🔥 What It Does

Portal Killer Watch is a **defensive security tool** that runs on M5StickC Plus2. It automatically:

- 🔍 **Scans** for open WiFi networks (potential evil portals)
- ⚡ **Detects** suspicious captive portals
- 💥 **Counter-attacks** by flooding them with fake credentials
- 🎯 **Roasts** data thieves with 420 unique, savage insults
- ⌚ **Functions** as a normal watch with customizable display

**Perfect for:** Coffee shops, airports, hotels, conferences - anywhere evil portals lurk!

---

## ✨ Features

### Core Functionality
- ✅ **420 Unique Insults** - Creative, tech-focused roasts for data thieves
- ✅ **Automatic Detection** - Scans for open WiFi networks every 30 seconds
- ✅ **Smart Counter-Attack** - Sends 25 different random fake credentials per portal
- ✅ **Status Tracking** - Visual feedback with color-coded messages:
  - 🟡 **PORTAL ATTACKED!** - Successfully connected and spamming
  - 🔵 **PORTAL DODGED!** - Couldn't connect to portal
  - 🟢 **PORTAL NUKED!** - Portal disappeared after attack (success!)

### Display & Interface
- ⏰ **Always-On Clock** - Time displayed at top, portal status below
- 🎨 **8 Clock Colors** - Red, Orange, Green, Cyan, Blue, Magenta, Yellow, White
- 💡 **11 Brightness Levels** - Adjustable for any lighting condition
- 🎛️ **Settings Menu** - Easy configuration with button navigation

### Power Management
- 💤 **Screen Timeout** - Auto-sleep after 10s, 30s, 60s, 2min, or 5min
- 🔔 **Shake to Wake** - Three sensitivity levels (Light, Medium, Heavy)
- 🔋 **Battery Optimized** - Efficient scanning and display management

---

## 📦 Quick Start

### What You Need
- M5StickC Plus2 device
- USB-C cable (data transfer capable)
- M5Burner OR esptool.py

### Installation (2 Minutes)

#### Option 1: M5Burner (Easiest)
1. Download [M5Burner](https://docs.m5stack.com/en/download)
2. Download `PortalHaterv1.0.8-MERGED.bin` from [Releases](../../releases)
3. Connect M5StickC Plus2 via USB
4. Open M5Burner, select your port
5. Click "Burn" and select the MERGED.bin file
6. Wait 30 seconds - Done!

#### Option 2: Command Line
```bash
pip install esptool
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 \
  write_flash 0x0 PortalHaterv1.0.8-MERGED.bin
```

### First Use
1. Device boots showing "PORTAL KILLER WATCH"
2. **Hold B button** (1 sec) to open settings menu
3. Select "Set Time" and adjust with A/B buttons
4. **Press A button** to activate Portal Killer mode
5. Watch automatically scans and attacks evil portals!

---

## 🎮 Controls

### Buttons
| Button | Action | Function |
|--------|--------|----------|
| **A** (tap) | Toggle | Portal Killer ON/OFF |
| **A** (in menu) | Select | Choose/confirm option |
| **B** (tap) | Brightness | Cycle through 11 levels |
| **B** (hold 1s) | Menu | Open settings menu |
| **B** (in menu) | Navigate | Move through options |
| **Power** (hold 6s) | Power Off | Shut down device |

### Settings Menu
1. **Set Time** - Adjust hours and minutes (saves to RTC)
2. **Screen Timeout** - Enable/disable with 5 duration options
3. **Shake to Wake** - Toggle and adjust sensitivity (Light/Medium/Heavy)
4. **Clock Color** - Choose from 8 colors with live preview
5. **Exit Menu** - Return to clock

---

## 🛠️ Building From Source

### Requirements
- [PlatformIO](https://platformio.org/) (VSCode extension or CLI)
- M5StickC Plus2 device

### Build Steps
```bash
# Clone the repository
git clone https://github.com/yourusername/PortalKillerWatch.git
cd PortalKillerWatch

# Build
pio run

# Flash to device
pio run --target upload

# Monitor serial output (optional)
pio device monitor
```

### Dependencies (Auto-installed)
- M5StickCPlus2 library v1.0.2
- HTTPClient v2.0.0
- WiFi v2.0.0

---

## 📊 Technical Specifications

| Component | Details |
|-----------|---------|
| **Device** | M5StickC Plus2 |
| **MCU** | ESP32-PICO-V3-02 (Dual-core 240MHz) |
| **Display** | 1.14" TFT LCD (135x240 pixels) |
| **WiFi** | 2.4GHz 802.11 b/g/n |
| **Sensors** | 6-axis IMU (accelerometer + gyro) |
| **Memory** | 320KB RAM, 4MB Flash |
| **Power** | Built-in 200mAh battery + USB-C |
| **RAM Usage** | 16.9% (55,480 bytes) |
| **Flash Usage** | 81.0% (1,061,865 bytes) |

---

## 🎯 How It Works

### Detection
1. Device scans WiFi every 30 seconds when active
2. Identifies **open networks** (no password = potential evil portal)
3. Open networks are prime candidates for phishing attacks

### Counter-Attack
1. Connects to detected portal
2. Sends 25 POST requests to common endpoints:
   - `/login`, `/auth`, `/signin`, `/portal`, `/admin`
3. Each request contains random fake credentials
4. Username: `hacker####` (random number)
5. Password & Email: Random insult from 420-insult database
6. Floods portal with junk data to waste attacker's time

### Smart Detection
- Tracks attacked portals
- Re-scans to verify if portal disappeared
- Shows **"PORTAL NUKED!"** only when portal actually goes offline

---

## 📝 Example Insults

All 420 insults are:
- ✅ Safe for all audiences
- ✅ No hate speech or slurs
- ✅ Tech/security themed
- ✅ Creative and entertaining

Sample roasts:
```
"Your encryption is weaker than your password"
"You're a script kiddie with expired motivation"
"Your backdoor is closed permanently"
"Even password123 would reject you"
"You're the human equivalent of a corrupted file"
"Your best exploit is wasting my time"
```

Want to add your own? Edit `src/main.cpp` line 20!

---

## ⚖️ Legal & Ethics

### ⚠️ IMPORTANT DISCLAIMER

This software is for **EDUCATIONAL and DEFENSIVE purposes only.**

### ✅ Acceptable Use
- Personal WiFi security awareness
- Educational demonstrations in controlled environments
- Security research with proper authorization
- Defensive measures against evil portals
- Raising awareness about WiFi security risks

### ❌ Prohibited Use
- Attacking networks without explicit permission
- Disrupting public or private WiFi services
- Unauthorized access to computer systems
- Any illegal activities under applicable laws

### 📜 Legal Notice
**Unauthorized access to computer networks is illegal** in most jurisdictions:
- 🇺🇸 USA: Computer Fraud and Abuse Act (CFAA)
- 🇪🇺 EU: Network and Information Security Directive
- 🇬🇧 UK: Computer Misuse Act
- And similar laws worldwide

**By using this software, you agree to:**
1. Use it legally and ethically
2. Take full responsibility for your actions
3. Comply with all applicable laws
4. Not hold the authors liable for any consequences

**When in doubt, don't use it without permission!**

---

## 🐛 Troubleshooting

<details>
<summary><b>Device won't connect to computer</b></summary>

- Try a different USB-C cable (must support data transfer)
- Try a different USB port on your computer
- Hold the reset button while connecting
- Check if drivers are installed (CP210x or CH340)
</details>

<details>
<summary><b>Flashing failed or timeout</b></summary>

- Lower baud rate: Use `115200` instead of `921600`
- Erase flash first: `esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash`
- Make sure you're using the MERGED.bin file
- Try holding reset button during flash
</details>

<details>
<summary><b>Portal Killer not detecting networks</b></summary>

- Press A button to ensure it's activated (should say "ACTIVE")
- Check that you're in range of open WiFi networks
- Wait 30 seconds for first scan
- Make sure WiFi isn't disabled in your area
</details>

<details>
<summary><b>Screen won't wake up</b></summary>

- Press any button (A or B)
- Check if Screen Timeout is enabled in settings
- If Shake to Wake enabled, try shaking device harder
- Adjust shake sensitivity in settings (try "Light")
</details>

<details>
<summary><b>Clock shows wrong time</b></summary>

- Hold B button for 1 second to open menu
- Select "Set Time" with A button
- Use B to adjust hours, press A to move to minutes
- Use B to adjust minutes, press A to save
</details>

---

## 📚 Documentation

| Document | Description |
|----------|-------------|
| [Quick Start Guide](docs/QUICK_START.md) | 5-minute setup walkthrough |
| [Flashing Instructions](docs/FLASHING.md) | Detailed firmware installation |
| [Changelog](docs/CHANGELOG.md) | Complete version history |
| [License](LICENSE) | MIT License with ethical guidelines |

---

## 🔄 Version History

### v1.0.8 (Current - November 15, 2024)
- ✨ Clock color customization (8 colors)
- 🎨 Live color preview in menu
- 🔵 "PORTAL DODGED!" changed to blue

### v1.0.7
- 📱 Shake sensitivity settings (Light/Medium/Heavy)
- ⚡ Adjustable wake threshold

### v1.0.6
- 🎛️ Settings menu system (Hold B button)
- ⏰ Set time function
- 💤 Screen timeout with adjustable timing
- 🔔 Shake to wake feature
- ⚡ "DESTROYED" changed to "NUKED!"

### v1.0.5
- 🕐 Clock always visible (unified display)
- 📊 Portal status shown below clock

### v1.0.4
- 🎲 25 different random insults per attack
- ✅ "PORTAL NUKED!" only when portal actually disappears
- 🔀 True random selection with hardware RNG

### v1.0.3
- 🔥 Expanded to 420 total insults

[See full changelog](docs/CHANGELOG.md)

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

- 🐛 Report bugs via [Issues](../../issues)
- 💡 Suggest features or improvements
- 🎨 Add more creative insults
- 📖 Improve documentation
- 🔧 Submit pull requests

**Adding insults:**
1. Edit `src/main.cpp` line 20 (dataThiefInsults array)
2. Keep them tech/security themed
3. No hate speech or offensive content
4. Submit a PR!

---

## 🙏 Credits & Thanks

**Built with:**
- [M5Stack](https://m5stack.com/) - Excellent ESP32 hardware
- [ESP32 Arduino](https://github.com/espressif/arduino-esp32) - Framework
- [PlatformIO](https://platformio.org/) - Build system

**Inspired by:**
- WiFi security research
- Defensive security practices
- Evil portal awareness initiatives

**Special thanks to the maker community!**

---

## 📜 License

This project is licensed under the **MIT License** with ethical use requirements.

See [LICENSE](LICENSE) file for full details.

**TL;DR:**
- ✅ Free to use, modify, and distribute
- ✅ Commercial use allowed
- ⚠️ Must use ethically and legally
- ⚠️ Authors not liable for misuse
- ⚠️ Use at your own risk

---

## 📧 Support

- 📖 Documentation: Check the [docs](docs/) folder
- 🐛 Issues: Open an [issue](../../issues)
- 💬 Discussions: Start a [discussion](../../discussions)
- 📧 Email: [Your email or remove this line]

---

## 🌟 Star This Project!

If you find Portal Killer Watch useful:
- ⭐ Star this repository
- 🍴 Fork it for your own modifications
- 📢 Share it with the security community
- 🐦 Tweet about it with #PortalKillerWatch

---

## 🎯 Quick Links

- **Latest Release:** [v1.0.8](../../releases/latest)
- **Firmware Download:** [PortalHaterv1.0.8-MERGED.bin](../../releases/latest)
- **Documentation:** [docs/](docs/)
- **Source Code:** [src/main.cpp](src/main.cpp)
- **Issues:** [Report a bug](../../issues)

---

<div align="center">

**Made with ❤️ for the cybersecurity community**

**Use responsibly. Stay legal. Be ethical.** ⚖️

**Happy portal hunting!** 🎯🔥

</div>

---

## 📊 Project Stats

![GitHub release (latest by date)](https://img.shields.io/github/v/release/yourusername/PortalKillerWatch)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/yourusername/PortalKillerWatch)
![GitHub last commit](https://img.shields.io/github/last-commit/yourusername/PortalKillerWatch)
![GitHub issues](https://img.shields.io/github/issues/yourusername/PortalKillerWatch)

**Development:** Single evening build (November 15, 2024)  
**Total Versions:** 8 releases  
**Features:** 15+ major features  
**Code:** ~1100 lines  
**Insults:** 420 unique messages  
**Status:** Feature Complete ✓

---

*Portal Killer Watch - Defending against evil portals, one insult at a time.* 🛡️
