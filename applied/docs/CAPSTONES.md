# Integration projects after the challenge track

These are project briefs, not prebuilt solutions. Build one to practice larger C++ design. All can run in simulation without hardware.

## A. Telemetry-driven robot simulator

Combine the parser, sensor filter, moving average, ring buffer, state machine and PID.

Deliverables:

- A command loop reading telemetry and events from a text file.
- A simple motor-position simulation with configurable timestep and gains.
- CSV logging of time, setpoint, measurement, output and state.
- A latched simulated fault; no motor command while Emergency is active.
- Tests for malformed commands, reset behavior and bounded output.

Use separate modules and headers. Keep parsing, controller policy and simulation distinct. Document units and timestep assumptions. First simulate ideal measurements, then add noise. Extension: implement anti-windup and compare step-response logs against the original controller.

## B. Small vision postprocessing pipeline

Combine grayscale crop/blur, tensor layout conversion and IoU/NMS. Use synthetic images and a text file of fake detections; a neural network is optional.

Deliverables:

- A tiny image buffer class with validated dimensions.
- Preprocessing that clearly distinguishes cropping, resizing, normalization and layout conversion.
- Score filtering followed by NMS, returning original detection IDs.
- A timing report for multiple input sizes, with correctness tests separate from timing.
- A documented coordinate convention and channel order.

Extension: integrate OpenCV after the dependency-free pipeline works. Check your crop and IoU results against manually computed cases before comparing library behavior.

## C. Robot mission planner

Combine a dependency DAG with grid BFS or weighted graph Dijkstra.

Deliverables:

- Load an occupancy grid and a list of task dependencies.
- Produce a valid execution order and a route for each reachable destination.
- Report cycles and unreachable goals explicitly, without treating them as successful plans.
- Tests for blocked starts, multiple ready tasks, disconnected graphs and duplicate dependencies.
- A readable log showing task completion and route cost.

Extension: implement A* using Manhattan distance on a four-neighbor unit-cost grid. Compare expanded-node counts and verify that path length agrees with BFS.

## Completion rubric

Explain the design in a README, include build commands, add at least five tests that cover failure cases, and give one measured performance result. Discuss one tradeoff and one limitation. Use Git commits to show your implementation steps; keep generated binaries out of version control.
