# Personal Portfolio — Astro + GitHub Pages

## Quick Setup

### 1. Prerequisites
- Node.js 18+
- A GitHub account

### 2. Clone and install
```bash
git clone https://github.com/YOUR_USERNAME/YOUR_USERNAME.github.io
cd YOUR_USERNAME.github.io
npm install
```

### 3. Run locally
```bash
npm run dev
# → http://localhost:4321
```

### 4. Deploy
Push to `main` branch. GitHub Actions handles the rest.

> **First deploy only:** Go to your repo → Settings → Pages → Source: GitHub Actions

---

## Configuration

Before deploying, update these placeholders:

| File | What to change |
|------|----------------|
| `astro.config.mjs` | `site:` → your GitHub Pages URL |
| `src/components/Nav.astro` | `YN` initials → yours |
| `src/components/Footer.astro` | GitHub, LinkedIn, Substack links |
| `src/pages/index.astro` | Your name, hero copy |
| `src/pages/about.astro` | Bio text, email, links, skills |
| `src/pages/contact.astro` | Email and social links |
| `public/` | Add `avatar.jpg` for the About page photo |

---

## Adding a New Project

Create a file in `src/content/projects/my-project-name.md`:

```markdown
---
title: "Project Title"
description: "One-sentence description shown in project cards."
domain: ["Renewables"]          # Options: Renewables, Electronics, Product Design, Research
featured: false                  # true = shows on homepage (max 3)
date: "2025-01-15"              # YYYY-MM-DD
status: complete                 # complete or active
thumbnail: "/images/project.jpg" # optional
---

## The Problem
Write your case study here in Markdown.

## Process
...

## Outcome
...
```

That's it. The project automatically appears in the Projects page and (if `featured: true`) on the homepage.

---

## Adding a Publication

Create a file in `src/content/publications/paper-slug.md`:

```markdown
---
title: "Full Paper Title"
authors: ["Your Name", "Co-Author Name"]
venue: "Conference or Journal Name"
year: 2025
url: "https://doi.org/10.xxxx/xxxxx"   # optional
abstract: "Your abstract text here."
status: published                        # published or in-progress
---
```

`in-progress` publications appear as a dashed card with an "In review" badge. Switch to `published` when the paper lands.

---

## Dark / Light Mode

The site respects the user's OS preference by default. Users can toggle manually — preference is saved in `localStorage` so it persists across visits.

---

## Customizing Colors

Accent colors are defined in `tailwind.config.mjs` and `src/styles/global.css`. The four core accents:
- `--royal: #002366` — Royal Blue
- `--crimson: #FD151B` — Red
- `--amber: #FCBA04` — Yellow  
- `--blush: #FFE6E8` — Blush Pink

---

## Stack
- [Astro](https://astro.build) — framework
- [Tailwind CSS](https://tailwindcss.com) — styling
- [Syne](https://fonts.google.com/specimen/Syne) — display font
- [DM Sans](https://fonts.google.com/specimen/DM+Sans) — body font
- [JetBrains Mono](https://fonts.google.com/specimen/JetBrains+Mono) — monospace
- GitHub Pages — hosting (free)
- GitHub Actions — CI/CD
