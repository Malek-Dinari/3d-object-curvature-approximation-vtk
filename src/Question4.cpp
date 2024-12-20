#include "Question4.h"
#include <iostream>

void Question4::executer(const std::string& filename) {
    std::cout << "Lecture du fichier OBJ : " << filename << std::endl;

    // Read the .obj file with vtkOBJReader
    auto reader = vtkSmartPointer<vtkOBJReader>::New();
    reader->SetFileName(filename.c_str());
    reader->Update();

    auto polyData = reader->GetOutput();
    if (!polyData || polyData->GetNumberOfPoints() == 0) {
        std::cerr << "Erreur : Impossible de lire le fichier ou fichier vide." << std::endl;
        return;
    }

    // Compute Minimal curvature
    auto minimalCurvature = vtkSmartPointer<vtkCurvatures>::New();
    minimalCurvature->SetInputData(polyData);
    minimalCurvature->SetCurvatureTypeToMinimum();
    minimalCurvature->Update();

    // Create a LookupTable for coloring
    auto lookupTable = vtkSmartPointer<vtkLookupTable>::New();
    lookupTable->SetNumberOfTableValues(256);
    lookupTable->SetTableRange(minimalCurvature->GetOutput()->GetScalarRange());

    for (int i = 0; i < 256; ++i) {
        double value = static_cast<double>(i) / 255.0;
        lookupTable->SetTableValue(i, 0.0, 1.0 - value, value);
    }

    auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection(minimalCurvature->GetOutputPort());
    mapper->SetLookupTable(lookupTable);
    mapper->ScalarVisibilityOn();

    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    auto colors = vtkSmartPointer<vtkNamedColors>::New();
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    auto renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

    renderWindow->AddRenderer(renderer);
    renderWindowInteractor->SetRenderWindow(renderWindow);

    renderer->AddActor(actor);
    renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

    renderWindow->SetWindowName("Approximation de la Courbure Minimale");
    renderWindow->Render();
    renderWindowInteractor->Start();
}
