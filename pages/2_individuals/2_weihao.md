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

The objective of my work is to ensure that the payload can detect and record radiation levels accurately, and that the components used to fulfil the objective are suitable for space applications. My scope of work consists of the following tasks:

<b>1. Radiation Sensor Operations</b>

As part of mission objectives, the payload will be monitoring and storing radiation counts. A radiation sensor has to be powered and its output read and stored. 

<b>2. High Voltage PCB Design</b>

Custom Printed Circuit Boards (PCB) were designed to provide the high power requirements of the radiation sensor and to process its output. Sufficient clearance is required between the high voltage lines from the rest of the signal conditioning circuit. This prevents inference between the two systems that can break down the entire payload.

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
      <td>Assumption of 5V provided by flight provider.</td>
    </tr>
    <tr>
      <td>Current Consumption</td>
      <td>&lt;2A</td>
      <td>Assumption of 2A maximum provided by flight provider. Current is shared with low voltage board developed by Sowmya.</td>
    </tr>
    <tr>
      <td>Radiation Sensor</td>
      <td>Detects alpha and beta particles</td>
      <td>Monitor the particles responsible for SEE.</td>
    </tr>
    <tr>
      <td>Signal processing</td>
      <td>Microcontroller gets triggered once per signal for accurate detection</td>
      <td>Ensure radiation is correctly recorded by the microcontroller.</td>
    </tr>
    <tr>
      <td>Microcontroller</td>
      <td>Radiation-Hardened</td>
      <td>Provide reliable data storage throughout the mission.</td>
    </tr>
    <tr>
      <td>High and low voltage clearance</td>
      <td>Ensure voltage lines do not interfere with each other</td>
      <td>Avoid eletrical damage and compromising other systems on the same payload or satellite.</td>
    </tr>
    <tr>
      <td>Signal interference</td>
      <td>Signals only travel through the signal net</td>
      <td>Prevent unwanted noise in other nets and prevent unwanted distortions to signal.</td>
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
    <tr>
      <td>Thermal resistance</td>
      <td>
        Component must be able to operate reliably from -25°C to 70°C (FalconUsersGuide, 2021).
      </td>
      <td>
        Component must pass the thermal cycling test for qualifications testing. More details on thermal cycling test will becovered by Mingchuan
      </td>
    </tr>
    <tr>
      <td>Mechanical robustness</td>
      <td>
        Component must be able to operate reliably after intense vibrations from all axis experienceed during launch.
      </td>
      <td>
        Component must pass the random and sine vibrations test for qualifications testing. More details on vibration tests will be covered by Mingchuan.
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

<img src="{{site.baseurl}}/assets/images/weihao/Fig1.jpg" alt="ZSOM-M01 board" width="600" class="img-center">

<p align="center"><strong>Fig 2-2  ZSOM-M01 board (Zero Error Systems, 2024b)</strong></p>

The ZSOM-M01 remained on the final design due to its reliability in storing data of the mission. This trait is supported by its radiation hardened status, Triple Modular Redundancy configuration and the Error Detection and Correction functionality (Zero Error Systems, 2024b). Since our main mission consists of a memory corruption experiment of Atmega32U4 microcontrollers, the ZSOM-M01 provides the robust foundation for collecting data for further analysis. 

The detailed explanation for choosing ZSOM-M01 can be found in appendix B1.

The ZSOM-M01 can operature within the temperature range of -40°C to 105°C, allowing it to operate normally within the temperature range for the thermal cycling test (Zero Error Systems, 2024b). 

<b>Design Implementation</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig2.jpg" alt="Pinout of ZSOM-M01" width="600" class="img-center">

<p align="center"><strong>Fig 2-3 Pinout of ZSOM-M01 (Zero Error Systems, 2024b)</strong></p>

The ZSOM-M01 pins that were planned to be used in the circuit were altered during prototyping. The Geiger-Müller (GM) tube now sends the detected signal at unpredictable intervals to the ZSOM-M01 via D4 interrupt pin. This allows the ZSOM-M01 to  count the signal immediately in the midst of its other operations, ensuring that the signals are recorded accurately.

The PWM pin from the ZSOM-M01 is no longer needed to controlthe converter. This further simplifies the circuit. The new connection will be shown in the later circuit design.

#### 2.3.1.2 GM Tube

<b>Design Choice</b>

The GM tube remained on the final design as it could provide robust signals as an indication of the radiation levels it experienced. Detailed explanation of its choice over other detectors can be found in the appendix B2.

<b>Design Implementation</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig3.jpg" alt="LND712 GM Tube" width="600" class="img-center">

<p align="center"><strong>Fig 2-4 LND712 GM Tube (LND. Inc., n.d.)</strong></p>

The LND 712 is chosen for our purposes. It requires between 450V to 650V to operate, which can be supplied easily with a DC-to-DC converter, making it easy to integrate. The connections required are also very simple, requiring two resistors and a 50pF capacitor. The GM tube can also operate between -40°C to 70°C, hence it can operate normally during the thermal cycling test (LND. Inc., n.d.). 

### 2.3.2 New Components
Several new components are added to the final design.

#### 2.3.2.1 DC-DC Converter

<b> Design Choice </b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig4.jpg" alt="AEQ5-600FL0.5 Converter" width="400" class="img-center">

<p align="center"><strong>Fig 2-5 AEQ5-600FL0.5 Converter (Element14, 2025)</strong></p>

The AEQ5-600FL0.5 provides a reliable input of around 600V to the GM tube, allowing the Gm tube to operate optimally without being vulnerable to small changes in load that may disrupt its poeer supply. This prevents over-voltage damage to the GM tube, and allows it to work at its optimal operating voltage. It can also operate between -25°C to 70°C, hence it can operate normally during the thermal cycling test (Element14, 2025).

<img src="{{site.baseurl}}/assets/images/weihao/Fig5.jpg" alt="Advanced Energy’s Senior Engineer confirming casing material" width="800" class="img-center">

<p align="center"><strong>Fig 2-6 Advanced Energy’s Senior Engineer confirming casing material (E. Wang, personal communication, Mar 03, 2025)</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig6.png" alt="TML and CVCM values from NASA’s Outgassing Database" width="800" class="img-center">

<p align="center"><strong>Fig 2-7 TML and CVCM values from NASA’s Outgassing Database (National Aeronautics and Space Administration, n.d.)</strong></p>

According to the senior engineer from the Advanced Energy, the converter's casing is made of black diallyl phthalate (E. Wang, personal communication, Mar 03, 2025).The material has TML and CVCM values of 0.56% and 0.00%, making it suitable for use in space applications (National Aeronautics and Space Administration, n.d.). 

<b>Design Implementation</b> 

The converter is powered by 5V and accepts a control signal ranging from 0V to 5 V to provide a maximum output of up to 600V. In the circuit design, the control pin is tied to 5V in the PCB. This simplifies the circuit design and reduces the workload of the ZSOM-M01 to control the converter. 

#### 2.3.2.2 Thermal Pad 

<b>Design Choice</b>

As the converter experiences a significant rise in temperature during operation, effective heat management is required to ensure its continued optimal operation in space. This is because there is no air in the vacuum of space to remove heat from the converter via convection. Thermally conductive but electrically insulating thermal pad is used to conduct heat from the converter to the aluminium shielding of the payload, while maintaining electrical isolation to prevent short circuits. This utilises the high volume of the shielding as an effective heatsink to radiate heat away in space, thereby preventing the converter from overheating and getting damaged. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig7.jpg" alt="SIL-PAD 2000 Thermal Pad" width="600" class="img-center">

<p align="center"><strong>Fig 2-8 Figure 7.SIL-PAD 2000 Thermal Pad (DigiKey, 2025)</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig8.png" alt="Sil-Pad Outgassing Data" width="800" class="img-center">

<p align="center"><strong>Fig 2-9 Sil-Pad Outgassing Data (National Aeronautics and Space Administration, n.d.-b)</strong></p>

The SIL-PAD 2000 thermal pad was chosen as it has 0.07% and 0.03% as its TML and CVCM value respectively (National Aeronautics and Space Administration, n.d.-b). This makes it acceptable for space applications. 

Its high thermal conductivity of 3.5W/m-K helps it efficiently conduct heat away from the converter. It also has adhesive on one side, making it easier to secure in the payload. Furthermore, it can withstand temperatures from -60°C to 200°C, hence it will not receive damage from the thermal cycling test (DigiKey, 2025).

<b>Design Implementation</b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig9.jpg" alt="Thermal pad applied to the inside of the shielding" width="400" class="img-center">

<p align="center"><strong>Fig 2-10 Thermal pad applied to the inside of the shielding</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig10.jpg" alt="Converter pressed firmly on the thermal pad" width="600" class="img-center">

<p align="center"><strong>Fig 2-11 Converter pressed firmly on the thermal pad</strong></p>

Six 20mm by 25mm pieces of thermal pad were stacked to the left side of the shielding, so that the converter presses firmly onto the thermal pad when the PCB is mounted onto the shielding. This maximises the area of contact and minimises any gaps between the converter and the material, transferring heat effectively to the shielding in the vacuum of space.

<img src="{{site.baseurl}}/assets/images/weihao/Fig11.jpg" alt="Thermal pad applied to underside of shield cover" width="600" class="img-center">

<p align="center"><strong>Fig 2-12 Thermal pad applied to underside of shield cover</strong></p>

Three pieces of 22mm by 36mm of thermal pad were adhered on the top cover of the shielding, where the pins of the converter are situated. While the pins of the converter have sufficient clearance from the shielding, this further ensures that the pins, especially the 500V output pin of the converter, will be electrically isolated from the shielding.

#### 2.3.2.3 Cable Tie

<b>Design Choice</b>

Cable ties were needed to physically fasten the GM tube to the PCB. This is to prevent the GM tube from receiving damage when experiencing violent vibrations during launch.

<img src="{{site.baseurl}}/assets/images/weihao/Fig12.jpg" alt="Pan-ty Cable Tie Halar Maroon" width="300" class="img-center">

<p align="center"><strong>Fig 2-13 Pan-ty Cable Tie Halar Maroon (Mouser Electronics, 2025)</strong></p>

<img src="{{site.baseurl}}/assets/images/weihao/Fig13.jpg" alt="Cable Tie Outgassing Data" width="800" class="img-center">

<p align="center"><strong>Fig 2-14 Cable Tie Outgassing Data (National Aeronautics and Space Administration, n.d.-c)</strong></p>

The Pan-ty Cable Tie Halar Maroon was selected for its low outgassing properties, as compared to other cable-ties. Its TML and CVCM values were 0.21% and 0.01%, within the acceptable range for space applications (National Aeronautics and Space Administration, n.d.-c). 

It can also withstand the temperature range of -60°C to 125°C, thus avoiding any damage during the thermal cycling test (Panduit, n.d.).

<b> Design Implementation </b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig14.png" alt="Cable tie securing GM tube to PCB" width="600" class="img-center">

<p align="center"><strong>Fig 2-15 Cable tie securing GM tube to PCB</strong></p>

The  ties will be looped through holes designed on the PCB and tightened around the GM tube and PCB, firmly securing the GM tube in place and ensuring its mechanical stability throughout the launch and the mission.

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

Detailed explanations for the circuit design can be found in the appendix B4.

#### 2.4.2.2 PCB Layout 

Several iterations of the PCB were designed for testing hypotheses and aligning design goals with the other teammates. 

Detailed breakdown of each iteration can be found in appendix B5.

<b> 2.4.2.2.1 Layout considerations </b>

Considerations while designing the PCB are listed below.

<b>High-voltage and Low-voltage clearance</b>

Internal conductors in the PCB like traces and external uncoated components on the PCB such as vias and exposed pads need to be 0.0025mm  and 0.00305mm apart per voltage of potential difference respectively. This is to prevent signal interference or electrical leakages (JHDPCB, 2024). 

For a maximum of 600V of potential difference,
<p>Internal conductors clearance 
= <i>0.0025mm/v * 600V</i>
= <i>1.5mm</i></p>
<p>External uncoated components 
= <i>0.00305mm/v * 600V</i>
= <i>1.83mm</i></p>

Hence, internal conductors and external components need to be at least 1.5mm and 1.83mm apart respectively. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig17.png" alt="High voltage lines sufficient distances away from any low voltage line and components" width="600" class="img-center">

<p align="center"><strong>Fig 2-17 High voltage lines sufficient distances away from any low voltage line and components (Clearances marked in red) </strong></p>

<b>Ground Pour</b>
<p>Clearance was based on the above calculations also ensured between the ground plane and the high voltage lines to avoid electrical short-circuits or arcing due to the high potential difference. </p>

<b>GM Tube Placement</b>
<p>Since the GM tube receives radiation particles from its mica window, its window is oriented to face the right of the PCB which is unblocked by any component. This allows the GM tube to operate unhindered.</p>

<b>Electrical Alignment</b>
<p>The location of the pinstack was aligned with the low-voltage PCB developed by Sowmya. The high-voltage PCB needs to receive 5V and 3.3V power from the low voltage PCB, while sending GM tube signals to the ZSOM-M01 on the low-voltage PCB. To achieve this, a 6-header picoblade wire is used to connect the two boards. A 6-header molex male connector was placed on the right underside of the board to be closer to the other one on the low-voltage board. This allows a shorter picoblade wire to be used.</p>

<b>Mechanical Alignment</b>
<p>The PCB has to be mechanically mounted into the payload. Hence, the shape of the PCB and pinstack location was coordinated with Mingchuan who developed the shielding and the mounting. The placement of the GM tube was also coordinated to ensure that the entire payload will be shielded except for the GM tube for it to receive radiation particles.</p>

<b>2.4.2.2.2 Final Layout</b>
The final PCB design incorporating the design considerations is shown below:

<img src="{{site.baseurl}}/assets/images/weihao/Fig18.png" alt="Final Layout" width="600" class="img-center">

<p align="center"><strong>Fig 2-18 Final Layout </strong></p>

### 2.4.5  Signal Detection Code
A simple arduino code was also developed to allow the ZSOM-M01 detect signals from the GM tube. The ZSOM-M01 will count the signals for a minute to provide the radiation reading as counts per minute. The full code can be found in appendix B6.

The code was then passed to Richard to integrate into the ZSOM-M01 firmware.

### 2.4.6 Signal Conditioning Tuning
To ensure that inherent capacitances in the PCB was accounted for in the final prototype, the lowpass filter on the signal net on the latest PCB iteration was tuned. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig19.png" alt="Unfiltered Signal" width="600" class="img-center">

<p align="center"><strong>Fig 2-19 Unfiltered Signal </strong></p>

The raw incoming signal from the GM tube is very noisy, causing hundreds of false counts for each signal. This added up to thousands counts per minute, which was several times more than the normal background radiation of around 5 to 60 counts per minute (ECOTEST, 2025).

<img src="{{site.baseurl}}/assets/images/weihao/Fig20.png" alt="Filtered Signal" width="600" class="img-center">

<p align="center"><strong>Fig 2-20 Filtered Signal </strong></p>

Capacitor C2 was tuned to ensure that the lowpass filter on the signal net filtered only the noise and retained a clean wave with one positive and one negative edge per signal. It is also important to ensure that the filtered signal does not a slow rise time to avoid two consecutive signals getting detected as one. The optimal value for C2 was found to be 4.7uF.

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

A blue LED, LED1, was temporarily soldered on the PCB in the location displayed on figure 18. If a particle was detected, the resultant signal pulls the signal net low and current flows through the LED, turning it on briefly. Once the signal passes, the net will be pulled high again and the LED turns off as no current flows through it. Hence, an LED blink indicates one signal pulse. 
The PCB was connected to the oscilloscope which displayed the pulses on the signal line. The time scale of the oscilloscope was set to 500ms to display all pulses within 5 seconds on the entire screen. An Arduino Uno was programmed to record and print its signal counts every 5 seconds. 

<iframe width="800" height="450" src="{{site.baseurl}}/assets/videos/weihao/Fig23.mp4" frameborder="0" allowfullscreen></iframe>

<p align="center"><strong>Fig 2-24 Testing setup with synchronised microcontroller counts, oscilloscope pulses and LED blinks </strong></p>

The LED blinks whenever a new pulse appears on the oscilloscope screen, and it blinks the same number of times in 5 seconds as the number of pulses present on the oscilloscope screen. The microcontroller’s counts is also synchronised with the number of pulses on the screen. Hence, the microcontroller is accurately recording pulses from the GM tube. 

<b>Current Consumption<b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig24.jpg" alt="Current drawn" width="600" class="img-center">

<p align="center"><strong>Fig 2-25 Current drawn by the high-voltage PCB (left) and the low-voltage PCB (right) </strong></p>

The high voltage PCB consumed between 0.086A to 0.14A. The high-voltage PCB, combined with the current drawn by the low-voltage PCB of between 0.026A to 0.032A, will draw a maximum current of 0.172A. This is lower than the 2A limit for our payload. Hence the 2A current supply limit is satisfied. 

<b> Maximum Temperature during Operation </b>

<img src="{{site.baseurl}}/assets/images/weihao/Fig25.png" alt="Thermal imaging of the circuit, converter is the hostess component" width="600" class="img-center">

<p align="center"><strong>Fig 2-26 Thermal imaging of the circuit, converter is the hostess component </strong></p>

After running for 4 hours, the hottest component on the PCB was found to be the converter, and its temperature plateaued at 51.8°C degrees Celsius. As the maximum temperature reached by the converter is within its recommended operating temperature of -25°C to 70°C (Advanced Energy, 2023), the converter should be able to operate for prolonged periods of time during the mission.

### 2.6.2 Qualifications Testing (Post-integration)

The high-voltage PCB is then integrated together into the rest of the payload and sent for qualification testing. Vibration and thermal cycle tests were conducted on the payload in the ST Engineering Advanced Networks and Sensors facility.

<b>Sine and Random Vibration testing</b>

The payload underwent both sine vibration and random vibration testing in all three axes to tet for its mechanical stability. The specifics of the sine and random vibration test will be elaborated in Mingchuan's section.

After the vibration testing, the payload was retested for any damage. It is found that the GM tube can still provide counts per minute in the appropriate 5 to 60 range (ECOTEST, 2025), showing that the high-voltage PCB and its components is undamaged. This proves that the components chosen for the high-voltage PCB can withstand the intense vibrations during launch.

<b>Thermal Testing</b>

The payload was then subjected to 16 hour thermal cycle testing, with 4 hours each in cold (-25°C) and hot (+70°C) phase. The GM tube's counts per minute are then collected over this time and plotted along the temperature. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig26.png" alt="Plotting counts and temperature across duration of thermal cycling" width="600" class="img-center">

<p align="center"><strong>Fig 2-27 Plotting counts and temperature across duration of thermal cycling</strong></p>

The PCB generally operated as per normal, detecting between the normal range of 5 to 60 counts per minute (ECOTEST, 2025), indicating no substantial damage to the circuit and proving its reliability over a wide temperature range that it is expected to experience in space. 

<img src="{{site.baseurl}}/assets/images/weihao/Fig27.png" alt="Outlier Count Data" width="800" class="img-center">

<p align="center"><strong>Fig 2-28 Outlier Count Data</strong></p>

Upon closer analysis, the count was unusually lower than 5 counts per minute for three minutes, at around 12 midnight. This may be due to a momentary event where the converter supplied less than the minimum voltage range of 450V to the GM tube. If the GM tube does not receive enough voltage, its signals will have a shorter period and get filtered by the lowpass filter on the signal net. Hence the detected signals may not be recorded by the ZSOM-M01. 

However, the counts returned to normal immediately after, signifying that the circuit did not suffer any permanent damage. Furthermore, while this event may be attributed to the rapid change in temperature, it only occured once out of the 4 temperature shifts. Moreover, over 16 hours of testing, this event only occured once over a short 3 consecutive minutes. Hence, these 3 data points can be considered as outliers and confidence remains high in the high-voltage PCB's ability to provide robust radiation detection under extreme temperatures and changes in temperature. 

## 2.7 Conclusion

In conclusion, the high-voltage PCB have successfully proven that it can provide reliable radiation level readings even under extreme temperature environments and remains undamaged under intense vibrations. Furthermore, the additional materials like cable tie and thermal pad posed no outgassing issues that may interfere with the other components and payloads. 

## 2.8 Future work

Moving on from our current stage, more development can be done in the lead up to launching our payload:

<ul>
  <li>Further testing and development on GM tube circuit to further prevent outlier data as seen in the thermal cycling test.</li>
  <li>Noise can be filtered from the 5V and 3.3V Picoblade input to further prevent noise from generating false counts.</li>
  <li>Optimise the thermal pad more to ensure higher heat transfer from the converter to the shielding.</li>
  <li>Assemble the final flight model and send it for protoflight testing.</li>
</ul>
