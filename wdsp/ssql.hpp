/*  ssql.h

This file is part of a program that implements a Software-Defined Radio.

Copyright (C) 2023 Warren Pratt, NR0V
Copyright (C) 2024 Edouard Griffiths, F4EXB Adapted to SDRangel

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

The author can be reached by email at

warren@pratt.one

*/

#ifndef wdsp_ssql_h
#define wdsp_ssql_h

#include "export.h"

namespace WDSP {

class WDSP_API FTOV                    // Frequency to Voltage Converter
{
public:
    int run;                            // 0 => don't run; 1 => run
    int size;                           // buffer size
    int rate;                           // sample-rate
    int rsize;                          // rate * time_to_fill_ring, e.g., 48K/s * 50ms = 2400
    float fmax;                        // frequency (Hz) for full output, e.g., 2000 (Hz)
    float* in;                         // pointer to the intput buffer for ftov
    float* out;                        // pointer to the output buffer for ftov
    int* ring;                          // pointer to the base of the ring
    int rptr;                           // index into the ring
    float inlast;                      // holds last sample from previous buffer
    int rcount;                         // count of zero-crossings currently in the ring
    float div;                         // divisor for 'rcount' to produce output of 1.0 at 'fmax'
    float eps;                         // minimum input change to count as a signal edge transition

    static FTOV* create_ftov (int run, int size, int rate, int rsize, float fmax, float* in, float* out);
    static void destroy_ftov (FTOV *a);
    static void flush_ftov (FTOV *a);
    static void xftov (FTOV *a);
};

class CBL;
class FTDV;
class BQLP;
class RXA;

class WDSP_API SSQL                    // Syllabic Squelch
{
public:
    int run;                            // 0 if squelch system is OFF; 1 if it's ON
    int size;                           // size of input/output buffers
    float* in;                         // squelch input signal buffer
    float* out;                        // squelch output signal buffer
    int rate;                           // sample rate
    int state;                          // state machine control
    int count;                          // count variable for raised cosine transitions
    float tup;                         // time for turn-on transition
    float tdown;                       // time for turn-off transition
    int ntup;                           // number of samples for turn-on transition
    int ntdown;                         // number of samples for turn-off transition
    float* cup;                        // coefficients for up-slew
    float* cdown;                      // coefficients for down-slew
    float muted_gain;                  // audio gain while muted; 0.0 for complete silence

    float* b1;                         // buffer to hold output of dc-block function
    float* ibuff;                      // buffer containing only 'I' component
    float* ftovbuff;                   // buffer containing output of f to v converter
    float* lpbuff;                     // buffer containing output of low-pass filter
    int* wdbuff;                        // buffer containing output of window detector
    CBL *dcbl;                          // pointer to DC Blocker data structure
    FTOV *cvtr;                         // pointer to F to V Converter data structure
    BQLP *filt;                         // pointer to Bi-Quad Low-Pass Filter data structure
    int ftov_rsize;                     // ring size for f_to_v converter
    float ftov_fmax;                   // fmax for f_to_v converter
    // window detector
    float wdtau;                       // window detector time constant
    float wdmult;                      // window detector time constant multiplier
    float wdaverage;                   // average signal value
    float wthresh;                     // window threshold above/below average
    // trigger
    float tr_thresh;                   // trigger threshold:  100K/(100K+22K)=0.8197
    float tr_tau_unmute;               // trigger unmute time-constant:  (100K||220K)*10uF = 0.6875
    float tr_ss_unmute;                // trigger steady-state level for unmute:  100K/(100K+220K)=0.3125
    float tr_tau_mute;                 // trigger mute time-constant:  220K*10uF = 2.2
    float tr_ss_mute;                  // trigger steady-state level for mute:  1.0
    float tr_voltage;                  // trigger voltage
    float mute_mult;                   // multiplier for successive voltage calcs when muted
    float unmute_mult;                 // multiplier for successive voltage calcs when unmuted
    int* tr_signal;                     // trigger signal, 0 or 1

    static SSQL* create_ssql (
        int run,
        int size,
        float* in,
        float* out,
        int rate,
        float tup,
        float tdown,
        float muted_gain,
        float tau_mute,
        float tau_unmute,
        float wthresh,
        float tr_thresh,
        int rsize,
        float fmax
    );
    static void destroy_ssql (SSQL *a);
    static void flush_ssql (SSQL *a);
    static void xssql (SSQL *a);
    static void setBuffers_ssql (SSQL *a, float* in, float* out);
    static void setSamplerate_ssql (SSQL *a, int rate);
    static void setSize_ssql (SSQL *a, int size);
    // RXA Properties
    static void SetSSQLRun (RXA& rxa, int run);
    static void SetSSQLThreshold (RXA& rxa, float threshold);
    static void SetSSQLTauMute (RXA& rxa, float tau_mute);
    static void SetSSQLTauUnMute (RXA& rxa, float tau_unmute);

private:
    static void compute_ssql_slews(SSQL *a);
    static void calc_ssql (SSQL *a);
    static void decalc_ssql (SSQL *a);
};

} // namespace WDSP

#endif
