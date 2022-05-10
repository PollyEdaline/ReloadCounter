#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OxygenCallback.h"
#include "Components/ActorComponent.h"
#include "OxygenDelegateDelegate.h"
#include "OxygenActiveDelegateDelegate.h"
#include "OxygenTriggerDelegateDelegate.h"
#include "OxygenComponent.generated.h"

class UStatusEffect;
class UHealthComponentBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOxygenComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenDelegate OnOxygenChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenActiveDelegate OnOxygenReplenishingEvent;
    
protected:
    UPROPERTY(EditAnywhere)
    float OxygenGivenOnRevive;
    
    UPROPERTY(EditAnywhere, Transient)
    float CurrentOxygen;
    
    UPROPERTY(EditAnywhere)
    float OxygenReplinishmentRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_NetworkedOxygen, meta=(AllowPrivateAccess=true))
    int32 NetworkedOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsReplenishingOxygen, meta=(AllowPrivateAccess=true))
    bool IsReplenishingOxygen;
    
    UPROPERTY(EditAnywhere)
    float OxygenDepletionPersecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FOxygenCallback> Callbacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> NoOxygenStatusEffect;
    
public:
    UOxygenComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void RegisterOxygenEvent(FOxygenTriggerDelegate OxygenCallback, float oxygenLevel, bool triggerOnOxygenLoss);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRevived();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NetworkedOxygen(int32 OldValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsReplenishingOxygen();
    
    UFUNCTION(BlueprintCallable)
    void OnDeath(UHealthComponentBase* HealthComponent);
    
};

