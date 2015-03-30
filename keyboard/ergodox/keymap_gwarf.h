#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "debug.h"
#include "keymap.h"
#define ONESHOTMOD_REFERENCE_LAYER 2
#define SHIFT_KEY_REFERENCE_LAYER 2
#define ONESHOT_TIMEOUT 0
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  |  F5  |           |  F6  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   |   Q  |   W  |   E  |   R  |   T  |  `   |           | ESC  |   Y  |   U  |   I  |   O  |   P  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  ESC   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    "   |
     * |--------+------+------+------+------+------|MOUSE |           | TAB  |------+------+------+------+------+--------|
     * | LCTRL  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | shift  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L1  | ~L9  | +L3  | LAlt | LCTL |                                       |  Lft |  Up  |  Dn  | Rght | ~L6  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |SFTCTL| LALT |       | RALT |SFTCTL|
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LMETA|       | RMETA|      |      |
     *                                 | BkSp | ENTR |------|       |------|  ~L1 | Space|
     *                                 | Shift|      | LCTL |       | RCTL | TAB  | Shift|
     *                                 `--------------------'       `--------------------'
     *
     ****************************************************************************************************
     *
     * FN4 is ~9 and with the key left of 1, its the teensy key combo
     * todo: replace lmeta and rmeta with layers.
     * Since I always use it for gui commands, it would make sense to do
     * tap key hold action with a layer toggle making the cluster
     * different. This also makes sense with bksp and space. Actually,
     * using space/bksp as shift makes a lot of sense.
     */

/*
 * I'd like to have no combo keys required.  that means all modifiers should be toggle-able
 * the question is "Should it act like sticky keys or just be oneshot?"
 * That was the original thought.
 * Turns out, sticky modifiers are annoying
 */

#define KC_COMBO(keys) keys

    KEYMAP(  // Layer0: default
        // left hand
          GRV,   1,   2,   3,   4,   5,   F5,
          TAB,   Q,   W,   E,   R,   T,   GRV,
          ESC,   A,   S,   D,   F,   G,
         LCTL,   Z,   X,   C,   V,   B,   FN2,
          FN3, FN4, FN3,LALT,LCTL,
                                      FN15,LALT,
                                           LGUI,
                              BSPACE, ENTER, LCTL,
        // right hand
           F6,    6,    7,     8,   9,    0, MINS,
         FN13,    Y,    U,     I,   O,    P, BSLS,
                  H,    J,     K,   L, SCLN, QUOT,
          TAB,    N,    M,  COMM, DOT, SLSH, RSFT,
         LEFT,   UP, DOWN, RIGHT, F12,
         RALT, FN15,
         RGUI,
         RCTL, FN17, SPACE
    ),

     /*
     * This layout is based off "Blueshift".  There should be a link, but a google for ergodox and blueshift should get it.
     * I may have missed a few keys or changed them and not updated the docs
     *
     ****************************************************************************************************
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  App   |   f1 |  f2  |  f3  |  f4  |   f5 |  f6  |           |  f7  |  f8  |  f9  |  f10 |  f11 | f12  | PgUp   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Home  |   !  |   @  |   #  |   $  |   %  |  =>  |           |      |   ^  |   &  |   *  |   (  |   )  | PgDn   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  End   |   [  |   ]  |   +  |   '  |   "  |------|           |------| left | down |  up  |right |   |  |        |
     * |--------+------+------+------+------+------|  ->  |           |      |------+------+------+------+------+--------j
     * |LCtl+Sft|   {  |   }  |   -  |   \  |   =  |      |           |      |  !   |   :  |   <  |   >  |   _  |LCtl+Sft|
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Vol+ | Vol- |Next  |      |      |                                       | Ins  | Del  |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | ???  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 | ESC  | TAB  |------|       |------|  TAB | Enter|
     *                                 |      |      | RCTL |       | RCTL |      |      |
     *                                 `--------------------'       `--------------------'
     *
     */

    KEYMAP(  // Layer1: blueshift
        // left hand
        APP,  F1,  F2,  F3,  F4,  F5,  F6,
        TAB,FN14,FN14,FN14,FN14,FN14,FN11,
         ESC,LBRC,RBRC,FN14,QUOT,FN14,
        LSFT,FN14,FN14,MINS,BSLS, EQL,FN12,
        VOLU,VOLD,MNXT,TRNS,TRNS,
                                        TRNS,TRNS,
                                           TRNS,
                              ESC, FN1,  LCTL,
        // right hand
        F7, F8, F9, F10, F11, F12, PGUP,
          NO,FN14,FN14,FN14,FN14,FN14,PGDN,
        LEFT,DOWN,  UP,RIGHT,FN14,TRNS,
          NO,FN14,INS,HOME,PGUP,FN14,FN15,
                  DEL, END,PGDN,  NO,  NO,
        TRNS,FN14,
        TRNS,
        TRNS, FN1, ENTER
    ),

/*
    KEYMAP(
        // left hand
        // layer 2 is for blueshift FN14
        TRNS,  NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,   1,   2,   3,   4,   5,TRNS,
        TRNS,  NO,  NO, EQL,  NO,QUOT,
        LSFT,LBRC,RBRC,  NO,  NO,QUOT,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,LALT,
                                           LGUI,
                                  TRNS,FN1,LCTL,

        // right hand
             TRNS,NO,  NO,  NO,  NO,  NO,  NO,
             TRNS,6,7,8,9,0,PGUP,
                  NO,  NO,  NO,  NO,BSLS,  NO,
               NO,   1, SCLN,COMM, DOT,MINS,  NO,
                         NO,  NO,  NO,  NO,  NO,
        RALT,TRNS,
        RGUI,
        RCTL,FN1,TRNS
    ),

    KEYMAP(  // Layer3: experimental mouse key layer
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  TRNS,NO,  NO,  NO,
        TRNS,NO,  TRNS,NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             BTN3,NO,  NO,  NO,  NO,  NO,  NO,
             BTN1,WH_L,WH_D,WH_U,WH_R,WH_R,PGUP,
             MS_L,MS_D,MS_U,MS_R,PGDN,TRNS,
             BTN2,BTN2,HOME,END, DEL, INS, NO,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // Layer4: norman
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,   D,   F,   K,TRNS,
        TRNS,TRNS,TRNS,   E,   T,   G,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS, FN3,TRNS,TRNS,
                                      FN15,LALT,
                                           LGUI,
                              FN10, FN16, LCTL,

        // in Workman right hand will be:
        //              +
        //    ^ { } ( ) =
        //    ' ! $ " ; \
        //    # [ < > ] \
        //

        // right hand
             TRNS,   J,   U,   R,   L,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,SCLN,TRNS,
                     Y,   N,   I,   O,   H,TRNS,
             TRNS,   P,   M,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        RALT,FN15,
        RGUI,
        RCTL, FN17, FN9
    ),
        // right hand



    KEYMAP(  // Layer5: F-keys instead of numbers, leftled:red
        // left hand
        FN0,F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer6: F-keys, cursor, Workman-layer switch, Teensy, leftled:red+onboard
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,
        FN0, NO,  PGUP,UP,  PGDN,PGUP,TRNS,
        TRNS,NO,  LEFT,DOWN,RGHT,PGDN,
        TRNS,INS, DEL, END, HOME,NO,  TRNS,
        FN18,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, MINS,
             TRNS,PGUP,PGUP,UP,  PGDN,NO,  FN0,
                  PGDN,LEFT,DOWN,RGHT,NO,  TRNS,
             TRNS,NO,  HOME,END, DEL, INS, TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

/*
    //
    // rarely used
    //

    KEYMAP(  // Layer7: F-keys only, leftled:red
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,F13, F14, F15, F16, NO,  TRNS,
        TRNS,F17, F18, F19, F20, NO,
        TRNS,F21, F22, F23, F24, NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  F1,  F2,  F3,  F4,  TRNS,
                  NO,  F5,  F6,  F7,  F8,  TRNS,
             TRNS,NO,  F9,  F10, F11, F12, TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer8: mouse and navigation, leftled:blue and green
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  TRNS,NO,  NO,
        TRNS,NO,  NO,  TRNS,NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // right hand
             TRNS,NO,  NO,  NO,  NO,  NO,  NO,
             TRNS,BTN2,WH_L,WH_U,WH_D,WH_R,PGUP,
                  BTN1,MS_L,MS_U,MS_D,MS_R,PGDN,
             TRNS,BTN3,HOME,END, DEL, INS, NO,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
    KEYMAP(  // Layer9: numpad, leftled:blue
        // left hand
         FN0,NO,  NO,  NO,  NO,  PAUS,PSCR,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  TRNS,NO,
        TRNS,NO,  NO,  NO,  TRNS,NO,  TRNS,
        TRNS,TRNS,FN2,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             SLCK,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,PGUP,
                  TRNS,P4,  P5,  P6,  PPLS,PGDN,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
    ONE_SHOT_MOD,
    ESCAPE_WRAPPER,
    SHIFT_KEY
};

enum macro_id {
    LSHIFT_LBRACE,
    LSHIFT_RBRACE,
    LSHIFT_LT,
    LSHIFT_GT,
    HELLO,
    VOLUP,
    FAT_ARROW,
    THIN_ARROW
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    ACTION_LAYER_MOMENTARY(1),                      // FN1 - Momentary toggle layer one for blueshift
    ACTION_LAYER_MOMENTARY(3),                      // FN2 - Momentary toggle layer 3 for mouse
    ACTION_LAYER_TOGGLE(4),                         // FN3 - Momentary toggle layer 4 for norman layout
    ACTION_LAYER_MOMENTARY(9),                      // FN4 - toggle layer 9 for teensy boot key

    ACTION_MACRO_TAP(LSHIFT_LT),                    // FN5 - <
    ACTION_MACRO_TAP(LSHIFT_GT),                    // FN6 - >
    ACTION_MACRO_TAP(LSHIFT_LBRACE),                // FN7 - {
    ACTION_MACRO_TAP(LSHIFT_RBRACE),                // FN8 - }

    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SPC),          // FN9 = space/shift key
    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_BSPC),         // FN10 = bspace/shift key

    ACTION_MACRO(FAT_ARROW),                        // FN11 = Fat arrow =>
    ACTION_MACRO(THIN_ARROW),                       // FN12 = Thin arrow ->
    ACTION_FUNCTION(ESCAPE_WRAPPER),                // FN13 = clear oneshot and send esc.
    ACTION_FUNCTION(SHIFT_KEY),                     // FN14 = shifted numbers
    ACTION_MODS(MOD_RCTL| MOD_RGUI),                // FN15 = ctrl + gui
    //ACTION_LAYER_TAP_KEY(1, KC_ESC),                // FN16 - momentary Layer5 on Enter, to use with F* keys on top row
    //ACTION_LAYER_TAP_KEY(1, KC_TAB),                // FN17 - momentary Layer5 on Enter, to use with F* keys on top row

    ACTION_LAYER_SET(1, ON_BOTH),                   // FN18 - set Layer1, to use Workman layout at firmware level
    ACTION_LAYER_SET(2, ON_BOTH),                   // FN19 - set Layer2, to use with Numpad keys

    //ACTION_LAYER_MOMENTARY(2),                      // FN20 - momentary Layer2, to use with Numpad keys
    //ACTION_LAYER_TAP_KEY(5, KC_ENT),                // FN21 - momentary Layer5 on Enter, to use with F* keys on top row
    //ACTION_LAYER_TAP_KEY(6, KC_ENT),                // FN22 - momentary Layer6 on Enter, to use with F* keys on top row, cursor, Teensy, Workman-layer switch
    //ACTION_LAYER_MOMENTARY(7),                      // FN23 - momentary Layer7, to use with F* keys (F1-F24)

    //ACTION_LAYER_TAP_KEY(4, KC_Z),                  // FN24 = momentary Layer4 on Z key, to use with unconvenient keys
    //ACTION_LAYER_TAP_KEY(3, KC_X),                  // FN25 = momentary Layer3 on X key, to use with F* keys
    //ACTION_LAYER_TAP_KEY(8, KC_C),                  // FN26 = momentary Layer8 on C key, to use with mouse and navigation keys
    //ACTION_LAYER_TAP_KEY(2, KC_V),                  // FN27 = momentary Layer2 on V key, to use with Numpad keys

    // i'd like to remove this - will try to get used to live without this and convert them to usual keys
    //ACTION_LAYER_TAP_KEY(4, KC_A),                  // FN28 = momentary Layer4 on A key, to use with unconvenient keys
    //ACTION_LAYER_TAP_KEY(3, KC_S),                  // FN29 = momentary Layer3 on S key, to use with F* keys
    //ACTION_LAYER_TAP_KEY(8, KC_D),                  // FN30 = momentary Layer8 on D key, to use with mouse and navigation keys
    //ACTION_LAYER_TAP_KEY(2, KC_F),                  // FN31 = momentary Layer2 on F key, to use with Numpad keys
};





/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt);



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt);
