---
title: "Appendix E: Analysis of Memory Storage Options"
parent: More Appendices
nav_order: 5
permalink: /memory/
last_modified_date: 16-11-2024
---

# Analysis of Memory Storage Options

| Memory Type | Pros | Cons |
| :---------- | :--- | :--- |
| Flash | - Provides additional storage capacity<br>- Flexibility in additional capacity | - Needs additional components<br>- Known to suffer from corruption due to SEE |
| SRAM | - EDAC protection from corruption<br>- Help maximise FRAM by storing raw data while parity bits stored in FRAM | - Memory wiped after power cycling |
| FRAM | - Radiation hardened<br>- EDAC protection from corruption<br>- TMR protection from corruption | - Limited amount of space |

<div class="fig-label">Table E-1. Comparison of memory types</div>

Flash storage can help store massive amounts of data. However, flash memory is external to the microcontroller, hence it is not radiation-hardened. It is also known to get corrupted by radiation. This is because radiation removes electrons from the floating gate in flash memory, causing unwanted bitflips (Kay et al., 2017). Hence using flash memory may derail the mission due to the high risk of data corruption. Even if Error and Detection code (EDAC) can help correct data corruption, the code may not be robust enough to handle multiple types of corruption events (Hansen et al., n.d.). Therefore flash memory should be avoided to prevent this potential point of failure.

SRAM is the next viable storage option. However, the data in SRAM gets wiped out if power cycling happens (Awati & Sheldon, 2024). Since there is a high chance that other non-radiation-hardened components experience latchups, the frequency of power cycling may be high. Hence, there would be little to no progress in the mission as the collected data get wiped frequently To avoid this, the SRAM should not be used.