#include "AnimatedItem.h"
#include "FirstPersonSkeletalMeshComponent.h"
#include "SkinnableComponent.h"
#include "Components/SkeletalMeshComponent.h"


FTransform AAnimatedItem::GetMuzzle() const {
    return FTransform{};
}

USkeletalMeshComponent* AAnimatedItem::GetItemMesh() const {
    return NULL;
}

AAnimatedItem::AAnimatedItem() {
    this->Skinnable = CreateDefaultSubobject<USkinnableComponent>(TEXT("Skinnable"));
    this->FPAnimInstance = NULL;
    this->TPAnimInstance = NULL;
    this->FPMesh = CreateDefaultSubobject<UFirstPersonSkeletalMeshComponent>(TEXT("FPMesh"));
    this->TPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TPMesh"));
    this->FP_EquipAnimation = NULL;
    this->TP_EquipAnimation = NULL;
    this->EquipDuration = 0.25f;
    this->CharacterAnimationSet = NULL;
}

