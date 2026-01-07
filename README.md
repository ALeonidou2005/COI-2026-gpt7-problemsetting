# GPT-7 - COI 2026 Round A Problem

A competitive programming problem I designed for Round A of the Cyprus Olympiad in Informatics (COI) 2026.

## About

This repository contains:
- Problem statements (English and Greek, in both .md and PDF formats)
- Reference solutions in C++ for all 6 subtasks
- Sample test cases
- Test case generation code

## Problem Design

**Inspiration:** This problem was inspired by concepts from my linear algebra and machine learning classes during my 1st semester as an undergraduate at Rice.

**Core Concept:** Built around the prefix sum technique, a fundamental optimization in competitive programming.

**Skills Tested:**
- **Algorithmic knowledge:** Prefix sums, Sorting, Cumulative Sums, Range Queries
- **Data structures:** Multi-dimensional arrays, Tuples/Pairs
- **Implementation:** Subtasks 3 and 6 are relatively implementation-heavy and test the ability to write and debug larger programs.
- **Problem-solving:** Recognizing how to use dual prefix sums for alternating sums.

## Test Case Generation

The test cases were generated using a custom C++ generator (`gen.cpp`) that creates random inputs based on subtask-specific constraint settings that I wrote manually. The generation process:

1. **Settings files** in `subtask_gen_settings/` define constraints for each subtask (N, M, K ranges, special conditions)
2. **Generator script** (`gen.cpp`) reads these settings and produces random valid inputs
3. **Reference solution** (`sub6_solution.cpp`) processes each input and calculates the expected outputs
4. **Automation script** (`run.sh`) orchestrates the generation of all test cases and organizes them in files and folders.

**Subtasks:**

The 6-subtask structure allows contestants to earn partial credit while solving and testing different parts of the problem and applying optimization techniques progressively.

- **Subtask 1, 2 (10 pts):** Trivial - Test problem understanding
- **Subtask 3 (25 pts):** Brute Force
- **Subtask 4,5,6 (65 pts):** Build upon the Prefix Sum Technique

## Repository Structure

```
├── GPT-7 (EN).md/pdf         # Problem statement (English)
├── GPT-7 (GR).md/pdf         # Problem statement (Greek)
├── tutorial.md               # Solution explanations
├── solutions/                # C++ solutions for subtasks 1-6
│   ├── sub1.cpp
│   ├── ...
│   └── sub6.cpp
├── test_case_generator/      # Scripts and settings used for generating the test cases
│   ├── subtask_gen_settings/    # Generator settings for each subtask
│   ├── gen.cpp                  # C++ script that randomly generates test cases
│   ├── run.sh                   # Bash script for test case generation
│   └── sub6_solution.cpp        # Full solution used to calculate the outputs
├── test_cases/               # Test cases for subtasks 1-6
│   ├── sub1_tests/
│   ├── ...
│   └── sub6_tests/
└── images/                   # Problem Statement LaTeX & Diagrams
```

## Competition

This problem was used in COI 2026 Round A. For submission and official testing, visit the [COI website](https://www.coinformatics.org/).

---

**Author:** Antreas Leonidou  
**Date:** December 2025
