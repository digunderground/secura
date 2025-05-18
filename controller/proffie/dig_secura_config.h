// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
//#include "dig-styles.h"
/*--------------------------------- Blade Config ---------------------------------*/
#define BLADE_DETECT_PIN 6 // insertion & removal
#define NUM_BLADES 6
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 300; // 144 = base
#define EXTRA_COLOR_BUFFER_SPACE 60
// for blade ID
#define SHARED_POWER_PINS
#define BLADE_ID_SCAN_MILLIS 1000
#define BLADE_ID_TIMES 10
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// USE:
/*
BladeConfig blades[] = {
      { 5000,
        WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
        CONFIGARRAY(blade1_in) },
      { 10000,
        WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
        CONFIGARRAY(blade2_in) },
      { NO_BLADE,
        WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
        CONFIGARRAY(no_blade) },
    };
*/
/*--------------------------------- Volume Config ---------------------------------*/
#define VOLUME 2500 // 33mm = 3000 28mm = 2500
#define BOOT_VOLUME 600
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 4 //orig 8
/*--------------------------------- Power Save ---------------------------------*/
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
//#define PLI_OFF_TIME 30 * 1000 //  Controls how long battery display is shown on OLED after animations end.
/*--------------------------------- base Enable / Disable ---------------------------------*/
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
//#define DISABLE_BASIC_PARSER_STYLES // disable OOTB parser styles
#define ENABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS // disable logging
#define ENABLE_ALL_EDIT_OPTIONS
#define SAVE_PRESET
#define NO_REPEAT_RANDOM
#define FETT263_SAY_BATTERY_PERCENT
/*--------------------------------- OLED ---------------------------------*/
#define ENABLE_SSD1306
//#define OLED_FLIP_180
//#define USE_AUREBESH_FONT // use Aurebesh font on OLED
/*--------------------------------- Bluetooth ---------------------------------*/
//#define ENABLE_SERIAL
//#define BLE_PASSWORD "12345"
//#define BLE_NAME "digsaber"
//#define BLE_SHORTNAME "digsaber"
/*--------------------------------- On-Saber Settings method ---------------------------------*/
#define FETT263_DISABLE_COPY_PRESET //- Disables the "on-the-fly" Copy Preset option
// #define FETT263_DISABLE_CHANGE_FONT //- Disables the "on-the-fly" Change Font option
// #define FETT263_DISABLE_CHANGE_STYLE //- Disables the "on-the-fly" Change Style option
/* OPT 1 ====================*/
#define FETT263_EDIT_MODE_MENU // Edit ALL settings like blades, color
/* OPT 2 ====================*/
//#define FETT263_EDIT_SETTINGS_MENU // edit base settings IE volume, brightness

/*--------------------------------- Blade Color / Multiphase ---------------------------------*/
/* OPT 1 ====================
#define FETT263_MULTI_PHASE // allows color wheel - cannot use with FETT263_SPECIAL_ABILITIES - swap if stuff stopps working */
/* OPT 2 ====================*/
#define FETT263_SPECIAL_ABILITIES // need for kyber/multi select - remove if unused
//
#define COLOR_CHANGE_DIRECT //no color wheel? Needed for special ability color change?
#define FETT263_USE_BC_MELT_STAB // melt is full-time gesture controlled.
/*--------------------------------- Power Button control ---------------------------------*/
#define FETT263_MOTION_WAKE_POWER_BUTTON
//#define FETT263_HOLD_BUTTON_OFF // instant off for power?
/*--------------------------------- Motion Action(s) ---------------------------------*/
#define FETT263_SWING_ON
#define FETT263_TWIST_ON_PREON
#define FETT263_TWIST_OFF
/*--------------------------------- Action Speed ---------------------------------*/
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 10 // higher = battlemode uses clash even for hard hits. lower locks up easier
#define FETT263_SWING_ON_SPEED 300 // orig 250
#define CLASH_THRESHOLD_G 2.5 // previous = 3.0
#define AUDIO_CLASH_SUPPRESSION_LEVEL 1 // new addition https://crucible.hubbe.net/t/whats-the-minimum-clash-threshold-can-be-adjusted-and-or-set-to/3268/3
#define KILL_OLD_PLAYERS
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

/*--------------------------------- Blade Presets = Blade ---------------------------------*/
// use blade style functions
// main blade is WITH a blade inserrted
// no_blade is for when the blade is removed - turns off SPG motor and other accents
// for help use https://pod.hubbe.net/config/preset-configuration.html
#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "FONT_NAME;common",  "",
StylePtr<BladeStyleFunctionGoesHere>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),
"name on\n screen"
},
};
/*--------------------------------- Blade Presets = no_blade ---------------------------------*/
Preset no_blade[] = {
{ "FONT_NAME;common",  "",
//main
StylePtr<BladeStyleFunctionGoesHere>(),
// PG motor partial power
StylePtr<InOutHelper<SimpleClash<Lockup<Blast<White,Black>,AudioFlicker<Rgb<0,0,0>,Black>>,Black,0>,0,0,Rgb<50,50,50>>>(),
//SPG lights
StylePtr<SPGStyleFunctionGoesHere>(),
//CC
StylePtr<CCStyleFunctionGoesHere>(),
//accent
StylePtr<AccentStyleFunctionGoesHere>(),
//speaker lights
StylePtr<SPStyleFunctionGoesHere>(),
"secura\n chassis"
},
};

/*--------------------------------- Blade Config + no_blade ---------------------------------*/
/*========Blade Designations ===============
REFERENCES:
Blade Config: https://pod.hubbe.net/config/blades/blade-configuration.html
Sub Blade Define: https://pod.hubbe.net/config/blades/subblade.html
//
Blade 1 = power 2,3  data1 = main blade - removable
Blade 2 = Pin 4, = SPG motor
Blade 3 = Pin 1 data2 = spg lights
Blade 4 = Pin 5 data 3 = CC
Blade 5 = pin 6 (free1) data 4 = accent
Blade 6 = pin 6 (free 3) data 6 (speaker and side accents)
====================================*/
BladeConfig blades[] = {
  // no resistor
  { 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>() , // PG motor
    WS281XBladePtr<64, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // SPG lights - 4x shtok medium rings
    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(), // CC - 1x shtok small ring
    WS281XBladePtr<8, trigger4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), // accent
    WS281XBladePtr<1, trigger6Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // speaker - 1x shtok small ring
  , CONFIGARRAY(presets) },
  { 5475, WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // pixel Stick resistor value 5475
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>() , // PG motor
    WS281XBladePtr<64, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // SPG lights
    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(), // CC
    WS281XBladePtr<8, trigger4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), // accent
    WS281XBladePtr<1, trigger6Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // speaker
  , CONFIGARRAY(presets) },
  { NO_BLADE, WS281XBladePtr<18, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // Shtok v3 18 pixels V3 config series
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>() , // PG motor
    WS281XBladePtr<64, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // SPG lights
    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(), // CC
    WS281XBladePtr<8, trigger4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), // accent
    WS281XBladePtr<1, trigger6Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // speaker
  , CONFIGARRAY(no_blade) },
};

#endif

/*--------------------------------- Button Config ---------------------------------*/
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

/*=============================================================================================
STYLE FUNCTION INCLUDES BELOW
=============================================================================================*/
#ifdef CONFIG_STYLES
//#include "path/to/file_of_function_styles.h"
/*=============================================================================================
OR PASTE STYLE FUNCTIONS  BELOW
=============================================================================================*/

#endif
