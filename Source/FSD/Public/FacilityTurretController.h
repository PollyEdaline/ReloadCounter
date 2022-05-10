#pragma once
#include "CoreMinimal.h"
#include "FSDAIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "FacilityTurretController.generated.h"

class UAIPerceptionComponent;
class UHealthComponentBase;
class AActor;

UCLASS(Blueprintable)
class AFacilityTurretController : public AFSDAIController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAIPerceptionComponent* Perception;
    
private:
    UPROPERTY(EditAnywhere)
    float RememberTargetTime;
    
    UPROPERTY(EditAnywhere)
    float RetargetOnAttackChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RespectAttack;
    
public:
    AFacilityTurretController();
private:
    UFUNCTION(BlueprintCallable)
    void OnTurretsAttackingChanged(bool IsAttacking);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetRevived();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnTargetDied(UHealthComponentBase* Health);
    
    UFUNCTION(BlueprintCallable)
    void OnPerceptionUpdated(AActor* sensedActor, FAIStimulus Stimulus);
    
};

