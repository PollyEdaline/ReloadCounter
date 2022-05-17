#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResourceAddedDelegate.h"
#include "ResourceChangedSignatureDelegate.h"
#include "ResourceFullSignatureDelegate.h"
#include "ResourceAddedSignatureDelegate.h"
#include "ResourcesComponent.generated.h"

class UResourceData;
class UCappedResource;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UResourcesComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceChangedSignature OnResourceChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceAddedSignature OnResourceIncreased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceFullSignature OnResourceFull;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceAdded OnResourceAdded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Resources, meta=(AllowPrivateAccess=true))
    TArray<UCappedResource*> Resources;
    
    UPROPERTY(EditAnywhere)
    float ResourceCap;
    
public:
    UResourcesComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void ResourceIncreased(UCappedResource* Resource, float Delta);
    
    UFUNCTION(BlueprintCallable)
    void ResourceFull(UCappedResource* Resource);
    
    UFUNCTION()
    void ResourceChanged(UCappedResource* Resource, float currentAmount);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Resources();
    
public:
    UFUNCTION(BlueprintPure)
    static int32 GetXPFromResourceMap(const TMap<UResourceData*, float>& NewResources);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetXpFromMining() const;
    
    UFUNCTION(BlueprintCallable)
    static TMap<UResourceData*, float> GetSeparateResourcesFromMap(const TMap<UResourceData*, float>& NewResources);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCappedResource* GetResource(UResourceData* Data, bool createIfAmountIsZero);
    
    UFUNCTION(BlueprintPure)
    float GetCapacityPct() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UCappedResource*> GetAllResources();
    
};
