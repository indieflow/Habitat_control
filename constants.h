// Define constant values

//========================================================
//======================= Lighting =======================
//========================================================
 
#define redPin               5        // Red channel PWM pin
#define greenPin             6        // Green channel PWM pin
#define bluePin              3        // Blue channel PWM pin
 
#define fadespeed            10       // Make this higher to slow down the transition

//========================================================
//======================= Cooling ========================
//========================================================

#define thermCoolPin1        A1       // Thermistor analog pin
//#define thermCoolPin2        A3

#define fanPin               9        // Fan PWM pin

//========================================================
//======================= Heating ========================
//========================================================

#define thermHotPin1         A0       // Thermistor analog pin
//#define thermHotPin2         A2

#define thermistorNominal    10000    // Resistance at 25 degrees C
#define temperatureNominal   25       // Temp. for nominal resistance (almost always 25 C)
#define numsamples           5        // How many samples to take and average, more takes longer but is more 'smooth'
#define bCoefficient         3950     // The beta coefficient of the thermistor (usually 3000-4000)
#define seriesResistor       10000    // The value of the 'other' resistor

#define relay_ON             0        // Relay logic state
#define relay_OFF            1        // Relay logic state

#define relay_1              12       // Relay pin controlling heatmat
//#define relay_2             11
//#define relay_3             10
//#define relay_4             8

//========================================================
//===================== LCD Display ======================
//========================================================



