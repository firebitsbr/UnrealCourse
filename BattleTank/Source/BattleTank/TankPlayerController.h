// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    ATankPlayerController();
	
protected:
	virtual void BeginPlay() override;

    UFUNCTION(BlueprintImplementableEvent, Category="Setup")
    void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
    virtual void Tick(float DeltaTime) override;

    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector& HitLocation) const;
    bool GetLookDirectionHitLocation(FVector CameraLocation, FVector LookDirection, FVector& HitLocation) const;

    UPROPERTY(EditDefaultsOnly)
    float CrosshairXLocation = 0.5f;
    UPROPERTY(EditDefaultsOnly)
    float CrosshairYLocation = 0.333333333f;
    UPROPERTY(EditDefaultsOnly)
    float LineTraceRangeKM = 10.0f;
};
