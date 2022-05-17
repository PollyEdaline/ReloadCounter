#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynamicIcon.h"
#include "TwoFacetDynamicIcon.generated.h"

class UTexture2D;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable, EditInlineNew)
class FSD_API UTwoFacetDynamicIcon : public UDynamicIcon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Primary1Tint1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Primary1Tint2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Primary1Texture;
    
    UPROPERTY(EditAnywhere)
    float Primary1Texture_BasePoint;
    
    UPROPERTY(EditAnywhere)
    float Primary1Texture_Contrast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Primary2Tint1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Primary2Tint2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Primary2Texture;
    
    UPROPERTY(EditAnywhere)
    float Primary2Texture_BasePoint;
    
    UPROPERTY(EditAnywhere)
    float Primary2Texture_Contrast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PreviewInstance;
    
public:
    UTwoFacetDynamicIcon();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePreview();
    
};
