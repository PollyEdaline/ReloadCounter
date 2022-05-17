#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TrackBuilderSegment.h"
#include "EPipelineBuildState.h"
#include "Engine/EngineTypes.h"
#include "EInputKeys.h"
#include "PipelineSegment.generated.h"

class USplineComponent;
class USimpleHealthComponent;
class APipelineSegment;
class UStaticMesh;
class UMaterialInterface;
class USingleUsableComponent;
class UDroneUseComponent;
class USplineMeshComponent;
class APlayerCharacter;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UPathfinderSplineSegmentCollisionComponent;
class APipelineStart;
class UHealthComponentBase;
class UTrackBuilderUsable;

UCLASS(Abstract, Blueprintable)
class APipelineSegment : public ATrackBuilderSegment {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPipelineStateDelegate, EPipelineBuildState, InPipelineState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPipelineSegmentDelegate, APipelineSegment*, InPipelineSegment);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPipelineSegmentDelegate OnPipelineBroken;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPipelineSegmentDelegate OnPipelineRepaired;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPipelineSegmentDelegate OnPipelineActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPipelineStateDelegate OnPipelineStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMeshUnassembled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMeshAssembled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMeshFinal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EditorEndLocation;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ETraceTypeQuery> CarvingTraceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* NumberMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USingleUsableComponent* RepairSegmentUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USingleUsableComponent* ActivateSegmentUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDroneUseComponent* DroneUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USimpleHealthComponent* SegmentHealthComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USplineComponent* MovementSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USplineComponent* MovementSplineRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USplineComponent* MovementSplineLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* PipelineMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* PipelineOuterMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* PipelineCapMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* EndPostMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* EndPostMeshStatic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPathfinderSplineSegmentCollisionComponent* PathfinderComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SegmentBroken, meta=(AllowPrivateAccess=true))
    bool bSegmentBroken;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_SegmentActivatedProgress)
    float SegmentActivatedProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EPipelineBuildState PipelineState;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<APipelineStart> PipelineStart;
    
    UPROPERTY(EditAnywhere)
    float MinValidLength;
    
    UPROPERTY(EditAnywhere)
    float MaxValidLength;
    
    UPROPERTY(EditAnywhere)
    float TooSharpExtraLength;
    
    UPROPERTY(EditAnywhere)
    float TooSteepExtraLength;
    
    UPROPERTY(EditAnywhere)
    float BlockedSphereSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockedExtraRaytraceRotationOffset;
    
    UPROPERTY(EditAnywhere)
    float BlockedExtraRaytraces;
    
    UPROPERTY(EditAnywhere)
    float BlockedExtraRaytraceDist;
    
    UPROPERTY(EditAnywhere)
    float BlockedRayTraceSuccesses;
    
public:
    APipelineSegment();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateSplineMesh(USplineMeshComponent* InMesh, float InProgress, bool InMoveEndCap);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetSegmentBroken(APlayerCharacter* InUser, bool InSegmentBroken);
    
    UFUNCTION(BlueprintCallable)
    void SetPipelineNumberMaterial(UMaterialInterface* InNumberMaterial);
    
    UFUNCTION(BlueprintCallable)
    void SetEndPostVisible(bool InVisible);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSegmentBrokenChanged(bool InSegmentBroken);
    
    UFUNCTION(BlueprintImplementableEvent)
    void ReceiveSegmentActivatedProgress(float InProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSegmentActivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRepaired(APlayerCharacter* InUser);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SegmentBroken();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SegmentActivatedProgress();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APipelineStart* GetPipelineStart() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APipelineSegment* GetNextPipelineSegment(bool bForward) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsSegmentActivated() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void CallbackSegmentRepaired(APlayerCharacter* InUser, EInputKeys Key);
    
    UFUNCTION(BlueprintCallable)
    void CallbackSegmentDestroyed(UHealthComponentBase* InHealth);
    
    UFUNCTION()
    void CallbackSegmentActivatedProgress(float InProgress);
    
    UFUNCTION(BlueprintCallable)
    void CallbackSegmentActivated(APlayerCharacter* InUser, EInputKeys Key);
    
    UFUNCTION(BlueprintCallable)
    void CallbackPipelineStateChanged(APipelineStart* InPipelineStart, EPipelineBuildState InState);
    
    UFUNCTION(BlueprintCallable)
    void CallbackNextSegmentChanged(UTrackBuilderUsable* InUsable, ATrackBuilderSegment* InSegment);
    
    UFUNCTION(BlueprintCallable)
    void CallbackDroneUsed(int32 TimesUsed);
    
};
