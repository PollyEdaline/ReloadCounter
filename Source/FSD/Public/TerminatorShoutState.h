#pragma once
#include "CoreMinimal.h"
#include "TerminatorShoutState.generated.h"

class USoundCue;

USTRUCT(BlueprintType)
struct FTerminatorShoutState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundCue*> Shouts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Loop;
    
    UPROPERTY(EditAnywhere)
    float MaxRandomShoutDelay;
    
    UPROPERTY(EditAnywhere)
    float MinRandomShoutDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Interruptable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PreventSubsequentDuplicate;
    
    FSD_API FTerminatorShoutState();
};

