// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"


/**
 * 
 */
UCLASS()
class RUNNERGAME_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AActor> SpawnObjectClass;
	
	void SpawnObject();

private:
	int SpawnedObjectCount;

	FVector SpawnLocation;

	
};
