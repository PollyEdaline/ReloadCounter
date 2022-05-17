#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "ShowroomStage.generated.h"

class UShowroomController;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;
class USceneComponent;

UCLASS(Abstract, Blueprintable)
class AShowroomStage : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* SceneCapure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* ActiveCaptureComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UShowroomController> ControllerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UShowroomController* ControllerInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* SceneCapture;
    
    UPROPERTY(EditAnywhere)
    float MinPitch;
    
    UPROPERTY(EditAnywhere)
    float MaxPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* CameraFocusPoint;
    
public:
    AShowroomStage();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveInitialize(UTextureRenderTarget2D* RenderTarget);
    
public:
    UFUNCTION(BlueprintCallable)
    USceneCaptureComponent2D* GetActiveCaptureComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UTextureRenderTarget2D* CreateRenderTarget();
    
};
