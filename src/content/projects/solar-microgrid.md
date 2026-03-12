---
title: "Off-Grid Solar Microgrid for Rural Electrification"
description: "Designing and simulating a low-cost solar microgrid system for villages with unreliable grid access — from load analysis to battery sizing."
domain: ["Renewables", "Research"]
featured: true
date: "2024-08-01"
status: complete
---

## The Problem

Over 600 million people in sub-Saharan Africa lack reliable electricity access. The grid extension model is slow and expensive. Distributed solar microgrids offer a faster, more resilient path — but the design challenge is real: undersized systems fail users, oversized systems fail economically.

This project explores a first-principles approach to microgrid sizing for a 50-household village cluster.

## Process

### Load profiling first
Before touching a single solar panel spec, I spent time understanding actual usage patterns. Rural households don't behave like urban ones. LED lighting, phone charging, and a shared water pump dominate load — not refrigerators or air conditioning.

I built a probabilistic load model accounting for:
- Seasonal variation in usage
- Coincidence factor (not everyone turns on lights at once)
- Critical vs. non-critical loads

### Sizing the system
Working backward from the load profile:

- **Daily energy demand:** ~18 kWh/day for 50 households
- **Peak load:** ~4.2 kW
- **Solar resource:** 5.2 peak sun hours (location-specific)
- **Autonomy:** 2 days without sun

This yielded a system around **12 kW PV + 40 kWh battery** — significantly smaller (and cheaper) than rule-of-thumb approaches would suggest.

### Simulation and validation
I modeled the full system in MATLAB/Simulink, running a year of synthetic weather data against the load profile to check:
- Loss of load probability (target: <5%)
- Battery state-of-charge distribution
- Inverter sizing adequacy

The simulation flagged that the initial battery sizing was aggressive in the rainy season — I iterated the design accordingly.

## Outcome

A documented sizing methodology that can be adapted for similar contexts. The probabilistic load model alone reduced estimated system cost by ~22% compared to deterministic approaches while maintaining the same reliability target.

**Key insight:** The design problem in rural electrification isn't primarily technical — it's about accurately modeling human behavior under constrained conditions.
