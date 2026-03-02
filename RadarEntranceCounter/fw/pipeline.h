/****************************************************************************/
/* Copyright (c) 2025 embedUR systems, Inc.    All rights reserved          */
/****************************************************************************/

#ifndef PIPELINE_H
#define PIPELINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************
* MACROS
*******************************************************************************/

/* Physical constants */
#define LIGHT_SPEED_M_S                 299792458.0f
#define CENTER_FREQ_HZ                  60750000000.0f
#define WAVELENGTH_M                    (LIGHT_SPEED_M_S / CENTER_FREQ_HZ)
#define CHIRP_REPETITION_TIME_S         0.000501488f

/* Detection tuning */
#define PSD_THRESHOLD                   30.0f
#define ALPHA                           0.2f
#define VELOCITY_BUFFER_SIZE            3
#define MIN_VALID_RANGE_BIN             3
#define MIN_VELOCITY_M_S                0.1f

/* Pipeline status codes */
#define PIPELINE_OK                     1
#define PIPELINE_ERROR                 -1

/*******************************************************************************
* Global Declaration
*******************************************************************************/
extern int   g_pipeline_in;
extern int   g_pipeline_out;
extern float g_pipeline_distance_m;
extern float g_pipeline_velocity_m_s;

/*******************************************************************************
* Function Name: pipeline_init
****************************************************************************//**
*
* Initializes the radar signal processing pipeline. This includes generating
* Hanning window coefficients, initializing ARM CMSIS-DSP FFT instances for
* both range and Doppler processing, and resetting all internal state
* variables to their default values.
*
* \param None
*
* \return PIPELINE_OK on success, PIPELINE_ERROR if FFT initialization fails.
*
*******************************************************************************/
int pipeline_init(void);

/*******************************************************************************
* Function Name: pipeline_process_frame
****************************************************************************//**
*
* Processes one complete radar frame through all DSP pipeline stages:
*   1. Range Hanning windowing
*   2. Range FFT  (real FFT per chirp per antenna)
*   3. Doppler Hanning windowing
*   4. Doppler FFT (complex FFT per range bin)
*   5. Power Spectral Density (PSD) map computation
*   6. Peak detection with threshold comparison
*   7. Distance calculation with EMA smoothing
*   8. Velocity computation and direction logic (IN / OUT)
*
* Results are written to the global variables g_pipeline_in, g_pipeline_out,
* g_pipeline_distance_m, and g_pipeline_velocity_m_s.
*
* \param frame_data  Pointer to the raw float32 radar frame buffer.
*                    Length must equal NUM_CHIRPS x NUM_ANTENNAS x NUM_SAMPLES.
*
* \return PIPELINE_OK if a valid detection was found, PIPELINE_ERROR otherwise.
*
*******************************************************************************/
int pipeline_process_frame(float *frame_data);

/*******************************************************************************
* Function Name: pipeline_reset
****************************************************************************//**
*
* Resets the dynamic pipeline state including the EMA-smoothed distance value
* and the velocity direction ring buffer. Does not reinitialize FFT instances
* or window coefficients. Call this after a radar reconfiguration to prevent
* stale history from affecting subsequent frame processing.
*
* \param None
*
* \return None
*
*******************************************************************************/
void pipeline_reset(void);

/*******************************************************************************
* Function Name: pipeline_set_range_zone
****************************************************************************//**
*
* Overrides the valid detection zone boundaries used during peak search.
* Any range bin outside [min_bin, max_bin] is excluded from detection.
* Useful for masking walls, furniture, or other static reflectors at
* known distances.
*
* Default values set by pipeline_init():
*   min_bin = MIN_VALID_RANGE_BIN (3)
*   max_bin = (NUM_SAMPLES_PER_CHIRP / 2) - 1
*
* \param min_bin  Minimum range bin index, inclusive (>= 0).
* \param max_bin  Maximum range bin index, inclusive.
*
* \return None
*
*******************************************************************************/
void pipeline_set_range_zone(int min_bin, int max_bin);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* PIPELINE_H */
