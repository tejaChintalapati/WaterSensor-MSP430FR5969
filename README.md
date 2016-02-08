# WaterSensor-MSP430FR5969

Integrates Grove Water sensor with MSP430FR5969

# Working:
* Water Sensor outputs 0 if water is detected and 1 when no water is present near the sensor.
* This project will detect raising and falling edges of the transition and sets red/green LED accordingly.
* On startup, the system will detect if water is present around the sensor . If water is present, it will set Green LED on
and selects the pin interrupt transition from LOW to HIGH.
* If no water is detected around the sensor on startup, then system turns Green LED of and Red LED on 
and selects the pin interrupt transition from HIGH to LOW
* After starting up, system will go to LPM4 and waits for interrupt transition. On detecting the interrupt on pin,
system will turn appropriate LED on/off and changes the interrupt edge transition.
