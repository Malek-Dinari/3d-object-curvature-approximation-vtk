#ifndef QUESTION3_H
#define QUESTION3_H

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

class Question3 {
public:
    void executer(const std::string& filename);
};

#endif // QUESTION3_H
