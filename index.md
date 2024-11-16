---
title: Intro
layout: home
nav_order: 1
---

# ASI-404 Galassia-5 Cubesat Interim Report

## 1.1 Abstract

This project aims to investigate alternative shielding methods for off-the-shelf electronic components to protect them from Single Event Effects (SEEs). To do this, a radiation payload will be built with the end goal of flying it on a flight provider that flies over the South Atlantic Anomaly (SAA) of the Van Allen’s Belt (VAB).

## 1.2 Mission Background

Satellites deployed into space are at constant risk of radiation effects on their electrical components. Previous satellites launched by NUS, Galassia-1, and Galassia-2, faced these issues which caused some inconvenience to the mission. Galassia-1 had a memory card failure whilst Galassia-2 powered on despite being unprompted. The issues were suspected by the Galassia team to be caused by radiation, more specifically SEE.

<div style="display:flex; gap:2em">
  <img src="{{site.baseurl}}/assets/images/intro/img_1.jpg" alt="Galassia-2 housekeeping log 1" width="350">
  <img src="{{site.baseurl}}/assets/images/intro/img_2.jpg" alt="Galassia-2 housekeeping log 2" width="350">
</div>

<div class="fig-label">Fig 1-1 and 1-2. Galassia-2 Housekeeping Logs detailing a sudden unexpected rise in temperature due to the current draw.</div>

## 1.3 Literature Review

### 1.3.1 Radiation Phenomena

There are 3 major radiation phenomena that cause failures in electronics: Total Ionization Dosage (TID), Single Event Effects (SEE), and Displacement Damage (George, 2019). 

<table>
  <tr>
    <th>Radiation Event</th>
    <th>Particles</th>
  </tr>
  <tr>
    <td>Total Ionization Dosage (TID)</td>
    <td>
      <ul>
        <li>Trapped protons and electrons</li>
        <li>Solar protons</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Single Event Effects (SEE)</td>
    <td>
      <ul>
        <li>Trapped and solar protons</li>
        <li>Heavier Ions</li>
        <li>Neutrons</li>
        <li>High energy electrons</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Displacement Damage</td>
    <td>
      <ul>
        <li>Trapped protons and electrons</li>
      </ul>
    </td>
  </tr>
</table>

<div class="fig-label">Table 1-1. Radiation Phenomena and their respective particles</div>

Based on the aforementioned issues faced by Galassia-1 and Galassia-2, we are interested in focusing on SEE to investigate ways to avoid similar issues from occurring in the future.

SEE happens when energetic particles such as solar protons, heavier ions, neutrons, and highly energy electrons in space hit the electronics. They can result in 3 effects, namely: Single Event Upsets (SEU), Single Event Latchup (SEL), and Single Event Burnout (SEB). SEU happens when bits are flipped after a particle hits integrated circuit chips, especially memory storage. SEU happens when particles cause a high current in the circuit or short circuit. SEB happens when the energy from the charged particles damages the semiconductors (LaBel, n.d.).

### 1.3.2 Radiation Protection Features

A method for managing SEE is to design fault-tolerant systems that can continue to operate when a component experiences a fault. However, adding fault management features can increase the development timeline greatly, as each individual potential failure mode must be identified and addressed (Lara et al., 2023). Many smaller developer teams may not be able to afford the delays needed to implement a fully fault-tolerant system.

In most cases of SEE, power cycling can help reset the system and resolve any issues (De Aguiar et al., 2024). However, frequent power cycling, especially when the electronics have a high risk of experiencing SEE, will cause frequent disruptions to their function. This will derail their operations. 

Another way to prevent SEE from occurring is using radiation-hardened components that have a low risk of experiencing SEU. These components are designed, and certified to withstand high levels of radiation, in a process called Radiation Hardened By Design. However, these components are very expensive and their development period is lengthy due to radiation testing (Parris, 2023). 

Alternatively, radiation-tolerant components with flight heritage can be used instead. They can tolerate more radiation doses than normal off-the-shelf parts but less than that of radiation-hardened components. These components are neither tested nor certified in their performance in high-radiation environments, but they have been used on payloads without any known issues. However, they do not guarantee it will not experience SEE (Taylor, 2023).

Shielding is also another common way to physically block radiation particles from damaging electronics. It is used by many space agencies due to its simplicity and effectiveness (NASA. n.d.). 

## 1.4 Problem Statement

Following the literature review,  we realized that current solutions for managing SEE in space electronics are costly and time-consuming, limiting accessibility for CubeSat developers to avoid disruptions by SEE to their missions.

## 1.5 Stakeholders

### 1.5.1 Primary Stakeholders

#### CubeSat Developers

Developers of CubeSats or CubeSats subsystems are the most directly impacted by the high costs associated with environmental protections. Certain teams such as those from universities can often be constrained by budget and timeframe. Hence, our experiment can help them develop their payloads with off-the-shelf parts instead of radiation-tolerant components.

#### Rideshare Providers

By incorporating our payload and experiment onto their CubeSat, we will share our experimental outcomes which can help them in the future development of CubeSats and client payloads.

#### In-Space Missions

In-Space Missions is a subsidiary of BAE Systems that designs, builds and operates satellite missions. They are operating the Faraday Dragon Rideshare Mission.

Our team has a technical partnership with them, making their team available to address some of the technical concerns we may encounter. Additionally, the UK Space Agency is providing funding for our team via In-Space Missions.

### 1.5.2 Secondary Stakeholders

#### Zero-Error Systems (ZES)

ZES is the Singaporean company that designed the ZSOM-M01 board to be used as our primary MCU. By incorporating the ZSOM-M01in our design, we are helping them cultivate more flight heritage for their product.

## 1.6 Design Statement

We aim to design a radiation measurement payload that will allow for the characterization of radiation in the SAA of the VAB to investigate the correlation between radiation and malfunctions in COTS electronic components. We will be using shielding as our radiation protection method and validate shielding as a cheaper method of protection against radiation.

## 1.7 Value Proposition

We aim to design a radiation measurement payload that allows for the characterization of radiation in Low Earth Orbit, to investigate the correlation between radiation and malfunctions in COTS electronics, and to validate our shielding as a cheaper method of protection against radiation.

The data gathered by our payload can be used to develop lower-cost solutions for managing SEE, and the shielding used on our payload can be validated for future flights. These lower-cost solutions can then give other CubeSats developers more freedom in their development cycle.

We will also be able to provide rideshare providers with more insights into the effects of SEE on rideshare satellites and their client payloads.

We aim to fly our payload through the South Atlantic Anomaly, which is known for its high radiation levels (Meier et al., 2023). This will allow us to assess the conduct of our experiment under some of the most challenging radiation conditions


## System Architecture

<br>

<img src="{{site.baseurl}}/assets/images/intro/img_3.png" alt="system architecture diagram" width="700">

<div class="fig-label">Fig 1-3. System Architecture Diagram</div>

This is the system architecture diagram of the payload. 

The onboard computer (OBC) and power supply on the left of the dotted line are part of the parent satellite and are not developed by us.

Wei Hao is working on the radiation detection system, consisting of the HV source, counter electronics, radiation detector, and the ZSOM.

Sowmya will be focusing on the experiments with the 2 ATMega32U4 MCUs and communications between the ATMegas and the ZSOM. 

Richard will be handling the communications and interfacing between the payload and the parent satellite.

Mingchuan will be handling the radiation shielding that covers most of our payload and also the payload configuration.
