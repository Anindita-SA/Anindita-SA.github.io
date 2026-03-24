import { defineCollection, z } from 'astro:content';

const projects = defineCollection({
  type: 'content',
  schema: z.object({
    title: z.string(),
    description: z.string(),
    domain: z.array(z.enum(['Renewables', 'Electronics', 'Product Design', 'Research'])),
    featured: z.boolean().default(false),
    date: z.string(),
    thumbnail: z.string().optional(),
    status: z.enum(['active', 'complete']).default('complete'),
  }),
});

const publications = defineCollection({
  type: 'content',
  schema: z.object({
    title: z.string(),
    authors: z.array(z.string()),
    venue: z.string(),
    year: z.number(),
    doi: z.string().optional(),
    url: z.string().optional(),
    abstract: z.string(),
    status: z.enum(['published', 'in-progress']).default('published'),
  }),
});

const tutorials = defineCollection({
  type: 'content',
  schema: z.object({
    title: z.string(),
    description: z.string(),
    category: z.array(z.enum(['Step-by-Step', 'Concept', 'Tool Walkthrough', 'Project Breakdown'])),
    tags: z.array(z.string()),
    date: z.string(),
    difficulty: z.enum(['Beginner', 'Intermediate', 'Advanced']).default('Beginner'),
    duration: z.string().optional(),
  }),
});

export const collections = { projects, publications, tutorials };