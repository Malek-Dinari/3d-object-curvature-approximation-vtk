#include <iostream>
#include <vtkSmartPointer.h>
#include <vtkOBJReader.h>
#include <vtkCurvatures.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>
#include <vtkLookupTable.h>

#include "Question1.h"
#include "Question2.h"
#include "Question3.h"
#include "Question4.h"

#define GLFW_INCLUDE_NONE
#include <glfw3.h>
#include <glad.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// Function to initialize ImGui and GLFW
void InitImGui(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable keyboard controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable gamepad controls (if needed)

    // Set up ImGui for GLFW and OpenGL3
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Optional: Set custom style
    ImGui::StyleColorsDark();
}

void RenderUI(int& choix, char* filePath, size_t bufferSize) {
    // Set up ImGui window and interface
    ImGui::NewFrame();
    ImGui::Begin("3D Curvature Approximation");

    ImGui::Text("Select the curvature type:");

    if (ImGui::Button("Gaussian Curvature")) {
        choix = 1;
    }
    if (ImGui::Button("Mean Curvature")) {
        choix = 2;
    }
    if (ImGui::Button("Maximal Curvature")) {
        choix = 3;
    }
    if (ImGui::Button("Minimal Curvature")) {
        choix = 4;
    }

    ImGui::Separator();

    ImGui::Text("Enter the path to the 3D object file:");
    ImGui::InputText("File Path", filePath, bufferSize);

    ImGui::Separator();

    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "ApproximationCourbures3D", nullptr, nullptr);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Create a windowed mode window and its OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Initialize OpenGL loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL loader\n";
        return -1;
    }

    InitImGui(window);

    int choix = 0;
    char filePath[256] = "C:/VTK/TP/ApproximationCourbures3D/Skull1.obj"; // Default path

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Clear framebuffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render UI
        RenderUI(choix, filePath, sizeof(filePath));

        // Execute corresponding function based on the user's choice
        switch (choix) {
        case 1: {
            Question1 q1;
            q1.executer(filePath);
            choix = 0; // Reset choix after execution
            break;
        }
        case 2: {
            Question2 q2;
            q2.executer(filePath);
            choix = 0; // Reset choix after execution
            break;
        }
        case 3: {
            Question3 q3;
            q3.executer(filePath);
            choix = 0; // Reset choix after execution
            break;
        }
        case 4: {
            Question4 q4;
            q4.executer(filePath);
            choix = 0; // Reset choix after execution
            break;
        }
        }

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}