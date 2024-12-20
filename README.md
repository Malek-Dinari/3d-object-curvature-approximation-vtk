# ApproximationCourbures3D

## Project Description
This project focuses on approximating principal curvatures of 3D objects using VTK and C++ techniques. It is part of a workshop and aims to provide a visual understanding of curvature estimation.

## Current Progress
- Successfully set up a build system using CMake and Visual Studio.
- Resolved integration issues with VTK and OpenGL.
- Started implementing GUI with ImGui for visualizing curvature approximation.
- Resolved initial runtime errors (e.g., invalid `DisplaySize` in ImGui).

## Future Goals
1. Dockerize the project to improve portability and shareability.
2. Optimize curvature estimation algorithms.
3. Implement additional visualization techniques for curvature mapping.

## Usage
To run the project locally:
```bash
# Compile and run the application
cmake .
make
./ApproximationCourbures3D
```

---

### **5. Dockerization Plan**
Add this section to the `README.md` to outline your Dockerization plan:

```markdown
## Dockerization Plan
The primary goal is to containerize this project for easy deployment. The following steps will be taken:
1. Create a `Dockerfile` to build the application environment.
2. Include all dependencies (VTK, ImGui, C++) in the container.
3. Map necessary ports for GUI rendering (or use an X11 server for Linux hosts).
4. Test and optimize container performance.
5. Push the final image to Docker Hub for distribution.
