---
title: "Appendix E"
parent: Appendices
nav_order: 5
permalink: /appendix-e/
last_modified_date: 05-04-2025
---

## Appendix E1: Iteration Designs

Details for previous iterations and material comparison can be found in the [Interim Report](https://spawnageloong.github.io/cde4301-docs/ming-chuan/).

**First Iteration**: All components on the same side of PCB, covered by 1 shield.
**Problems**: Not enough space for all components.

<img src="{{site.baseurl}}/assets/images/appendix_e/E1-1.png" alt="Iteration 1" width="600" class="img-center">

<div class="fig-label">Fig E1-1. First Iteration</div>

**Second Iteration**: Shielded and unshielded components on opposite sides of the same PCB.
**Problems**: Close proximity of high and low voltage components.

<img src="{{site.baseurl}}/assets/images/appendix_e/E1-2.png" alt="Iteration 2" width="600" class="img-center">

<div class="fig-label">Fig E1-2. Second Iteration</div>

**Third Iteration**: PCBs for high and low voltage components. Shielded components on the inside of middle shielding.
**Problem**: Thin structures (on the outside of pin stacks) which were vulnerable to vibrations and stress.

<img src="{{site.baseurl}}/assets/images/appendix_e/E1-3.png" alt="Iteration 3" width="600" class="img-center">

<div class="fig-label">Fig E1-3. Third Iteration</div>

**Final Iteration**: Optimised design from 3rd iteration.

<img src="{{site.baseurl}}/assets/images/appendix_e/E1-4.png" alt="Final Iteration" width="600" class="img-center">

## Appendix E2: CAD Models

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-1.png" alt="CAD Model Top View" width="600" class="img-center">

<div class="fig-label">Fig E2-1. Top View</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-2.png" alt="CAD Model Bottom View" width="600" class="img-center">

<div class="fig-label">Fig E2-2. Bottom View</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-3.png" alt="CAD Model Side View" width="600" class="img-center">

<div class="fig-label">Fig E2-3. Side View</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-4.png" alt="CAD Model Isometric View" width="600" class="img-center">

<div class="fig-label">Fig E2-4. Isometric View</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-5.png" alt="CAD Model Isometric without Central Shielding" width="600" class="img-center">

<div class="fig-label">Fig E2-5. Isometric View without Central Shielding</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-6.png" alt="Inner Side of High Voltage PCB" width="600" class="img-center">

<div class="fig-label">Fig E2-6. Inner Side of High Voltage PCB</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E2-7.png" alt="Inner Side of Low Voltage PCB" width="600" class="img-center">

<div class="fig-label">Fig E2-7. Inner Side of Low Voltage PCB</div>

## Appendix E3: Material Choice Summary

Details of the materials can be found in the [Interim Report](https://spawnageloong.github.io/cde4301-docs/ming-chuan/).

<table>
  <tr>
    <th>Material</th>
    <th>Pros</th>
    <th>Cons</th>
  </tr>
  <tr>
    <td>PEEK</td>
    <td>
      <ul>
        <li>Very available</li>
        <li>Light compared to metals at 1.32g/cm^3  (Curbell plastics, n.d.)</li>
        <li>Radiation Resistant (Ensinger, n.d.)</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Does not have strong shielding properties without high Z materials added as composite. (Khozemy et al., 2022)</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>PEEK infused with heavy atoms</td>
    <td>
      <ul>
        <li>Strong shielding properties. (Khozemy et al., 2022)</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Unavailable and expensive. (Khozemy et al., 2022)</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Aluminium 6061</td>
    <td>
      <ul>
        <li>Very available</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Only shields alpha and beta particles. (IMS Team, n.d.)</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Concrete</td>
    <td>
      <ul>
        <li>Strong shielding properties. (IMS Team, n.d.) (Onaizi et al, 2024)</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Heavy and brittle (Onaizi et al, 2024)</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Lead</td>
    <td>
      <ul>
        <li>Strong shielding properties. (IMS Team, n.d.)</li>
      </ul>
    </td>
    <td>
      <ul>
        <li>Environmental unfriendly (Sampson, n.d.)</li>
        <li>Heavy</li>
      </ul>
    </td>
  </tr>
</table>

<div class="fig-label">Table E3-1. Material Comparison</div>

## Appendix E4: Radiation Experiment Data

<img src="{{site.baseurl}}/assets/images/appendix_e/E4-1.png" alt="Radiation Experiment Data" width="600" class="img-center">

<div class="fig-label">Fig E4-1. GM Counters</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E4-2.png" alt="GM Tube Specs" width="600" class="img-center">

<div class="fig-label">Fig E4-2. GM Tube Specs</div>

Background radiation can fluctuate from 20 to 100 CPM. ([Link](https://www.gqelectronicsllc.com/comersus/store/comersus_viewItem.asp?idProduct=5637))

Each reading is 30 minutes. We first check whether the two counters are calibrated. A total of 7 readings are taken, with both GM Counters left outside.

| No. |  Counter A  |  Counter B  |
|:----|:------------|:------------|
| 1   | 2598        | 2613        |
| 2   | 2612        | 2542        |
| 3   | 2586        | 2576        |
| 4   | 2624        | 2710        |
| 5   | 2655        | 2453        |
| 6   | 2587        | 2573        |
| 7   | 2534        | 2474        |
| Avg | 2599.43     | 2563.00     |
| CPM | 86.64761905 | 85.43333333 |

<div class="fig-label">Table E4-1. GM Counter Readings</div>

The counters are calibrated and have very close values.

<img src="{{site.baseurl}}/assets/images/appendix_e/E4-3.png" alt="GM Counters and aluminium boxes" width="600" class="img-center">

<div class="fig-label">Fig E4-3. GM Counters and Aluminium Boxes</div>

Next we put Counter A inside the box and Counter B outside the box and take the reading. We swap the two counters and take the readings again to average out any errors from their differences. Then we repeat for different thicknesses.

| Raw Data | Counter A | Counter B | | Counter A | Counter B | |
| Thickness | Inside Box (1) | Inside Box (2) | Inside Box (Average) | Outside Box (1) | Outside Box (2) | Outside Box (Average) |
| 0mm | 2598 | 2576 | 2587 | 2613 | 2586 | 2599.5 |
| 2mm | 2480 | 2428 | 2454 | 2496 | 2613 | 2554.5 |
| 4mm | 2247 | 2448 | 2347.5 | 2526 | 2579 | 2552.5 |
| 6mm | 2294 | 2262 | 2278 | 2596 | 2635 | 2615.5 |
| 8mm | 2258 | 2247 | 2252.5 | 2600 | 2548 | 2574 |
| 10mm | 2093 | 2079 | 2086 | 2557 | 2629 | 2593 |

<div class="fig-label">Table E4-2. Counter Data</div>

We collect more data.

| Raw Data | Counter A | Counter B | | Counter A | Counter B | |
| Thickness | Inside Box (1) | Inside Box (2) | Inside Box (Average) | Outside Box (1) | Outside Box (2) | Outside Box (Average) |
| 0mm | 2547 | 2554 | 2550.5 | 2534 | 2572 | 2553 |
| 2mm | 2467 | 2429 | 2448 | 2578 | 2497 | 2537.5 |
| 4mm | 2389 | 2401 | 2395 | 2562 | 2554 | 2558 |
| 6mm | 2212 | 2365 | 2288.5 | 2510 | 2520 | 2515 |
| 8mm | 2176 | 2260 | 2218 | 2496 | 2495 | 2495.5 |
| 10mm | 2116 | 2230 | 2173 | 2470 | 2396 | 2433 |

<div class="fig-label">Table E4-3. Counter Data</div>

We tabulate the data below.

| Thickness (mm) | Inside Box | CPM | Outside Box | CPM | Absolute Difference (CPM) | Percentage Drop |
|:--------------:|:----------:|:---:|:-----------:|:---:|:------------------------:|:--------------:|
| 0              | 2573.7     | 85.79 | 2576.3      | 85.88 | 0.09                     | 0.10%          |
| 2              | 2458.3     | 81.94 | 2546.0      | 84.87 | 2.92                     | 3.44%          |
| 4              | 2361.3     | 78.71 | 2555.3      | 85.18 | 6.46                     | 7.59%          |
| 6              | 2256.0     | 75.20 | 2565.3      | 85.51 | 10.31                    | 12.06%         |
| 8              | 2227.0     | 74.23 | 2534.8      | 84.49 | 10.26                    | 12.14%         |
| 10             | 2129.5     | 70.98 | 2513.0      | 83.77 | 12.78                    | 15.26%         |

<div class="fig-label">Table E4-4. Counter Data Analysis</div>

Graph is plotted. It plateaus after 6mm.

<img src="{{site.baseurl}}/assets/images/appendix_e/E4-4.png" alt="Counter Data Analysis" width="600" class="img-center">

<div class="fig-label">Fig E4-4. Counter Data Analysis</div>

## Appendix E5: Bill of Materials and Mass Budget

| Item | Material | Manufacturing Method | Mass (g) | Number of Counts | Total Mass (g) |
|:-----|:---------|:----------------------|:---------|:-----------------|:--------------:|
| Top Shielding | Aluminum 6061 | CNC | 47.5 | 1 | 47.5 |
| Bottom Shielding | Aluminum 6061 | CNC | 54.5 | 1 | 54.5 |
| Middle Shielding | Aluminum 6061 | CNC | 138.0 | 1 | 138.0 |
| HV PCB (Soldered) | FR4 | Bought | 56.0 | 1 | 56.0 |
| LV PCB (Soldered) | FR4 | Bought | 60.0 | 1 | 60.0 |
| Bolts | Stainless Steel | Bought | 3.0 | 4 | 12.0 |
| Spacer | Stainless Steel | Bought | 0.5 | 10 | 5.0 |
| Pin Stacks | Plastic and Copper | Bought | 6.5 | 2 | 13.0 |
| Thermal Interface Material | Thermal Interface Material | Bought | - | - | - |
| **Total** | | | | | **386.0** |

<div class="fig-label">Table E5-1. Bill of Materials</div>

The precision of the scale was 0.5 grams. The mass of the full module is 388.5g.

<img src="{{site.baseurl}}/assets/images/appendix_e/E5-1.png" alt="Weighing" width="600" class="img-center">

<div class="fig-label">Fig E5-1. Weighing</div>

## Appendix E6: Physical Parameters

Height: 48.0mm
Length and Breadth: 96.39mm by 94.33mm

<div style="display:flex; gap:2em">
  <img src="{{site.baseurl}}/assets/images/appendix_e/E6-1.png" alt="Physical Parameters" width="350">
  <img src="{{site.baseurl}}/assets/images/appendix_e/E6-2.png" alt="Physical Parameters" width="350">
</div>

<div class="fig-label">Fig E6-1 and E6-2. Physical Parameters</div>

Centre of Gravity:
X = 43.39mm
Y = 48.03mm
Z = -14.22mm

<div style="display:flex; gap:2em">
  <img src="{{site.baseurl}}/assets/images/appendix_e/E6-3.png" alt="Centre of Gravity" width="350">
  <img src="{{site.baseurl}}/assets/images/appendix_e/E6-4.png" alt="Centre of Gravity" width="350">
</div>

<div class="fig-label">Fig E6-3 and E6-4. Centre of Gravity</div>

Moment of Inertia (at CG):

| Lxx = 387471.00	| Lxy = 15000.87	| Lxz = 16132.16 |
| Lyx = 15000.87	| Lyy = 397053.44	| Lyz = 23131.01 |
| Lzx = 16132.16	| Lzy = 23131.01	| Lzz = 648808.59 |

<div class="fig-label">Table E6-1. Moment of Inertia</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E6-5.png" alt="Moment of Inertia" width="600" class="img-center">

<div class="fig-label">Fig E6-5. Moment of Inertia</div>

## Appendix E7: Jig Drawing

<img src="{{site.baseurl}}/assets/images/appendix_e/E7-1.png" alt="Jig CAD" width="600" class="img-center">

<div class="fig-label">Fig E7-1. Jig CAD</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E7-2.png" alt="Jig Drawing" width="600" class="img-center">

<div class="fig-label">Fig E7-2. Jig Drawing</div>

Note: There was some mistake by the manufacturer. In this drawing, the central hole is missing and the M3 holes were mirrored. The mistakes were subsequently fixed.

## Appendix E8: Test Profiles

Test profiles are taken from [SpaceX](https://www.spacex.com/media/falcon-users-guide-2021-09.pdf).

### Sine Profile: (1.25x MPE)

#### Axial

<img src="{{site.baseurl}}/assets/images/appendix_e/E8-1.png" alt="Sine Profile Axial" width="600" class="img-center">

<div class="fig-label">Fig E8-1. Sine Profile Axial</div>

- Frequency range: 5 Hz to 100 Hz.
- Acceleration levels:
  - 5Hz: ±0.5g * 1.25 = ±0.625g.
  - 20Hz: ±0.8g * 1.25 = ±1.00g
  - Peaks at ±0.9g * 1.25 = ±1.125g at 100 Hz.

| No. | Description | Time |
|:----|:-----------|:-----|
| 1   | Start at 5Hz and 0.625g amplitude | - |
| 2   | Increase frequency from 5Hz to 20Hz at a rate of 2 oct/min, increase amplitude linearly from 0.625g to 1.00g at 20Hz | 60 seconds |
| 3   | Increase frequency from 20Hz to 35Hz at a rate of 2 oct/min, amplitude remain at 1.00g | About 24.2 seconds |
| 4   | At the end of step 3, drop amplitude to 0.75g | - |
| 5   | Increase frequency from 35Hz to 75Hz at a rate of 2 oct/min, amplitude remain at 0.75g | About 33.0 seconds |
| 6   | Increase frequency from 75Hz to 85Hz at a rate of 2 oct/min, increase amplitude linearly from 0.75g to 1.125g at 85Hz | About 5.41 seconds |
| 7   | Increase frequency from 85Hz to 100Hz at a rate of 4 oct/min, amplitude remain at 1.125g | About 7.02 seconds |
| 8   | Repeat steps 1 to 7 one more time | About 130 seconds |
| 9   | End | - |

<div class="fig-label">Table E8-1. Sine Profile Axial</div>

Total: about 260 seconds

#### Lateral

<img src="{{site.baseurl}}/assets/images/appendix_e/E8-2.png" alt="Sine Profile Lateral" width="600" class="img-center">

<div class="fig-label">Fig E8-2. Sine Profile Lateral</div>

- Frequency range: 5 Hz to 100 Hz
- Acceleration levels:
  - Constant ±0.5 * 1.25 = 0.625g between 5 Hz and 85 Hz.
  - Peaks at ±0.6 * 1.25 = 0.75g at 100 Hz.

| No. | Description | Time |
|:----|:-----------|:-----|
| 1   | Start at 5Hz and 0.625g amplitude | - |
| 2   | Increase frequency from 5Hz to 85Hz at a rate of 2 oct/min, amplitude remain at 0.625g | About 120.6 seconds |
| 3   | Increase frequency from 85Hz to 100Hz at a rate of 2 oct/min, increase amplitude linearly from 0.625g to 0.75g at 85Hz | About 7.04 seconds |
| 4   | Repeat steps 1 to 3 one more time | About 130 seconds |
| 5   | Repeat steps 1 to 4 for the other lateral axis | About 260 seconds |
| 6   | End | - |

<div class="fig-label">Table E8-2. Sine Profile Lateral</div>

Total: about 520 seconds

### Random

<img src="{{site.baseurl}}/assets/images/appendix_e/E8-3.png" alt="Random Profile" width="600" class="img-center">

<div class="fig-label">Fig E8-3. Random Profile</div>

All axes: Require +6dB (using Falcon)

<img src="{{site.baseurl}}/assets/images/appendix_e/E8-4.png" alt="Random Profile" width="600" class="img-center">

<div class="fig-label">Fig E8-4. Random Profile</div>

| No. | Description | Time |
|:----|:-----------|:-----|
| 1   | Vibrate from 20Hz to 100Hz with constant 0.0264 g^2/Hz | 20s |
| 2   | Increase vibration from 100Hz with 0.0264 g^2/Hz to 300Hz with 0.04 g^2/Hz | 20s |
| 3   | Vibrate from 300Hz to 700Hz with constant 0.04 g^2/Hz | 20s |
| 4   | Increase vibration from 700Hz with 0.04 g^2/Hz to 800Hz with 0.12 g^2/Hz | 20s |
| 5   | Vibrate from 800Hz to 925Hz with constant 0.12 g^2/Hz | 20s |
| 6   | Decrease vibration from 925Hz with 0.12 g^2/Hz to 2000Hz with 0.03864 g^2/Hz | 20s |
| 7   | Repeat steps 1 to 6 two more times | 240s |
| 8   | Repeat steps 1 to 7 for the other two axes. | 720s |
| 9   | End | - |

<div class="fig-label">Table E8-3. Random Profile</div>

Total: about 1080 seconds

### Thermal Cycling

| No. | Description | Specification |
|:----|:-----------|:-------------|
| 1   | Starting Temp | Room Temperature (assume 20°C) |
| 2   | High Peak Temperature | 70°C |
| 3   | Low Peak Temperature | -25 and -30°C |
| 4   | Dwell Time* | 4 hours |
| 5   | Ramp Cycles | 10°C/minute |
| 6   | Cycles | 2 |

<div class="fig-label">Table E8-4. Thermal Cycling</div>

| No. | Description | Time |
|:----|:-----------|:-----|
| 1   | Room temperature (20°C) decrease to low peak temperature (-25°C) | 4.5 minutes |
| 2   | Dwell at low peak temperature | 4 hours |
| 3   | Low peak temperature (-25°C) increase to high peak temperature (70°C) | 9.5 minutes |
| 4   | Dwell at high peak temperature | 4 hours |
| 5   | High peak temperature (70°C) decrease to low peak temperature (-30°C) | 10 minutes |
| 6   | Dwell at low peak temperature | 4 hours |
| 7   | Low peak temperature (-30°C) increase to high peak temperature (70°C) | 10 minutes |
| 8   | Dwell at high peak temperature | 4 hours |
| 9   | High peak temperature (70°C) decrease to room temperature (20°C) | 5 minutes |
| -   | Total time | 16 hours 39 minutes |

<div class="fig-label">Table E8-5. Thermal Cycling</div>

### Over Testing Procedures

| No. | Test | Time |
|:----|:-----|:-----|
| 1   | First Sine | About 15 minutes |
| 2   | First Random | About 20 minutes |
| 3   | Thermal | About 16 hours 41 minutes |
| 4   | Second Sine | About 15 minutes |
| 5   | Second Random | About 20 minutes |

<div class="fig-label">Table E8-6. Over Testing Procedures</div>

Total: about 2 days

## Appendix E9: Simulations

### Static

Required Profile:

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-1.png" alt="Static Profile" width="600" class="img-center">

<div class="fig-label">Fig E9-1. Static Profile</div>

Axial: 1.25 * 8.5g

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-2.png" alt="Static Profile Axial" width="600" class="img-center">

<div class="fig-label">Fig E9-2. Static Profile Axial</div>

Lateral: 1.25 * 3g

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-3.png" alt="Static Profile Lateral" width="600" class="img-center">

<div class="fig-label">Fig E9-3. Static Profile Lateral</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-4.png" alt="Static Profile Lateral" width="600" class="img-center">

<div class="fig-label">Fig E9-4. Static Profile Lateral</div>

### Sine Frequency

Find the resonance frequency

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-5.png" alt="Sine Frequency" width="600" class="img-center">

<div class="fig-label">Fig E9-5. Sine Frequency</div>

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-6.png" alt="Sine Frequency" width="600" class="img-center">

<div class="fig-label">Fig E9-6. Sine Frequency</div>

### Thermal

Check for overheating

<img src="{{site.baseurl}}/assets/images/appendix_e/E9-7.png" alt="Thermal Simulation" width="600" class="img-center">

<div class="fig-label">Fig E9-7. Thermal Simulation</div>

## Appendix E10: Test Results

Vibration results before thermal cycle: [Link]({{site.baseurl}}/assets/files/appendix_e/1_vibration_before_thermal.zip)

Thermal cycle data: [Link]({{site.baseurl}}/assets/files/appendix_e/2_thermal_data.zip)

Vibration results after thermal cycle: [Link]({{site.baseurl}}/assets/files/appendix_e/3_vibration_after_thermal.zip)

## Appendix E11: Usable area of PCB and Size of Components

| Item | Dimensions (mm by mm) | Area (mm^2) | Usable Height (mm) |
|:-----|:----------------------|:-------------|:--------------------|
| PCB | 94.39 x 90.33 | 8526.25 | - |
| Usable PCB Plate (Inner Side) | 70.75 x 57.79 | 4088.64 | 20mm |
| Usable PCB Plate (Outer Side) | 70.75 x 57.79 | 4088.64 | 3mm |
| Pin Stack | 2.5 x 2.5 | 6.25 | 3mm |

<div class="fig-label">Table E11-1. PCB Size</div>

| Item | Dimensions (mm by mm) | Area (mm^2) | Height (mm) |
|:-----|:----------------------|:-------------|:--------------------|
| Z-SOM | 68.00 x 45.00 | 3060.00 | 3.00 |
| AT-Mega | 10.00 x 10.00 | 100.00 | 2.00 |
| GM Tube | 49.20 x 15.10 | 742.92 | 15.10 |
| HV Converter | 28.00 x 15.00 | 420.00 | 8.00 |

<div class="fig-label">Table E11-2. Component Size</div>
