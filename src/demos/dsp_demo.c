

#include "dsp_demo.h"
#include <time/time.h>

#pragma GCC push_options 
#pragma GCC optimize("O0")

void wait_100ms(void){
    tm_system_t ts0, ts1;
    tm_sdelta_t delta = 100;
    tm_current_time(&ts0);
    tm_apply_sdelta(&ts0, &delta);
    tm_current_time(&ts1);
    while (tm_cmp_stime(&ts1, &ts0) != 1){
        tm_current_time(&ts1);
    };
}

// void cordic_sine_wave_f32_demo(void){
//     f32_t f1;
//     debug_printf("\nCordic Sine Wave f32_t\n");
//     // The output values are very off. It is unclear why. Feels like some 
//     // kind of quantization error. This should be investigated and fixed. 
//     cordic_sine_wave_f32_t wave = {
//         .amplitude = 1,
//         .freq = 1000,
//         .initial_phase = 0
//     };
//     cordic_sine_wave_f32_reset(&wave, 10000);
//     while (1)
//     {
//         cordic_sine_wave_f32_propagate(&wave);
//         f1 = q31_to_f32(wave.phase) * M_PI;
//         debug_printf("phase: %.2f, sin: %.4f, cos: %.4f\n", f1, wave.sin, wave.cos);
//         wait_100ms();
//     }
// }

void recurs_sine_wave_f32_demo(void){
    debug_printf("\nRecursive Sine Wave f32_t\n");
    
    recurs_sine_wave_f32_t wave = {
        .amplitude = 1,
        .freq = 1000,
        .initial_phase = 0
    };
    recurs_sine_wave_f32_reset(&wave, 10000);
    while (1)
    {
        recurs_sine_wave_f32_propagate(&wave);
        debug_printf("sin: %.4f, cos: %.4f\n", wave.sin, wave.cos);
        wait_100ms();
    }
}


void dsp_demo(void){
    f32_t f1, f2;
    q31_t q1;
    f32_t input[] = {-1, -0.5, 0, 0.5, 1, 1.5, -1.5};
    size_t len = sizeof(input) / sizeof(input[0]);
    
    debug_printf("\nq31_t Conversions\n");
    for (int i = 0; i < len; i++){
        f1 = input[i];
        q1 = f32_to_q31(f1);
        f2 = q31_to_f32(q1);
        debug_printf("Q1.31: %9x, In: %.2f, Out: %.2f\n", q1, f1, f2);
        wait_100ms();
    }

    // debug_printf("\nCordic Sine\n");
    // m = f32_to_q31(0.75f);

    // for (int i = 0; i < len; i++){
    //     inp = input[i];
    //     q1 = f32_to_q31(inp);
    //     cordic_sincos(q1, m, &r1, &r2);
    //     f1 = q31_to_f32(r1);
    //     f2 = q31_to_f32(r2);
    //     debug_printf("in: %.2f, sin: %.4f, cos: %.4f\n", inp, f1, f2);
    //     wait_100ms();
    // }

    // cordic_sine_wave_f32_demo(); 
    recurs_sine_wave_f32_demo();
}   

#pragma GCC pop_options 
