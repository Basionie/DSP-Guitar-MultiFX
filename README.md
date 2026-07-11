# DSP-Guitar-MultiFX

A modular, high-performance guitar multi-effects processor built on the Teensy 4.1. This project features a professional-grade audio graph, real-time parameter control, and a scalable architecture for adding new audio effects.

🛠️ Features
Modular Architecture: Isolated namespaces for DSP, audio routing, and UI logic.

Audio Effects: Currently supports Chorus, Delay, and Reverb.

Hardware Interface: Integrated support for SGTL5000 audio shield, rotary encoder for navigation, and display integration.

Scalable Design: Easily add new effects by implementing the IEffect interface.

🚀 Getting Started
Clone the repository: git clone [https://github.com/Basionie/DSP-Guitar-MultiFX.git](https://github.com/Basionie/DSP-Guitar-MultiFX.git)

Setup: Open the firmware/ folder in VS Code with the PlatformIO extension.

Build: Use the PlatformIO "Build" button to compile the firmware.

Upload: Connect your Teensy 4.1 via USB and click "Upload".

⚙️ How to Add New Effects
To add a new effect (e.g., Distortion):

Create effects/distortion.h and distortion.cpp.

Implement the IEffect interface.

Register the new effect in the EffectManager to enable UI control.

📜 Dependencies
U8g2 (Display driver)

CriticalTaskScheduler 
(Task scheduling)

<img width="666" height="375" alt="7448d674-3cfc-4cf9-ab88-5cb7c3a28c2d" src="https://github.com/user-attachments/assets/63558f9f-1172-43c1-9434-3829b08f5324" />

