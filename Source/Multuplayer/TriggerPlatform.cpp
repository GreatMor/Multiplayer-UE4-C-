// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerPlatform.h"
#include "Components/BoxComponent.h"

// Sets default values
ATriggerPlatform::ATriggerPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr))return;
	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATriggerPlatform::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ATriggerPlatform::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATriggerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin"));
}

void ATriggerPlatform::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd"));
}