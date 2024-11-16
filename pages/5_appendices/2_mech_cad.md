---
title: "Appendix B: Additional Mechanical Information"
parent: More Appendices
nav_order: 2
permalink: /cad/
last_modified_date: 16-11-2024
---

# Additional Mechanical Information

## B1. Materials

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

<div class="fig-label">Table B-1. Materials comparison.</div>

## B2. GM Counter

<img src="{{site.baseurl}}/assets/images/appendix_b/img_1.png" alt="fig b-1" width="400" class="img-center">

<div class="fig-label">Figure B-1. GM Counters.</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_2.png" alt="fig b-2" width="600" class="img-center">

<div class="fig-label">Figure B-2. GM Counter Specs.</div>

Background radiation can fluctuate from 20 to 100 CPM.
[Product Link](https://www.gqelectronicsllc.com/comersus/store/comersus_viewItem.asp?idProduct=5637)

## B3. Radiation Experiment Data

Each reading is 30 minutes.

We first check whether the two counters are calibrated. A total of 7 readings are taken, with both GM Counters left outside.

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

<div class="fig-label">Table B-2. Counter Data.</div>

The counters are calibrated and have very close values.

<img src="{{site.baseurl}}/assets/images/appendix_b/img_3.png" alt="fig b-3" width="600" class="img-center">

<div class="fig-label">Figure B-3. GM Counters and aluminium boxes.</div>

Next we put Counter A inside the box and Counter B outside the box and take the reading. We swap the two counters and take the readings again to average out any errors from their differences. Then we repeat for different thicknesses.

| Raw Data | Counter A | Counter B | | Counter A | Counter B | |
| Thickness | Inside Box (1) | Inside Box (2) | Inside Box (Average) | Outside Box (1) | Outside Box (2) | Outside Box (Average) |
| 0mm | 2598 | 2576 | 2587 | 2613 | 2586 | 2599.5 |
| 2mm | 2480 | 2428 | 2454 | 2496 | 2613 | 2554.5 |
| 4mm | 2247 | 2448 | 2347.5 | 2526 | 2579 | 2552.5 |
| 6mm | 2294 | 2262 | 2278 | 2596 | 2635 | 2615.5 |
| 8mm | 2258 | 2247 | 2252.5 | 2600 | 2548 | 2574 |
| 10mm | 2093 | 2079 | 2086 | 2557 | 2629 | 2593 |

<div class="fig-label">Table B-3. Counter Data in aluminium boxes.</div>

We tabulate the data below.

| Thickness (mm) | Inside Box CPM | Outside Box CPM | Absolute Difference (CPM) | Percentage Drop |
|:--------------:|:--------------:|:---------------:|:------------------------:|:--------------:|
| 0              | 2587           | 2599.5          | 0.42                     | 0.48%          |
| 2              | 2454           | 2554.5          | 3.35                     | 3.93%          |
| 4              | 2347.5         | 2552.5          | 6.83                     | 8.03%          |
| 6              | 2278           | 2615.5          | 11.25                    | 12.90%         |
| 8              | 2252.5         | 2574            | 10.72                    | 12.49%         |
| 10             | 2086           | 2593            | 16.90                    | 19.55%         |

<div class="fig-label">Table B-4. Counter Data Analysis.</div>

Graph is plotted with an error bar. More data has to be collected.

<img src="{{site.baseurl}}/assets/images/appendix_b/img_4.png" alt="fig b-4" width="600" class="img-center">

<div class="fig-label">Figure B-4. Counter Data Analysis.</div>

## B4. CAD Models

<img src="{{site.baseurl}}/assets/images/appendix_b/img_5.png" alt="fig b-5" width="500" class="img-center">

<div class="fig-label">Figure B-5. Top view.</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_6.png" alt="fig b-6" width="500" class="img-center">

<div class="fig-label">Figure B-6. Bottom view.</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_7.png" alt="fig b-7" width="500" class="img-center">

<div class="fig-label">Figure B-7. Side view.</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_8.png" alt="fig b-8" width="500" class="img-center">

<div class="fig-label">Figure B-8. Isometric view.</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_9.png" alt="fig b-9" width="500" class="img-center">

<div class="fig-label">Figure B-9. Isometric (Without Central Shielding).</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_10.png" alt="fig b-10" width="500" class="img-center">

<div class="fig-label">Figure B-10. Inner Side of High Voltage PCB.</div>

<img src="{{site.baseurl}}/assets/images/appendix_b/img_11.png" alt="fig b-11" width="500" class="img-center">

<div class="fig-label">Figure B-11. Inner Side of Low Voltage PCB.</div>

## B5. Dimensions and Specifications

| Item | Dimensions (mm by mm) | Area (mm^2) | Thickness (mm) |
|:-----|:-----------------------|:------------|:---------------|
| PCB Plate | 94.39 x 90.33 | 8526.25 | 2.00 (estimated) |
| PCB Plate (Usable) | 70.75 x 57.79 | 4088.64 | 2.00 (estimated) |
| Z-SOM | 68.00 x 45.00 | 3060.00 | 2.00 (estimated) |
| AT-Mega | 10.00 x 10.00 | 100.00 | 2.00 (estimated) |
| GM Tube | 49.20 x 15.10 | 742.92 | 15.10 |
| HV Converter | 28.00 x 15.00 | 420.00 | 8.000 |
| Side Shielding | 90.33 x 79.26 | 7159.56 | 4.00 |
| Central Shielding | 90.31 x 79.29 | 7160.68 | 4mm thickness, 24mm height |

<div class="fig-label">Table B-5. Dimensions and Specifications.</div>

## B6. Bill of Materials and Mass Budget

| Item | Material | Manufacturing Method | Estimated Mass (g) | Number of Counts | Total Mass (g) |
|:-----|:---------|:----------------------|:-------------------|:-----------------|:--------------:|
| PCB Plate | PCB Plastic | Bought | 30 | 2 | 60 |
| Z-SOM | PCB Plastic | Bought | 20 | 1 | 20 |
| AT-Mega | PCB Plastic | Bought | 5 | 2 | 10 |
| GM Tube | 446 Stainless Steel | Bought | 8.0 | 1 | 8.0 |
| HV Converter | Steel with Zinc Plating | Bought | 50 | 1 | 50 |
| Top/Bottom Shielding | Aluminum 6061 | Laser Cut/CNC | 31.40 | 2 | 62.80 |
| Centre Shielding | Aluminium 6061 | CNC | 89.12 | 1 | 89.12 |

<div class="fig-label">Table B-6. Bill of Materials and Mass Budget.</div>

Total Mass: 299.92 grams