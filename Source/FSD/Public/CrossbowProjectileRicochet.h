#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "CrossbowProjectileRicochet.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrossbowProjectileRicochet : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraTrailParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RicochetMax;
    
    UPROPERTY(EditAnywhere)
    float RicochetRange;
    
public:
    UCrossbowProjectileRicochet();
protected:
    UFUNCTION(BlueprintCallable)
    void Ricochet(const FHitResult& HitResult);
    
};

