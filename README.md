# Smart-Watering-Plant-Using-RT-Thread
Project Title: Smart Agriculture (Irrigation system)
Description: Smart irrigation systems are a combination of sensors and controllers which monitor the watering, moisture related content temperature and climate and there by watering the crops as per requirement. In this project I am using a soil moisture sensor to detect the moisture of the soil.
There are two types of soil moisture sensor.
1. Resistive soil moisture sensor 
2. Capacitive soil moisture sensor
Both the soil moisture sensor works on the principle of electrical conductivity. Resistive soil moisture sensor works with change in resistance between the two leads of the sensor where as capacitive soil moisture sensor has only one lead which works with respect to the change in dielectric property of the soil. In this project I am using a resistive soil moisture sensor.
When the soil moisture sensor detects the change in electrical conductivity it sends data to the controller then with respect to the sensor data the controller switches ON the water pump or switches OFF the water pump. When the water pump is ON led green light is ON, When the water pump is switched OFF the red led is OFF. Thereby the green and red led show the status of the water pump is whether ON or OFF respectively. Threads are used to run tasks concurrently; I have used 3 threads for this project one to monitor the sensor data simultaneously and thread two to turn ON the water pump and green led if the sensor didn’t find any moisture and the thread 3 turns OFF the water pump and turns ON the red led.

# Product Features: 
1.	The sensor collects data all the time.
2.	All the process happens concurrently so no delay occurs unless manual delay which were made on intention 
3.	Multiple sensors can be added in future.
My Experience in RT-Thread
I am using RT-thread for this project. I am new to RT-thread this is my 1st project in RT-Thread I used RT-Thread studio for this project it is user friendly and free tool so I will be using it for my future projects. I also used the thread function which helped me achieve concurrency. I got help from RT-Thread Club and some direct help from the people from RT-Thread. They were so friendly that they helped me at various stages of the project. My special thanks to the members from RT-Thread for helping me to complete this project.

# Hardware Framework
The Controller used in this project is STM32 F411-RE which has ARM CORTEX – M4 as the CPU with 512kb of flash memory and 32 kHz internal clock

# Software Framework
1.	The OS used for this project is RT-Thread RTOS
2.	The program is written in c the only work of the main function is to activate the three threads.

# Wiring 
1. GREEN LED			                  P(A, 5)
2. RED LED          			          P(A, 6)
3. Soil Moisture Sensor            P(C, 0)
4. Water Pump                      P(A, 10)

<iframe width="693" height="390" src="https://www.youtube.com/embed/PkLooRFrJ24" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
