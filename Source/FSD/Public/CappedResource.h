#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceChangedSignatureDelegate.h"
#include "UObject/Object.h"
#include "ResourceFullSignatureDelegate.h"
#include "ResourceAddedSignatureDelegate.h"
#include "CappedResource.generated.h"

class UResourceData;
class UCappedResource;

UCLASS(Blueprintable)
class UCappedResource : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceChangedSignature OnChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceAddedSignature OnIncreased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceFullSignature OnFull;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    UResourceData* Data;
    
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_CurrentAmount)
    float currentAmount;
    
    UPROPERTY(EditAnywhere, Replicated)
    float MaxAmount;
    
    UPROPERTY(EditAnywhere, Replicated)
    float TotalCollected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_FullFlag, meta=(AllowPrivateAccess=true))
    int32 FullFlag;
    
public:
    UCappedResource();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    float TransferAll(UCappedResource* Receiver);
    
    UFUNCTION(BlueprintCallable)
    float Transfer(float Amount, UCappedResource* Receiver);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_FullFlag(int32 OldValue);
    
    UFUNCTION()
    void OnRep_CurrentAmount(float OldAmount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectiveResource(UObject* WorldContext, bool& IsCompleted) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isEmpty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCraftingResource() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTitle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FColor GetColor() const;
    
    UFUNCTION(BlueprintPure)
    float GetCapacityPct() const;
    
    UFUNCTION(BlueprintCallable)
    float Deduct(float Amount);
    
    UFUNCTION(BlueprintCallable)
    float Add(float Amount);
    
};
