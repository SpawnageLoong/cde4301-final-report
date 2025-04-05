---
title: "Appendix D: Experiment Information"
parent: Appendices
nav_order: 4
permalink: /experiment/
last_modified_date: 16-11-2024
---

# Experiment Information

## D.1 Reason for 1 minute Interval between Runs of the Experiment

<ul>
	<li>Given that a LEO takes 90-120 minutes, we would want to conduct the experiment for at least half the orbit duration. Since the rideshare is not decided upon, we go with the higher number of 60 minutes per orbit. </li>
	<li>A finer resolution in time is preferred in general, to prevent double bit flips from occurring since our bit flip count cannot reflect double flips. </li>
	<li>However, the data budget shows that we can run up to 60 runs of the experiment per orbit. Hence, the interval between runs is decided as 1 minute.</li>
</ul>


## D.2 Possible Faults in I2C in Space Environment and Management Approach

<table>
  <thead>
    <tr>
      <th>Problem</th>
      <th>Management Method</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Data Corruption</td>
      <td>CRC Checks [To be implemented next semester provided it doesn’t cause high increase in data transfer time]. If it causes a high increase in data transfer time, try simpler methods like parity bit.</td>
    </tr>
    <tr>
      <td>Signal Integrity Issues</td>
      <td>Intend to implement proper PCB design with controlled impedance for I2C trace and add series resistors to I2C lines to dampen reflections.</td>
    </tr>
    <tr>
      <td>Power Supply Fluctuation</td>
      <td>Surge protector, in the form of SEL protection by ZSOM.</td>
    </tr>
    <tr>
      <td>Bus Lock-Up</td>
      <td>Watchdog timers to reset the I2C bus in case of a lock-up (timeout feature). Power reset in case of a lockup that can’t be fixed by the recommended I2C reset method.</td>
    </tr>
    <tr>
      <td>Cross-Talk</td>
      <td>Using relatively slower clock speeds, that still provide reasonable data transfer timings, to reduce susceptibility to cross-talk.</td>
    </tr>
  </tbody>
</table>



## D.3 Other Microcontrollers having USB support but not selected

<table>
  <thead>
    <tr>
      <th>SNo.</th>
      <th>MCU</th>
      <th>Reason</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>ATMega16U4</td>
      <td>1.25KB SRAM only and less likely to be used in future missions because of small memory size</td>
    </tr>
    <tr>
      <td>2</td>
      <td>SAMD21</td>
      <td>It is the one already in Arduino M0+ in ZSOM</td>
    </tr>
    <tr>
      <td>3</td>
      <td>STM32F0/F1/F4</td>
      <td>20KB SRAM is too big and not as popular</td>
    </tr>
    <tr>
      <td>4</td>
      <td>ESP32-S2 and ESP32-S3</td>
      <td>320KB SRAM, too big</td>
    </tr>
    <tr>
      <td>5</td>
      <td>RP2040</td>
      <td>264KB SRAM, too big and the coding environment is not simple - less likely to be used</td>
    </tr>
    <tr>
      <td>6</td>
      <td>Teensy</td>
      <td>64KB RAM, too big</td>
    </tr>
    <tr>
      <td>7</td>
      <td>PIC18F/32 Series</td>
      <td>Not as user-friendly, not very popular - less likely to be used in future missions</td>
    </tr>
    <tr>
      <td>8</td>
      <td>AT32UC3 Series</td>
      <td>Specifically designed for USB device applications - not broad enough, hence less likely to be used in future missions</td>
    </tr>
    <tr>
      <td>9</td>
      <td>nRF52840</td>
      <td>Has Bluetooth support that is not required in most Cubesat applications and also not popular - less likely to be used in future missions</td>
    </tr>
  </tbody>
</table>


## D.4 Flight Heritage Information about the ATMega328P 

<ul>
	<li>The ATmega328P microcontroller has flown on several CubeSats, with ArduSat-1 (2013) and ArduSat-2 (2014) being notable examples. </li>
	<li>Mitigation strategies included using software-based error correction and redundancy. </li>
	<li> The satellites operated successfully for their planned lifespans, indicating that these measures were effective for short-term missions in LEO.</li>
	<li>While the solar conditions of 2025 will be different (more intense) than the conditions of 2013, 2013 was also a time of solar peak. </li>
	<li>Our satellite is also going to be flying at LEO, for short-term, and during solar peak of Cycle 25.</li>
</ul>

 <b>We wish to send a new microcontroller to space that hasn’t flown in LEO orbit before, so that it can be tested for its radiation tolerance.</b>

However, below is the table comparing the solar conditions, for more information. 

<table>
  <thead>
    <tr>
      <th>Parameter</th>
      <th>2013 (Solar Cycle 24)</th>
      <th>2025 (Expected, Solar Cycle 25)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Solar Cycle Peak Year</strong></td>
      <td>2014 (April)</td>
      <td>2025 (July, projected)</td>
    </tr>
    <tr>
      <td><strong>Maximum Sunspot Number</strong></td>
      <td>114 (weakest in 100 years)</td>
      <td>137–173 (below average but stronger than Cycle 24)</td>
    </tr>
    <tr>
      <td><strong>Solar Flares</strong></td>
      <td>Low to moderate (mostly C-class and M-class)</td>
      <td>Moderate to high (increased likelihood of M and X-class flares)</td>
    </tr>
    <tr>
      <td><strong>Coronal Mass Ejections</strong></td>
      <td>Few and weak</td>
      <td>Increased frequency and strength expected</td>
    </tr>
    <tr>
      <td><strong>Geomagnetic Storms</strong></td>
      <td>Minor to moderate</td>
      <td>Moderate to strong</td>
    </tr>
    <tr>
      <td><strong>Auroras</strong></td>
      <td>Visible near polar regions</td>
      <td>Potentially visible at lower latitudes</td>
    </tr>
  </tbody>
</table>


## D.5 Pictures of the Prototype and Some of the Testing

### D.5.1 The Prototype

<img src="{{site.baseurl}}/assets/images/appendix_d/img_1.png" alt="prototype" width="350">

### D.5.2 The SRAM Dump
As seen below, the fixed pattern of 55 can be stored across a certain range of memory addresses. This range of memory addresses remains constant as well.

<img src="{{site.baseurl}}/assets/images/appendix_d/img_2.png" alt="SRAM dump" width="700">