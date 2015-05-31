/*
 *File:   slackdsp_mini.c
 *
 *   Copyright © 2015 Ian Maltby
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "slackdsp_mini.h"
#include "sram.h"

//sine wavetable
const int sine[256] = {0, 804, 1607, 2410, 3211, 4011, 4808, 5602, 6392, 7179, 7961, 8739, 9512, 10278, 11039, 11793, 12539, 13278, 14010, 14732, 15446, 16151, 16846, 17530, 18204, 18868, 19519, 20159, 20787, 21403, 22005, 22594, 23170, 23732, 24279, 24812, 25330, 25832, 26319, 26790, 27245, 27684, 28106, 28511, 28898, 29269, 29621, 29956, 30273, 30572, 30852, 31114, 31357, 31581, 31786, 31971, 32138, 32285, 32413, 32521, 32610, 32679, 32728, 32758, 32767, 32758, 32728, 32679, 32610, 32521, 32413, 32285, 32138, 31971, 31785, 31580, 31356, 31114, 30852, 30572, 30273, 29956, 29621, 29269, 28898, 28510, 28105, 27684, 27245, 26790, 26319, 25832, 25329, 24812, 24279, 23732, 23170, 22594, 22005, 21403, 20787, 20159, 19519, 18867, 18204, 17530, 16846, 16151, 15446, 14732, 14009, 13278, 12539, 11792, 11039, 10278, 9511, 8739, 7961, 7179, 6392, 5601, 4807, 4010, 3211, 2410, 1607, 804, 0, -804, -1608, -2410, -3211, -4011, -4808, -5602, -6392, -7179, -7962, -8739, -9512, -10278, -11039, -11793, -12539, -13279, -14010, -14733, -15446, -16151, -16846, -17530, -18205, -18868, -19520, -20160, -20787, -21403, -22005, -22595, -23170, -23732, -24279, -24812, -25330, -25832, -26319, -26790, -27245, -27684, -28106, -28511, -28898, -29269, -29622, -29956, -30273, -30572, -30852, -31114, -31357, -31581, -31786, -31971, -32138, -32285, -32413, -32521, -32610, -32679, -32728, -32758, -32767, -32758, -32728, -32679, -32610, -32521, -32413, -32285, -32138, -31971, -31785, -31580, -31356, -31114, -30852, -30572, -30273, -29956, -29621, -29269, -28898, -28510, -28105, -27684, -27245, -26790, -26319, -25832, -25329, -24812, -24279, -23731, -23170, -22594, -22005, -21402, -20787, -20159, -19519, -18867, -18204, -17530, -16845, -16151, -15446, -14732, -14009, -13278, -12539, -11792, -11038, -10278, -9511, -8739, -7961, -7179, -6392, -5601, -4807, -4010, -3211, -2410, -1607, -803};
const int log_pot_scale[256] = {0, 5, 9, 13, 17, 22, 26, 31, 35, 40, 45, 50, 55, 60, 65, 71, 76, 82, 88, 93, 99, 105, 112, 118, 124, 131, 138, 144, 151, 158, 166, 173, 181, 188, 196, 204, 212, 221, 229, 238, 247, 256, 265, 274, 284, 294, 304, 314, 324, 335, 346, 357, 368, 380, 391, 403, 416, 428, 441, 454, 467, 480, 494, 508, 522, 537, 552, 567, 583, 598, 615, 631, 648, 665, 682, 700, 718, 737, 756, 775, 795, 815, 836, 857, 878, 900, 922, 945, 968, 991, 1015, 1040, 1065, 1091, 1117, 1143, 1170, 1198, 1226, 1255, 1285, 1315, 1345, 1377, 1408, 1441, 1474, 1508, 1542, 1578, 1613, 1650, 1688, 1726, 1765, 1804, 1845, 1886, 1928, 1971, 2015, 2060, 2106, 2152, 2200, 2248, 2298, 2348, 2400, 2452, 2506, 2560, 2616, 2673, 2731, 2790, 2851, 2912, 2975, 3039, 3105, 3172, 3240, 3309, 3380, 3452, 3526, 3601, 3678, 3757, 3837, 3918, 4001, 4086, 4173, 4261, 4351, 4443, 4537, 4633, 4730, 4830, 4932, 5035, 5141, 5249, 5359, 5471, 5586, 5703, 5822, 5944, 6068, 6195, 6324, 6456, 6590, 6727, 6867, 7010, 7156, 7304, 7456, 7610, 7768, 7929, 8093, 8261, 8432, 8606, 8784, 8966, 9151, 9340, 9533, 9729, 9930, 10134, 10343, 10556, 10773, 10995, 11221, 11452, 11687, 11928, 12173, 12423, 12678, 12938, 13203, 13474, 13750, 14032, 14319, 14613, 14912, 15217, 15529, 15847, 16171, 16501, 16839, 17183, 17534, 17892, 18258, 18631, 19011, 19399, 19795, 20199, 20611, 21032, 21461, 21898, 22345, 22800, 23265, 23739, 24222, 24716, 25219, 25733, 26257, 26791, 27336, 27893, 28460, 29039, 29630, 30232, 30847, 31474, 32114, 32767};
const int semitone_table[12] = {16384, 17358, 18390, 19483, 20642, 21870, 23170, 24548, 26007, 27554, 30928, 32767};
const int hypertri[1024] = {1986, 1969, 1952, 1935, 1918, 1902, 1885, 1869, 1853, 1836, 1820, 1804, 1788, 1772, 1756, 1741, 1725, 1710, 1694, 1679, 1664, 1648, 1633, 1618, 1603, 1589, 1574, 1559, 1545, 1530, 1516, 1501, 1487, 1473, 1459, 1445, 1431, 1417, 1403, 1390, 1376, 1363, 1349, 1336, 1323, 1309, 1296, 1283, 1270, 1257, 1245, 1232, 1219, 1207, 1194, 1182, 1169, 1157, 1145, 1133, 1121, 1109, 1097, 1085, 1073, 1061, 1050, 1038, 1027, 1015, 1004, 993, 982, 971, 960, 949, 938, 927, 916, 906, 895, 884, 874, 864, 853, 843, 833, 823, 813, 803, 793, 783, 773, 763, 754, 744, 735, 725, 716, 707, 697, 688, 679, 670, 661, 652, 643, 635, 626, 617, 609, 600, 592, 583, 575, 567, 558, 550, 542, 534, 526, 518, 511, 503, 495, 488, 480, 472, 465, 458, 450, 443, 436, 429, 422, 415, 408, 401, 394, 387, 381, 374, 368, 361, 355, 348, 342, 336, 329, 323, 317, 311, 305, 299, 293, 288, 282, 276, 271, 265, 260, 254, 249, 244, 238, 233, 228, 223, 218, 213, 208, 203, 198, 194, 189, 184, 180, 175, 171, 167, 162, 158, 154, 150, 146, 142, 138, 134, 130, 126, 122, 119, 115, 111, 108, 104, 101, 98, 94, 91, 88, 85, 82, 79, 76, 73, 70, 68, 65, 62, 60, 57, 55, 52, 50, 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 26, 24, 22, 21, 19, 18, 17, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 5, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 21, 22, 24, 26, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 50, 52, 55, 57, 60, 62, 65, 68, 70, 73, 76, 79, 82, 85, 88, 91, 94, 98, 101, 104, 108, 111, 115, 119, 122, 126, 130, 134, 138, 142, 146, 150, 154, 158, 162, 167, 171, 175, 180, 184, 189, 194, 198, 203, 208, 213, 218, 223, 228, 233, 238, 244, 249, 254, 260, 265, 271, 276, 282, 288, 293, 299, 305, 311, 317, 323, 329, 336, 342, 348, 355, 361, 368, 374, 381, 387, 394, 401, 408, 415, 422, 429, 436, 443, 450, 458, 465, 472, 480, 488, 495, 503, 511, 518, 526, 534, 542, 550, 558, 567, 575, 583, 592, 600, 609, 617, 626, 635, 643, 652, 661, 670, 679, 688, 697, 707, 716, 725, 735, 744, 754, 763, 773, 783, 793, 803, 813, 823, 833, 843, 853, 864, 874, 884, 895, 906, 916, 927, 938, 949, 960, 971, 982, 993, 1004, 1015, 1027, 1038, 1050, 1061, 1073, 1085, 1097, 1109, 1121, 1133, 1145, 1157, 1169, 1182, 1194, 1207, 1219, 1232, 1245, 1257, 1270, 1283, 1296, 1309, 1323, 1336, 1349, 1363, 1376, 1390, 1403, 1417, 1431, 1445, 1459, 1473, 1487, 1501, 1516, 1530, 1545, 1559, 1574, 1589, 1603, 1618, 1633, 1648, 1664, 1679, 1694, 1710, 1725, 1741, 1756, 1772, 1788, 1804, 1820, 1836, 1853, 1869, 1885, 1902, 1918, 1935, 1952, 1969, 1986, 2003, 2020, 2037, 2055, 2072, 2090, 2107, 2125, 2143, 2161, 2179, 2197, 2215, 2234, 2252, 2271, 2289, 2308, 2327, 2346, 2365, 2384, 2404, 2423, 2443, 2462, 2482, 2502, 2522, 2542, 2562, 2582, 2603, 2623, 2644, 2665, 2685, 2707, 2728, 2749, 2770, 2792, 2813, 2835, 2857, 2879, 2901, 2923, 2945, 2968, 2990, 3013, 3036, 3059, 3082, 3105, 3129, 3152, 3176, 3199, 3223, 3247, 3272, 3296, 3320, 3345, 3370, 3395, 3420, 3445, 3470, 3496, 3521, 3547, 3573, 3599, 3626, 3652, 3679, 3705, 3732, 3759, 3787, 3814, 3842, 3869, 3897, 3925, 3953, 3982, 4011, 4039, 4068, 4097, 4127, 4156, 4186, 4216, 4246, 4276, 4307, 4338, 4368, 4399, 4431, 4462, 4494, 4526, 4558, 4590, 4623, 4656, 4689, 4722, 4755, 4789, 4823, 4857, 4891, 4926, 4961, 4996, 5031, 5067, 5103, 5139, 5175, 5212, 5249, 5286, 5324, 5361, 5399, 5438, 5477, 5516, 5555, 5594, 5634, 5674, 5715, 5756, 5797, 5838, 5880, 5922, 5965, 6008, 6051, 6094, 6138, 6183, 6227, 6272, 6318, 6364, 6410, 6457, 6504, 6552, 6600, 6648, 6697, 6746, 6796, 6847, 6898, 6949, 7001, 7053, 7106, 7160, 7214, 7268, 7324, 7379, 7436, 7493, 7550, 7608, 7668, 7727, 7787, 7849, 7910, 7973, 8036, 8100, 8165, 8231, 8297, 8365, 8433, 8502, 8572, 8643, 8716, 8789, 8863, 8939, 9016, 9094, 9173, 9252, 9334, 9417, 9501, 9587, 9674, 9762, 9853, 9945, 10039, 10135, 10233, 10332, 10433, 10537, 10643, 10753, 10863, 10979, 11095, 11212, 11336, 11461, 11593, 11726, 11861, 12004, 12148, 12299, 12455, 12619, 12784, 12965, 13147, 13331, 13534, 13740, 13958, 14192, 14444, 14699, 14976, 15279, 15615, 15995, 16387, 16839, 17379, 17932, 18600, 19936, 20713, 20713, 20713, 19936, 18600, 17932, 17379, 16839, 16387, 15995, 15615, 15279, 14976, 14699, 14444, 14192, 13958, 13740, 13534, 13331, 13147, 12965, 12784, 12619, 12455, 12299, 12148, 12004, 11861, 11726, 11593, 11461, 11336, 11212, 11095, 10979, 10863, 10753, 10643, 10537, 10433, 10332, 10233, 10135, 10039, 9945, 9853, 9762, 9674, 9587, 9501, 9417, 9334, 9252, 9173, 9094, 9016, 8939, 8863, 8789, 8716, 8643, 8572, 8502, 8433, 8365, 8297, 8231, 8165, 8100, 8036, 7973, 7910, 7849, 7787, 7727, 7668, 7608, 7550, 7493, 7436, 7379, 7324, 7268, 7214, 7160, 7106, 7053, 7001, 6949, 6898, 6847, 6796, 6746, 6697, 6648, 6600, 6552, 6504, 6457, 6410, 6364, 6318, 6272, 6227, 6183, 6138, 6094, 6051, 6008, 5965, 5922, 5880, 5838, 5797, 5756, 5715, 5674, 5634, 5594, 5555, 5516, 5477, 5438, 5399, 5361, 5324, 5286, 5249, 5212, 5175, 5139, 5103, 5067, 5031, 4996, 4961, 4926, 4891, 4857, 4823, 4789, 4755, 4722, 4689, 4656, 4623, 4590, 4558, 4526, 4494, 4462, 4431, 4399, 4368, 4338, 4307, 4276, 4246, 4216, 4186, 4156, 4127, 4097, 4068, 4039, 4011, 3982, 3953, 3925, 3897, 3869, 3842, 3814, 3787, 3759, 3732, 3705, 3679, 3652, 3626, 3599, 3573, 3547, 3521, 3496, 3470, 3445, 3420, 3395, 3370, 3345, 3320, 3296, 3272, 3247, 3223, 3199, 3176, 3152, 3129, 3105, 3082, 3059, 3036, 3013, 2990, 2968, 2945, 2923, 2901, 2879, 2857, 2835, 2813, 2792, 2770, 2749, 2728, 2707, 2685, 2665, 2644, 2623, 2603, 2582, 2562, 2542, 2522, 2502, 2482, 2462, 2443, 2423, 2404, 2384, 2365, 2346, 2327, 2308, 2289, 2271, 2252, 2234, 2215, 2197, 2179, 2161, 2143, 2125, 2107, 2090, 2072, 2055, 2037, 2020, 2003};


//delayline

int delayline(long d_length, long d_time, int d_mod, int d_in) {

    static long writeaddress;
    static long readaddress;
    int d_out;

    writeaddress = (writeaddress + 2) & (d_length - 1);
    readaddress = (writeaddress + d_length - d_time + d_mod) & (d_length - 2);
    sram_write(writeaddress, d_in);
    d_out = sram_read(readaddress);
    return (d_out);
}


//mulx

int mulx(int m_in1, int m_in2) {

    long sample32;

    sample32 = m_in1 * (long) m_in2;

    return (sample32 >> 15);

}

//add

int add(int a_in1, int a_in2) {

    long sample32;

    sample32 = a_in1 + (long) a_in2;
    if (sample32 < -32768)
        sample32 = -32768;
    if (sample32 > 32767)
        sample32 = 32767;

    return (sample32);

}

//clipper

int clip(int c_level, int c_in) {

    if (c_in < -c_level)
        c_in = -c_level;
    if (c_in > c_level)
        c_in = c_level;

    return (c_in);
}


//pitchshifter

int pitchshift(int s_shift, int s_in) {

#define slength 2048

    static int buffer[slength];
    static int writeaddress;
    static int readaddress;
    long sample1;
    long sample2;
    int env;
    static long counter;

    writeaddress = (writeaddress + 1) & (slength - 1);
    buffer[writeaddress] = s_in;

    counter = counter + s_shift;
    if (counter > 32767) {
        counter = counter & 32767;
        readaddress = (readaddress + 2) & (slength - 1);
    }

    env = (writeaddress - readaddress) << 5;
    if (env < 0)
        env = ~env;

    sample1 = buffer[readaddress];
    sample2 = buffer[((readaddress + (slength / 2)) & (slength - 1))];
    sample1 = (sample1 * env);
    sample2 = (sample2 * (32767 - env));

    return ((sample1 + sample2) >> 15);
}

//lowpass filter

int lowpass(int lp_freq, int lp_in) {

    static long lp_out = 0;

    lp_out = ((((lp_in - lp_out) * lp_freq) >> 15) + lp_out);

    return (lp_out);
}

//highpass filter

int hipass(int hp_freq, int hp_in) {

    int hp_out;
    static long h_lp = 0;

    hp_out = ((((hp_in - h_lp) * hp_freq) >> 15) + h_lp) - hp_in;

    return (hp_out);

}
//VCO

int vco(long v_speed) {

    static long counter = 0;

    counter = (counter + v_speed) & 32767;

    return (sine[counter >> 7]);

}

//random number generator

int random(void) {
    static long lfsr = 1234;
    int xorbit;
#define bit1 28
#define bit2 31
    xorbit = ((lfsr >> (bit1 - 1) ^ (lfsr >> (bit2 - 1)))) & 1;
    lfsr = (lfsr << 1 | xorbit);
    return (lfsr);
}

//crossfade two signals

int crossfade(int cf_ctrl, int in_1, int in_2) {

    long sample32;

    sample32 = ~in_1 + (long) in_2;
    sample32 = (cf_ctrl * sample32) >> 15;
    sample32 = sample32 + in_1;

    return (sample32);

}

//gain and clipper

int gain(int g_level, int gc_level, int g_in) {

    long sample32;

    sample32 = (g_level >> 5) * (long) g_in;

    if (sample32 < -gc_level)
        sample32 = -gc_level;
    if (sample32 > gc_level)
        sample32 = gc_level;

    return (sample32);
}

int pitchshift2(int s_shift, int s_in) {

#define slength2 2048

    static int buffer2[slength2];
    static int writeaddress2;
    static int readaddress2;
    long sample1;
    long sample2;
    int env;
    static long counter2;

    writeaddress2 = (writeaddress2 + 1) & (slength2 - 1);
    buffer2[writeaddress2] = s_in;

    counter2 = counter2 + s_shift;
    if (counter2 > 32767) {
        counter2 = counter2 & 32767;
        readaddress2 = (readaddress2 + 2) & (slength2 - 1);
    }

    env = (writeaddress2 - readaddress2) << 5;
    if (env < 0)
        env = ~env;

    sample1 = buffer2[readaddress2];
    sample2 = buffer2[((readaddress2 + (slength2 / 2)) & (slength2 - 1))];
    sample1 = (sample1 * env);
    sample2 = (sample2 * (32767 - env));

    return ((sample1 + sample2) >> 15);
}

//Semitone

int semitones(int st_in) {

    return (semitone_table[st_in]);
}

//Saw LFO

int saw_lfo(int saw_speed) {

    static long saw_counter = 0;
    static int saw_out = 0;

    saw_counter = saw_counter + saw_speed;
    if (saw_counter > 32767) {
        saw_counter = saw_counter & 32767;
        saw_out = (saw_out + 32) & 32767;
    }
    return (saw_out);

}

//Tri LFO

int tri_lfo(int tri_speed) {

    static long tri_counter = 0;
    static long tri = 0;
    int tri_out = 0;

    tri_counter = tri_counter + tri_speed;
    if (tri_counter > 32767) {
        tri_counter = tri_counter & 32767;
        tri = (tri + 64) & 65535;
    }
    tri_out = tri - 32767;
    if (tri_out < 0)
        tri_out = ~tri_out;

    return (tri_out);

}

int logpot(int logpot_in) {

    return (log_pot_scale[logpot_in >> 7]);

}

//State Variable Filter
//http://www.musicdsp.org/showArchiveComment.php?ArchiveID=142

int svf(int svf_freq, int svf_q, int svf_type, int svf_in) {

    static long low = 0;
    static long band = 0;
    long high;

    low = low + ((svf_freq * band) >> 15);
    high = svf_in - low - ((svf_q * band) >> 15);
    band = ((svf_freq * high) >> 15) + band;

    if (band < -32767)
        band = -32767;
    if (band > 32767)
        band = 32767;

    if (svf_type == bp)
        return (band);

    if (svf_type == hp)
        return (high);

    else

        return (low);

}

//reverse delayline

int revdelay(long rd_length, long rd_time, int rd_in) {

    static long rdwriteaddress = 0;
    static long rdreadaddress = 0;
    int rd_out;

    rdwriteaddress = (rdwriteaddress + 2);
    if (rdwriteaddress > rd_time)
        rdwriteaddress = 0;

    rdreadaddress = (rdreadaddress - 2);
    if (rdreadaddress < 0)
        rdreadaddress = rd_time;

    sram_write(rdwriteaddress, rd_in);
    rd_out = sram_read(rdreadaddress);
    return (rd_out);
}

//blend

int blend(int b_ctrl, int b_in_1, int b_in_2) {

    long sample32;
    long ctrl1;
    long ctrl2;

    ctrl2 = b_ctrl;
    if (ctrl2 > 16383)
        ctrl2 = 16383;

    ctrl1 = ~b_ctrl;
    if (ctrl1 > -16383)
        ctrl1 = 16383;
    else
        ctrl1 = ctrl1 + 32767;

    sample32 = (ctrl1 * b_in_1) + (ctrl2 * b_in_2);

    return (sample32 >> 14);

}

//Random LFO

int random_lfo(int random_speed) {

    static long random_counter = 0;
    static int random_out = 0;

    random_counter = random_counter + random_speed;
    if (random_counter > 33554431) {
        random_counter = random_counter & 33554431;
        random_out = rand();

    }
    return (random_out);

}

//envelope follower
//http://www.musicdsp.org/archive.php?classid=0#136

int envelope(int env_attack, int env_release, int env_in) {

    static long env_out = 0;
    int temp;

    temp = abs(env_in);

    if (env_out < temp)
        env_out = temp + ((env_attack * (env_out - temp)) >> 15);

    else

        env_out = temp + ((env_release * (env_out - temp)) >> 15);

    return (env_out);

}

//hyper_tri LFO

int hyper_tri_lfo(long hpt_speed) {

    static long hpt_counter = 0;
    static int pos = 0;

    hpt_counter = hpt_counter + hpt_speed;
    if (hpt_counter > 32767) {
        hpt_counter = hpt_counter & 32767;
        pos = (pos + 1) & 1023;

    }

    return (hypertri[pos]);
}

//serial_send - sends a 16 bit int to the serial port once per second

void serial_send(int s_out) {

    static int serial_delay = 0;

    serial_delay = serial_delay + 1;

    if (serial_delay == 32000) {
        serial_delay = 0;
        U1TXREG = s_out >> 8;
        U1TXREG = s_out;

    }
}