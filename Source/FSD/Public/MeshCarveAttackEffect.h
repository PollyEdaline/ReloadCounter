#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttackEffect.h"
#include "UObject/NoExportTypes.h"
#include "MeshCarveAttackEffect.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, EditInlineNew)
class UMeshCarveAttackEffect : public UAttackEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float ExpensiveNoise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* CarveMesh;
    
    UPROPERTY(EditAnywhere)
    float CarverOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator CarverOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CarverScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Socket;
    
public:
    UMeshCarveAttackEffect();
};
