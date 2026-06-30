import whisper
import sounddevice as sd
import soundfile as sf
import serial
import time

# =========================
# ESP32 COM PORT
# =========================
ser = serial.Serial("COM6", 115200)
time.sleep(2)

# =========================
# Load Whisper
# =========================
print("Đang tải Whisper...")
model = whisper.load_model("base")
print("Đã sẵn sàng!")
print("----------------------")

while True:

    print("🎤 Hãy nói...")

    audio = sd.rec(
        int(5 * 16000),
        samplerate=16000,
        channels=1,
        dtype="float32"
    )

    sd.wait()

    sf.write("temp.wav", audio, 16000)

    result = model.transcribe("temp.wav", language="zh")

    text = result["text"].strip()

    print("Whisper nghe:", text)

    if any(word in text for word in ["开心", "高兴", "快乐", "幸福"]):
        print("→ happy")
        ser.write(b"happy\n")

    elif any(word in text for word in ["伤心", "难过", "悲伤"]):
        print("→ sad")
        ser.write(b"sad\n")

    elif any(word in text for word in ["生气", "愤怒", "火大"]):
        print("→ angry")
        ser.write(b"angry\n")

    elif any(word in text for word in ["累", "疲惫", "疲倦"]):
        print("→ tired")
        ser.write(b"tired\n")

    elif any(word in text for word in ["惊讶", "震惊", "哇"]):
        print("→ surprised")
        ser.write(b"surprised\n")

    else:
        print("Không phát hiện từ khóa.")

    print("----------------------")