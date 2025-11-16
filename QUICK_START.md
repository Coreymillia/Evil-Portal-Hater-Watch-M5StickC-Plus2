# Portal Killer Watch - Quick Start Guide

## 📦 What You Need
- M5StickC Plus2 device
- USB-C cable (data transfer capable)
- Computer with M5Burner or esptool.py

---

## ⚡ 5-Minute Setup

### 1. Flash Firmware
**Easiest Method - M5Burner:**
1. Download M5Burner from https://docs.m5stack.com/en/download
2. Connect M5StickC Plus2 via USB
3. Open M5Burner and click "Burn"
4. Select `firmware/PortalHaterv1.0.8-MERGED.bin`
5. Wait 30 seconds for flash to complete

**Alternative - Command Line:**
```bash
pip install esptool
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 \
  write_flash 0x0 firmware/PortalHaterv1.0.8-MERGED.bin
```

### 2. First Boot
Device will show:
- "PORTAL KILLER WATCH" splash screen
- Current time (may be incorrect)
- "Portal Killer: OFF" status

### 3. Set the Time
1. **Hold B button** for 1 second (opens menu)
2. Navigate to "Set Time" with B button
3. Press A to select
4. Use B to change hours, press A to move to minutes
5. Use B to change minutes, press A to save

### 4. Start Hunting Portals
1. **Press A button** - activates Portal Killer mode
2. Watch displays "PORTAL KILLER: ACTIVE"
3. Automatically scans every 30 seconds
4. When portal detected:
   - Yellow = "PORTAL ATTACKED!" (connected and attacking)
   - Blue = "PORTAL DODGED!" (couldn't connect)
   - Green = "PORTAL NUKED!" (portal disappeared)

---

## 🎮 Button Guide

### Button A (Bottom Left)
- **Single Press:** Toggle Portal Killer ON/OFF
- When menu open: Select/Confirm

### Button B (Top Right)
- **Single Press:** Cycle brightness (11 levels)
- **Hold 1 Second:** Open Settings menu
- When menu open: Navigate options

### Power Button (Side)
- **Single Press:** Wake from sleep
- **Double Press:** Reset device
- **Hold 6 Seconds:** Power off

---

## ⚙️ Settings Menu

**Access:** Hold B button for 1 second

### 1. Set Time
- Adjust hours and minutes
- Saves to real-time clock (RTC)

### 2. Screen Timeout
- Enable/disable auto-sleep
- Options: 10s, 30s, 60s, 2min, 5min

### 3. Shake to Wake
- Enable shake detection to wake screen
- Sensitivity: Light (easy) / Medium / Heavy (hard shake)

### 4. Clock Color
- Choose from 8 colors
- Live preview shown
- Colors: Red, Orange, Green, Cyan, Blue, Magenta, Yellow, White

### 5. Exit Menu
- Return to clock display

---

## 🎯 How It Works

### Portal Detection
1. Device scans for open WiFi networks
2. Open networks = potential evil portals
3. When found, automatically initiates counter-attack

### Counter-Attack
1. Connects to detected portal
2. Sends 25 different fake credentials to common endpoints:
   - /login
   - /auth
   - /signin
   - /portal
   - /admin
3. Each message contains random insult from 420-insult database
4. Floods portal with junk data to waste attacker's time

### Smart Responses
- **PORTAL ATTACKED! (Yellow)** - Successfully connected and spammed
- **PORTAL DODGED! (Blue)** - Couldn't connect (portal rejected)
- **PORTAL NUKED! (Green)** - Portal disappeared after attack (success!)

---

## 💡 Tips & Best Practices

### Battery Life
- Enable Screen Timeout (30-60 seconds recommended)
- Enable Shake to Wake for easy screen wake
- Lower brightness when not needed

### Portal Scanning
- Scanning runs every 30 seconds when active
- Press A to toggle on/off as needed
- Kill count persists while active

### Real-World Use
- Works great at coffee shops, airports, hotels
- Detects suspicious open networks
- Helps protect against WiFi phishing
- Educational tool for security awareness

### What NOT to Do
- Don't use on networks you don't own without permission
- Don't use to disrupt legitimate services
- Stay legal and ethical - this is a defensive tool

---

## 🔧 Troubleshooting

### Clock Time Wrong
- Hold B → Select "Set Time" → Adjust with A/B buttons

### Screen Won't Wake
- Press any button
- Check Screen Timeout is enabled
- Try Shake to Wake if enabled

### Portal Killer Not Scanning
- Press A to ensure it's activated
- Check for open WiFi networks nearby
- Wait 30 seconds for first scan

### Display Too Bright/Dim
- Tap B button to cycle through 11 brightness levels

---

## 📊 Status Indicators

### Top Display (Always Visible)
```
12:34:56          ← Clock (customizable color)
PORTAL KILLER: ACTIVE  ← Status (or OFF)
Kills: 5          ← Portal attack count
Scanning...       ← Current activity
```

### Bottom Display
```
A:Off  B:Bright   ← Button hints
```

---

## 🎓 Understanding the Insults

All 420 insults are:
- ✅ Safe for all audiences
- ✅ No hate speech
- ✅ Tech/security themed
- ✅ Focused on roasting bad security practices
- ✅ Creative and entertaining

Examples:
- "Your encryption is weaker than your password"
- "You're a script kiddie with expired motivation"
- "Your backdoor is closed permanently"

---

## 📱 Daily Use Scenarios

### Scenario 1: Coffee Shop Protection
1. Walk into coffee shop
2. Press A to activate Portal Killer
3. Watch detects suspicious open "Free WiFi" network
4. Device automatically attacks and warns you
5. You know to avoid that network!

### Scenario 2: Airport Security
1. Activate at airport
2. Multiple open networks detected
3. Portal Killer floods them with fake data
4. Legitimate networks (with password) ignored
5. Data thieves get junk, you stay safe

### Scenario 3: Hotel WiFi Check
1. Check in to hotel
2. Activate Portal Killer
3. Scan for suspicious "Guest WiFi" copies
4. Attack any fake portals
5. Connect only to official hotel network

---

## 🚀 You're Ready!

Your Portal Killer Watch is now set up and ready to hunt!

**Remember:**
- Use it legally and ethically
- It's a defensive security tool
- Help protect yourself and raise awareness
- Have fun with those insults! 😎

**Stay safe out there, portal hunter!** 🎯

---

## Need More Help?

📖 Full README: See README.md for complete documentation
🔧 Flashing Issues: See FLASHING.md for detailed instructions
⚖️ Legal Info: See LICENSE for terms and disclaimers
💻 Build from Source: See source/ folder for development

GitHub: [Your Repo URL Here]
