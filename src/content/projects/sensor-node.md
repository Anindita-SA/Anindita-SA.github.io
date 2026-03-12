---
title: "Modular Sensor Node for Environmental Monitoring"
description: "A low-power wireless sensor node built from scratch — PCB design, firmware, and enclosure — to log temperature, humidity, and particulate matter."
domain: ["Electronics", "Product Design"]
featured: true
date: "2024-11-01"
status: active
---

## The Itch

I kept wanting to understand microenvironments — how air quality changes across a room, how temperature gradients form. Commercial sensors are either too expensive to deploy in multiples or locked to proprietary ecosystems.

So I built one.

## Hardware Design

The design constraints were clear from the start:
- **Battery life:** Weeks, not hours. This ruled out WiFi and pushed me toward BLE.
- **Cost:** Under ₹800 per node fully assembled.
- **Form factor:** Small enough to place unobtrusively.

### Sensor selection
After testing several options:
- **BME280** for temperature/humidity/pressure (excellent accuracy, I²C)
- **PMS5003** for PM2.5/PM10 (laser particle counter — this one pulls significant current)
- **Custom PCB** designed in KiCad with an ESP32-C3 as the main controller

The PMS5003 was the tricky one — it consumes 100mA active, which destroys battery life. The solution: power it via a MOSFET gate, spin it up only for 30 seconds per reading cycle, then cut power. Dropped average current from ~110mA to ~4mA.

## Firmware

Written in C++ using the ESP-IDF framework (not Arduino — the sleep modes are more controllable). Key decisions:

- Deep sleep between readings (5-minute intervals)
- BLE advertisement burst to transmit data (no persistent connection)
- Readings stored in RTC memory across sleep cycles as a rolling buffer

## Enclosure

First iteration was a 3D-printed box — functional but rough. The second iteration integrated the PCB mounting points directly into the enclosure design in Fusion 360, with snap-fit assembly and a diffuser window for the particulate sensor.

## What I Learned

The gap between "it works on a breadboard" and "it works reliably as a product" is mostly about power management and mechanical robustness. Neither shows up in tutorials.

The design thinking lens was genuinely useful here: treating the enclosure and firmware as part of the same user experience problem (not as afterthoughts to the electronics) changed the order in which I made decisions.
