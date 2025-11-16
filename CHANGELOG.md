# Portal Killer Watch - Version History & Changelog

## Current Release: v1.0.8 (November 15, 2024)

---

## v1.0.8 - Final Release 🎉
**Released:** November 15, 2024

### New Features
- ✨ **Clock Color Customization** - Choose from 8 colors for the clock display
- 🎨 **Color Options:** Red, Orange, Green, Cyan, Blue, Magenta, Yellow, White
- 👀 **Live Preview** - See color before saving in menu
- 🔵 **Changed "PORTAL DODGED!" to Blue** for better visual distinction

### Improvements
- Improved menu organization with 5th option (Clock Color)
- Enhanced visual feedback in color picker
- Better color contrast for readability

### Files
- Firmware: `PortalHaterv1.0.8-MERGED.bin`
- MD5: `2c7a994a1b0decabf604b27af5cfc82a`

---

## v1.0.7 - Shake Sensitivity
**Released:** November 15, 2024

### New Features
- 📱 **Shake Sensitivity Settings** - Three levels: Light, Medium, Heavy
- ⚡ **Adjustable Wake Threshold** - Easier wake-up with Light setting
- 🎚️ **Customizable Experience** - Choose shake intensity that works for you

### Technical
- Thresholds: 0.8g (Light), 1.2g (Medium), 1.5g (Heavy)
- IMU accelerometer integration
- Menu option for sensitivity adjustment

### Files
- Firmware: `PortalHaterv1.0.7-MERGED.bin`
- MD5: `5fb0b5a09ddb655b5e0b1dada7c7fd95`

---

## v1.0.6 - Settings Menu System
**Released:** November 15, 2024

### Major Features
- 🎛️ **Settings Menu** - Hold B button (1 sec) to access
- ⏰ **Set Time Function** - Adjust hours and minutes
- 💤 **Screen Timeout** - Enable/disable with adjustable timing (10s-5min)
- 🔔 **Shake to Wake** - Toggle feature on/off
- ⚡ **Changed "DESTROYED" to "NUKED!"** - More impactful messaging

### Menu Options
1. Set Time (with RTC save)
2. Screen Timeout (5 duration options)
3. Shake to Wake (enable/disable)
4. Exit Menu

### Improvements
- Long-press detection for B button
- Activity tracking for timeout
- IMU integration for shake detection
- Non-blocking menu system

### Files
- Firmware: `PortalHaterv1.0.6-MERGED.bin`
- MD5: `ef0eb29e59190973108c1cf075411a50`

---

## v1.0.5 - Always-On Clock Display
**Released:** November 15, 2024

### Major Changes
- 🕐 **Clock Always Visible** - No more screen switching
- 📊 **Unified Display** - Clock on top, portal status below
- 🎯 **Improved UX** - All info on one screen
- 📐 **Surgical Display Changes** - No logic modifications

### Technical
- Removed separate portal killer UI screen
- Clock positioned at top 1/3 of display
- Portal status in bottom 2/3
- Only clear sections, not full screen
- Background scanning with foreground clock

### Files
- Firmware: `PortalHaterv1.0.5-MERGED.bin`
- MD5: `696beed711f82c37a2951dbe327323ed`

---

## v1.0.4 - Random Message Enhancement
**Released:** November 15, 2024

### New Features
- 🎲 **25 Different Random Insults** - Each message unique
- ✅ **"PORTAL NUKED!" Only When Actually Gone** - Smart detection
- 🔀 **True Random Selection** - ESP32 hardware RNG seeding

### Bug Fixes
- Fixed repeated insult issue (was sending same message 25 times)
- Fixed premature "DESTROYED" message
- Added proper substring bounds checking

### Technical
- `esp_random()` for seed generation
- Portal tracking with `lastAttackedPortal`
- Rescan verification before showing "NUKED"
- Per-message random selection in loop

### Files
- Firmware: `PortalHaterv1.0.4-MERGED.bin`
- MD5: `ef0eb29e59190973108c1cf075411a50`

---

## v1.0.3 - Insult Expansion
**Released:** November 15, 2024

### Features
- 🔥 **420 Total Insults** - Massive expansion from ~100 to 420
- 📝 **Three Categories:**
  - "Get a New Hobby" deterrents
  - System crash vibes
  - Nuclear-level roasts
- ✅ All safe, no hate speech, tech-focused

### Files
- Firmware: `PortalHaterv1.0.3-MERGED.bin`
- MD5: `c3f2e681cd115fd884283ddfd2c28111`

---

## v1.0.2 - Insult Database Growth
**Released:** November 15, 2024

### Features
- Added 75+ new "Get a New Hobby" insults
- Added 75+ failure energy insults
- Total: ~200 insults

---

## v1.0.1 - Core Functionality
**Released:** November 15, 2024

### Features
- ⚡ Portal scanning every 30 seconds
- 🎯 Automatic attack on open networks
- 💬 ~100 data thief insults
- 📊 Kill count tracking
- 🔆 Brightness control (B button)

---

## v1.0.0 - Initial Release
**Released:** November 15, 2024

### Core Features
- ESP32-based M5StickC Plus2 firmware
- WiFi portal detection
- HTTP endpoint spamming
- Basic insult database
- Clock display
- Portal killer toggle (A button)

---

## Development Stats

### Final Metrics (v1.0.8)
- **Insults:** 420 unique messages
- **Code Size:** 42KB main.cpp
- **RAM Usage:** 16.9% (55,480 bytes)
- **Flash Usage:** 81.0% (1,061,865 bytes)
- **Menu Items:** 5 (Set Time, Timeout, Shake, Color, Exit)
- **Clock Colors:** 8 options
- **Development Time:** 1 evening (November 15, 2024)

### Version Count
- **Major Releases:** 8 (v1.0.1 through v1.0.8)
- **Features Added:** 15+ major features
- **Bug Fixes:** 5+ critical fixes
- **Lines of Code:** ~1100+ lines

---

## Upgrade Path

### From Any Version to v1.0.8
1. Download `PortalHaterv1.0.8-MERGED.bin`
2. Flash using M5Burner or esptool.py
3. All settings reset (must reconfigure time, etc.)
4. Enjoy new features!

### Backwards Compatibility
- Settings not preserved between versions
- Must reconfigure after upgrade
- All core functionality remains compatible

---

## Known Issues

### Current (v1.0.8)
- None reported

### Fixed Issues
- ✅ Repeated insults (fixed in v1.0.4)
- ✅ Premature "DESTROYED" message (fixed in v1.0.4)
- ✅ Screen flickering during attacks (fixed in v1.0.5)
- ✅ Difficult shake wake (fixed in v1.0.7)

---

## Future Considerations

### Potential Features (Not Planned)
- OTA updates
- WiFi credential storage
- Bluetooth integration
- Multi-language support
- Custom insult upload
- Statistics tracking
- Web interface

### Status
Project is feature-complete as of v1.0.8.
No further major updates planned.
Community contributions welcome!

---

## Credits

**Development:** November 15, 2024
**Platform:** M5StickC Plus2 (ESP32)
**Framework:** Arduino + PlatformIO
**Inspiration:** Defensive WiFi security, evil portal awareness

---

## License

MIT License with ethical use requirements.
See LICENSE file for full details.

**Use responsibly. Stay legal. Be ethical.** ⚖️
