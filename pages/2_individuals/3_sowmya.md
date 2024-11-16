---
title: Sowmya
parent: Individual Contributions
nav_order: 3
permalink: /sowmya/
---

<div style="display:flex">
  <img src="{{site.baseurl}}/assets/images/profiles/sowmya.jpg" alt="Sowmya" width="200" style="border-radius:50%">
  <div style="margin-left: 20px">
    <h2>Sowmya Srinivasan</h2>
    <h3>Year 4 Electrical Engineering</h3>
    <h3>A0246190H</h3>
  </div>
</div>

# 2. The Bit Flip Experiment

## 2.1 Objectives, Scope of Work & Deliverables

<b>Objective:</b> The complete implementation of the Radiation-SEU Correlation experiment. 

<b>The Deliverables:</b>
Proposal of Radiation-SEU Correlation Experiment
PCB Implementation of the Proposed Experiment for the Payload.

## Background & Research Gap Identification

### 2.2.1 The Reason For Monitoring Bit Flips 

Bits that represent either data or programs, are stored in computer memory as charge. Different memory devices deal with different levels of charge to store bits. When ionizing particle radiation strikes a material, it can alter this charge, changing 0’s to 1’s and vice versa. These flips cause corruption in both program and data memory and are called SEU. [[1]]({{site.baseurl}}/references/#1-baraniuk-c-2022-october-12-the-computer-errors-from-outer-space-bbc-link)

### 2.2.2 Bit Flip Experiments Carried Out

While some microcontrollers have been in LEO, the only experiment carried out and available online is by Utah State University [[5]]({{site.baseurl}}/references/#5-olsen-w-wood-b-dennison-j-nd-microcontroller-survivability-in-space-conditions-link), but the experiment was conducted in a lab environment, and the data collected was limited. The diagram below summarizes the current state of research on bit flips in space. 

<img src="{{site.baseurl}}/assets/images/sowmya/img_1.jpg" alt="state of bit flip research" width="700">

<b>Hence, there is a gap in research about bit flips in microcontrollers in space environment. </b>

While data from computers can give cubesat developers a rough idea of what to expect, the data cannot be confidently used for microcontrollers. Hence, our payload intends to bridge this gap in research and benefit our stakeholders. 

## 2.3 Design Process

### 2.3.1 Concept of Experiment

#### 2.3.1.1 Basic Idea

<ul>
	<li>The experiment comprises microcontrollers of the same kind being sent to space, both shielded and unshielded.</li>
	<li>While having multiple microcontrollers with different shielding materials or thickness would be ideal, the space constraint and data budget limit permit only 2 microcontrollers to be used. </li>
	<li>Hence, one microcontroller is unshielded, while the other is shielded (shielding is from Mingchuan). </li>
	<li>Both the microcontrollers under experiment would experience bit flips, and every minute, a central microcontroller (selected by WeiHao) gathers the data on bit flips from them. The reasoning for a 1 minute interval is in Appendix Section D.1</li>
	<li>The central microcontroller then computes the error count by comparing the fixed pattern with the received pattern and also stores either error indices or a 10% sample of the SRAM to memory. (information to be stored is decided by Richard)</li>
	<li>The radiation counts per minute is measured by a Geiger Muller tube (selected by Wei Hao)</li>
</ul>
#### 2.3.1.2 Possible Inferences From Experiment Data
1. The error count of the unshielded microcontroller would tell us the extent of radiation tolerance of the chosen MCU.
2. Comparing the error count of the unshielded microcontroller with the Radiation CPM of the Geiger Tube would allow us to quantify the correlation between SEU and particle radiation in LEO.
3. Comparing error counts of the shielded and unshielded microcontrollers would quantify the effectiveness of the shielding method.


### 2.3.2 Design Specifications 

<table>
  <thead>
    <tr>
      <th>Feature</th>
      <th>Specification</th>
      <th>Reasoning</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Current Consumption</td>
      <td>&lt;100mA</td>
      <td>The central microcontroller (ZSOM) is rated for 500mA, including its own operation. It is reasonable that we should draw &lt;20% of the total current resource.</td>
    </tr>
    <tr>
      <td>Operating Voltage</td>
      <td>3.3V</td>
      <td>The ZSOM supplies power at 3.3V, and has logic voltage of 3.3V as well.</td>
    </tr>
    <tr>
      <td>Duration of Data Transfer</td>
      <td>&lt;12s</td>
      <td>The experiment is to be conducted every minute. Since other tasks need to be done in that time, only &lt;20% of the time should go for data transfers.</td>
    </tr>
    <tr>
      <td>Size of Experiment Payload</td>
      <td>&lt;1088 mm<sup>2</sup> in Area<br>&lt;5 mm in Height</td>
      <td>Derived from payload layout. A very rough sizing check is in Section 3.4, Appendix.</td>
    </tr>
    <tr>
      <td>Minimum Size of Memory to count bit flips</td>
      <td>&gt;1 Kb</td>
      <td>According to <a href="{{site.baseurl}}/references/#6-matthews-m-2021-using-bit-flips-as-a-source-of-randomness-in-cubesat-communication-encryption-acta-astronautica-179-546549-link">[6]</a>, up to 10 upsets can happen over 1kB per day. &lt;1 kB means too little information from the experiment.</td>
    </tr>
    <tr>
      <td>Maximum Size of Memory to count bit flips</td>
      <td>&lt;=2.56 Kb</td>
      <td>Restricted by the data budget of only 256 bytes per microcontroller. A minimum sampling of at least 10% is desired for good data collection.</td>
    </tr>
  </tbody>
</table>


### 2.3.3 Design Choices Reasoning

For each aspect of the experiment, a design choice had to be made, as elaborated below.

#### 2.3.3.1 The Memory Device 

<b>The Ideal Case:</b> Easy to read, Highly susceptible to bit flips, Size of 1 to 2.56 kB, Easy to reset, does not lose data upon power cycle due to SEL .

<img src="{{site.baseurl}}/assets/images/sowmya/img_2.jpg" alt="bit flip measurement area selection" width="700">

Due to the highest number of positives, the SRAM was chosen as the memory device. The one drawback, that is of data loss upon occasional latch-up events, is deemed to be worth the benefit of a simpler reset, which will be needed more often than the latch-up events.

#### 2.3.3.2 ZSOM to Microcontroller Communication

The below table lists the communication peripherals on the ZSOM board and its availability or relevance for this experiment.

<table>
  <thead>
    <tr>
      <th>Communication Interface</th>
      <th>Can it be used for this experiment?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>SPI</td>
      <td>No. SPI of the ZSOM is being used to implement CAN protocol and interface with the OBC, which shouldn’t be interfered with.</td>
    </tr>
    <tr>
      <td>UART</td>
      <td>No. UART is a peer-to-peer protocol. The experiment needs a bus protocol for 2 ATMegas to communicate to the ZSOM.</td>
    </tr>
    <tr>
      <td>I2C</td>
      <td>Yes. It is not being used for any other purpose and is a bus protocol. Also, data transfer speed is sufficient.</td>
    </tr>
  </tbody>
</table>


Due to I2C being the only interface on the ZSOM that is available for use and supports multiple devices, I2C is chosen as the communication interface between the ZSOM and the ATMegas. 

Since it is known that I2C can face problems in the space environment, the experiment incorporates a timeout feature followed by bus reset and/or power cycling to provide robustness to the transfer of data.

Further elaboration on the various issues faced by I2C and our approach towards managing it elaborated on in the Appendix, Section D.2

#### 2.3.3.3. The Microprocessor
<b>The Ideal Case:</b> Has I2C Interface, a readable SRAM, <span style="color: red; text-decoration: underline; font-style: italic;">NO</span> flight heritage, SRAM in 1-2.56 kB size range, high probability of use in future missions 

After applying an initial filter of SRAM sizes, availability of documentation, popularity, and presence of unique features, the following 3 microprocessors were shortlisted for a good demonstration of the reasons for selection.

<img src="{{site.baseurl}}/assets/images/sowmya/img_3.jpg" alt="microcontroller selection" width="700">

Hence, ATMega32U4, having the most positives, is selected as the Microcontroller under experiment.

The appendix further elaborates on 
The reasoning towards not selecting other microcontrollers with USB support (Appendix Section D.3)
Explanation of the flight heritage relevance of the ATMega328P (Appendix Section D.4)
 
#### 2.3.3.4 Other Components

<table>
  <thead>
    <tr>
      <th>Component</th>
      <th>Choice</th>
      <th>Reasons</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Power Source for ATMegas</td>
      <td>3.3V from ZSOM, with SEL protection</td>
      <td>The ZSOM provides protection against latch up events so that the microcontrollers do not suffer permanent damage. ZSOM has a power cycle implementation after latch-up detection.</td>
    </tr>
    <tr>
      <td>Power Cycling Method</td>
      <td>PMOS as a digital switch</td>
      <td>Simple and known implementation. Provides digital control. Can meet the current and voltage specifications.</td>
    </tr>
    <tr>
      <td>Bootloader</td>
      <td>Caterina by Sparkfun</td>
      <td>Supports 3.3V and 8MHz Clock. Supports programming by D+ D- pins. In use by Sparkfun ProMicro.</td>
    </tr>
    <tr>
      <td>Bootloader Upload</td>
      <td>ICSP & Arduino as ISP</td>
      <td>Very common, reliable method.</td>
    </tr>
    <tr>
      <td>Program Upload</td>
      <td>D+ D- USB</td>
      <td>Only 2 additional pins to the ICSP header in the PCB. In use by SparkFun Pro Micro.</td>
    </tr>
  </tbody>
</table>


### 2.3.4 Design Choices Summary
The table below summarizes the final choices made for each component.

<table>
  <thead>
    <tr>
      <th>Requirement</th>
      <th>Component Choice</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Microprocessor Chip For Experiment</td>
      <td>ATMega32U4</td>
    </tr>
    <tr>
      <td>Area to Observe Bit Flips</td>
      <td>SRAM</td>
    </tr>
    <tr>
      <td>ATMega to ZSOM Communication</td>
      <td>I2C Protocol</td>
    </tr>
    <tr>
      <td>Robustness Method</td>
      <td>Bus Reset and Power Cycling</td>
    </tr>
    <tr>
      <td>Bus Reset Implementation</td>
      <td>9 Pulses on SCL after Timeout (the usual I2C method for reset)</td>
    </tr>
    <tr>
      <td>Power Cycling Implementation</td>
      <td>PMOS Switch</td>
    </tr>
    <tr>
      <td>Power Source of ATMegas</td>
      <td>ZSOM SEL protected, 3.3V pin</td>
    </tr>
    <tr>
      <td>Bootloader</td>
      <td>Caterina by SparkFun</td>
    </tr>
    <tr>
      <td>Bootloader Upload Method</td>
      <td>ICSP</td>
    </tr>
    <tr>
      <td>Program Upload Method</td>
      <td>D+ D- Inbuilt USB</td>
    </tr>
    <tr>
      <td>Reference Microcontroller Board</td>
      <td>SparkFun Pro Micro 3.3V, 8MHz</td>
    </tr>
  </tbody>
</table>


## 2.3.5 Final Design of Experiment

The diagram below illustrates the working of the experiment, using the final design choices. As bit flips occur in the ATMega32U4’s, their SRAM Dump will reflect them.

<img src="{{site.baseurl}}/assets/images/sowmya/img_4.jpg" alt="bit flip experiment architecture diagram" width="700">

## 2.4 Prototyping and Testing

### 2.4.1 Prototyping Objectives 

<ul> 
<li>To provide proof of concepts used in the experiment.</li> 
<li>To collect rough estimates of power consumption and data transfer duration.</li> 
<li>To verify repeatability of the experiment.</li> 
</ul>

### 2.4.2 Description of Prototype
The below table describes how each aspect was implemented in the prototype. 

<table>
  <thead>
    <tr>
      <th>Feature</th>
      <th>Implementation in Prototype</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Central Microcontroller</td>
      <td>SparkFun Pro Micro 3.3V, 8MHz</td>
    </tr>
    <tr>
      <td>MCUs under test</td>
      <td>2 x SparkFun Pro Micro 3.3V, 8MHz</td>
    </tr>
    <tr>
      <td>PMOS Switch</td>
      <td>SMD PMOS soldered onto veroboard + wires</td>
    </tr>
    <tr>
      <td>I2C Bus</td>
      <td>On the breadboard + wires</td>
    </tr>
  </tbody>
</table>


Pictures and Specifics of the prototype and some verifications/characterizations are present in Appendix Section D.5

### 2.4.3 Verifications of Proof of Concepts

<table>
  <thead>
    <tr>
      <th>Feature</th>
      <th>Implementation in Prototype</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Central Microcontroller</td>
      <td>SparkFun Pro Micro 3.3V, 8MHz</td>
    </tr>
    <tr>
      <td>MCUs under test</td>
      <td>2 x SparkFun Pro Micro 3.3V, 8MHz</td>
    </tr>
    <tr>
      <td>PMOS Switch</td>
      <td>SMD PMOS soldered onto veroboard + wires</td>
    </tr>
    <tr>
      <td>I2C Bus</td>
      <td>On the breadboard + wires</td>
    </tr>
  </tbody>
</table>

### 2.4.4. Data Gathered Through Testing
<table>
  <thead>
    <tr>
      <th>Verification Attempt</th>
      <th>Outcome</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>ICSP Bootloader Flashing</td>
      <td>Bootloader Flashed successfully</td>
    </tr>
    <tr>
      <td>Code Flash Through D+/D-</td>
      <td>Code Flashed Successfully</td>
    </tr>
    <tr>
      <td>Storing fixed Data in SRAM</td>
      <td>Consistency in the fixed bit pattern observed within the applicable range of memory addresses</td>
    </tr>
    <tr>
      <td>Trigger Based Data Transfer Over I2C</td>
      <td>Data Transfer completed successfully</td>
    </tr>
    <tr>
      <td>Power Cycling Implementation</td>
      <td>Implemented Successfully</td>
    </tr>
    <tr>
      <td>Bus Lockup and Reset Implementation</td>
      <td>Implemented Successfully, Master can detect timeout and reset</td>
    </tr>
    <tr>
      <td>Repeatability</td>
      <td>The implementation shows the same behavior over multiple runs</td>
    </tr>
  </tbody>
</table>

The expected differences in functionality of the prototype and the final PCB implementation are as follows
<ul>
<li>ZSOM current consumption will be different from the SparkFun Pro Micro that is      currently being used as the Master.</li>
<li>The Power consumption of the ATMega32U4 will also differ in PCB due to possible differences in the component models being used.</li>
<li>The breadboard capacitances contribute to the bus capacitance and hence currently, data transfer speed of I2C is lower than would be on a PCB.</li>
</ul>

Despite these differences the testing has provided rough estimates that verifies the feasibility of the experiment. 

## 2.5 Moving Forward

The work achieved thus far is the first deliverable, “Proposal of Radiation-SEU Correlation Experiment”. Additionally, the functionality of concepts and ability to adhere to specifications is verified. 

Moving forward, following are the key milestones or tasks pending. 

<b>Milestone 1:</b> Design of PCB Schematic and Layout of the prototype
Intermediates: 
<ul>
<li>First iteration of the PCB, followed by Testing & Improvements</li>
<li>Second iteration of the PCB, Testing and Characterization</li>
</ul>

<b>Milestone 2:</b> Integration with the other Electronics Member
Intermediate : Testing and Improvements of the Combined PCB

<b>Milestone 3:</b> Integration with Mechanical and Software sections
Intermediate: Combined Testing and Improvements or optimization (if needed)

<b>Final Milestone:</b> Final Checks before deeming the payload flight ready.

For the temporal work plan, kindly refer to the combined table in the “Future Work” section of this report.

