---
title: "1 kHz Quadrature Oscillator (Sine/Cosine Generator)"
description: "An analog state-variable oscillator synthesizing simultaneous 1 kHz sine and cosine waveforms with 90° quadrature phase - from differential equations to LTSpice modeling and KiCad PCB prototyping."
domain: ["Electronics", "Research"]
featured: true
date: "2025-10-15"
thumbnail: "/projects/quadrature-oscillator/thumbnail.png"
status: Active
draft: false
---

<div class="grid grid-cols-1 md:grid-cols-2 gap-8 items-center my-6 p-6 border border-[var(--border)] bg-[var(--bg-surface)] transition-all">
<div class="space-y-3">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mb-1">Analog Systems & Circuit Synthesis</div>
<h2 class="font-display text-2xl font-bold tracking-tight text-[var(--text-primary)] !mt-0 !mb-2">The Concept & Motivation</h2>
<p class="leading-relaxed opacity-90 text-sm md:text-base">
Quadrature signal generation, producing simultaneous sine and cosine waves locked in exact 90° phase displacement, is a fundamental requirement across communications and control engineering. It powers lock-in amplifiers, motor resolvers, vector modulators, and IQ demodulation systems.
</p>
<p class="leading-relaxed opacity-90 text-sm md:text-base">
While modern digital signal processors can generate sine/cosine pairs via look-up tables and dual DACs, discrete analog state-variable oscillators synthesize pure continuous-time harmonic motion directly from differential equations without quantization noise or clock jitter.
</p>
<p class="font-semibold text-[var(--amber)] text-sm md:text-base">
This project designs, simulates in LTSpice, and prototypes a 1 kHz state-variable quadrature oscillator in KiCad, investigating loop stability, amplitude-limiting non-linearities, and physical board constraints.
</p>
</div>
<div class="flex items-center justify-center">
<div class="w-full max-w-[320px] md:max-w-[340px] photo-card-amber rounded cursor-pointer">
<img src="/projects/quadrature-oscillator/pcb-3d.png" alt="3D CAD render of the 1 kHz Quadrature Oscillator PCB" class="w-full h-auto object-contain rounded" draggable="false" oncontextmenu="return false;" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono flex items-center justify-center gap-1.5 font-medium">
⚡ 3D KiCad PCB render for the state-variable oscillator board
</div>
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">Mathematical Architecture & Loop Dynamics</h2>
</div>

<div class="space-y-6 my-6">
<div class="space-y-3">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">First Principles</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">State-Variable Integrator Topology</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The circuit implements a continuous-time analog solution to a pair of coupled first-order differential equations:
</p>

<div class="p-4 my-3 rounded border border-[var(--border)] bg-[var(--bg)] text-center font-mono text-xs md:text-sm tracking-wide text-[var(--text-primary)] shadow-sm space-y-1">
<div>d(sine) / dt = ω · cosine</div>
<div>d(cosine) / dt = -ω · sine</div>
</div>

<p class="text-sm md:text-base leading-relaxed opacity-90">
By cascading two active op-amp integrators in a closed feedback loop:
</p>
<ul class="space-y-2 text-sm md:text-base">
<li><strong>First Stage (Integrator 1):</strong> Integrates the cosine input to yield a -90° phase-shifted sine wave.</li>
<li><strong>Second Stage (Integrator 2):</strong> Integrates the sine wave with an inverted polarity feedback loop, providing the additional 90° shift and negative sign required to close the loop.</li>
<li><strong>Barkhausen Criterion:</strong> The total loop phase shift equals 360° (0°) with a unity loop gain (|Aβ| = 1) at the target frequency, sustaining continuous oscillation without external clocks.</li>
</ul>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-stretch my-6">
<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] flex flex-col justify-between h-full">
<div>
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mb-3">Target vs Measured Parameters</div>
<div class="overflow-x-auto">
<table class="w-full text-xs md:text-sm font-mono text-left border-collapse">
<thead>
<tr class="border-b border-[var(--border)] bg-[var(--bg)]">
<th class="py-2 px-3">Parameter</th>
<th class="py-2 px-3">Theoretical</th>
<th class="py-2 px-3">Measured / Sim</th>
</tr>
</thead>
<tbody class="opacity-90 divide-y divide-[var(--border)]">
<tr class="hover:bg-[var(--bg)]">
<td class="py-2 px-3 font-semibold">Oscillation Frequency</td>
<td class="py-2 px-3">995 Hz</td>
<td class="py-2 px-3 text-[var(--amber)] font-bold">1.01 kHz (±1.5%)</td>
</tr>
<tr class="hover:bg-[var(--bg)]">
<td class="py-2 px-3 font-semibold">Phase Displacement</td>
<td class="py-2 px-3">90.0°</td>
<td class="py-2 px-3">83° to 85°</td>
</tr>
<tr class="hover:bg-[var(--bg)]">
<td class="py-2 px-3 font-semibold">Peak Amplitude</td>
<td class="py-2 px-3">2.37 V</td>
<td class="py-2 px-3">~2.40 V</td>
</tr>
<tr class="hover:bg-[var(--bg)]">
<td class="py-2 px-3 font-semibold">Supply Rails</td>
<td class="py-2 px-3">±15 V DC</td>
<td class="py-2 px-3">±15 V DC</td>
</tr>
</tbody>
</table>
</div>
</div>
</div>

<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] flex flex-col justify-between h-full space-y-3">
<div>
<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold mb-3">Component Calculations</div>
<div class="text-xs md:text-sm font-mono space-y-3 opacity-90">
<div>
<div class="font-semibold text-[var(--text-primary)]">Frequency:</div>
<div class="text-[var(--royal)]">f = 1 / (2πRC) = 1 / (2π · 1.6kΩ · 100nF) ≈ 995 Hz</div>
</div>
<div>
<div class="font-semibold text-[var(--text-primary)]">Bias Threshold:</div>
<div class="text-[var(--royal)]">V_bias = 15V · (1kΩ / 9kΩ) = 1.67 V</div>
</div>
<div>
<div class="font-semibold text-[var(--text-primary)]">Peak Voltage:</div>
<div class="text-[var(--royal)]">V_peak = V_bias + V_diode = 1.67V + 0.70V = 2.37 V</div>
</div>
</div>
</div>
<div class="pt-3 border-t border-[var(--border)] font-mono text-xs text-[var(--amber)] opacity-90">
<strong>Limiter Topology:</strong> Dual anti-parallel 1N4148 diodes for soft amplitude regulation without hard rail saturation.
</div>
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">Simulation & Waveform Diagnostics</h2>
</div>

<div class="grid grid-cols-1 lg:grid-cols-2 gap-8 items-stretch my-6">
<div class="flex flex-col justify-between space-y-4 h-full">
<div class="photo-card-royal rounded cursor-pointer">
<img src="/projects/quadrature-oscillator/transient-startup.png" alt="LTSpice transient startup envelope simulation" class="w-full h-auto object-contain rounded" draggable="false" oncontextmenu="return false;" />
<div class="text-xs text-center text-[var(--royal)] mt-2 font-mono font-medium">LTSpice transient analysis: Startup envelope growth into steady-state limiting</div>
</div>
<div class="bg-[var(--bg-surface)] p-4 border-l-4 border-[var(--royal)] border border-[var(--border)] text-xs md:text-sm leading-relaxed">
<strong>Startup Dynamics:</strong> Initial circuit noise initiates regenerative exponential envelope buildup until the 1N4148 diode network clamps effective gain to unity, preventing rail saturation.
</div>
</div>

<div class="flex flex-col justify-between space-y-4 h-full">
<div class="photo-card-crimson rounded cursor-pointer">
<img src="/projects/quadrature-oscillator/lissajous-phase.png" alt="X-Y Lissajous phase pattern showing quadrature relationship" class="w-full h-auto object-contain rounded" draggable="false" oncontextmenu="return false;" />
<div class="text-xs text-center text-[var(--crimson)] mt-2 font-mono font-medium">X-Y Lissajous plot: Circular trajectory validating near-quadrature phase lock</div>
</div>
<div class="bg-[var(--bg-surface)] p-4 border-l-4 border-[var(--crimson)] border border-[var(--border)] text-xs md:text-sm leading-relaxed">
<strong>Phase Alignment:</strong> Plotting Channel 1 (Cosine) against Channel 2 (Sine) on X-Y mode yields an open circular/elliptical orbit, verifying consistent quadrature phase separation.
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">PCB Prototyping & Physical Implementation</h2>
</div>

<div class="grid grid-cols-1 lg:grid-cols-2 gap-8 items-center my-6">
<div class="space-y-4">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">KiCad Implementation</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">Hardware Layout & Routing</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The schematic was transferred into KiCad to produce a dedicated 2-layer evaluation board centered around dual LM358 operational amplifier packages.
</p>
<ul class="space-y-2.5 text-sm md:text-base">
<li><strong>Component Placement:</strong> Symmetrical integrator placement with short feedback loops around the timing capacitors (C1, C2) to minimize parasitic loop inductance.</li>
<li><strong>Decoupling & Power Rails:</strong> 100 nF ceramic bypass capacitors placed adjacent to IC power supply pins to suppress switching transients.</li>
<li><strong>Test Points:</strong> Dedicated BNC / pin headers for simultaneous dual-channel oscilloscope probing of sine and cosine outputs.</li>
</ul>
</div>

<div class="space-y-4">
<div class="photo-card-amber rounded cursor-pointer">
<img src="/projects/quadrature-oscillator/schematic.png" alt="Complete KiCad circuit schematic of the 1 kHz Quadrature Oscillator" class="w-full h-auto object-contain rounded" draggable="false" oncontextmenu="return false;" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono font-medium">Complete KiCad circuit schematic with dual integrator stages and diode limiter</div>
</div>
</div>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold mt-10 mb-1">Engineering Diagnosis</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-4">Version 1 Failure Analysis & Honest Gaps</h2>

<p class="text-sm md:text-base leading-relaxed opacity-90 mb-4">
Building and testing Version 1 highlighted practical component-level bottlenecks that separate ideal circuit theory from physical hardware:
</p>

<div class="overflow-x-auto my-6">
<table class="w-full text-xs md:text-sm font-body border border-[var(--border)] bg-[var(--bg-surface)] min-w-[650px]">
<thead class="bg-[var(--bg)] font-mono text-xs uppercase border-b border-[var(--border)]">
<tr>
<th class="p-3.5 text-left text-[var(--crimson)] w-1/3">Observed Behavior in v1</th>
<th class="p-3.5 text-left text-[var(--amber)] w-1/3">Underlying Root Cause</th>
<th class="p-3.5 text-left text-[var(--royal)] w-1/3">v2 Architectural Fix</th>
</tr>
</thead>
<tbody class="divide-y divide-[var(--border)] opacity-90">
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">Phase displacement measured at 83° to 85° instead of 90.0°</td>
<td class="p-3.5 leading-relaxed">LM358 finite gain-bandwidth product (1 MHz) and modest slew rate (0.5 V/μs) introduce excess phase lag in the integration loop.</td>
<td class="p-3.5 leading-relaxed">Upgrade to high-speed JFET-input dual op-amps (TL072 or OPA2134) offering 3 MHz+ GBW and 20 V/μs slew rate for exact 90.0° orthogonality.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">Slight crossover distortion on raw waveforms</td>
<td class="p-3.5 leading-relaxed">LM358 Class-AB output stage exhibits slight zero-crossing distortion when driving capacitive or low-impedance feedback loads.</td>
<td class="p-3.5 leading-relaxed">Modern audio-grade op-amps with rail-to-rail or push-pull output buffers eliminate zero-crossing dead zones.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">Harmonic distortion from hard diode clipping</td>
<td class="p-3.5 leading-relaxed">Passive 1N4148 diodes create soft-clipping flattening at peak voltages, generating small odd harmonic overtones.</td>
<td class="p-3.5 leading-relaxed">Replace passive diode limiting with an active JFET-based automatic gain control (AGC) loop for &lt;0.1% total harmonic distortion (THD).</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">PCB ground-return cross-talk</td>
<td class="p-3.5 leading-relaxed">Fragmented ground routing in v1 layout created shared impedance between the first and second integrator stages.</td>
<td class="p-3.5 leading-relaxed">Redesign with a solid unbroken bottom ground plane and isolated analog star grounding for timing capacitors.</td>
</tr>
</tbody>
</table>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mt-10 mb-1">Roadmap</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-4">Version 2 Planned Improvements</h2>

<div class="grid grid-cols-1 md:grid-cols-3 gap-6 my-6 items-stretch">
<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] space-y-2 h-full flex flex-col justify-between">
<div>
<div class="font-mono text-xs text-[var(--amber)] font-bold uppercase">1. Silicon Upgrade</div>
<h3 class="font-display text-base font-bold text-[var(--text-primary)] !mt-1 !mb-2">JFET-Input Op-Amps</h3>
<p class="text-xs opacity-80 leading-relaxed">
Migrating from LM358 to OPA2134 / TL072 to eliminate crossover distortion and achieve true 90.0° phase orthogonality.
</p>
</div>
</div>

<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] space-y-2 h-full flex flex-col justify-between">
<div>
<div class="font-mono text-xs text-[var(--royal)] font-bold uppercase">2. Active Gain Control</div>
<h3 class="font-display text-base font-bold text-[var(--text-primary)] !mt-1 !mb-2">JFET AGC Loop</h3>
<p class="text-xs opacity-80 leading-relaxed">
Replacing passive diode clamping with an active drain-source resistance JFET control circuit for ultra-low distortion sine generation.
</p>
</div>
</div>

<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] space-y-2 h-full flex flex-col justify-between">
<div>
<div class="font-mono text-xs text-[var(--crimson)] font-bold uppercase">3. Multi-Layer Layout</div>
<h3 class="font-display text-base font-bold text-[var(--text-primary)] !mt-1 !mb-2">Ground Plane & 0.1% Passives</h3>
<p class="text-xs opacity-80 leading-relaxed">
Implementing dedicated ground planes, matched 0.1% thin-film resistors, and precision PPS film capacitors for temperature-stable frequency lock.
</p>
</div>
</div>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold mt-10 mb-1">Core Disciplines</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-4">Skills & Applied Technologies</h2>

<div class="flex flex-wrap gap-2.5 my-4">
<span class="tag tag-electronics">Analog Circuit Design</span>
<span class="tag tag-electronics">State-Variable Oscillators</span>
<span class="tag tag-product">Barkhausen Criterion</span>
<span class="tag tag-product">Op-Amp Integrators</span>
<span class="tag tag-software">KiCad PCB Layout</span>
<span class="tag tag-software">3D CAD Modeling</span>
<span class="tag tag-health">LTSpice Simulation</span>
<span class="tag tag-health">Transient Modeling</span>
<span class="tag tag-renewables">Lissajous Phase Analysis</span>
<span class="tag tag-ux">Iterative Hardware Design</span>
</div>
