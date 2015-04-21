#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "slackdsp_mini.h"
#include "sram.h"

//sine wavetable
const int sine[256] = {0, 804, 1607, 2410, 3211, 4011, 4808, 5602, 6392, 7179, 7961, 8739, 9512, 10278, 11039, 11793, 12539, 13278, 14010, 14732, 15446, 16151, 16846, 17530, 18204, 18868, 19519, 20159, 20787, 21403, 22005, 22594, 23170, 23732, 24279, 24812, 25330, 25832, 26319, 26790, 27245, 27684, 28106, 28511, 28898, 29269, 29621, 29956, 30273, 30572, 30852, 31114, 31357, 31581, 31786, 31971, 32138, 32285, 32413, 32521, 32610, 32679, 32728, 32758, 32767, 32758, 32728, 32679, 32610, 32521, 32413, 32285, 32138, 31971, 31785, 31580, 31356, 31114, 30852, 30572, 30273, 29956, 29621, 29269, 28898, 28510, 28105, 27684, 27245, 26790, 26319, 25832, 25329, 24812, 24279, 23732, 23170, 22594, 22005, 21403, 20787, 20159, 19519, 18867, 18204, 17530, 16846, 16151, 15446, 14732, 14009, 13278, 12539, 11792, 11039, 10278, 9511, 8739, 7961, 7179, 6392, 5601, 4807, 4010, 3211, 2410, 1607, 804, 0, -804, -1608, -2410, -3211, -4011, -4808, -5602, -6392, -7179, -7962, -8739, -9512, -10278, -11039, -11793, -12539, -13279, -14010, -14733, -15446, -16151, -16846, -17530, -18205, -18868, -19520, -20160, -20787, -21403, -22005, -22595, -23170, -23732, -24279, -24812, -25330, -25832, -26319, -26790, -27245, -27684, -28106, -28511, -28898, -29269, -29622, -29956, -30273, -30572, -30852, -31114, -31357, -31581, -31786, -31971, -32138, -32285, -32413, -32521, -32610, -32679, -32728, -32758, -32767, -32758, -32728, -32679, -32610, -32521, -32413, -32285, -32138, -31971, -31785, -31580, -31356, -31114, -30852, -30572, -30273, -29956, -29621, -29269, -28898, -28510, -28105, -27684, -27245, -26790, -26319, -25832, -25329, -24812, -24279, -23731, -23170, -22594, -22005, -21402, -20787, -20159, -19519, -18867, -18204, -17530, -16845, -16151, -15446, -14732, -14009, -13278, -12539, -11792, -11038, -10278, -9511, -8739, -7961, -7179, -6392, -5601, -4807, -4010, -3211, -2410, -1607, -803};
const int log_pot_scale[256] = {0, 5, 9, 13, 17, 22, 26, 31, 35, 40, 45, 50, 55, 60, 65, 71, 76, 82, 88, 93, 99, 105, 112, 118, 124, 131, 138, 144, 151, 158, 166, 173, 181, 188, 196, 204, 212, 221, 229, 238, 247, 256, 265, 274, 284, 294, 304, 314, 324, 335, 346, 357, 368, 380, 391, 403, 416, 428, 441, 454, 467, 480, 494, 508, 522, 537, 552, 567, 583, 598, 615, 631, 648, 665, 682, 700, 718, 737, 756, 775, 795, 815, 836, 857, 878, 900, 922, 945, 968, 991, 1015, 1040, 1065, 1091, 1117, 1143, 1170, 1198, 1226, 1255, 1285, 1315, 1345, 1377, 1408, 1441, 1474, 1508, 1542, 1578, 1613, 1650, 1688, 1726, 1765, 1804, 1845, 1886, 1928, 1971, 2015, 2060, 2106, 2152, 2200, 2248, 2298, 2348, 2400, 2452, 2506, 2560, 2616, 2673, 2731, 2790, 2851, 2912, 2975, 3039, 3105, 3172, 3240, 3309, 3380, 3452, 3526, 3601, 3678, 3757, 3837, 3918, 4001, 4086, 4173, 4261, 4351, 4443, 4537, 4633, 4730, 4830, 4932, 5035, 5141, 5249, 5359, 5471, 5586, 5703, 5822, 5944, 6068, 6195, 6324, 6456, 6590, 6727, 6867, 7010, 7156, 7304, 7456, 7610, 7768, 7929, 8093, 8261, 8432, 8606, 8784, 8966, 9151, 9340, 9533, 9729, 9930, 10134, 10343, 10556, 10773, 10995, 11221, 11452, 11687, 11928, 12173, 12423, 12678, 12938, 13203, 13474, 13750, 14032, 14319, 14613, 14912, 15217, 15529, 15847, 16171, 16501, 16839, 17183, 17534, 17892, 18258, 18631, 19011, 19399, 19795, 20199, 20611, 21032, 21461, 21898, 22345, 22800, 23265, 23739, 24222, 24716, 25219, 25733, 26257, 26791, 27336, 27893, 28460, 29039, 29630, 30232, 30847, 31474, 32114, 32767};
const int semitone_table[12] = {16384, 17358, 18390, 19483, 20642, 21870, 23170, 24548, 26007, 27554, 30928, 32767};

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
    static int pos = 0;

    counter = counter + v_speed;
    if (counter > 65536) {
        counter = counter & 65535;
        pos = (pos + 8) & 255;

    }

    return (sine[pos]);
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
    static long int tri = 0;
    int tri_out = 0;

    tri_counter = tri_counter + tri_speed;
    if (tri_counter > 32767) {
        tri_counter = tri_counter & 32767;
        tri = (tri + 64) & 65535;
    }
    tri_out = tri - 32767;
    tri_out = abs(tri_out);

    return (tri_out);

}

int logpot(int logpot_in) {

    return (log_pot_scale[logpot_in >> 7]);

}

//State Variable Filter
//http://www.musicdsp.org/showone.php?id=142

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
//http://www.musicdsp.org/showone.php?id=136

int envelope(int env_attack, int env_release, int env_in) {

    static long env_out = 0;
    int temp;

    temp = abs(env_in);

    if (env_out < temp)
        env_out = temp + ((env_attack * (env_out - temp)) >> 15) ;

    else

        env_out = temp + ((env_release * (env_out - temp)) >> 15);

    return (env_out);

}