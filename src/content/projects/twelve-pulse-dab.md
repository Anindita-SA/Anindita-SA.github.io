---
title: "Three-Phase 12-Pulse Dual Active Bridge Converter"
description: "Modeling, simulation, and FPGA-based hardware realization of a 12-pulse DAB converter for offshore wind DC collection systems with harmonic cancellation and ZVS validation."
domain: ["Electronics", "Renewables", "Research"]
featured: true
date: "2026-05-30"
thumbnail: "/projects/twelve-pulse-dab/thumbnail.png"
status: Completed
draft: false
---

<div class="grid grid-cols-1 md:grid-cols-2 gap-8 items-center my-6 p-6 border border-[var(--border)] bg-[var(--bg-surface)] transition-all">
<div class="space-y-3">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mb-1">Research & Engineering Context</div>
<h2 class="font-display text-2xl font-bold tracking-tight text-[var(--text-primary)] !mt-0 !mb-2">The Problem & Motivation</h2>
<p class="leading-relaxed opacity-90 text-sm md:text-base">
Medium-frequency-transformer (MFT) based isolated DC-DC conversion is a foundational building block for modern high-power systems, including solid-state transformers, MVDC/HVDC grids, and offshore wind energy collection systems.
</p>
<p class="leading-relaxed opacity-90 text-sm md:text-base">
In offshore wind platforms, eliminating bulky line-frequency transformers reduces structural platform footprint and capital expenditure. However, achieving high power density requires switching topologies that minimize filtering requirements, lower transformer kVA ratings, and preserve soft-switching across varying load conditions.
</p>
<p class="font-semibold text-[var(--amber)] text-sm md:text-base">
During a summer research internship at IIT Kharagpur, I modeled three-phase Dual Active Bridge (DAB) topologies, extended the architecture into a 12-pulse configuration for harmonic cancellation, and implemented real-time gate pulse generation on a Xilinx Virtex-5 FPGA with hardware testbed validation.
</p>
</div>
<div>
<div class="w-full photo-card-amber rounded cursor-pointer">
<img src="/projects/twelve-pulse-dab/dab-topology.png" alt="Single-phase Dual Active Bridge topology with intermediate AC link" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono flex items-center justify-center gap-1.5 font-medium">
⚡ Baseline DAB converter structure with intermediate AC link
</div>
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">Topology & Harmonic Cancellation</h2>
</div>

<div class="space-y-6 my-6">
<div class="space-y-3">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">First Principles</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">12-Pulse Geometric Cancellation</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
A standard single-phase DAB produces high per-device current stress. Moving to a three-phase DAB with six-step operation distributes power across three bridge legs, reducing RMS current per switch but introducing characteristic 5th and 7th harmonics (<em>h</em> = 6<em>k</em> ± 1).
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The twelve-pulse configuration overcomes this by combining two three-phase bridges:
</p>
<ul class="space-y-2 text-sm md:text-base">
<li><strong>Bridge 1:</strong> Star-Star (Y-Y) transformer with 1:1 turns ratio.</li>
<li><strong>Bridge 2:</strong> Delta-Star (Δ-Y) transformer with √3 : 1 turns ratio.</li>
<li><strong>Interconnection:</strong> Primary windings connected in parallel, secondary windings connected in series.</li>
</ul>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The delta winding introduces an inherent 30° geometric phase displacement (Yd1 vector group). This natural displacement causes the 5th and 7th harmonic voltages and currents from the two converter groups to cancel each other out completely, leaving only higher-order characteristic harmonics of order <em>h</em> = 12<em>k</em> ± 1 (11th, 13th, 23rd, 25th, etc.) without requiring active controller phase delays.
</p>
</div>

<div class="bg-[var(--bg-surface)] p-6 border border-[var(--border)] space-y-4">
<div class="flex items-center justify-between border-b border-[var(--border)] pb-3">
<div>
<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold">Analytical Comparison</div>
<h4 class="font-display text-lg font-bold text-[var(--text-primary)] !mt-0 !mb-0">Converter Topologies & Harmonic Spectrum</h4>
</div>
<span class="font-mono text-xs text-[var(--amber)] bg-[var(--bg)] px-2.5 py-1 border border-[var(--border)] rounded">
Theoretical Modeling
</span>
</div>

<div class="overflow-x-auto">
<table class="w-full text-xs md:text-sm font-mono text-left border-collapse min-w-[550px]">
<thead>
<tr class="border-b border-[var(--border)] text-[var(--text-primary)] bg-[var(--bg)]">
<th class="py-3 px-4">Topology</th>
<th class="py-3 px-4">Harmonics (<em>h</em>)</th>
<th class="py-3 px-4">Valid Phase Shift Range (φ)</th>
<th class="py-3 px-4">Transformer Turns Ratio</th>
<th class="py-3 px-4">kVA Rating Impact</th>
</tr>
</thead>
<tbody class="opacity-90 divide-y divide-[var(--border)]">
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="py-3 px-4 font-semibold">1-Phase DAB</td>
<td class="py-3 px-4">2<em>k</em> ± 1</td>
<td class="py-3 px-4">0 to π</td>
<td class="py-3 px-4">1 : 1</td>
<td class="py-3 px-4 opacity-70">Baseline</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="py-3 px-4 font-semibold">3-Phase Y-Y</td>
<td class="py-3 px-4">6<em>k</em> ± 1</td>
<td class="py-3 px-4">0 to π</td>
<td class="py-3 px-4">1 : 1</td>
<td class="py-3 px-4 opacity-70">Lower device current stress</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="py-3 px-4 font-semibold">3-Phase Δ-Y</td>
<td class="py-3 px-4">6<em>k</em> ± 1</td>
<td class="py-3 px-4">0 to π</td>
<td class="py-3 px-4">√3 : 1</td>
<td class="py-3 px-4 opacity-70">Compensates line-to-phase relation</td>
</tr>
<tr class="bg-[var(--bg)] text-[var(--amber)] font-bold">
<td class="py-3 px-4">12-Pulse DAB</td>
<td class="py-3 px-4">12<em>k</em> ± 1</td>
<td class="py-3 px-4">0 to π/3</td>
<td class="py-3 px-4">Combined (1:1 + √3:1)</td>
<td class="py-3 px-4 text-[var(--amber)]">~10% Total VA Reduction</td>
</tr>
</tbody>
</table>
</div>

<div class="text-xs md:text-sm bg-[var(--bg)] p-3.5 border-l-4 border-[var(--amber)] border border-[var(--border)] text-[var(--text-secondary)] leading-relaxed">
<strong class="text-[var(--amber)]">Key Harmonic Benefit:</strong> Canceling the 5th, 7th, 17th, and 19th harmonic orders reduces the resultant secondary winding RMS current, yielding an inherent ~10% reduction in required transformer kVA rating.
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">Simulation & Control Architecture</h2>
</div>

<div class="grid grid-cols-1 lg:grid-cols-2 gap-8 items-center my-6">
<div class="space-y-4">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">MATLAB / Simscape Modeling</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">Closed-Loop Control & Stiff Solvers</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The complete 12-pulse converter model was constructed in MATLAB/Simulink utilizing Simscape Electrical Specialized Power Systems blocks, simulating both Y-Y and Delta-Y bridges operating in tandem.
</p>
<ul class="space-y-2.5 text-sm md:text-base">
<li><strong>Two-Stage Control Hierarchy:</strong> An outer voltage regulation loop calculates error <em>e(t)</em> = <em>V<sub>ref</sub></em> - <em>V<sub>o,meas</sub></em> and feeds a PI controller (<em>K<sub>p</sub></em> = 0.04, <em>K<sub>i</sub></em> = 2.35) to generate current reference <em>I<sub>dab,ref</sub></em>. The inner stage maps this current into the required phase-shift angle φ.</li>
<li><strong>Feed-Forward Current Compensation:</strong> To enhance dynamic response during rapid load transitions, feed-forward current (<em>I<sub>fed</sub></em>) from the buck converter is directly subtracted: <em>I<sub>dab,ref</sub></em> = <em>I<sub>PI</sub></em> - <em>I<sub>fed</sub></em>.</li>
<li><strong>Low-Pass Ripple Attenuation:</strong> Switching ripple on the measured feed-forward current initially caused loop instability. Adding a discrete low-pass filter on <em>I<sub>fed</sub></em> stabilized the loop without degrading response time.</li>
<li><strong>Stiff Solver Selection (ODE23TB vs ODE45):</strong> Standard variable-step ODE45 produced severe numerical stiffness issues, triggering fictitious multi-kV spikes and excessively slow step times. Switching to ODE23TB (a trapezoidal rule stiff solver with backward differentiation formulas) restored numerical stability and clean waveform generation.</li>
</ul>
</div>

<div class="space-y-4">
<div class="photo-card-royal rounded cursor-pointer">
<img src="/projects/twelve-pulse-dab/simulink-zero-power.png" alt="Simulink output waveforms showing zero power transfer at phi = 0" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--royal)] mt-2 font-mono font-medium">12-pulse primary output waveforms at φ = 0 (Zero power transfer)</div>
</div>
<div class="photo-card-amber rounded cursor-pointer">
<img src="/projects/twelve-pulse-dab/simulink-power-transfer.png" alt="Simulink output waveforms showing active power transfer at phi = -15 degrees" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono font-medium">12-pulse primary output waveforms at φ = -15° (Active power transfer)</div>
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">FPGA Digital Control Implementation</h2>
</div>

<div class="grid grid-cols-1 lg:grid-cols-2 gap-8 items-start my-6">
<div class="space-y-4">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold">Xilinx System Generator</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">Virtex-5 Hardware Architecture</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The gate pulse generation and discrete control logic were implemented in Xilinx System Generator 2013b for synthesis onto a Digilent Genesys Virtex-5 FPGA board.
</p>
<ul class="space-y-2.5 text-sm md:text-base">
<li><strong>Fixed-Point Arithmetic:</strong> All controller operations were quantised to fixed-point formats with explicit overflow and truncation management to prevent accumulator overflow in hardware.</li>
<li><strong>Counter-Based Carrier:</strong> The 2 kHz switching frequency (500 μs period) was generated via an up-counter running from 0 to 499 at a 1 MHz clock rate (1 μs per count). Comparing the counter against 250 produced 50% duty cycle square waves per phase.</li>
<li><strong>Three-Phase Carrier Offsets:</strong> 120° and 240° phase displacements were established using fixed count offsets of 167 and 333 counts relative to the 500-count master period.</li>
<li><strong>Look-Up Table (LUT) Square Root:</strong> Calculating phase angle φ from the power transfer equation requires a square-root evaluation:</li>
</ul>

<div class="p-4 my-3 rounded border border-[var(--border)] bg-[var(--bg)] text-center font-mono text-xs md:text-sm tracking-wide text-[var(--text-primary)] shadow-sm">
φ = (2π / 3) ± √[ (2π / 3)² - (2π ω L I<sub>i</sub> / V<sub>cp</sub>) ]
</div>

<p class="text-xs md:text-sm leading-relaxed opacity-85">
Conventional CORDIC square-root blocks introduced high FPGA slice consumption and multi-cycle pipeline latency. Designing a Look-Up Table (LUT) based square root approximation eliminated computational latency and delivered deterministic single-cycle execution.
</p>
</div>

<div class="space-y-4">
<div class="photo-card-crimson rounded cursor-pointer">
<img src="/projects/twelve-pulse-dab/zvs-oscilloscope.png" alt="Oscilloscope capture showing Zero Voltage Switching validation with lagging transformer current" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--crimson)] mt-2 font-mono font-medium">Oscilloscope capture verifying Zero Voltage Switching (ZVS) under lagging current</div>
</div>
<div class="bg-[var(--bg-surface)] p-4 border-l-4 border-[var(--crimson)] border border-[var(--border)] text-xs md:text-sm leading-relaxed">
<strong class="text-[var(--crimson)]">Zero Voltage Switching (ZVS) Verification:</strong> Soft-switching requires the transformer leakage current to be flowing in the reverse direction prior to switch turn-on to forward-bias the anti-parallel diode. As captured on the oscilloscope above, the R-phase current (C3) transitions negative immediately before the zero-crossing of the pole voltage (C2), verifying complete ZVS operation.
</div>
</div>
</div>

<div class="flex items-center gap-3 my-8 pt-4">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">Hardware Experimental Validation</h2>
</div>

<div class="space-y-6 my-6">
<p class="text-sm md:text-base leading-relaxed opacity-90">
The physical experimental setup connected two 12-pulse converters back-to-back in a circulating-power test loop. Power circulated between the two converter stages while an auxiliary buck converter supplied only the system losses (<em>P<sub>buck</sub></em> = <em>V<sub>CP</sub></em> × <em>I<sub>buck</sub></em>). This enabled full-power throughput evaluation with minimal supply draw.
</p>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-stretch">
<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] flex flex-col justify-between">
<div>
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mb-3">Experimental Operating Parameters</div>
<ul class="text-xs md:text-sm font-mono space-y-2 opacity-90">
<li><strong>Bus Voltage (<em>V<sub>CP</sub></em>):</strong> 100 V DC</li>
<li><strong>Switching Frequency (<em>f<sub>sw</sub></em>):</strong> 2 kHz</li>
<li><strong>Leakage Inductance (<em>L</em>):</strong> 220 μH</li>
<li><strong>DC Bus Capacitance (<em>C</em>):</strong> 4700 μF</li>
<li><strong>Controller Platform:</strong> Digilent Genesys Virtex-5 FPGA</li>
<li><strong>Clock Frequency:</strong> 1 MHz system clock</li>
</ul>
</div>
<div class="mt-4 pt-3 border-t border-[var(--border)] text-[11px] font-mono text-[var(--amber)]">
Validated across positive and negative phase shifts
</div>
</div>

<div class="bg-[var(--bg-surface)] p-5 border border-[var(--border)] flex flex-col justify-between">
<div>
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold mb-3">Efficiency & Power Loop Results</div>
<div class="overflow-x-auto">
<table class="w-full text-xs md:text-sm font-mono text-left border-collapse">
<thead>
<tr class="border-b border-[var(--border)] bg-[var(--bg)]">
<th class="py-2 px-3">Test Point</th>
<th class="py-2 px-3"><em>V<sub>CP</sub></em></th>
<th class="py-2 px-3"><em>P<sub>buck</sub></em> (Loss)</th>
<th class="py-2 px-3"><em>P<sub>circ</sub></em></th>
<th class="py-2 px-3">Efficiency</th>
</tr>
</thead>
<tbody class="opacity-90 divide-y divide-[var(--border)]">
<tr class="hover:bg-[var(--bg)]">
<td class="py-2 px-3 font-semibold">+15° Shift</td>
<td class="py-2 px-3">102.7 V</td>
<td class="py-2 px-3">26.77 W</td>
<td class="py-2 px-3">592 W</td>
<td class="py-2 px-3 text-[var(--amber)] font-bold">95.6%</td>
</tr>
<tr class="hover:bg-[var(--bg)]">
<td class="py-2 px-3 font-semibold">-15° Shift</td>
<td class="py-2 px-3">102.7 V</td>
<td class="py-2 px-3">23.84 W</td>
<td class="py-2 px-3">592 W</td>
<td class="py-2 px-3 text-[var(--amber)] font-bold">96.1%</td>
</tr>
</tbody>
</table>
</div>
</div>
<p class="text-xs opacity-75 mt-4 pt-3 border-t border-[var(--border)] leading-relaxed">
Total converter losses accounted for under 5% of circulating throughput power across all operating test points.
</p>
</div>
</div>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold mt-10 mb-1">Engineering Diagnosis</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-4">Failure Analysis & Debugging Log</h2>

<p class="text-sm md:text-base leading-relaxed opacity-90 mb-4">
Bridging theoretical power equations, discrete simulation, and physical FPGA hardware exposed several practical engineering challenges:
</p>

<div class="overflow-x-auto my-6">
<table class="w-full text-xs md:text-sm font-body border border-[var(--border)] bg-[var(--bg-surface)] min-w-[650px]">
<thead class="bg-[var(--bg)] font-mono text-xs uppercase border-b border-[var(--border)]">
<tr>
<th class="p-3.5 text-left text-[var(--crimson)] w-1/3">Issue Encountered</th>
<th class="p-3.5 text-left text-[var(--amber)] w-1/3">Root Cause</th>
<th class="p-3.5 text-left text-[var(--royal)] w-1/3">Engineering Resolution</th>
</tr>
</thead>
<tbody class="divide-y divide-[var(--border)] opacity-90">
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">Excessive circulating current in Delta-Y DAB branch</td>
<td class="p-3.5 leading-relaxed">Transformer turns ratio mismatch and leakage inductance disparity between Y-Y and Δ-Y branches.</td>
<td class="p-3.5 leading-relaxed">Adjusted Δ-Y turns ratio to compensate for line-to-phase voltage relationships; balanced branch currents on mean rather than uncorrected RMS.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold"><em>V<sub>CP</sub></em> bus collapse when removing manual phase trim</td>
<td class="p-3.5 leading-relaxed">Natural 30° transformer geometric displacement and controller phase reference were misaligned.</td>
<td class="p-3.5 leading-relaxed">Corrected carrier phase alignment in gate generation logic to account for inherent winding displacement.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">Continuous integrator saturation in discrete Powergui</td>
<td class="p-3.5 leading-relaxed">Continuous-time PI integrator accumulated unbounded error during discrete solver transient steps.</td>
<td class="p-3.5 leading-relaxed">Replaced with discrete-time integrator featuring conditional anti-windup clamping and reset limits.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">Distorted line-to-ground voltage on Delta secondary</td>
<td class="p-3.5 leading-relaxed">Delta windings lack a neutral point, making line-to-ground voltage physically undefined.</td>
<td class="p-3.5 leading-relaxed">Switched instrumentation to line-to-line differential measurement across all three phases.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">System Generator token hierarchy errors</td>
<td class="p-3.5 leading-relaxed">Xilinx DSP blocks instantiated outside the root System Generator token scope.</td>
<td class="p-3.5 leading-relaxed">Restructured block diagram hierarchy to ensure all FPGA primitives resided within the token domain.</td>
</tr>
<tr class="hover:bg-[var(--bg)] transition-colors">
<td class="p-3.5 font-semibold">FPGA pin output inconsistency across builds</td>
<td class="p-3.5 leading-relaxed">Stale bitstream generation files and UCF constraint net name mismatches.</td>
<td class="p-3.5 leading-relaxed">Implemented LED blink test harness on physical board to verify gateway nets; cleaned stale build targets before synthesis.</td>
</tr>
</tbody>
</table>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold mt-10 mb-1">Core Disciplines</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-4">Skills & Applied Technologies</h2>

<div class="flex flex-wrap gap-2.5 my-4">
<span class="tag tag-renewables">MFT Isolated DC-DC</span>
<span class="tag tag-renewables">Offshore Wind Systems</span>
<span class="tag tag-renewables">Harmonic Cancellation</span>
<span class="tag tag-product">Dual Active Bridge (DAB)</span>
<span class="tag tag-product">Zero Voltage Switching (ZVS)</span>
<span class="tag tag-product">Circulating-Power Test Loop</span>
<span class="tag tag-software">Xilinx Virtex-5 FPGA</span>
<span class="tag tag-software">System Generator (DSP)</span>
<span class="tag tag-software">Fixed-Point DSP</span>
<span class="tag tag-electronics">Power Electronics</span>
<span class="tag tag-electronics">Gate Driver Control</span>
<span class="tag tag-health">Oscilloscope Diagnostics</span>
<span class="tag tag-health">MATLAB / Simulink</span>
<span class="tag tag-craft">Simscape Power Systems</span>
<span class="tag tag-ux">Discrete Anti-Windup Control</span>
</div>
