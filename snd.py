import pyaudio
import numpy as np
from pymem import Pymem

CHUNK = 2**11
RATE = 44100

with open('bridge', 'r') as file:
    adresse_text = file.read().strip()
    adresse_int = int(adresse_text, 16)

print(adresse_int)

pm = Pymem("Visualizer.exe")

p=pyaudio.PyAudio()
stream=p.open(format=pyaudio.paInt16,channels=1,rate=RATE,input=True,
              frames_per_buffer=CHUNK)

while True:
    data = np.fromstring(stream.read(CHUNK),dtype=np.int16)
    peak=np.average(np.abs(data))*2
    #Aggressive (Dubstep, party ...)
    bars = int(17*peak/2**6)
    #Mid (HipHop)
    #bars = int(250*peak/2**10)
    #Calm (Chill songs with a lot of bass)
    #bars = int(300*peak/2**11)
    pm.write_int(adresse_int, bars)


stream.stop_stream()
stream.close()
p.terminate()
