#include "InteractiveToolsFramework//WorldGizmo.h"
#include "BaseGizmos/GizmoArrowComponent.h"
#include "UObject/ObjectFactory.h"
#include "Camera/CameraComponent.h"
#include "Math/JungleMath.h"


UWorldGizmo::UWorldGizmo() {
    UObject* obj = FObjectFactory::ConstructObject<UGizmoArrowComponent>();
    UGizmoArrowComponent* ArrowX = static_cast<UGizmoArrowComponent*>(obj);
    ArrowX->SetType("ArrowX");
    ArrowX->SetParent(this);
    AttachChildren.Add(ArrowX);
    ArrowArr.Add(ArrowX);

    obj = FObjectFactory::ConstructObject<UGizmoArrowComponent>();
    UGizmoArrowComponent* ArrowY = static_cast<UGizmoArrowComponent*>(obj);
    ArrowY->SetType("ArrowY");

    ArrowY->SetParent(this);
    ArrowY->SetDir(ARROW_DIR::AD_Y);
    AttachChildren.Add(ArrowY);
    ArrowArr.Add(ArrowY);


    obj = FObjectFactory::ConstructObject<UGizmoArrowComponent>();
    UGizmoArrowComponent* ArrowZ = static_cast<UGizmoArrowComponent*>(obj);
    AttachChildren.Add(ArrowZ);
    ArrowZ->SetType("ArrowZ");
    ArrowZ->SetParent(this);
    ArrowZ->SetDir(ARROW_DIR::AD_Z);
    AttachChildren.Add(ArrowZ);
    ArrowArr.Add(ArrowZ);
}

void UWorldGizmo::Render()
{
    float ViewportSize = 10;

    float Near = GetWorld()->GetCamera()->GetNearClip();
    float Far = GetWorld()->GetCamera()->GetFarClip();

    //FMatrix MVP =  FMatrix::Transpose(JungleMath::CreateOrthographicMatrix(ViewportSize, ViewportSize, Near, Far))
    //    * FMatrix::Transpose(GetEngine().renderer->GetViewMatrix())
    //    * FMatrix::Transpose(WorldPosition);

    //FVector delta = FVector(-0.8, -0.8, 0);

    //MVP.M[3][0] = delta.x;
    //MVP.M[3][1] = delta.y;
    //MVP.M[3][2] = delta.z;
}
