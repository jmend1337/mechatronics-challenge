# Voyage Mechatronics Challenge
By Jose Antonio Mendez

Goal:
1a) A very simple wiring schematic showing how the GPS, accelerometer, and microcontroller would be wired together to be functional.
1b) A program in C++ that sends GPS coordinates and accelerometer data via serial USB (heavy use of existing libraries is recommended).
2) Design simple box to house all components. No constraints on size.

Part 1: Electrical/Coding
Before starting the wiring and programming, I researched what parts can achieve the 2 desired goals.
At first I was planning on using the recommended Particle Photon microcontroller and Carloop GPS, but then switched to using the Asset Tracker v2.

I switched to the Asset Tracker V2 for the following reasons:
a) The asset tracker provided a shield for the Particle Electron
	This would save me the hassle of wiring the connections through a breadboard/through hole board
	I would not have to solder the components
	The end product would be smaller and aesthetically pleasing
b) There was more information on libraries for the specific GPS/Accelerometer module on the Asset Tracker V2.
	Adafruit gave the datasheet on the Asset Tracker v2.0.0
	The particle community had created libraries that can be easily implemented and there was a good amount of documentation in particle's forums.
c) I did not want to re-invent the wheel
	For a proof of concept, or a quick prototype, I find it more effective to buy something that is already able to do what is desired.
	If this product were to be mass produced, or the component was significantly expensive, then it would be justifiable to design a similar system from scratch.
d) This would ultimately save me time 
	In the time of doing this I am a full time student, leading a research team at UCR, and currently working part time at my NASA JPL internship.
	As I have deadlines to meet for a variety of topics: school, research, work, it is very important that I find a quick and effective way to solve problems.

After settling on using the Particle Electron, and the Asset Tracker v2 shield, I looked to see if there was an Eagle schematic.		
I found the eagle schematic, and could read it to understand how the GPS, accelerometer, and microcontroller would be wired together to be functional.

I read particle's forums to see what issues other people ran into while implementing a GPS and accelerometer together.
This is how I learned that the recommended library to use (AssetTracker), had issues with printing out both the GPS and accelerometer at the same time.
I then selected the AssetTrackerRK as the community had modified the original library to fix this issue.
If I had the hardware, I would first use the example code in the library to confirm that both by GPS, and accelerometer can output data.
After reading the libraries code, and the various examples, I combined the GPS and Accelerometer example codes to get the Particle Electron to output both GPS and acceleration.
In doing this I had to slightly modify the logic to insure the program would correctly execute.

Part 2: Mechanical
I first looked for the dimensions of my parts sizes and the mounting holes, and searched to see what CAD models the community had already designed.
I found a CAD model for the Particle Electron, but not for the shield.
As I could not find a premade CAD file, I created my own CAD model of the Asset Tracker v2.
Lastly I created the housing for the electronic components and rendered a realistic model in SolidWorks.

References:

Particle Electron Pinout: https://docs.particle.io/assets/images/electron/illustrations/electron_pinout.pdf
Electron Datasheet (v005): https://docs.particle.io/datasheets/electron-(cellular)/electron-datasheet/
Electron to Asset Tracker v2 shield wiring: https://github.com/particle-iot/shields/blob/master/electron-shields/asset-tracker/pdfs/asset-tracker-v200.pdf
Asset Tracker v2 Datasheet: https://cdn-shop.adafruit.com/product-files/3451/p3451b-datasheet.pdf
Particle Asset Tracker-kit: https://www.adafruit.com/product/3451
Electron Asset Tracker v2: https://docs.particle.io/datasheets/kits-and-accessories/particle-shields/#electron-asset-tracker-v2
Particle products CAD files: https://github.com/particle-iot/hardware-libraries#3d-cad-models
AssetTrackerRK library: https://build.particle.io/libs/AssetTrackerRK/0.1.4/tab/AssetTrackerRK.cpp
GPS module on shield: https://www.adafruit.com/product/746
Acceleromter on shield: https://www.adafruit.com/product/2809?gclid=Cj0KCQiA2Y_UBRCGARIsALglqQ2QbUXzeiPkbgFIC7qv0VD7M4BwxoCirZc2aKSPdg7Lz1ue1S4hVpUaAnlzEALw_wcB


