#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ERessuplyPodState.h"
#include "EPipelineExtractorPodAnimState.h"
#include "EPipelineBuildState.h"
#include "ERefineryState.h"
#include "PipelineExtractorPodAnimInstance.generated.h"

class APipelineStart;
class APipelineSegment;
class APipelineExtractorPod;
class AFSDRefinery;

UCLASS(Abstract, Blueprintable, NonTransient)
class FSD_API UPipelineExtractorPodAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float ConnectionRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPipelineExtractorPodAnimState AnimState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERessuplyPodState PodState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPipelineBuildState PipelineState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERefineryState RefineryState;
    
    UPROPERTY(EditAnywhere)
    float RotationSpeed;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<APipelineExtractorPod> Pod;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<APipelineSegment> ConnectedSegment;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<APipelineStart> PipelineStart;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<AFSDRefinery> Refinery;
    
public:
    UPipelineExtractorPodAnimInstance();
};
