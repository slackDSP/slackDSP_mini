/* 
 * File:   WM8510.h
 * Author: Ian Maltby
 *
 * Created on August 31, 2014, 12:40 PM
 */

#ifndef WM8510_H
#define	WM8510_H

#define WM8510_SS LATCbits.LATC7 //SS SPI slave select
#define software_reset 0
#define power_mngmnt1 1
#define power_mngmnt2 2
#define power_mngmnt3 3
#define audio_interface 4
#define companding_ctrl 5
#define clock_gen_ctrl 6
#define additional_ctrl 7
#define gpio_stuff 8
#define dac_control 10
#define dac_digital_vol 11
#define adc_control 14
#define adc_digital_vol 15
#define dac_limiter1 24
#define dac_limiter2 25
#define notch_filter1 27
#define notch_filter2 28
#define notch_filter3 29
#define notch_filter4 30
#define alc_control1 32
#define alc_control2 33
#define alc_control3 34
#define noise_gate 35
#define pll_n 36
#define pll_k1 37
#define pll_k2 38
#define pll_k3 39
#define attenuation_ctrl 40
#define input_ctrl 44
#define inp_pga_gain_ctrl 45
#define adc_boost_ctrl 47
#define output_ctrl 49
#define spk_mixer_ctrl 50
#define spk_volume_ctrl 54
#define mono_mixer_ctrl 56

//function prototypes
void WM8510_init(void);
void WM8510_write(int reg, int data);

#endif	/* WM8510_H */

