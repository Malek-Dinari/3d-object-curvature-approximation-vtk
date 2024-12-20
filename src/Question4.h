#ifndef QUESTION4_H
#define QUESTION4_H

#include <vtkSmartPointer.h>
#include <vtkOBJReader.h>
#include <vtkCurvatures.h>
#include <vtkDataSetMapper.h>
#include <vtkLookupTable.h>
#include <vtkScalarsToColors.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>

class Question4 {
public:
    void executer(const std::string& filename);
};

#endif // QUESTION4_H
