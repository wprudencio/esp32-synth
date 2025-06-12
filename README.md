# 🎛️ Custom Hardware Synth Project
https://github.com/user-attachments/assets/1837dc73-f9c6-4a2d-afaf-8ea2c64a5b65

---

## 🧰 Hardware Used

### 🔌 Main Board

<p align="center">
  <img width="600" alt="Main Board" src="https://github.com/user-attachments/assets/46574a20-2fd0-4157-84c9-6804b67c569a" />
</p>

- [Buy on AliExpress](https://www.aliexpress.us/item/3256805917724211.html?spm=a2g0o.order_list.order_list_main.70.5da71802OAppXl&gatewayAdapt=glo2usa4itemAdapt)

---

### 🎮 Additional Accessory

<p align="center">
  <img width="700" alt="Additional Accessory" src="https://github.com/user-attachments/assets/5f6c12e1-a11c-4320-ad2e-45d3f28f87c3" />
</p>

- [Buy on AliExpress](https://www.aliexpress.us/item/3256805879357212.html?spm=a2g0o.order_list.order_list_main.145.5da71802OAppXl&gatewayAdapt=glo2usa4itemAdapt)

---

## 📚 Libraries Used

- [arduino-audio-tools](https://github.com/pschatzmann/arduino-audio-tools)  
- [Maximilian](https://github.com/pschatzmann/Maximilian)  
- [Maximilian in the Browser (Mimic Project)](https://mimicproject.com/course/making-music/overview) — Great for exploring the library using JavaScript before implementing it in C++ on the ESP32.

---

## 💻 Source Code

- [synth-base.cpp](https://github.com/wprudencio/esp32-synth/blob/main/synth-base.cpp)

---

## 🛠️ Troubleshooting

If you're using the I2S DAC interface linked above, **you may need to solder the bridges** shown below:

<p align="center">
  <img width="700" alt="DAC Soldering Instructions" src="https://github.com/user-attachments/assets/396e993a-9079-4a50-9718-5f5c59dd2507" />
</p>

- Official guide: [Audio Tools Wiki – External DAC](https://github.com/pschatzmann/arduino-audio-tools/wiki/External-DAC#hiletgo-pcm5102-i2s-iis-lossless-digital-audio-dac-decoder)  
- Some users report it works without soldering, but **in my case, soldering was required** for proper functionality.

---

## 🎹 Learn How Synthesizers Work

- [FM SYNTHS in under 4 minutes](https://www.youtube.com/watch?v=vvBl3YUBUyY)  
- [How to learn any synthesizer](https://www.youtube.com/watch?v=JfJ9Dbjz6cs)
