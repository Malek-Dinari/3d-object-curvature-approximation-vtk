#ifndef QUESTION1_H
#define QUESTION1_H

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

class Question1 {
public:
    void executer(const std::string& filename);
};

#endif // QUESTION1_H
