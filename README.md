# Epitech-Year1-Dante_Star

This project is about making a maze generator, and a maze solver
The 2 parts of this Project are the following:
- A maze generator for perfect and imperfect maze
- A maze solver using a A* search algorithm

But we must follow some rules for those maze, which are:
- The maze starts at the top left and his exit is at the bottom right of it.
- There is only one entrance and exit
- The maze has to be a rectangle
- The maze must have a solution when we create it
- The maze solver must handle mazes with no solution

# The Maze Generator

The Maze Generator is a generator of random maze that works by giving the proportion of the map the following way:
```
./generator {size x} {size y}
```
Giving us then an imperfect maze of the chosen size, but what's an imperfect maze ?
An imperfect maze has:
- Clusters and dead-ends
- Loops
- At least one solution

And while we're at it, a perfect maze has:
- No clusters and no dead-ends
- No loops
- One and only path
- The only path must be the solution

If the user wants a perfect maze, he can use the command ./generator {size x} {size y} {perfect}
By default the maze generator is an imperfect maze generator

# The A* Solver

```
./solver {filename}
```
A* (pronounced "A-star") is a graph traversal and path search algorithm, which is often used in many fields of computer science due to its completeness, optimality, and optimal efficiency.
