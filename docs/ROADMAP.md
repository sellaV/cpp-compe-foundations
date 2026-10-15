# Roadmap and pacing

Use this as an 8–12 week track alongside college, at roughly three focused sessions per week. This is a starting pace, not a deadline: repeat a problem when you cannot yet explain the invariant. Warm-ups can take 20–40 minutes; Core tasks often need 45–90 minutes; Stretch tasks may take several sessions.

## Recommended order

Follow the IDs. Read the C++ bridge as concepts appear. Problems 01–04 introduce the API style; 05–08 strengthen algorithmic reasoning; 09–12 shift toward C++ design. Finish 13–16 before a robotics capstone and 17–24 before a vision/edge AI capstone.

Problem 20 directly includes problem 19. Other problems compile independently, even though earlier concepts remain useful.

| ID | Challenge | Level | Main C++ / reasoning skills |
| --- | --- | --- | --- |
| 01 | [Filter valid sensor samples](../problems/01_stable_compaction/README.md) | Warm-up | const references, range-based loops, vector, return by value |
| 02 | [Longest consecutive alarm](../problems/02_longest_alarm/README.md) | Warm-up | size_t, counters, loop invariants |
| 03 | [Pair of complementary measurements](../problems/03_two_sum/README.md) | Core | unordered_map, optional, pair, iterators, int64_t |
| 04 | [Parse a telemetry command](../problems/04_packet_parser/README.md) | Core | string_view, from_chars, optional, error codes |
| 05 | [Moving average without repeated sums](../problems/05_moving_average/README.md) | Core | indexing, vector<double>, explicit casts, exceptions |
| 06 | [First sample at or above a target](../problems/06_lower_bound/README.md) | Core | half-open intervals, unsigned indices, binary search |
| 07 | [Merge motor reservation intervals](../problems/07_merge_intervals/README.md) | Core | struct, sort comparator, value parameters, back() |
| 08 | [Modify a hardware status register](../problems/08_register_bits/README.md) | Core | uint32_t, bitwise OR/AND/NOT, shifts, unsigned literals |
| 09 | [Fixed-capacity telemetry buffer](../problems/09_ring_buffer/README.md) | Stretch | class, constructor, private state, template, optional, circular indexing |
| 10 | [Latched emergency-stop state machine](../problems/10_robot_state/README.md) | Core | enum class, class encapsulation, switch, methods |
| 11 | [Traverse an owned command chain](../problems/11_owned_chain/README.md) | Core | unique_ptr, raw observing pointers, nullptr, make_unique, ownership |
| 12 | [Transform data with a callable](../problems/12_generic_transform/README.md) | Stretch | function templates, callable parameters, lambdas, decltype, type_traits |
| 13 | [Shortest path in an occupancy grid](../problems/13_grid_bfs/README.md) | Core | queue, pair, vector of vectors, structured bindings, BFS |
| 14 | [Minimum-cost route through a robot graph](../problems/14_weighted_path/README.md) | Stretch | priority_queue, greater, adjacency lists, int64_t distances |
| 15 | [Dependency order for automation tasks](../problems/15_task_order/README.md) | Stretch | indegree counts, topological sorting, optional, min-heap |
| 16 | [A bounded discrete PID controller](../problems/16_pid_step/README.md) | Stretch | stateful classes, floating point, constructor validation, clamp |
| 17 | [Crop a flattened grayscale image](../problems/17_image_crop/README.md) | Core | row-major storage, nested loops, bounds checking |
| 18 | [3x3 box blur with explicit border behavior](../problems/18_box_blur/README.md) | Core | nested loops, accumulation, casts, numeric output |
| 19 | [Intersection over union of boxes](../problems/19_iou/README.md) | Core | struct, const reference, geometry, floating point |
| 20 | [Greedy non-maximum suppression](../problems/20_nms/README.md) | Stretch | sorting index vectors, tie-breaking, nested comparisons, reuse of helpers |
| 21 | [Stable softmax for classifier logits](../problems/21_stable_softmax/README.md) | Core | exp, max_element, accumulate, floating point stability |
| 22 | [Quantize floating-point samples to int8](../problems/22_quantize/README.md) | Core | round, clamp, int8_t, numeric limits, narrowing conversions |
| 23 | [Multiply row-major matrices](../problems/23_matrix_multiply/README.md) | Stretch | flat tensors, triple loops, index arithmetic, shape contracts |
| 24 | [Convert HWC pixels to normalized CHW tensor](../problems/24_tensor_layout/README.md) | Stretch | uint8_t, float, tensor indexing, explicit casts, layout conversion |

## Milestones

- After 04: write a function with a precise input/output contract, explain references and optional results, and handle malformed telemetry.
- After 08: distinguish O(n), O(log n) and O(n log n); explain a binary-search invariant and safely set register bits.
- After 12: design a small class with private state, explain ownership versus observation, and instantiate a template with more than one type.
- After 16: explain why BFS uses a queue, why Dijkstra needs nonnegative costs, and what state persists between PID samples.
- After 20: trace row-major image indices, state border behavior, and explain why NMS suppresses boxes rather than merging them.
- After 24: avoid softmax overflow, explain int8 saturation, and track matrix/tensor dimensions precisely.

## A session that builds understanding

Spend a few minutes on the contract and one manual example, then code and test. Reserve the last ten minutes for a short learning note. Return 2–3 days later and explain the approach without looking. If you needed the solution, rewrite it from memory rather than marking it complete immediately.

## Beyond this repository

Your next C++ learning should include translation units and CMake, deeper move semantics and RAII, standard algorithms and iterators, concurrency and synchronization, and profiling. Pair that with discrete math, linear algebra, signals, controls and embedded systems coursework. The algorithm track is one part of preparation for robotics and edge AI; deployment also involves latency, memory, hardware I/O and system integration.
