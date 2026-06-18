# DSP Guitar Effects Pedal Architecture (Teensy 4.1)

## System Overview

The system is a real-time digital audio processing pedal built on the Teensy 4.1 microcontroller.

A guitar input signal is captured, processed through a modular DSP effects chain, and output with minimal latency suitable for live performance.

---

## Signal Flow

Guitar Input  
→ Analog Front-End (signal conditioning)  
→ Audio Codec (ADC via SGTL5000)  
→ Teensy 4.1 DSP Processing Core  
→ Effects Processing Chain  
→ Audio Codec (DAC)  
→ Output to amplifier / speaker

---

## DSP Processing Pipeline

Audio is processed in real time using a block-based streaming architecture:

1. Audio buffer acquisition (input block)
2. Pre-processing (gain control / normalization)
3. Effects chain processing:
   - Distortion (non-linear waveshaping)
   - Delay (buffer-based echo)
   - Reverb (Algorithmic Reverb)
4. Mixing and output gain control
5. Output buffer transmission

---

## Hardware Architecture

- Teensy 4.1 (ARM Cortex-M7 @ 600 MHz)
- Audio Shield (SGTL5000 codec)
- Guitar input jack with analog conditioning circuit
- Audio output to amplifier or speaker system

---

## Software Architecture

The firmware is modular and built around the Teensy Audio Library.

Main components:

- `audio_input.cpp` → Handles audio input stream
- `audio_engine.cpp` → Manages DSP pipeline and routing
- `effects/` → Individual effect modules (distortion, delay, reverb)
- `config.h` → Global parameters (gain, mix, effect levels)

The system uses interrupt-driven, real-time audio processing with fixed-size audio blocks.

---

## Real-Time Constraints

- Target latency: < 10 ms
- Block-based processing using Teensy Audio Library
- Optimized for ARM Cortex-M7 DSP instructions
- No dynamic memory allocation in the audio processing path
- Deterministic execution per audio block

---

## Expandability

The architecture is designed to support future enhancements:

- Footswitch / pedal control input
- Preset saving and loading system
- External UI (OLED display)


---

## Summary

This architecture provides a scalable and real-time DSP framework for guitar audio processing on embedded hardware, balancing performance, modularity, and low latency.
