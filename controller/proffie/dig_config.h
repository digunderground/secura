// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
//#include "dig-styles.h"
/*--------------------------------- Blade Config ---------------------------------*/
#define BLADE_DETECT_PIN 6 // insertion & removal
#define NUM_BLADES 3
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 300; // 144 = base, 474 = tritium saber
//#define EXTRA_COLOR_BUFFER_SPACE 30
// for blade ID
#define SHARED_POWER_PINS
#define BLADE_ID_SCAN_MILLIS 1000
#define BLADE_ID_TIMES 10
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
//#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>
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
#define VOLUME 3200 // prev 2800
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
#define DISABLE_BASIC_PARSER_STYLES // disable OOTB parser styles
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
// #define ETT263_DISABLE_CHANGE_FONT //- Disables the "on-the-fly" Change Font option
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
// https://pod.hubbe.net/config/preset-configuration.html
#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "TFA_1;common",  "",
StylePtr<MainCustomBladeMultiPhaseOriginalColorChange>(),
StylePtr<Black>(),
StylePtr<MainCustomBladeMultiPhaseOriginalColorChange>(),
"Graflex Blue"
},
{ "TFA_2;common",  "",
StylePtr<CanChangeColors>(),
StylePtr<Black>(),
StylePtr<CanChangeColors>(),
"Graflex Green"
},
{ "Binary_dark;common",  "",
StylePtr<MainBinaryRollingPulsewithUnstableSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Binary_dark"
},
{ "Ra;common",  "",
StylePtr<MainRaAudioFlickerUnstableSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Ra"
},
{ "Volatile;common",  "",
StylePtr<MainVolatileTwoColorRotatingSwingSpeedAudioFlickerBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Volatile"
},
{ "Analog;common",  "",
StylePtr<MainAnalogAudioFlickerwithRippleSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Analog"
},
{ "Magnetic;common",  "",
StylePtr<YellowPurple>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Magnetic"
},
{ "Coda;common",  "",
StylePtr<MainCODARollingPulsewithUnstableSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Coda"
},
{ "KyberWorkshop;common",  "",
StylePtr<KyberWorkshop>(),
StylePtr<Black>(),
StylePtr<KyberWorkshopCC>(),
"Kyber"
},
{ "Fracture;common",  "",
StylePtr<FireBlade>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Fracture"
},
{ "KP_Unstable;common",  "",
StylePtr<ControlMainBladeofTalzinBaseColorAudioColorShift>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Unstable"
},
{ "KSith_Proto;common",  "",
StylePtr<DigProtoSaberTest>(),
StylePtr<Black>(),
StylePtr<SideUnstableErraticAltColorBrightPulse>(),
"Proto Saber"
},
{ "Adrenaline_Proffie;common",  "font12/tracks/track.wav",
StylePtr<DigBluePurplePlasmaGate>(),
StylePtr<Black>(),
StylePtr<SideUnstableErraticAltColorBrightPulse>(),
"Adrenaline"
},
};
/*--------------------------------- Blade Presets = no_blade ---------------------------------*/
Preset no_blade[] = {
{ "TFA_1;common",  "",
StylePtr<MainCustomBladeMultiPhaseOriginalColorChange>(),
StylePtr<Black>(),
StylePtr<MainCustomBladeMultiPhaseOriginalColorChange>(),
"Graflex Blue"
},
{ "TFA_2;common",  "",
StylePtr<CanChangeColors>(),
StylePtr<Black>(),
StylePtr<CanChangeColors>(),
"Graflex Green"
},
{ "Binary_dark;common",  "",
StylePtr<MainBinaryRollingPulsewithUnstableSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Binary"
},
{ "Ra;common",  "",
StylePtr<MainRaAudioFlickerUnstableSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Ra"
},
{ "Volatile;common",  "",
StylePtr<MainVolatileTwoColorRotatingSwingSpeedAudioFlickerBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Volatile"
},
{ "Analog;common",  "",
StylePtr<MainAnalogAudioFlickerwithRippleSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Analog"
},
{ "Magnetic;common",  "",
StylePtr<YellowPurple>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Magnetic"
},
{ "Coda;common",  "",
StylePtr<MainCODARollingPulsewithUnstableSwingBaseColor>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Coda"
},
{ "KyberWorkshop;common",  "",
StylePtr<KyberWorkshop>(),
StylePtr<Black>(),
StylePtr<KyberWorkshopCC>(),
"Kyber"
},
{ "Fracture;common",  "",
StylePtr<FireBlade>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Fracture"
},
{ "KP_Unstable;common",  "",
StylePtr<ControlMainBladeofTalzinBaseColorAudioColorShift>(),
StylePtr<Black>(),
StylePtr<Black>(),
"Unstable"
},
{ "KSith_Proto;common",  "",
StylePtr<DigProtoSaberTest>(),
StylePtr<InOutHelper<SimpleClash<Lockup<Blast<White,Black>,AudioFlicker<Rgb<0,0,0>,Black>>,Black,0>,0,0,Rgb<50,50,50>>>(),
StylePtr<SideUnstableErraticAltColorBrightPulse>(),
"Proto Saber"
},
{ "Adrenaline_Proffie;common",  "",
StylePtr<DigBluePurplePlasmaGate>(),
StylePtr<Black>(),
StylePtr<SideUnstableErraticAltColorBrightPulse>(),
"Adrenaline"
},
};

/*--------------------------------- Blade Config + no_blade ---------------------------------*/
/*========Blade Designations ===============
REFERENCES:
Blade Config: https://pod.hubbe.net/config/blades/blade-configuration.html
Sub Blade Define: https://pod.hubbe.net/config/blades/subblade.html
//
Blade 1 = Pin 2,3 = main balde removable
Blade 2 = Pin 4, = SPG motor
Blade 3 = Pin 6 = CC
Blade 4 = SPG color
Blade 5 = Chassis (speaker and side accents)
====================================*/
BladeConfig blades[] = {
  // no resistor
  { 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>() , // PG motor
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // CC
  , CONFIGARRAY(presets) },
  { 11069, WS281XBladePtr<8, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // test plug
     SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>() , // PG motor
     WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // CC
  , CONFIGARRAY(presets) },
  { 9019, WS281XBladePtr<25, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // test plug
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>() , // PG motor
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // CC
  , CONFIGARRAY(presets) },
  { 28663, WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // STD Blade
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>() , // PG motor
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // CC
  , CONFIGARRAY(presets) },
  { 5475, WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // pixel Stick
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>() , // PG motor
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // CC
  , CONFIGARRAY(presets) },
  { NO_BLADE, WS281XBladePtr<18, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // Shtok v3 18 pixels V3 config series
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>() , // PG motor
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >() // CC
  , CONFIGARRAY(no_blade) },
};

#endif

/*--------------------------------- Button Config ---------------------------------*/
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

/*=============================================================================================
STYLES BELOW
=============================================================================================*/
#ifdef CONFIG_STYLES
#include "dig_plasmaGate_styles.h"
/*--------------------------------- MainCustomBladeMultiPhaseOriginalColorChange---------------------------------*/
using MainCustomBladeMultiPhaseOriginalColorChange =
/*copyright Fett263 CustomBlade (Primary Blade) OS7 Style
https://fett263library.com/early-access/#CustomBlade
OS7.8 v1.014
Single Style
Multi Phase (Original - Color Change)
Default: Hyper Responsive Rotoscope (Original Trilogy) [BaseColorArg]
1: Unstable Rage [AltColorArg]
Multi Phase Control: use Color Change with COLOR_CHANGE_DIRECT define (to enable click-to-change).

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
 Layers<Black,ColorChange<TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrFadeX<Int<1000>>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Stripes<3000,-3500,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>>>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>;
/* add to preset as StylePtr<MainCustomBladeMultiPhaseOriginalColorChange>() */

/*--------------------------------- motor---------------------------------*/
using motor =
/*copyright Fett263 CustomBlade (Crystal Chamber) OS7 Style
https://fett263library.com/early-access/#CustomBlade
OS7.8 v1.014
Single Style
Multi Phase (Original - Color Change)
Default: Hyper Responsive Rotoscope (Original Trilogy) [BaseColorArg]
1: Unstable Rage [AltColorArg]

Off Behavior: Off [Color: OffColorArg]
Multi Phase Control: use Color Change with COLOR_CHANGE_DIRECT define (to enable click-to-change).

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
*/
 Layers<Black,ColorChange<TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrFadeX<Int<1000>>>,RgbArg<BASE_COLOR_ARG,Rgb<128,128,128>>,Stripes<3000,-3500,RgbArg<ALT_COLOR_ARG,Rgb<128,128,128>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<128,128,128>>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,Rgb<128,128,128>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<128,128,128>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<128,128,128>>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<128,128,128>>>>>>,InOutTrL<TrInstant,TrInstant,Black>>;;
/*
 add to preset as StylePtr<motor>()
*/

/*--------------------------------- MainBinaryRollingPulsewithUnstableSwingBaseColor---------------------------------*/
using MainBinaryRollingPulsewithUnstableSwingBaseColor =
/*copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.8 v1.015
This Style Contains 4 Unique Combinations
Style Options:
Default (0): CODA (Rolling Pulse with Unstable Swing)
1: Crispity (Unstable Blade - AudioFlicker Swing)


--Effects Included--
Preon Effect Options: Default (0): Faulty Fire Ignition, 1: Emitter Heat Up [Color: PreonColorArg]
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: RetractionColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
 Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,Layers<Mix<Sin<Int<3>>,AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,Stripes<5000,-90,Mix<Int<21200>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Mix<Int<16384>,Black,RotateColorsX<Int<30000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<12632>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>>,AudioFlicker<RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Stripes<5000,-90,Mix<Int<21672>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<26736>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<26736>,Black,RotateColorsX<Int<28000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<21000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>>>,AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Int<31600>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Black>,Black,RotateColorsX<Int<31600>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Black>,SwingSpeed<525>>>,Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,RandomPerLEDFlicker<Mix<Int<6000>,Black,RotateColorsX<Int<32000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,300>,Mix<Int<10772>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,0,6,10,1000,2>,AlphaL<AudioFlickerL<RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,SwingSpeed<400>>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,Black>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrSelect<IntArg<PREON_OPTION_ARG,0>,TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrWipe<100>>,AlphaL<StripesX<Int<3000>,Sin<Int<60>,Int<-1600>,Int<-4000>>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10772>,Black,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<24000>,Black,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>>,SmoothStep<NoisySoundLevel,Int<-3000>>>,TrFade<100>>,TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrFade<100>>,AlphaL<HumpFlickerL<Mix<Trigger<EFFECT_PREON,Mult<WavLen<EFFECT_PREON>,Int<24000>>,WavLen<EFFECT_PREON>,Int<500>>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,White>,20>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-3000>>>,TrFade<200>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>;
/*
 add to preset as StylePtr<MainCODARollingPulsewithUnstableSwingBaseColor>()
*/
using CanChangeColors =
/*--------------------------------- CanChangeColors -------------------------
copyright Fett263 CustomBlade (Primary Blade) OS7 Style
https://fett263library.com/early-access/#CustomBlade
OS7.8 v1.015
This Style Contains 2 Unique Combinations
Multi Phase (Original - Color Change)
Default: Hyper Responsive Rotoscope (Original Trilogy) [BaseColorArg]
1: Unstable Rage [AltColorArg]
Multi Phase Control: use Color Change with COLOR_CHANGE_DIRECT define (to enable click-to-change).

--Effects Included--
Preon Effect Options: Default (0): Rey TROS Spark, 1: Emitter Heat Up [Color: PreonColorArg]
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Power Burst [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
Layers<Black,ColorChange<TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrFadeX<Int<1000>>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Stripes<3000,-3500,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>>>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrCenterWipeX<Int<150>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrJoin<TrCenterWipeX<Int<150>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSmoothFade<150>>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,17992>,Int<98304>>>>,Black>,TransitionEffectL<TrSelect<IntArg<PREON_OPTION_ARG,0>,TrConcat<TrJoin<TrDelayX<Int<100>>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrWipe<100>,AlphaL<DodgerBlue,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrDelayX<Sum<WavLen<EFFECT_PREON>,Int<200>>>>,TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrFade<100>>,AlphaL<HumpFlickerL<Mix<Trigger<EFFECT_PREON,Mult<WavLen<EFFECT_PREON>,Int<24000>>,WavLen<EFFECT_PREON>,Int<500>>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,White>,20>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-3000>>>,TrFade<200>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>;
/* Add to preset as StylePtr<MainCustomBladeMultiPhaseOriginalColorChange>() */
//
/*--------------------------------- KyberWorkshop -------------------------
copyright Fett263 CustomBlade (Primary Blade) OS7 Style
https://fett263library.com/early-access/#CustomBlade
OS7.8 v1.015
Single Style
Multi Phase (Special Abilities*)
Default: Live Action Darksaber (Hyper-Responsive) [BaseColorArg]
1: Audio Rotoscope - Single Color (Original Trilogy) [AltColorArg]
2: Audio Rotoscope - Single Color (Original Trilogy) [AltColor2Arg]
3: Hyper Responsive Rotoscope (Subtle) [AltColor3Arg]
4: The Duel: Ronin [OffColorArg]
5: Hyper Responsive Rotoscope (Subdued) [PostOffColorArg]
Multi Phase Control: use Special Abilities controls to change Phase. Requires Alt Font.

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt005/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Preon Effects: 0: Emitter Heat Up 1: Disable 2: Disable 3: Disable 4: Emitter Heat Up 5: Disable [Color:PreonColorArg]
Ignition Effects: 0: SparkTip Ignition [MILLIS: 300, BEND: 16384] 1: Standard Ignition [MILLIS: 300, BEND: 16384] 2: Standard Ignition [MILLIS: 300, BEND: 16384] 3: SparkTip Ignition [MILLIS: 300, BEND: 16384] 4: Glitch On [MILLIS: 300, BEND: 16384] 5: Standard Ignition [MILLIS: 300, BEND: 16384] [Color:IgnitionColorArg]
Retraction Effects: 0: Glitch Off [MILLIS: 500, BEND: 16384] 1: Standard Retraction [MILLIS: 500, BEND: 16384] 2: Standard Retraction [MILLIS: 500, BEND: 16384] 3: SparkTip Retraction [MILLIS: 300, BEND: 16384] 4: Metal Forge (Cool Down) [MILLIS: 200, BEND: 30384] 5: Standard Retraction [MILLIS: 500, BEND: 16384] [Color:RetractionColorArg]
PostOff Effect: Emitter Cool Off (Emitter Size) [Color: PostOffColorArg]
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Stab Effect: AudioFlicker Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
Special Ability 1: Next Phase
Special Ability 2: Previous Phase
Special Ability 5: Next Phase
Special Ability 6: Previous Phase

*/
using KyberWorkshop = Layers<Black,ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrColorCycleX<Int<1000>>>,Mix<HoldPeakF<SwingSpeed<400>,Scale<SwingAcceleration<>,Int<2000>,Int<4000>>,Int<8000>>,HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Stripes<35000,-200,Mix<Int<14000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<24000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<28000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>>,100>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,AudioFlicker<Stripes<10000,-2600,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>,AudioFlicker<Stripes<10000,-2600,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,Mix<Sin<Int<16>,Int<32768>,Int<18000>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,Stripes<12000,-200,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,Mix<Int<20000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>>>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>>,HumpFlicker<Stripes<20000,-800,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,50>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,Mix<PulsingF<Sin<Int<30>,Int<4000>,Int<10000>>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Stripes<12000,-400,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<7710>,Black,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<16448>,Black,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>>>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>>>,AlphaL<AudioFlickerL<Mix<NoisySoundLevel,RotateColorsX<Int<4096>,RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<6>>,Int<-1>>,EFFECT_USER1>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<6>>,Int<-1>>,EFFECT_USER2>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<Mix<NoisySoundLevel,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<11980>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,White>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<Mix<NoisySoundLevel,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<11980>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,White>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,Mix<NoisySoundLevel,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<11980>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,White>>,Mix<Int<16384>,Black,Mix<NoisySoundLevel,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<11980>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,White>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,Mix<NoisySoundLevel,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<11980>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,White>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,Mix<NoisySoundLevel,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<11980>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,White>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrSelect<AltF,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<Int<300>,Int<16384>>>,TrConcat<TrJoin<TrDelayX<Mult<Int<300>,Int<16384>>>,TrWipeX<Mult<Int<300>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<Int<300>,Int<16384>>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>>,TrSelect<AltF,TrConcat<TrJoin<TrDelayX<Mult<Int<500>,Int<16384>>>,TrWipeInX<Mult<Int<500>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeInX<Mult<Int<500>,Int<16384>>>>,TrWipeInX<BendTimePowInvX<Int<500>,Int<16384>>>,TrWipeInX<BendTimePowInvX<Int<500>,Int<16384>>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<Int<300>,Int<16384>>>,TrConcat<TrFadeX<BendTimePowInvX<Int<200>,Int<30384>>>,White,TrFadeX<BendTimePowInvX<Int<200>,Int<30384>>>,DarkOrange,TrFadeX<BendTimePowInvX<Int<200>,Int<30384>>>,Red,TrFadeX<BendTimePowInvX<Int<200>,Int<30384>>>>,TrWipeInX<BendTimePowInvX<Int<500>,Int<16384>>>>,Black>,TransitionEffectL<TrSelect<AltF,TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrFade<100>>,AlphaL<HumpFlickerL<Mix<Trigger<EFFECT_PREON,Mult<WavLen<EFFECT_PREON>,Int<24000>>,WavLen<EFFECT_PREON>,Int<500>>,RgbArg<PREON_COLOR_ARG,Rgb<255,0,0>>,White>,20>,SmoothStep<IntArg<PREON_SIZE_ARG,6388>,Int<-3000>>>,TrFade<200>>,TrInstant,TrInstant,TrInstant,TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrFade<100>>,AlphaL<HumpFlickerL<Mix<Trigger<EFFECT_PREON,Mult<WavLen<EFFECT_PREON>,Int<24000>>,WavLen<EFFECT_PREON>,Int<500>>,RgbArg<PREON_COLOR_ARG,Rgb<255,0,0>>,White>,20>,SmoothStep<IntArg<PREON_SIZE_ARG,6388>,Int<-3000>>>,TrFade<200>>,TrInstant>,EFFECT_PREON>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<6>>,Int<-1>>,EFFECT_USER5>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<6>>,Int<-1>>,EFFECT_USER6>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<KyberWorkshop>()
--------------------------------------------------------------------------*/
/*--------------------------------- KyberWorkshopCC -------------------------
copyright Fett263 CustomBlade (Crystal Chamber) OS7 Style
https://fett263library.com/early-access/#CustomBlade
OS7.8 v1.015
Single Style
Multi Phase (Special Abilities*)
Default: Live Action Darksaber (Hyper-Responsive) [BaseColorArg]
1: Audio Rotoscope - Single Color (Original Trilogy) [AltColorArg]
2: Audio Rotoscope - Single Color (Original Trilogy) [AltColor2Arg]
3: Hyper Responsive Rotoscope (Subtle) [AltColor3Arg]
4: The Duel: Ronin [OffColorArg]
5: Hyper Responsive Rotoscope (Subdued) [PostOffColorArg]

Off Behavior: Off [Color: Match ON Color]
Multi Phase Control: use Special Abilities controls to change Phase. Requires Alt Font.

*This style REQUIRES Alt Fonts alt000/ to alt005/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect: Metal Forge (Heat Up) [Color: IgnitionColorArg]
Retraction Effect: Metal Forge (Cool Down) [Color: RetractionColorArg]
Lockup Effect: Lockup Flash [Color: LockupColorArg]
LightningBlock Effect: Full Blade Lightning [Color: LBColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Special Ability 1: Next Phase
Special Ability 2: Previous Phase

*/
using KyberWorkshopCC = Layers<Black,ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrColorCycleX<Int<1000>>>,Mix<HoldPeakF<SwingSpeed<400>,Scale<SwingAcceleration<>,Int<2000>,Int<4000>>,Int<8000>>,HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Stripes<35000,-200,Mix<Int<14000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<24000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<28000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>>,100>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,AudioFlicker<Stripes<10000,-2600,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>,AudioFlicker<Stripes<10000,-2600,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,Mix<Int<7710>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,Mix<Sin<Int<16>,Int<32768>,Int<18000>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,Stripes<12000,-200,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,Mix<Int<20000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>>>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>>,HumpFlicker<Stripes<20000,-800,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,50>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,Mix<PulsingF<Sin<Int<30>,Int<4000>,Int<10000>>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Stripes<12000,-400,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<7710>,Black,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<16448>,Black,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>>>>,RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,SmoothStep<ClashImpactF<>,Int<-4000>>>,TrFadeX<Scale<ClashImpactF<>,Int<100>,Int<300>>>>,EFFECT_LOCKUP_BEGIN>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,SmoothStep<ClashImpactF<>,Int<-4000>>>,TrFadeX<Scale<ClashImpactF<>,Int<100>,Int<300>>>>,EFFECT_LOCKUP_END>,LockupTrL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrInstant,TrFade<1000>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrConcat<TrFadeX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,Red,TrFadeX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,DarkOrange,TrFadeX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,White,TrFadeX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrConcat<TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,White,TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,DarkOrange,TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Red,TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>>;
/*
Add to preset as StylePtr<KyberWorkshopCC>()
--------------------------------------------------------------------------*/
//
//
//
//
/*--------------------------------- MainRaAudioFlickerUnstableSwingBaseColor -------------------------
copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.8 v1.015
Single Style
Base Style: Ra (AudioFlicker - Unstable Swing)


--Effects Included--
Ignition Effect: Cycle Up [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Fire Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect: AudioFlicker Swing (Scaled Cutting Edge) [Color: SwingColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainRaAudioFlickerUnstableSwingBaseColor = Layers<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<23130>,Black,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>>,AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Int<4200>,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>,Black>,Black,RotateColorsX<Int<4200>,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>,Black>>,SwingSpeed<350>>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<16000>>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<Stripes<2000,3000,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrWipeIn<200>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrColorCycleX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainRaAudioFlickerUnstableSwingBaseColor>()
--------------------------------------------------------------------------*/
/*--------------------------------- MainVolatileTwoColorRotating/SwingSpeedAudioFlickerBaseColor -------------------------
copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.8 v1.015
Single Style
Base Style: Volatile (Two Color Rotating/Swing Speed AudioFlicker)


--Effects Included--
Preon Effect: Faulty Ignition (Volatile Version) [Color: PreonColorArg]
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Swing Effect: Force Boost AudioFlicker Swing (Scaled Cutting Edge) [Color: SwingColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainVolatileTwoColorRotatingSwingSpeedAudioFlickerBaseColor = Layers<AudioFlicker<Mix<SwingSpeed<450>,Mix<Sin<Int<1>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,Mix<Sin<Int<2>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<16384>,Black,Mix<SwingSpeed<450>,Mix<Sin<Int<1>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,Mix<Sin<Int<2>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<6425>,Black,RotateColorsX<Int<26000>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,RotateColorsX<Int<26000>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>>,RotateColorsX<Int<21845>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainVolatileTwoColorRotating/SwingSpeedAudioFlickerBaseColor>()
--------------------------------------------------------------------------*/
/*--------------------------------- MainAnalogAudioFlickerwithRippleSwingBaseColor -------------------------
copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.8 v1.015
Single Style
Base Style: Analog (AudioFlicker with Ripple Swing)


--Effects Included--
Preon Effect: Pilot Light (Analog Version) [Color: PreonColorArg]
Ignition Effect: Glitch On [Color: IgnitionColorArg]
PowerUp Effect: Unstable Power Up Center Out [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Center Out [Color: RetractionColorArg]
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect: Force Boost AudioFlicker Swing (Scaled Cutting Edge) [Color: SwingColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainAnalogAudioFlickerwithRippleSwingBaseColor = Layers<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<20000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>>,AlphaL<RotateColorsX<Int<27000>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,SwingSpeed<500>>,AlphaL<Stripes<2500,-4000,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,Mix<Int<7710>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>>,Pulsing<Mix<Int<3855>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<300>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<300>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<300>,Int<16384>>>>,TrColorCycleX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<PulsingL<Mix<Int<16384>,White,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>,Int<300>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrBoingX<WavLen<EFFECT_PREON>,9>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainAnalogAudioFlickerwithRippleSwingBaseColor>()
--------------------------------------------------------------------------*/
/*--------------------------------- MainMagneticLavaLampwithFlickerBaseColor -------------------------
copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.8 v1.015
Single Style
Base Style: Magnetic (Lava Lamp with Flicker)


--Effects Included--
Preon Effect: Disable [Color: PreonColorArg]
Ignition Effect: Cycle Up [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: SparkTip Retraction [Color: RetractionColorArg]
CoolDown Effect: Power Flash [Color: RetractionColorArg]
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect: AudioFlicker Swing (Scaled Cutting Edge) [Color: SwingColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainMagneticLavaLampwithFlickerBaseColor = Layers<Layers<StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>,3000>,Mix<Sin<Int<2>>,Mix<Int<24000>,Black,RotateColorsX<Int<4800>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>>,Mix<Int<800>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>>>,Mix<Int<5000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>,Pulsing<Mix<Int<5000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>,Mix<Int<5000>,RotateColorsX<Int<5000>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>,White>>,Mix<Int<11000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>>,2000>,Pulsing<Mix<Int<20000>,Black,RotateColorsX<Int<5000>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>>,Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>>,3000>>,AudioFlickerL<AlphaL<Black,Int<8000>>>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<16000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrColorCycleX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrInstant,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,255,203>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainMagneticLavaLampwithFlickerBaseColor>()
--------------------------------------------------------------------------*/
/*--------------------------------- MainCODARollingPulsewithUnstableSwingBaseColor -------------------------
copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.8 v1.015
Single Style
Base Style: CODA (Rolling Pulse with Unstable Swing)


--Effects Included--
Preon Effect: Overload [Color: PreonColorArg]
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Stable) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
CoolDown Effect: Power Flash [Color: RetractionColorArg]
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect: Flame Thrower Swing [Color: AltColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainCODARollingPulsewithUnstableSwingBaseColor = Layers<Layers<Mix<Sin<Int<3>>,AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,Stripes<5000,-90,Mix<Int<21200>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Mix<Int<16384>,Black,RotateColorsX<Int<30000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<12632>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>>,AudioFlicker<RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Stripes<5000,-90,Mix<Int<21672>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<26736>,Black,RotateColorsX<Int<31000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<26736>,Black,RotateColorsX<Int<28000>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>,Mix<Int<21000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>>>>,AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Int<31600>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Black>,Black,RotateColorsX<Int<31600>,RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>>,Black>,SwingSpeed<525>>>,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<30,144,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainCODARollingPulsewithUnstableSwingBaseColor>()
--------------------------------------------------------------------------*/
/*--------------------------------- ControlMainBladeofTalzinBaseColorAudioColorShift -------------------------
copyright Fett263 Ahsoka (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Ahsoka
OS7.11 v2.1
This Style Contains 2 Unique Combinations
Base Style: Blade of Talzin


--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Unstable Power Up Forward [Color: AltColorArg]
Retraction Effect Options: Default (0): Glitch Off, 1: Metal Forge (Cool Down) [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: RetractionColorArg]
PostOff Effect: Emitter Spark (Preon Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Sparking Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Emitter Effect: Unstable Flare [Color: EmitterColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Power Save: 10% Increment
*/
using ControlMainBladeofTalzinBaseColorAudioColorShift = Layers<StaticFire<Mix<SmoothStep<Scale<BladeAngle<>,Int<38000>,Int<23000>>,Int<8000>>,Mix<Int<400>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<894>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Mix<Int<6000>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<894>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,StripesX<Int<14000>,Scale<BladeAngle<>,Int<-5>,Int<-50>>,Mix<NoisySoundLevel,RotateColorsX<Int<894>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Scale<HoldPeakF<SwingSpeed<250>,Int<1000>,Int<8000>>,Int<6000>,Int<16000>>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<894>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,0,2,4,2000,2>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,14,0>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<3000,-3500,RgbArg<ALT_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,14,0>>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,14,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,14,0>>>>>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,97,0>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,97,0>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,97,0>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,97,0>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<0>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,TrConcat<TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,White,TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,DarkOrange,TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Red,TrFadeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Rgb<255,14,0>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,2000>,Sum<IntArg<PREON_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<3277>>,AlphaL<Black,Int<6554>>,AlphaL<Black,Int<9831>>,AlphaL<Black,Int<13108>>,AlphaL<Black,Int<16385>>,AlphaL<Black,Int<19662>>,AlphaL<Black,Int<22939>>,AlphaL<Black,Int<26216>>,AlphaL<Black,Int<29493>>,AlphaL<Black,Int<0>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,97,0>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<ControlMainBladeofTalzinBaseColorAudioColorShift>()
--------------------------------------------------------------------------*/
/*--------------------------------- FireBlade -------------------------
copyright Fett263 FireBlade (Primary Blade) OS7 Style
https://fett263library.com/early-access/#FireBlade
OS7.11 v2.1
Single Style
Base Style: Fire Blade Faster (Sparking)


--Effects Included--
Preon Effect: Erratic (Apocalypse Version) [Color: BaseColorArg]
Ignition Effect: Gravity Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: BaseColorArg]
Retraction Effect: Gravity Retraction [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: StabColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Responsive Clash with Wave [Color: BaseColorArg]
Emitter Effect: Emitter Heat Up [Color: EmitterColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
Power Save: 10% Increment
*/
using FireBlade = Layers<StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,4,0,3000,5>,AlphaL<TransitionEffect<Mix<NoisySoundLevel,RotateColorsX<Int<2280>,RgbArg<EMITTER_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<EMITTER_COLOR_ARG,Rgb<255,0,0>>>,AlphaL<Mix<NoisySoundLevel,RotateColorsX<Int<2280>,RgbArg<EMITTER_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<EMITTER_COLOR_ARG,Rgb<255,0,0>>>,Int<0>>,TrInstant,TrConcat<TrFade<1000>,Red,TrFade<1000>,Orange,TrFade<1000>>,EFFECT_IGNITION>,SmoothStep<IntArg<EMITTER_SIZE_ARG,5203>,Int<-6000>>>,TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Mix<NoisySoundLevel,RotateColorsX<Int<3150>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<3150>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Black>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Int<3150>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<3150>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<3150>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RotateColorsX<Int<3150>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,Black>,BrownNoiseFlicker<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<3855>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,Mix<Int<3855>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrWaveX<RotateColorsX<Int<4341>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrSelect<Scale<IsLessThan<BladeAngle<>,Int<18384>>,Scale<IsGreaterThan<SwingAcceleration<>,Int<16384>>,Int<0>,Int<2>>,Int<1>>,TrWipeInX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipe<100>>,TrSelect<Scale<IsLessThan<BladeAngle<>,Int<18384>>,Int<0>,Int<1>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,20992>,Int<98304>>>>,TrWipeX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,20992>,Int<98304>>>>>,Black>,TransitionEffectL<TrConcat<TrExtendX<Mult<WavLen<EFFECT_PREON>,Int<16384>>,TrInstant>,Layers<AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>,100>,RandomPerLEDFlicker<Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>,Mix<Int<8192>,Black,Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>,RotateColorsX<Int<4000>,Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>>>,RotateColorsX<Int<1200>,Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,AlphaL<HumpFlickerL<AlphaL<White,Trigger<EFFECT_PREON,Mult<WavLen<EFFECT_PREON>,Int<8176>>,WavLen<EFFECT_PREON>,Mult<WavLen<EFFECT_PREON>,Int<16384>>>>,40>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>>,TrLoopN<10,TrWaveX<Mix<NoisySoundLevel,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3363>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>>,Int<200>,Int<200>,Scale<Trigger<EFFECT_PREON,Int<0>,Mult<WavLen<EFFECT_PREON>,Int<24576>>,Mult<WavLen<EFFECT_PREON>,Int<8192>>>,Int<400>,Int<100>>,Int<0>>>>,EFFECT_PREON>,EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<3277>>,AlphaL<Black,Int<6554>>,AlphaL<Black,Int<9831>>,AlphaL<Black,Int<13108>>,AlphaL<Black,Int<16385>>,AlphaL<Black,Int<19662>>,AlphaL<Black,Int<22939>>,AlphaL<Black,Int<26216>>,AlphaL<Black,Int<29493>>,AlphaL<Black,Int<0>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<FireBlade>()
--------------------------------------------------------------------------*/
/*--------------------------------- yellowPurple -------------------------
copyright Fett263 Greyscale (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Greyscale
OS7.12 v2.2
Single Style
Base Style: Splinter (Swing Speed - Split Blade)


--Effects Included--
Preon Effect: Emitter Heat Up [Color: PreonColorArg]
Ignition Effect: Lightning Strike [Color: IgnitionColorArg]
Retraction Effect: Disassemble [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Forward [Color: AltColor3Arg]
PostOff Effect: Emitter Cool Off (Preon Size) [Color: BaseColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect: Flame Thrower Swing [Color: AltColor3Arg]
Emitter Effect: Unstable Flare with Random Pulse [Color: EmitterColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
Power Save: 10% Increment
*/
using YellowPurple = Layers<Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,Stripes<5000,-1300,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>,RotateColorsX<Int<800>,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>>,AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<24000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>>>>,TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<1000>>,Int<300>,Int<3000>>>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,0>>,Int<0>>,TrSparkX<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,0>>,Scale<NoisySoundLevel,Int<200>,Int<600>>,Int<250>,Int<0>>>>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,0>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,4474>,Sum<IntArg<EMITTER_SIZE_ARG,4474>,Int<6000>>>,Int<-6000>>>,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,-3500,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<255,255,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrConcat<TrWipeInX<Mult<IgnitionTime<300>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Black>,TrJoin<TrDelayX<Mult<IgnitionTime<300>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<300>,Int<19660>>>>,TrConcat<TrSparkX<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Int<100>,Mult<RetractionTime<0>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<26216>,Int<0>>>,TrSparkX<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Int<100>,Mult<RetractionTime<0>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<19662>,Int<0>>>,TrSparkX<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Int<100>,Mult<RetractionTime<0>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<13108>,Int<0>>>,TrSparkX<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Int<100>,Mult<RetractionTime<0>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<6554>,Int<0>>>,TrSparkX<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,Int<100>,Mult<RetractionTime<0>,Int<6554>>,Int<0>>>,Black>,TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrFade<100>>,AlphaL<HumpFlickerL<Mix<Trigger<EFFECT_PREON,Mult<WavLen<EFFECT_PREON>,Int<24000>>,WavLen<EFFECT_PREON>,Int<500>>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,White>,20>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-3000>>>,TrFade<200>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>,EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<3277>>,AlphaL<Black,Int<6554>>,AlphaL<Black,Int<9831>>,AlphaL<Black,Int<13108>>,AlphaL<Black,Int<16385>>,AlphaL<Black,Int<19662>>,AlphaL<Black,Int<22939>>,AlphaL<Black,Int<26216>>,AlphaL<Black,Int<29493>>,AlphaL<Black,Int<0>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<118,0,194>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<YellowPurple>()
--------------------------------------------------------------------------*/
/*--------------------------------- SideUnstableErraticAltColorBrightPulse -------------------------
copyright Fett263 UnstableBlades (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#UnstableBlades
OS7.14 v3.01p
Single Style
Base Style: Unstable Erratic


--Effects Included--

Effect Reaction: Unstable Wave Fast, BaseColorArg, Type: Responsive Center, Direction: Normal, Duration: 200, Consecutive Effects to Max: 3
Effect Reactions: Clash, Blast, LockupPreon Effect: Faulty Ignition (Volatile Version) [Color: AltColorArg (Bright Pulse = Shift: 4096, Speed: 20)
]
Ignition Effect: Cycle Up [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V2) [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
PostOff Effect: Emitter Cool Off (Emitter Size) [Color: PostOffColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect:
0: sideDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: sideMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Emitter Effect: Emitter Heat Up [Color: AltColor2Arg (Bright Pulse = Shift: 4096, Speed: 20)
]
*/
using SideUnstableErraticAltColorBrightPulse = Layers<StaticFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4391>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,6800>,Black,100>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4391>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,6800>>,Mix<Int<1285>,Black,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4391>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,6800>>>,Mix<Int<3212>,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4391>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,6800>,White>,Mix<Int<16384>,Black,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4391>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,6800>>>,Mix<Int<10280>,Black,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4391>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,6800>>,0,5,3,3000,0>,AlphaL<AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<20000>,Int<32000>>,Int<8000>>>,Stripes<4800,-1400,RandomPerLEDFlicker<Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<20000>,Int<32000>>,Int<8000>>,Int<16000>>>,HoldPeakF<Mult<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_BLAST>,LockupPulseF<SaberBase::LOCKUP_NORMAL>>,IncrementWithReset<ThresholdPulseF<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_BLAST>,LockupPulseF<SaberBase::LOCKUP_NORMAL>>,Int<30000>>,ThresholdPulseF<InvertF<HoldPeakF<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_BLAST>,LockupPulseF<SaberBase::LOCKUP_NORMAL>>,Int<500>,Int<8172>>>,Int<30000>>,Int<32768>,Int<10992>>>,Int<200>,Int<10000>>>,AlphaL<TransitionEffect<Pulsing<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>,2000>,AlphaL<Pulsing<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>,2000>,Int<0>>,TrInstant,TrConcat<TrFade<1000>,Red,TrFade<1000>,Orange,TrFade<1000>>,EFFECT_IGNITION>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrColorCycleX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,13992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4096>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,2000>,100>,RandomPerLEDFlicker<Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4096>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,2000>,Mix<Int<6425>,Black,RotateColorsX<Int<26000>,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4096>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,2000>>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4096>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,2000>,RotateColorsX<Int<26000>,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4096>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,2000>>>,RotateColorsX<Int<21845>,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,Mix<Int<4096>,RgbArg<ALT_COLOR_ARG,Rgb<0,51,255>>,White>,2000>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>>;
/*
Add to preset as StylePtr<SideUnstableErraticAltColorBrightPulse>()
--------------------------------------------------------------------------*/
/*--------------------------------- DigProtoSaberTest -------------------------
copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.01p
Single Style
Style Option

--Effects Included--

Effect Reaction: AudioFlicker, BaseColorArg, Type: Centered, Direction: Normal, Duration: 3000, Consecutive Effects to Max: 3
Effect Reactions: Clash, BlastPreon Effect: Faulty Ignition (Volatile Version) [Color: PreonColorArg]
Ignition Effect: Metal Forge (Heat Up) [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Metal Forge (Cool Down) [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: AltColor2Arg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Fire Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Fire Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Sparking Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: AltColor2Arg]
Emitter Effect: Unstable Flare with Random Pulse [Color: AltColor2Arg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
*/
using DigProtoSaberTest = Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,AlphaL<AlphaL<Remap<CenterDistF<>,AudioFlickerL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,Bump<Int<16384>,Int<40000>>>,HoldPeakF<Mult<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_BLAST>>,IncrementWithReset<ThresholdPulseF<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_BLAST>>,Int<30000>>,ThresholdPulseF<InvertF<HoldPeakF<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_BLAST>>,Int<500>,Int<8172>>>,Int<30000>>,Int<32768>,Int<10992>>>,Int<3000>,Int<10000>>>,TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<1000>>,Int<300>,Int<3000>>>,AlphaL<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Int<0>>,TrSparkX<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Scale<NoisySoundLevel,Int<200>,Int<600>>,Int<250>,Int<0>>>>,AlphaL<RandomPerLEDFlickerL<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>>>,BrownNoiseFlicker<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<20000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,AlphaL<RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<Stripes<2000,3000,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Layers<Stripes<2000,4000,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,Mix<Sin<Int<50>>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,Mix<Int<4096>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,TransitionPulseL<TrConcat<TrExtend<4000,TrInstant>,Stripes<2000,3000,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,Mix<Sin<Int<30>>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,Mix<Int<8192>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,TrFade<4000>>,LockupPulseF<SaberBase::LOCKUP_MELT>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrConcat<TrFadeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,Red,TrFadeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,DarkOrange,TrFadeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,White,TrFadeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrConcat<TrFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,White,TrFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,DarkOrange,TrFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Red,TrFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<6425>,Black,RotateColorsX<Int<26000>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,RotateColorsX<Int<26000>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>>,RotateColorsX<Int<21845>,RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<DigProtoSaberTest>()
--------------------------------------------------------------------------*/

#endif
