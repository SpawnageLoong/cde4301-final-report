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

# 3. The Bit Flip Experiment

## 3.1 Objectives, Scope of Work & Deliverables

<b>Objective:</b> The design and implementation of the Radiation-SEU Correlation experiment.

<b>Final Deliverables:</b>
<ul>
  <li>Design of the experiment</li>
  <li>A space-grade implementation of the design</li>
  <li>Integration with the rest of the payload</li>
</ul>

## 3.2 Problem Context and Value Proposition

### 3.2.1 Problem Context

Bits that represent either data or programs are stored in computer memory as charge. Ionized particle radiation can alter this charge and cause bit flips that corrupt data. This is called Single Event Upsets (Baraniuk, 2022). Without sufficient data on SEU, it is hard to create solutions that safeguard the processors in space.

### 3.2.2 Identification of Research Gap

The image below depicts the current state of data and experiments on bit flips. Further details on the experiments pertaining to microcontrollers can be found in [Appendix C.1]({{site.baseurl}}/appendix-c/#appendix-c1-details-on-bit-flip-experiments-on-microcontrollers-in-leo).  But the diagram below highlights the gap.

<img src="{{site.baseurl}}/assets/images/sowmya/Fig 3.1.png" alt="Existing State of Research on Bit Flips" width="600" class="img-center">

<p align="center"><strong>Fig 3-1 Existing State of Research on Bit Flips</strong></p> 
<p align="center">Reference Keys: [1,2] (Seidleck, 2002) [3] (Noeldeke, 2021) [4] (Poivey)  [5] (Coronetti, 2024)  [6] (Brian D. Sierawski) [7] (Olsen, W.) [8] (Wang, 2022)</p>

While there are many studies on larger SRAM sizes, there is a <i>Lack of data on Microcontroller Bit Flips in LEO in comparison with Radiation Counts.</i>

### 3.2.3 Value Proposition

CubeSats, which are becoming increasingly popular, extensively use microcontrollers and operate in LEO. While data about larger SRAMs can provide developers with a rough idea of what to expect, it cannot be confidently applied to microcontrollers. Hence, this experiment bridges the gap by collecting microcontroller bit flip data in LEO to benefit CubeSat developers and carrier services. 

## 3.3 Design Overview

### 3.3.1 Concept of Experiment

Two microcontrollers of the exact kind will be placed in the payload, with only one of them shielded (according to Mingchuan’s section). Their SRAM data will be periodically requested every minute by the payload’s central processor. Their error counts are then computed and stored, along with a 10 percent sample of the SRAM.

On Earth, this error count can be compared with the radiation counts from the on-board GM Tube (from Weihao’s section) in order to derive a correlation between counts of certain types of radiation and bit flips. In addition, we can also compare the error counts in order to understand the effectiveness of the shielding method. As a collateral, we also understand the radiation tolerance of the microcontroller under test.

For a more detailed/specific explanation of the concept and possible inferences please refer to [Appendix C.2]({{site.baseurl}}/appendix-c/#appendix-c2-detailed-concept-of-experiment--possible-inferences).

### 3.3.2 Design Specifications

The design was constrained by the following specifications.

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
      <td>Current Consumption</td>
      <td>&lt;100mA</td>
      <td>The central microcontroller (ZSOM) is rated for 500mA, including its own operation. It is reasonable that the experiment should draw &lt;20% of the total current resource.</td>
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
      <td>
        &lt;4088 mm² in Area, but can be double sided.<br>
        &lt;20mm height on inner side<br>
        &lt;3mm height on outer side
      </td>
      <td>Derived from payload dimensions, shielding presence and layout. Data present in [Appendix E.11]({{site.baseurl}}/appendix-e/#appendix-e11-usable-area-of-pcb-and-size-of-components)</td>
    </tr>
    <tr>
      <td>Minimum Size of Memory to count bit flips</td>
      <td>&gt; 1 Kb</td>
      <td>According to (Matthews, M., 2021) up to 10 upsets can happen over 1kB per day. &lt;1 kB means too little information from the experiment.</td>
    </tr>
    <tr>
      <td>Maximum Size of Memory to count bit flips</td>
      <td>&le;2.56Kb</td>
      <td>Restricted by the data budget of only 256 bytes per microcontroller. A minimum sampling of at least 10% is desired for good data collection.</td>
    </tr>
  </tbody>
</table>

<p align="center"><strong>Table 3-2  Design Specifications Table</strong></p>

### 3.3.3 Design Choices Summary

<table border="1" align="center" cellpadding="6" cellspacing="0">
  <thead>
    <tr>
      <th>Requirement</th>
      <th>Component Choice</th>
      <th>Reasons</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Microprocessor Chip For Experiment</strong></td>
      <td>ATMega32U4</td>
      <td>- Has SRAM of suitable size and has I2C.<br>- Likely to be used in future space applications due to built-in USB support.</td>
    </tr>
    <tr>
      <td><strong>Area to Observe Bit Flips</strong></td>
      <td>SRAM</td>
      <td>- Very high susceptibility to bit flips.<br>- Easy to read and reset.</td>
    </tr>
    <tr>
      <td><strong>ATMega to ZSOM Communication</strong></td>
      <td>I2C Protocol</td>
      <td>- Supports multiple devices connected to the same bus.<br>- The only such available-to-use interface on ZSOM.</td>
    </tr>
    <tr>
      <td><strong>I2C Robustness Method</strong></td>
      <td>Bus Reset and Power Cycling</td>
      <td>-Bus reset makes the slave release the SCL line, which is often the reason for lock-ups<br>-Power cycling resets the ATMega32u4, if the error is due to other reasons</td>
    </tr>
    <tr>
      <td>Bus Reset Implementation</td>
      <td>9 Pulses on SCL after Timeout</td>
      <td>-Standard method for lock-ups caused by SCL pulled low is to toggle 8-16 times (Nguyen, D.)</td>
    </tr>
    <tr>
      <td>Power Cycling Implementation</td>
      <td>PMOS Switch x 2</td>
      <td>-Pulls up completely to 3.3V<br>-Low static power consumption<br>-Separate PMOS for each ATMega32U4 to support graceful degradation if needed</td>
    </tr>
    <tr>
      <td>Power Source of ATMegas</td>
      <td>ZSOM SEL protected 3.3V line</td>
      <td>-Provides latch-up protection to ATMega32u4s<br>-Supplies more than sufficient current</td>
    </tr>
    <tr>
      <td>Bootloader</td>
      <td>Caterina by SparkFun</td>
      <td>-Supports 8MHz 3.3V operation and D+D- programming<br>-In use by Sparkfun Pro Micro boards</td>
    </tr>
    <tr>
      <td>Bootloader Upload Method</td>
      <td>ICSP using avrdude</td>
      <td>-Popular and reliable method</td>
    </tr>
    <tr>
      <td>Program Upload Method</td>
      <td>D+ D- Inbuilt USB</td>
      <td>-Suggested method for ATMega32u4 & Caterina bootloader</td>
    </tr>
    <tr>
      <td>Reference Microcontroller Board</td>
      <td>SparkFun Pro Micro 3.3V, 8MHz</td>
      <td>-Uses the same chip, frequency and voltage as requirements<br>-Trusted source</td>
    </tr>
  </tbody>
</table>


<p align="center"><strong>Table 3-3  Design Choices Summary Table</strong></p>

The above table only summarizes the final choices. Detailed reasons for the selections consisting of comparison tables of alternative solutions and addressing I2C related concerns were covered in the Interim and are also present in the Appendix [Section C.3]({{site.baseurl}}/appendix-c/#appendix-c3-detailed-evaluation-and-selection-of-potential-solutions) and [C.4]({{site.baseurl}}/appendix-c/#appendix-c4-addressing-i2c-related-concerns) respectively.

### 3.3.4 Design Overview Diagram

The below diagram represents the architecture of the experiment.

<img src="{{site.baseurl}}/assets/images/sowmya/Fig3.4.png" alt="Design Overview" width="600" class="img-center">

<p align="center"><strong>Fig 3-4 Design Overview</strong></p>

## 3.4 Design Details

### 3.4.1 Schematic Entry for PCB

Link to download and view the schematic is available at [Link]({{site.baseurl}}/assets/files/sowmya/FYP_Schematic_PDF.pdf).

Link to download and view the board is available at [Link]({{site.baseurl}}/assets/files/sowmya/FYP_Board_PDF.pdf).

<b>ATMega32U4 and supporting circuitry</b>
<ul>
  <li>
    Circuit was fully referenced based on the SparkFun Pro Micro Schematic 
    <a href="https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/Pro_Micro_v13b.pdf" target="_blank">Link</a>.
  </li>
  <li>
    Only the load capacitor for the crystal oscillator was changed to suit the selected oscillator, which is about <strong>18pF</strong> according to the datasheet.
  </li>
  <li>
    Since the microcontroller is running only at <strong>8MHz</strong>, there is a decent margin to alter the crystal oscillator load capacitances.
  </li>
  <li>
    This circuit was verified by Prototype #2 (PCB)
  </li>
</ul>

<b>I2C connections</b>
<ul>
  <li>Standard bus configuration with pull-up was used.</li>
  <li>The 3.3V on the ZSOM (without latch-up) protection supplies the pull-up since it needs to be a permanent pull-up.</li>
  <li>Pull-up resistors were chosen to be 4.7k ohms, which is popular in microcontroller-based I2C design.</li>
  <li>This circuit was verified by Prototype #1 (Table-Top)</li>
</ul>

<b>CAN Transceiver module</b>
<ul>
  <li>The CAN module essentially converts SPI of ZSOM-M01 to CAN signals.</li>
  <li>Design was referenced based on a SPI to CAN breakout board we tested with 
    <a href="https://github.com/yasir-shahzad/MCP2515-CAN-Bus-Module" target="_blank">Link</a>.
  </li>
  <li>However, it was adapted to work at 3.3V by changing TJA1050 to TCAN334RD.</li>
  <li>The oscillator and corresponding capacitors were altered as well to be the same as that for ATMega32u4 circuitry.</li>
</ul>


<b>Power Cycling circuit</b>
<ul>
  <li>A simple PMOS switch was implemented.</li>
  <li>Decision to leave out the usually present BJT was based on trial and error, which showed that current consumption and sensitivity to resistance (hence temperature) values is greater in the case of BJTs.</li>
  <li>Each ATMega32u4 is controlled by a separate PMOS switch for graceful degradation. This is done in case the unshielded chip gets severely damaged and corrupts the bus. With a separate PMOS, we can disable the noisy chip and at least collect data from the shielded ATMega32u4.</li>
</ul>

<b>PCB Traces</b>
<ul>
  <li>The CAN lines, which are a differential pair, were routed with symmetry and consistent spacing as much as possible, as advised by 
    <a href="https://resources.altium.com/p/identifying-minimum-trace-spacing-and-trace-requirements-altium" target="_blank">Altium Resource</a>.
  </li>
  <li>For the I2C lines, the guideline of spacing to be at least 3 times the width of the lines, according to the above article, has been followed.</li>
  <li>There is a polygon pour ground plane across the PCB to reduce noise.</li>
  <li>On the conservative side, 0.254mm traces were used for signal routing and 0.4064mm traces were used for 3V3 and 5V lines. This was done by using the PC104 or Pico Blade specification of maximum 1A per pin as a clear upper limit. This complies with the recommendations in 
    <a href="https://resources.altium.com/p/pcb-trace-width-vs-current-table-high-voltage-design" target="_blank">Altium Resource</a>.
  </li>
</ul>

### 3.4.2 Chip Programming

**Programming Steps**

- The Caterina bootloader was flashed onto the chip through ICSP using a SparkFun Pro Micro as the ISP. The tool used for this was avrdude.
- The Low fuse was ensured to be 0xFF to be able to use an external oscillator.
- After this, the application program was flashed onto the chips using ArduinoIDE via the D+ D- pins over a USB connection.

The code used for the ATMega32U4s (slaves) and ZSOM’s (master) I2C can be found in [Appendix C.5]({{site.baseurl}}/appendix-c/#appendix-c5-code).

### 3.4.3  Current Budget Table

In the table below, a conservative estimate of total current draw by the experiment setup was done by considering operation currents for the key chips involved in the design. 

<img src="{{site.baseurl}}/assets/images/sowmya/Table3.7.jpg" alt="Current Budget Table" width="600" class="img-center">

<p align="center"><strong>Table 3-5 Current Budget Table</strong></p>

Apart from this, other components would also draw some power, so we can round up this estimate to 50mA. To estimate a rough power requirement, we can take 5V as the operating voltage to obtain,
<i>Power Consumption Estimate = 0.25W</i>

### 3.4.4  Bill Of Materials & Temperature Tolerance Table

<table border="1" cellpadding="6" cellspacing="0">
  <thead>
    <tr>
      <th>S. No</th>
      <th>Component Name</th>
      <th>Temperature Range (C)</th>
      <th>Material / Description</th>
      <th>Item No with Link</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Crystal Oscillator</td>
      <td>-40 to 85</td>
      <td>Hermetically Sealed with Glass</td>
      <td><a href="https://www.digikey.sg/en/products/detail/abracon-llc/abm3-8-000mhz-d2y-t/2344570">ABM3-8.000MHz-D2Y</a></td>
    </tr>
    <tr>
      <td>2</td>
      <td>18pF Capacitor</td>
      <td>-55 to 125</td>
      <td>Cu, Ni, Sn, C0G</td>
      <td><a href="https://www.digikey.sg/en/products/detail/murata-electronics/GJM1555C1H180GB01D/2592861">GJM1555C1H180GB01</a></td>
    </tr>
    <tr>
      <td>3</td>
      <td>1uF Capacitor</td>
      <td>-55 to 125</td>
      <td>Cu, Ni, Sn, X7R</td>
      <td><a href="https://www.digikey.sg/en/products/detail/samsung-electro-mechanics/CL10B105KP8NNNC/3887604">CL10B105KP8NNNC</a></td>
    </tr>
    <tr>
      <td>4</td>
      <td>0.1uF Capacitor</td>
      <td>-55 to 85</td>
      <td>Cu, Ni, Sn, X7R</td>
      <td><a href="https://www.digikey.sg/en/products/detail/samsung-electro-mechanics/CL05B104KP5NNNC/3886660">CL05B104KP5NNNC</a></td>
    </tr>
    <tr>
      <td>5</td>
      <td>10uF Capacitor</td>
      <td>-55 to 125</td>
      <td>Cu, Ni, Sn, X7R</td>
      <td><a href="https://www.digikey.sg/en/products/detail/murata-electronics/GRM21BR61C106KE15K/2546903">GRM21BR61C106KE15K</a></td>
    </tr>
    <tr>
      <td>6</td>
      <td>10kohm Resistor</td>
      <td>-55 to 155</td>
      <td>Thick Film Resistor</td>
      <td><a href="https://www.digikey.sg/en/products/detail/yageo/RC0402FR-7W10KL/12698939?gclsrc=aw.ds&&utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_SG_High%20Performing%20Products&utm_term=&productid=12698939&utm_content=&utm_id=go_cmp-20033881620_adg-_ad-__dev-c_ext-_prd-12698939_sig-Cj0KCQiA_Yq-BhC9ARIsAA6fbAhjXYGEtARH7SEDKarvOE7_E8vZ1rUBdSqSknkpwbnmGOBOJB7lysAaAjOqEALw_wcB&gad_source=1&gclid=Cj0KCQiA_Yq-BhC9ARIsAA6fbAhjXYGEtARH7SEDKarvOE7_E8vZ1rUBdSqSknkpwbnmGOBOJB7lysAaAjOqEALw_wcB&gclsrc=aw.ds">RC0402FR-7W10KL</a></td>
    </tr>
    <tr>
      <td>7</td>
      <td>4.7kohm Resistor</td>
      <td>-55 to 155</td>
      <td>Thick Film Resistor</td>
      <td><a href="https://www.digikey.sg/en/products/detail/yageo/RC0402JR-074K7L/726477?s=N4IgTCBcDaIEoGEAMAWJYBScC0SDsKA0ngDIgC6AvkA">RC0402JR-074K7L</a></td>
    </tr>
    <tr>
      <td>8</td>
      <td>120ohm Resistor</td>
      <td>-55 to 155</td>
      <td>Thick Film Resistor</td>
      <td><a href="https://www.digikey.sg/en/products/detail/yageo/RC1206FR-07120RL/728523">RC1206FR-07120RL</a></td>
    </tr>
    <tr>
      <td>9</td>
      <td>22ohm Resistor</td>
      <td>-55 to 155</td>
      <td>Thick Film Resistor</td>
      <td><a href="https://www.digikey.sg/en/products/detail/panasonic-electronic-components/ERJ-2RKF22R0X/1746157">ERJ-2RKF22R0X</a></td>
    </tr>
    <tr>
      <td>10</td>
      <td>ATMega32U4</td>
      <td>-40 to 85</td>
      <td>COTS chip</td>
      <td><a href="https://www.digikey.sg/en/products/detail/microchip-technology/ATMEGA32U4-AU/1914602">ATMEGA32U4-AU</a></td>
    </tr>
    <tr>
      <td>11</td>
      <td>PMOS AO3401A</td>
      <td>-55 to 150</td>
      <td>COTS PMOS</td>
      <td><a href="https://www.digikey.sg/en/products/detail/alpha-omega-semiconductor-inc/AO3401A/1855773?s=N4IgTCBcDaIOwA4CsBaAjABg29KByAIiALoC%2BQA">AO3401A</a></td>
    </tr>
    <tr>
      <td>12</td>
      <td>MCP2515</td>
      <td>-40 to 125</td>
      <td>COTS chip</td>
      <td><a href="https://www.digikey.sg/en/products/detail/microchip-technology/MCP2515-E-SO/593677">MCP2515-E/SO</a></td>
    </tr>
    <tr>
      <td>13</td>
      <td>TCAN334DR</td>
      <td>-40 to 125</td>
      <td>COTS chip</td>
      <td><a href="https://www.digikey.sg/en/products/detail/texas-instruments/tcan334dr/5957538">TCAN334DR</a></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Picoblade Connectors</td>
      <td>-40 to 105</td>
      <td>Widely used in Cubesats</td>
      <td><a href="https://www.digikey.sg/en/products/detail/molex/0532610671/699111?gclsrc=aw.ds&&utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_SG_High%20Performing%20Products&utm_term=&productid=699111&utm_content=&utm_id=go_cmp-20033881620_adg-_ad-__dev-c_ext-_prd-699111_sig-Cj0KCQiAqL28BhCrARIsACYJvkf7GUZazcxuxNbLwb0N9wuzDb4NqYdvvgoZghfUw35MEU_r65xGS7UaAgvnEALw_wcB&gad_source=1&gclid=Cj0KCQiAqL28BhCrARIsACYJvkf7GUZazcxuxNbLwb0N9wuzDb4NqYdvvgoZghfUw35MEU_r65xGS7UaAgvnEALw_wcB&gclsrc=aw.ds">532610671</a></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Picoblade Wire</td>
      <td>-40 to 105</td>
      <td>Widely used in Cubesats</td>
      <td><a href="https://sg.element14.com/molex/15134-0600/cable-assy-6pos-rcpt-rcpt-50mm/dp/2913937">15134-0600</a></td>
    </tr>
  </tbody>
</table>

<p align="center"><strong>Table 3-6 Bill of Materials & Temperature Tolerance Tables </strong></p>

Overall, 
<ul>
  <li>All the components meet the (-30, 70) degrees C range needed for Qualification.</li>
  <li>The materials involved are acceptable because this payload is for a Cubesat, which often uses COTS components.</li>
  <li>There is space heritage for the thick film resistors, X7R/C0G capacitors, and Picoblade connectors in Galassia-1 and Galassia-2.</li>
</ul>


## 3.4 Prototyping Overview

Images of prototyping iterations and final product can be found in [Appendix C.6]({{site.baseurl}}/appendix-c/#appendix-c6-prototyping-photos).

### 3.4.1 Prototype 1
<b>Description:</b> Table top Setup to Test Functionality

<b>Objectives:</b> 
<ul>
  <li>To obtain realistic values for current consumptions, data transfer time</li>
  <li>To verify bootloader and code flashing, SRAM dumps, I2C setup, Power Cycle & Bus Reset Implementation, and Repeatability</li>
</ul>
<b>Approach:</b>
The below table describes how each aspect was implemented in the prototype. 

<table border="1">
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

<p align="center"><strong>Table 3-7 Table Top Setup </strong></p>

<b>Outcome </b>
<ul>
  <li>All the functionality was verified and possible.</li>
  <li>Overall Current Consumption was 33mA (within specification &lt;100mA).</li>
  <li>Overall time for 1 run of experiment was 10.3 seconds (within specification &lt;12s).</li>
</ul>



### 3.4.2 Prototype 2
<b>Description:</b> A functional PCB implementation, but without CAN, only 1 PMOS, and dimensionally inaccurate

<b>Objectives:</b> To have a functional PCB and identify any fundamental issues in operation 

<b>Approach:</b> Since the purpose was only to test functionality on PCB, a rough dimension PCB of 10x10cm was made. 

<b>Outcome:</b> 
<ul>
  <li>The PCB was fully functional in terms of desired features.</li>
  <li>Current Draw was in the range of 0.028 to 0.031 mA.</li>
  <li>Overall Time for one run of the experiment was 10s.</li>
</ul>

<b>Actionables: </b>
<ul>
  <li>Realization that it is better to have 2 PMOS so that only the faulty one can be disabled.</li>
  <li>Realization that all components need to have a wide enough temperature range with sufficient margin.</li>
</ul>


### 3.4.3 Prototype 3
<b>Description:</b> A functionally and dimensionally accurate PCB Implementation with CAN, 2 PMOS and dimensionally accurate

<b>Objectives:</b> To test if integration with Central Code (Richard), HV PCB (Weihao) and Mechanical (MingChuan) was possible and functional.

<b>Approach:</b> The PCB was resized, CAN was added, a second PMOS was added. After this we checked mechanical fit with the shielding manufactured, as well as overall integrated functionality.

<b>Outcome:</b> 
<ul>
  <li>The whole payload could be integrated and function as one with all desired functionality.</li>
  <li>Realization that the temperature range of the oscillator does not provide enough margin.</li>
</ul>

<b>Actionables: </b>
For the final product, the only change made was to select an oscillator with as wide a margin as possible to be on the safer side, since I2C needs an accurate clock that shouldn’t be affected too much by extreme temperatures.

## 3.5   Final Product Testing & Results and Evaluation

### 3.5.1 Basic Tests & Evaluation

The below table lists the basic verifications carried out on the experiment PCB.

<table border="1">
  <thead>
    <tr>
      <th>Test For</th>
      <th>Method</th>
      <th>Outcomes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Intact Connections and No Shorts</td>
      <td>Multimeter on Continuity Mode</td>
      <td>All necessary connections were connected to each other. All non-connections remained disconnected. So, the board was electrically functional in the same way as the design.</td>
    </tr>
    <tr>
      <td>Functionality of the PCB and Code</td>
      <td>Different variations of SRAM bit pattern were stored into the ATMega32u4s and SRAM dumps were examined. Bus lock-up was simulated (Error cases elaborated in [Appendix C.4.2]({{site.baseurl}}/appendix-c/#c42-error-case-vs-code-element-that-handles-it)) and Bus Reset and Power Cycling was carried out.</td>
      <td>The chips on the PCB were able to be reprogrammed with different codes. They always gave the correct SRAM dump output. Bus lock-up detection, Bus Reset and Power Cycling were all successful. So, the PCB design has all the desired functionality.</td>
    </tr>
    <tr>
      <td>Time for Transfer</td>
      <td>After integration, a test run was carried out to see if the system can complete all necessary operations every minute.</td>
      <td>The integrated system had sufficient time to complete all necessary operations per minute. So the experiment setup occupied an acceptable amount of time.</td>
    </tr>
    <tr>
      <td>Current Draw Limit</td>
      <td>Power draw was tested using Lab Bench Supply</td>
      <td>The maximum current draw ever observed for the experiment PCB is 32 mA. The current usually varies in the range 26mA - 32 mA. The voltage supplied was at 4.997V. Hence the total current draw is <100mA and meets the constraint. </td>
    </tr>
  </tbody>
</table>

<p align="center"><strong>Table 3-8 Basic Tests and Evaluation </strong></p>

### 3.5.2 Space Related Tests & Evaluation

In order to test the functionality of the product and understand aspects of its endurance in space and also during launch, we carried out the following tests at ST Engineering’s Jalan Boon Lay Facility.

<b>Thermal Cycle Test:</b> A 16 hour long test, comprising 2 thermal cycles. Each cycle consisted of 4 hours at -30 C, followed by 4 hours at 70 C. To simulate the temperature fluctuation in space.


<b>Switch-on Test:</b> Tested for both -30 C and 70 C. For this test, the payload was kept at the first extreme temperature, -30 C for an hour, after which it was switched on and operated at -30 C for another hour. The same was done for 70 C


<b>Vibration Test:</b> A sine and random vibration test was carried out to understand its mechanical durability (further elaborated in Mingchuan’s Section).


The below table explains the testing goals, method and outcomes for the final product.
<table border="1">
  <thead>
    <tr>
      <th>Test For</th>
      <th>Method</th>
      <th>Outcome & Inference</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Repeatability and Endurance</td>
      <td>The payload was kept running continuously for 16 hours.</td>
      <td>The experiment setup can endure at least 960 continuous SRAM reads. So, it is beyond suitable to carry out the 60 continuous reads needed during the experiment.</td>
    </tr>
    <tr>
      <td>Correctness of Data Transfer Across Temperature Extremes</td>
      <td>The payload was subjected to the 16 hour thermal cycle test mentioned above.</td>
      <td>The plot of error count versus temperature shows that the SRAM data is correctly transferred for long periods of time, and under harsh temperatures (-30 to 70 C). This indicates that the experiment setup is robust to the temperature variation it will experience in space during operation.</td>
    </tr>
    <tr>
      <td>Ability to Switch on at Temperature Extremes</td>
      <td>The payload was subjected to the Switch on Test, described above.</td>
      <td>The payload was able to switch on and operate at the temperature extremes of -30 and +70 C. This means the experiment start-up is robust to the temperature variation it will experience in space.</td>
    </tr>
    <tr>
      <td>Mechanical Strength</td>
      <td>The payload was subjected to the vibration testing described above.</td>
      <td>The payload was operational after being subjected to these tests, and also visually appeared to be intact. This implies that the solder joints in the design are of sufficient strength and further reinforcement is not required for vibrations of the tested frequencies - which are the expected frequencies during launch.</td>
    </tr>
  </tbody>
</table>

<p align="center"><strong>Table 3-9 Space Related Tests and Evaluation </strong></p>

The below image shows that the error counts for both SRAMS are consistently zero over the entire range of temperature variation. Hence, the product is reliable under these conditions.

Please note that the Error counts from both SRAMs are the same hence only the pink line shows in the graph. 

<img src="{{site.baseurl}}/assets/images/sowmya/Graph3.10.jpg" alt="Error Counts vs Temperature" width="600" class="img-center">

<p align="center"><strong>Graph 3-10 Graph for Error Counts vs Temperature Variance </strong></p>


## 3.6 Future Recommendations

### 3.6.1 Steps Towards Launch
<ul>
  <li>Proceed to Proto-flight test and ensure everything operates properly.</li>
  <li>Find a launch partner and coordinate the interfacing between PCB pinout and their satellite.</li>
</ul>

### 3.6.2 Future Design Recommendations

<ul>
  <li>If more area is available, or in a second version of this mission, use different MCUs and derive a correlation between similar families of MCUs when it comes to radiation tolerance.</li>
  <li>If a higher data budget is available on OBC, take full SRAM samples at a lower rate to understand the exact spatial correlation of errors.</li>
</ul>

## 3.7 Conclusion

The Radiation-SEU Correlation experiment has been fully designed and implemented, including a space-grade version integrated with the rest of the payload. Extensive testing has verified its functionality under some harsh space and launch conditions.

During the payload’s spaceflight, the experiment will provide data on bit flips in microcontrollers relative to radiation counts, along with insights into the impact of the shielding under test. 

This data will help CubeSat developers better understand and address the effects of space radiation on microcontrollers in Low Earth Orbit, significantly aiding future projects by providing a foundation for evaluating cost-effective and simpler solutions for managing Single Event Upsets.
