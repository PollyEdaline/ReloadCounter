#pragma once
#include "CoreMinimal.h"
#include "HealthRegenerationParams.generated.h"

USTRUCT(BlueprintType)
struct FHealthRegenerationParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsRegenerating;
    
    UPROPERTY(EditAnywhere)
    float DelayAfterDamage;
    
    UPROPERTY(EditAnywhere)
    float HealthPerSecond;
    
    UPROPERTY(EditAnywhere)
    float TargetHealthRatio;
    
    FSD_API FHealthRegenerationParams();
};

