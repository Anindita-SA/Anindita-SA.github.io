---
title: "Aloka Fit - Precision Health Tracker"
description: "A data-dense wellness PWA built from scratch for a body with conditions - tracking macros, biomarkers, cycle, and AI-coached insights, because every other app was too fluffy to be useful."
domain: ["UX Design", "Software Design", "Health Tech"]
featured: true
date: "2026-03-28"
status: active
---

## The Itch

Every health app I tried made the same assumption: the user is healthy, motivated, and needs gentle nudges.

I am none of those things on a bad week. I have ADHD and migraines. I live in a college hostel with a fixed mess menu and zero kitchen access. I needed to track whether soy sauce triggered yesterday's headache, whether low sleep correlated with poor protein intake, whether my cycle phase explained why Tuesday felt impossible. No app on the market does all of that in one place without burying it under gamification badges and congratulatory push notifications.

So I built Aloka Fit. For myself. Over seven weeks. And I use it every single day.

![Dashboard with macro ring and progress bars](/projects/aloka-fit/dashboard.png)

## Who It's For

The design brief was specific: one user, known conditions, hostile environment.

- **ADHD** means friction is the enemy. Every extra tap is a tap that won't happen. Data entry has to be near-instant or it doesn't get logged.
- **Migraines** with known dietary triggers (soy, ginger, caffeine) mean food logging isn't just about macros - it's a trigger investigation tool.
- **Hostel mess food** means no barcodes, no packaged nutrition labels. Every meal has to be described in natural language and estimated on the fly.
- **No kitchen** means cost per gram of protein matters for deciding what to buy outside.

The AI inline allergy warning - which fires automatically when you log a food containing known triggers - came directly from this context. It's not a feature added for completeness. It's the reason the app exists.

![AI nutrition estimate with inline allergy and migraine warning](/projects/aloka-fit/allergy-warning.png)

## The Design Decisions That Mattered

### Rings Over Bars

The first version used standard HTML progress bars for macros - one bar per nutrient, stacked vertically. It worked, but it consumed enormous vertical space and felt passive. You glanced at it, processed nothing, scrolled past.

The pivot was a circular SVG macro ring tracking protein and calories as the hero element, paired with a compact horizontal grid for the remaining macros. The ring provides a psychological completion anchor - you either see a full circle or you don't. The compact grid reclaimed enough vertical space to fit the food library and daily log on the same screen without scrolling.

![Macro goals panel with SVG ring and compact nutrient grid](/projects/aloka-fit/fuel-tab.png)

Same logic applied to water tracking: a plain text counter (`1500/3000ml`) was replaced with an interactive SVG wave that visually fills as you tap the quick-add buttons. One fluid interaction instead of a mental arithmetic exercise.

### Sliders Over Dropdowns

Biomarker logging - mood, energy, stress - originally used dropdown menus. Two taps minimum. On a bad day, that's two taps too many.

Replaced with continuous 1-5 HTML range sliders with emoji faces that update in real-time as you drag. One fluid gesture. The data still gets stored as a 1-5 integer; the interaction just stops feeling like a form.

![Mood, energy, and stress sliders with real-time emoji feedback](/projects/aloka-fit/biomarkers.png)

### AI as Information Architecture

The AI food estimator isn't a chatbot bolted on. It's the primary data entry path for anyone without barcode access. You type "mess dal rice medium portion" and get a full macro breakdown with cost estimate, per-gram protein grade, and any relevant health warnings - all before you log a single item.

The harder design problem was the AI coaching report. Sending 30 days of raw meal logs, mood entries, supplement adherence, sleep hours, and cycle data to a language model is expensive and slow if done naively. The solution was a Supplement Reference Dictionary: active supplements are described once at the top of the prompt, and daily logs only reference them by name. This compressed a payload that would otherwise hit token limits into something fast and affordable.

That's an information architecture decision - what to say once, what to repeat, what to omit entirely.

![AI ingredient breakdown with cost grading and health advisory](/projects/aloka-fit/ai-estimate.png)

### Micronutrients as a Citizen

Most trackers treat micros as an afterthought - a collapsed section you never open. Here, Iron, Calcium, Vitamin C, Vitamin D, and Vitamin B12 sit alongside macros in the same panel, with their own progress indicators. For someone managing migraines and hormonal health, these numbers are not optional.

![Full macro and micronutrient tracking panel](/projects/aloka-fit/micronutrients.png)

### The Cycle Journal

Cycle phase affects energy, recovery capacity, and appetite. The app tracks Menstrual, Follicular, Ovulation, and Luteal phases on a dedicated calendar. With Cycle Sync enabled, the current phase is sent to the AI coach so recipe and nutrient recommendations account for where you are in the month.

This is people-centred design in the most literal sense: acknowledging that the body being tracked is not a generic body.

![Cycle journal calendar with phase tracking](/projects/aloka-fit/cycle-journal.png)

## The Logo

Five petals. One dot beneath.

The lotus in Ayurveda is a cooling, Sattvic herb used to balance excess Pitta and promote mental clarity. In yoga, Padmasana reinforces the connection between physical posture and mental state. The five petals map to the five tracking pillars - nutrition, movement, biomarkers, cycle, and AI insight. The dot below the flower is the mind, grounding the body.

The logo is the product philosophy made visible: mind and body tracked together, neither subordinate to the other.

![Aloka Fit lotus logo sketch](/projects/aloka-fit/logo_sketch.png)
![Aloka Fit lotus logo](/projects/aloka-fit/logo.png)

## The History View

The History tab aggregates everything: daily logs, mood timeline, 30-day summary with a consistency grade, and the AI Coach trigger. The grade is brutally honest - a D means you hit your protein target 4 out of 30 days. No softening, no "great effort" messaging. The data is the data.

![History tab with 30-day summary and daily log](/projects/aloka-fit/history-tab.png)

## What Worked. What Didn't.

**Worked:** The food logging flow is fast enough that I actually use it. The inline allergy warnings have caught real potential migraine triggers before eating. The cycle-mood correlation is visible in the history view in ways I couldn't see before. The AI coaching report, when it isn't rate-limited, is genuinely useful - not generic.

**Didn't work:** Consistency. The app grades my own adherence a D. That's not a design failure, it's an honest one. The tool works; the habit is still being built.

**Honest gap:** The Groq API key was initially hardcoded client-side - a known vulnerability documented during the security audit. This was resolved by migrating all AI calls to a Supabase Edge Function, where the key lives in server-side environment variables and never reaches the browser. The function verifies the user's Supabase JWT before forwarding any request to Groq, so only authenticated Aloka Fit users can trigger AI calls. The client-side codebase now contains no sensitive credentials.

No physical prototype exists. This is a software product that lives entirely on a screen, which limits what it can demonstrate for hardware-oriented reviewers. The v2 concept addresses this.

## If I Built This Again

- Per-user Groq API key storage - eliminate the shared key vulnerability entirely
- Supabase Edge Function proxy for AI calls - server-side key management
- Wrist-worn data input: heart rate and HRV pulled from a peripheral device to replace manual mood/energy sliders with objective data
- Offline-first architecture with background sync, so logging works without a connection
- A physical companion device - a small ambient display showing today's macro ring and current cycle phase, no screen required

The bones of this project are solid. The surface has room to grow.

## Skills

UX Design · Information Architecture · Prompt Engineering · Vanilla JS · Supabase (PostgreSQL + RLS) · SVG Animation · AI Integration (Groq) · Token Optimization · Security Hardening · Data Visualization · Constraint-Driven Design · Iterative Design