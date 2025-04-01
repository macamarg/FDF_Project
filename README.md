# FDF - Wireframe Model

## About
FDF ("fil de fer" - wireframe in French) is a 42 School project that creates a simplified 3D wireframe representation of a landscape from elevation data. The program reads coordinate points from a `.fdf` file and renders them in isometric projection using the MiniLibX graphics library.
This project is about representing a landscape as a 3D object
in which all surfaces are outlined in lines.



## Features
### Mandatory
- Parses `.fdf` map files containing elevation data
- Renders 3D wireframe models in isometric projection
- Smooth window management with MiniLibX
- Clean exit on ESC key or window close
- Memory leak-free implementation

### Bonus (if implemented)
- [ ] Additional projections (parallel/conic)
- [:ballot_box_with_check:] Zoom functionality
- [:ballot_box_with_check:] Model translation
- [:ballot_box_with_check:] Model rotation
- [:ballot_box_with_check:] Reset to initial configurations




*Isometric projection with rotation and scale alteration*






Useful links

https://medium.com/@youbihi129/42-the-network-fdf-fil-de-fer-project-roadmap-464be06d6f15
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm?source=post_page-----464be06d6f15--------------------------------
https://harm-smits.github.io/42docs/
https://medium.com/@jalal92/understanding-the-minilibx-a-practical-dive-into-x-window-programming-api-in-c-cb8a6f72bec3
