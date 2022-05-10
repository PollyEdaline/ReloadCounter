#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateEventDelegate.h"
#include "DroneFinishedUsingDelegate.h"
#include "DroneUseProgressDelegate.h"
#include "EInputKeys.h"
#include "DroneUseComponent.generated.h"

class USingleUsableComponent;
class UDialogDataAsset;
class APlayerCharacter;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UDroneUseComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDroneFinishedUsing OnUsed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnBeginUse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnStopUse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDroneUseProgress OnProgress;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* BoscoLaserpointerShout;
    
    UPROPERTY(EditAnywhere, Export, Transient)
    TWeakObjectPtr<USingleUsableComponent> SyncToUsable;
    
    UPROPERTY(EditAnywhere, Replicated, Transient)
    float Progress;
    
    UPROPERTY(EditAnywhere)
    float useDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ResetOnFail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanUse;
    
public:
    UDroneUseComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void SyncedUsableUserCountChangedResponse(int32 userCount);
    
    UFUNCTION(BlueprintCallable)
    void SyncedUsableUsedResponse(APlayerCharacter* User, EInputKeys Key);
    
    UFUNCTION(BlueprintCallable)
    void SyncedUsableBeginUseResponse(APlayerCharacter* User, EInputKeys Key);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetUseDuration(float NewUseDuration);
    
    UFUNCTION(BlueprintCallable)
    void SetCanUse(bool NewCanUse);
    
    UFUNCTION(BlueprintPure)
    float GetProgress() const;
    
    UFUNCTION(BlueprintCallable)
    void EndUse();
    
    UFUNCTION(BlueprintCallable)
    void BeginUse();
    
};

