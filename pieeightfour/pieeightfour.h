#pragma once

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// There are a number of variations depending on the layout of your bottom row.
// The arrow variant adds an additional key on the bottom-right, while the
// command variant adds an additional key on the bottom-left. arrow-command is a
// combination of both of those, having an additional key on both sides.
//
// Please note that the numbering of the macro arguments are based on the
// numbers of the keys on the PCB.

#define LAYOUT( \
    K00, K01, K02, K03, \
    K10, K11, K12, K13, \
    K20, K21, K22, K23, \
    K30, K31, K32, K33,  \
    K40, K41, K42, K43,  \
    K50, K51, K52, K53,  \
    K60, K61, K62, K63,  \
    K70, K71, K72, K73  \
) \
{ \
    { K00,   K01,   K02,   K03 }, \
    { K10,   K11,   K12,   K13 }, \
    { K20,   K21,   K22,   K23 }, \
    { K30,   K31,   K32,   K33 },  \
    { K40,   K41,   K42,   K43 },  \
    { K50,   K51,   K52,   K53 },  \
    { K60,   K61,   K62,   K63 },  \
    { K70,   K71,   K72,   K73 }  \
}
