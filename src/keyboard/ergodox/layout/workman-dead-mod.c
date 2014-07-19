/* ----------------------------------------------------------------------------
* ergoDOX layout : Workman Dead via JC's Sticky Keys Mod
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>,
*    2013 Ryan Prince <judascleric@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// DEFINITIONS ----------------------------------------------------------------
#define  kprrel   &kbfun_press_release
#define  kprpst   &kbfun_press_release_preserve_sticky
#define  mprrel   &kbfun_mediakey_press_release
#define  ktrans   &kbfun_transparent
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lsticky1   &kbfun_layer_sticky_1
#define  lsticky2   &kbfun_layer_sticky_2
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
    // unused
    0,
    // left hand
    _equal,		_1,		_2,	_3,	_4,	_5,	_esc,
    _dash,		_Q,		_D,	_R,	_W,	_B,	_tab,
    0,			_A,		_S,	_H,	_T,	_G,
    _shiftL,	_Z,		_X,	_M,	_C,	_V,	_guiL,
    0,			_grave,	0,	0,	0,
    // thumb block
            0,		0,
    0,		0,		_altL,
    _bs,	_del,	_ctrlL,
    // right hand
    _esc,	_6,			_7,			_8,			_9,			_0,			_backslash,
    _tab,	_J,			_F,			_U,			_P,			_semicolon,	0,
            _Y,			_N,			_E,			_O,			_I,			_quote,
    _guiR,  _K,			_L,			1,			_period,	_slash,		_shiftR,
            _arrowU,	_arrowD,	_arrowL,	_arrowR, 0,
    // thumb block
    0,		0,
    _altR,	0,		0,
    _ctrlR,	_enter,	_space
),
// LAYER 1
KB_MATRIX_LAYER(
    // unused
    0,
    // left hand
    0,	0,			0,			0,			0,			0,		0,
    0,	_bracketR,	_bracketR,	_0,			_add_kp,	_2,		0,
    0,	_bracketL,	_bracketL,	_9,			_equal_kp,	0,
    0,	_comma,		_period,	_backslash,	_dash,		_dash,	0,
    0,	0,			0,			0,			0,
    // thumb block
    0,	0,
    0,	0,	0,
    0,	0,	0,
    // right hand
    0,	0,			0,			0,		0,	0,		0,
    0,	0,			0,			0,		0,	0,		0,
    0,	0,			0,			0,		0,	0,
    0,	_semicolon,	_semicolon,	_slash,	_1,	_grave,	0,
    0,	0,			0,			0,		0,
    // thumb block
    0,	0,
    0,	0,	0,
    0,	0,	_comma
),
};
// ----------------------------------------------------------------------------

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
    //unused
    NULL,
    // left hand
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    NULL,	kprrel,	NULL,	NULL,	NULL,
    NULL,	NULL,
    NULL,	NULL,	kprrel,
    kprrel,	kprrel,	kprrel,
    // right hand
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	lsticky1,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	NULL,
    NULL,	NULL,
    kprrel,	NULL,	NULL,
    kprrel,	kprrel,	kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
    // unused
    NULL,
    // left hand
    ktrans,	ktrans,		ktrans,		ktrans,		ktrans,		ktrans,		ktrans,
    ktrans,	kprrel,		sshprre,	sshprre,	sshprre,	sshprre,	ktrans,
    ktrans,	kprrel,		sshprre,	sshprre,	sshprre,	ktrans,
    ktrans,	sshprre,	sshprre,	sshprre,	kprrel,		sshprre,	ktrans,
    NULL,	ktrans,		ktrans,		ktrans,		ktrans,
    NULL,	NULL,
    NULL,	NULL,	ktrans,
    ktrans,	ktrans,	ktrans,
    // right hand
    ktrans,	ktrans,		ktrans,		ktrans,		ktrans,		ktrans,		ktrans,
    ktrans,	ktrans,	ktrans,	ktrans,		ktrans,		ktrans,		ktrans,
    ktrans,	ktrans,	ktrans,	ktrans,		ktrans,		ktrans,
    ktrans,	kprrel,		sshprre,	sshprre,	sshprre,	sshprre,	ktrans,
    ktrans,	ktrans,		ktrans,		ktrans,		ktrans,
    NULL,	NULL,
    ktrans,	NULL,	NULL,
    ktrans,	ktrans,	kprrel
),
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
    // unused
    NULL,
    // left hand
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    NULL,	kprrel,	NULL,	NULL,	NULL,
    NULL,	NULL,
    NULL,	NULL,	kprrel,
    kprrel,	kprrel,	kprrel,
    // right hand
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,
    kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	lsticky1,	kprrel,	kprrel,	kprrel,
    kprrel,	kprrel,	kprrel,	kprrel,	NULL,
    NULL,	NULL,
    kprrel,	NULL,	NULL,
    kprrel,	kprrel,	kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
    // unused
    NULL,
    // left hand
    ktrans,	ktrans,		ktrans,		ktrans,		ktrans,		ktrans,		ktrans,
    ktrans,	kprrel,		sshprre,	sshprre,	sshprre,	sshprre,	ktrans,
    ktrans,	kprrel,		sshprre,	sshprre,	sshprre,	ktrans,
    ktrans,	sshprre,	sshprre,	sshprre,	kprrel,		sshprre,	ktrans,
    ktrans,	ktrans,		ktrans,		ktrans,		ktrans,
    NULL,	NULL,
    NULL,	NULL,	ktrans,
    ktrans,	ktrans,	ktrans,
    // right hand
    ktrans,	ktrans,		ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
    ktrans,	ktrans,		ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
    ktrans,	ktrans,		ktrans,	ktrans,	ktrans,	ktrans,
    ktrans,	kprrel,		sshprre,	sshprre,	sshprre,	sshprre,	ktrans,
    ktrans,	ktrans,		ktrans,	ktrans,	ktrans,
    NULL,	NULL,
    ktrans,	NULL,	NULL,
    ktrans,	ktrans,	kprrel
),
};
// ----------------------------------------------------------------------------
