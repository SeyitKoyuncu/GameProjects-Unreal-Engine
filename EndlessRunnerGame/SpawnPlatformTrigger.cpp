// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPlatformTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "BasePlatform.h"
#include "MainGameMode.h"

USpawnPlatformTrigger::USpawnPlatformTrigger()
{
    PrimaryComponentTick.bCanEverTick = true;
    UE_LOG(LogTemp, Warning, TEXT("SpawnTrigger olusturuldu"));
}

void USpawnPlatformTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    SpawnPlatform();
}

void USpawnPlatformTrigger::BeginPlay()
{
	Super::BeginPlay();	
    GameModeName = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());
}

void USpawnPlatformTrigger::SpawnPlatform()
{
    TArray <AActor*> Actors;
    GetOverlappingActors(Actors);

    TArray <AActor*> AllPlatforms;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABasePlatform::StaticClass(), AllPlatforms);
    SizeOfPlatforms = AllPlatforms.Num();

    //Chechk the main actor in box overlap with trigger
    bool IsActorInOverlap = IsActorInOverlapFunction();

    if(IsActorInOverlap && DoesOverlapOnce == false)
    {
        DoesOverlapOnce = true;
        Platform = Cast<ABasePlatform>(UGameplayStatics::GetActorOfClass(GetWorld(), ABasePlatform::StaticClass()));
    }

    // If actor overlap with trigger spawn new platform in front of the old platform
    if(IsActorInOverlap && DoesOverlapOnce)
    {
        GameModeName -> SpawnObject();
        
        AController * PlayerController = Cast<AController>(UGameplayStatics::GetPlayerController(this, 0));
        APawn * MainChar = PlayerController -> GetPawn();
        FVector MainCharLocation = MainChar -> GetActorLocation();

        FVector SpawnLocation = MainCharLocation;
        SpawnLocation.Y = MainCharLocation.Y - OffsetForSpawning;
        SpawnLocation.Z = (Platform -> GetActorLocation()).Z;
        SpawnLocation.X = (Platform -> GetActorLocation()).X;

        if(SpawnedPlatform)
        {   
            GetWorld() -> SpawnActor<ABasePlatform>(SpawnedPlatform, SpawnLocation, Platform -> GetActorRotation());
            UE_LOG(LogTemp, Error, TEXT("Spawn Yapildi"));
            DoesOverlapOnce = false;
            count++; 
        }
        
        if(SizeOfPlatforms > 3)
            AllPlatforms[0] -> Destroy();
    }     
}

bool USpawnPlatformTrigger::IsActorInOverlapFunction()
{
    TArray <AActor*> Actors;
    GetOverlappingActors(Actors);
    for(AActor * Actor: Actors)
    {
        if(Actor -> GetActorNameOrLabel() == "BP_ThirdPersonCharacter")
            return true;
    }
    return false;
}
