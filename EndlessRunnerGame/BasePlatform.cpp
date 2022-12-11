// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlatform.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "MainGameMode.h"

// Sets default values 
ABasePlatform::ABasePlatform()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePlatform::BeginPlay()
{
	Super::BeginPlay();
	//Take game mode 
	GameModeName = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());
	
}

// Called every frame
void ABasePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//GameModeName -> SpawnObject();
}

// Called to bind functionality to input
void ABasePlatform::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

