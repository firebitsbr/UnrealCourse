// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorOpener.h"


// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpener::BeginPlay()
{
    Super::BeginPlay();

    ThisComponent = GetOwner();
    MainPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(MainPawn)) {
        OpenDoor();
        LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    }

    if (LastDoorOpenTime + DoorCloseDelay <= GetWorld()->GetTimeSeconds()) {
        CloseDoor();
    }
}

void UDoorOpener::OpenDoor()
{
    ThisComponent->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UDoorOpener::CloseDoor()
{
    ThisComponent->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}
