# ✨ Interactive Lightsaber Bow

The **Interactive Lightsaber Bow** is a real-time audiovisual system that transforms monophonic sound input into dazzling light effects. Built using **Max/MSP**, **Arduino**, and a **Neopixel LED strip**, the system converts incoming audio into MIDI notes and maps them to RGB hues for synchronized lighting, creating an immersive "lightsaber"-like visual response from your musical performance.

---

![Demo of Interactive Lightsaber Bow](lightsaber.gif)

## 🔧 Features

- Real-time pitch detection from monophonic audio
- Converts frequency to MIDI note to RGB color
- Max/MSP patch using FFT (`sigmund~`)
- Jitter-based color visualization in Max
- Serial connection to Arduino for live Neopixel lighting

---

## 🖥️ System Requirements

- Max/MSP 8+
- Arduino IDE
- Arduino Nano (or similar)
- Neopixel LED strip
- USB cable and breadboard
- Audio input (microphone, instrument, interface)

---

## 🚀 Getting Started

### 1. Install Sigmund for Max/MSP (macOS)

1. Download from [vud.org/max](http://vud.org/max/)
2. Or from [GitHub: v7b1](https://github.com/v7b1/)
3. Extract `.mxo` and `.maxhelp` files
4. Move them to `~/Documents/Max 8/Library`
5. Restart Max

### 2. Install Adafruit Neopixel Library for Arduino

1. Open Arduino IDE
2. Go to **Sketch > Include Library > Manage Libraries**
3. Search for `Adafruit DMA Neopixel`
4. Install it

---

## 🔌 Hardware Setup

1. Connect Arduino Nano to your computer via USB
2. On a breadboard:
    - 5V → Positive rail
    - GND → Negative rail
    - D2 → 300Ω resistor → LED Data In
    - Add 100μF capacitor across power rails
    - Connect rails to Neopixel power terminals

---

## 🧠 How It Works

### Max/MSP Patch

- Open `color2arduinofinalprojectLK.maxpat`
- Use **Presenter Mode** for simple interface
- Incoming audio is analyzed with `sigmund~`
- Frequency → MIDI → RGB → Jitter visualization
- RGB data is sent via serial to Arduino
- Ensure the serial object uses the correct port (e.g. `serial c`, baud `9600`)

### Arduino Sketch

- Upload `sketch_march21finalprojLK.ino` to the Nano
- Upload the sketch *before* launching Max/MSP
- Neopixel strip lights up in sync with pitch data

---

## 🎨 Visual Feedback

- Jitter object in Max displays current RGB hue
- LED strip changes colors based on pitch
- Smooth transitions are handled via `line~`

---

## 🛠 Troubleshooting

- **No LED Output?**
  - Check serial port ID and baud rate
  - Verify wiring, check resistor/capacitor placement
- **Max Patch Errors?**
  - Launch `color2arduino.maxpat` test patch first
  - Confirm Sigmund is installed correctly
- **Audio Not Detected?**
  - Make sure input device is selected and active
  - Adjust gain and check mic connection

---

## 📁 Project Folder Contents

- `color2arduinofinalprojectLK.maxpat` – Main Max patch
- `sketch_march21finalprojLK.ino` – Arduino sketch
- `color2arduino.maxpat` – Test/debug patch
- PDF user manual
- Reference video/tutorial links

---

## 🎓 Sources & Inspiration

- [Adafruit NeoPixel Guide](https://learn.adafruit.com/adafruit-neopixel-uberguide)
- [Sound Simulator YouTube Channel](https://www.youtube.com/@SoundSimulator)
    - Serial communication with Max/MSP
    - Lightsaber and synth tutorials
- [FFT to RGB Jitter Patch Inspiration](https://www.youtube.com/watch?v=WPj-clNbvfk)

---

## 🙏 Thanks

Thanks for checking out the **Interactive Lightsaber Bow**! Whether you're a musician, engineer, or just love shiny things that react to sound, we hope this project brings joy and inspiration to your creative journey.
