---
title: "Appendix G: Radiation Sensor Detailed Reasoning"
parent: Appendices
nav_order: 7
permalink: /appendix-g/
last_modified_date: 05-04-2025
---

# Radiation Sensor Detailed Reasoning

Ion chamber detectors operate similarly to GM Tubes but at lower voltage levels (USC Environmental Health & Safety, n.d.). This helps to simplify the circuit board design due to the lower clearance needed between the high and low-voltage lines. However, ion chambers are more suited for gamma radiation detection which is not our target radiation source. While some can detect alpha and beta particles, it would especially require a thin window which adds manufacturing constraints to the product. This makes it more expensive and yet more fragile  (Nuclear Power, 2024). 

Solid state detectors can provide readings with high energy resolution, resulting in precise data for analysis later on. It is also generally small and lightweight and requires low voltage (Shah, 2024), allowing for easy integration in circuit design. However, it would require low temperatures for optimum performance to prevent its charge carriers from being excited at room temperature (S.E. International, Inc., 2019). While this would be space-suitable due to the low temperatures in space, it would make it complex to integrate and test before the flight. It is also known to receive radiation damage (Ogasawara et al., 2016) which is highly likely to occur given our mission in the Van Allen Belt which is known for its high levels of radiation (NASA Science Editorial Team, 2024), hence affecting the data it collects. 

These detectors are not chosen although they can operate on low voltage. This is because this benefit has been outweighed by other issues, like their fragility, which is a major point of failure in our mission. The addition of a high voltage circuit is considered simpler compared to their fragility, hence the Gm Tube is chosen for these sensors.
