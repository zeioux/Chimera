#include <windows.h>
#include <winternl.h>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <string>

// des faux flags pour les strings.exe warriors
// lure 2 et 4 jamais affiches mais presents dans le binaire pour faire perdre du temps
__attribute__((used)) volatile const char* const LURE_1 = "FLAG{s1mpl3_xor_nub_lmao}";
__attribute__((used)) volatile const char* const LURE_2 = "FLAG{try_h4rd3r_buddy}";
__attribute__((used)) volatile const char* const LURE_3 = "FLAG{n0t_th1s_0n3_keep_d1gg1ng}";
__attribute__((used)) volatile const char* const LURE_4 = "FLAG{alm0st_th3r3_xD}";

// FLAG{Enf3r_Sur_T3rr3} encode
// enc[i] = (plain[i] ^ 0x5A) ^ (i*3+7)
static unsigned char G_ENC[] = {
    0x1B, 0x1C, 0x16, 0x0D, 0x32, 0x09, 0x2D, 0x20,
    0x76, 0x0A, 0x20, 0x21, 0x04, 0x06, 0x34, 0x3A,
    0x5E, 0x12, 0x15, 0x29, 0x64
};
static constexpr size_t FLAG_LEN = 21;

// FLAG{p01s0n_1s_sw33t} pre-encode pour le mode poison
// fake_enc[i] = plain[i] ^ (i*3+7)
// quand le pere est debogue -> fils affiche ca au lieu du vrai
static const unsigned char G_ENC_FAKE[] = {
    0x41, 0x46, 0x4C, 0x57, 0x68, 0x66, 0x29, 0x2D,
    0x6C, 0x12, 0x4B, 0x77, 0x1A, 0x5D, 0x6E, 0x47,
    0x40, 0x09, 0x0E, 0x34, 0x3E
};

