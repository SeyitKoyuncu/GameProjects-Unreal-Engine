// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"


void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DuplicatePlatform();
	Moved();
}

void AWall::Moved()
{
	FVector PlatformLocation = GetActorLocation();
	PlatformLocation.Y = PlatformLocation.Y - Speed;
	SetActorLocation(PlatformLocation, false);
}