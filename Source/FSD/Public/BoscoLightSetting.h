#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoscoLightSetting.generated.h"

USTRUCT(BlueprintType)
struct FBoscoLightSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor Color;
    
    UPROPERTY(EditAnywhere)
    float Intensity;
    
    UPROPERTY(EditAnywhere)
    float Radius;
    
    FSD_API FBoscoLightSetting();
};

