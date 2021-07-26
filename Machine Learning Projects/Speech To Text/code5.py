import os
import time
import playsound
import speech_recognition as sr
from gtts import gTTS
import cv2
import numpy as np
import webbrowser

print("How can i help you")
def speak(text):
    tts=gTTS(text=text,lang="en")
    filename="voice.mp3"
    tts.save(filename)
    playsound.playsound(filename)

def get_audio():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        audio=r.listen(source)
        said=""
        try :
            said=r.recognize_google(audio)
            print(said)
        except Exception as e:
            print("Exception"+str(e))
    return said

text=get_audio()

if "open Google" in text:
    speak("Opening google for you")
    webbrowser.open_new("https://www.google.com")

elif "open YouTube" in text:
    speak("Opening youtube for you")
    webbrowser.open_new("https://www.youtube.com")

elif "open text" in text:
    speak("Opening your text file")
    open("WiFi_ESP8266.txt","r")

else:
    f=open("newtext.txt","w")
    f.write(text)


    

