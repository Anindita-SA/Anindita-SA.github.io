---
title: "Aloka Fit - Precision Health Tracker"
description: "A data-dense wellness PWA built from scratch for a body with conditions: tracking macros, biomarkers, cycle, and AI-coached insights, because every other app was too fluffy to be useful."
domain: ["UX Design", "Software Design", "Health Tech"]
featured: true
date: "2026-03-28"
status: Completed
---

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4 p-5 border border-[var(--border)] bg-[var(--bg-surface)] transition-all">
<div>
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mb-1">Project Context</div>
<h2 class="font-display text-2xl font-bold tracking-tight text-[var(--text-primary)] !mt-0 !mb-2">The Itch</h2>
<p class="leading-relaxed opacity-90 text-sm md:text-base mb-2">
Every health app I tried made the same assumption: the user is healthy, motivated, and needs gentle nudges.
</p>
<p class="leading-relaxed opacity-90 text-sm md:text-base mb-2">
I am none of those things on a bad week. I have migraines. I live in a college hostel with a fixed mess menu and zero kitchen access. I needed to track whether soy sauce triggered yesterday's headache, whether low sleep correlated with poor protein intake, and whether my cycle phase explained why Tuesday felt impossible. No app on the market does all of that in one place without burying it under gamification badges and push notifications.
</p>
<p class="font-semibold text-[var(--amber)] text-sm md:text-base">
So I built Aloka Fit for myself over seven weeks, and I use it every single day.
</p>
</div>
<div>
<div class="w-full photo-card-amber rounded cursor-pointer">
<img src="/projects/aloka-fit/dashboard.gif" alt="Dashboard with macro ring and progress bars" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono flex items-center justify-center gap-1.5 font-medium">
⚡ Hero Dashboard with macro ring and progress bars
</div>
</div>
</div>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="order-2 md:order-1">
<div class="w-full photo-card-crimson rounded cursor-pointer">
<img src="/projects/aloka-fit/allergy-warning.gif" alt="AI nutrition estimate with inline allergy and migraine warning" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--crimson)] mt-2 font-mono flex items-center justify-center gap-1.5 font-medium">
⚠️ AI nutrition estimate with inline trigger warning
</div>
</div>
</div>
<div class="order-1 md:order-2 space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold">User Persona & Constraints</div>
<h2 class="font-display text-2xl font-bold tracking-tight text-[var(--text-primary)] !mt-0 !mb-2">Who It's For</h2>
<p class="leading-relaxed opacity-90 text-sm md:text-base">
The design brief was specific: one user, known conditions, hostile environment.
</p>
<ul class="space-y-2 text-sm md:text-base">
<li><strong class="text-[var(--crimson)]">ADHD:</strong> Friction is the enemy. Every extra tap is a tap that will not happen. Data entry has to be near-instant or it does not get logged.</li>
<li><strong class="text-[var(--amber)]">Migraines:</strong> Known dietary triggers like soy, ginger, and caffeine mean food logging is not just about macros: it is a trigger investigation tool.</li>
<li><strong class="text-[var(--royal)]">Hostel mess food:</strong> No barcodes or packaged nutrition labels exist. Every meal has to be described in natural language and estimated on the fly.</li>
<li><strong class="text-[var(--amber)]">No kitchen access:</strong> Cost per gram of protein matters directly for deciding what supplementary food to buy outside.</li>
</ul>
<div class="text-xs md:text-sm opacity-90 bg-[var(--bg-surface)] p-3 border-l-4 border-[var(--crimson)] shadow-sm">
The AI inline allergy warning fires automatically when you log a food containing known triggers. It came directly from this context and is the core reason the app exists.
</div>
</div>
</div>

<div class="flex items-center gap-3 my-4 pt-2">
<div class="h-0.5 w-12 bg-[var(--royal)]"></div>
<div class="h-0.5 w-6 bg-[var(--crimson)]"></div>
<div class="h-0.5 w-3 bg-[var(--amber)]"></div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !my-0">The Design Decisions That Mattered</h2>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">Interaction Design</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">Rings Over Bars</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The initial prototype used standard HTML progress bars stacked vertically for each macro. It worked, but it consumed enormous vertical space and felt passive. You glanced at it, processed nothing, and scrolled past.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The pivot was a circular SVG macro ring tracking protein and calories as the hero element, paired with a compact horizontal grid for the remaining macros. The ring provides a psychological completion anchor: you either see a full circle or you do not. This compact grid reclaimed enough vertical space to fit the food library and daily log on the same screen without scrolling.
</p>
<p class="text-xs md:text-sm opacity-80 italic bg-[var(--bg-surface)] p-2.5 border-l-4 border-[var(--royal)] border border-[var(--border)]">
Water tracking follows the same logic: a plain text counter (1500/3000ml) was replaced with an interactive SVG wave that visually fills as you tap quick-add buttons. It turns mental arithmetic into a single fluid interaction.
</p>
</div>
<div>
<div class="w-full photo-card-royal rounded cursor-pointer">
<img src="/projects/aloka-fit/fuel-tab.png" alt="Macro goals panel with SVG ring and compact nutrient grid" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--royal)] mt-2 font-mono font-medium">Macro goals panel with SVG ring and compact nutrient grid</div>
</div>
</div>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="order-2 md:order-1">
<div class="w-full photo-card-amber rounded cursor-pointer">
<img src="/projects/aloka-fit/biomarkers.gif" alt="Mood, energy, and stress sliders with real-time emoji feedback" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono font-medium">Biomarker sliders with real-time emoji feedback</div>
</div>
</div>
<div class="order-1 md:order-2 space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold">UX Friction Reduction</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">Sliders Over Dropdowns</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
Biomarker logging for mood, energy, and stress originally used dropdown menus requiring two taps minimum per field. On a high-fatigue or migraine day, two taps per field is two taps too many.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
These were replaced with continuous 1 to 5 range sliders paired with emoji faces that update dynamically as you drag. The interaction takes a single fluid gesture while storing clean integer data in the database.
</p>
</div>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">Prompt Engineering</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">AI as Information Architecture</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The AI food estimator is not a chatbot bolted on. It serves as the primary data entry interface for hostel meals without barcode access. Entering "mess dal rice medium portion" generates a complete macro estimate, cost breakdown, per-gram protein score, and health advisories before logging.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
To prevent token limit bottlenecks when generating 30-day AI coaching summaries, active supplements are stored in a Supplement Reference Dictionary. Prompt payloads reference supplements by key instead of repeating full definitions, compressing API payload size and cutting latency.
</p>
</div>
<div>
<div class="w-full photo-card-royal rounded cursor-pointer">
<img src="/projects/aloka-fit/ai-estimate.png" alt="AI ingredient breakdown with cost grading and health advisory" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--royal)] mt-2 font-mono font-medium">AI ingredient breakdown with cost grading and health advisory</div>
</div>
</div>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="order-2 md:order-1">
<div class="w-full photo-card-amber rounded cursor-pointer">
<img src="/projects/aloka-fit/micronutrients.png" alt="Full macro and micronutrient tracking panel" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--amber)] mt-2 font-mono font-medium">Full macro and micronutrient tracking panel</div>
</div>
</div>
<div class="order-1 md:order-2 space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold">Nutritional Data</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">Micronutrients as First-Class Citizens</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
Most fitness apps treat micronutrients as an afterthought hidden deep in sub-menus. In Aloka Fit, key minerals and vitamins including Iron, Calcium, Vitamin C, Vitamin D, and Vitamin B12 sit directly alongside macros in the main tracking panel.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
For managing chronic headaches and hormonal health, these micronutrient metrics provide crucial diagnostic clarity.
</p>
</div>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold">Women's Health</div>
<h3 class="font-display text-xl font-bold text-[var(--text-primary)] !mt-0">The Cycle Journal</h3>
<p class="text-sm md:text-base leading-relaxed opacity-90">
Hormonal phase directly alters energy levels, recovery rate, and metabolic demand. The application tracks Menstrual, Follicular, Ovulation, and Luteal phases on a dedicated calendar view.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
When Cycle Sync is active, current phase data is forwarded to the AI coach so workout intensity and dietary recommendations adjust dynamically based on where you are in your monthly cycle.
</p>
</div>
<div>
<div class="w-full photo-card-crimson rounded cursor-pointer">
<img src="/projects/aloka-fit/cycle-journal.png" alt="Cycle journal calendar with phase tracking" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--crimson)] mt-2 font-mono font-medium">Cycle journal calendar with phase tracking</div>
</div>
</div>
</div>

<div class="my-5 border border-[var(--border)] bg-[var(--bg-surface)] p-5 hover:border-[var(--royal)] transition-all">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold mb-1">Brand Identity</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] mb-3 border-b border-[var(--border)] pb-2">The Logo & Philosophy</h2>
<div class="grid grid-cols-1 md:grid-cols-[1.1fr_1fr] gap-6 items-center">
<div class="space-y-2.5">
<p class="text-sm md:text-base leading-relaxed opacity-90">
The emblem consists of five lotus petals anchored above a single central dot.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
In Ayurvedic tradition, the lotus is a cooling Sattvic herb used to soothe excess Pitta and foster mental clarity. In yogic practice, Padmasana symbolizes the grounding connection between physical posture and internal equilibrium.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The five petals represent the five functional pillars of Aloka Fit: Nutrition, Movement, Biomarkers, Cycle Phase, and AI Insights. The dot beneath represents the grounding presence of the mind.
</p>
</div>
<div class="grid grid-cols-2 gap-3">
<div class="photo-card-amber rounded text-center cursor-pointer">
<img src="/projects/aloka-fit/logo_sketch.png" alt="Aloka Fit lotus logo sketch" class="w-full h-auto object-contain rounded" />
<div class="text-xs opacity-80 mt-1 font-mono text-[var(--amber)] font-medium">Initial Sketch</div>
</div>
<div class="photo-card-royal rounded text-center cursor-pointer">
<img src="/projects/aloka-fit/logo_icon.png" alt="Aloka Fit lotus logo" class="w-full h-auto object-contain rounded" />
<div class="text-xs opacity-80 mt-1 font-mono text-[var(--royal)] font-medium">Vector Icon</div>
</div>
</div>
</div>
</div>

<div class="grid grid-cols-1 md:grid-cols-2 gap-6 items-center my-4">
<div class="order-2 md:order-1">
<div class="w-full photo-card-royal rounded cursor-pointer">
<img src="/projects/aloka-fit/history-tab.gif" alt="History tab with 30-day summary and daily log" class="w-full h-auto object-contain rounded" />
<div class="text-xs text-center text-[var(--royal)] mt-2 font-mono font-medium">History tab with 30-day summary and daily log</div>
</div>
</div>
<div class="order-1 md:order-2 space-y-2.5">
<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold">Analytics & Coaching</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] !mt-0">The History View</h2>
<p class="text-sm md:text-base leading-relaxed opacity-90">
The History tab synthesizes all recorded data into a 30-day timeline: daily meal logs, mood trajectory, habit consistency grades, and the monthly AI Coach summary trigger.
</p>
<p class="text-sm md:text-base leading-relaxed opacity-90">
Adherence scoring is calculated objectively without superficial artificial encouragement. If protein targets were achieved on only 4 out of 30 days, the app presents a D grade. Unfiltered data provides authentic self-awareness.
</p>
</div>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--crimson)] font-bold mt-5 mb-0.5">Security & Synthesis</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-3">What Worked & Security Audit</h2>

<div class="space-y-2.5 my-3">
<p class="text-sm md:text-base leading-relaxed">
<strong class="text-[var(--royal)]">What Worked:</strong> Fast friction-free data logging led to consistent real-world usage. Inline allergen warnings successfully flagged migraine triggers prior to consumption, and cycle-mood correlations became visible over multi-week periods.
</p>

<div class="bg-[var(--bg-surface)] p-3.5 border-l-4 border-[var(--crimson)] border border-[var(--border)] shadow-sm space-y-2">
<p class="text-sm md:text-base leading-relaxed !mb-0">
<strong class="text-[var(--crimson)]">Backend Security Architecture:</strong> During the initial security audit, client-side API key exposure was identified as a critical vulnerability. All AI calls were subsequently migrated to a Supabase Edge Function environment. The Edge Function validates user JWT tokens before forwarding requests to the Groq API, ensuring zero sensitive credentials reside on the client browser.
</p>
</div>
</div>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--amber)] font-bold mt-5 mb-0.5">Next Steps</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-3">Future Roadmap</h2>

<ul class="space-y-2 my-3 text-sm md:text-base">
<li>Individual user API key vaults to support self-hosted AI inference.</li>
<li>Peripheral hardware integration: fetching heart rate and HRV metrics from wearable devices to supplement manual mood sliders.</li>
<li>Offline-first local storage architecture with automatic background synchronization.</li>
<li>Ambient physical companion display showing real-time macro progress rings and current cycle phase without screen distractions.</li>
</ul>

<div class="font-mono text-xs uppercase tracking-wider text-[var(--royal)] font-bold mt-5 mb-0.5">Tech Stack</div>
<h2 class="font-display text-2xl font-bold text-[var(--text-primary)] border-b border-[var(--border)] pb-2 mb-3">Skills & Technologies</h2>

<div class="flex flex-wrap gap-2 my-3">
<span class="tag tag-ux">UX Design</span>
<span class="tag tag-ux">Information Architecture</span>
<span class="tag tag-research">Prompt Engineering</span>
<span class="tag tag-software">Vanilla JS</span>
<span class="tag tag-health">Supabase (PostgreSQL + RLS)</span>
<span class="tag tag-product">SVG Animation</span>
<span class="tag tag-electronics">Groq AI Integration</span>
<span class="tag tag-software">Token Optimization</span>
<span class="tag tag-research">Security Hardening</span>
<span class="tag tag-product">Data Visualization</span>
</div>