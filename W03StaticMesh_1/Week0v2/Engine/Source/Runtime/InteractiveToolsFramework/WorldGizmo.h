#pragma once
#include "Components/SceneComponent.h"

class UWorldGizmo : public USceneComponent
{
public:
    UWorldGizmo();

    TArray<UGizmoArrowComponent*>& GetArrowArr() { return ArrowArr; }
    void Render() override;
private:
    TArray<UGizmoArrowComponent*> ArrowArr;
};