#ifndef QUESTION2_H
#define QUESTION2_H

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

class Question2 {
public:
    void executer(const std::string& filename);
};

#endif // QUESTION2_H
