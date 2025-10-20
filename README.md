# 42 C-Piscine’s final project

This is a group project at 42. I worked with [Ömer Recep Dindar](https://github.com/Slyord) (Slyord).

Project subject : [Link](https://github.com/06ergin06/42-BSQ/blob/main/en.subject.pdf)

### Project description
The aim of this project is to find the biggest square on a map while avoiding
obstacles.

### Structure
**bsq.h :** [bsq.h](bsq.h) — Declares the global map structure, headers, and function prototypes.

**main.c :** [main.c](main.c) — Main entry point; orchestrates all function calls.

**ft_utils.c :** [ft_utils.c](ft_utils.c) — Common utility functions.

**ft_map_reader :** [ft_map_reader.c](ft_map_reader.c) — Reads the map from a file or stdin into a string buffer.

**ft_map_validator :** [ft_map_validator.c](ft_map_validator.c) — Validates the map read by the [ft_map_reader.c](ft_map_reader.c).

**ft_parse_map :** [ft_parse_map.c](ft_parse_map.c) — Converts the input string into a 2D array and initializes the global map data.

**ft_map_solver :** [ft_map_solver.c](ft_map_solver.c) — Solves the biggest square problem and marks the result on the map.