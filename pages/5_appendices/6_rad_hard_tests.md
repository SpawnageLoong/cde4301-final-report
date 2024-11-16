---
title: "Appendix F: Radiation-Hardening Tests for ZSOM-M01"
parent: More Appendices
nav_order: 6
permalink: /rad-hard/
last_modified_date: 16-11-2024
---

# Radiation-Hardening Tests for ZSOM-M01

These are test results provided by Zero Error Systems.

<table>
  <tr>
    <th>Test</th>
    <th>Findings</th>
  </tr>
  <tr>
    <td>Proton Single-Event Effect on ZSOM-M01 (Zero Error Systems, 2024a)</td>
    <td>
      <ul>
        <li>No SEL observed with up to 200MeV proton energy at fluence up to 2.57x10</li>
        <li>SEFI was observed, and a system reset could address the SEFI.</li>
        <li>SEU was observed on the SRAM of the SAMD21 MCU.</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Heavy-Ion Single Event Effect on ZES400-F/S-QFN28SP Quad-Channel Voter (Zero Error Systems, 2022b)</td>
    <td>
      <ul>
        <li>Single-Event Latch‐up (SEL) and Destructive Single Event Effects (DSEE):
          <ul>
            <li>ZES400 is SEL immune up to an LET of 110.1 MeV∙cm2/mg, the highest LET used during SEL testing, at the condition of a maximum power supply of +5V and heated to 125°C.</li>
            <li>There were no destructive events observed during or after the SEL test runs.</li>
          </ul>
        </li>
        <li>Single-Event Transient (SET):
          <ul>
            <li>ZES400 is SET immune up to an LET of 83.3* MeV∙cm2/mg, and a fluence of 107 ions/cm2 at ambient temperature.</li>
          </ul>
        </li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Total Ionizing Dose on ZES400 Quad-Channel Voter (Zero Error Systems, 2023b)</td>
    <td>
      <ul>
        <li>ZES400 remained fully functional up to TID of 300Krad (Si) @ Cobalt-60 source at the condition of a power supply of +5V and ambient temperature.</li>
        <li>The current shift was within 1% during test runs up to 200 Krad (Si)</li>
        <li>The current shift was within 7% during test runs up to 300 Krad (Si)</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Single-Event Effects on ZES100F-QFN32SP Latchup Detection and Protection (LDAP) (Zero Error Systems, 2022a)</td>
    <td>
      <ul>
        <li>Single-Event Latch‐up (SEL) and Destructive Single Event Effects (DSEE):
          <ul>
            <li>ZES100F-QFN32SP is SEL immune up to a LET of 2/mg, the highest LET used during SEL testing, at the condition of a maximum power supply of +5V and heated to 125°C.</li>
            <li>There were no destructive events observed during or after the SEL test runs.</li>
          </ul>
        </li>
        <li>Single Event Upset (SEU) and Single Event Transient (SET):
          <ul>
            <li>ZES100F-QFN32SP LET used during SEL testing, at room temperature.</li>
          </ul>
        </li>
        <li>ZES100F-QFN32SP Functionality o 2 /mg, the highest
          <ul>
            <li>When a Commercial-Off-the-Shelf (COTS) device is irradiated, ZES100F-QFN32SP exhibits an immediate response to every SEL experienced by the COTS device.</li>
          </ul>
        </li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>Total Ionizing Dose on ZES100F-QFN32SP Latchup Detection and Protection (LDAP) (Zero Error Systems, 2023a)</td>
    <td>
      <ul>
        <li>Shows SEE error-free up to Linear Energy Transfer (LET) of 2/mg</li>
        <li>3 samples of ZES100F-QFN32SP are tested up to 300Krad at the dose rate of ~13.88rad(Si)/s, and another 3 samples of ZES100F-QFN32SP are tested up to 50Krad at the dose rate of ~2.3rad(Si)/s. All 6 samples remain functional and pass the tests.</li>
      </ul>
    </td>
  </tr>
</table>

It is observed from the testing that the ZSOM-M01 is resistant to damage from high levels of radiation. In addition to this, its various protection systems are immune from lasting damage, especially for the Quad-Channel Voter in for SEL and LDAP with SEE. This means that even if the microcontroller experiences SEE events from the high-energy particles in the Van Allen Belt, it can be reset reliably to remove the error. 

