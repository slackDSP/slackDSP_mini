/* 
 * File:   slackdsp_mini.h
 * Author: Ian Maltby
 *
 * Created on August 18, 2014, 6:29 PM
 */

#ifndef SLACKDSP_MINI_H
#define	SLACKDSP_MINI_H

//Define nice pin names

#define LED LATBbits.LATB14 //LED1 output

//define other nice names

#define ADC ADC1BUF0 //ADC input
#define CLOCKOUT OC1RS //Clock out to drive codec
#define pot1 pots[0]
#define pot2 pots[1]
#define pot3 pots[2]

//define types for filters
#define lp 1
#define bp 2
#define hp 3

//function prototypes
int delayline(long d_length, long d_time, int d_mod, int d_in);
int mulx(int m_in1, int m_in2);
int add(int a_in1, int a_in2);
int clip(int c_level, int c_in);
int pitchshift(int shift, int s_in);
int lowpass(int lp_freq, int lp_in);
int hipass(int hp_freq, int hp_in);
int vco(long v_speed);
int random(void);
int crossfade(int cf_ctrl, int in_1, int in_2);
int gain(int g_level, int gc_level, int g_in);
int pitchshift2(int s_shift, int s_in);
int semitones(int semis_in);
int saw_lfo(int saw_speed);
int tri_lfo(int tri_speed);
int logpot(int logpot_in);
int svf(int reso_freq, int reso_q, int svf_type, int reso_in);
int revdelay(long rd_length, long rd_time, int rd_in);
int blend(int b_ctrl, int b_in_1, int b_in_2);
int random_lfo(int random_speed);
int envelope(int env_attack, int env_release, int env_in);
#endif	/* SLACKDSP_WOLFSON_H */