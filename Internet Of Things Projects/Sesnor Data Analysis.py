import os
import time
import playsound
import speech_recognition as sr
from gtts import gTTS
import serial #Import Serial Library
import time

arduinoSerialData = serial.Serial('COM4',9600) #Create Serial port object called arduinoSerialData

l=[]
count=0
def speak(text):
    tts=gTTS(text=text,lang="en")
    filename="voice.mp3"
    tts.save(filename)
    playsound.playsound(filename)

def speak1(text1):
    tts=gTTS(text=text1,lang="en")
    filename1="voice1.mp3"
    tts.save(filename1)
    playsound.playsound(filename1)

def speak2(text2):
    tts=gTTS(text=text2,lang="en")
    filename2="voice2.mp3"
    tts.save(filename2)
    playsound.playsound(filename2)

def speak3(text3):
    tts=gTTS(text=text3,lang="en")
    filename3="voice3.mp3"
    tts.save(filename3)
    playsound.playsound(filename3)

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

while (1==1):
    if (arduinoSerialData.inWaiting()>0):
        myData = arduinoSerialData.readline()
        print(myData)
        count=count+1
        if(count>=40):
            break
        l.append(float(myData))
print(l)

dist=[]
temp=[]

for j in range(0,len(l)):
    if j%2==0:
        dist.append(l[j])
    elif j%2!=0:
        temp.append(l[j])
print(dist)
print(temp)

my_list=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
my_list1=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]

import numpy as np
import matplotlib.pyplot as plt

speak("here is our sensor data for distance.")
plt.scatter(my_list,dist,color="blue")
plt.grid(True)
plt.axis([my_list[0],my_list[-1],0,5])
plt.xlabel("Readings")
plt.ylabel("Values")
plt.title("MY ULTRASONIC SENSOR DATA")
plt.show()

speak1("here is our sensor data for temperature")
plt.scatter(my_list1,temp,color="red")
plt.grid(True)
plt.axis([my_list1[0],my_list1[-1],0,50])
plt.xlabel("Readings")
plt.ylabel("Values")
plt.title("MY DHT11 SENSOR DATA")
plt.show()

for k in range(0,len(temp)):
    if(temp[k]>=38):
        speak2("You are unwell please quarantine yourself and visit your doctor as soon as possible")
        print("You are unwell please quarantine yourself and visit your doctor as soon as possible")
    else:
        speak3("You are completely safe.")
        print("You are completely safe.")

        
