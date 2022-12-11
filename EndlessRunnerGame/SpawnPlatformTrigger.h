// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SpawnPlatformTrigger.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta =(BlueprintSpawnableComponent)) //with this we can see this component in the blueprint
class RUNNERGAME_API USpawnPlatformTrigger : public UBoxComponent
{
	GENERATED_BODY()

public:
	USpawnPlatformTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	bool DoesOverlapOnce = false;
	int count = 0;
	int SizeOfPlatforms;
	class ABasePlatform * Platform;

	UPROPERTY(EditDefaultsOnly, Category=Spawn)
	TSubclassOf<class AActor> SpawnedPlatform;

	UPROPERTY(EditDefaultsOnly, Category = Spawn)
	int OffsetForSpawning = 1400;

	void SpawnPlatform();

	bool IsActorInOverlapFunction();

	class AMainGameMode * GameModeName;

};
