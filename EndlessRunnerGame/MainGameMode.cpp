// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

void AMainGameMode::SpawnObject()
{
	AController * PlayerController = Cast<AController>(UGameplayStatics::GetPlayerController(this, 0));
	APawn * MainChar = PlayerController -> GetPawn();
	FVector MainCharLocation = MainChar -> GetActorLocation();
	if(SpawnedObjectCount < 1)
	{
        UE_LOG(LogTemp, Warning, TEXT("Game Mode SpawnObject Girdi"));
		SpawnLocation = MainCharLocation;
		SpawnLocation.Y = SpawnLocation.Y - 500;
		SpawnLocation.Z = SpawnLocation.Z + 50;
		if(SpawnObjectClass)
		{
			GetWorld() -> SpawnActor<class AActor>(SpawnObjectClass, SpawnLocation, MainChar -> GetActorRotation());	
			SpawnedObjectCount++;
		}
	}
	int difference = abs(MainCharLocation.Y - SpawnLocation.Y);
	UE_LOG(LogTemp, Warning, TEXT("Difference s = %d"), difference);
	if(abs(MainCharLocation.Y - SpawnLocation.Y <60))
		SpawnedObjectCount = 0; //destroy de before spawning actor but first chech the distance between main actor
}