#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GrabbedActorSigDelegate.h"
#include "ReleasedActorSigDelegate.h"
#include "EOutline.h"
#include "EGrabbedStateCameraMode.h"
#include "GrabberComponent.generated.h"

class ADeepPathfinderCharacter;
class UAudioComponent;
class USkeletalMeshComponent;
class USoundCue;
class UDialogDataAsset;
class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGrabberComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGrabbedActorSig OnGrabbedActor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReleasedActorSig OnReleasedActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery TagFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* GrabLoopSoundInstance;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<ADeepPathfinderCharacter> PathfinderOwner;
    
    UPROPERTY(EditAnywhere, Export, Transient)
    TWeakObjectPtr<USkeletalMeshComponent> OwnerMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BeginGrabedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* GrabedLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* EndGrabedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* BeginGrabbedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* EndGrabbedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* AttentionGrabbedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentlyGrabbed, meta=(AllowPrivateAccess=true))
    AActor* CurrentlyGrabbed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GrabAttachName;
    
    UPROPERTY(EditAnywhere)
    float GrabTime;
    
    UPROPERTY(EditAnywhere)
    float CarryCooldown;
    
    UPROPERTY(EditAnywhere)
    float RevivedGravePeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOutline PlayerOutlineOnGrab;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGrabbedStateCameraMode CameraMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TrackPlayerCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ManualGrabTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanPlayerShoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HeightenSensesImmune;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NeedsPathToTarget;
    
public:
    UGrabberComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void Timer_ReleaseTarget();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ReleaseTarget();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentlyGrabbed(AActor* oldCurrentlyGrabbed);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGrabbedTargetValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasGrabbed() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool GrabTarget(AActor* aGrabTarget);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetGrabbedActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanGrabTarget(AActor* aTarget) const;
    
};
