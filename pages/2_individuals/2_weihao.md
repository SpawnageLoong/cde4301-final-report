---
title: Wei Hao
parent: Individual Contributions
nav_order: 2
permalink: /wei-hao/
---

<div style="display:flex">
  <img src="{{site.baseurl}}/assets/images/profiles/weihao.jpg" alt="Wei Hao" width="200" style="border-radius:50%">
  <div style="margin-left: 20px">
    <h2>Ho Wei Hao</h2>
    <h3>Year 4 Electrical Engineering</h3>
    <h3>A0240152X</h3>
  </div>
</div>









# 2. Radiation Monitoring System

## 2.1 Job Scope

My scope of work consists of the following tasks:

<b>1. Radiation Sensor Operations</b>

As part of mission objectives, the payload will be monitoring and storing radiation counts. A radiation sensor has to be powered and its output read and stored. 

<b>2. High Voltage PCB Design</b>

Custom Printed Circuit Boards (PCB) were designed to provide the high power requirements of the radiation sensor and to process its output. Sufficient clearance is required between the high voltage lines from the rest of the signal conditioning circuit. This prevents inference between the two systems that can break down the entire payload.

<b>The Objective</b> of my work is to ensure that the payload can detect and record radiation levels accurately, and the components used to fulfil the objective are suitable for space applications.

 ## 2.2 Design Requirements

The payload requires certain specifications to be met to operate as intended. Since the interim report, the list has gained new specifications to meet. 

<table border="1" cellpadding="6" cellspacing="0">
  <thead>
    <tr>
      <th>Feature</th>
      <th>Specification</th>
      <th>Reasoning</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Operating Voltage</td>
      <td>5V</td>
      <td>Assumption of 5V provided</td>
    </tr>
    <tr>
      <td>Current Consumption</td>
      <td>&lt;2A</td>
      <td>Assumption of 2A maximum provided to the entire payload, so current is shared with low voltage circuit</td>
    </tr>
    <tr>
      <td>Radiation Sensor</td>
      <td>Detects alpha and beta particles</td>
      <td>Monitor the particles responsible for SEE</td>
    </tr>
    <tr>
      <td>Signal processing</td>
      <td>Trigger microcontroller with signal</td>
      <td>Ensure that radiation is correctly recorded by the microcontroller.</td>
    </tr>
    <tr>
      <td>Microcontroller</td>
      <td>Radiation-Hardened</td>
      <td>Provide reliable data storage throughout the mission</td>
    </tr>
    <tr>
      <td>High and low voltage clearance</td>
      <td>Ensure voltage lines do not interfere with each other</td>
      <td>Avoid compromising other systems on the same payload or satellite</td>
    </tr>
    <tr>
      <td>Signal interference</td>
      <td>Signals only travel through the signal line</td>
      <td>Prevent unwanted noise in other lines</td>
    </tr>
    <tr>
      <td>Space suitability</td>
      <td>
        Total Mass Loss (TML) and Collected Volatile Condensable Materials (CVCM) of each component do not exceed 1% and 0.1% respectively (Kern, 2019)
      </td>
      <td>
        High CVCM values indicate that unwanted vapours will condense on the payload and its adjacent components, which may contaminate or interfere with operations of nearby sensitive equipment that need cleanliness (Kern, 2019). TML must also be low as the vaporised material may condense on surrounding equipment and hamper their operations (Kern, 2019).
      </td>
    </tr>
  </tbody>
</table>

<p align="center"><strong>Table 2-1 Design Specifications Table</strong></p>

## 2.3 Design Specifications 

Only the ZSOM-M01 microcontroller and the GM tube persisted into the final design. 

### 2.3.1 Unchanged Components

#### 2.3.1.1 Microcontroller

<b>Design Choice</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig1.png" alt="ZSOM-M01 board" width="600" class="img-center">

<p align="center"><strong>Fig 2-2  ZSOM-M01 board (Zero Error Systems, 2024b)</strong></p>

The ZSOM-M01 remained on the final design due to its reliability in storing data of the mission. This trait is supported by its radiation hardened status, Triple Modular Redundancy configuration and the Error Detection and Correction functionality. Since our main mission consists of a memory corruption experiment of Atmega32U4 microcontrollers, the ZSOM-M01 provides the robust foundation for collecting data for further analysis. 

The detailed explanation was discussed in the interim, and it can be found in appendix B1.

<b>Design Implementation</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig2.png" alt="Pinout of ZSOM-M01" width="600" class="img-center">

<p align="center"><strong>Fig 2-3 Pinout of ZSOM-M01 (Zero Error Systems, 2024b)</strong></p>

The ZSOM-M01 pins used by the circuit were altered during prototyping. The GM tube circuit sends the detected signal at unpredictable intervals to the ZSOM-M01 via D4 interrupt pin, so that it can record the signal immediately during its other operations. This allows the signals to be recorded accurately.

With the chosen DC-DC converter, the PWM pin from the ZSOM is no longer needed to further simplify the circuit. The new connection will be shown in the later circuit design

#### 2.3.1.2 GM Tube

<b>Design Choice</b>

Geiger-Müller (GM) tubes remained on the final design as it could provide robust signals as an indication of the radiation levels it experienced. Detailed explanation of its choice over other detectors can be found in the appendix B2.

<b>Design Implementation</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig3.png" alt="LND712 GM Tube" width="600" class="img-center">

<p align="center"><strong>Fig 2-4 LND712 GM Tube (LND. Inc., n.d.)</strong></p>

The LND 712 is chosen for our purposes. It requires between 450 to 650V to operate, hence power can be supplied easily with a DC-to-DC converter, making it easy to integrate. The connections required are also very simple, requiring two resistors and a 50pF capacitor. (LND. Inc., n.d.). 

### 2.3.2 New Components

The new components are checked for suitability for space 

#### 2.3.2.1 DC-DC Converter

<b> Design Choice </b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig4.png" alt="AEQ5-600FL0.5 Converter" width="400" class="img-center">

<p align="center"><strong>Fig 2-5 AEQ5-600FL0.5 Converter (Element14, 2025)</strong></p>

The AEQ5-600FL0.5 provides a reliable input of around 600V to the GM tube, allowing it to operate optimally without being overly-sensitive to small changes in load. This prevents over-voltage damage to the GM tube, and allows the GM tube to work at its optimal operating voltage. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig5.png" alt="Advanced Energy’s Senior Engineer confirming casing material" width="800" class="img-center">

<p align="center"><strong>Fig 2-6 Advanced Energy’s Senior Engineer confirming casing material (E. Wang, personal communication, Mar 03, 2025)</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig6.png" alt="TML and CVCM values from NASA’s Outgassing Database" width="800" class="img-center">

<p align="center"><strong>Fig 2-7 TML and CVCM values from NASA’s Outgassing Database (National Aeronautics and Space Administration, n.d.)</strong></p>

According to the senior engineer from the Advanced Energy, the converter's casing is made of black diallyl phthalate (E. Wang, personal communication, Mar 03, 2025).The material has TML and CVCM values of 0.56% and 0.00%, making it suitable for use in space applications (National Aeronautics and Space Administration, n.d.). 

<b>Design Implementation</b> 

The converter is powered by 5V and accepts a control signal ranging from 0V to 5 V to provide a maximum output of up to 600V. In the circuit design, the control pin is tied to 5V in the PCB. This simplifies the circuit design and reduces the workload of the ZSOM-M01 to control the converter. 

#### 2.3.2.2 Thermal Pad 

<b>Design Choice</b>

As the converter experiences a significant rise in temperature during operation, effective heat management is required to ensure its continued optimal operation in space. This is because there is no air in the vacuum of space to remove heat from the converter via convection.  Thermally conductive but electrically insulating thermal pad is used to conduct heat from the converter to the aluminium shielding of the payload, while maintaining electrical isolation to prevent short circuits. This utilises the high volume of the shielding as an effective heatsink to radiate heat away in space, thereby preventing the converter from overheating and getting damaged in space. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig7.png" alt="SIL-PAD 2000 Thermal Pad" width="600" class="img-center">

<p align="center"><strong>Fig 2-8 Figure 7.SIL-PAD 2000 Thermal Pad (DigiKey, 2025)</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig8.png" alt="Sil-Pad Outgassing Data" width="800" class="img-center">

<p align="center"><strong>Fig 2-9 Sil-Pad Outgassing Data (National Aeronautics and Space Administration, n.d.-b)</strong></p>

The SIL-PAD 2000 thermal pad was chosen as it has 0.07% and 0.03% as its TML and CVCM value respectively (National Aeronautics and Space Administration, n.d.-b). This makes it acceptable for space applications. 

Its high thermal conductivity of 3.5W/m-K helps it efficiently conduct heat away from the converter. It also has adhesive on one side, making it easier to secure in the payload (DigiKey, 2025).

<b>Design Implementation</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig9.png" alt="Thermal pad applied to the inside of the shielding" width="400" class="img-center">

<p align="center"><strong>Fig 2-10 Thermal pad applied to the inside of the shielding</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig10.png" alt="Converter pressed firmly on the thermal pad" width="600" class="img-center">

<p align="center"><strong>Fig 2-11 Converter pressed firmly on the thermal pad</strong></p>

Six 20mm by 25mm pieces of thermal pad were stacked to the left side of the shielding. so that the converter presses firmly onto the thermal pad when the PCB is mounted onto the shielding. This maximises the area of contact and minimises any gaps between the converter and the material, transferring heat effectively to the shielding in the vacuum of space.

<img src="{{site.baseurl}}/assets/images/weihao/Fig11.png" alt="Thermal pad applied to underside of shield cover" width="600" class="img-center">

<p align="center"><strong>Fig 2-12 Thermal pad applied to underside of shield cover</strong></p>

Three pieces of 22mm by 36mm of thermal pad were adhered on the top cover of the shielding, where the pins of the converter are situated. While the pins of the converter have sufficient clearance from the shielding, this further ensures that the pins, especially the 500v output pin of the converter, will be electrically isolated from the shielding.

#### 2.3.2.3 Cable Tie

<b>Design Choice</b>

Cable ties were needed to physically fasten the GM Tube to the PCB to prevent the GM tube from experiencing violent vibrations during launch and receiving consequent damage.

<img src="{{site.baseurl}}/assets/images/weihao/Fig12.png" alt="Pan-ty Cable Tie Halar Maroon" width="300" class="img-center">

<p align="center"><strong>Fig 2-13 Pan-ty Cable Tie Halar Maroon (Mouser Electronics, 2025)</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig13.png" alt="Cable Tie Outgassing Data" width="800" class="img-center"

<p align="center"><strong>Fig 2-14 Cable Tie Outgassing Data (National Aeronautics and Space Administration, n.d.-c)</strong></p>

The Pan-ty Cable Tie Halar Maroon was selected for its low outgassing properties, as compared to other cable-tie. Its TML and CVCM values were 0.21% and 0.01%, within the acceptable range for space applications.

<b> Design Implementation </b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig14.png" alt="Cable-tie securing GM tube to PCB" width="600" class="img-center">

<p align="center"><strong>Fig 2-15 Cable-tie securing GM tube to PCB</strong></p>

The cable-ties will be looped through holes designed on the PCB and tightened around the GM tube and PCB, firmly securing the GM tube in place and ensuring its mechanical stability throughout the launch and the mission.

## 2.4 Design Process

### 2.4.1 Proof of Concept

<img src="{{site.baseurl}}/assets/images/weihao/Fig15.png" alt="Breadboard prototype circuit" width="600" class="img-center">

<p align="center"><strong>Fig 2-16 Breadboard prototype circuit </strong></p>

The components were first tested in a proof of concept to refine component selection. Once the proof-of-concept worked, the process of PCB design started. 

Details on the proof-of-concept and its testing can be found in appendix B3.

### 2.4.2 Custom PCB Design

#### 2.4.2.1 PCB Schematic

Based on the proof of concept, PCB schematic was designed as follows: [Link]({{site.baseurl}}/assets/files/weihao/Fig16.pdf)

The overall design of the high voltage circuit remains unchanged since the proof-of-concept stage, except for the specific values of the resistors and capacitors. 

Detailed circuit components can be found in the appendix B4.

#### 2.4.2.2 PCB Layout 

Several iterations of the PCB were designed for testing hypotheses and aligning goals with the other teammates. 

Detailed breakdown of each iteration can be found in appendix B5.

<b> 2.4.2.2.1 Layout considerations </b>

Considerations while designing the PCB are listed below.

<b>High-voltage and Low-voltage clearance</b>

Internal conductors in the PCB like traces and external uncoated components on the PCB such as vias and exposed pads need to be 0.0025mm  and 0.00305mm apart per voltage of potential difference respectively. This is to prevent signal interference or electrical leakages (JHDPCB, 2024). 

For a maximum of 600V of potential difference,
Internal conductors clearance 
= <i>0.0025mm/v * 600V</i>
= <i>1.5mm</i>
External uncoated components 
= <i>0.00305mm/v * 600V</i>
= <i>1.83mm</i>

Hence, internal conductors and external components need to be at least 1.5mm and 1,83mm apart. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig17.png" alt="High voltage lines sufficient distances away from any low voltage line and components" width="600" class="img-center">

<p align="center"><strong>Fig 2-17 High voltage lines sufficient distances away from any low voltage line and components (Clearances marked in red) </strong></p>

<b>GM Tube Placement</b>
Since the GM tube receives radiation particles from its mica window, its window is oriented to face the right of the PCB which is unblocked by any component. This allows the GM tube to operate unhindered.

<b>Ground Pour</b>
Clearance was ensured between the ground plane and the high voltage lines to avoid electrical short-circuit due to the high potential difference. 

<b>Electrical Alignment</b>
The location of the pinstack was aligned with the low-voltage PCB developed by Sowmya. The high-voltage PCB needs to receive 5V and 3.3V power from the low voltage PCB, while sending GM tube signals to the ZSOM-M01 on the low-voltage PCB. To achieve this, a 6 header picoblade wire connects the boards. A 6 header molex male connector was placed on the right underside of the board to be closer to the other one on the low-voltage board. This allows a shorter picoblade wire to be used.

<b>Mechanical Alignment</b>
The PCB has to be mechanically mounted into the payload. Hence, the shape of the PCB and pinstack location was coordinated with Mingchuan who is developing the shielding and the mounting. The placement of the GM Tube was also coordinated to ensure that the entire payload will be shielded except for the GM tube for it to receive radiation particles.

<b>2.4.2.2.2 Final Layout</b>
The final PCB design incorporating the design considerations is shown below:

<img src="{{site.baseurl}}/assets/images/weihao/Fig18.png" alt="Final Layout" width="600" class="img-center">

<p align="center"><strong>Fig 2-18 Final Layout </strong></p>

### 2.4.5 Signal Conditioning Tuning
A simple arduino code was also developed to allow the ZSOM-M01 detect signals from the GM tube. The full code can be found in appendix B6.

The code was then passed to Richard to integrate into the ZSOM-M01 firmware.

### 2.4.6 Signal Conditioning Tuning
To ensure that inherent capacitances in the PCB was accounted for in the final prototype, the lowpass filter on the signal net on the latest PCB iteration was tuned. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig19.png" alt="Unfiltered Signal" width="600" class="img-center">

<p align="center"><strong>Fig 2-19 Unfiltered Signal </strong></p>

The incoming signal from the GM tube was very noisy, causing hundreds of false counts for each signal. This added up to a few thousand counts per minute, which was several times more than the normal background radiation of around 5 to 60 counts per minute (ECOTEST, 2025).

<img src="{{site.baseurl}}/assets/images/weihao/Fig20.png" alt="Filtered Signal" width="600" class="img-center">

<p align="center"><strong>Fig 2-20 Filtered Signal </strong></p>

Capacitor C2 was tuned to ensure that the lowpass filter on the signal net filtered only the noise and retained a clean wave with one positive and one negative edge per signal. It is also important to ensure that the filtered signal does not have too slow a rise time that two consecutive signals become detected as one. The optimal value for C2 was found to be 4.7uF.

## 2.5 High-Voltage PCB Assembly

The assembled high-voltage PCB is as follows:

<img src="{{site.baseurl}}/assets/images/weihao/Fig21.png" alt="Testing setup with synchronised microcontroller counts, oscilloscope pulses and LED blinks" width="600" class="img-center">

<p align="center"><strong>Fig 2-21 Final assembled PCB, front</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig22.png" alt="Current drawn by the high-voltage PCB and the low-voltage PCb" width="600" class="img-center">

<p align="center"><strong>Fig 2-22 Final assembled PCB, back</strong></p>

## 2.6 Results and Verifications

### 2.6.1. Pre-integration Testing

After finalising and tuning the PCB, it was tested to check if it remained within project requirements defined at the start of the project. 

<b> GM Tube Operation Test </b>

LED1 was temporarily soldered on the PCB in the location displayed on figure 18. If a particle was detected, the resultant signal pulls the signal net low and current flows through the LED, turning it on briefly. Once the signal passes, the net will be pulled high again and the LED turns off as no current flows through it. Hence, an LED blink indicates one signal pulse. 
The PCB was connected to the oscilloscope which displayed the pulses on the signal line. The time scale of the oscilloscope was set to 500ms to display all pulses within 5 seconds on the entire screen. An Arduino Uno was programmed to record and print its signal counts every 5 seconds. 

<iframe width="800" height="450" src="{{site.baseurl}}/assets/videos/weihao/Fig23.mp4" frameborder="0" allowfullscreen></iframe>

<p align="center"><strong>Fig 2-24 Testing setup with synchronised microcontroller counts, oscilloscope pulses and LED blinks </strong></p>

The LED blinks whenever a new pulse appears on the oscilloscope screen, and it tallies with the number of pulses present on the oscilloscope screen. The microcontroller’s counts also tallied with the number of pulses on the screen. Hence, the microcontroller is accurately recording pulses from the GM tube. 

<b>Current Consumption<b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig24.jpg" alt="Current drawn" width="600" class="img-center">

<p align="center"><strong>Fig 2-25 Current drawn by the high-voltage PCB (left) and the low-voltage PCb (right) </strong></p>

The high voltage PCB consumed between 0.086A to 0.14A. This, combined with the current drawn by the low-voltage PCB of between 0.026A to 0.032A, is lower than the 2A limit for our payload. Hence the 2A current supply limit is satisfied. 

<b> Maximum Temperature during Operation </b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig25.png" alt="Thermal imaging of the circuit, converter is the hostess component" width="600" class="img-center">

<p align="center"><strong>Fig 2-26 Thermal imaging of the circuit, converter is the hostess component </strong></p>

After running for 4 hours, the high-voltage PCB hottest component was the converter, and its temperature plateaued at 51.8°C degrees Celsius. As the maximum temperature reached by the converter is within its recommended operating temperature of -25°C to 70°C (Advanced Energy, 2023), the converter should be able to operate for prolonged periods of time during the mission.

### 2.6.2 Qualifications Testing

The high-voltage PCB is then integrated together into the rest of the payload and sent for qualification testing. Vibration and thermal cycle tests were conducted on the payload in the ST Engineering Advanced Networks and Sensors facility.

<b>Sine and Random Vibration testing</b>

The payload underwent both sine vibration and random vibration testing in all three axes. 

After the vibration testing, the payload was retested for any damage. It is found that the GM tube can still provide counts in the appropriate 5 to 60 range (ECOTEST, 2025), proving that the high-voltage PCB is undamaged

<b>Thermal Testing</b>

The payload was then subjected to 16 hour thermal cycle testing, with 4 hours each in cold (-25°C) and hot (+70°C) phase. The GM counts are then collected over this time and graphed along with temperature. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig26.png" alt="Plotting counts and temperature across duration of thermal cycling" width="600" class="img-center">

<p align="center"><strong>Fig 2-27 Plotting counts and temperature across duration of thermal cycling</strong></p>

The PCB generally operated as reliably, detecting between the normal range of 5 to 60 counts (ECOTEST, 2025), indicating no substantial damage to the circuit and that it is robust over a wide temperature range. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig27.png" alt="Outlier Count Data" width="800" class="img-center">

<p align="center"><strong>Fig 2-28 Outlier Count Data</strong></p>

The count was unusually lower than 5 for three minutes, around 12 midnight. This may be due to a momentary event where the converter supplied less than the minimum voltage range of 450 to the GM tube. If the GM tube is not provided with enough voltage, the GM tube’s signals will have a shorter period and get filtered by the lowpass filter on the signal net. Hence the signals may not be recorded by the ZSOM-M01. 

However, the counts returned to normal immediately after, signifying that the circuit did not suffer any lasting damage. Furthermore, while this event may be attributed to the rapid change in temperature, out of the 4 temperature shifts and over 16 hours, this event was concentrated over 3 minutes and never observed again. Hence, this is considered as an outlier datapoint and confidence remains high in the GM tube ability to provide robust radiation detection. 

## 2.7 Conclusion

In conclusion, the high-voltage PCB have successfully proven that it can provide robust radiation level readings even under extreme temperature environments and remain undamaged under intense vibrations. In addition to this, the additional materials like cable-tie and thermal pad posed no outgassing issues that may interfere with the other components and payloads. 

## 2.8 Future work

Moving on from our current stage, more development can be done in the lead up to launching our payload:

<ul>
  <li>Further testing and development on GM tube circuit to further prevent outlier data as seen in the thermal cycling test.</li>
  <li>Noise can be filtered from the 5V and 3.3V Picoblade input to further prevent noise from generating false counts.</li>
  <li>Optimise the thermal pad more to ensure higher heat transfer from the converter to the shielding.</li>
  <li>Assemble the final flight model and send it for protoflight testing.</li>
</ul>
