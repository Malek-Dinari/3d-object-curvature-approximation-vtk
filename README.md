# ApproximationCourbures3D

## Project Description
This project focuses on approximating principal curvatures of 3D objects using VTK and C++ techniques. It is me trying to expand based on a workshop at my uni ENSI (Tunisia) and aims to provide a visual understanding of curvature estimation.

## Current Progress
- Successfully set up a build system using CMake and Visual Studio.
- Resolved integration issues with VTK and OpenGL.
- Started implementing GUI with ImGui for visualizing curvature approximation.
- Resolved initial runtime errors (e.g., invalid `DisplaySize` in ImGui).


### Prerequisites
- CMake 3.18 or higher
- A C++ compiler (Visual Studio, GCC, etc.)
- VTK (9.4 or compatible version)
- OpenGL (installed with most graphics drivers)

## Setup and Run
To run the project in its current state, follow these steps:

1. **Install Required Software:**
   - Install [CMake](https://cmake.org/download/).
   - Install [Visual Studio](https://visualstudio.microsoft.com/) (ensure the C++ development tools are selected during installation).
   - Install [VTK 9.4.0](https://vtk.org/download/).
   - Install [ImGui](https://github.com/ocornut/imgui).

2. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/ApproximationCourbures3D.git
   cd ApproximationCourbures3D
   ```

3. **Build the Project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

4. **Run the Application:**
   ```bash
   ./ApproximationCourbures3D
   ```
# Additional necessary steps!

## Generate and Add glad
1. Visit the [glad generator](https://gen.glad.sh/), configure the desired OpenGL version (e.g., OpenGL 3.3), and download the files.
2. Extract and copy the files into the `third_party/glad/` directory:
   - Place `include/glad/` under `third_party/glad/include/glad/`.
   - Place `src/glad.c` under `third_party/glad/src/glad.c`.

---

## Download and Build GLFW
1. Visit [glfw.org](https://www.glfw.org/) and download the source code.
2. Extract and place the files in `third_party/glfw/`.
3. Build GLFW:
   ```bash
   cd third_party/glfw
   cmake .
   make

---

## Future Goals
1. Dockerize the project to improve portability and shareability.
2. Optimize curvature estimation algorithms.
3. Implement additional visualization techniques for curvature mapping.

### **6. Dockerization Plan**
Add this section to the `README.md` to outline your Dockerization plan:

```markdown
## Dockerization Plan
The primary goal is to containerize this project for easy deployment. The following steps will be taken:
1. Create a `Dockerfile` to build the application environment.
2. Include all dependencies (VTK, ImGui, C++) in the container.
3. Map necessary ports for GUI rendering (or use an X11 server for Linux hosts).
4. Test and optimize container performance.
5. Push the final image to Docker Hub for distribution.
