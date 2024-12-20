cmake_minimum_required(VERSION 3.18)

project(ApproximationCourbures3D)

# Find VTK
set(VTK_DIR "C:/VTK/Lib/bin/lib/cmake/vtk-9.4")
find_package(VTK REQUIRED)
include_directories(${VTK_INCLUDE_DIRS})

# Set directories for third-party libraries
set(GLFW_DIR "C:/VTK/TP/approximationCourbures3D/third_party/glfw")
set(IMGUI_DIR "C:/VTK/TP/approximationCourbures3D/third_party/imgui")
set(GLAD_DIR "C:/VTK/TP/approximationCourbures3D/third_party/glad")

# Add GLFW include directory
include_directories(${GLFW_DIR}/include)

# Add ImGui include directories
include_directories(${IMGUI_DIR})
include_directories(${IMGUI_DIR}/backends)

# Add GLAD include directory
include_directories(${GLAD_DIR})

# Define ImGui sources
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Define project sources
set(SOURCES
    main.cpp
    Question1.cpp
    Question2.cpp
    Question3.cpp
    Question4.cpp
    third_party/glad/glad.c
)

# Define project headers
set(HEADERS
    Question1.h
    Question2.h
    Question3.h
    Question4.h
)

# Add GLFW library directory (built files)
link_directories(${GLFW_DIR}/lib)

# Add ImGui as a library
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)

# Link GLFW with the ImGui library
target_link_libraries(imgui PRIVATE glfw3)

# Create the main executable
add_executable(approximationCourbures3D ${SOURCES})

# Link libraries to the executable
target_link_libraries(approximationCourbures3D PRIVATE ${VTK_LIBRARIES} glfw3 imgui)

# Automatically initialize VTK modules
vtk_module_autoinit(
  TARGETS approximationCourbures3D
  MODULES ${VTK_LIBRARIES}
)
