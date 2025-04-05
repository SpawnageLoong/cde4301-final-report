---
title: "Appendix B"
parent: More Appendices
nav_order: 2
permalink: /appendix-b/
last_modified_date: 05-04-2025
---

## Appendix B1: ZSOM Microcontroller

### Design Choice

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b1/zsom.png" alt="ZSOM Microcontroller" width="500">

<div class="fig-label">Fig B1-1. ZSOM-M01 board (Zero Error Systems, 2024b)</div>

As specified in the design requirements, a radiation-hardened microcontroller was required to store data reliably. This will ensure that the mission results are reliable. 

The ZSOM-M01 was considered because it can be programmed with the Arduino IDE, not only making it easily programmable but also interfaceable with the other chips we wish to experiment with.

Further analysis of the microcontroller’s available storage was conducted to further assure its suitability for the project. This is because as part of a radiation payload, components are to be exposed to high levels of radiation, increasing the risk of SEU occurring. A detailed comparison can be found in Appendix E.

FRAM was deemed suitable to store all the data due to its radiation-hardened status which reduces the risk of data corruption. Additionally, the proprietary EDAC code can correct any bitflips in the FRAM, further enhancing its data protection. The FRAM is also configured in Triple Modular Redundancy with radiation-hardened voters (Zero Error Systems, 2024b). This adds a third layer of protection for its memory contents, making it a suitable choice. The radiation-hardened test summary provided by Zero Error Systems can be found in the appendix.

Since the trustworthy Zero Error Systems meets the requirements of the mission, it has been chosen for the project.

### Analysis of Memory Storage Options

<table>
  <tr>
    <th>Memory</th>
    <th>Pros</th>
    <th>Cons</th>
  </tr>
  <tr>
    <td>Flash</td>
    <td>
      <ul>
        <li>Provides additional storage capacity</li>
        <li>Flexibility in additional capacity</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Need additional component</li>
        <li>Known to suffer from corruption due to SEE</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>SRAM</td>
    <td>
      <ul>
        <li>EDAC protection from corruption</li>
        <li>Help maximise FRAM by storing raw data while parity bits stored in FRAM</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Memory wiped after power cycling</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>FRAM</td>
    <td>
      <ul>
        <li>EDAC protection from corruption</li>
        <li>Radiation hardened</li>
        <li>TMR protection from corruption</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Limited storage capacity</li>
      </ul>
    </td>
  </tr>
</table>

<div class="fig-label">Table B1-1. Comparison of memory options</div>

Flash storage can help store massive amounts of data. However, flash memory is external to the microcontroller, hence it is not radiation-hardened. It is also known to get corrupted by radiation. This is because radiation removes electrons from the floating gate in flash memory, causing unwanted bitflips (Kay et al., 2017). Hence using flash memory may derail the mission due to the high risk of data corruption. Even if Error and Detection code (EDAC) can help correct data corruption, the code may not be robust enough to handle multiple types of corruption events (Hansen et al., n.d.). Therefore flash memory should be avoided to prevent this potential point of failure. 

SRAM is the next viable storage option. However, the data in SRAM gets wiped out if power cycling happens (Awati & Sheldon, 2024). Since there is a high chance that other non-radiation-hardened components experience latchups, the frequency of power cycling may be high. Hence, there would be little to no progress in the mission as the collected data get wiped frequently To avoid this, the SRAM should not be used.

## Appendix B2: Radiation Sensor

### Design Choice

Several radiation sensors were considered below. These sensors were chosen on their ability to detect the desired charged particles.

<table>
  <tr>
    <th></th>
    <th>GM Tube</th>
    <th>Ion Chamber</th>
    <th>Solid State Detector</th>
  </tr>
  <tr>
    <td>Particles</td>
    <td style="color: green">Alpha, Beta, Gamma</td>
    <td style="color: red">Alpha, Beta, but mainly Gamma</td>
    <td style="color: green">Alpha, Beta, Gamma</td>
  </tr>
  <tr>
    <td>Input Voltage</td>
    <td style="color: red">High</td>
    <td style="color: green">Low</td>
    <td style="color: green">Low</td>
  </tr>
  <tr>
    <td>Form Factor</td>
    <td style="color: green">Very small and light</td>
    <td style="color: green">Very small and light</td>
    <td style="color: red">Bilkier for more than 1 radiation type</td>
  </tr>
  <tr>
    <td>Durability</td>
    <td style="color: green">Robust</td>
    <td style="color: red">Fragile when built to detect alpha and beta</td>
    <td style="color: red">vulnerable to radiation damage</td>
  </tr>
  <tr>
    <td>Ease of Testing</td>
    <td style="color: green">Easy</td>
    <td style="color: green">Easy</td>
    <td style="color: red">Difficult</td>
  </tr>
</table>

<div class="fig-label">Table B2-1. Comparison of radiation sensors</div>

A more detailed comparison of the other sensors is in Appendix G.

Geiger-Müller (GM) tubes are preferred in our project to provide radiation data from desired particles that are responsible for SEE. It only requires simple electronics to provide high potential difference across its terminals and to read the signals it produces, making it easy to integrate. They are also considered a cheap relative to other sensors, but they have low energy detection efficiency when receiving high doses of radiation (Matsusada Precision Inc., 2024). However, it is sufficient as the project only needs to quantify the radiation received by the payload, and does not need comprehensive and high-resolution data. The GM tube is also chosen since the other two options are also more vulnerable to damage during space operations, causing a major risk of failure during the mission.

### Design Proposition

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b2/gm-tube.png" alt="GM Tube" width="500">

<div class="fig-label">Fig B2-1. LND712 GM Tube (LND. Inc., n.d.)</div>

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b2/gm-tube-setup.png" alt="GM Tube Setup" width="500">

<div class="fig-label">Fig B2-2. Recommended wiring for LND712 (LND. Inc., n.d.)</div>

The LND 712 is chosen for our purposes. It requires between 450 to 650V to operate, hence power can be supplied easily with a DC-to-DC converter, making it easy to integrate. The connections required are also very simple, requiring two resistors and a 50pF capacitor. This component, although being one of the largest components in the circuit, only weighs a mere 8g, therefore providing extra allowance on the mass budget for other purposes (LND. Inc., n.d.).

## Appendix B3: Proof of Concept

### Circuit Layout

Reference was taken from a tutorial on Sparkfun on assembling the circuit components.

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b3/circuit1.png" alt="Circuit Layout" width="500">

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b3/circuit2.png" alt="Circuit Layout" width="500">

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b3/circuit3.png" alt="Circuit Layout" width="500">

<div class="fig-label">Figs B3-1, B3-2, B3-3. Reference circuit taken from Sparkfun tutorial (bitsmashed, 2009)</div>

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b3/prototype.png" alt="Circuit Layout" width="500">

<div class="fig-label">Fig B3-4. Prototype circuit</div>

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b3/readings.png" alt="Circuit Layout" width="500">

<div class="fig-label">Fig B3-5. Readings from the prototype circuit</div>

The microcontroller successfully detected the radiation signals from the GM Tube. 

This proof of concept validated the following findings:

- Load-independent DC-DC converter provided reliable 500V that is sufficient for GM Tube operations
- Signal conditioning is sufficient, and the signal from the GM is detectable by the microcontroller. 

Following form this experiment, further optimizing the circuit components, especially R0, R1, and C0 is required before the custom circuit board can be designed and fabricated

## Appendix B4: High Voltage Circuit Design

The high voltage circuit is made of the following parts:

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b4/lowpass.png" alt="Low Pass Filter" width="500">

<div class="fig-label">Fig B4-1. First Low Pass Filter</div>

Lowpass Filter (R1 and C0) to prevent signals from interfering with the source.

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b4/highpass.png" alt="High Pass Filter" width="500">

<div class="fig-label">Fig B4-2. High Pass Filter</div>

Highpass Filter (R0 and C0) to filter signals towards the microcontroller.

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b4/currentamp.png" alt="Current Amplifier" width="500">

<div class="fig-label">Fig B4-3. Current Amplifier</div>

Current amplifier (Q0 and R3) to amplify the current of signals to be identified by the microcontroller.

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b4/pullup.png" alt="Pull Up" width="500">

<div class="fig-label">Fig B4-4. Pull Up</div>

A 3.3V pull-up (R4) to bring the signal line to 3V3 if the line is floating.

TODO: IMAGE
<img src="{{site.baseurl}}/assets/images/appendix-b4/lowpass2.png" alt="Low Pass Filter" width="500">

Lowpass filter (C1) to clean up signal for reading.
