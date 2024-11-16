---
title: Intro
layout: home
nav_order: 1
---

# ASI-404 Galassia-5 Cubesat Interim Report

<br>

{: .warning}
This page is a draft and the content is subject to change.

## Mission Background

Satellites deployed into space are at constant risk of radiation effects on their electrical components. This was an issue faced by previous satellites launched by NUS, Galassia-1 and Galassia-2. Galassia-1 had a memory card failure whilst Galassia-2 powered on despite being unprompted. The issues were suspected to be caused by radiation, more specifically Single Event Effects (SEE).

<div style="display:flex; gap:2em">
  <img src="{{site.baseurl}}/assets/images/intro/img_1.jpg" alt="Galassia-2 housekeeping log 1" width="350">
  <img src="{{site.baseurl}}/assets/images/intro/img_2.jpg" alt="Galassia-2 housekeeping log 2" width="350">
</div>
<p style="font-size:0.875em; text-align: center;">
Galassia-2 Housekeeping Logs detailing a sudden unexpected rise in temperature due to the current draw
</p>

## Literature Review

There are 3 radiation phenomena that cause failures in electronics: Total Ionization Dosage (TID), Single Event Effects (SEE), and Displacement Damage. A table summary of the 3 types of radiation can be found in Appendix X. The cause of failure in Galassia-1 and Galassia-2 was suspected to be SEE. SEE happens when energetic particles such as solar protons, heavier ions, neutrons, and highly energy electrons in space hit the electronics. They can result in 3 effects, namely: Single Event Upsets (SEU), Single Event Latchup (SEL), and Single Event Burnout (SEB).

SEU happens when bits are flipped after a particle hits integrated circuit chips, especially memory storage. SEU happens when particles cause a high current in the circuit or short circuit. SEB happens when the energy from the charged particles damages the semiconductors.

To protect satellite parts and electronics from SEE, current state-of-the-art electronics are radiation-hardened. However, radiation-hardened components are very expensive and take very long to develop. Alternatives to radiation-hardened components are radiation-tolerant components. These are normal electrical components that have been proven to work in space or flown by another user. However, radiation-tolerant components have to be flown to find out their tolerant properties.

Talk about VAB/SAA

Just want to find out the effects of shielding
Rad hard vs rad tolerant vs shielding

While power cycling can reset the system from errors caused by radiation, it may hinder the progress of the payload operation if it is applied too frequently. One way to avoid this is to use radiation-hardened components that have a low risk of experiencing SEU. However, these components are very expensive and their development period is lengthy due to radiation testing. Alternatively, radiation-tolerant components that have been flown before can be used instead. However, the tolerance of a component is not known or tested beforehand, and it has to be flown to be discovered.

## Problem Statement

Expensive and untested tolerance

Current radiation hardening solutions for mitigating SEE in space electronics are costly and time-consuming, limiting accessibility for CubeSat developers.

## Value Proposition

We aim to design a radiation measurement payload that allows for the characterization of radiation in Low Earth Orbits, to investigate the correlation between radiation and malfunctions in COTS electronic components, and to validate shielding as a cheaper method of protection against radiation.

Final product of the project

## Stakeholders

Our team had the opportunity to work with In-Space Missions, a UK space and satellite company and we want were allowedgiven the opportunity to investigate deeper into radiation effects on electrical components on satellites.
+ZES

## System Architecture

<br>
<img src="{{site.baseurl}}/assets/images/intro/img_3.png" alt="system architecture diagram" width="700">

This is the full system we will be designing. 

On the left of the dotted line, there is the onboard computer and power supply, which is external to our payload. 

Wei Hao will be working on the radiation detector system, consisting of the HV source, counter electronics, radiation  detector, and ZSOM

Sowmya will be focusing on her experiments with the 2 ATMega32U4 MCUs and communications with the ZSOM. 

Richard will be handling the communications and connection between the payload and the flight provided via the CAN module.

Finally, Mingchuan will be handling the shielding that covers most of our payload.
