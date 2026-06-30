# Aura

## AI Emotional Smart Keychain

Aura is an AI emotional smart keychain designed to provide simple emotional interaction through speech recognition and animated facial expressions. The system uses Python with the Whisper speech recognition model to recognize users' emotions and communicates with an ESP32 DevKit (ESP32-WROOM-32) via Serial to display corresponding facial expressions on a GC9A01 round LCD.

---

## Project Overview

Aura combines artificial intelligence with embedded hardware to create a portable emotional companion. Instead of focusing on complex conversations, the project provides intuitive emotional feedback through dynamic facial expressions, making everyday interactions more engaging and enjoyable.

---

## Hardware

- ESP32 DevKit (ESP32-WROOM-32)
- GC9A01 Round LCD Display (240 × 240)
- USB Type-C Cable
- Plush Fabric
- PP Cotton Filling
- Keychain Accessories

---

## Software

- Python 3
- OpenAI Whisper
- PySerial
- SoundDevice
- SoundFile
- Arduino IDE

---

## Features

- Speech Recognition
- Emotion Keyword Detection
- Serial Communication
- Animated Facial Expressions
- Real-time Emotion Feedback

---

## Project Structure

```
Aura
│
├── Arduino
│   ├── Aura.ino
│   ├── happy.h
│   ├── sad.h
│   ├── angry.h
│   ├── tired.h
│   ├── suprised.h
│   ├── smile.h
│   ├── binhthuong.h
│   └── chop.h
│
├── Python
│   └── voice.py
│
└── README.md
```

---

## System Workflow

```
User Speech
      │
      ▼
Python (Whisper)
      │
      ▼
Speech-to-Text
      │
      ▼
Emotion Keyword Detection
      │
      ▼
Serial Communication
      │
      ▼
ESP32 DevKit
      │
      ▼
GC9A01 Round LCD
      │
      ▼
Animated Facial Expression
```

---

## Supported Emotions

| Emotion | Display |
|----------|---------|
| Happy | 😊 |
| Sad | 😢 |
| Angry | 😠 |
| Tired | 😴 |
| Surprised | 😲 |

---

## Development Environment

- Operating System: Windows
- Programming Language: Python & C++
- IDE: Arduino IDE
- Communication: Serial (USB)

---

## Author

**Project Name:** Aura

**Course:** Intelligent Product Design
