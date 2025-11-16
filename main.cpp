// Portal Killer Watch - Discrete Portal Defense with Savage Insults
// A watch that roasts data thieves and attacks evil portals
#include <M5StickCPlus2.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Clock display settings
bool use24HourFormat = true;
int brightnessLevel = 8;
const int BRIGHTNESS_VALUES[] = {25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 255};
int clockColorIndex = 2; // Default GREEN
const uint16_t CLOCK_COLORS[] = {RED, ORANGE, GREEN, CYAN, BLUE, MAGENTA, YELLOW, WHITE};
const char* CLOCK_COLOR_NAMES[] = {"Red", "Orange", "Green", "Cyan", "Blue", "Magenta", "Yellow", "White"};
const int NUM_CLOCK_COLORS = 8;

// Screen timeout settings
bool screenTimeoutEnabled = false;
int screenTimeoutSeconds = 30;
unsigned long lastActivityTime = 0;
bool screenOff = false;

// Shake to wake settings
bool shakeToWakeEnabled = false;
int shakeSensitivity = 2; // 0=Light, 1=Medium, 2=Heavy
const float SHAKE_THRESHOLDS[] = {0.8, 1.2, 1.5}; // Acceleration thresholds

// Menu system
bool inMenu = false;
int menuSelection = 0;
const int MENU_ITEMS = 5; // Set Time, Screen Timeout, Shake to Wake, Clock Color, Exit
unsigned long btnBPressTime = 0;
const unsigned long LONG_PRESS_TIME = 1000; // 1 second hold

// Portal killer state
bool portalKillerActive = false;
bool scanningForPortals = false;
int portalKillCount = 0;
unsigned long lastScanTime = 0;
const unsigned long SCAN_INTERVAL = 30000; // Scan every 30 seconds when active
String lastAttackedPortal = ""; // Track last attacked portal

// Insult messages targeting data thieves and portal hackers
const String dataThiefInsults[] = {
    "Caught ya slippin, fool!",
    "Your portal is garbage!",
    "Stealing data? Pathetic.",
    "Your encryption is weak!",
    "Portal hacker detected!",
    "You're a script kiddie!",
    "Your phishing sucks!",
    "Amateur hour detected!",
    "Your portal is toast!",
    "Your evil portal died!",
    "Packet sniffer noob!",
    "Your honeypot stinks!",
    "Man-in-middle fail!",
    "DNS spoofing amateur!",
    "Your RAT got caught!",
    "Keylogger detected!",
    "Your botnet is dead!",
    "Credential thief fail!",
    "Your rootkit is weak!",
    "Session hijack fail!",
    "Your malware is old!",
    "Zero-day? More like zero-brain!",
    "SQL injection noob!",
    "XSS attack? Pathetic!",
    "Your DDoS is weak!",
    "Brute force amateur!",
    "Your payload failed!",
    "Ransomware wannabe!",
    "Your trojan is obvious!",
    "Spyware fail detected!",
    "Your backdoor is closed!",
    "Exploit kit trash!",
    "Your crypto is broken!",
    "Password stealer fail!",
    "Your phish got caught!",
    "Evil twin AP detected!",
    "Your MITM died!",
    "Rogue AP shutdown!",
    "Your capture portal failed!",
    "Fake hotspot destroyed!",
    "Your portal got wrecked!",
    "Data exfil blocked!",
    "Your C2 server died!",
    "Packet injection fail!",
    "Your sniffer is blind!",
    "ARP poisoning fail!",
    "Your beacon spam failed!",
    "Deauth attack blocked!",
    "Your WiFi pineapple died!",
    "Portal credentials fake!",
    "Your harvest failed!",
    "Social engineering fail!",
    "Your portal is burning!",
    "Credential harvesting blocked!",
    "Your captive portal died!",
    "Login stealer detected!",
    "Your fake AP is dead!",
    "Network infiltration fail!",
    "Your data grab failed!",
    "Information thief blocked!",
    "Your portal got nuked!",
    "Access point imposter!",
    "Your WiFi trap sprung!",
    "Man-in-browser fail!",
    "Your session steal failed!",
    "Cookie theft blocked!",
    "Your portal is toast!",
    "Authentication bypass fail!",
    "Your evil portal burned!",
    "Credential logger dead!",
    "Your WiFi attack failed!",
    "Portal defense active!",
    "Your network trap closed!",
    "Data theft prevented!",
    "Your phishing died!",
    "Portal spam incoming!",
    "Your harvest is over!",
    "Fake login destroyed!",
    "Your portal got flooded!",
    "Credential theft blocked!",
    "Your evil WiFi died!",
    "Portal attack launched!",
    "Your trap got trapped!",
    "Data stealer defeated!",
    "Your portal is spam!",
    "Network attacker blocked!",
    "Your WiFi scam failed!",
    "Portal defender active!",
    "Your data grab died!",
    "Evil portal eliminated!",
    "Your network hack failed!",
    "Portal killer active!",
    "Your WiFi trick failed!",
    "Data protection active!",
    "Your portal is history!",
    "Caught you snooping — congrats on failing at crime and life simultaneously.",
    "Wow, you pick locks about as well as you pick hobbies.",
    "You're not a hacker — you're a walking tutorial on bad decisions.",
    "Your skills are so weak even auto-fill feels sorry for you.",
    "If this is your career path, it's time to turn around. Fast.",
    "You're about three mistakes away from starring in a cautionary tale.",
    "Stealing data? Buddy, you can't even steal a nap.",
    "Please uninstall yourself from the internet.",
    "You break into systems like a toddler breaks into cookies — messy and obvious.",
    "Your hacking attempt just got outsmarted by a toaster.",
    "You're the reason cybersecurity professionals sleep well.",
    "If incompetence were a felony, you'd finally succeed at something.",
    "This attempt was so weak, it made my antivirus yawn.",
    "You're basically a screensaver pretending to be dangerous.",
    "Find a new hobby — this one requires skill.",
    "Your whole technique feels like a last-minute science project.",
    "You break more rules than you break encryption.",
    "Your keyboard begged me to stop you.",
    "You're the bicycle thief of cyberspace.",
    "You couldn't brute-force your way out of a paper bag.",
    "Your approach screams 'I watched one YouTube tutorial.'",
    "You're a bootleg villain with discount skills.",
    "Your digital footprint has 'amateur hour' written all over it.",
    "I've met CAPTCHA bots with more finesse.",
    "You're why cybersecurity budgets keep going up — thanks for the job security.",
    "This breach attempt came pre-failed.",
    "Your skillset is the reason training wheels exist.",
    "Please go touch grass before touching another login form.",
    "Even malware would be embarrassed to be seen with you.",
    "This attempt had all the grace of a dropped sandwich.",
    "You hack like you live: without a plan.",
    "You're the NPC of cybercrime — predictable and useless.",
    "Even the bugs in this system are laughing at you.",
    "Your best exploit is wasting my time.",
    "You're the participation trophy of cybercriminals.",
    "This intrusion attempt was sponsored by Failure™.",
    "If brains were bandwidth, you'd be offline.",
    "Try knitting. Literally anything else would suit you better.",
    "You're the reason tutorials start with 'Don't do this.'",
    "Your attempt was denied due to lack of effort and dignity.",
    "I've seen fortune cookies with better strategies.",
    "You're a threat to no one but yourself.",
    "Breaking news: local wannabe hacker defeated by basic security.",
    "You're the human equivalent of a weak password.",
    "Your entire skillset should come with a warning label.",
    "You're one wrong click away from infecting yourself.",
    "This attempt had all the stealth of a marching band.",
    "You can't even spell 'breach' without autocorrect.",
    "You're the knock-knock joke of cybercrime.",
    "If stupidity was encrypted, you'd finally crack something.",
    "Your technique is older than your excuses.",
    "Your best hack was convincing yourself you can hack.",
    "You're not a threat — you're a training dummy.",
    "If failure had a user ID, it would be yours.",
    "The only thing you've breached is your own dignity.",
    "You're a glitch in the tutorial level.",
    "Your persistence is impressive; your results are not.",
    "You're proof that copy-pasting commands is not a personality.",
    "My logs are laughing at you.",
    "Your effort-to-competence ratio is tragic.",
    "You're the junk folder of cybercriminals.",
    "Breaking into systems isn't for everyone. Especially you.",
    "You're the CAPTCHA equivalent of 'try again later.'",
    "Your digital fingerprints smell like desperation.",
    "You navigate cyberspace like a Roomba in a hurricane.",
    "This attempt is being saved for the blooper reel.",
    "You're the practice round, not the boss fight.",
    "Your ambition far exceeds your ability.",
    "You're about as stealthy as a car alarm.",
    "You're the weakest link — and the chain knows it.",
    "Your tools are outdated, much like your judgment.",
    "You're the melted ice cream cone of cybercrime.",
    "You're one Google search away from discovering this isn't for you.",
    "Thanks for the entertainment, failure levels like yours are rare.",
    "Final verdict: find a new hobby, champ — this one is beating you.",
    "Your intrusion attempt was so weak the firewall didn't even stretch first.",
    "You're about as threatening as a rubber spoon.",
    "This hack attempt belongs in a museum labeled 'Why It Failed.'",
    "My logs are keeping this for comedy night.",
    "You type like you're wearing oven mitts.",
    "Your idea of stealth is shouting 'I'M SNEAKING!'",
    "Congratulations, you've been defeated by basic math and common sense.",
    "You couldn't bypass a revolving door.",
    "This was so predictable even fortune cookies saw it coming.",
    "Your best exploit is giving cybersecurity analysts something to laugh at.",
    "You're the kiddie-pool version of a cyber threat.",
    "Even a broken clock hacks better than you.",
    "You're a minor inconvenience pretending to be a menace.",
    "Your code smells like fear and stack overflow threads.",
    "If effort was competence, you'd still be failing.",
    "You're the tutorial boss that everyone beats by accident.",
    "Breaking news: local amateur defeated by login screen.",
    "You fumble through cyberspace like spilled spaghetti.",
    "I've seen toddlers with more coherent inputs.",
    "Your hack attempt expired before it even launched.",
    "You're a discount villain with bargain-bin tactics.",
    "You couldn't break encryption even if it handed you the key.",
    "Your persistence is admirable; your results are tragic.",
    "Even your malware ghosted you.",
    "You're the bootleg version of a cybercriminal.",
    "You're a 404 error wearing a hoodie.",
    "If cluelessness was currency, you'd be rich.",
    "You're not a threat — you're a screensaver with delusions of grandeur.",
    "Your technique is so outdated it runs on nostalgia.",
    "You approach security like it's a vending machine.",
    "This attempt has been auto-filed under 'LOL.'",
    "Your keyboard deserves a better owner.",
    "You hack like you cook: burnt, sloppy, and barely edible.",
    "Your threat level: lukewarm soup.",
    "You couldn't exploit a wet paper bag.",
    "You're a participation trophy of cybercrime.",
    "Your entire strategy was a polite request to fail.",
    "Even password123 would reject you.",
    "You're the cyber equivalent of a tricycle with one wheel.",
    "This is the kind of attempt antivirus software uses for warmups.",
    "You're a walking, talking 'access denied.'",
    "Your best vector is disappointing people.",
    "You're a loading bar stuck at 2%.",
    "This intrusion was powered by hope and zero skill.",
    "You're a glitch in human form.",
    "Cybersecurity didn't notice you — the janitor did.",
    "You're a knockoff hacker with expired motivation.",
    "You hack like a pigeon plays chess.",
    "I've seen spam emails with more finesse.",
    "Your effort was high; your execution was subterranean.",
    "You fumbled the bag, the room, the whole building.",
    "You're the digital equivalent of stepping on a LEGO.",
    "If failure had a logo, it would be you.",
    "Your strategy is the cybersecurity version of 'winging it.'",
    "You missed the mark so hard the mark sent condolences.",
    "You couldn't compromise a cardboard box.",
    "Your plan was so transparent it didn't require decryption.",
    "You're the NPC who thinks they're the final boss.",
    "Your intrusion attempt tripped over its own shoelaces.",
    "You're the practice dummy with fragile confidence.",
    "Your execution was a crime. Against efficiency.",
    "You hack like you're afraid of success.",
    "Your entire playbook is a sticky note that says 'try?'",
    "You're a mild inconvenience at best.",
    "This hack attempt had the structural integrity of wet tissue.",
    "You are the lag spike of human potential.",
    "Your technique was so obvious even the toaster saw it coming.",
    "Trying to hack this was your third mistake today.",
    "You're a floppy disk pretending to be a threat.",
    "Your digital fingerprint looks like a cry for help.",
    "Even brute-force attacks want nothing to do with you.",
    "You hack like you're being timed — and losing.",
    "Your incompetence has reached legendary status.",
    "You're the final boss of disappointment.",
    "Result: You lose. Again. Maybe try sudoku?",
    "Your entire personality feels like a software bug they never bothered to patch.",
    "You're the reason people double-check if the door is locked — not from fear, from embarrassment.",
    "Your existence is a long-running inside joke the universe forgot to explain.",
    "You function like a broken captcha — annoying and unsolvable.",
    "Even your shadow distances itself from your decisions.",
    "You have the energy of a wet firework fired upside down.",
    "If confidence was based on results, you'd be invisible.",
    "Your competence is in beta. Permanent beta.",
    "You are the final boss of wasted potential.",
    "Your thought process requires a parental advisory warning.",
    "You are proof that not every experiment needs to be repeated.",
    "Your brain runs on trial versions with watermark restrictions.",
    "Your ambition and your ability filed for divorce.",
    "You're a motivational poster in reverse.",
    "Your problem-solving skills come pre-broken.",
    "Your life is a software update that keeps failing at 99%.",
    "You bring the same energy as an unplugged router.",
    "Your best ideas sound like rejected spam subject lines.",
    "You are a loading screen that never finishes.",
    "Your presence feels like a pop-up ad nobody asked for.",
    "Even autocorrect refuses to fix you.",
    "Your initiative left the chat years ago.",
    "You could trip over wireless internet.",
    "Your brain has buffering issues.",
    "You couldn't navigate a straight line with GPS, a map, and a guide dog.",
    "Your decisions are what happens when common sense calls in sick.",
    "You are the human equivalent of a corrupted file.",
    "Even your excuses need excuses.",
    "You have the internal stability of a folding lawn chair in a hurricane.",
    "Your problem-solving skills file for bankruptcy daily.",
    "You're a participation trophy with self-esteem issues.",
    "Your logic is the reason patience was invented.",
    "You could lose a staring contest with a wall.",
    "You are the plot twist no one wanted and everyone saw coming.",
    "Your ideas belong in time-out forever.",
    "You are a glitch pretending to be a feature.",
    "Your determination has the lifespan of a soap bubble.",
    "You're the tutorial mode for bad choices.",
    "Your common sense evaporates under light questioning.",
    "You bring the same intensity as a lukewarm handshake.",
    "You are the reason warning labels exist.",
    "Your skill level is the digital equivalent of dial-up.",
    "You are a user error given walking privileges.",
    "Your confidence is wildly out of sync with your output.",
    "You generate disappointment at factory-setting efficiency.",
    "You fail with such style it should be taught in art class.",
    "Your brain runs on whatever is left after the battery icon turns red.",
    "You are the aftertaste of a bad idea.",
    "Your intelligence pings the server and gets 'no response.'",
    "You're the final draft of a mistake.",
    "Your planning skills are a public safety concern.",
    "You are an unskippable ad in human form.",
    "Your thinking is the spiritual successor to static noise.",
    "You're the boss battle players beat accidentally.",
    "Your best argument has a plot hole the size of your confidence.",
    "You are the patch note that says 'miscellaneous fixes' — meaningless and forgettable.",
    "Your efforts collapse under the weight of their own mediocrity.",
    "You contribute to conversations like a dropped call.",
    "Your judgment is powered by outdated firmware.",
    "You are the moral equivalent of clicking the wrong link.",
    "Your success rate is what statisticians call 'statistically amusing.'",
    "You break down faster than cheap headphones.",
    "Your entire vibe feels auto-generated on low settings.",
    "You are the practice round nobody takes seriously.",
    "Your decision-making is a spectator sport.",
    "You are the slowest-loading part of the human experience.",
    "You're the Easter egg no one bothered hiding.",
    "Your aspirations need tech support.",
    "You bring the chaos of a missing semicolon.",
    "Your confidence is built on fictional backstory.",
    "You are the human version of a typo that somehow made it to print.",
    "Your thought process takes detours into dead ends.",
    "You have the intensity of a sleeping goldfish.",
    "You are the spiritual embodiment of 'not great, not terrible.'",
    "You are a cosmic reminder that not every process concludes successfully.",
    "Your existence feels like a loading error the universe forgot to fix.",
    "You have the unstoppable momentum of a paper airplane thrown in a hurricane.",
    "Your IQ called — it's filing for emancipation.",
    "You radiate the confidence of someone who doesn't realize the toaster is unplugged.",
    "You are the final stage of a failed experiment nobody documented.",
    "Your ideas hit the ground faster than bad Wi-Fi.",
    "You bring the emotional depth of a voicemail beep.",
    "You're the reason the progress bar stays at 0%.",
    "Your brain activity is the spiritual cousin of airplane mode.",
    "You generate confusion like it's renewable energy.",
    "You're a pop-up ad with legs and misplaced optimism.",
    "Your thought process is a maze with all the walls missing.",
    "You're the sequel nobody asked for and everyone regrets.",
    "Your best decisions are on backorder indefinitely.",
    "Your initiative is powered by a dead AA battery.",
    "You're a system crash pretending to be a reboot.",
    "Your reasoning is sponsored by random number generators.",
    "You think like the warning label on a cheap blender.",
    "You're a motivational speech in reverse.",
    "Your ideas should come with a 'return to sender' label.",
    "You're a smoke alarm with no battery and too much confidence.",
    "Your potential is trapped in a permanent maintenance window.",
    "If common sense was a currency, you'd be in debt.",
    "Your logic evaporates faster than spilled vodka.",
    "You're a corrupted save file with delusional ambitions.",
    "Your presence feels like lag on a boss fight.",
    "You're the blooper reel of human decision-making.",
    "Your brain takes coffee breaks during emergencies.",
    "You're a storm cloud that forgot how to rain.",
    "Your ideas crash harder than a bargain-bin drone.",
    "You're a low-resolution disappointment.",
    "Your confidence is wildly unlicensed.",
    "Your life is a tutorial level you keep failing.",
    "You bring the intensity of a paperclip in a thunderstorm.",
    "Your choices need a legal disclaimer.",
    "Your strategy is what happens when chaos gets tired.",
    "You are a cosmic hiccup in the timeline.",
    "Your competence fell off the map and took your dignity with it.",
    "You're a push notification nobody enables.",
    "Your plan was outdated before you thought of it.",
    "You're a factory-reset version of mediocrity.",
    "Your effort and your results haven't met yet.",
    "Your thinking is a speedrun of confusion.",
    "You're a spilled drink on the keyboard of life.",
    "Your goals need an exorcism.",
    "You're the cold fries of humanity.",
    "Your mind is running a background process called 'failure.'",
    "You bring the impact of a rubber hammer.",
    "Your decisions were handcrafted by poor judgment.",
    "You're the unplugged extension cord of ambition.",
    "Your attempts are so weak even gravity ignores them.",
    "You have the mental Wi-Fi strength of a basement from 1992.",
    "You're a glitch hoping to be a feature someday.",
    "Your skills are archived in a folder labeled 'why bother.'",
    "You couldn't shine even in a blackout.",
    "Your problem-solving skills were discontinued.",
    "You're the lag spike that ruins the raid.",
    "Your competence is a myth told around campfires.",
    "You are the error message that appears even when nothing is wrong.",
    "Your ambition is running on fumes and excuses.",
    "You're the boot sequence that freezes at startup.",
    "Your ideas should come with a hazard warning.",
    "You're a motivational poster rewritten by despair.",
    "Your intelligence is on a coffee break permanently.",
    "You're a rerun of a show that got canceled mid-season.",
    "Your presence is the human equivalent of low battery mode.",
    "Your failures have unionized.",
    "You are the distant cousin of bad decisions.",
    "Your purpose crashed and never restarted.",
    "You're a broken compass in a fog machine.",
    "Your thinking needs a software rollback.",
    "You bring the thrill of a muted alarm.",
    "Your existence is the universe's debugging session.",
    "You're the lost instruction manual for a product no one wanted.",
    "You are the cliffhanger that leads to cancellation.",
    "You're the ransomware nobody bothered to patch.",
    "Your ambition is a phishing email written in crayon.",
    "You're the human embodiment of a corrupted ZIP file.",
    "Your brain is running malware disguised as common sense.",
    "You're the Trojan horse that forgot to hide.",
    "Your logic is a denial-of-service attack on yourself.",
    "You're the lag spike that ruins every raid.",
    "Your ideas buffer forever and never load.",
    "You're the spinning wheel of disappointment.",
    "Your thought process is stuck in safe mode.",
    "You're the reboot nobody asked for.",
    "Your competence times out after 30 seconds.",
    "You're a password written on a sticky note.",
    "Your strategy is weaker than '1234.'",
    "You're the CAPTCHA nobody can solve because you make no sense.",
    "Your brain is a firewall with all the ports open.",
    "You're the expired SSL certificate of humanity.",
    "Your ideas leak faster than unencrypted data.",
    "You're the patch note that only adds bugs.",
    "Your existence is a failed penetration test.",
    "You're the exploit that crashes the tutorial level.",
    "Your confidence is a phishing scam with typos.",
    "You're the brute-force attempt that locks everyone out.",
    "Your presence is the human equivalent of spam mail.",
};
const int numInsults = sizeof(dataThiefInsults) / sizeof(dataThiefInsults[0]);

// Function prototypes
void drawClock();
void scanForEvilPortals();
void attackPortal(String ssid);
void displayMessage(String msg, uint16_t color = WHITE);
void drawMenu();
void handleMenuInput();
void setTimeMenu();
void screenTimeoutMenu();
void shakeToWakeMenu();
void clockColorMenu();
void updateActivity();

void setup() {
    M5.begin();
    Serial.begin(115200);
    
    // Seed random number generator for true randomness
    randomSeed(esp_random());
    
    M5.Lcd.setRotation(1);
    M5.Lcd.setBrightness(BRIGHTNESS_VALUES[brightnessLevel]);
    M5.Lcd.fillScreen(BLACK);
    
    // Startup message
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("PORTAL");
    M5.Lcd.setCursor(10, 40);
    M5.Lcd.println("KILLER");
    M5.Lcd.setCursor(10, 60);
    M5.Lcd.println("WATCH");
    
    delay(2000);
    M5.Lcd.fillScreen(BLACK);
    
    Serial.println("Portal Killer Watch Started");
    Serial.println("Button A: Toggle Portal Killer Mode");
    Serial.println("Button B: Brightness");
    
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void loop() {
    M5.update();
    
    auto dt = M5.Rtc.getDateTime();
    
    // Check for screen timeout
    if (screenTimeoutEnabled && !screenOff) {
        if (millis() - lastActivityTime > (screenTimeoutSeconds * 1000)) {
            M5.Lcd.setBrightness(0);
            screenOff = true;
        }
    }
    
    // Wake screen on any button press or shake
    if (screenOff) {
        if (M5.BtnA.wasPressed() || M5.BtnB.wasPressed()) {
            M5.Lcd.setBrightness(BRIGHTNESS_VALUES[brightnessLevel]);
            screenOff = false;
            updateActivity();
        } else if (shakeToWakeEnabled) {
            M5.Imu.update();
            auto data = M5.Imu.getImuData();
            if (abs(data.accel.y) > SHAKE_THRESHOLDS[shakeSensitivity]) {
                M5.Lcd.setBrightness(BRIGHTNESS_VALUES[brightnessLevel]);
                screenOff = false;
                updateActivity();
            }
        }
        delay(100);
        return; // Don't process other inputs when screen is off
    }
    
    // Track button B press for long press detection
    if (M5.BtnB.isPressed() && btnBPressTime == 0) {
        btnBPressTime = millis();
    }
    
    // Check for long press to enter menu
    if (M5.BtnB.isPressed() && btnBPressTime > 0) {
        if (millis() - btnBPressTime >= LONG_PRESS_TIME && !inMenu) {
            inMenu = true;
            menuSelection = 0;
            M5.Lcd.fillScreen(BLACK);
            updateActivity();
        }
    }
    
    // Reset button timer when released
    if (!M5.BtnB.isPressed() && btnBPressTime > 0) {
        // Short press = brightness (only if not in menu)
        if (!inMenu && (millis() - btnBPressTime) < LONG_PRESS_TIME) {
            brightnessLevel = (brightnessLevel + 1) % 11;
            M5.Lcd.setBrightness(BRIGHTNESS_VALUES[brightnessLevel]);
            updateActivity();
        }
        btnBPressTime = 0;
    }
    
    // Handle menu mode
    if (inMenu) {
        handleMenuInput();
        drawMenu();
        delay(100);
        return;
    }
    
    // Button A: Toggle Portal Killer Mode
    if (M5.BtnA.wasPressed()) {
        portalKillerActive = !portalKillerActive;
        M5.Lcd.fillScreen(BLACK);
        updateActivity();
        
        if (portalKillerActive) {
            displayMessage("PORTAL KILLER\nACTIVE!", RED);
            Serial.println("Portal Killer Mode: ACTIVE");
            lastScanTime = 0; // Force immediate scan
            portalKillCount = 0;
        } else {
            displayMessage("PORTAL KILLER\nOFF", GREEN);
            Serial.println("Portal Killer Mode: OFF");
        }
        delay(1500);
        M5.Lcd.fillScreen(BLACK);
    }
    
    // Portal scanning and attack logic
    if (portalKillerActive) {
        unsigned long now = millis();
        if (now - lastScanTime >= SCAN_INTERVAL) {
            scanForEvilPortals();
            lastScanTime = now;
        }
    }
    
    // Always draw clock (with portal status below if active)
    drawClock();
    
    delay(100);
}

void drawClock() {
    static int lastMinute = -1;
    auto dt = M5.Rtc.getDateTime();
    
    // Only clear screen on minute change when portal killer is OFF
    if (dt.time.minutes != lastMinute && !portalKillerActive) {
        M5.Lcd.fillScreen(BLACK);
        lastMinute = dt.time.minutes;
    }
    
    char timeBuf[16];
    if (use24HourFormat) {
        snprintf(timeBuf, sizeof(timeBuf), "%02d:%02d:%02d", 
                 dt.time.hours, dt.time.minutes, dt.time.seconds);
    } else {
        int displayHour = dt.time.hours % 12;
        if (displayHour == 0) displayHour = 12;
        snprintf(timeBuf, sizeof(timeBuf), "%2d:%02d:%02d", 
                 displayHour, dt.time.minutes, dt.time.seconds);
    }
    
    // Clock at top 1/3 of screen
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(CLOCK_COLORS[clockColorIndex], BLACK);
    M5.Lcd.setCursor(20, 10);
    M5.Lcd.println(timeBuf);
    
    // Show Portal Killer status below clock
    M5.Lcd.setTextSize(1);
    if (portalKillerActive) {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Lcd.setCursor(5, 45);
        M5.Lcd.printf("PORTAL KILLER: ACTIVE");
        
        M5.Lcd.setTextColor(YELLOW, BLACK);
        M5.Lcd.setCursor(5, 60);
        M5.Lcd.printf("Kills: %d", portalKillCount);
        
        M5.Lcd.setTextColor(GREEN, BLACK);
        M5.Lcd.setCursor(5, 75);
        M5.Lcd.println("Scanning...");
        
        M5.Lcd.setTextColor(DARKGREY, BLACK);
        M5.Lcd.setCursor(5, 120);
        M5.Lcd.print("A:Off  B:Bright");
    } else {
        M5.Lcd.setTextColor(DARKGREY, BLACK);
        M5.Lcd.setCursor(5, 45);
        M5.Lcd.print("Portal Killer: OFF");
        M5.Lcd.setCursor(5, 120);
        M5.Lcd.print("A:Activate  B:Bright");
    }
}

void scanForEvilPortals() {
    Serial.println("Scanning for evil portals...");
    
    // Clear only the status area below clock (not the whole screen)
    M5.Lcd.fillRect(0, 45, 240, 90, BLACK);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(YELLOW, BLACK);
    M5.Lcd.setCursor(5, 60);
    M5.Lcd.println("SCANNING NETWORKS...");
    
    int n = WiFi.scanNetworks();
    
    if (n == 0) {
        M5.Lcd.fillRect(0, 60, 240, 15, BLACK);
        M5.Lcd.setCursor(5, 60);
        M5.Lcd.println("No networks found");
        delay(1000);
        return;
    }
    
    // Look for open networks (potential evil portals)
    bool foundLastPortal = false;
    for (int i = 0; i < n; i++) {
        if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
            String ssid = WiFi.SSID(i);
            
            // Check if this is the portal we just attacked
            if (ssid == lastAttackedPortal) {
                foundLastPortal = true;
            }
            
            Serial.printf("Evil portal detected: %s\n", ssid.c_str());
            
            // Attack the portal with random insult
            lastAttackedPortal = ssid;
            attackPortal(ssid);
            portalKillCount++;
            
            delay(1000);
        }
    }
    
    // If we attacked a portal before and it's now gone, show nuked message
    if (lastAttackedPortal != "" && !foundLastPortal) {
        displayMessage("PORTAL\nNUKED!", GREEN);
        lastAttackedPortal = "";
        delay(1500);
    }
    
    WiFi.scanDelete();
}

void attackPortal(String ssid) {
    // Clear only status area below clock
    M5.Lcd.fillRect(0, 45, 240, 90, BLACK);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(RED, BLACK);
    M5.Lcd.setCursor(5, 50);
    M5.Lcd.println("ATTACKING:");
    
    M5.Lcd.setTextColor(WHITE, BLACK);
    M5.Lcd.setCursor(5, 65);
    M5.Lcd.println(ssid.substring(0, 25)); // Show SSID
    
    // Pick random insult for display
    int insultIndex = random(0, numInsults);
    String insult = dataThiefInsults[insultIndex];
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(YELLOW, BLACK);
    M5.Lcd.setCursor(5, 80);
    
    // Word wrap the insult (smaller display area)
    int maxWidth = 30; // Characters per line at size 1
    int startPos = 0;
    int yPos = 80;
    
    while (startPos < insult.length() && yPos < 115) {
        String line = insult.substring(startPos, min((int)insult.length(), startPos + maxWidth));
        M5.Lcd.setCursor(5, yPos);
        M5.Lcd.println(line);
        startPos += maxWidth;
        yPos += 10;
    }
    
    Serial.printf("Attacking %s with: %s\n", ssid.c_str(), insult.c_str());
    
    // Try to connect and spam the portal
    WiFi.begin(ssid.c_str());
    
    unsigned long startTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 5000) {
        delay(100);
    }
    
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected! Launching counterattack...");
        
        // Spam common portal endpoints with fake credentials
        String endpoints[] = {"/login", "/auth", "/signin", "/portal", "/admin"};
        
        for (int i = 0; i < 5; i++) {
            for (String endpoint : endpoints) {
                // Pick a NEW random insult for each message
                int msgInsultIndex = random(0, numInsults);
                String msgInsult = dataThiefInsults[msgInsultIndex];
                
                HTTPClient http;
                String url = "http://192.168.4.1" + endpoint;
                http.begin(url);
                http.addHeader("Content-Type", "application/x-www-form-urlencoded");
                
                String fakeData = "username=hacker" + String(random(1000, 9999)) + 
                                 "&password=" + msgInsult.substring(0, min(16, (int)msgInsult.length())) +
                                 "&email=" + msgInsult.substring(min(16, (int)msgInsult.length()));
                
                http.POST(fakeData);
                http.end();
                delay(50);
            }
        }
        
        WiFi.disconnect();
        Serial.println("Counterattack complete!");
        
        displayMessage("PORTAL\nATTACKED!", YELLOW);
    } else {
        Serial.println("Couldn't connect to portal");
        displayMessage("PORTAL\nDODGED!", BLUE);
    }
    
    delay(1500);
}

void displayMessage(String msg, uint16_t color) {
    // Clear only status area below clock
    M5.Lcd.fillRect(0, 45, 240, 90, BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(color, BLACK);
    
    // Simple word wrap in status area
    int yPos = 60;
    int startPos = 0;
    while (startPos < msg.length()) {
        int newlinePos = msg.indexOf('\n', startPos);
        if (newlinePos == -1) newlinePos = msg.length();
        
        String line = msg.substring(startPos, newlinePos);
        M5.Lcd.setCursor(10, yPos);
        M5.Lcd.println(line);
        
        startPos = newlinePos + 1;
        yPos += 20;
    }
}

void updateActivity() {
    lastActivityTime = millis();
}

void drawMenu() {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(YELLOW, BLACK);
    M5.Lcd.setCursor(20, 10);
    M5.Lcd.println("SETTINGS");
    
    M5.Lcd.setTextSize(1);
    const char* menuItems[] = {"Set Time", "Screen Timeout", "Shake to Wake", "Clock Color", "Exit Menu"};
    
    for (int i = 0; i < MENU_ITEMS; i++) {
        if (i == menuSelection) {
            M5.Lcd.setTextColor(BLACK, GREEN);
        } else {
            M5.Lcd.setTextColor(WHITE, BLACK);
        }
        M5.Lcd.setCursor(10, 45 + (i * 15));
        M5.Lcd.println(menuItems[i]);
    }
    
    // Show current settings
    M5.Lcd.setTextColor(DARKGREY, BLACK);
    M5.Lcd.setCursor(10, 110);
    M5.Lcd.printf("Timeout: %s", screenTimeoutEnabled ? "ON" : "OFF");
    M5.Lcd.setCursor(10, 120);
    const char* sensNames[] = {"Light", "Med", "Heavy"};
    M5.Lcd.printf("Shake: %s %s", shakeToWakeEnabled ? "ON" : "OFF", 
                  shakeToWakeEnabled ? sensNames[shakeSensitivity] : "");
}

void handleMenuInput() {
    if (M5.BtnB.wasPressed()) {
        menuSelection = (menuSelection + 1) % MENU_ITEMS;
        updateActivity();
    }
    
    if (M5.BtnA.wasPressed()) {
        updateActivity();
        switch (menuSelection) {
            case 0: // Set Time
                setTimeMenu();
                break;
            case 1: // Screen Timeout
                screenTimeoutMenu();
                break;
            case 2: // Shake to Wake
                shakeToWakeMenu();
                break;
            case 3: // Clock Color
                clockColorMenu();
                break;
            case 4: // Exit
                inMenu = false;
                M5.Lcd.fillScreen(BLACK);
                break;
        }
    }
}

void setTimeMenu() {
    int hour = 12;
    int minute = 0;
    bool settingHour = true;
    
    while (true) {
        M5.update();
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(YELLOW, BLACK);
        M5.Lcd.setCursor(20, 10);
        M5.Lcd.println("SET TIME");
        
        M5.Lcd.setTextSize(3);
        if (settingHour) {
            M5.Lcd.setTextColor(GREEN, BLACK);
        } else {
            M5.Lcd.setTextColor(WHITE, BLACK);
        }
        M5.Lcd.setCursor(40, 50);
        M5.Lcd.printf("%02d", hour);
        
        M5.Lcd.setTextColor(WHITE, BLACK);
        M5.Lcd.print(":");
        
        if (!settingHour) {
            M5.Lcd.setTextColor(GREEN, BLACK);
        } else {
            M5.Lcd.setTextColor(WHITE, BLACK);
        }
        M5.Lcd.printf("%02d", minute);
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(DARKGREY, BLACK);
        M5.Lcd.setCursor(10, 110);
        M5.Lcd.print("B:Change A:Next/Save");
        
        if (M5.BtnB.wasPressed()) {
            updateActivity();
            if (settingHour) {
                hour = (hour + 1) % 24;
            } else {
                minute = (minute + 1) % 60;
            }
        }
        
        if (M5.BtnA.wasPressed()) {
            updateActivity();
            if (settingHour) {
                settingHour = false;
            } else {
                // Save time
                auto dt = M5.Rtc.getDateTime();
                dt.time.hours = hour;
                dt.time.minutes = minute;
                dt.time.seconds = 0;
                M5.Rtc.setDateTime(dt);
                M5.Lcd.fillScreen(BLACK);
                return;
            }
        }
        
        delay(100);
    }
}

void screenTimeoutMenu() {
    int timeoutOptions[] = {10, 30, 60, 120, 300}; // seconds
    int currentOption = 1; // default 30s
    
    // Find current setting
    for (int i = 0; i < 5; i++) {
        if (timeoutOptions[i] == screenTimeoutSeconds) {
            currentOption = i;
            break;
        }
    }
    
    while (true) {
        M5.update();
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(YELLOW, BLACK);
        M5.Lcd.setCursor(10, 10);
        M5.Lcd.println("SCREEN TIMEOUT");
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(WHITE, BLACK);
        M5.Lcd.setCursor(10, 50);
        M5.Lcd.println("Enable:");
        M5.Lcd.setCursor(80, 50);
        M5.Lcd.setTextColor(screenTimeoutEnabled ? GREEN : RED, BLACK);
        M5.Lcd.println(screenTimeoutEnabled ? "ON" : "OFF");
        
        M5.Lcd.setTextColor(WHITE, BLACK);
        M5.Lcd.setCursor(10, 70);
        M5.Lcd.println("Time:");
        M5.Lcd.setCursor(80, 70);
        M5.Lcd.setTextColor(GREEN, BLACK);
        M5.Lcd.printf("%ds", timeoutOptions[currentOption]);
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(DARKGREY, BLACK);
        M5.Lcd.setCursor(10, 110);
        M5.Lcd.print("B:Toggle/Change A:Save");
        
        if (M5.BtnB.wasPressed()) {
            updateActivity();
            if (!screenTimeoutEnabled) {
                screenTimeoutEnabled = true;
            } else {
                currentOption = (currentOption + 1) % 5;
            }
        }
        
        if (M5.BtnA.wasPressed()) {
            updateActivity();
            screenTimeoutSeconds = timeoutOptions[currentOption];
            M5.Lcd.fillScreen(BLACK);
            return;
        }
        
        delay(100);
    }
}

void shakeToWakeMenu() {
    const char* sensitivityNames[] = {"Light", "Medium", "Heavy"};
    
    while (true) {
        M5.update();
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(YELLOW, BLACK);
        M5.Lcd.setCursor(10, 10);
        M5.Lcd.println("SHAKE TO WAKE");
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(WHITE, BLACK);
        M5.Lcd.setCursor(10, 50);
        M5.Lcd.println("Enable:");
        M5.Lcd.setCursor(80, 50);
        M5.Lcd.setTextColor(shakeToWakeEnabled ? GREEN : RED, BLACK);
        M5.Lcd.println(shakeToWakeEnabled ? "ON" : "OFF");
        
        M5.Lcd.setTextColor(WHITE, BLACK);
        M5.Lcd.setCursor(10, 70);
        M5.Lcd.println("Sensitivity:");
        M5.Lcd.setCursor(80, 70);
        M5.Lcd.setTextColor(GREEN, BLACK);
        M5.Lcd.println(sensitivityNames[shakeSensitivity]);
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(DARKGREY, BLACK);
        M5.Lcd.setCursor(10, 110);
        M5.Lcd.print("B:Toggle/Change A:Save");
        
        if (M5.BtnB.wasPressed()) {
            updateActivity();
            if (!shakeToWakeEnabled) {
                shakeToWakeEnabled = true;
            } else {
                shakeSensitivity = (shakeSensitivity + 1) % 3;
            }
        }
        
        if (M5.BtnA.wasPressed()) {
            updateActivity();
            M5.Lcd.fillScreen(BLACK);
            return;
        }
        
        delay(100);
    }
}

void clockColorMenu() {
    while (true) {
        M5.update();
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(YELLOW, BLACK);
        M5.Lcd.setCursor(20, 10);
        M5.Lcd.println("CLOCK COLOR");
        
        // Show current color name
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(CLOCK_COLORS[clockColorIndex], BLACK);
        M5.Lcd.setCursor(40, 50);
        M5.Lcd.println(CLOCK_COLOR_NAMES[clockColorIndex]);
        
        // Show preview time
        M5.Lcd.setTextSize(3);
        M5.Lcd.setTextColor(CLOCK_COLORS[clockColorIndex], BLACK);
        M5.Lcd.setCursor(30, 80);
        M5.Lcd.println("12:34:56");
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(DARKGREY, BLACK);
        M5.Lcd.setCursor(10, 110);
        M5.Lcd.print("B:Change A:Save");
        
        if (M5.BtnB.wasPressed()) {
            updateActivity();
            clockColorIndex = (clockColorIndex + 1) % NUM_CLOCK_COLORS;
        }
        
        if (M5.BtnA.wasPressed()) {
            updateActivity();
            M5.Lcd.fillScreen(BLACK);
            return;
        }
        
        delay(100);
    }
}
