# Travel Route Optimization

## Overview
This program implements a travel route optimization system that helps find the shortest path or least expensive route between locations in a graph representing a transportation network. Users can query specific routes between two locations or find the shortest paths from a given location to all other locations.

## Algorithm

1. **Define Constants and Initialize Arrays**  
   - Set `max = 5` (representing the number of vertices).  
   - Initialize two 2D arrays, `distance` and `price`, to represent the weights between vertices in terms of distance and price, respectively.

2. **User Input**  
   - The program runs a loop until a valid choice is made.
   - Users select:
     - 'S' to find the shortest path between a specific source and destination.
     - 'A' to compute the shortest paths from a given source to all other vertices.

3. **Processing User Choice**  
   - If 'S' is selected:
     - The user inputs the source and destination vertices.
     - The user chooses between:
       - 'D' for the shortest distance.
       - 'P' for the least cost.
     - The relevant matrix (`distance` or `price`) is copied into a local array `path`.
   - Apply the **Floyd-Warshall Algorithm** on the chosen matrix to compute the shortest paths between all pairs of vertices.
   - Display the computed shortest path based on the selected criteria.

4. **Handling 'A' (All Paths from a Source)**  
   - If 'A' is selected:
     - The user inputs a source vertex.
     - Call the `shortestPathFromSource` function, which computes and displays the shortest path from the given source to all other vertices.

5. **Shortest Path Calculation**  
   - The `shortestPathFromSource` function:
     - Initializes a visited bitmask.
     - Iterates over possible paths.
     - Selects the next vertex with the minimum weight that hasn't been visited.
     - Updates the visited bitmask and tracks the path taken.

6. **Loop Completion & Program Termination**  
   - If an invalid choice is made, an error message is displayed, and the prompt reappears.
   - If a valid operation is executed, the loop exits, and the program terminates after displaying the results.

## Usage
- Run the program.
- Select either 'S' (specific route) or 'A' (all paths from a source).
- Follow the on-screen prompts to enter source, destination, and optimization criteria.
- View the computed shortest paths based on your input.

## Dependencies
- Standard C/C++ libraries for matrix operations and path calculations.
- No external dependencies are required.

## License
This project is open-source and available under the MIT License.

